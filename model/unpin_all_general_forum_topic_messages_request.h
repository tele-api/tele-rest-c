/*
 * unpin_all_general_forum_topic_messages_request.h
 *
 * Request parameters for unpinAllGeneralForumTopicMessages
 */

#ifndef _unpin_all_general_forum_topic_messages_request_H_
#define _unpin_all_general_forum_topic_messages_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct unpin_all_general_forum_topic_messages_request_t unpin_all_general_forum_topic_messages_request_t;

#include "bot_command_scope_chat_chat_id.h"



typedef struct unpin_all_general_forum_topic_messages_request_t {
    struct bot_command_scope_chat_chat_id_t *chat_id; //model

    int _library_owned; // Is the library responsible for freeing this object?
} unpin_all_general_forum_topic_messages_request_t;

__attribute__((deprecated)) unpin_all_general_forum_topic_messages_request_t *unpin_all_general_forum_topic_messages_request_create(
    bot_command_scope_chat_chat_id_t *chat_id
);

void unpin_all_general_forum_topic_messages_request_free(unpin_all_general_forum_topic_messages_request_t *unpin_all_general_forum_topic_messages_request);

unpin_all_general_forum_topic_messages_request_t *unpin_all_general_forum_topic_messages_request_parseFromJSON(cJSON *unpin_all_general_forum_topic_messages_requestJSON);

cJSON *unpin_all_general_forum_topic_messages_request_convertToJSON(unpin_all_general_forum_topic_messages_request_t *unpin_all_general_forum_topic_messages_request);

#endif /* _unpin_all_general_forum_topic_messages_request_H_ */

