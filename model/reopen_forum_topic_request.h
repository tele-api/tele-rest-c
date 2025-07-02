/*
 * reopen_forum_topic_request.h
 *
 * Request parameters for reopenForumTopic
 */

#ifndef _reopen_forum_topic_request_H_
#define _reopen_forum_topic_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reopen_forum_topic_request_t reopen_forum_topic_request_t;

#include "bot_command_scope_chat_chat_id.h"



typedef struct reopen_forum_topic_request_t {
    struct bot_command_scope_chat_chat_id_t *chat_id; //model
    int message_thread_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} reopen_forum_topic_request_t;

__attribute__((deprecated)) reopen_forum_topic_request_t *reopen_forum_topic_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    int message_thread_id
);

void reopen_forum_topic_request_free(reopen_forum_topic_request_t *reopen_forum_topic_request);

reopen_forum_topic_request_t *reopen_forum_topic_request_parseFromJSON(cJSON *reopen_forum_topic_requestJSON);

cJSON *reopen_forum_topic_request_convertToJSON(reopen_forum_topic_request_t *reopen_forum_topic_request);

#endif /* _reopen_forum_topic_request_H_ */

