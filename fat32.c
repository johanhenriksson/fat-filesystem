/*
 * fat32.c
 *
 */
#include <stdio.h>

#include "fat32.h"

uint32_t read_fat32(void* fat_start, uint32_t fat_idx) {
    uint32_t* ptr = (uint32_t*)(fat_start + sizeof(uint32_t) * fat_idx);
    return *ptr;
}
