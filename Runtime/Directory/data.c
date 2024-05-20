#include "data.h"

Data *createData(const char *name, const char *payload, size_t size) {
    Data *data = (Data *)malloc(sizeof(Data));
    data->name = strdup(name);
    data->payload = cJSON_Parse(payload);
    data->size = size;
    data->next = NULL;
    return data;
}