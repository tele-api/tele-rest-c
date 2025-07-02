/*
 * remove_chat_verification_request.h
 *
 * Request parameters for removeChatVerification
 */

#ifndef _remove_chat_verification_request_H_
#define _remove_chat_verification_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct remove_chat_verification_request_t remove_chat_verification_request_t;

#include "send_message_request_chat_id.h"



typedef struct remove_chat_verification_request_t {
    struct send_message_request_chat_id_t *chat_id; //model

    int _library_owned; // Is the library responsible for freeing this object?
} remove_chat_verification_request_t;

__attribute__((deprecated)) remove_chat_verification_request_t *remove_chat_verification_request_create(
    send_message_request_chat_id_t *chat_id
);

void remove_chat_verification_request_free(remove_chat_verification_request_t *remove_chat_verification_request);

remove_chat_verification_request_t *remove_chat_verification_request_parseFromJSON(cJSON *remove_chat_verification_requestJSON);

cJSON *remove_chat_verification_request_convertToJSON(remove_chat_verification_request_t *remove_chat_verification_request);

#endif /* _remove_chat_verification_request_H_ */

