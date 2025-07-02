/*
 * decline_chat_join_request_request.h
 *
 * Request parameters for declineChatJoinRequest
 */

#ifndef _decline_chat_join_request_request_H_
#define _decline_chat_join_request_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct decline_chat_join_request_request_t decline_chat_join_request_request_t;

#include "send_message_request_chat_id.h"



typedef struct decline_chat_join_request_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    int user_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} decline_chat_join_request_request_t;

__attribute__((deprecated)) decline_chat_join_request_request_t *decline_chat_join_request_request_create(
    send_message_request_chat_id_t *chat_id,
    int user_id
);

void decline_chat_join_request_request_free(decline_chat_join_request_request_t *decline_chat_join_request_request);

decline_chat_join_request_request_t *decline_chat_join_request_request_parseFromJSON(cJSON *decline_chat_join_request_requestJSON);

cJSON *decline_chat_join_request_request_convertToJSON(decline_chat_join_request_request_t *decline_chat_join_request_request);

#endif /* _decline_chat_join_request_request_H_ */

