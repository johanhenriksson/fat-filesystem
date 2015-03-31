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

#include "fat.h"
#include "fat12.h"
#include "fat32.h"
#include "fatfs.h"

/**
 * How to use this program.
 */
#define USAGE "Usage: %s file-system-file\n"

/*
 * Default size of one sector.
 */
#define DEFAULT_SECTOR_SIZE 512

/*
 * Size of one directory entry.
 */
#define DIR_ENTRY_SIZE 32

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
    fsinfo->sectors_for_root = fsinfo->rootdir_size * 32 / fsinfo->sector_size;

    fsinfo->fat_offset     = fsinfo->reserved_sectors;

    /* determine file system type (FAT12/FAT32) */
    fsinfo->type = fsinfo->rootdir_size == 0 ? FAT32 : FAT12;

    /* version specific stuff */
    if (fsinfo->type == FAT12) {
        printf("Filesystem type is FAT12\n");
        bootsect_fat12_t* bootsect_f12 = (bootsect_fat12_t*)disk_start;

        fsinfo->sectors_per_fat  = bootsect_f12->fat_size;
        fsinfo->hidden_sectors   = bootsect_f12->hidden_sectors;

        fsinfo->rootdir_offset = fsinfo->fat_offset + fsinfo->fat_count * fsinfo->sectors_per_fat;
    }

    if (fsinfo->type == FAT32) {
        printf("Filesystem type is FAT32\n");
        bootsect_fat32_t* bootsect_f32 = (bootsect_fat32_t*)disk_start;

        fsinfo->sectors_per_fat  = bootsect_f32->fat_size;
        fsinfo->hidden_sectors   = bootsect_f32->hidden_sectors;

        fsinfo->rootdir_offset   = bootsect_f32->root_cluster;
    }

    /* calculate offsets */
    fsinfo->cluster_offset = fsinfo->rootdir_offset + fsinfo->sectors_for_root;

    return fsinfo;
}

/* returns a pointer to the given cluster */
void* fs_cluster_ptr(fsinfo_t* fsinfo, uint32_t cluster_idx) 
{
    /* disk_start + sector size * cluster_size * cluster_idx */
    size_t cluster_size = fsinfo->sector_size * fsinfo->cluster_size;
    return (void*)(fsinfo->disk_start + cluster_size * cluster_idx);
}

