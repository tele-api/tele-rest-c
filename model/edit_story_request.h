/*
 * edit_story_request.h
 *
 * Request parameters for editStory
 */

#ifndef _edit_story_request_H_
#define _edit_story_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct edit_story_request_t edit_story_request_t;

#include "input_story_content.h"
#include "message_entity.h"
#include "story_area.h"



typedef struct edit_story_request_t {
    char *business_connection_id; // string
    int story_id; //numeric
    struct input_story_content_t *content; //model
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    list_t *areas; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} edit_story_request_t;

__attribute__((deprecated)) edit_story_request_t *edit_story_request_create(
    char *business_connection_id,
    int story_id,
    input_story_content_t *content,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    list_t *areas
);

void edit_story_request_free(edit_story_request_t *edit_story_request);

edit_story_request_t *edit_story_request_parseFromJSON(cJSON *edit_story_requestJSON);

cJSON *edit_story_request_convertToJSON(edit_story_request_t *edit_story_request);

#endif /* _edit_story_request_H_ */

