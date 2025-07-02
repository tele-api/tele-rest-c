/*
 * copy_message_request.h
 *
 * Request parameters for copyMessage
 */

#ifndef _copy_message_request_H_
#define _copy_message_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct copy_message_request_t copy_message_request_t;

#include "forward_message_request_from_chat_id.h"
#include "message_entity.h"
#include "reply_parameters.h"
#include "send_message_request_chat_id.h"
#include "send_message_request_reply_markup.h"



typedef struct copy_message_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    struct forward_message_request_from_chat_id_t *from_chat_id; //model
    int message_id; //numeric
    int message_thread_id; //numeric
    int video_start_timestamp; //numeric
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
} copy_message_request_t;

__attribute__((deprecated)) copy_message_request_t *copy_message_request_create(
    send_message_request_chat_id_t *chat_id,
    forward_message_request_from_chat_id_t *from_chat_id,
    int message_id,
    int message_thread_id,
    int video_start_timestamp,
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

void copy_message_request_free(copy_message_request_t *copy_message_request);

copy_message_request_t *copy_message_request_parseFromJSON(cJSON *copy_message_requestJSON);

cJSON *copy_message_request_convertToJSON(copy_message_request_t *copy_message_request);

#endif /* _copy_message_request_H_ */

