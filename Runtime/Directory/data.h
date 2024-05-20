#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cJSON.h>

typedef struct Data {
    char *name;
    size_t size;
    cJSON *payload;
    struct Data *next;
} Data;

Data *createData(const char *name, const char *payload, size_t size);

#endif