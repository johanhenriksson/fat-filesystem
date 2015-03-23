/*
 * fatfs.c
 *
 * Basic operations on a FAT filesystem.
 */

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>

#include "fatfs.h"

/**
 * How to use this program.
 */
#define USAGE "Usage: %s file-system-file\n"

/*
 * Default size of one sector.
 */
#define DEFAULT_SECTOR_SIZE 512

/*
 * Size of one directory entry.
 */
#define DIR_ENTRY_SIZE 32

/*
 * Function to open the file system and map it into memory. 
 */
void * open_filesystem(int argc, char *argv[])
{
    char *filename;
    void *memory; 
    int fd;
    struct stat statBuff;

    if (argc == 2)
    {
	filename = argv[1];
    }
    else
    {
	fprintf(stderr, USAGE, argv[0]);
	exit(1);
    }

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
      char buff[256];
      snprintf(buff, 256, "Could not open %s", filename);
      perror(buff);
      exit(1);
    }
    
    if (fstat(fd, &statBuff)) {
	perror("Stat failed");
	exit(1);
    }
    memory = mmap(0, statBuff.st_size, PROT_READ,  MAP_FILE | MAP_PRIVATE, fd, 0);
    if (memory == NULL) {
      perror("MMAP of file failed");
      exit(1);
    }
    return memory;
}

/*
 * This function sets up information about a FAT filesystem that will be used to read from
 * that file system.
 */
filesystem_info *initialize_filesystem_info(void *diskStart)
{
    filesystem_info *fsinfo = (filesystem_info *) malloc(sizeof(filesystem_info));
    
    // ADD CODE 

    return fsinfo;
}

