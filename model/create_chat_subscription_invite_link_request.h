/*
 * create_chat_subscription_invite_link_request.h
 *
 * Request parameters for createChatSubscriptionInviteLink
 */

#ifndef _create_chat_subscription_invite_link_request_H_
#define _create_chat_subscription_invite_link_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_chat_subscription_invite_link_request_t create_chat_subscription_invite_link_request_t;

#include "create_chat_subscription_invite_link_request_chat_id.h"



typedef struct create_chat_subscription_invite_link_request_t {
    struct create_chat_subscription_invite_link_request_chat_id_t *chat_id; //model
    int subscription_period; //numeric
    int subscription_price; //numeric
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} create_chat_subscription_invite_link_request_t;

__attribute__((deprecated)) create_chat_subscription_invite_link_request_t *create_chat_subscription_invite_link_request_create(
    create_chat_subscription_invite_link_request_chat_id_t *chat_id,
    int subscription_period,
    int subscription_price,
    char *name
);

void create_chat_subscription_invite_link_request_free(create_chat_subscription_invite_link_request_t *create_chat_subscription_invite_link_request);

create_chat_subscription_invite_link_request_t *create_chat_subscription_invite_link_request_parseFromJSON(cJSON *create_chat_subscription_invite_link_requestJSON);

cJSON *create_chat_subscription_invite_link_request_convertToJSON(create_chat_subscription_invite_link_request_t *create_chat_subscription_invite_link_request);

#endif /* _create_chat_subscription_invite_link_request_H_ */

