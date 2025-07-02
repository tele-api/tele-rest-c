/*
 * post_ban_chat_sender_chat_request.h
 *
 * 
 */

#ifndef _post_ban_chat_sender_chat_request_H_
#define _post_ban_chat_sender_chat_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_ban_chat_sender_chat_request_t post_ban_chat_sender_chat_request_t;

#include "post_send_message_request_chat_id.h"



typedef struct post_ban_chat_sender_chat_request_t {
    struct post_send_message_request_chat_id_t *chat_id; //model
    int sender_chat_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} post_ban_chat_sender_chat_request_t;

__attribute__((deprecated)) post_ban_chat_sender_chat_request_t *post_ban_chat_sender_chat_request_create(
    post_send_message_request_chat_id_t *chat_id,
    int sender_chat_id
);

void post_ban_chat_sender_chat_request_free(post_ban_chat_sender_chat_request_t *post_ban_chat_sender_chat_request);

post_ban_chat_sender_chat_request_t *post_ban_chat_sender_chat_request_parseFromJSON(cJSON *post_ban_chat_sender_chat_requestJSON);

cJSON *post_ban_chat_sender_chat_request_convertToJSON(post_ban_chat_sender_chat_request_t *post_ban_chat_sender_chat_request);

#endif /* _post_ban_chat_sender_chat_request_H_ */

