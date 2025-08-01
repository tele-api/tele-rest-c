/*
 * _revoke_chat_invite_link_post_request.h
 *
 * 
 */

#ifndef __revoke_chat_invite_link_post_request_H_
#define __revoke_chat_invite_link_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _revoke_chat_invite_link_post_request_t _revoke_chat_invite_link_post_request_t;

#include "_revoke_chat_invite_link_post_request_chat_id.h"



typedef struct _revoke_chat_invite_link_post_request_t {
    struct _revoke_chat_invite_link_post_request_chat_id_t *chat_id; //model
    char *invite_link; // string

    int _library_owned; // Is the library responsible for freeing this object?
} _revoke_chat_invite_link_post_request_t;

__attribute__((deprecated)) _revoke_chat_invite_link_post_request_t *_revoke_chat_invite_link_post_request_create(
    _revoke_chat_invite_link_post_request_chat_id_t *chat_id,
    char *invite_link
);

void _revoke_chat_invite_link_post_request_free(_revoke_chat_invite_link_post_request_t *_revoke_chat_invite_link_post_request);

_revoke_chat_invite_link_post_request_t *_revoke_chat_invite_link_post_request_parseFromJSON(cJSON *_revoke_chat_invite_link_post_requestJSON);

cJSON *_revoke_chat_invite_link_post_request_convertToJSON(_revoke_chat_invite_link_post_request_t *_revoke_chat_invite_link_post_request);

#endif /* __revoke_chat_invite_link_post_request_H_ */

