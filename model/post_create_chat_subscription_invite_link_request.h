/*
 * post_create_chat_subscription_invite_link_request.h
 *
 * 
 */

#ifndef _post_create_chat_subscription_invite_link_request_H_
#define _post_create_chat_subscription_invite_link_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_create_chat_subscription_invite_link_request_t post_create_chat_subscription_invite_link_request_t;

#include "post_create_chat_subscription_invite_link_request_chat_id.h"



typedef struct post_create_chat_subscription_invite_link_request_t {
    struct post_create_chat_subscription_invite_link_request_chat_id_t *chat_id; //model
    int subscription_period; //numeric
    int subscription_price; //numeric
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} post_create_chat_subscription_invite_link_request_t;

__attribute__((deprecated)) post_create_chat_subscription_invite_link_request_t *post_create_chat_subscription_invite_link_request_create(
    post_create_chat_subscription_invite_link_request_chat_id_t *chat_id,
    int subscription_period,
    int subscription_price,
    char *name
);

void post_create_chat_subscription_invite_link_request_free(post_create_chat_subscription_invite_link_request_t *post_create_chat_subscription_invite_link_request);

post_create_chat_subscription_invite_link_request_t *post_create_chat_subscription_invite_link_request_parseFromJSON(cJSON *post_create_chat_subscription_invite_link_requestJSON);

cJSON *post_create_chat_subscription_invite_link_request_convertToJSON(post_create_chat_subscription_invite_link_request_t *post_create_chat_subscription_invite_link_request);

#endif /* _post_create_chat_subscription_invite_link_request_H_ */

