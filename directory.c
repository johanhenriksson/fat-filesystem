#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "file.h"
#include "fatfs.h"
#include "directory.h"

void directory_fill(fsinfo_t*, directory_t*);
void directory_append_subdir(directory_t* parent, directory_t* subdir);
void directory_append_file(directory_t* parent, file_t* file);

/* returns the full directory name (allocated) */
char* directory_path(directory_t* dir); 

directory_t* directory_init(fsinfo_t* fsinfo, direntry_t* entry, directory_t* parent) 
{
    /* allocate directory structure */
    directory_t* dir = (directory_t*)malloc(sizeof(directory_t));
    assert(dir);

    dir->entry   = entry;
    dir->parent  = parent;
    dir->cluster = entry->cluster;
    dir->cluster_size = fs_cluster_size(fsinfo, entry->cluster);
    dir->path = directory_path(dir);

    /* Allocate subdirectory & file lists */
    dir->max_files   = MAX_FILE_ALLOC;
    dir->max_subdirs = MAX_SUBDIR_ALLOC;
    dir->subdirs = malloc(dir->max_subdirs * sizeof(directory_t*));
    dir->files   = malloc(dir->max_files * sizeof(file_t*));
    assert(dir->subdirs);
    assert(dir->files);

    return dir;
}

void directory_print(directory_t* dir) 
{
    printf("Filename: %s\n", dir->path + 6); /* 6 skips root label */
    printf("This file is a directory.\n");
    printf("Clusters: %u", dir->cluster);
    if (dir->cluster_size > 1)
        printf("-%u", dir->cluster + dir->cluster_size - 1);
    printf("\n\n");

    directory_root_print(dir);
}

void directory_root_print(directory_t* directory)
{
    int i;
    for(i = 0; i < directory->subdir_count; i++) 
        directory_print(directory->subdirs[i]);
    for(i = 0; i < directory->file_count; i++)  
        file_print(directory->files[i]);
}

directory_t* directory_root(fsinfo_t* fsinfo, uint32_t root_cluster) 
{
    /* fake a root entry */
    direntry_t* root_entry = malloc(sizeof(direntry_t));
    assert(root_entry);
    memset(root_entry->filename, ' ', 11);
    memcpy(root_entry->filename, "FATx2", 5);
    root_entry->filename[3] = fsinfo->type == FAT32 ? '3' : '1';
    root_entry->cluster = root_cluster;

    directory_t* dir = directory_init(fsinfo, root_entry, NULL);
    assert(dir);

    if (fsinfo->type == FAT32) {
        /* we can treat the root directory as any other */
        directory_fill(fsinfo, dir);
    }
    else if (fsinfo->type == FAT12) {
        /* root is a special case in FAT12 */
        int i;
        uint32_t max_root_dirs = 32 * fsinfo->sector_size / sizeof(direntry_t);

        void* root_ptr = fs_sector_ptr(fsinfo, fsinfo->rootdir_offset);
        for (i = 0; i < max_root_dirs; i++) 
        {
            direntry_t* child = (direntry_t*)((intptr_t)root_ptr + i * sizeof(direntry_t));
            if (child->filename[0] == 0x00) break;
            if (child->filename[0] == 0xE5) continue;

            if (entry_is_directory(child)) {
                directory_t* subdir = directory_init(fsinfo, child, dir);
                directory_fill(fsinfo, subdir);
                directory_append_subdir(dir, subdir);
            }
            else {
                file_t* file = file_init(fsinfo, child, dir);
                directory_append_file(dir, file);
            }
        }
    }

    return dir;
}

void directory_fill(fsinfo_t* fsinfo, directory_t* dir) 
{
    /* sanity check, dont recurse up the directory tree */
    if (dir->entry->filename[0] == '.')
        return;

    /* loop through entries */
    uint32_t cluster = dir->cluster;
    uint32_t dirs_per_cluster = fsinfo->cluster_size * fsinfo->sector_size / sizeof(direntry_t);
    do {
        void* cluster_ptr = fs_sector_ptr(fsinfo, fs_cluster_sector(fsinfo, cluster));

        int i;
        for(i = 0; i < dirs_per_cluster; i++) {
            direntry_t* child = (direntry_t*)((intptr_t)cluster_ptr + i * sizeof(direntry_t));

            if (child->filename[0] == 0x00) break;
            if (child->filename[0] == 0xE5) continue;

            if (entry_is_directory(child)) {
                /* create subdirectory entry */
                directory_t* subdir = directory_init(fsinfo, child, dir);
                directory_fill(fsinfo, subdir);
                directory_append_subdir(dir, subdir);
            }
            else {
                /* create file entry */
                file_t* file = file_init(fsinfo, child, dir);
                directory_append_file(dir, file);
            }
        }

        cluster = fs_next_cluster(fsinfo, cluster);
    }
    while(cluster != 0);
}

void directory_free(directory_t** dir_ptr) 
{
    assert(dir_ptr);
    directory_t* directory = *dir_ptr;

    /* free directory and all nested structures */
    int i;
    for(i = 0; i < directory->subdir_count; i++) 
        directory_free(&directory->subdirs[i]);
    for(i = 0; i < directory->file_count; i++) 
        file_free(&directory->files[i]);
    free(directory->subdirs);
    free(directory->files);
    free(directory->path);
    free(directory);

    /* forget about it */
    *dir_ptr = NULL;
}

/* returns the full directory name (allocated) */
char* directory_path(directory_t* dir) 
{
    char* parent_name = NULL;
    size_t parent_len = 0;
    if (dir->parent != NULL) {
        parent_name = dir->parent->path;
        parent_len  = strlen(parent_name);
    }

    uint32_t namelen = entry_namelen(dir->entry);
    uint32_t newlen = parent_len + namelen + 2;

    char* path = malloc(newlen);
    path[newlen - 1] = '\0';

    if (parent_len > 0)
        strncpy(path, parent_name, parent_len);
    
    strncpy(path + parent_len + 1, (const char*)dir->entry->filename, namelen);
    path[parent_len] = '/';

    return path;
}

void directory_append_subdir(directory_t* dir, directory_t* subdir) {
    /* realloc if neccessary */
    if (dir->subdir_count >= dir->max_subdirs) {
        dir->max_subdirs *= 2;
        dir->subdirs = realloc(dir->subdirs, dir->max_subdirs * sizeof(directory_t*));
        assert(dir->subdirs);
    }

    /* append to list */
    dir->subdirs[dir->subdir_count++] = subdir;
}

void directory_append_file(directory_t* dir, file_t* file) {
    /* realloc if neccessary */
    if (dir->file_count >= dir->max_files) {
        dir->max_files *= 2;
        dir->files = realloc(dir->files, dir->max_files * sizeof(file_t*));
        assert(dir->files);
    }

    /* append to list */
    dir->files[dir->file_count++] = file;
}
