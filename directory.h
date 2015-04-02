#ifndef DIRECTORY_H
#define DIRECTORY_H 1

#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "common.h"
#include "direntry.h"

#define MAX_FILE_ALLOC   5
#define MAX_SUBDIR_ALLOC 5

/* serves as an abstraction on top of the directory entries */
struct directory_t 
{
    directory_t*    parent;
    direntry_t*     entry;
    uint32_t        sector;
    uint32_t        cluster;
    uint32_t        cluster_size;
    uint32_t        subdir_count;
    uint32_t        file_count;
    uint32_t        max_subdirs;
    uint32_t        max_files;
    char*           path;

    directory_t**   subdirs;
    file_t**        files;
};

directory_t* directory_init(fsinfo_t* fsinfo, direntry_t* entry, directory_t* parent); 
directory_t* directory_root(fsinfo_t* fsinfo, uint32_t root_cluster);

void directory_free(directory_t** dir_ptr);
void directory_print(directory_t* dir);
void directory_root_print(directory_t* root_dir);

#endif
