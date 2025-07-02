/*
 * post_delete_my_commands_request.h
 *
 * 
 */

#ifndef _post_delete_my_commands_request_H_
#define _post_delete_my_commands_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_delete_my_commands_request_t post_delete_my_commands_request_t;

#include "bot_command_scope.h"



typedef struct post_delete_my_commands_request_t {
    struct bot_command_scope_t *scope; //model
    char *language_code; // string

    int _library_owned; // Is the library responsible for freeing this object?
} post_delete_my_commands_request_t;

__attribute__((deprecated)) post_delete_my_commands_request_t *post_delete_my_commands_request_create(
    bot_command_scope_t *scope,
    char *language_code
);

void post_delete_my_commands_request_free(post_delete_my_commands_request_t *post_delete_my_commands_request);

post_delete_my_commands_request_t *post_delete_my_commands_request_parseFromJSON(cJSON *post_delete_my_commands_requestJSON);

cJSON *post_delete_my_commands_request_convertToJSON(post_delete_my_commands_request_t *post_delete_my_commands_request);

#endif /* _post_delete_my_commands_request_H_ */

