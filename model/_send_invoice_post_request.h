/*
 * _send_invoice_post_request.h
 *
 * 
 */

#ifndef __send_invoice_post_request_H_
#define __send_invoice_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _send_invoice_post_request_t _send_invoice_post_request_t;

#include "_send_message_post_request_chat_id.h"
#include "inline_keyboard_markup.h"
#include "labeled_price.h"
#include "reply_parameters.h"



typedef struct _send_invoice_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model
    char *title; // string
    char *description; // string
    char *payload; // string
    char *currency; // string
    list_t *prices; //nonprimitive container
    int message_thread_id; //numeric
    char *provider_token; // string
    int max_tip_amount; //numeric
    list_t *suggested_tip_amounts; //primitive container
    char *start_parameter; // string
    char *provider_data; // string
    char *photo_url; // string
    int photo_size; //numeric
    int photo_width; //numeric
    int photo_height; //numeric
    int need_name; //boolean
    int need_phone_number; //boolean
    int need_email; //boolean
    int need_shipping_address; //boolean
    int send_phone_number_to_provider; //boolean
    int send_email_to_provider; //boolean
    int is_flexible; //boolean
    int disable_notification; //boolean
    int protect_content; //boolean
    int allow_paid_broadcast; //boolean
    char *message_effect_id; // string
    struct reply_parameters_t *reply_parameters; //model
    struct inline_keyboard_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _send_invoice_post_request_t;

__attribute__((deprecated)) _send_invoice_post_request_t *_send_invoice_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    char *title,
    char *description,
    char *payload,
    char *currency,
    list_t *prices,
    int message_thread_id,
    char *provider_token,
    int max_tip_amount,
    list_t *suggested_tip_amounts,
    char *start_parameter,
    char *provider_data,
    char *photo_url,
    int photo_size,
    int photo_width,
    int photo_height,
    int need_name,
    int need_phone_number,
    int need_email,
    int need_shipping_address,
    int send_phone_number_to_provider,
    int send_email_to_provider,
    int is_flexible,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    inline_keyboard_markup_t *reply_markup
);

void _send_invoice_post_request_free(_send_invoice_post_request_t *_send_invoice_post_request);

_send_invoice_post_request_t *_send_invoice_post_request_parseFromJSON(cJSON *_send_invoice_post_requestJSON);

cJSON *_send_invoice_post_request_convertToJSON(_send_invoice_post_request_t *_send_invoice_post_request);

#endif /* __send_invoice_post_request_H_ */

