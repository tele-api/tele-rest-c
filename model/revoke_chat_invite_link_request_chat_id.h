/*
 * revoke_chat_invite_link_request_chat_id.h
 *
 * Unique identifier of the target chat or username of the target channel (in the format &#x60;@channelusername&#x60;)
 */

#ifndef _revoke_chat_invite_link_request_chat_id_H_
#define _revoke_chat_invite_link_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct revoke_chat_invite_link_request_chat_id_t revoke_chat_invite_link_request_chat_id_t;




typedef struct revoke_chat_invite_link_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} revoke_chat_invite_link_request_chat_id_t;

__attribute__((deprecated)) revoke_chat_invite_link_request_chat_id_t *revoke_chat_invite_link_request_chat_id_create(
);

void revoke_chat_invite_link_request_chat_id_free(revoke_chat_invite_link_request_chat_id_t *revoke_chat_invite_link_request_chat_id);

revoke_chat_invite_link_request_chat_id_t *revoke_chat_invite_link_request_chat_id_parseFromJSON(cJSON *revoke_chat_invite_link_request_chat_idJSON);

cJSON *revoke_chat_invite_link_request_chat_id_convertToJSON(revoke_chat_invite_link_request_chat_id_t *revoke_chat_invite_link_request_chat_id);

#endif /* _revoke_chat_invite_link_request_chat_id_H_ */

