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
    file->cluster      = dir->cluster;
    file->cluster_size = fs_cluster_size(fsinfo, dir->cluster);
    file->byte_size    = entry->size;

    file->path = file_path(file);

    printf("File: %s\n", file->path);

    return file;
}

char* file_path(file_t* file) 
{
    directory_t* parent = file->directory;

    uint32_t namelen = entry_namelen(file->entry);
    uint32_t extlen  = entry_extlen(file->entry);

    size_t parent_len = strlen(parent->path);

    size_t newlen = parent_len + namelen + extlen + 2;

    char* path = malloc(newlen);
    assert(path);
    path[newlen - 1] = '\0';

    if (parent_len) 
        strncpy(path, parent->path, parent_len);

    strncpy(path + parent_len, (const char*)file->entry->filename, namelen);
    strncpy(path + parent_len + namelen + 1, (const char*)file->entry->ext, extlen);
    path[parent_len + namelen] = '.';
    
    return path;
}
