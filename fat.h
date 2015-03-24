#ifndef FAT_H
#define FAT_H

#include <stdint.h>

/* contains common fat12/32 stuff */

typedef enum {
    BM_FLOPPY = 0xf0,
    BM_HDD    = 0xf8,
} 
BOOT_MEDIA_TYPE;
 
/** Boot sector struct - 512 bytes */
struct bootsect_t 
{
    uint8_t     boot_jump[3];                              /* 0  Jump to bootstrap */
    uint8_t     oem_name[8];                               /* 3  OEM Manufacturer name */
    uint16_t    sector_size         __attribute((packed)); /* 11 Sector size in bytes */
    uint8_t     cluster_size;                              /* 13 Sectors per cluster */
    uint16_t    reserved_sectors    __attribute((packed)); /* 14 Number of reserved sectors */
    uint8_t     fat_copies;                                /* 16 # of FAT copies */
    uint16_t    root_dir_entries    __attribute((packed)); /* 17 # of root directory entries */
    uint16_t    total_sectors       __attribute((packed)); /* 19 Total number of sectors */
    uint8_t     media_type;                                /* 21 Media type */
    uint16_t    fat_sector_size     __attribute((packed)); /* 22 Number of sectors per FAT */
    uint16_t    sectors_per_track   __attribute((packed)); /* 24 Number of sectors per track */
    uint16_t    head_count          __attribute((packed)); /* 26 Number of heads */
    uint16_t    hidden_sectors      __attribute((packed)); /* 28 Number of hidden sectors */
    uint8_t     bootstrap[480];                            /* 30 Bootstrap code */
    uint8_t     signature[2];                              /* 509 Boot sector signature 0x55 0xAA */
} 
__attribute((packed));

typedef struct bootsect_t bootsect_t;

struct fat12 {
    bootsect_t bootsect; 
}
__attribute((packed));

#endif
