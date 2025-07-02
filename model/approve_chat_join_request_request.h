/*
 * approve_chat_join_request_request.h
 *
 * Request parameters for approveChatJoinRequest
 */

#ifndef _approve_chat_join_request_request_H_
#define _approve_chat_join_request_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct approve_chat_join_request_request_t approve_chat_join_request_request_t;

#include "send_message_request_chat_id.h"



typedef struct approve_chat_join_request_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    int user_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} approve_chat_join_request_request_t;

__attribute__((deprecated)) approve_chat_join_request_request_t *approve_chat_join_request_request_create(
    send_message_request_chat_id_t *chat_id,
    int user_id
);

void approve_chat_join_request_request_free(approve_chat_join_request_request_t *approve_chat_join_request_request);

approve_chat_join_request_request_t *approve_chat_join_request_request_parseFromJSON(cJSON *approve_chat_join_request_requestJSON);

cJSON *approve_chat_join_request_request_convertToJSON(approve_chat_join_request_request_t *approve_chat_join_request_request);

#endif /* _approve_chat_join_request_request_H_ */

