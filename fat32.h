/*
 * fat32.h
 *
 * Functions used to deal with the file allocation table.
 */
#ifndef FAT32_H
#define FAT32_H

#include <stdint.h>

#include "fat12.h"


// Any FAT 32 specific data structures go here as well as function prototypes. Some examples
// FAT32 specific code might be the code to determine the next cluster from a FAT table entry.

/** FAT32 Boot sector struct - 512 bytes */
struct bootsect_fat32_t 
{
    bootsect_common_t common;

    uint16_t    unused1             __attribute((packed)); /* 22 Number of sectors per FAT */
    uint16_t    sectors_per_track   __attribute((packed)); /* 24 Number of sectors per track */
    uint16_t    head_count          __attribute((packed)); /* 26 Number of heads */

    uint32_t    hidden_sectors      __attribute((packed)); /* 28 Number of hidden sectors */
    uint32_t    total_sectors       __attribute((packed)); /* 32 */
    uint32_t    fat_size            __attribute((packed)); /* 36 */
    uint16_t    mirror_flags        __attribute((packed)); /* 40 */
    uint16_t    fs_version          __attribute((packed)); /* 42 */

    uint32_t    root_cluster        __attribute((packed)); /* 44 */
    uint16_t    fsinfo_sector       __attribute((packed)); /* 48 */
    uint16_t    backup_boot_sector  __attribute((packed)); /* 50 */
    uint8_t     unused3[12];                               /* 52 */
    uint8_t     drive_number;                              /* 64 */
    uint8_t     unused4;                                   /* 65 */
    uint8_t     ext_signature;                             /* 66 */
    
    uint32_t    serial_no           __attribute((packed)); /* 67 */
    uint8_t     label[11];                                 /* 71 */
    uint8_t     fs_type[8];                                /* 82 */

    uint8_t     bootstrap[420];                            /* 90 Bootstrap code */
    uint8_t     signature[2];                              /* 510 Boot sector signature 0x55 0xAA */
} 
__attribute((packed));

typedef struct bootsect_fat32_t bootsect_fat32_t;

struct fsinfo_sector_t 
{
    uint8_t signature[4];
    uint8_t reserved[480];

    uint8_t  info_signature[4];
    uint32_t free_clusters      __attribute((packed));
    uint32_t last_allocated     __attribute((packed));

    uint8_t  reserved2[12];

};

uint32_t read_fat32(void* fat_start, uint32_t fat_idx);

#endif
