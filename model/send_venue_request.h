/*
 * send_venue_request.h
 *
 * Request parameters for sendVenue
 */

#ifndef _send_venue_request_H_
#define _send_venue_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_venue_request_t send_venue_request_t;

#include "reply_parameters.h"
#include "send_message_request_chat_id.h"
#include "send_message_request_reply_markup.h"



typedef struct send_venue_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    double latitude; //numeric
    double longitude; //numeric
    char *title; // string
    char *address; // string
    char *business_connection_id; // string
    int message_thread_id; //numeric
    char *foursquare_id; // string
    char *foursquare_type; // string
    char *google_place_id; // string
    char *google_place_type; // string
    int disable_notification; //boolean
    int protect_content; //boolean
    int allow_paid_broadcast; //boolean
    char *message_effect_id; // string
    struct reply_parameters_t *reply_parameters; //model
    struct send_message_request_reply_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} send_venue_request_t;

__attribute__((deprecated)) send_venue_request_t *send_venue_request_create(
    send_message_request_chat_id_t *chat_id,
    double latitude,
    double longitude,
    char *title,
    char *address,
    char *business_connection_id,
    int message_thread_id,
    char *foursquare_id,
    char *foursquare_type,
    char *google_place_id,
    char *google_place_type,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
);

void send_venue_request_free(send_venue_request_t *send_venue_request);

send_venue_request_t *send_venue_request_parseFromJSON(cJSON *send_venue_requestJSON);

cJSON *send_venue_request_convertToJSON(send_venue_request_t *send_venue_request);

#endif /* _send_venue_request_H_ */

