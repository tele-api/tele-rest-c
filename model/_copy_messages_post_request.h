/*
 * _copy_messages_post_request.h
 *
 * 
 */

#ifndef __copy_messages_post_request_H_
#define __copy_messages_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _copy_messages_post_request_t _copy_messages_post_request_t;

#include "_forward_messages_post_request_from_chat_id.h"
#include "_send_message_post_request_chat_id.h"



typedef struct _copy_messages_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model
    struct _forward_messages_post_request_from_chat_id_t *from_chat_id; //model
    list_t *message_ids; //primitive container
    int message_thread_id; //numeric
    int disable_notification; //boolean
    int protect_content; //boolean
    int remove_caption; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} _copy_messages_post_request_t;

__attribute__((deprecated)) _copy_messages_post_request_t *_copy_messages_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    _forward_messages_post_request_from_chat_id_t *from_chat_id,
    list_t *message_ids,
    int message_thread_id,
    int disable_notification,
    int protect_content,
    int remove_caption
);

void _copy_messages_post_request_free(_copy_messages_post_request_t *_copy_messages_post_request);

_copy_messages_post_request_t *_copy_messages_post_request_parseFromJSON(cJSON *_copy_messages_post_requestJSON);

cJSON *_copy_messages_post_request_convertToJSON(_copy_messages_post_request_t *_copy_messages_post_request);

#endif /* __copy_messages_post_request_H_ */

