/*
 * set_chat_administrator_custom_title_request.h
 *
 * Request parameters for setChatAdministratorCustomTitle
 */

#ifndef _set_chat_administrator_custom_title_request_H_
#define _set_chat_administrator_custom_title_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_chat_administrator_custom_title_request_t set_chat_administrator_custom_title_request_t;

#include "bot_command_scope_chat_chat_id.h"



typedef struct set_chat_administrator_custom_title_request_t {
    struct bot_command_scope_chat_chat_id_t *chat_id; //model
    int user_id; //numeric
    char *custom_title; // string

    int _library_owned; // Is the library responsible for freeing this object?
} set_chat_administrator_custom_title_request_t;

__attribute__((deprecated)) set_chat_administrator_custom_title_request_t *set_chat_administrator_custom_title_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    int user_id,
    char *custom_title
);

void set_chat_administrator_custom_title_request_free(set_chat_administrator_custom_title_request_t *set_chat_administrator_custom_title_request);

set_chat_administrator_custom_title_request_t *set_chat_administrator_custom_title_request_parseFromJSON(cJSON *set_chat_administrator_custom_title_requestJSON);

cJSON *set_chat_administrator_custom_title_request_convertToJSON(set_chat_administrator_custom_title_request_t *set_chat_administrator_custom_title_request);

#endif /* _set_chat_administrator_custom_title_request_H_ */

