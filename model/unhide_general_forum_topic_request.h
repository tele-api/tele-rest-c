/*
 * unhide_general_forum_topic_request.h
 *
 * Request parameters for unhideGeneralForumTopic
 */

#ifndef _unhide_general_forum_topic_request_H_
#define _unhide_general_forum_topic_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct unhide_general_forum_topic_request_t unhide_general_forum_topic_request_t;

#include "bot_command_scope_chat_chat_id.h"



typedef struct unhide_general_forum_topic_request_t {
    struct bot_command_scope_chat_chat_id_t *chat_id; //model

    int _library_owned; // Is the library responsible for freeing this object?
} unhide_general_forum_topic_request_t;

__attribute__((deprecated)) unhide_general_forum_topic_request_t *unhide_general_forum_topic_request_create(
    bot_command_scope_chat_chat_id_t *chat_id
);

void unhide_general_forum_topic_request_free(unhide_general_forum_topic_request_t *unhide_general_forum_topic_request);

unhide_general_forum_topic_request_t *unhide_general_forum_topic_request_parseFromJSON(cJSON *unhide_general_forum_topic_requestJSON);

cJSON *unhide_general_forum_topic_request_convertToJSON(unhide_general_forum_topic_request_t *unhide_general_forum_topic_request);

#endif /* _unhide_general_forum_topic_request_H_ */

