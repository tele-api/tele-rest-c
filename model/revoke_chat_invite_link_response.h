/*
 * revoke_chat_invite_link_response.h
 *
 * 
 */

#ifndef _revoke_chat_invite_link_response_H_
#define _revoke_chat_invite_link_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct revoke_chat_invite_link_response_t revoke_chat_invite_link_response_t;

#include "chat_invite_link.h"



typedef struct revoke_chat_invite_link_response_t {
    int ok; //boolean
    struct chat_invite_link_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} revoke_chat_invite_link_response_t;

__attribute__((deprecated)) revoke_chat_invite_link_response_t *revoke_chat_invite_link_response_create(
    int ok,
    chat_invite_link_t *result
);

void revoke_chat_invite_link_response_free(revoke_chat_invite_link_response_t *revoke_chat_invite_link_response);

revoke_chat_invite_link_response_t *revoke_chat_invite_link_response_parseFromJSON(cJSON *revoke_chat_invite_link_responseJSON);

cJSON *revoke_chat_invite_link_response_convertToJSON(revoke_chat_invite_link_response_t *revoke_chat_invite_link_response);

#endif /* _revoke_chat_invite_link_response_H_ */

