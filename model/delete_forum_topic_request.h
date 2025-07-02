/*
 * delete_forum_topic_request.h
 *
 * Request parameters for deleteForumTopic
 */

#ifndef _delete_forum_topic_request_H_
#define _delete_forum_topic_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_forum_topic_request_t delete_forum_topic_request_t;

#include "bot_command_scope_chat_chat_id.h"



typedef struct delete_forum_topic_request_t {
    struct bot_command_scope_chat_chat_id_t *chat_id; //model
    int message_thread_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} delete_forum_topic_request_t;

__attribute__((deprecated)) delete_forum_topic_request_t *delete_forum_topic_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    int message_thread_id
);

void delete_forum_topic_request_free(delete_forum_topic_request_t *delete_forum_topic_request);

delete_forum_topic_request_t *delete_forum_topic_request_parseFromJSON(cJSON *delete_forum_topic_requestJSON);

cJSON *delete_forum_topic_request_convertToJSON(delete_forum_topic_request_t *delete_forum_topic_request);

#endif /* _delete_forum_topic_request_H_ */

