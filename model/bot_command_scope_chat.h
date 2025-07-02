/*
 * bot_command_scope_chat.h
 *
 * Represents the [scope](https://core.telegram.org/bots/api/#botcommandscope) of bot commands, covering a specific chat.
 */

#ifndef _bot_command_scope_chat_H_
#define _bot_command_scope_chat_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bot_command_scope_chat_t bot_command_scope_chat_t;

#include "post_restrict_chat_member_request_chat_id.h"



typedef struct bot_command_scope_chat_t {
    char *type; // string
    struct post_restrict_chat_member_request_chat_id_t *chat_id; //model

    int _library_owned; // Is the library responsible for freeing this object?
} bot_command_scope_chat_t;

__attribute__((deprecated)) bot_command_scope_chat_t *bot_command_scope_chat_create(
    char *type,
    post_restrict_chat_member_request_chat_id_t *chat_id
);

void bot_command_scope_chat_free(bot_command_scope_chat_t *bot_command_scope_chat);

bot_command_scope_chat_t *bot_command_scope_chat_parseFromJSON(cJSON *bot_command_scope_chatJSON);

cJSON *bot_command_scope_chat_convertToJSON(bot_command_scope_chat_t *bot_command_scope_chat);

#endif /* _bot_command_scope_chat_H_ */

