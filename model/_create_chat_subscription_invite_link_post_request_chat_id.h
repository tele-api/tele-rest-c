/*
 * _create_chat_subscription_invite_link_post_request_chat_id.h
 *
 * Unique identifier for the target channel chat or username of the target channel (in the format &#x60;@channelusername&#x60;)
 */

#ifndef __create_chat_subscription_invite_link_post_request_chat_id_H_
#define __create_chat_subscription_invite_link_post_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _create_chat_subscription_invite_link_post_request_chat_id_t _create_chat_subscription_invite_link_post_request_chat_id_t;




typedef struct _create_chat_subscription_invite_link_post_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} _create_chat_subscription_invite_link_post_request_chat_id_t;

__attribute__((deprecated)) _create_chat_subscription_invite_link_post_request_chat_id_t *_create_chat_subscription_invite_link_post_request_chat_id_create(
);

void _create_chat_subscription_invite_link_post_request_chat_id_free(_create_chat_subscription_invite_link_post_request_chat_id_t *_create_chat_subscription_invite_link_post_request_chat_id);

_create_chat_subscription_invite_link_post_request_chat_id_t *_create_chat_subscription_invite_link_post_request_chat_id_parseFromJSON(cJSON *_create_chat_subscription_invite_link_post_request_chat_idJSON);

cJSON *_create_chat_subscription_invite_link_post_request_chat_id_convertToJSON(_create_chat_subscription_invite_link_post_request_chat_id_t *_create_chat_subscription_invite_link_post_request_chat_id);

#endif /* __create_chat_subscription_invite_link_post_request_chat_id_H_ */

