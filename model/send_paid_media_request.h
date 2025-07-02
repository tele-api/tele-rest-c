/*
 * send_paid_media_request.h
 *
 * Request parameters for sendPaidMedia
 */

#ifndef _send_paid_media_request_H_
#define _send_paid_media_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_paid_media_request_t send_paid_media_request_t;

#include "input_paid_media.h"
#include "message_entity.h"
#include "reply_parameters.h"
#include "send_message_request_reply_markup.h"
#include "send_paid_media_request_chat_id.h"



typedef struct send_paid_media_request_t {
    struct send_paid_media_request_chat_id_t *chat_id; //model
    int star_count; //numeric
    list_t *media; //nonprimitive container
    char *business_connection_id; // string
    char *payload; // string
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    int show_caption_above_media; //boolean
    int disable_notification; //boolean
    int protect_content; //boolean
    int allow_paid_broadcast; //boolean
    struct reply_parameters_t *reply_parameters; //model
    struct send_message_request_reply_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} send_paid_media_request_t;

__attribute__((deprecated)) send_paid_media_request_t *send_paid_media_request_create(
    send_paid_media_request_chat_id_t *chat_id,
    int star_count,
    list_t *media,
    char *business_connection_id,
    char *payload,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
);

void send_paid_media_request_free(send_paid_media_request_t *send_paid_media_request);

send_paid_media_request_t *send_paid_media_request_parseFromJSON(cJSON *send_paid_media_requestJSON);

cJSON *send_paid_media_request_convertToJSON(send_paid_media_request_t *send_paid_media_request);

#endif /* _send_paid_media_request_H_ */

