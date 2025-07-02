/*
 * close_forum_topic_request.h
 *
 * Request parameters for closeForumTopic
 */

#ifndef _close_forum_topic_request_H_
#define _close_forum_topic_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct close_forum_topic_request_t close_forum_topic_request_t;

#include "bot_command_scope_chat_chat_id.h"



typedef struct close_forum_topic_request_t {
    struct bot_command_scope_chat_chat_id_t *chat_id; //model
    int message_thread_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} close_forum_topic_request_t;

__attribute__((deprecated)) close_forum_topic_request_t *close_forum_topic_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    int message_thread_id
);

void close_forum_topic_request_free(close_forum_topic_request_t *close_forum_topic_request);

close_forum_topic_request_t *close_forum_topic_request_parseFromJSON(cJSON *close_forum_topic_requestJSON);

cJSON *close_forum_topic_request_convertToJSON(close_forum_topic_request_t *close_forum_topic_request);

#endif /* _close_forum_topic_request_H_ */

