/*
 * direntry.c
 *
 * Functions used to deal with directory entries.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "fatfs.h"
#include "fat12.h"
#include "fat32.h"
#include "direntry.h"

bool dir_exists(direntry_t* dir) {
    if (dir->filename[0] == 0x00)
        return false;
    return dir_is_deleted(dir);
}

bool dir_is_deleted(direntry_t* dir) {
    return dir->filename[0] == 0xe5;
}

bool dir_is_directory(direntry_t* dir) {
    return strncmp((const char*)dir->ext, "   ", 3) == 0;
}

uint32_t dir_cluster_size(direntry_t* dir, fsinfo_t* fsinfo) 
{
    void* fat_start = fs_sector_ptr(fsinfo, fsinfo->fat_offset);
    if (fsinfo->type == FAT12) {
        return fat12_cluster_size(fat_start, dir->cluster, 0);
    }
    if (fsinfo->type == FAT32) {
        return fat32_cluster_size(fat_start, dir->cluster, 0);
    }

    printf("Unknown file system type\n");
    exit(1);
}
