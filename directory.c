#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "file.h"
#include "fatfs.h"
#include "directory.h"

void directory_fill(fsinfo_t*, directory_t*);

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

    printf("Directory: %s\n", dir->path);

    directory_fill(fsinfo, dir);

    return dir;
}

directory_t* directory_root(fsinfo_t* fsinfo, uint32_t root_cluster) 
{
    directory_t* dir = (directory_t*)malloc(sizeof(directory_t));
    assert(dir);

    dir->parent = NULL;
    dir->cluster = root_cluster;
    dir->cluster_size = fs_cluster_size(fsinfo, root_cluster);
    
    char* root_name = malloc(2 * sizeof(char));
    root_name = "/";
    dir->path = root_name;

    if (fsinfo->type == FAT32) {
        /* we can treat the root directory as any other */
        directory_fill(fsinfo, dir);
    }
    else if (fsinfo->type == FAT12) {
        /* root is a special case in FAT12 */

        int i;
        uint32_t max_root_dirs = 32 * fsinfo->sector_size / sizeof(direntry_t);

        void* root_ptr = fs_sector_ptr(fsinfo, fsinfo->rootdir_offset);
        for (i = 0; i < max_root_dirs; i++) {
            direntry_t* child = (direntry_t*)((intptr_t)root_ptr + i * sizeof(direntry_t));
            if (child->filename[0] == 0x00) break;
            if (child->filename[0] == 0xE5) continue;
            if (child->filename[0] == '.')  continue;

            if (entry_is_directory(child)) {
                directory_t* subdir = directory_init(fsinfo, child, dir);
                //printf("path %s\n", subdir->path);
            }
            else {
                file_t* file = file_init(fsinfo, child, dir);
            }
        }
    }

    return dir;
}

void directory_fill(fsinfo_t* fsinfo, directory_t* dir) 
{
    uint32_t dirs_per_cluster = fsinfo->cluster_size * fsinfo->sector_size / sizeof(direntry_t);

    /* loop through entries */
    uint32_t cluster = dir->cluster;
    do {
        void* cluster_ptr = fs_sector_ptr(fsinfo, fs_cluster_sector(fsinfo, cluster));

        int i;
        for(i = 0; i < dirs_per_cluster; i++) {
            direntry_t* child = (direntry_t*)((intptr_t)cluster_ptr + i * sizeof(direntry_t));

            if (child->filename[0] == 0x00) break;
            if (child->filename[0] == 0xE5) continue;
            if (child->filename[0] == '.')  continue;

            if (entry_is_directory(child)) {
                /* create subdirectory entry */
                directory_t* subdir = directory_init(fsinfo, child, dir);
            }
            else {
                /* create file entry */
                file_t* file = file_init(fsinfo, child, dir);
            }
        }

        cluster = fs_next_cluster(fsinfo, cluster);
    }
    while(cluster != 0);
}

void directory_free(directory_t** dir_ptr) {
    assert(dir_ptr);
    free(*dir_ptr);
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
    
    strncpy(path + parent_len, (const char*)dir->entry->filename, namelen);
    path[parent_len + namelen] = '/';

    return path;
}
