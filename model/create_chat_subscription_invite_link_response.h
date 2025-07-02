/*
 * create_chat_subscription_invite_link_response.h
 *
 * 
 */

#ifndef _create_chat_subscription_invite_link_response_H_
#define _create_chat_subscription_invite_link_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_chat_subscription_invite_link_response_t create_chat_subscription_invite_link_response_t;

#include "chat_invite_link.h"



typedef struct create_chat_subscription_invite_link_response_t {
    int ok; //boolean
    struct chat_invite_link_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} create_chat_subscription_invite_link_response_t;

__attribute__((deprecated)) create_chat_subscription_invite_link_response_t *create_chat_subscription_invite_link_response_create(
    int ok,
    chat_invite_link_t *result
);

void create_chat_subscription_invite_link_response_free(create_chat_subscription_invite_link_response_t *create_chat_subscription_invite_link_response);

create_chat_subscription_invite_link_response_t *create_chat_subscription_invite_link_response_parseFromJSON(cJSON *create_chat_subscription_invite_link_responseJSON);

cJSON *create_chat_subscription_invite_link_response_convertToJSON(create_chat_subscription_invite_link_response_t *create_chat_subscription_invite_link_response);

#endif /* _create_chat_subscription_invite_link_response_H_ */

