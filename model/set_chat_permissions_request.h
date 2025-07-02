/*
 * set_chat_permissions_request.h
 *
 * Request parameters for setChatPermissions
 */

#ifndef _set_chat_permissions_request_H_
#define _set_chat_permissions_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_chat_permissions_request_t set_chat_permissions_request_t;

#include "bot_command_scope_chat_chat_id.h"
#include "chat_permissions.h"



typedef struct set_chat_permissions_request_t {
    struct bot_command_scope_chat_chat_id_t *chat_id; //model
    struct chat_permissions_t *permissions; //model
    int use_independent_chat_permissions; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} set_chat_permissions_request_t;

__attribute__((deprecated)) set_chat_permissions_request_t *set_chat_permissions_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    chat_permissions_t *permissions,
    int use_independent_chat_permissions
);

void set_chat_permissions_request_free(set_chat_permissions_request_t *set_chat_permissions_request);

set_chat_permissions_request_t *set_chat_permissions_request_parseFromJSON(cJSON *set_chat_permissions_requestJSON);

cJSON *set_chat_permissions_request_convertToJSON(set_chat_permissions_request_t *set_chat_permissions_request);

#endif /* _set_chat_permissions_request_H_ */

