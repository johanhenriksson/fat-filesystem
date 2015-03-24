/*
 * Program to print information about a FAT file system.
 */
#include <stdio.h>

#include "fat.h"
#include "fatfs.h"
#include "wordio.h"
#include "blockio.h"
#include "directory.h"

/*
 * Function to print information about a FAT filesystem (useful for debugging).
 */
void print_filesystem_info(const fsinfo_t* fsinfo)
{
    printf("Sector size: %zu\n", fsinfo->sector_size);
    printf("Cluster size in sectors: %u\n", fsinfo->cluster_size);
    printf("Root directory size (nb of entries): %u\n", fsinfo->rootdir_size);

    printf("Sectors per fat: %u\n", fsinfo->sectors_per_fat);
    printf("Reserved sectors: %u\n", fsinfo->reserved_sectors);
    printf("Hidden sectors: %u\n", fsinfo->hidden_sectors);

    printf("Fat offset in sectors: %u\n", fsinfo->fat_offset);
    printf("Root directory offset in sectors: %u\n", fsinfo->rootdir_offset);
    printf("First cluster offset in sectors: %u\n", fsinfo->cluster_offset);
}

/*
 * Main function.
 */
int main(int argc, char *argv[])
{
    if (argc < 2) {
    }

    void * mem = open_filesystem(argv[1]);
    int i;

    printf("size: %lu\n", sizeof(bootsect_t));

    fsinfo_t* fsinfo = fsinfo_init(mem);
    print_filesystem_info(fsinfo);
    putchar('\n');

    // Add call to function to print the directory tree
    
}
