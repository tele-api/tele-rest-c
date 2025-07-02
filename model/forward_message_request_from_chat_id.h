/*
 * forward_message_request_from_chat_id.h
 *
 * Unique identifier for the chat where the original message was sent (or channel username in the format &#x60;@channelusername&#x60;)
 */

#ifndef _forward_message_request_from_chat_id_H_
#define _forward_message_request_from_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct forward_message_request_from_chat_id_t forward_message_request_from_chat_id_t;




typedef struct forward_message_request_from_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} forward_message_request_from_chat_id_t;

__attribute__((deprecated)) forward_message_request_from_chat_id_t *forward_message_request_from_chat_id_create(
);

void forward_message_request_from_chat_id_free(forward_message_request_from_chat_id_t *forward_message_request_from_chat_id);

forward_message_request_from_chat_id_t *forward_message_request_from_chat_id_parseFromJSON(cJSON *forward_message_request_from_chat_idJSON);

cJSON *forward_message_request_from_chat_id_convertToJSON(forward_message_request_from_chat_id_t *forward_message_request_from_chat_id);

#endif /* _forward_message_request_from_chat_id_H_ */

