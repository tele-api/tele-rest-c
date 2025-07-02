/*
 * post_story_response.h
 *
 * 
 */

#ifndef _post_story_response_H_
#define _post_story_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_story_response_t post_story_response_t;

#include "story.h"



typedef struct post_story_response_t {
    int ok; //boolean
    struct story_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_story_response_t;

__attribute__((deprecated)) post_story_response_t *post_story_response_create(
    int ok,
    story_t *result
);

void post_story_response_free(post_story_response_t *post_story_response);

post_story_response_t *post_story_response_parseFromJSON(cJSON *post_story_responseJSON);

cJSON *post_story_response_convertToJSON(post_story_response_t *post_story_response);

#endif /* _post_story_response_H_ */

