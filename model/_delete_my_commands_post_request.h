/*
 * _delete_my_commands_post_request.h
 *
 * 
 */

#ifndef __delete_my_commands_post_request_H_
#define __delete_my_commands_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _delete_my_commands_post_request_t _delete_my_commands_post_request_t;

#include "bot_command_scope.h"



typedef struct _delete_my_commands_post_request_t {
    struct bot_command_scope_t *scope; //model
    char *language_code; // string

    int _library_owned; // Is the library responsible for freeing this object?
} _delete_my_commands_post_request_t;

__attribute__((deprecated)) _delete_my_commands_post_request_t *_delete_my_commands_post_request_create(
    bot_command_scope_t *scope,
    char *language_code
);

void _delete_my_commands_post_request_free(_delete_my_commands_post_request_t *_delete_my_commands_post_request);

_delete_my_commands_post_request_t *_delete_my_commands_post_request_parseFromJSON(cJSON *_delete_my_commands_post_requestJSON);

cJSON *_delete_my_commands_post_request_convertToJSON(_delete_my_commands_post_request_t *_delete_my_commands_post_request);

#endif /* __delete_my_commands_post_request_H_ */

