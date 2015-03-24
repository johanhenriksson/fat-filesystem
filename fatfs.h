/*
 * fatfs.h
 *
 * Definition of the structure used to represent a FAT filesystem.
 */

#ifndef FATFS_H
#define FATFS_H

#include <stdlib.h>
#include <stdint.h>

#include "fat12.h"
#include "fat32.h"

enum FS_TYPE {
  FAT12 = 12,
  FAT16 = 16,
  FAT32 = 32
};

typedef enum FS_TYPE FS_TYPE;

struct fsinfo_t
{
    FS_TYPE  fs_type;
    void     *disk_start;      /* This is where in memory the disk starts   */
    size_t   sector_size;      /* Size of one sector on the disk.           */
    uint32_t cluster_size;     /* Number of sectors per cluster.            */
    uint32_t rootdir_size;     /* Number of entries in root directory.      */

    uint32_t sectors_per_fat;  /* Number of sectors per fat.                */
    uint32_t hidden_sectors;   /* Number of hidden sectors.                 */
    uint32_t reserved_sectors; /* Number of reserved sectors.               */
    uint32_t sectors_for_root; /* Number of sectors for root directory.     */

    uint32_t fat_offset;       /* First sector of the first FAT copy.       */
    uint32_t rootdir_offset;   /* First sector of the root directory.       */
    uint32_t cluster_offset;   /* Sector number of the first cluster.       */
 
}; 

typedef struct fsinfo_t fsinfo_t;

/*
 * Function to open the file system.
 */
void* open_filesystem(const char* filename);

/*
 * This function sets up information about a FAT filesystem that will be used to read from
 * that file system.
 */
fsinfo_t* fsinfo_init(void *disk_start);

#endif
