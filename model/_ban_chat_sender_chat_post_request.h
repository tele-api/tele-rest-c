/*
 * _ban_chat_sender_chat_post_request.h
 *
 * 
 */

#ifndef __ban_chat_sender_chat_post_request_H_
#define __ban_chat_sender_chat_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _ban_chat_sender_chat_post_request_t _ban_chat_sender_chat_post_request_t;

#include "_send_message_post_request_chat_id.h"



typedef struct _ban_chat_sender_chat_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model
    int sender_chat_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} _ban_chat_sender_chat_post_request_t;

__attribute__((deprecated)) _ban_chat_sender_chat_post_request_t *_ban_chat_sender_chat_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    int sender_chat_id
);

void _ban_chat_sender_chat_post_request_free(_ban_chat_sender_chat_post_request_t *_ban_chat_sender_chat_post_request);

_ban_chat_sender_chat_post_request_t *_ban_chat_sender_chat_post_request_parseFromJSON(cJSON *_ban_chat_sender_chat_post_requestJSON);

cJSON *_ban_chat_sender_chat_post_request_convertToJSON(_ban_chat_sender_chat_post_request_t *_ban_chat_sender_chat_post_request);

#endif /* __ban_chat_sender_chat_post_request_H_ */

