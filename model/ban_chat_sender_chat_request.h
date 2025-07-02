/*
 * ban_chat_sender_chat_request.h
 *
 * Request parameters for banChatSenderChat
 */

#ifndef _ban_chat_sender_chat_request_H_
#define _ban_chat_sender_chat_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ban_chat_sender_chat_request_t ban_chat_sender_chat_request_t;

#include "send_message_request_chat_id.h"



typedef struct ban_chat_sender_chat_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    int sender_chat_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} ban_chat_sender_chat_request_t;

__attribute__((deprecated)) ban_chat_sender_chat_request_t *ban_chat_sender_chat_request_create(
    send_message_request_chat_id_t *chat_id,
    int sender_chat_id
);

void ban_chat_sender_chat_request_free(ban_chat_sender_chat_request_t *ban_chat_sender_chat_request);

ban_chat_sender_chat_request_t *ban_chat_sender_chat_request_parseFromJSON(cJSON *ban_chat_sender_chat_requestJSON);

cJSON *ban_chat_sender_chat_request_convertToJSON(ban_chat_sender_chat_request_t *ban_chat_sender_chat_request);

#endif /* _ban_chat_sender_chat_request_H_ */

