/*
 * post_send_dice_request.h
 *
 * 
 */

#ifndef _post_send_dice_request_H_
#define _post_send_dice_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_send_dice_request_t post_send_dice_request_t;

#include "post_send_message_request_chat_id.h"
#include "post_send_message_request_reply_markup.h"
#include "reply_parameters.h"

// Enum EMOJI for post_send_dice_request

typedef enum  { telegram_bot_api_post_send_dice_request_EMOJI_NULL = 0, telegram_bot_api_post_send_dice_request_EMOJI_🎲, telegram_bot_api_post_send_dice_request_EMOJI_🎯, telegram_bot_api_post_send_dice_request_EMOJI_🏀, telegram_bot_api_post_send_dice_request_EMOJI_⚽, telegram_bot_api_post_send_dice_request_EMOJI_🎳, telegram_bot_api_post_send_dice_request_EMOJI_🎰 } telegram_bot_api_post_send_dice_request_EMOJI_e;

char* post_send_dice_request_emoji_ToString(telegram_bot_api_post_send_dice_request_EMOJI_e emoji);

telegram_bot_api_post_send_dice_request_EMOJI_e post_send_dice_request_emoji_FromString(char* emoji);



typedef struct post_send_dice_request_t {
    struct post_send_message_request_chat_id_t *chat_id; //model
    char *business_connection_id; // string
    int message_thread_id; //numeric
    telegram_bot_api_post_send_dice_request_EMOJI_e emoji; //enum
    int disable_notification; //boolean
    int protect_content; //boolean
    int allow_paid_broadcast; //boolean
    char *message_effect_id; // string
    struct reply_parameters_t *reply_parameters; //model
    struct post_send_message_request_reply_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_send_dice_request_t;

__attribute__((deprecated)) post_send_dice_request_t *post_send_dice_request_create(
    post_send_message_request_chat_id_t *chat_id,
    char *business_connection_id,
    int message_thread_id,
    telegram_bot_api_post_send_dice_request_EMOJI_e emoji,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    post_send_message_request_reply_markup_t *reply_markup
);

void post_send_dice_request_free(post_send_dice_request_t *post_send_dice_request);

post_send_dice_request_t *post_send_dice_request_parseFromJSON(cJSON *post_send_dice_requestJSON);

cJSON *post_send_dice_request_convertToJSON(post_send_dice_request_t *post_send_dice_request);

#endif /* _post_send_dice_request_H_ */

