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

struct fsinfo_sector_t {
    uint8_t signature[4];
    uint8_t reserved[480];

    uint8_t  info_signature[4];
    uint32_t free_clusters      __attribute((packed));
    uint32_t last_allocated     __attribute((packed));

    uint8_t  reserved2[12];

};

#endif
