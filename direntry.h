/*
 * direntry.h
 *
 * Functions used to deal with directory entries.
 */

#ifndef DIRENTRY_H
#define DIRENTRY_H

#include <stdbool.h>
#include <stdint.h>
#include "fatfs.h"

enum DIR_ATTR {
    DIR_READ_ONLY       = 0x01,
    DIR_HIDDEN          = 0x02,
    DIR_SYSTEM          = 0x04,
    DIR_VOLUME_LABEL    = 0x08,
    DIR_SUBDIR          = 0x10,
    DIR_ARCHIVE         = 0x20,
    DIR_DEVICE          = 0x40,
    DIR_RESERVED        = 0x80,
};

typedef enum DIR_ATTR DIR_ATTR;

struct direntry_t 
{
    uint8_t     filename[8];
    uint8_t     ext[3];
    uint8_t     attr;
    uint8_t     reserved[10];

    /* bit fields - total size 32 bits */
    uint32_t    hour     : 5    __attribute((packed));
    uint32_t    minute   : 6    __attribute((packed));
    uint32_t    seconds2 : 5    __attribute((packed));
    uint32_t    year     : 7    __attribute((packed));
    uint32_t    month    : 4    __attribute((packed));
    uint32_t    day      : 5    __attribute((packed));

    uint16_t    cluster         __attribute((packed));
    uint32_t    size            __attribute((packed));
}
__attribute((packed));

typedef struct direntry_t direntry_t;

bool dir_exists(direntry_t* dir);
bool dir_is_deleted(direntry_t* dir); 
bool dir_is_directory(direntry_t* dir);
uint32_t dir_cluster_size(direntry_t* dir, fsinfo_t* fsinfo);

#endif
