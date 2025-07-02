/*
 * create_chat_invite_link_request.h
 *
 * Request parameters for createChatInviteLink
 */

#ifndef _create_chat_invite_link_request_H_
#define _create_chat_invite_link_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_chat_invite_link_request_t create_chat_invite_link_request_t;

#include "send_message_request_chat_id.h"



typedef struct create_chat_invite_link_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    char *name; // string
    int expire_date; //numeric
    int member_limit; //numeric
    int creates_join_request; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} create_chat_invite_link_request_t;

__attribute__((deprecated)) create_chat_invite_link_request_t *create_chat_invite_link_request_create(
    send_message_request_chat_id_t *chat_id,
    char *name,
    int expire_date,
    int member_limit,
    int creates_join_request
);

void create_chat_invite_link_request_free(create_chat_invite_link_request_t *create_chat_invite_link_request);

create_chat_invite_link_request_t *create_chat_invite_link_request_parseFromJSON(cJSON *create_chat_invite_link_requestJSON);

cJSON *create_chat_invite_link_request_convertToJSON(create_chat_invite_link_request_t *create_chat_invite_link_request);

#endif /* _create_chat_invite_link_request_H_ */

