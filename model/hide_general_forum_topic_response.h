/*
 * hide_general_forum_topic_response.h
 *
 * 
 */

#ifndef _hide_general_forum_topic_response_H_
#define _hide_general_forum_topic_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct hide_general_forum_topic_response_t hide_general_forum_topic_response_t;




typedef struct hide_general_forum_topic_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} hide_general_forum_topic_response_t;

__attribute__((deprecated)) hide_general_forum_topic_response_t *hide_general_forum_topic_response_create(
    int ok,
    int result
);

void hide_general_forum_topic_response_free(hide_general_forum_topic_response_t *hide_general_forum_topic_response);

hide_general_forum_topic_response_t *hide_general_forum_topic_response_parseFromJSON(cJSON *hide_general_forum_topic_responseJSON);

cJSON *hide_general_forum_topic_response_convertToJSON(hide_general_forum_topic_response_t *hide_general_forum_topic_response);

#endif /* _hide_general_forum_topic_response_H_ */

