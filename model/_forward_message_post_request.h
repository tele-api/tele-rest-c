/*
 * _forward_message_post_request.h
 *
 * 
 */

#ifndef __forward_message_post_request_H_
#define __forward_message_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _forward_message_post_request_t _forward_message_post_request_t;

#include "_forward_message_post_request_from_chat_id.h"
#include "_send_message_post_request_chat_id.h"



typedef struct _forward_message_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model
    struct _forward_message_post_request_from_chat_id_t *from_chat_id; //model
    int message_id; //numeric
    int message_thread_id; //numeric
    int video_start_timestamp; //numeric
    int disable_notification; //boolean
    int protect_content; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} _forward_message_post_request_t;

__attribute__((deprecated)) _forward_message_post_request_t *_forward_message_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    _forward_message_post_request_from_chat_id_t *from_chat_id,
    int message_id,
    int message_thread_id,
    int video_start_timestamp,
    int disable_notification,
    int protect_content
);

void _forward_message_post_request_free(_forward_message_post_request_t *_forward_message_post_request);

_forward_message_post_request_t *_forward_message_post_request_parseFromJSON(cJSON *_forward_message_post_requestJSON);

cJSON *_forward_message_post_request_convertToJSON(_forward_message_post_request_t *_forward_message_post_request);

#endif /* __forward_message_post_request_H_ */

