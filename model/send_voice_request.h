/*
 * send_voice_request.h
 *
 * Request parameters for sendVoice
 */

#ifndef _send_voice_request_H_
#define _send_voice_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_voice_request_t send_voice_request_t;

#include "message_entity.h"
#include "reply_parameters.h"
#include "send_message_request_chat_id.h"
#include "send_message_request_reply_markup.h"



typedef struct send_voice_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    char *voice; // string
    char *business_connection_id; // string
    int message_thread_id; //numeric
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    int duration; //numeric
    int disable_notification; //boolean
    int protect_content; //boolean
    int allow_paid_broadcast; //boolean
    char *message_effect_id; // string
    struct reply_parameters_t *reply_parameters; //model
    struct send_message_request_reply_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} send_voice_request_t;

__attribute__((deprecated)) send_voice_request_t *send_voice_request_create(
    send_message_request_chat_id_t *chat_id,
    char *voice,
    char *business_connection_id,
    int message_thread_id,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int duration,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
);

void send_voice_request_free(send_voice_request_t *send_voice_request);

send_voice_request_t *send_voice_request_parseFromJSON(cJSON *send_voice_requestJSON);

cJSON *send_voice_request_convertToJSON(send_voice_request_t *send_voice_request);

#endif /* _send_voice_request_H_ */

