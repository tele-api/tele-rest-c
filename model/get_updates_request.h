/*
 * get_updates_request.h
 *
 * Request parameters for getUpdates
 */

#ifndef _get_updates_request_H_
#define _get_updates_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_updates_request_t get_updates_request_t;




typedef struct get_updates_request_t {
    int offset; //numeric
    int limit; //numeric
    int timeout; //numeric
    list_t *allowed_updates; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} get_updates_request_t;

__attribute__((deprecated)) get_updates_request_t *get_updates_request_create(
    int offset,
    int limit,
    int timeout,
    list_t *allowed_updates
);

void get_updates_request_free(get_updates_request_t *get_updates_request);

get_updates_request_t *get_updates_request_parseFromJSON(cJSON *get_updates_requestJSON);

cJSON *get_updates_request_convertToJSON(get_updates_request_t *get_updates_request);

#endif /* _get_updates_request_H_ */

