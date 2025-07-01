/*
 * _revoke_chat_invite_link_post_request_chat_id.h
 *
 * Unique identifier of the target chat or username of the target channel (in the format &#x60;@channelusername&#x60;)
 */

#ifndef __revoke_chat_invite_link_post_request_chat_id_H_
#define __revoke_chat_invite_link_post_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _revoke_chat_invite_link_post_request_chat_id_t _revoke_chat_invite_link_post_request_chat_id_t;




typedef struct _revoke_chat_invite_link_post_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} _revoke_chat_invite_link_post_request_chat_id_t;

__attribute__((deprecated)) _revoke_chat_invite_link_post_request_chat_id_t *_revoke_chat_invite_link_post_request_chat_id_create(
);

void _revoke_chat_invite_link_post_request_chat_id_free(_revoke_chat_invite_link_post_request_chat_id_t *_revoke_chat_invite_link_post_request_chat_id);

_revoke_chat_invite_link_post_request_chat_id_t *_revoke_chat_invite_link_post_request_chat_id_parseFromJSON(cJSON *_revoke_chat_invite_link_post_request_chat_idJSON);

cJSON *_revoke_chat_invite_link_post_request_chat_id_convertToJSON(_revoke_chat_invite_link_post_request_chat_id_t *_revoke_chat_invite_link_post_request_chat_id);

#endif /* __revoke_chat_invite_link_post_request_chat_id_H_ */

