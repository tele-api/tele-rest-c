/*
 * switch_inline_query_chosen_chat.h
 *
 * This object represents an inline button that switches the current user to inline mode in a chosen chat, with an optional default inline query.
 */

#ifndef _switch_inline_query_chosen_chat_H_
#define _switch_inline_query_chosen_chat_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct switch_inline_query_chosen_chat_t switch_inline_query_chosen_chat_t;




typedef struct switch_inline_query_chosen_chat_t {
    char *query; // string
    int allow_user_chats; //boolean
    int allow_bot_chats; //boolean
    int allow_group_chats; //boolean
    int allow_channel_chats; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} switch_inline_query_chosen_chat_t;

__attribute__((deprecated)) switch_inline_query_chosen_chat_t *switch_inline_query_chosen_chat_create(
    char *query,
    int allow_user_chats,
    int allow_bot_chats,
    int allow_group_chats,
    int allow_channel_chats
);

void switch_inline_query_chosen_chat_free(switch_inline_query_chosen_chat_t *switch_inline_query_chosen_chat);

switch_inline_query_chosen_chat_t *switch_inline_query_chosen_chat_parseFromJSON(cJSON *switch_inline_query_chosen_chatJSON);

cJSON *switch_inline_query_chosen_chat_convertToJSON(switch_inline_query_chosen_chat_t *switch_inline_query_chosen_chat);

#endif /* _switch_inline_query_chosen_chat_H_ */

