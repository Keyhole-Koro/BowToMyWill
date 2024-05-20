#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cJSON.h>

typedef struct File {
    char *name;
    size_t size;
    cJSON *payload;
    struct File *next;
} File;

File *createFile(const char *name, const char *payload, size_t size);

#endif