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
    bootsect_t* bootsect = (bootsect_t*)disk_start;

    /* Verify */
    if (bootsect->signature[0] != 0x55 || bootsect->signature[1] != 0xAA) {
        perror("Invalid boot sector signature");
        exit(1);
    }

    fsinfo->sector_size      = bootsect->sector_size;
    fsinfo->cluster_size     = bootsect->cluster_size;
    fsinfo->rootdir_size     = bootsect->root_dir_entries;
    fsinfo->sectors_per_fat  = bootsect->fat_sector_size;
    fsinfo->hidden_sectors   = bootsect->hidden_sectors;
    fsinfo->reserved_sectors = bootsect->reserved_sectors;

    return fsinfo;
}

