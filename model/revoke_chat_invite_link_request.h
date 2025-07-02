/*
 * revoke_chat_invite_link_request.h
 *
 * Request parameters for revokeChatInviteLink
 */

#ifndef _revoke_chat_invite_link_request_H_
#define _revoke_chat_invite_link_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct revoke_chat_invite_link_request_t revoke_chat_invite_link_request_t;

#include "revoke_chat_invite_link_request_chat_id.h"



typedef struct revoke_chat_invite_link_request_t {
    struct revoke_chat_invite_link_request_chat_id_t *chat_id; //model
    char *invite_link; // string

    int _library_owned; // Is the library responsible for freeing this object?
} revoke_chat_invite_link_request_t;

__attribute__((deprecated)) revoke_chat_invite_link_request_t *revoke_chat_invite_link_request_create(
    revoke_chat_invite_link_request_chat_id_t *chat_id,
    char *invite_link
);

void revoke_chat_invite_link_request_free(revoke_chat_invite_link_request_t *revoke_chat_invite_link_request);

revoke_chat_invite_link_request_t *revoke_chat_invite_link_request_parseFromJSON(cJSON *revoke_chat_invite_link_requestJSON);

cJSON *revoke_chat_invite_link_request_convertToJSON(revoke_chat_invite_link_request_t *revoke_chat_invite_link_request);

#endif /* _revoke_chat_invite_link_request_H_ */

