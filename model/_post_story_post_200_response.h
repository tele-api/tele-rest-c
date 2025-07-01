/*
 * _post_story_post_200_response.h
 *
 * 
 */

#ifndef __post_story_post_200_response_H_
#define __post_story_post_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _post_story_post_200_response_t _post_story_post_200_response_t;

#include "story.h"



typedef struct _post_story_post_200_response_t {
    int ok; //boolean
    struct story_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _post_story_post_200_response_t;

__attribute__((deprecated)) _post_story_post_200_response_t *_post_story_post_200_response_create(
    int ok,
    story_t *result
);

void _post_story_post_200_response_free(_post_story_post_200_response_t *_post_story_post_200_response);

_post_story_post_200_response_t *_post_story_post_200_response_parseFromJSON(cJSON *_post_story_post_200_responseJSON);

cJSON *_post_story_post_200_response_convertToJSON(_post_story_post_200_response_t *_post_story_post_200_response);

#endif /* __post_story_post_200_response_H_ */

