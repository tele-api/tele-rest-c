/*
 * post_stop_poll_request.h
 *
 * 
 */

#ifndef _post_stop_poll_request_H_
#define _post_stop_poll_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_stop_poll_request_t post_stop_poll_request_t;

#include "inline_keyboard_markup.h"
#include "post_send_message_request_chat_id.h"



typedef struct post_stop_poll_request_t {
    struct post_send_message_request_chat_id_t *chat_id; //model
    int message_id; //numeric
    char *business_connection_id; // string
    struct inline_keyboard_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_stop_poll_request_t;

__attribute__((deprecated)) post_stop_poll_request_t *post_stop_poll_request_create(
    post_send_message_request_chat_id_t *chat_id,
    int message_id,
    char *business_connection_id,
    inline_keyboard_markup_t *reply_markup
);

void post_stop_poll_request_free(post_stop_poll_request_t *post_stop_poll_request);

post_stop_poll_request_t *post_stop_poll_request_parseFromJSON(cJSON *post_stop_poll_requestJSON);

cJSON *post_stop_poll_request_convertToJSON(post_stop_poll_request_t *post_stop_poll_request);

#endif /* _post_stop_poll_request_H_ */

