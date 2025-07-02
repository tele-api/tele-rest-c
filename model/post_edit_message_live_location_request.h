/*
 * post_edit_message_live_location_request.h
 *
 * 
 */

#ifndef _post_edit_message_live_location_request_H_
#define _post_edit_message_live_location_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_edit_message_live_location_request_t post_edit_message_live_location_request_t;

#include "inline_keyboard_markup.h"
#include "post_edit_message_text_request_chat_id.h"



typedef struct post_edit_message_live_location_request_t {
    double latitude; //numeric
    double longitude; //numeric
    char *business_connection_id; // string
    struct post_edit_message_text_request_chat_id_t *chat_id; //model
    int message_id; //numeric
    char *inline_message_id; // string
    int live_period; //numeric
    double horizontal_accuracy; //numeric
    int heading; //numeric
    int proximity_alert_radius; //numeric
    struct inline_keyboard_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_edit_message_live_location_request_t;

__attribute__((deprecated)) post_edit_message_live_location_request_t *post_edit_message_live_location_request_create(
    double latitude,
    double longitude,
    char *business_connection_id,
    post_edit_message_text_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    int live_period,
    double horizontal_accuracy,
    int heading,
    int proximity_alert_radius,
    inline_keyboard_markup_t *reply_markup
);

void post_edit_message_live_location_request_free(post_edit_message_live_location_request_t *post_edit_message_live_location_request);

post_edit_message_live_location_request_t *post_edit_message_live_location_request_parseFromJSON(cJSON *post_edit_message_live_location_requestJSON);

cJSON *post_edit_message_live_location_request_convertToJSON(post_edit_message_live_location_request_t *post_edit_message_live_location_request);

#endif /* _post_edit_message_live_location_request_H_ */

