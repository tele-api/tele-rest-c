/*
 * post_unpin_chat_message_request.h
 *
 * 
 */

#ifndef _post_unpin_chat_message_request_H_
#define _post_unpin_chat_message_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_unpin_chat_message_request_t post_unpin_chat_message_request_t;

#include "post_send_message_request_chat_id.h"



typedef struct post_unpin_chat_message_request_t {
    struct post_send_message_request_chat_id_t *chat_id; //model
    char *business_connection_id; // string
    int message_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} post_unpin_chat_message_request_t;

__attribute__((deprecated)) post_unpin_chat_message_request_t *post_unpin_chat_message_request_create(
    post_send_message_request_chat_id_t *chat_id,
    char *business_connection_id,
    int message_id
);

void post_unpin_chat_message_request_free(post_unpin_chat_message_request_t *post_unpin_chat_message_request);

post_unpin_chat_message_request_t *post_unpin_chat_message_request_parseFromJSON(cJSON *post_unpin_chat_message_requestJSON);

cJSON *post_unpin_chat_message_request_convertToJSON(post_unpin_chat_message_request_t *post_unpin_chat_message_request);

#endif /* _post_unpin_chat_message_request_H_ */

