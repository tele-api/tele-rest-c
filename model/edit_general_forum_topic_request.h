/*
 * edit_general_forum_topic_request.h
 *
 * Request parameters for editGeneralForumTopic
 */

#ifndef _edit_general_forum_topic_request_H_
#define _edit_general_forum_topic_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct edit_general_forum_topic_request_t edit_general_forum_topic_request_t;

#include "bot_command_scope_chat_chat_id.h"



typedef struct edit_general_forum_topic_request_t {
    struct bot_command_scope_chat_chat_id_t *chat_id; //model
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} edit_general_forum_topic_request_t;

__attribute__((deprecated)) edit_general_forum_topic_request_t *edit_general_forum_topic_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    char *name
);

void edit_general_forum_topic_request_free(edit_general_forum_topic_request_t *edit_general_forum_topic_request);

edit_general_forum_topic_request_t *edit_general_forum_topic_request_parseFromJSON(cJSON *edit_general_forum_topic_requestJSON);

cJSON *edit_general_forum_topic_request_convertToJSON(edit_general_forum_topic_request_t *edit_general_forum_topic_request);

#endif /* _edit_general_forum_topic_request_H_ */

