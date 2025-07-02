/*
 * forward_messages_request_from_chat_id.h
 *
 * Unique identifier for the chat where the original messages were sent (or channel username in the format &#x60;@channelusername&#x60;)
 */

#ifndef _forward_messages_request_from_chat_id_H_
#define _forward_messages_request_from_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct forward_messages_request_from_chat_id_t forward_messages_request_from_chat_id_t;




typedef struct forward_messages_request_from_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} forward_messages_request_from_chat_id_t;

__attribute__((deprecated)) forward_messages_request_from_chat_id_t *forward_messages_request_from_chat_id_create(
);

void forward_messages_request_from_chat_id_free(forward_messages_request_from_chat_id_t *forward_messages_request_from_chat_id);

forward_messages_request_from_chat_id_t *forward_messages_request_from_chat_id_parseFromJSON(cJSON *forward_messages_request_from_chat_idJSON);

cJSON *forward_messages_request_from_chat_id_convertToJSON(forward_messages_request_from_chat_id_t *forward_messages_request_from_chat_id);

#endif /* _forward_messages_request_from_chat_id_H_ */

