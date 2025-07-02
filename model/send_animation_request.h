/*
 * send_animation_request.h
 *
 * Request parameters for sendAnimation
 */

#ifndef _send_animation_request_H_
#define _send_animation_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_animation_request_t send_animation_request_t;

#include "message_entity.h"
#include "reply_parameters.h"
#include "send_message_request_chat_id.h"
#include "send_message_request_reply_markup.h"



typedef struct send_animation_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    char *animation; // string
    char *business_connection_id; // string
    int message_thread_id; //numeric
    int duration; //numeric
    int width; //numeric
    int height; //numeric
    char *thumbnail; // string
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    int show_caption_above_media; //boolean
    int has_spoiler; //boolean
    int disable_notification; //boolean
    int protect_content; //boolean
    int allow_paid_broadcast; //boolean
    char *message_effect_id; // string
    struct reply_parameters_t *reply_parameters; //model
    struct send_message_request_reply_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} send_animation_request_t;

__attribute__((deprecated)) send_animation_request_t *send_animation_request_create(
    send_message_request_chat_id_t *chat_id,
    char *animation,
    char *business_connection_id,
    int message_thread_id,
    int duration,
    int width,
    int height,
    char *thumbnail,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    int has_spoiler,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
);

void send_animation_request_free(send_animation_request_t *send_animation_request);

send_animation_request_t *send_animation_request_parseFromJSON(cJSON *send_animation_requestJSON);

cJSON *send_animation_request_convertToJSON(send_animation_request_t *send_animation_request);

#endif /* _send_animation_request_H_ */

