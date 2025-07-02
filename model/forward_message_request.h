/*
 * forward_message_request.h
 *
 * Request parameters for forwardMessage
 */

#ifndef _forward_message_request_H_
#define _forward_message_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct forward_message_request_t forward_message_request_t;

#include "forward_message_request_from_chat_id.h"
#include "send_message_request_chat_id.h"



typedef struct forward_message_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    struct forward_message_request_from_chat_id_t *from_chat_id; //model
    int message_id; //numeric
    int message_thread_id; //numeric
    int video_start_timestamp; //numeric
    int disable_notification; //boolean
    int protect_content; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} forward_message_request_t;

__attribute__((deprecated)) forward_message_request_t *forward_message_request_create(
    send_message_request_chat_id_t *chat_id,
    forward_message_request_from_chat_id_t *from_chat_id,
    int message_id,
    int message_thread_id,
    int video_start_timestamp,
    int disable_notification,
    int protect_content
);

void forward_message_request_free(forward_message_request_t *forward_message_request);

forward_message_request_t *forward_message_request_parseFromJSON(cJSON *forward_message_requestJSON);

cJSON *forward_message_request_convertToJSON(forward_message_request_t *forward_message_request);

#endif /* _forward_message_request_H_ */

