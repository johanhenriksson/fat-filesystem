/*
 * blockio.c
 *
 * Low-level functions used to perform  i/o operations on blocks (sectors). All of them
 * take as parameter an object  that contains information about the file that
 * is being accessed, the size of a sector, etc.
 */
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "blockio.h"

int block_copy(void** dest_ptr, void* src, size_t len) 
{
    /* allocate a new buffer */
    void* block = malloc(len);
    if (block == NULL) {
        printf("block_copy error: malloc failed\n");
        return 1;
    }

    /* copy block of memory */
    memcpy(block, src, len);
    
    *dest_ptr = block;
    return 0;
}

int block_free(void** block_ptr) {
    void* block = *block_ptr;
    free(block);
    *block_ptr = NULL;
    return 0;
}
