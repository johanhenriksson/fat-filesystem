#ifndef DIRECTORY_H
#define DIRECTORY_H 1

#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "common.h"
#include "direntry.h"

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
    char*           path;

    file_t**        files;
};

directory_t* directory_init(fsinfo_t* fsinfo, direntry_t* entry, directory_t* parent); 
directory_t* directory_root(fsinfo_t* fsinfo, uint32_t root_cluster);

void directory_free(directory_t** dir_ptr);

#endif
