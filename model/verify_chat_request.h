/*
 * verify_chat_request.h
 *
 * Request parameters for verifyChat
 */

#ifndef _verify_chat_request_H_
#define _verify_chat_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct verify_chat_request_t verify_chat_request_t;

#include "send_message_request_chat_id.h"



typedef struct verify_chat_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    char *custom_description; // string

    int _library_owned; // Is the library responsible for freeing this object?
} verify_chat_request_t;

__attribute__((deprecated)) verify_chat_request_t *verify_chat_request_create(
    send_message_request_chat_id_t *chat_id,
    char *custom_description
);

void verify_chat_request_free(verify_chat_request_t *verify_chat_request);

verify_chat_request_t *verify_chat_request_parseFromJSON(cJSON *verify_chat_requestJSON);

cJSON *verify_chat_request_convertToJSON(verify_chat_request_t *verify_chat_request);

#endif /* _verify_chat_request_H_ */

