/*
 * delete_my_commands_request.h
 *
 * Request parameters for deleteMyCommands
 */

#ifndef _delete_my_commands_request_H_
#define _delete_my_commands_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_my_commands_request_t delete_my_commands_request_t;

#include "bot_command_scope.h"



typedef struct delete_my_commands_request_t {
    struct bot_command_scope_t *scope; //model
    char *language_code; // string

    int _library_owned; // Is the library responsible for freeing this object?
} delete_my_commands_request_t;

__attribute__((deprecated)) delete_my_commands_request_t *delete_my_commands_request_create(
    bot_command_scope_t *scope,
    char *language_code
);

void delete_my_commands_request_free(delete_my_commands_request_t *delete_my_commands_request);

delete_my_commands_request_t *delete_my_commands_request_parseFromJSON(cJSON *delete_my_commands_requestJSON);

cJSON *delete_my_commands_request_convertToJSON(delete_my_commands_request_t *delete_my_commands_request);

#endif /* _delete_my_commands_request_H_ */

