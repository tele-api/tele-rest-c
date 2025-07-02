/*
 * stop_poll_request.h
 *
 * Request parameters for stopPoll
 */

#ifndef _stop_poll_request_H_
#define _stop_poll_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct stop_poll_request_t stop_poll_request_t;

#include "inline_keyboard_markup.h"
#include "send_message_request_chat_id.h"



typedef struct stop_poll_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    int message_id; //numeric
    char *business_connection_id; // string
    struct inline_keyboard_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} stop_poll_request_t;

__attribute__((deprecated)) stop_poll_request_t *stop_poll_request_create(
    send_message_request_chat_id_t *chat_id,
    int message_id,
    char *business_connection_id,
    inline_keyboard_markup_t *reply_markup
);

void stop_poll_request_free(stop_poll_request_t *stop_poll_request);

stop_poll_request_t *stop_poll_request_parseFromJSON(cJSON *stop_poll_requestJSON);

cJSON *stop_poll_request_convertToJSON(stop_poll_request_t *stop_poll_request);

#endif /* _stop_poll_request_H_ */

