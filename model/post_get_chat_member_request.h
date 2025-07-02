/*
 * post_get_chat_member_request.h
 *
 * 
 */

#ifndef _post_get_chat_member_request_H_
#define _post_get_chat_member_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_get_chat_member_request_t post_get_chat_member_request_t;

#include "post_leave_chat_request_chat_id.h"



typedef struct post_get_chat_member_request_t {
    struct post_leave_chat_request_chat_id_t *chat_id; //model
    int user_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} post_get_chat_member_request_t;

__attribute__((deprecated)) post_get_chat_member_request_t *post_get_chat_member_request_create(
    post_leave_chat_request_chat_id_t *chat_id,
    int user_id
);

void post_get_chat_member_request_free(post_get_chat_member_request_t *post_get_chat_member_request);

post_get_chat_member_request_t *post_get_chat_member_request_parseFromJSON(cJSON *post_get_chat_member_requestJSON);

cJSON *post_get_chat_member_request_convertToJSON(post_get_chat_member_request_t *post_get_chat_member_request);

#endif /* _post_get_chat_member_request_H_ */

