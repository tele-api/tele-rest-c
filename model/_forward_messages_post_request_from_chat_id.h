/*
 * _forward_messages_post_request_from_chat_id.h
 *
 * Unique identifier for the chat where the original messages were sent (or channel username in the format &#x60;@channelusername&#x60;)
 */

#ifndef __forward_messages_post_request_from_chat_id_H_
#define __forward_messages_post_request_from_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _forward_messages_post_request_from_chat_id_t _forward_messages_post_request_from_chat_id_t;




typedef struct _forward_messages_post_request_from_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} _forward_messages_post_request_from_chat_id_t;

__attribute__((deprecated)) _forward_messages_post_request_from_chat_id_t *_forward_messages_post_request_from_chat_id_create(
);

void _forward_messages_post_request_from_chat_id_free(_forward_messages_post_request_from_chat_id_t *_forward_messages_post_request_from_chat_id);

_forward_messages_post_request_from_chat_id_t *_forward_messages_post_request_from_chat_id_parseFromJSON(cJSON *_forward_messages_post_request_from_chat_idJSON);

cJSON *_forward_messages_post_request_from_chat_id_convertToJSON(_forward_messages_post_request_from_chat_id_t *_forward_messages_post_request_from_chat_id);

#endif /* __forward_messages_post_request_from_chat_id_H_ */

