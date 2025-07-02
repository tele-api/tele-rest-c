/*
 * create_chat_subscription_invite_link_request_chat_id.h
 *
 * Unique identifier for the target channel chat or username of the target channel (in the format &#x60;@channelusername&#x60;)
 */

#ifndef _create_chat_subscription_invite_link_request_chat_id_H_
#define _create_chat_subscription_invite_link_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_chat_subscription_invite_link_request_chat_id_t create_chat_subscription_invite_link_request_chat_id_t;




typedef struct create_chat_subscription_invite_link_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} create_chat_subscription_invite_link_request_chat_id_t;

__attribute__((deprecated)) create_chat_subscription_invite_link_request_chat_id_t *create_chat_subscription_invite_link_request_chat_id_create(
);

void create_chat_subscription_invite_link_request_chat_id_free(create_chat_subscription_invite_link_request_chat_id_t *create_chat_subscription_invite_link_request_chat_id);

create_chat_subscription_invite_link_request_chat_id_t *create_chat_subscription_invite_link_request_chat_id_parseFromJSON(cJSON *create_chat_subscription_invite_link_request_chat_idJSON);

cJSON *create_chat_subscription_invite_link_request_chat_id_convertToJSON(create_chat_subscription_invite_link_request_chat_id_t *create_chat_subscription_invite_link_request_chat_id);

#endif /* _create_chat_subscription_invite_link_request_chat_id_H_ */

