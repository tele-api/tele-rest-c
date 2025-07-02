/*
 * pin_chat_message_request.h
 *
 * Request parameters for pinChatMessage
 */

#ifndef _pin_chat_message_request_H_
#define _pin_chat_message_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pin_chat_message_request_t pin_chat_message_request_t;

#include "send_message_request_chat_id.h"



typedef struct pin_chat_message_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    int message_id; //numeric
    char *business_connection_id; // string
    int disable_notification; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} pin_chat_message_request_t;

__attribute__((deprecated)) pin_chat_message_request_t *pin_chat_message_request_create(
    send_message_request_chat_id_t *chat_id,
    int message_id,
    char *business_connection_id,
    int disable_notification
);

void pin_chat_message_request_free(pin_chat_message_request_t *pin_chat_message_request);

pin_chat_message_request_t *pin_chat_message_request_parseFromJSON(cJSON *pin_chat_message_requestJSON);

cJSON *pin_chat_message_request_convertToJSON(pin_chat_message_request_t *pin_chat_message_request);

#endif /* _pin_chat_message_request_H_ */

