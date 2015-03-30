/*
 * blockio.h
 *
 * Low-level functions used to perform  i/o operations on blocks. All of them
 * take as parameter an object  that contains information about the file that
 * is being accessed, the size of a sector, etc.
 */

#ifndef BLOCKIO_H
#define BLOCKIO_H

#include <stdlib.h>

/* allocates a buffer and copies a block of memory to it */
int block_copy(void** dest_ptr, void* src, size_t len);

/* frees an allocated buffer and sets its pointer to null */
int block_free(void** block_ptr); 

#endif
