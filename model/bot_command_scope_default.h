/*
 * bot_command_scope_default.h
 *
 * Represents the default [scope](https://core.telegram.org/bots/api/#botcommandscope) of bot commands. Default commands are used if no commands with a [narrower scope](https://core.telegram.org/bots/api/#determining-list-of-commands) are specified for the user.
 */

#ifndef _bot_command_scope_default_H_
#define _bot_command_scope_default_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bot_command_scope_default_t bot_command_scope_default_t;




typedef struct bot_command_scope_default_t {
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} bot_command_scope_default_t;

__attribute__((deprecated)) bot_command_scope_default_t *bot_command_scope_default_create(
    char *type
);

void bot_command_scope_default_free(bot_command_scope_default_t *bot_command_scope_default);

bot_command_scope_default_t *bot_command_scope_default_parseFromJSON(cJSON *bot_command_scope_defaultJSON);

cJSON *bot_command_scope_default_convertToJSON(bot_command_scope_default_t *bot_command_scope_default);

#endif /* _bot_command_scope_default_H_ */

