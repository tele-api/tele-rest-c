/*
 * ban_chat_member_request.h
 *
 * Request parameters for banChatMember
 */

#ifndef _ban_chat_member_request_H_
#define _ban_chat_member_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ban_chat_member_request_t ban_chat_member_request_t;

#include "ban_chat_member_request_chat_id.h"



typedef struct ban_chat_member_request_t {
    struct ban_chat_member_request_chat_id_t *chat_id; //model
    int user_id; //numeric
    int until_date; //numeric
    int revoke_messages; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} ban_chat_member_request_t;

__attribute__((deprecated)) ban_chat_member_request_t *ban_chat_member_request_create(
    ban_chat_member_request_chat_id_t *chat_id,
    int user_id,
    int until_date,
    int revoke_messages
);

void ban_chat_member_request_free(ban_chat_member_request_t *ban_chat_member_request);

ban_chat_member_request_t *ban_chat_member_request_parseFromJSON(cJSON *ban_chat_member_requestJSON);

cJSON *ban_chat_member_request_convertToJSON(ban_chat_member_request_t *ban_chat_member_request);

#endif /* _ban_chat_member_request_H_ */

