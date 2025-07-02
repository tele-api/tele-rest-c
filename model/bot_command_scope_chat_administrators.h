/*
 * bot_command_scope_chat_administrators.h
 *
 * Represents the [scope](https://core.telegram.org/bots/api/#botcommandscope) of bot commands, covering all administrators of a specific group or supergroup chat.
 */

#ifndef _bot_command_scope_chat_administrators_H_
#define _bot_command_scope_chat_administrators_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bot_command_scope_chat_administrators_t bot_command_scope_chat_administrators_t;

#include "bot_command_scope_chat_chat_id.h"



typedef struct bot_command_scope_chat_administrators_t {
    char *type; // string
    struct bot_command_scope_chat_chat_id_t *chat_id; //model

    int _library_owned; // Is the library responsible for freeing this object?
} bot_command_scope_chat_administrators_t;

__attribute__((deprecated)) bot_command_scope_chat_administrators_t *bot_command_scope_chat_administrators_create(
    char *type,
    bot_command_scope_chat_chat_id_t *chat_id
);

void bot_command_scope_chat_administrators_free(bot_command_scope_chat_administrators_t *bot_command_scope_chat_administrators);

bot_command_scope_chat_administrators_t *bot_command_scope_chat_administrators_parseFromJSON(cJSON *bot_command_scope_chat_administratorsJSON);

cJSON *bot_command_scope_chat_administrators_convertToJSON(bot_command_scope_chat_administrators_t *bot_command_scope_chat_administrators);

#endif /* _bot_command_scope_chat_administrators_H_ */

