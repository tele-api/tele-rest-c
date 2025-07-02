/*
 * close_general_forum_topic_request.h
 *
 * Request parameters for closeGeneralForumTopic
 */

#ifndef _close_general_forum_topic_request_H_
#define _close_general_forum_topic_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct close_general_forum_topic_request_t close_general_forum_topic_request_t;

#include "bot_command_scope_chat_chat_id.h"



typedef struct close_general_forum_topic_request_t {
    struct bot_command_scope_chat_chat_id_t *chat_id; //model

    int _library_owned; // Is the library responsible for freeing this object?
} close_general_forum_topic_request_t;

__attribute__((deprecated)) close_general_forum_topic_request_t *close_general_forum_topic_request_create(
    bot_command_scope_chat_chat_id_t *chat_id
);

void close_general_forum_topic_request_free(close_general_forum_topic_request_t *close_general_forum_topic_request);

close_general_forum_topic_request_t *close_general_forum_topic_request_parseFromJSON(cJSON *close_general_forum_topic_requestJSON);

cJSON *close_general_forum_topic_request_convertToJSON(close_general_forum_topic_request_t *close_general_forum_topic_request);

#endif /* _close_general_forum_topic_request_H_ */

