/*
 * send_media_group_request.h
 *
 * Request parameters for sendMediaGroup
 */

#ifndef _send_media_group_request_H_
#define _send_media_group_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_media_group_request_t send_media_group_request_t;

#include "reply_parameters.h"
#include "send_media_group_request_media_inner.h"
#include "send_message_request_chat_id.h"



typedef struct send_media_group_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    list_t *media; //nonprimitive container
    char *business_connection_id; // string
    int message_thread_id; //numeric
    int disable_notification; //boolean
    int protect_content; //boolean
    int allow_paid_broadcast; //boolean
    char *message_effect_id; // string
    struct reply_parameters_t *reply_parameters; //model

    int _library_owned; // Is the library responsible for freeing this object?
} send_media_group_request_t;

__attribute__((deprecated)) send_media_group_request_t *send_media_group_request_create(
    send_message_request_chat_id_t *chat_id,
    list_t *media,
    char *business_connection_id,
    int message_thread_id,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters
);

void send_media_group_request_free(send_media_group_request_t *send_media_group_request);

send_media_group_request_t *send_media_group_request_parseFromJSON(cJSON *send_media_group_requestJSON);

cJSON *send_media_group_request_convertToJSON(send_media_group_request_t *send_media_group_request);

#endif /* _send_media_group_request_H_ */

