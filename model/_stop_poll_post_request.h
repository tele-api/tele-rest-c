/*
 * _stop_poll_post_request.h
 *
 * 
 */

#ifndef __stop_poll_post_request_H_
#define __stop_poll_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _stop_poll_post_request_t _stop_poll_post_request_t;

#include "_send_message_post_request_chat_id.h"
#include "inline_keyboard_markup.h"



typedef struct _stop_poll_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model
    int message_id; //numeric
    char *business_connection_id; // string
    struct inline_keyboard_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _stop_poll_post_request_t;

__attribute__((deprecated)) _stop_poll_post_request_t *_stop_poll_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    int message_id,
    char *business_connection_id,
    inline_keyboard_markup_t *reply_markup
);

void _stop_poll_post_request_free(_stop_poll_post_request_t *_stop_poll_post_request);

_stop_poll_post_request_t *_stop_poll_post_request_parseFromJSON(cJSON *_stop_poll_post_requestJSON);

cJSON *_stop_poll_post_request_convertToJSON(_stop_poll_post_request_t *_stop_poll_post_request);

#endif /* __stop_poll_post_request_H_ */

