/*
 * _edit_message_live_location_post_request.h
 *
 * 
 */

#ifndef __edit_message_live_location_post_request_H_
#define __edit_message_live_location_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _edit_message_live_location_post_request_t _edit_message_live_location_post_request_t;

#include "_edit_message_text_post_request_chat_id.h"
#include "inline_keyboard_markup.h"



typedef struct _edit_message_live_location_post_request_t {
    double latitude; //numeric
    double longitude; //numeric
    char *business_connection_id; // string
    struct _edit_message_text_post_request_chat_id_t *chat_id; //model
    int message_id; //numeric
    char *inline_message_id; // string
    int live_period; //numeric
    double horizontal_accuracy; //numeric
    int heading; //numeric
    int proximity_alert_radius; //numeric
    struct inline_keyboard_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _edit_message_live_location_post_request_t;

__attribute__((deprecated)) _edit_message_live_location_post_request_t *_edit_message_live_location_post_request_create(
    double latitude,
    double longitude,
    char *business_connection_id,
    _edit_message_text_post_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    int live_period,
    double horizontal_accuracy,
    int heading,
    int proximity_alert_radius,
    inline_keyboard_markup_t *reply_markup
);

void _edit_message_live_location_post_request_free(_edit_message_live_location_post_request_t *_edit_message_live_location_post_request);

_edit_message_live_location_post_request_t *_edit_message_live_location_post_request_parseFromJSON(cJSON *_edit_message_live_location_post_requestJSON);

cJSON *_edit_message_live_location_post_request_convertToJSON(_edit_message_live_location_post_request_t *_edit_message_live_location_post_request);

#endif /* __edit_message_live_location_post_request_H_ */

