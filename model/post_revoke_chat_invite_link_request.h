/*
 * post_revoke_chat_invite_link_request.h
 *
 * 
 */

#ifndef _post_revoke_chat_invite_link_request_H_
#define _post_revoke_chat_invite_link_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_revoke_chat_invite_link_request_t post_revoke_chat_invite_link_request_t;

#include "post_revoke_chat_invite_link_request_chat_id.h"



typedef struct post_revoke_chat_invite_link_request_t {
    struct post_revoke_chat_invite_link_request_chat_id_t *chat_id; //model
    char *invite_link; // string

    int _library_owned; // Is the library responsible for freeing this object?
} post_revoke_chat_invite_link_request_t;

__attribute__((deprecated)) post_revoke_chat_invite_link_request_t *post_revoke_chat_invite_link_request_create(
    post_revoke_chat_invite_link_request_chat_id_t *chat_id,
    char *invite_link
);

void post_revoke_chat_invite_link_request_free(post_revoke_chat_invite_link_request_t *post_revoke_chat_invite_link_request);

post_revoke_chat_invite_link_request_t *post_revoke_chat_invite_link_request_parseFromJSON(cJSON *post_revoke_chat_invite_link_requestJSON);

cJSON *post_revoke_chat_invite_link_request_convertToJSON(post_revoke_chat_invite_link_request_t *post_revoke_chat_invite_link_request);

#endif /* _post_revoke_chat_invite_link_request_H_ */

