#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "file.h"
#include "direntry.h"

char* file_path(file_t* dir); 

file_t* file_init(fsinfo_t* fsinfo, direntry_t* entry, directory_t* dir) 
{
    file_t* file = malloc(sizeof(file_t));
    assert(file);

    file->entry        = entry;
    file->directory    = dir;
    file->cluster      = entry->cluster;
    file->cluster_size = fs_cluster_size(fsinfo, entry->cluster);
    file->byte_size    = entry->size;

    file->path = file_path(file);

    return file;
}

char* file_path(file_t* file) 
{
    directory_t* parent = file->directory;

    uint32_t namelen = entry_namelen(file->entry);
    uint32_t extlen  = entry_extlen(file->entry);

    size_t parent_len = strlen(parent->path);

    size_t newlen = parent_len + namelen + extlen + 3;

    char* path = malloc(newlen);
    assert(path);
    path[parent_len] = '/';
    path[newlen - 1] = '\0';

    if (parent_len) 
        strncpy(path, parent->path, parent_len);

    strncpy(path + parent_len + 1, (const char*)file->entry->filename, namelen);

    if (extlen) {
        path[parent_len + namelen + 1] = '.';
        strncpy(path + parent_len + namelen + 2, (const char*)file->entry->ext, extlen);
    }
    
    return path;
}

void file_free(file_t** file_ptr) 
{
    assert(file_ptr);
    file_t* file = *file_ptr;

    free(file->path);
    free(file);

    *file_ptr = NULL;
}

void file_print(file_t* file) 
{
    printf("Filename: %s\n", file->path + 6); /* 6 removes root label */
    printf("Size: %u\n", file->byte_size);
    printf("Clusters: %u", file->cluster);
    if (file->cluster_size > 1)
        printf("-%u", file->cluster + file->cluster_size - 1);
    printf("\n\n");
}
