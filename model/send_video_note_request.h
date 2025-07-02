/*
 * send_video_note_request.h
 *
 * Request parameters for sendVideoNote
 */

#ifndef _send_video_note_request_H_
#define _send_video_note_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_video_note_request_t send_video_note_request_t;

#include "reply_parameters.h"
#include "send_message_request_chat_id.h"
#include "send_message_request_reply_markup.h"



typedef struct send_video_note_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    char *video_note; // string
    char *business_connection_id; // string
    int message_thread_id; //numeric
    int duration; //numeric
    int length; //numeric
    char *thumbnail; // string
    int disable_notification; //boolean
    int protect_content; //boolean
    int allow_paid_broadcast; //boolean
    char *message_effect_id; // string
    struct reply_parameters_t *reply_parameters; //model
    struct send_message_request_reply_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} send_video_note_request_t;

__attribute__((deprecated)) send_video_note_request_t *send_video_note_request_create(
    send_message_request_chat_id_t *chat_id,
    char *video_note,
    char *business_connection_id,
    int message_thread_id,
    int duration,
    int length,
    char *thumbnail,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
);

void send_video_note_request_free(send_video_note_request_t *send_video_note_request);

send_video_note_request_t *send_video_note_request_parseFromJSON(cJSON *send_video_note_requestJSON);

cJSON *send_video_note_request_convertToJSON(send_video_note_request_t *send_video_note_request);

#endif /* _send_video_note_request_H_ */

