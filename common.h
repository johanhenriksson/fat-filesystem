#ifndef COMMON_H
#define COMMON_H

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
#define CLUSTER_OFFSET -2

typedef struct file_t file_t;
typedef struct directory_t directory_t;

#endif
