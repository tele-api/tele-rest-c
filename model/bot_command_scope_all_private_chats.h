/*
 * bot_command_scope_all_private_chats.h
 *
 * Represents the [scope](https://core.telegram.org/bots/api/#botcommandscope) of bot commands, covering all private chats.
 */

#ifndef _bot_command_scope_all_private_chats_H_
#define _bot_command_scope_all_private_chats_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bot_command_scope_all_private_chats_t bot_command_scope_all_private_chats_t;




typedef struct bot_command_scope_all_private_chats_t {
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} bot_command_scope_all_private_chats_t;

__attribute__((deprecated)) bot_command_scope_all_private_chats_t *bot_command_scope_all_private_chats_create(
    char *type
);

void bot_command_scope_all_private_chats_free(bot_command_scope_all_private_chats_t *bot_command_scope_all_private_chats);

bot_command_scope_all_private_chats_t *bot_command_scope_all_private_chats_parseFromJSON(cJSON *bot_command_scope_all_private_chatsJSON);

cJSON *bot_command_scope_all_private_chats_convertToJSON(bot_command_scope_all_private_chats_t *bot_command_scope_all_private_chats);

#endif /* _bot_command_scope_all_private_chats_H_ */

