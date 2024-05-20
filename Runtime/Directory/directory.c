#include "directory.h"

Directory *createDirectory(const char *name, Directory *parent) {
    Directory *dir = (Directory *)malloc(sizeof(Directory));
    dir->name = strdup(name);
    dir->parent = parent;
    dir->subdirs = NULL;
    dir->files = NULL;
    dir->next = NULL;
    return dir;
}

void addFileToDirectory(Directory *dir, File *file) {
    file->next = dir->files;
    dir->files = file;
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
            File *file = current_dir->files;
            while (file) {
                if (strcmp(file->name, token) == 0) {
                    result = file;
                    break;
                }
                file = file->next;
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