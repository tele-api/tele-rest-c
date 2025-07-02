/*
 * post_get_updates_request.h
 *
 * 
 */

#ifndef _post_get_updates_request_H_
#define _post_get_updates_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_get_updates_request_t post_get_updates_request_t;




typedef struct post_get_updates_request_t {
    int offset; //numeric
    int limit; //numeric
    int timeout; //numeric
    list_t *allowed_updates; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} post_get_updates_request_t;

__attribute__((deprecated)) post_get_updates_request_t *post_get_updates_request_create(
    int offset,
    int limit,
    int timeout,
    list_t *allowed_updates
);

void post_get_updates_request_free(post_get_updates_request_t *post_get_updates_request);

post_get_updates_request_t *post_get_updates_request_parseFromJSON(cJSON *post_get_updates_requestJSON);

cJSON *post_get_updates_request_convertToJSON(post_get_updates_request_t *post_get_updates_request);

#endif /* _post_get_updates_request_H_ */

