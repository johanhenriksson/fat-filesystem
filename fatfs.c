/*
 * fatfs.c
 *
 * Basic operations on a FAT filesystem.
 */

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <string.h>

#include "common.h"
#include "fat.h"
#include "fat12.h"
#include "fat32.h"
#include "fatfs.h"
#include "direntry.h"
#include "directory.h"

/*
 * Function to open the file system and map it into memory. 
 */
void* open_filesystem(const char* filename)
{
    void *memory; 
    int fd;
    struct stat statBuff;

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        char buff[256];
        snprintf(buff, 256, "Could not open %s", filename);
        perror(buff);
        exit(1);
    }
    
    if (fstat(fd, &statBuff)) {
        perror("Stat failed");
        exit(1);
    }

    memory = mmap(0, statBuff.st_size, PROT_READ,  MAP_FILE | MAP_PRIVATE, fd, 0);
    if (memory == NULL) {
        perror("MMAP of file system file failed");
        exit(1);
    }
    return memory;
}

/*
 * This function sets up information about a FAT filesystem that will be used to read from
 * that file system.
 */
fsinfo_t* fsinfo_init(void *disk_start)
{
    fsinfo_t* fsinfo = (fsinfo_t*)malloc(sizeof(fsinfo_t));
    memset(fsinfo, 0, sizeof(fsinfo_t));
    
    fsinfo->disk_start = disk_start;

    /* Read from boot sector */
    bootsect_common_t* bootsect = (bootsect_common_t*)disk_start;

    fsinfo->sector_size      = bootsect->sector_size;
    fsinfo->cluster_size     = bootsect->cluster_size;
    fsinfo->rootdir_size     = bootsect->root_dir_entries;
    fsinfo->reserved_sectors = bootsect->reserved_sectors;
    fsinfo->fat_count        = bootsect->fat_copies;
    fsinfo->sectors_for_root = fsinfo->rootdir_size * DIR_ENTRY_SIZE / fsinfo->sector_size;
    fsinfo->fat_offset       = fsinfo->reserved_sectors;

    /* determine file system type (FAT12/FAT32) */
    fsinfo->type = fsinfo->rootdir_size == 0 
        ? FAT32 
        : FAT12;

    /* version specific stuff */
    if (fsinfo->type == FAT12) {
        bootsect_fat12_t* bootsect_f12 = (bootsect_fat12_t*)disk_start;

        fsinfo->sectors_per_fat  = bootsect_f12->fat_size;
        fsinfo->hidden_sectors   = bootsect_f12->hidden_sectors;

        fsinfo->rootdir_offset   = fsinfo->fat_offset + fsinfo->fat_count * fsinfo->sectors_per_fat;
        fsinfo->cluster_offset   = fsinfo->rootdir_offset + fsinfo->sectors_for_root;
    }

    if (fsinfo->type == FAT32) {
        bootsect_fat32_t* bootsect_f32 = (bootsect_fat32_t*)disk_start;

        fsinfo->sectors_per_fat  = bootsect_f32->fat_size;
        fsinfo->hidden_sectors   = bootsect_f32->hidden_sectors;

        fsinfo->rootdir_offset   = fsinfo->fat_offset + bootsect_f32->fat_size * fsinfo->fat_count;
        fsinfo->cluster_offset   = fsinfo->rootdir_offset;
    }

    return fsinfo;
}

/* returns a pointer to the given cluster */
void* fs_sector_ptr(fsinfo_t* fsinfo, uint32_t sector) {
    return (void*)(fsinfo->disk_start + sector * fsinfo->sector_size);
}

uint32_t fs_cluster_sector(fsinfo_t* fsinfo, uint32_t cluster) {
    if (cluster < 2) {
        printf("Clusters 0 and 1 cannot be accessed\n");
        exit(1);
    }
    return fsinfo->cluster_offset + (cluster + CLUSTER_OFFSET) * fsinfo->cluster_size;
}

uint32_t fs_cluster_size(fsinfo_t* fsinfo, uint32_t start_cluster) {
    uint32_t size = 1;
    uint32_t cluster = start_cluster;
    while((cluster = fs_next_cluster(fsinfo, cluster)))
        size++;
    return size;
}

uint32_t fs_next_cluster(fsinfo_t* fsinfo, uint32_t cluster) 
{
    uint32_t next = 0;
    void* fat_start = fs_sector_ptr(fsinfo, fsinfo->fat_offset);
    if (fsinfo->type == FAT32) {
        next = read_fat32(fat_start, cluster);
        if (next < 0x002 || next >= 0x0FFFFFF0) 
            return 0;
    }
    else if (fsinfo->type == FAT12) {
        next = read_fat12(fat_start, cluster);
        if (next < 0x002 || next >= 0xFF0) 
            return 0;
    }
    return next;
}
