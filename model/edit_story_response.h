/*
 * edit_story_response.h
 *
 * 
 */

#ifndef _edit_story_response_H_
#define _edit_story_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct edit_story_response_t edit_story_response_t;

#include "story.h"



typedef struct edit_story_response_t {
    int ok; //boolean
    struct story_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} edit_story_response_t;

__attribute__((deprecated)) edit_story_response_t *edit_story_response_create(
    int ok,
    story_t *result
);

void edit_story_response_free(edit_story_response_t *edit_story_response);

edit_story_response_t *edit_story_response_parseFromJSON(cJSON *edit_story_responseJSON);

cJSON *edit_story_response_convertToJSON(edit_story_response_t *edit_story_response);

#endif /* _edit_story_response_H_ */

