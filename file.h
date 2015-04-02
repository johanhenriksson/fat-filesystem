#ifndef FILE_H
#define FILE_H 1

#include "common.h"
#include "fatfs.h"
#include "direntry.h"
#include "directory.h"

struct file_t 
{
    directory_t*    directory;
    direntry_t*     entry;
    uint32_t        cluster;
    uint32_t        cluster_size;
    uint32_t        byte_size;
    char*           path;
};

file_t* file_init(fsinfo_t* fsinfo, direntry_t* entry, directory_t* dir); 

#endif
