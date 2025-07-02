/*
 * send_dice_request.h
 *
 * Request parameters for sendDice
 */

#ifndef _send_dice_request_H_
#define _send_dice_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_dice_request_t send_dice_request_t;

#include "reply_parameters.h"
#include "send_message_request_chat_id.h"
#include "send_message_request_reply_markup.h"

// Enum EMOJI for send_dice_request

typedef enum  { telegram_bot_api_send_dice_request_EMOJI_NULL = 0, telegram_bot_api_send_dice_request_EMOJI_🎲, telegram_bot_api_send_dice_request_EMOJI_🎯, telegram_bot_api_send_dice_request_EMOJI_🏀, telegram_bot_api_send_dice_request_EMOJI_⚽, telegram_bot_api_send_dice_request_EMOJI_🎳, telegram_bot_api_send_dice_request_EMOJI_🎰 } telegram_bot_api_send_dice_request_EMOJI_e;

char* send_dice_request_emoji_ToString(telegram_bot_api_send_dice_request_EMOJI_e emoji);

telegram_bot_api_send_dice_request_EMOJI_e send_dice_request_emoji_FromString(char* emoji);



typedef struct send_dice_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    char *business_connection_id; // string
    int message_thread_id; //numeric
    telegram_bot_api_send_dice_request_EMOJI_e emoji; //enum
    int disable_notification; //boolean
    int protect_content; //boolean
    int allow_paid_broadcast; //boolean
    char *message_effect_id; // string
    struct reply_parameters_t *reply_parameters; //model
    struct send_message_request_reply_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} send_dice_request_t;

__attribute__((deprecated)) send_dice_request_t *send_dice_request_create(
    send_message_request_chat_id_t *chat_id,
    char *business_connection_id,
    int message_thread_id,
    telegram_bot_api_send_dice_request_EMOJI_e emoji,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
);

void send_dice_request_free(send_dice_request_t *send_dice_request);

send_dice_request_t *send_dice_request_parseFromJSON(cJSON *send_dice_requestJSON);

cJSON *send_dice_request_convertToJSON(send_dice_request_t *send_dice_request);

#endif /* _send_dice_request_H_ */

