/*
 * _send_message_post_request.h
 *
 * 
 */

#ifndef __send_message_post_request_H_
#define __send_message_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _send_message_post_request_t _send_message_post_request_t;

#include "_send_message_post_request_chat_id.h"
#include "_send_message_post_request_reply_markup.h"
#include "link_preview_options.h"
#include "message_entity.h"
#include "reply_parameters.h"



typedef struct _send_message_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model
    char *text; // string
    char *business_connection_id; // string
    int message_thread_id; //numeric
    char *parse_mode; // string
    list_t *entities; //nonprimitive container
    struct link_preview_options_t *link_preview_options; //model
    int disable_notification; //boolean
    int protect_content; //boolean
    int allow_paid_broadcast; //boolean
    char *message_effect_id; // string
    struct reply_parameters_t *reply_parameters; //model
    struct _send_message_post_request_reply_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _send_message_post_request_t;

__attribute__((deprecated)) _send_message_post_request_t *_send_message_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    char *text,
    char *business_connection_id,
    int message_thread_id,
    char *parse_mode,
    list_t *entities,
    link_preview_options_t *link_preview_options,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    _send_message_post_request_reply_markup_t *reply_markup
);

void _send_message_post_request_free(_send_message_post_request_t *_send_message_post_request);

_send_message_post_request_t *_send_message_post_request_parseFromJSON(cJSON *_send_message_post_requestJSON);

cJSON *_send_message_post_request_convertToJSON(_send_message_post_request_t *_send_message_post_request);

#endif /* __send_message_post_request_H_ */

