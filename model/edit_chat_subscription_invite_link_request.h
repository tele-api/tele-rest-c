/*
 * edit_chat_subscription_invite_link_request.h
 *
 * Request parameters for editChatSubscriptionInviteLink
 */

#ifndef _edit_chat_subscription_invite_link_request_H_
#define _edit_chat_subscription_invite_link_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct edit_chat_subscription_invite_link_request_t edit_chat_subscription_invite_link_request_t;

#include "send_message_request_chat_id.h"



typedef struct edit_chat_subscription_invite_link_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    char *invite_link; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} edit_chat_subscription_invite_link_request_t;

__attribute__((deprecated)) edit_chat_subscription_invite_link_request_t *edit_chat_subscription_invite_link_request_create(
    send_message_request_chat_id_t *chat_id,
    char *invite_link,
    char *name
);

void edit_chat_subscription_invite_link_request_free(edit_chat_subscription_invite_link_request_t *edit_chat_subscription_invite_link_request);

edit_chat_subscription_invite_link_request_t *edit_chat_subscription_invite_link_request_parseFromJSON(cJSON *edit_chat_subscription_invite_link_requestJSON);

cJSON *edit_chat_subscription_invite_link_request_convertToJSON(edit_chat_subscription_invite_link_request_t *edit_chat_subscription_invite_link_request);

#endif /* _edit_chat_subscription_invite_link_request_H_ */

