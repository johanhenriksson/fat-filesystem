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
 
/** FAT12 Boot sector struct - 512 bytes */
struct bootsect_fat12_t 
{
    bootsect_common_t common;

    uint16_t    fat_size            __attribute((packed)); /* 22 Number of sectors per FAT */
    uint16_t    sectors_per_track   __attribute((packed)); /* 24 Number of sectors per track */
    uint16_t    head_count          __attribute((packed)); /* 26 Number of heads */
    uint16_t    hidden_sectors      __attribute((packed)); /* 28 Number of hidden sectors */
    uint8_t     bootstrap[480];                            /* 30 Bootstrap code */
    uint8_t     signature[2];                              /* 509 Boot sector signature 0x55 0xAA */
} 
__attribute((packed));

typedef struct bootsect_fat12_t bootsect_fat12_t;

/** FAT32 Boot sector struct - 512 bytes */
struct bootsect_fat32_t 
{
    bootsect_common_t common;

    uint16_t    unused1             __attribute((packed)); /* 22 Number of sectors per FAT */
    uint16_t    sectors_per_track   __attribute((packed)); /* 24 Number of sectors per track */
    uint16_t    head_count          __attribute((packed)); /* 26 Number of heads */

    uint32_t    hidden_sectors      __attribute((packed)); /* 28 Number of hidden sectors */
    uint32_t    total_sectors       __attribute((packed)); /* 32 */
    uint32_t    fat_size            __attribute((packed)); /* 36 */
    uint16_t    mirror_flags        __attribute((packed)); /* 40 */
    uint16_t    fs_version          __attribute((packed)); /* 42 */

    uint32_t    root_cluster        __attribute((packed)); /* 44 */
    uint16_t    fsinfo_sector       __attribute((packed)); /* 48 */
    uint16_t    backup_boot_sector  __attribute((packed)); /* 50 */
    uint8_t     unused3[12];                               /* 52 */
    uint8_t     drive_number;                              /* 64 */
    uint8_t     unused4;                                   /* 65 */
    uint8_t     ext_signature;                             /* 66 */
    
    uint32_t    serial_no           __attribute((packed)); /* 67 */
    uint8_t     label[11];                                 /* 71 */
    uint8_t     fs_type[8];                                /* 82 */

    uint8_t     bootstrap[420];                            /* 90 Bootstrap code */
    uint8_t     signature[2];                              /* 510 Boot sector signature 0x55 0xAA */
} 
__attribute((packed));

typedef struct bootsect_fat32_t bootsect_fat32_t;

#endif
