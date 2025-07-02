/*
 * post_verify_chat_request.h
 *
 * 
 */

#ifndef _post_verify_chat_request_H_
#define _post_verify_chat_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_verify_chat_request_t post_verify_chat_request_t;

#include "post_send_message_request_chat_id.h"



typedef struct post_verify_chat_request_t {
    struct post_send_message_request_chat_id_t *chat_id; //model
    char *custom_description; // string

    int _library_owned; // Is the library responsible for freeing this object?
} post_verify_chat_request_t;

__attribute__((deprecated)) post_verify_chat_request_t *post_verify_chat_request_create(
    post_send_message_request_chat_id_t *chat_id,
    char *custom_description
);

void post_verify_chat_request_free(post_verify_chat_request_t *post_verify_chat_request);

post_verify_chat_request_t *post_verify_chat_request_parseFromJSON(cJSON *post_verify_chat_requestJSON);

cJSON *post_verify_chat_request_convertToJSON(post_verify_chat_request_t *post_verify_chat_request);

#endif /* _post_verify_chat_request_H_ */

