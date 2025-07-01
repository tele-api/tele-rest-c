/*
 * _create_chat_subscription_invite_link_post_request.h
 *
 * 
 */

#ifndef __create_chat_subscription_invite_link_post_request_H_
#define __create_chat_subscription_invite_link_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _create_chat_subscription_invite_link_post_request_t _create_chat_subscription_invite_link_post_request_t;

#include "_create_chat_subscription_invite_link_post_request_chat_id.h"



typedef struct _create_chat_subscription_invite_link_post_request_t {
    struct _create_chat_subscription_invite_link_post_request_chat_id_t *chat_id; //model
    int subscription_period; //numeric
    int subscription_price; //numeric
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} _create_chat_subscription_invite_link_post_request_t;

__attribute__((deprecated)) _create_chat_subscription_invite_link_post_request_t *_create_chat_subscription_invite_link_post_request_create(
    _create_chat_subscription_invite_link_post_request_chat_id_t *chat_id,
    int subscription_period,
    int subscription_price,
    char *name
);

void _create_chat_subscription_invite_link_post_request_free(_create_chat_subscription_invite_link_post_request_t *_create_chat_subscription_invite_link_post_request);

_create_chat_subscription_invite_link_post_request_t *_create_chat_subscription_invite_link_post_request_parseFromJSON(cJSON *_create_chat_subscription_invite_link_post_requestJSON);

cJSON *_create_chat_subscription_invite_link_post_request_convertToJSON(_create_chat_subscription_invite_link_post_request_t *_create_chat_subscription_invite_link_post_request);

#endif /* __create_chat_subscription_invite_link_post_request_H_ */

