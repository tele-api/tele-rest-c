/*
 * unpin_all_general_forum_topic_messages_response.h
 *
 * 
 */

#ifndef _unpin_all_general_forum_topic_messages_response_H_
#define _unpin_all_general_forum_topic_messages_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct unpin_all_general_forum_topic_messages_response_t unpin_all_general_forum_topic_messages_response_t;




typedef struct unpin_all_general_forum_topic_messages_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} unpin_all_general_forum_topic_messages_response_t;

__attribute__((deprecated)) unpin_all_general_forum_topic_messages_response_t *unpin_all_general_forum_topic_messages_response_create(
    int ok,
    int result
);

void unpin_all_general_forum_topic_messages_response_free(unpin_all_general_forum_topic_messages_response_t *unpin_all_general_forum_topic_messages_response);

unpin_all_general_forum_topic_messages_response_t *unpin_all_general_forum_topic_messages_response_parseFromJSON(cJSON *unpin_all_general_forum_topic_messages_responseJSON);

cJSON *unpin_all_general_forum_topic_messages_response_convertToJSON(unpin_all_general_forum_topic_messages_response_t *unpin_all_general_forum_topic_messages_response);

#endif /* _unpin_all_general_forum_topic_messages_response_H_ */

