/*
 * _create_invoice_link_post_request.h
 *
 * 
 */

#ifndef __create_invoice_link_post_request_H_
#define __create_invoice_link_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _create_invoice_link_post_request_t _create_invoice_link_post_request_t;

#include "labeled_price.h"



typedef struct _create_invoice_link_post_request_t {
    char *title; // string
    char *description; // string
    char *payload; // string
    char *currency; // string
    list_t *prices; //nonprimitive container
    char *business_connection_id; // string
    char *provider_token; // string
    int subscription_period; //numeric
    int max_tip_amount; //numeric
    list_t *suggested_tip_amounts; //primitive container
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

    int _library_owned; // Is the library responsible for freeing this object?
} _create_invoice_link_post_request_t;

__attribute__((deprecated)) _create_invoice_link_post_request_t *_create_invoice_link_post_request_create(
    char *title,
    char *description,
    char *payload,
    char *currency,
    list_t *prices,
    char *business_connection_id,
    char *provider_token,
    int subscription_period,
    int max_tip_amount,
    list_t *suggested_tip_amounts,
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
    int is_flexible
);

void _create_invoice_link_post_request_free(_create_invoice_link_post_request_t *_create_invoice_link_post_request);

_create_invoice_link_post_request_t *_create_invoice_link_post_request_parseFromJSON(cJSON *_create_invoice_link_post_requestJSON);

cJSON *_create_invoice_link_post_request_convertToJSON(_create_invoice_link_post_request_t *_create_invoice_link_post_request);

#endif /* __create_invoice_link_post_request_H_ */

