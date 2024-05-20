#include "directory.h"

Directory *createDirectory(const char *name, Directory *parent) {
    Directory *dir = (Directory *)malloc(sizeof(Directory));
    dir->name = strdup(name);
    dir->parent = parent;
    dir->subdirs = NULL;
    dir->data = NULL;
    dir->next = NULL;
    return dir;
}

void addDataToDirectory(Directory *dir, Data *data) {
    data->next = dir->data;
    dir->data = data;
}

void addSubdirectory(Directory *parent, Directory *subdir) {
    subdir->next = parent->subdirs;
    parent->subdirs = subdir;
}

void *fetch(Directory *dir, const char *path) {
    int path_len;
    char **tokens = split_path(path, &path_len);

    Directory *current_dir = dir;
    void *result = NULL;

    for (int i = 0; i < path_len; i++) {
        char *token = tokens[i];
        result = NULL;

        Directory *subdir = current_dir->subdirs;
        while (subdir) {
            if (strcmp(subdir->name, token) == 0) {
                current_dir = subdir;
                result = current_dir;
                break;
            }
            subdir = subdir->next;
        }

        if (result == NULL) {
            Data *data = current_dir->data;
            while (data) {
                if (strcmp(data->name, token) == 0) {
                    result = data;
                    break;
                }
                data = data->next;
            }
        }

        if (result == NULL) break;
    }

    for (int i = 0; i < path_len; i++) {
        free(tokens[i]);
    }
    free(tokens);

    return result;
}