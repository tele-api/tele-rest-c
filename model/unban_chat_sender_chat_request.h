/*
 * unban_chat_sender_chat_request.h
 *
 * Request parameters for unbanChatSenderChat
 */

#ifndef _unban_chat_sender_chat_request_H_
#define _unban_chat_sender_chat_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct unban_chat_sender_chat_request_t unban_chat_sender_chat_request_t;

#include "send_message_request_chat_id.h"



typedef struct unban_chat_sender_chat_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    int sender_chat_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} unban_chat_sender_chat_request_t;

__attribute__((deprecated)) unban_chat_sender_chat_request_t *unban_chat_sender_chat_request_create(
    send_message_request_chat_id_t *chat_id,
    int sender_chat_id
);

void unban_chat_sender_chat_request_free(unban_chat_sender_chat_request_t *unban_chat_sender_chat_request);

unban_chat_sender_chat_request_t *unban_chat_sender_chat_request_parseFromJSON(cJSON *unban_chat_sender_chat_requestJSON);

cJSON *unban_chat_sender_chat_request_convertToJSON(unban_chat_sender_chat_request_t *unban_chat_sender_chat_request);

#endif /* _unban_chat_sender_chat_request_H_ */

