/*
 * direntry.c
 *
 * Functions used to deal with directory entries.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "fatfs.h"
#include "fat12.h"
#include "fat32.h"
#include "direntry.h"

bool entry_exists(direntry_t* dir) {
    if (dir->filename[0] == 0x00)
        return false;
    return entry_is_deleted(dir);
}

bool entry_is_deleted(direntry_t* dir) {
    return dir->filename[0] == 0xe5;
}

bool entry_is_directory(direntry_t* dir) 
{
    if (dir->filename[0] == '.')
        return true;
    return entry_extlen(dir) == 0;
}

uint32_t entry_totlen(direntry_t* dir) 
{
    uint32_t extlen = entry_extlen(dir);
    if (extlen > 0)
        extlen++; // add the fucking dot
    return entry_namelen(dir) + extlen;
}

uint32_t entry_namelen(direntry_t* dir) 
{
    uint32_t len = 8;
    while(len > 0) {
        if (dir->filename[len - 1] != 0x20)
            break;
        len--;
    }
    return len;
}

uint32_t entry_extlen(direntry_t* dir)
{
    uint32_t ext_len = 3;
    while(ext_len > 0) {
        if (dir->ext[ext_len - 1] != 0x20)
            break;
        ext_len--;
    }
    return ext_len;
}
