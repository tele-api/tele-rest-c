/*
 * post_restrict_chat_member_request.h
 *
 * 
 */

#ifndef _post_restrict_chat_member_request_H_
#define _post_restrict_chat_member_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_restrict_chat_member_request_t post_restrict_chat_member_request_t;

#include "chat_permissions.h"
#include "post_restrict_chat_member_request_chat_id.h"



typedef struct post_restrict_chat_member_request_t {
    struct post_restrict_chat_member_request_chat_id_t *chat_id; //model
    int user_id; //numeric
    struct chat_permissions_t *permissions; //model
    int use_independent_chat_permissions; //boolean
    int until_date; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} post_restrict_chat_member_request_t;

__attribute__((deprecated)) post_restrict_chat_member_request_t *post_restrict_chat_member_request_create(
    post_restrict_chat_member_request_chat_id_t *chat_id,
    int user_id,
    chat_permissions_t *permissions,
    int use_independent_chat_permissions,
    int until_date
);

void post_restrict_chat_member_request_free(post_restrict_chat_member_request_t *post_restrict_chat_member_request);

post_restrict_chat_member_request_t *post_restrict_chat_member_request_parseFromJSON(cJSON *post_restrict_chat_member_requestJSON);

cJSON *post_restrict_chat_member_request_convertToJSON(post_restrict_chat_member_request_t *post_restrict_chat_member_request);

#endif /* _post_restrict_chat_member_request_H_ */

