/*
 * input_message_content.h
 *
 * This object represents the content of a message to be sent as a result of an inline query. Telegram clients currently support the following 5 types:  * [InputTextMessageContent](https://core.telegram.org/bots/api/#inputtextmessagecontent) * [InputLocationMessageContent](https://core.telegram.org/bots/api/#inputlocationmessagecontent) * [InputVenueMessageContent](https://core.telegram.org/bots/api/#inputvenuemessagecontent) * [InputContactMessageContent](https://core.telegram.org/bots/api/#inputcontactmessagecontent) * [InputInvoiceMessageContent](https://core.telegram.org/bots/api/#inputinvoicemessagecontent)
 */

#ifndef _input_message_content_H_
#define _input_message_content_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_message_content_t input_message_content_t;

#include "input_contact_message_content.h"
#include "input_invoice_message_content.h"
#include "input_location_message_content.h"
#include "input_text_message_content.h"
#include "input_venue_message_content.h"
#include "labeled_price.h"
#include "link_preview_options.h"
#include "message_entity.h"



typedef struct input_message_content_t {
    char *message_text; // string
    double latitude; //numeric
    double longitude; //numeric
    char *title; // string
    char *address; // string
    char *phone_number; // string
    char *first_name; // string
    char *description; // string
    char *payload; // string
    char *currency; // string
    list_t *prices; //nonprimitive container
    char *parse_mode; // string
    list_t *entities; //nonprimitive container
    struct link_preview_options_t *link_preview_options; //model
    double horizontal_accuracy; //numeric
    int live_period; //numeric
    int heading; //numeric
    int proximity_alert_radius; //numeric
    char *foursquare_id; // string
    char *foursquare_type; // string
    char *google_place_id; // string
    char *google_place_type; // string
    char *last_name; // string
    char *vcard; // string
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
} input_message_content_t;

__attribute__((deprecated)) input_message_content_t *input_message_content_create(
    char *message_text,
    double latitude,
    double longitude,
    char *title,
    char *address,
    char *phone_number,
    char *first_name,
    char *description,
    char *payload,
    char *currency,
    list_t *prices,
    char *parse_mode,
    list_t *entities,
    link_preview_options_t *link_preview_options,
    double horizontal_accuracy,
    int live_period,
    int heading,
    int proximity_alert_radius,
    char *foursquare_id,
    char *foursquare_type,
    char *google_place_id,
    char *google_place_type,
    char *last_name,
    char *vcard,
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

void input_message_content_free(input_message_content_t *input_message_content);

input_message_content_t *input_message_content_parseFromJSON(cJSON *input_message_contentJSON);

cJSON *input_message_content_convertToJSON(input_message_content_t *input_message_content);

#endif /* _input_message_content_H_ */

