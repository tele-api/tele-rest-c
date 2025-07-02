/*
 * edit_general_forum_topic_response.h
 *
 * 
 */

#ifndef _edit_general_forum_topic_response_H_
#define _edit_general_forum_topic_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct edit_general_forum_topic_response_t edit_general_forum_topic_response_t;




typedef struct edit_general_forum_topic_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} edit_general_forum_topic_response_t;

__attribute__((deprecated)) edit_general_forum_topic_response_t *edit_general_forum_topic_response_create(
    int ok,
    int result
);

void edit_general_forum_topic_response_free(edit_general_forum_topic_response_t *edit_general_forum_topic_response);

edit_general_forum_topic_response_t *edit_general_forum_topic_response_parseFromJSON(cJSON *edit_general_forum_topic_responseJSON);

cJSON *edit_general_forum_topic_response_convertToJSON(edit_general_forum_topic_response_t *edit_general_forum_topic_response);

#endif /* _edit_general_forum_topic_response_H_ */

