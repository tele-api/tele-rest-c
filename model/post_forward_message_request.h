/*
 * post_forward_message_request.h
 *
 * 
 */

#ifndef _post_forward_message_request_H_
#define _post_forward_message_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_forward_message_request_t post_forward_message_request_t;

#include "post_forward_message_request_from_chat_id.h"
#include "post_send_message_request_chat_id.h"



typedef struct post_forward_message_request_t {
    struct post_send_message_request_chat_id_t *chat_id; //model
    struct post_forward_message_request_from_chat_id_t *from_chat_id; //model
    int message_id; //numeric
    int message_thread_id; //numeric
    int video_start_timestamp; //numeric
    int disable_notification; //boolean
    int protect_content; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} post_forward_message_request_t;

__attribute__((deprecated)) post_forward_message_request_t *post_forward_message_request_create(
    post_send_message_request_chat_id_t *chat_id,
    post_forward_message_request_from_chat_id_t *from_chat_id,
    int message_id,
    int message_thread_id,
    int video_start_timestamp,
    int disable_notification,
    int protect_content
);

void post_forward_message_request_free(post_forward_message_request_t *post_forward_message_request);

post_forward_message_request_t *post_forward_message_request_parseFromJSON(cJSON *post_forward_message_requestJSON);

cJSON *post_forward_message_request_convertToJSON(post_forward_message_request_t *post_forward_message_request);

#endif /* _post_forward_message_request_H_ */

