/*
 * bot_command_scope_chat_member.h
 *
 * Represents the [scope](https://core.telegram.org/bots/api/#botcommandscope) of bot commands, covering a specific member of a group or supergroup chat.
 */

#ifndef _bot_command_scope_chat_member_H_
#define _bot_command_scope_chat_member_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bot_command_scope_chat_member_t bot_command_scope_chat_member_t;

#include "bot_command_scope_chat_chat_id.h"



typedef struct bot_command_scope_chat_member_t {
    char *type; // string
    struct bot_command_scope_chat_chat_id_t *chat_id; //model
    int user_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} bot_command_scope_chat_member_t;

__attribute__((deprecated)) bot_command_scope_chat_member_t *bot_command_scope_chat_member_create(
    char *type,
    bot_command_scope_chat_chat_id_t *chat_id,
    int user_id
);

void bot_command_scope_chat_member_free(bot_command_scope_chat_member_t *bot_command_scope_chat_member);

bot_command_scope_chat_member_t *bot_command_scope_chat_member_parseFromJSON(cJSON *bot_command_scope_chat_memberJSON);

cJSON *bot_command_scope_chat_member_convertToJSON(bot_command_scope_chat_member_t *bot_command_scope_chat_member);

#endif /* _bot_command_scope_chat_member_H_ */

