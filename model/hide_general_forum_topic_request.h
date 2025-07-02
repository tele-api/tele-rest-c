/*
 * hide_general_forum_topic_request.h
 *
 * Request parameters for hideGeneralForumTopic
 */

#ifndef _hide_general_forum_topic_request_H_
#define _hide_general_forum_topic_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct hide_general_forum_topic_request_t hide_general_forum_topic_request_t;

#include "bot_command_scope_chat_chat_id.h"



typedef struct hide_general_forum_topic_request_t {
    struct bot_command_scope_chat_chat_id_t *chat_id; //model

    int _library_owned; // Is the library responsible for freeing this object?
} hide_general_forum_topic_request_t;

__attribute__((deprecated)) hide_general_forum_topic_request_t *hide_general_forum_topic_request_create(
    bot_command_scope_chat_chat_id_t *chat_id
);

void hide_general_forum_topic_request_free(hide_general_forum_topic_request_t *hide_general_forum_topic_request);

hide_general_forum_topic_request_t *hide_general_forum_topic_request_parseFromJSON(cJSON *hide_general_forum_topic_requestJSON);

cJSON *hide_general_forum_topic_request_convertToJSON(hide_general_forum_topic_request_t *hide_general_forum_topic_request);

#endif /* _hide_general_forum_topic_request_H_ */

