/*
 * send_message_request_chat_id.h
 *
 * Unique identifier for the target chat or username of the target channel (in the format &#x60;@channelusername&#x60;)
 */

#ifndef _send_message_request_chat_id_H_
#define _send_message_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_message_request_chat_id_t send_message_request_chat_id_t;




typedef struct send_message_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} send_message_request_chat_id_t;

__attribute__((deprecated)) send_message_request_chat_id_t *send_message_request_chat_id_create(
);

void send_message_request_chat_id_free(send_message_request_chat_id_t *send_message_request_chat_id);

send_message_request_chat_id_t *send_message_request_chat_id_parseFromJSON(cJSON *send_message_request_chat_idJSON);

cJSON *send_message_request_chat_id_convertToJSON(send_message_request_chat_id_t *send_message_request_chat_id);

#endif /* _send_message_request_chat_id_H_ */

