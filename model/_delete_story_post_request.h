/*
 * _delete_story_post_request.h
 *
 * 
 */

#ifndef __delete_story_post_request_H_
#define __delete_story_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _delete_story_post_request_t _delete_story_post_request_t;




typedef struct _delete_story_post_request_t {
    char *business_connection_id; // string
    int story_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} _delete_story_post_request_t;

__attribute__((deprecated)) _delete_story_post_request_t *_delete_story_post_request_create(
    char *business_connection_id,
    int story_id
);

void _delete_story_post_request_free(_delete_story_post_request_t *_delete_story_post_request);

_delete_story_post_request_t *_delete_story_post_request_parseFromJSON(cJSON *_delete_story_post_requestJSON);

cJSON *_delete_story_post_request_convertToJSON(_delete_story_post_request_t *_delete_story_post_request);

#endif /* __delete_story_post_request_H_ */

