/*
 * fat12.h
 *
 * Functions used to deal with the file allocation table.
 */
#ifndef FAT12_H
#define FAT12_H

#include "fat.h"
#include <stdint.h>

/** FAT12 Boot sector struct - 512 bytes */
struct bootsect_fat12_t 
{
    bootsect_common_t common;

    uint16_t    fat_size            __attribute((packed)); /* 22  Number of sectors per FAT */
    uint16_t    sectors_per_track   __attribute((packed)); /* 24  Number of sectors per track */
    uint16_t    head_count          __attribute((packed)); /* 26  Number of heads */
    uint16_t    hidden_sectors      __attribute((packed)); /* 28  Number of hidden sectors */
    uint8_t     bootstrap[480];                            /* 30  Bootstrap code */
    uint8_t     signature[2];                              /* 510 Boot sector signature 0x55 0xAA */
} 
__attribute((packed));

typedef struct bootsect_fat12_t bootsect_fat12_t;

uint32_t read_fat12(void* fat_start, uint32_t fat_idx);

#endif
