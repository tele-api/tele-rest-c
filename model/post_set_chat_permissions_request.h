/*
 * post_set_chat_permissions_request.h
 *
 * 
 */

#ifndef _post_set_chat_permissions_request_H_
#define _post_set_chat_permissions_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_set_chat_permissions_request_t post_set_chat_permissions_request_t;

#include "chat_permissions.h"
#include "post_restrict_chat_member_request_chat_id.h"



typedef struct post_set_chat_permissions_request_t {
    struct post_restrict_chat_member_request_chat_id_t *chat_id; //model
    struct chat_permissions_t *permissions; //model
    int use_independent_chat_permissions; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} post_set_chat_permissions_request_t;

__attribute__((deprecated)) post_set_chat_permissions_request_t *post_set_chat_permissions_request_create(
    post_restrict_chat_member_request_chat_id_t *chat_id,
    chat_permissions_t *permissions,
    int use_independent_chat_permissions
);

void post_set_chat_permissions_request_free(post_set_chat_permissions_request_t *post_set_chat_permissions_request);

post_set_chat_permissions_request_t *post_set_chat_permissions_request_parseFromJSON(cJSON *post_set_chat_permissions_requestJSON);

cJSON *post_set_chat_permissions_request_convertToJSON(post_set_chat_permissions_request_t *post_set_chat_permissions_request);

#endif /* _post_set_chat_permissions_request_H_ */

