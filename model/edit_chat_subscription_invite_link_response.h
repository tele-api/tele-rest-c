/*
 * edit_chat_subscription_invite_link_response.h
 *
 * 
 */

#ifndef _edit_chat_subscription_invite_link_response_H_
#define _edit_chat_subscription_invite_link_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct edit_chat_subscription_invite_link_response_t edit_chat_subscription_invite_link_response_t;

#include "chat_invite_link.h"



typedef struct edit_chat_subscription_invite_link_response_t {
    int ok; //boolean
    struct chat_invite_link_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} edit_chat_subscription_invite_link_response_t;

__attribute__((deprecated)) edit_chat_subscription_invite_link_response_t *edit_chat_subscription_invite_link_response_create(
    int ok,
    chat_invite_link_t *result
);

void edit_chat_subscription_invite_link_response_free(edit_chat_subscription_invite_link_response_t *edit_chat_subscription_invite_link_response);

edit_chat_subscription_invite_link_response_t *edit_chat_subscription_invite_link_response_parseFromJSON(cJSON *edit_chat_subscription_invite_link_responseJSON);

cJSON *edit_chat_subscription_invite_link_response_convertToJSON(edit_chat_subscription_invite_link_response_t *edit_chat_subscription_invite_link_response);

#endif /* _edit_chat_subscription_invite_link_response_H_ */

