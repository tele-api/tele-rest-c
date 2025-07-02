/*
 * send_poll_request.h
 *
 * Request parameters for sendPoll
 */

#ifndef _send_poll_request_H_
#define _send_poll_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_poll_request_t send_poll_request_t;

#include "input_poll_option.h"
#include "message_entity.h"
#include "reply_parameters.h"
#include "send_message_request_chat_id.h"
#include "send_message_request_reply_markup.h"

// Enum TYPE for send_poll_request

typedef enum  { telegram_bot_api_send_poll_request_TYPE_NULL = 0, telegram_bot_api_send_poll_request_TYPE_quiz, telegram_bot_api_send_poll_request_TYPE_regular } telegram_bot_api_send_poll_request_TYPE_e;

char* send_poll_request_type_ToString(telegram_bot_api_send_poll_request_TYPE_e type);

telegram_bot_api_send_poll_request_TYPE_e send_poll_request_type_FromString(char* type);



typedef struct send_poll_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    char *question; // string
    list_t *options; //nonprimitive container
    char *business_connection_id; // string
    int message_thread_id; //numeric
    char *question_parse_mode; // string
    list_t *question_entities; //nonprimitive container
    int is_anonymous; //boolean
    telegram_bot_api_send_poll_request_TYPE_e type; //enum
    int allows_multiple_answers; //boolean
    int correct_option_id; //numeric
    char *explanation; // string
    char *explanation_parse_mode; // string
    list_t *explanation_entities; //nonprimitive container
    int open_period; //numeric
    int close_date; //numeric
    int is_closed; //boolean
    int disable_notification; //boolean
    int protect_content; //boolean
    int allow_paid_broadcast; //boolean
    char *message_effect_id; // string
    struct reply_parameters_t *reply_parameters; //model
    struct send_message_request_reply_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} send_poll_request_t;

__attribute__((deprecated)) send_poll_request_t *send_poll_request_create(
    send_message_request_chat_id_t *chat_id,
    char *question,
    list_t *options,
    char *business_connection_id,
    int message_thread_id,
    char *question_parse_mode,
    list_t *question_entities,
    int is_anonymous,
    telegram_bot_api_send_poll_request_TYPE_e type,
    int allows_multiple_answers,
    int correct_option_id,
    char *explanation,
    char *explanation_parse_mode,
    list_t *explanation_entities,
    int open_period,
    int close_date,
    int is_closed,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
);

void send_poll_request_free(send_poll_request_t *send_poll_request);

send_poll_request_t *send_poll_request_parseFromJSON(cJSON *send_poll_requestJSON);

cJSON *send_poll_request_convertToJSON(send_poll_request_t *send_poll_request);

#endif /* _send_poll_request_H_ */

