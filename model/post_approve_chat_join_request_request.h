/*
 * post_approve_chat_join_request_request.h
 *
 * 
 */

#ifndef _post_approve_chat_join_request_request_H_
#define _post_approve_chat_join_request_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_approve_chat_join_request_request_t post_approve_chat_join_request_request_t;

#include "post_send_message_request_chat_id.h"



typedef struct post_approve_chat_join_request_request_t {
    struct post_send_message_request_chat_id_t *chat_id; //model
    int user_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} post_approve_chat_join_request_request_t;

__attribute__((deprecated)) post_approve_chat_join_request_request_t *post_approve_chat_join_request_request_create(
    post_send_message_request_chat_id_t *chat_id,
    int user_id
);

void post_approve_chat_join_request_request_free(post_approve_chat_join_request_request_t *post_approve_chat_join_request_request);

post_approve_chat_join_request_request_t *post_approve_chat_join_request_request_parseFromJSON(cJSON *post_approve_chat_join_request_requestJSON);

cJSON *post_approve_chat_join_request_request_convertToJSON(post_approve_chat_join_request_request_t *post_approve_chat_join_request_request);

#endif /* _post_approve_chat_join_request_request_H_ */

