/*
 * unhide_general_forum_topic_response.h
 *
 * 
 */

#ifndef _unhide_general_forum_topic_response_H_
#define _unhide_general_forum_topic_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct unhide_general_forum_topic_response_t unhide_general_forum_topic_response_t;




typedef struct unhide_general_forum_topic_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} unhide_general_forum_topic_response_t;

__attribute__((deprecated)) unhide_general_forum_topic_response_t *unhide_general_forum_topic_response_create(
    int ok,
    int result
);

void unhide_general_forum_topic_response_free(unhide_general_forum_topic_response_t *unhide_general_forum_topic_response);

unhide_general_forum_topic_response_t *unhide_general_forum_topic_response_parseFromJSON(cJSON *unhide_general_forum_topic_responseJSON);

cJSON *unhide_general_forum_topic_response_convertToJSON(unhide_general_forum_topic_response_t *unhide_general_forum_topic_response);

#endif /* _unhide_general_forum_topic_response_H_ */

