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

/* recursive function to determine length of fat32 cluster chain */
uint32_t fat32_cluster_size(void* fat_start, uint32_t cluster_idx, uint32_t size) 
{
    uint32_t next = read_fat32(fat_start, cluster_idx);
    
    if (next < 0x002 || next >= 0xFF0) 
        return size + 1;
    
    return fat32_cluster_size(fat_start, next, size + 1);
}
