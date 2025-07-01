/*
 * _set_my_commands_post_request.h
 *
 * 
 */

#ifndef __set_my_commands_post_request_H_
#define __set_my_commands_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _set_my_commands_post_request_t _set_my_commands_post_request_t;

#include "bot_command.h"
#include "bot_command_scope.h"



typedef struct _set_my_commands_post_request_t {
    list_t *commands; //nonprimitive container
    struct bot_command_scope_t *scope; //model
    char *language_code; // string

    int _library_owned; // Is the library responsible for freeing this object?
} _set_my_commands_post_request_t;

__attribute__((deprecated)) _set_my_commands_post_request_t *_set_my_commands_post_request_create(
    list_t *commands,
    bot_command_scope_t *scope,
    char *language_code
);

void _set_my_commands_post_request_free(_set_my_commands_post_request_t *_set_my_commands_post_request);

_set_my_commands_post_request_t *_set_my_commands_post_request_parseFromJSON(cJSON *_set_my_commands_post_requestJSON);

cJSON *_set_my_commands_post_request_convertToJSON(_set_my_commands_post_request_t *_set_my_commands_post_request);

#endif /* __set_my_commands_post_request_H_ */

