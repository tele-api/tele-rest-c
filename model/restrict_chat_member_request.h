/*
 * restrict_chat_member_request.h
 *
 * Request parameters for restrictChatMember
 */

#ifndef _restrict_chat_member_request_H_
#define _restrict_chat_member_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct restrict_chat_member_request_t restrict_chat_member_request_t;

#include "bot_command_scope_chat_chat_id.h"
#include "chat_permissions.h"



typedef struct restrict_chat_member_request_t {
    struct bot_command_scope_chat_chat_id_t *chat_id; //model
    int user_id; //numeric
    struct chat_permissions_t *permissions; //model
    int use_independent_chat_permissions; //boolean
    int until_date; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} restrict_chat_member_request_t;

__attribute__((deprecated)) restrict_chat_member_request_t *restrict_chat_member_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    int user_id,
    chat_permissions_t *permissions,
    int use_independent_chat_permissions,
    int until_date
);

void restrict_chat_member_request_free(restrict_chat_member_request_t *restrict_chat_member_request);

restrict_chat_member_request_t *restrict_chat_member_request_parseFromJSON(cJSON *restrict_chat_member_requestJSON);

cJSON *restrict_chat_member_request_convertToJSON(restrict_chat_member_request_t *restrict_chat_member_request);

#endif /* _restrict_chat_member_request_H_ */

