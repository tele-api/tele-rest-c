/*
 * stop_message_live_location_request.h
 *
 * Request parameters for stopMessageLiveLocation
 */

#ifndef _stop_message_live_location_request_H_
#define _stop_message_live_location_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct stop_message_live_location_request_t stop_message_live_location_request_t;

#include "edit_message_text_request_chat_id.h"
#include "inline_keyboard_markup.h"



typedef struct stop_message_live_location_request_t {
    char *business_connection_id; // string
    struct edit_message_text_request_chat_id_t *chat_id; //model
    int message_id; //numeric
    char *inline_message_id; // string
    struct inline_keyboard_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} stop_message_live_location_request_t;

__attribute__((deprecated)) stop_message_live_location_request_t *stop_message_live_location_request_create(
    char *business_connection_id,
    edit_message_text_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    inline_keyboard_markup_t *reply_markup
);

void stop_message_live_location_request_free(stop_message_live_location_request_t *stop_message_live_location_request);

stop_message_live_location_request_t *stop_message_live_location_request_parseFromJSON(cJSON *stop_message_live_location_requestJSON);

cJSON *stop_message_live_location_request_convertToJSON(stop_message_live_location_request_t *stop_message_live_location_request);

#endif /* _stop_message_live_location_request_H_ */

