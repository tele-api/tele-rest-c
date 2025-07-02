/*
 * bot_command_scope_chat_chat_id.h
 *
 * Unique identifier for the target chat or username of the target supergroup (in the format &#x60;@supergroupusername&#x60;)
 */

#ifndef _bot_command_scope_chat_chat_id_H_
#define _bot_command_scope_chat_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bot_command_scope_chat_chat_id_t bot_command_scope_chat_chat_id_t;




typedef struct bot_command_scope_chat_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} bot_command_scope_chat_chat_id_t;

__attribute__((deprecated)) bot_command_scope_chat_chat_id_t *bot_command_scope_chat_chat_id_create(
);

void bot_command_scope_chat_chat_id_free(bot_command_scope_chat_chat_id_t *bot_command_scope_chat_chat_id);

bot_command_scope_chat_chat_id_t *bot_command_scope_chat_chat_id_parseFromJSON(cJSON *bot_command_scope_chat_chat_idJSON);

cJSON *bot_command_scope_chat_chat_id_convertToJSON(bot_command_scope_chat_chat_id_t *bot_command_scope_chat_chat_id);

#endif /* _bot_command_scope_chat_chat_id_H_ */

