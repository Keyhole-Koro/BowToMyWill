#include "file.h"

File *createFile(const char *name, const char *payload, size_t size) {
    File *file = (File *)malloc(sizeof(File));
    file->name = strdup(name);
    file->payload = cJSON_Parse(payload);
    file->size = size;
    file->next = NULL;
    return file;
}