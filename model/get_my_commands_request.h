/*
 * get_my_commands_request.h
 *
 * Request parameters for getMyCommands
 */

#ifndef _get_my_commands_request_H_
#define _get_my_commands_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_my_commands_request_t get_my_commands_request_t;

#include "bot_command_scope.h"



typedef struct get_my_commands_request_t {
    struct bot_command_scope_t *scope; //model
    char *language_code; // string

    int _library_owned; // Is the library responsible for freeing this object?
} get_my_commands_request_t;

__attribute__((deprecated)) get_my_commands_request_t *get_my_commands_request_create(
    bot_command_scope_t *scope,
    char *language_code
);

void get_my_commands_request_free(get_my_commands_request_t *get_my_commands_request);

get_my_commands_request_t *get_my_commands_request_parseFromJSON(cJSON *get_my_commands_requestJSON);

cJSON *get_my_commands_request_convertToJSON(get_my_commands_request_t *get_my_commands_request);

#endif /* _get_my_commands_request_H_ */

