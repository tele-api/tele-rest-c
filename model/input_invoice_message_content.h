/*
 * input_invoice_message_content.h
 *
 * Represents the [content](https://core.telegram.org/bots/api/#inputmessagecontent) of an invoice message to be sent as the result of an inline query.
 */

#ifndef _input_invoice_message_content_H_
#define _input_invoice_message_content_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_invoice_message_content_t input_invoice_message_content_t;

#include "labeled_price.h"



typedef struct input_invoice_message_content_t {
    char *title; // string
    char *description; // string
    char *payload; // string
    char *currency; // string
    list_t *prices; //nonprimitive container
    char *provider_token; // string
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
} input_invoice_message_content_t;

__attribute__((deprecated)) input_invoice_message_content_t *input_invoice_message_content_create(
    char *title,
    char *description,
    char *payload,
    char *currency,
    list_t *prices,
    char *provider_token,
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

void input_invoice_message_content_free(input_invoice_message_content_t *input_invoice_message_content);

input_invoice_message_content_t *input_invoice_message_content_parseFromJSON(cJSON *input_invoice_message_contentJSON);

cJSON *input_invoice_message_content_convertToJSON(input_invoice_message_content_t *input_invoice_message_content);

#endif /* _input_invoice_message_content_H_ */

