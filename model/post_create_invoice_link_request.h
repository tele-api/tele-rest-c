/*
 * post_create_invoice_link_request.h
 *
 * 
 */

#ifndef _post_create_invoice_link_request_H_
#define _post_create_invoice_link_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_create_invoice_link_request_t post_create_invoice_link_request_t;

#include "labeled_price.h"



typedef struct post_create_invoice_link_request_t {
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
} post_create_invoice_link_request_t;

__attribute__((deprecated)) post_create_invoice_link_request_t *post_create_invoice_link_request_create(
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

void post_create_invoice_link_request_free(post_create_invoice_link_request_t *post_create_invoice_link_request);

post_create_invoice_link_request_t *post_create_invoice_link_request_parseFromJSON(cJSON *post_create_invoice_link_requestJSON);

cJSON *post_create_invoice_link_request_convertToJSON(post_create_invoice_link_request_t *post_create_invoice_link_request);

#endif /* _post_create_invoice_link_request_H_ */

