/*
 * _copy_message_post_request.h
 *
 * 
 */

#ifndef __copy_message_post_request_H_
#define __copy_message_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _copy_message_post_request_t _copy_message_post_request_t;

#include "_forward_message_post_request_from_chat_id.h"
#include "_send_message_post_request_chat_id.h"
#include "_send_message_post_request_reply_markup.h"
#include "message_entity.h"
#include "reply_parameters.h"



typedef struct _copy_message_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model
    struct _forward_message_post_request_from_chat_id_t *from_chat_id; //model
    int message_id; //numeric
    int message_thread_id; //numeric
    int video_start_timestamp; //numeric
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    int show_caption_above_media; //boolean
    int disable_notification; //boolean
    int protect_content; //boolean
    int allow_paid_broadcast; //boolean
    struct reply_parameters_t *reply_parameters; //model
    struct _send_message_post_request_reply_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _copy_message_post_request_t;

__attribute__((deprecated)) _copy_message_post_request_t *_copy_message_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    _forward_message_post_request_from_chat_id_t *from_chat_id,
    int message_id,
    int message_thread_id,
    int video_start_timestamp,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    reply_parameters_t *reply_parameters,
    _send_message_post_request_reply_markup_t *reply_markup
);

void _copy_message_post_request_free(_copy_message_post_request_t *_copy_message_post_request);

_copy_message_post_request_t *_copy_message_post_request_parseFromJSON(cJSON *_copy_message_post_requestJSON);

cJSON *_copy_message_post_request_convertToJSON(_copy_message_post_request_t *_copy_message_post_request);

#endif /* __copy_message_post_request_H_ */

