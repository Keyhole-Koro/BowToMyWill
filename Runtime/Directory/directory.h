#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cJSON.h>

#include "file.h"
#include "accessPrivilege.h"

typedef struct Directory {
    char *name;
    AccessPrivilege *privilege;
    struct Directory *parent;
    struct Directory *subdirs;
    File *files;
    struct Directory *next;
} Directory;


Directory *createDirectory(const char *name, Directory *parent);

void addFileToDirectory(Directory *dir, File *file);

void addSubdirectory(Directory *parent, Directory *subdir);

void *fetch(Directory *dir, const char *path);

#endif