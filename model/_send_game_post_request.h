/*
 * _send_game_post_request.h
 *
 * 
 */

#ifndef __send_game_post_request_H_
#define __send_game_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _send_game_post_request_t _send_game_post_request_t;

#include "inline_keyboard_markup.h"
#include "reply_parameters.h"



typedef struct _send_game_post_request_t {
    int chat_id; //numeric
    char *game_short_name; // string
    char *business_connection_id; // string
    int message_thread_id; //numeric
    int disable_notification; //boolean
    int protect_content; //boolean
    int allow_paid_broadcast; //boolean
    char *message_effect_id; // string
    struct reply_parameters_t *reply_parameters; //model
    struct inline_keyboard_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _send_game_post_request_t;

__attribute__((deprecated)) _send_game_post_request_t *_send_game_post_request_create(
    int chat_id,
    char *game_short_name,
    char *business_connection_id,
    int message_thread_id,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    inline_keyboard_markup_t *reply_markup
);

void _send_game_post_request_free(_send_game_post_request_t *_send_game_post_request);

_send_game_post_request_t *_send_game_post_request_parseFromJSON(cJSON *_send_game_post_requestJSON);

cJSON *_send_game_post_request_convertToJSON(_send_game_post_request_t *_send_game_post_request);

#endif /* __send_game_post_request_H_ */

