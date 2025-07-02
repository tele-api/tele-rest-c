/*
 * post_copy_message_request.h
 *
 * 
 */

#ifndef _post_copy_message_request_H_
#define _post_copy_message_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_copy_message_request_t post_copy_message_request_t;

#include "message_entity.h"
#include "post_forward_message_request_from_chat_id.h"
#include "post_send_message_request_chat_id.h"
#include "post_send_message_request_reply_markup.h"
#include "reply_parameters.h"



typedef struct post_copy_message_request_t {
    struct post_send_message_request_chat_id_t *chat_id; //model
    struct post_forward_message_request_from_chat_id_t *from_chat_id; //model
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
    struct post_send_message_request_reply_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_copy_message_request_t;

__attribute__((deprecated)) post_copy_message_request_t *post_copy_message_request_create(
    post_send_message_request_chat_id_t *chat_id,
    post_forward_message_request_from_chat_id_t *from_chat_id,
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
    post_send_message_request_reply_markup_t *reply_markup
);

void post_copy_message_request_free(post_copy_message_request_t *post_copy_message_request);

post_copy_message_request_t *post_copy_message_request_parseFromJSON(cJSON *post_copy_message_requestJSON);

cJSON *post_copy_message_request_convertToJSON(post_copy_message_request_t *post_copy_message_request);

#endif /* _post_copy_message_request_H_ */

