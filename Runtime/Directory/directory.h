#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cJSON.h>

#include "data.h"
#include "accessPrivilege.h"

#include "utils.h"

typedef struct Directory {
    char *name;
    AccessPrivilege *privilege;
    struct Directory *parent;
    struct Directory *subdirs;
    Data *data;
    struct Directory *next;
} Directory;


Directory *createDirectory(const char *name, Directory *parent);

void addDataToDirectory(Directory *dir, Data *data);

void addSubdirectory(Directory *parent, Directory *subdir);

void *fetch(Directory *dir, const char *path);

#endif