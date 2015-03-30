#ifndef FAT_H
#define FAT_H

#include <stdint.h>

/* contains common fat12/32 stuff */

typedef enum {
    BM_FLOPPY = 0xf0,
    BM_HDD    = 0xf8,
} 
BOOT_MEDIA_TYPE;

struct bootsect_common_t {
    uint8_t     boot_jump[3];                              /* 0  Jump to bootstrap */
    uint8_t     oem_name[8];                               /* 3  OEM Manufacturer name */
    uint16_t    sector_size         __attribute((packed)); /* 11 Sector size in bytes */
    uint8_t     cluster_size;                              /* 13 Sectors per cluster */
    uint16_t    reserved_sectors    __attribute((packed)); /* 14 Number of reserved sectors */
    uint8_t     fat_copies;                                /* 16 # of FAT copies */
    uint16_t    root_dir_entries    __attribute((packed)); /* 17 # of root directory entries */
    uint16_t    unused1             __attribute((packed)); /* 19 (UNUSED FAT32) Total number of sectors */
    uint8_t     media_type;                                /* 21 Media type */
}
__attribute((packed));

typedef struct bootsect_common_t bootsect_common_t;

#endif
