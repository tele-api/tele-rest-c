/*
 * send_game_request.h
 *
 * Request parameters for sendGame
 */

#ifndef _send_game_request_H_
#define _send_game_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_game_request_t send_game_request_t;

#include "inline_keyboard_markup.h"
#include "reply_parameters.h"



typedef struct send_game_request_t {
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
} send_game_request_t;

__attribute__((deprecated)) send_game_request_t *send_game_request_create(
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

void send_game_request_free(send_game_request_t *send_game_request);

send_game_request_t *send_game_request_parseFromJSON(cJSON *send_game_requestJSON);

cJSON *send_game_request_convertToJSON(send_game_request_t *send_game_request);

#endif /* _send_game_request_H_ */

