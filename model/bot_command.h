/*
 * bot_command.h
 *
 * This object represents a bot command.
 */

#ifndef _bot_command_H_
#define _bot_command_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bot_command_t bot_command_t;




typedef struct bot_command_t {
    char *command; // string
    char *description; // string

    int _library_owned; // Is the library responsible for freeing this object?
} bot_command_t;

__attribute__((deprecated)) bot_command_t *bot_command_create(
    char *command,
    char *description
);

void bot_command_free(bot_command_t *bot_command);

bot_command_t *bot_command_parseFromJSON(cJSON *bot_commandJSON);

cJSON *bot_command_convertToJSON(bot_command_t *bot_command);

#endif /* _bot_command_H_ */

