/*
 * create_forum_topic_response.h
 *
 * 
 */

#ifndef _create_forum_topic_response_H_
#define _create_forum_topic_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_forum_topic_response_t create_forum_topic_response_t;

#include "forum_topic.h"



typedef struct create_forum_topic_response_t {
    int ok; //boolean
    struct forum_topic_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} create_forum_topic_response_t;

__attribute__((deprecated)) create_forum_topic_response_t *create_forum_topic_response_create(
    int ok,
    forum_topic_t *result
);

void create_forum_topic_response_free(create_forum_topic_response_t *create_forum_topic_response);

create_forum_topic_response_t *create_forum_topic_response_parseFromJSON(cJSON *create_forum_topic_responseJSON);

cJSON *create_forum_topic_response_convertToJSON(create_forum_topic_response_t *create_forum_topic_response);

#endif /* _create_forum_topic_response_H_ */

