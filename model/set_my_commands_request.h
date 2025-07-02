/*
 * set_my_commands_request.h
 *
 * Request parameters for setMyCommands
 */

#ifndef _set_my_commands_request_H_
#define _set_my_commands_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_my_commands_request_t set_my_commands_request_t;

#include "bot_command.h"
#include "bot_command_scope.h"



typedef struct set_my_commands_request_t {
    list_t *commands; //nonprimitive container
    struct bot_command_scope_t *scope; //model
    char *language_code; // string

    int _library_owned; // Is the library responsible for freeing this object?
} set_my_commands_request_t;

__attribute__((deprecated)) set_my_commands_request_t *set_my_commands_request_create(
    list_t *commands,
    bot_command_scope_t *scope,
    char *language_code
);

void set_my_commands_request_free(set_my_commands_request_t *set_my_commands_request);

set_my_commands_request_t *set_my_commands_request_parseFromJSON(cJSON *set_my_commands_requestJSON);

cJSON *set_my_commands_request_convertToJSON(set_my_commands_request_t *set_my_commands_request);

#endif /* _set_my_commands_request_H_ */

