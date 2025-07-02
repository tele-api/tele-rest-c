/*
 * delete_story_request.h
 *
 * Request parameters for deleteStory
 */

#ifndef _delete_story_request_H_
#define _delete_story_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_story_request_t delete_story_request_t;




typedef struct delete_story_request_t {
    char *business_connection_id; // string
    int story_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} delete_story_request_t;

__attribute__((deprecated)) delete_story_request_t *delete_story_request_create(
    char *business_connection_id,
    int story_id
);

void delete_story_request_free(delete_story_request_t *delete_story_request);

delete_story_request_t *delete_story_request_parseFromJSON(cJSON *delete_story_requestJSON);

cJSON *delete_story_request_convertToJSON(delete_story_request_t *delete_story_request);

#endif /* _delete_story_request_H_ */

