/*
 * post_post_story_200_response.h
 *
 * 
 */

#ifndef _post_post_story_200_response_H_
#define _post_post_story_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_post_story_200_response_t post_post_story_200_response_t;

#include "story.h"



typedef struct post_post_story_200_response_t {
    int ok; //boolean
    struct story_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_post_story_200_response_t;

__attribute__((deprecated)) post_post_story_200_response_t *post_post_story_200_response_create(
    int ok,
    story_t *result
);

void post_post_story_200_response_free(post_post_story_200_response_t *post_post_story_200_response);

post_post_story_200_response_t *post_post_story_200_response_parseFromJSON(cJSON *post_post_story_200_responseJSON);

cJSON *post_post_story_200_response_convertToJSON(post_post_story_200_response_t *post_post_story_200_response);

#endif /* _post_post_story_200_response_H_ */

