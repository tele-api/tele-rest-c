/*
 * unban_chat_member_request.h
 *
 * Request parameters for unbanChatMember
 */

#ifndef _unban_chat_member_request_H_
#define _unban_chat_member_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct unban_chat_member_request_t unban_chat_member_request_t;

#include "ban_chat_member_request_chat_id.h"



typedef struct unban_chat_member_request_t {
    struct ban_chat_member_request_chat_id_t *chat_id; //model
    int user_id; //numeric
    int only_if_banned; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} unban_chat_member_request_t;

__attribute__((deprecated)) unban_chat_member_request_t *unban_chat_member_request_create(
    ban_chat_member_request_chat_id_t *chat_id,
    int user_id,
    int only_if_banned
);

void unban_chat_member_request_free(unban_chat_member_request_t *unban_chat_member_request);

unban_chat_member_request_t *unban_chat_member_request_parseFromJSON(cJSON *unban_chat_member_requestJSON);

cJSON *unban_chat_member_request_convertToJSON(unban_chat_member_request_t *unban_chat_member_request);

#endif /* _unban_chat_member_request_H_ */

