/*
 * _pin_chat_message_post_request.h
 *
 * 
 */

#ifndef __pin_chat_message_post_request_H_
#define __pin_chat_message_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _pin_chat_message_post_request_t _pin_chat_message_post_request_t;

#include "_send_message_post_request_chat_id.h"



typedef struct _pin_chat_message_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model
    int message_id; //numeric
    char *business_connection_id; // string
    int disable_notification; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} _pin_chat_message_post_request_t;

__attribute__((deprecated)) _pin_chat_message_post_request_t *_pin_chat_message_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    int message_id,
    char *business_connection_id,
    int disable_notification
);

void _pin_chat_message_post_request_free(_pin_chat_message_post_request_t *_pin_chat_message_post_request);

_pin_chat_message_post_request_t *_pin_chat_message_post_request_parseFromJSON(cJSON *_pin_chat_message_post_requestJSON);

cJSON *_pin_chat_message_post_request_convertToJSON(_pin_chat_message_post_request_t *_pin_chat_message_post_request);

#endif /* __pin_chat_message_post_request_H_ */

