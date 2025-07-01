/*
 * _unpin_chat_message_post_request.h
 *
 * 
 */

#ifndef __unpin_chat_message_post_request_H_
#define __unpin_chat_message_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _unpin_chat_message_post_request_t _unpin_chat_message_post_request_t;

#include "_send_message_post_request_chat_id.h"



typedef struct _unpin_chat_message_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model
    char *business_connection_id; // string
    int message_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} _unpin_chat_message_post_request_t;

__attribute__((deprecated)) _unpin_chat_message_post_request_t *_unpin_chat_message_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    char *business_connection_id,
    int message_id
);

void _unpin_chat_message_post_request_free(_unpin_chat_message_post_request_t *_unpin_chat_message_post_request);

_unpin_chat_message_post_request_t *_unpin_chat_message_post_request_parseFromJSON(cJSON *_unpin_chat_message_post_requestJSON);

cJSON *_unpin_chat_message_post_request_convertToJSON(_unpin_chat_message_post_request_t *_unpin_chat_message_post_request);

#endif /* __unpin_chat_message_post_request_H_ */

