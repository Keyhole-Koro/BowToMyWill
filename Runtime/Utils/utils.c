#include "utils.h"

char **split_path(const char *path, int *count) {
    char *path_copy = strdup(path);
    char *token;
    char **tokens = NULL;
    int tokens_count = 0;

    token = strtok(path_copy, "/");
    while (token != NULL) {
        tokens = (char **)realloc(tokens, sizeof(char *) * (tokens_count + 1));
        tokens[tokens_count] = strdup(token);
        tokens_count++;
        token = strtok(NULL, "/");
    }

    free(path_copy);
    *count = tokens_count;
    return tokens;
}