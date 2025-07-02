/*
 * send_location_request.h
 *
 * Request parameters for sendLocation
 */

#ifndef _send_location_request_H_
#define _send_location_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_location_request_t send_location_request_t;

#include "reply_parameters.h"
#include "send_message_request_chat_id.h"
#include "send_message_request_reply_markup.h"



typedef struct send_location_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    double latitude; //numeric
    double longitude; //numeric
    char *business_connection_id; // string
    int message_thread_id; //numeric
    double horizontal_accuracy; //numeric
    int live_period; //numeric
    int heading; //numeric
    int proximity_alert_radius; //numeric
    int disable_notification; //boolean
    int protect_content; //boolean
    int allow_paid_broadcast; //boolean
    char *message_effect_id; // string
    struct reply_parameters_t *reply_parameters; //model
    struct send_message_request_reply_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} send_location_request_t;

__attribute__((deprecated)) send_location_request_t *send_location_request_create(
    send_message_request_chat_id_t *chat_id,
    double latitude,
    double longitude,
    char *business_connection_id,
    int message_thread_id,
    double horizontal_accuracy,
    int live_period,
    int heading,
    int proximity_alert_radius,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
);

void send_location_request_free(send_location_request_t *send_location_request);

send_location_request_t *send_location_request_parseFromJSON(cJSON *send_location_requestJSON);

cJSON *send_location_request_convertToJSON(send_location_request_t *send_location_request);

#endif /* _send_location_request_H_ */

