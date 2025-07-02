/*
 * edit_forum_topic_request.h
 *
 * Request parameters for editForumTopic
 */

#ifndef _edit_forum_topic_request_H_
#define _edit_forum_topic_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct edit_forum_topic_request_t edit_forum_topic_request_t;

#include "bot_command_scope_chat_chat_id.h"



typedef struct edit_forum_topic_request_t {
    struct bot_command_scope_chat_chat_id_t *chat_id; //model
    int message_thread_id; //numeric
    char *name; // string
    char *icon_custom_emoji_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} edit_forum_topic_request_t;

__attribute__((deprecated)) edit_forum_topic_request_t *edit_forum_topic_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    int message_thread_id,
    char *name,
    char *icon_custom_emoji_id
);

void edit_forum_topic_request_free(edit_forum_topic_request_t *edit_forum_topic_request);

edit_forum_topic_request_t *edit_forum_topic_request_parseFromJSON(cJSON *edit_forum_topic_requestJSON);

cJSON *edit_forum_topic_request_convertToJSON(edit_forum_topic_request_t *edit_forum_topic_request);

#endif /* _edit_forum_topic_request_H_ */

