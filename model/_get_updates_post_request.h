/*
 * _get_updates_post_request.h
 *
 * 
 */

#ifndef __get_updates_post_request_H_
#define __get_updates_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _get_updates_post_request_t _get_updates_post_request_t;




typedef struct _get_updates_post_request_t {
    int offset; //numeric
    int limit; //numeric
    int timeout; //numeric
    list_t *allowed_updates; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} _get_updates_post_request_t;

__attribute__((deprecated)) _get_updates_post_request_t *_get_updates_post_request_create(
    int offset,
    int limit,
    int timeout,
    list_t *allowed_updates
);

void _get_updates_post_request_free(_get_updates_post_request_t *_get_updates_post_request);

_get_updates_post_request_t *_get_updates_post_request_parseFromJSON(cJSON *_get_updates_post_requestJSON);

cJSON *_get_updates_post_request_convertToJSON(_get_updates_post_request_t *_get_updates_post_request);

#endif /* __get_updates_post_request_H_ */

