/*
 * fat12.c
 *
 */
#include <stdio.h>

#include "fat12.h"

uint32_t read_fat12(void* fat_start, uint32_t fat_idx) 
{
    uint32_t triple_idx = fat_idx / 2;
    uint32_t high = fat_idx % 2;
    uint8_t* ptr = (uint8_t*)(fat_start + 3 * triple_idx);

    if (high) {
        uint8_t mid = ((ptr[1] & 0xF0) >> 4);
        uint8_t high = ptr[2]; 
        return (high << 4) + mid; 
    }
    else {
        uint8_t mid = (ptr[1] & 0x0F);
        uint8_t low = ptr[0]; 
        return (mid << 8) + low;
    }
}


