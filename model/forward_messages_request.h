/*
 * forward_messages_request.h
 *
 * Request parameters for forwardMessages
 */

#ifndef _forward_messages_request_H_
#define _forward_messages_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct forward_messages_request_t forward_messages_request_t;

#include "forward_messages_request_from_chat_id.h"
#include "send_message_request_chat_id.h"



typedef struct forward_messages_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    struct forward_messages_request_from_chat_id_t *from_chat_id; //model
    list_t *message_ids; //primitive container
    int message_thread_id; //numeric
    int disable_notification; //boolean
    int protect_content; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} forward_messages_request_t;

__attribute__((deprecated)) forward_messages_request_t *forward_messages_request_create(
    send_message_request_chat_id_t *chat_id,
    forward_messages_request_from_chat_id_t *from_chat_id,
    list_t *message_ids,
    int message_thread_id,
    int disable_notification,
    int protect_content
);

void forward_messages_request_free(forward_messages_request_t *forward_messages_request);

forward_messages_request_t *forward_messages_request_parseFromJSON(cJSON *forward_messages_requestJSON);

cJSON *forward_messages_request_convertToJSON(forward_messages_request_t *forward_messages_request);

#endif /* _forward_messages_request_H_ */

