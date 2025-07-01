/*
 * _send_venue_post_request.h
 *
 * 
 */

#ifndef __send_venue_post_request_H_
#define __send_venue_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _send_venue_post_request_t _send_venue_post_request_t;

#include "_send_message_post_request_chat_id.h"
#include "_send_message_post_request_reply_markup.h"
#include "reply_parameters.h"



typedef struct _send_venue_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model
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
    struct _send_message_post_request_reply_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _send_venue_post_request_t;

__attribute__((deprecated)) _send_venue_post_request_t *_send_venue_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
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
    _send_message_post_request_reply_markup_t *reply_markup
);

void _send_venue_post_request_free(_send_venue_post_request_t *_send_venue_post_request);

_send_venue_post_request_t *_send_venue_post_request_parseFromJSON(cJSON *_send_venue_post_requestJSON);

cJSON *_send_venue_post_request_convertToJSON(_send_venue_post_request_t *_send_venue_post_request);

#endif /* __send_venue_post_request_H_ */

