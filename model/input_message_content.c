#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_message_content.h"



static input_message_content_t *input_message_content_create_internal(
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
    ) {
    input_message_content_t *input_message_content_local_var = malloc(sizeof(input_message_content_t));
    if (!input_message_content_local_var) {
        return NULL;
    }
    input_message_content_local_var->message_text = message_text;
    input_message_content_local_var->latitude = latitude;
    input_message_content_local_var->longitude = longitude;
    input_message_content_local_var->title = title;
    input_message_content_local_var->address = address;
    input_message_content_local_var->phone_number = phone_number;
    input_message_content_local_var->first_name = first_name;
    input_message_content_local_var->description = description;
    input_message_content_local_var->payload = payload;
    input_message_content_local_var->currency = currency;
    input_message_content_local_var->prices = prices;
    input_message_content_local_var->parse_mode = parse_mode;
    input_message_content_local_var->entities = entities;
    input_message_content_local_var->link_preview_options = link_preview_options;
    input_message_content_local_var->horizontal_accuracy = horizontal_accuracy;
    input_message_content_local_var->live_period = live_period;
    input_message_content_local_var->heading = heading;
    input_message_content_local_var->proximity_alert_radius = proximity_alert_radius;
    input_message_content_local_var->foursquare_id = foursquare_id;
    input_message_content_local_var->foursquare_type = foursquare_type;
    input_message_content_local_var->google_place_id = google_place_id;
    input_message_content_local_var->google_place_type = google_place_type;
    input_message_content_local_var->last_name = last_name;
    input_message_content_local_var->vcard = vcard;
    input_message_content_local_var->provider_token = provider_token;
    input_message_content_local_var->max_tip_amount = max_tip_amount;
    input_message_content_local_var->suggested_tip_amounts = suggested_tip_amounts;
    input_message_content_local_var->provider_data = provider_data;
    input_message_content_local_var->photo_url = photo_url;
    input_message_content_local_var->photo_size = photo_size;
    input_message_content_local_var->photo_width = photo_width;
    input_message_content_local_var->photo_height = photo_height;
    input_message_content_local_var->need_name = need_name;
    input_message_content_local_var->need_phone_number = need_phone_number;
    input_message_content_local_var->need_email = need_email;
    input_message_content_local_var->need_shipping_address = need_shipping_address;
    input_message_content_local_var->send_phone_number_to_provider = send_phone_number_to_provider;
    input_message_content_local_var->send_email_to_provider = send_email_to_provider;
    input_message_content_local_var->is_flexible = is_flexible;

    input_message_content_local_var->_library_owned = 1;
    return input_message_content_local_var;
}

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
    ) {
    return input_message_content_create_internal (
        message_text,
        latitude,
        longitude,
        title,
        address,
        phone_number,
        first_name,
        description,
        payload,
        currency,
        prices,
        parse_mode,
        entities,
        link_preview_options,
        horizontal_accuracy,
        live_period,
        heading,
        proximity_alert_radius,
        foursquare_id,
        foursquare_type,
        google_place_id,
        google_place_type,
        last_name,
        vcard,
        provider_token,
        max_tip_amount,
        suggested_tip_amounts,
        provider_data,
        photo_url,
        photo_size,
        photo_width,
        photo_height,
        need_name,
        need_phone_number,
        need_email,
        need_shipping_address,
        send_phone_number_to_provider,
        send_email_to_provider,
        is_flexible
        );
}

void input_message_content_free(input_message_content_t *input_message_content) {
    if(NULL == input_message_content){
        return ;
    }
    if(input_message_content->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_message_content_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_message_content->message_text) {
        free(input_message_content->message_text);
        input_message_content->message_text = NULL;
    }
    if (input_message_content->title) {
        free(input_message_content->title);
        input_message_content->title = NULL;
    }
    if (input_message_content->address) {
        free(input_message_content->address);
        input_message_content->address = NULL;
    }
    if (input_message_content->phone_number) {
        free(input_message_content->phone_number);
        input_message_content->phone_number = NULL;
    }
    if (input_message_content->first_name) {
        free(input_message_content->first_name);
        input_message_content->first_name = NULL;
    }
    if (input_message_content->description) {
        free(input_message_content->description);
        input_message_content->description = NULL;
    }
    if (input_message_content->payload) {
        free(input_message_content->payload);
        input_message_content->payload = NULL;
    }
    if (input_message_content->currency) {
        free(input_message_content->currency);
        input_message_content->currency = NULL;
    }
    if (input_message_content->prices) {
        list_ForEach(listEntry, input_message_content->prices) {
            labeled_price_free(listEntry->data);
        }
        list_freeList(input_message_content->prices);
        input_message_content->prices = NULL;
    }
    if (input_message_content->parse_mode) {
        free(input_message_content->parse_mode);
        input_message_content->parse_mode = NULL;
    }
    if (input_message_content->entities) {
        list_ForEach(listEntry, input_message_content->entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(input_message_content->entities);
        input_message_content->entities = NULL;
    }
    if (input_message_content->link_preview_options) {
        link_preview_options_free(input_message_content->link_preview_options);
        input_message_content->link_preview_options = NULL;
    }
    if (input_message_content->foursquare_id) {
        free(input_message_content->foursquare_id);
        input_message_content->foursquare_id = NULL;
    }
    if (input_message_content->foursquare_type) {
        free(input_message_content->foursquare_type);
        input_message_content->foursquare_type = NULL;
    }
    if (input_message_content->google_place_id) {
        free(input_message_content->google_place_id);
        input_message_content->google_place_id = NULL;
    }
    if (input_message_content->google_place_type) {
        free(input_message_content->google_place_type);
        input_message_content->google_place_type = NULL;
    }
    if (input_message_content->last_name) {
        free(input_message_content->last_name);
        input_message_content->last_name = NULL;
    }
    if (input_message_content->vcard) {
        free(input_message_content->vcard);
        input_message_content->vcard = NULL;
    }
    if (input_message_content->provider_token) {
        free(input_message_content->provider_token);
        input_message_content->provider_token = NULL;
    }
    if (input_message_content->suggested_tip_amounts) {
        list_ForEach(listEntry, input_message_content->suggested_tip_amounts) {
            free(listEntry->data);
        }
        list_freeList(input_message_content->suggested_tip_amounts);
        input_message_content->suggested_tip_amounts = NULL;
    }
    if (input_message_content->provider_data) {
        free(input_message_content->provider_data);
        input_message_content->provider_data = NULL;
    }
    if (input_message_content->photo_url) {
        free(input_message_content->photo_url);
        input_message_content->photo_url = NULL;
    }
    free(input_message_content);
}

cJSON *input_message_content_convertToJSON(input_message_content_t *input_message_content) {
    cJSON *item = cJSON_CreateObject();

    // input_message_content->message_text
    if (!input_message_content->message_text) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_text", input_message_content->message_text) == NULL) {
    goto fail; //String
    }


    // input_message_content->latitude
    if (!input_message_content->latitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "latitude", input_message_content->latitude) == NULL) {
    goto fail; //Numeric
    }


    // input_message_content->longitude
    if (!input_message_content->longitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "longitude", input_message_content->longitude) == NULL) {
    goto fail; //Numeric
    }


    // input_message_content->title
    if (!input_message_content->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", input_message_content->title) == NULL) {
    goto fail; //String
    }


    // input_message_content->address
    if (!input_message_content->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "address", input_message_content->address) == NULL) {
    goto fail; //String
    }


    // input_message_content->phone_number
    if (!input_message_content->phone_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "phone_number", input_message_content->phone_number) == NULL) {
    goto fail; //String
    }


    // input_message_content->first_name
    if (!input_message_content->first_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "first_name", input_message_content->first_name) == NULL) {
    goto fail; //String
    }


    // input_message_content->description
    if (!input_message_content->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", input_message_content->description) == NULL) {
    goto fail; //String
    }


    // input_message_content->payload
    if (!input_message_content->payload) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "payload", input_message_content->payload) == NULL) {
    goto fail; //String
    }


    // input_message_content->currency
    if (!input_message_content->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", input_message_content->currency) == NULL) {
    goto fail; //String
    }


    // input_message_content->prices
    if (!input_message_content->prices) {
        goto fail;
    }
    cJSON *prices = cJSON_AddArrayToObject(item, "prices");
    if(prices == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *pricesListEntry;
    if (input_message_content->prices) {
    list_ForEach(pricesListEntry, input_message_content->prices) {
    cJSON *itemLocal = labeled_price_convertToJSON(pricesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(prices, itemLocal);
    }
    }


    // input_message_content->parse_mode
    if(input_message_content->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", input_message_content->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // input_message_content->entities
    if(input_message_content->entities) {
    cJSON *entities = cJSON_AddArrayToObject(item, "entities");
    if(entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *entitiesListEntry;
    if (input_message_content->entities) {
    list_ForEach(entitiesListEntry, input_message_content->entities) {
    cJSON *itemLocal = message_entity_convertToJSON(entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(entities, itemLocal);
    }
    }
    }


    // input_message_content->link_preview_options
    if(input_message_content->link_preview_options) {
    cJSON *link_preview_options_local_JSON = link_preview_options_convertToJSON(input_message_content->link_preview_options);
    if(link_preview_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "link_preview_options", link_preview_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_message_content->horizontal_accuracy
    if(input_message_content->horizontal_accuracy) {
    if(cJSON_AddNumberToObject(item, "horizontal_accuracy", input_message_content->horizontal_accuracy) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_message_content->live_period
    if(input_message_content->live_period) {
    if(cJSON_AddNumberToObject(item, "live_period", input_message_content->live_period) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_message_content->heading
    if(input_message_content->heading) {
    if(cJSON_AddNumberToObject(item, "heading", input_message_content->heading) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_message_content->proximity_alert_radius
    if(input_message_content->proximity_alert_radius) {
    if(cJSON_AddNumberToObject(item, "proximity_alert_radius", input_message_content->proximity_alert_radius) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_message_content->foursquare_id
    if(input_message_content->foursquare_id) {
    if(cJSON_AddStringToObject(item, "foursquare_id", input_message_content->foursquare_id) == NULL) {
    goto fail; //String
    }
    }


    // input_message_content->foursquare_type
    if(input_message_content->foursquare_type) {
    if(cJSON_AddStringToObject(item, "foursquare_type", input_message_content->foursquare_type) == NULL) {
    goto fail; //String
    }
    }


    // input_message_content->google_place_id
    if(input_message_content->google_place_id) {
    if(cJSON_AddStringToObject(item, "google_place_id", input_message_content->google_place_id) == NULL) {
    goto fail; //String
    }
    }


    // input_message_content->google_place_type
    if(input_message_content->google_place_type) {
    if(cJSON_AddStringToObject(item, "google_place_type", input_message_content->google_place_type) == NULL) {
    goto fail; //String
    }
    }


    // input_message_content->last_name
    if(input_message_content->last_name) {
    if(cJSON_AddStringToObject(item, "last_name", input_message_content->last_name) == NULL) {
    goto fail; //String
    }
    }


    // input_message_content->vcard
    if(input_message_content->vcard) {
    if(cJSON_AddStringToObject(item, "vcard", input_message_content->vcard) == NULL) {
    goto fail; //String
    }
    }


    // input_message_content->provider_token
    if(input_message_content->provider_token) {
    if(cJSON_AddStringToObject(item, "provider_token", input_message_content->provider_token) == NULL) {
    goto fail; //String
    }
    }


    // input_message_content->max_tip_amount
    if(input_message_content->max_tip_amount) {
    if(cJSON_AddNumberToObject(item, "max_tip_amount", input_message_content->max_tip_amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_message_content->suggested_tip_amounts
    if(input_message_content->suggested_tip_amounts) {
    cJSON *suggested_tip_amounts = cJSON_AddArrayToObject(item, "suggested_tip_amounts");
    if(suggested_tip_amounts == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *suggested_tip_amountsListEntry;
    list_ForEach(suggested_tip_amountsListEntry, input_message_content->suggested_tip_amounts) {
    if(cJSON_AddNumberToObject(suggested_tip_amounts, "", *(double *)suggested_tip_amountsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // input_message_content->provider_data
    if(input_message_content->provider_data) {
    if(cJSON_AddStringToObject(item, "provider_data", input_message_content->provider_data) == NULL) {
    goto fail; //String
    }
    }


    // input_message_content->photo_url
    if(input_message_content->photo_url) {
    if(cJSON_AddStringToObject(item, "photo_url", input_message_content->photo_url) == NULL) {
    goto fail; //String
    }
    }


    // input_message_content->photo_size
    if(input_message_content->photo_size) {
    if(cJSON_AddNumberToObject(item, "photo_size", input_message_content->photo_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_message_content->photo_width
    if(input_message_content->photo_width) {
    if(cJSON_AddNumberToObject(item, "photo_width", input_message_content->photo_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_message_content->photo_height
    if(input_message_content->photo_height) {
    if(cJSON_AddNumberToObject(item, "photo_height", input_message_content->photo_height) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_message_content->need_name
    if(input_message_content->need_name) {
    if(cJSON_AddBoolToObject(item, "need_name", input_message_content->need_name) == NULL) {
    goto fail; //Bool
    }
    }


    // input_message_content->need_phone_number
    if(input_message_content->need_phone_number) {
    if(cJSON_AddBoolToObject(item, "need_phone_number", input_message_content->need_phone_number) == NULL) {
    goto fail; //Bool
    }
    }


    // input_message_content->need_email
    if(input_message_content->need_email) {
    if(cJSON_AddBoolToObject(item, "need_email", input_message_content->need_email) == NULL) {
    goto fail; //Bool
    }
    }


    // input_message_content->need_shipping_address
    if(input_message_content->need_shipping_address) {
    if(cJSON_AddBoolToObject(item, "need_shipping_address", input_message_content->need_shipping_address) == NULL) {
    goto fail; //Bool
    }
    }


    // input_message_content->send_phone_number_to_provider
    if(input_message_content->send_phone_number_to_provider) {
    if(cJSON_AddBoolToObject(item, "send_phone_number_to_provider", input_message_content->send_phone_number_to_provider) == NULL) {
    goto fail; //Bool
    }
    }


    // input_message_content->send_email_to_provider
    if(input_message_content->send_email_to_provider) {
    if(cJSON_AddBoolToObject(item, "send_email_to_provider", input_message_content->send_email_to_provider) == NULL) {
    goto fail; //Bool
    }
    }


    // input_message_content->is_flexible
    if(input_message_content->is_flexible) {
    if(cJSON_AddBoolToObject(item, "is_flexible", input_message_content->is_flexible) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

input_message_content_t *input_message_content_parseFromJSON(cJSON *input_message_contentJSON){

    input_message_content_t *input_message_content_local_var = NULL;

    // define the local list for input_message_content->prices
    list_t *pricesList = NULL;

    // define the local list for input_message_content->entities
    list_t *entitiesList = NULL;

    // define the local variable for input_message_content->link_preview_options
    link_preview_options_t *link_preview_options_local_nonprim = NULL;

    // define the local list for input_message_content->suggested_tip_amounts
    list_t *suggested_tip_amountsList = NULL;

    // input_message_content->message_text
    cJSON *message_text = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "message_text");
    if (cJSON_IsNull(message_text)) {
        message_text = NULL;
    }
    if (!message_text) {
        goto end;
    }

    
    if(!cJSON_IsString(message_text))
    {
    goto end; //String
    }

    // input_message_content->latitude
    cJSON *latitude = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "latitude");
    if (cJSON_IsNull(latitude)) {
        latitude = NULL;
    }
    if (!latitude) {
        goto end;
    }

    
    if(!cJSON_IsNumber(latitude))
    {
    goto end; //Numeric
    }

    // input_message_content->longitude
    cJSON *longitude = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "longitude");
    if (cJSON_IsNull(longitude)) {
        longitude = NULL;
    }
    if (!longitude) {
        goto end;
    }

    
    if(!cJSON_IsNumber(longitude))
    {
    goto end; //Numeric
    }

    // input_message_content->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }

    // input_message_content->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }

    // input_message_content->phone_number
    cJSON *phone_number = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "phone_number");
    if (cJSON_IsNull(phone_number)) {
        phone_number = NULL;
    }
    if (!phone_number) {
        goto end;
    }

    
    if(!cJSON_IsString(phone_number))
    {
    goto end; //String
    }

    // input_message_content->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "first_name");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (!first_name) {
        goto end;
    }

    
    if(!cJSON_IsString(first_name))
    {
    goto end; //String
    }

    // input_message_content->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (!description) {
        goto end;
    }

    
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }

    // input_message_content->payload
    cJSON *payload = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "payload");
    if (cJSON_IsNull(payload)) {
        payload = NULL;
    }
    if (!payload) {
        goto end;
    }

    
    if(!cJSON_IsString(payload))
    {
    goto end; //String
    }

    // input_message_content->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (!currency) {
        goto end;
    }

    
    if(!cJSON_IsString(currency))
    {
    goto end; //String
    }

    // input_message_content->prices
    cJSON *prices = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "prices");
    if (cJSON_IsNull(prices)) {
        prices = NULL;
    }
    if (!prices) {
        goto end;
    }

    
    cJSON *prices_local_nonprimitive = NULL;
    if(!cJSON_IsArray(prices)){
        goto end; //nonprimitive container
    }

    pricesList = list_createList();

    cJSON_ArrayForEach(prices_local_nonprimitive,prices )
    {
        if(!cJSON_IsObject(prices_local_nonprimitive)){
            goto end;
        }
        labeled_price_t *pricesItem = labeled_price_parseFromJSON(prices_local_nonprimitive);

        list_addElement(pricesList, pricesItem);
    }

    // input_message_content->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // input_message_content->entities
    cJSON *entities = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "entities");
    if (cJSON_IsNull(entities)) {
        entities = NULL;
    }
    if (entities) { 
    cJSON *entities_local_nonprimitive = NULL;
    if(!cJSON_IsArray(entities)){
        goto end; //nonprimitive container
    }

    entitiesList = list_createList();

    cJSON_ArrayForEach(entities_local_nonprimitive,entities )
    {
        if(!cJSON_IsObject(entities_local_nonprimitive)){
            goto end;
        }
        message_entity_t *entitiesItem = message_entity_parseFromJSON(entities_local_nonprimitive);

        list_addElement(entitiesList, entitiesItem);
    }
    }

    // input_message_content->link_preview_options
    cJSON *link_preview_options = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "link_preview_options");
    if (cJSON_IsNull(link_preview_options)) {
        link_preview_options = NULL;
    }
    if (link_preview_options) { 
    link_preview_options_local_nonprim = link_preview_options_parseFromJSON(link_preview_options); //nonprimitive
    }

    // input_message_content->horizontal_accuracy
    cJSON *horizontal_accuracy = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "horizontal_accuracy");
    if (cJSON_IsNull(horizontal_accuracy)) {
        horizontal_accuracy = NULL;
    }
    if (horizontal_accuracy) { 
    if(!cJSON_IsNumber(horizontal_accuracy))
    {
    goto end; //Numeric
    }
    }

    // input_message_content->live_period
    cJSON *live_period = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "live_period");
    if (cJSON_IsNull(live_period)) {
        live_period = NULL;
    }
    if (live_period) { 
    if(!cJSON_IsNumber(live_period))
    {
    goto end; //Numeric
    }
    }

    // input_message_content->heading
    cJSON *heading = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "heading");
    if (cJSON_IsNull(heading)) {
        heading = NULL;
    }
    if (heading) { 
    if(!cJSON_IsNumber(heading))
    {
    goto end; //Numeric
    }
    }

    // input_message_content->proximity_alert_radius
    cJSON *proximity_alert_radius = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "proximity_alert_radius");
    if (cJSON_IsNull(proximity_alert_radius)) {
        proximity_alert_radius = NULL;
    }
    if (proximity_alert_radius) { 
    if(!cJSON_IsNumber(proximity_alert_radius))
    {
    goto end; //Numeric
    }
    }

    // input_message_content->foursquare_id
    cJSON *foursquare_id = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "foursquare_id");
    if (cJSON_IsNull(foursquare_id)) {
        foursquare_id = NULL;
    }
    if (foursquare_id) { 
    if(!cJSON_IsString(foursquare_id) && !cJSON_IsNull(foursquare_id))
    {
    goto end; //String
    }
    }

    // input_message_content->foursquare_type
    cJSON *foursquare_type = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "foursquare_type");
    if (cJSON_IsNull(foursquare_type)) {
        foursquare_type = NULL;
    }
    if (foursquare_type) { 
    if(!cJSON_IsString(foursquare_type) && !cJSON_IsNull(foursquare_type))
    {
    goto end; //String
    }
    }

    // input_message_content->google_place_id
    cJSON *google_place_id = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "google_place_id");
    if (cJSON_IsNull(google_place_id)) {
        google_place_id = NULL;
    }
    if (google_place_id) { 
    if(!cJSON_IsString(google_place_id) && !cJSON_IsNull(google_place_id))
    {
    goto end; //String
    }
    }

    // input_message_content->google_place_type
    cJSON *google_place_type = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "google_place_type");
    if (cJSON_IsNull(google_place_type)) {
        google_place_type = NULL;
    }
    if (google_place_type) { 
    if(!cJSON_IsString(google_place_type) && !cJSON_IsNull(google_place_type))
    {
    goto end; //String
    }
    }

    // input_message_content->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "last_name");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }

    // input_message_content->vcard
    cJSON *vcard = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "vcard");
    if (cJSON_IsNull(vcard)) {
        vcard = NULL;
    }
    if (vcard) { 
    if(!cJSON_IsString(vcard) && !cJSON_IsNull(vcard))
    {
    goto end; //String
    }
    }

    // input_message_content->provider_token
    cJSON *provider_token = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "provider_token");
    if (cJSON_IsNull(provider_token)) {
        provider_token = NULL;
    }
    if (provider_token) { 
    if(!cJSON_IsString(provider_token) && !cJSON_IsNull(provider_token))
    {
    goto end; //String
    }
    }

    // input_message_content->max_tip_amount
    cJSON *max_tip_amount = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "max_tip_amount");
    if (cJSON_IsNull(max_tip_amount)) {
        max_tip_amount = NULL;
    }
    if (max_tip_amount) { 
    if(!cJSON_IsNumber(max_tip_amount))
    {
    goto end; //Numeric
    }
    }

    // input_message_content->suggested_tip_amounts
    cJSON *suggested_tip_amounts = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "suggested_tip_amounts");
    if (cJSON_IsNull(suggested_tip_amounts)) {
        suggested_tip_amounts = NULL;
    }
    if (suggested_tip_amounts) { 
    cJSON *suggested_tip_amounts_local = NULL;
    if(!cJSON_IsArray(suggested_tip_amounts)) {
        goto end;//primitive container
    }
    suggested_tip_amountsList = list_createList();

    cJSON_ArrayForEach(suggested_tip_amounts_local, suggested_tip_amounts)
    {
        if(!cJSON_IsNumber(suggested_tip_amounts_local))
        {
            goto end;
        }
        double *suggested_tip_amounts_local_value = calloc(1, sizeof(double));
        if(!suggested_tip_amounts_local_value)
        {
            goto end;
        }
        *suggested_tip_amounts_local_value = suggested_tip_amounts_local->valuedouble;
        list_addElement(suggested_tip_amountsList , suggested_tip_amounts_local_value);
    }
    }

    // input_message_content->provider_data
    cJSON *provider_data = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "provider_data");
    if (cJSON_IsNull(provider_data)) {
        provider_data = NULL;
    }
    if (provider_data) { 
    if(!cJSON_IsString(provider_data) && !cJSON_IsNull(provider_data))
    {
    goto end; //String
    }
    }

    // input_message_content->photo_url
    cJSON *photo_url = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "photo_url");
    if (cJSON_IsNull(photo_url)) {
        photo_url = NULL;
    }
    if (photo_url) { 
    if(!cJSON_IsString(photo_url) && !cJSON_IsNull(photo_url))
    {
    goto end; //String
    }
    }

    // input_message_content->photo_size
    cJSON *photo_size = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "photo_size");
    if (cJSON_IsNull(photo_size)) {
        photo_size = NULL;
    }
    if (photo_size) { 
    if(!cJSON_IsNumber(photo_size))
    {
    goto end; //Numeric
    }
    }

    // input_message_content->photo_width
    cJSON *photo_width = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "photo_width");
    if (cJSON_IsNull(photo_width)) {
        photo_width = NULL;
    }
    if (photo_width) { 
    if(!cJSON_IsNumber(photo_width))
    {
    goto end; //Numeric
    }
    }

    // input_message_content->photo_height
    cJSON *photo_height = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "photo_height");
    if (cJSON_IsNull(photo_height)) {
        photo_height = NULL;
    }
    if (photo_height) { 
    if(!cJSON_IsNumber(photo_height))
    {
    goto end; //Numeric
    }
    }

    // input_message_content->need_name
    cJSON *need_name = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "need_name");
    if (cJSON_IsNull(need_name)) {
        need_name = NULL;
    }
    if (need_name) { 
    if(!cJSON_IsBool(need_name))
    {
    goto end; //Bool
    }
    }

    // input_message_content->need_phone_number
    cJSON *need_phone_number = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "need_phone_number");
    if (cJSON_IsNull(need_phone_number)) {
        need_phone_number = NULL;
    }
    if (need_phone_number) { 
    if(!cJSON_IsBool(need_phone_number))
    {
    goto end; //Bool
    }
    }

    // input_message_content->need_email
    cJSON *need_email = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "need_email");
    if (cJSON_IsNull(need_email)) {
        need_email = NULL;
    }
    if (need_email) { 
    if(!cJSON_IsBool(need_email))
    {
    goto end; //Bool
    }
    }

    // input_message_content->need_shipping_address
    cJSON *need_shipping_address = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "need_shipping_address");
    if (cJSON_IsNull(need_shipping_address)) {
        need_shipping_address = NULL;
    }
    if (need_shipping_address) { 
    if(!cJSON_IsBool(need_shipping_address))
    {
    goto end; //Bool
    }
    }

    // input_message_content->send_phone_number_to_provider
    cJSON *send_phone_number_to_provider = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "send_phone_number_to_provider");
    if (cJSON_IsNull(send_phone_number_to_provider)) {
        send_phone_number_to_provider = NULL;
    }
    if (send_phone_number_to_provider) { 
    if(!cJSON_IsBool(send_phone_number_to_provider))
    {
    goto end; //Bool
    }
    }

    // input_message_content->send_email_to_provider
    cJSON *send_email_to_provider = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "send_email_to_provider");
    if (cJSON_IsNull(send_email_to_provider)) {
        send_email_to_provider = NULL;
    }
    if (send_email_to_provider) { 
    if(!cJSON_IsBool(send_email_to_provider))
    {
    goto end; //Bool
    }
    }

    // input_message_content->is_flexible
    cJSON *is_flexible = cJSON_GetObjectItemCaseSensitive(input_message_contentJSON, "is_flexible");
    if (cJSON_IsNull(is_flexible)) {
        is_flexible = NULL;
    }
    if (is_flexible) { 
    if(!cJSON_IsBool(is_flexible))
    {
    goto end; //Bool
    }
    }


    input_message_content_local_var = input_message_content_create_internal (
        strdup(message_text->valuestring),
        latitude->valuedouble,
        longitude->valuedouble,
        strdup(title->valuestring),
        strdup(address->valuestring),
        strdup(phone_number->valuestring),
        strdup(first_name->valuestring),
        strdup(description->valuestring),
        strdup(payload->valuestring),
        strdup(currency->valuestring),
        pricesList,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        entities ? entitiesList : NULL,
        link_preview_options ? link_preview_options_local_nonprim : NULL,
        horizontal_accuracy ? horizontal_accuracy->valuedouble : 0,
        live_period ? live_period->valuedouble : 0,
        heading ? heading->valuedouble : 0,
        proximity_alert_radius ? proximity_alert_radius->valuedouble : 0,
        foursquare_id && !cJSON_IsNull(foursquare_id) ? strdup(foursquare_id->valuestring) : NULL,
        foursquare_type && !cJSON_IsNull(foursquare_type) ? strdup(foursquare_type->valuestring) : NULL,
        google_place_id && !cJSON_IsNull(google_place_id) ? strdup(google_place_id->valuestring) : NULL,
        google_place_type && !cJSON_IsNull(google_place_type) ? strdup(google_place_type->valuestring) : NULL,
        last_name && !cJSON_IsNull(last_name) ? strdup(last_name->valuestring) : NULL,
        vcard && !cJSON_IsNull(vcard) ? strdup(vcard->valuestring) : NULL,
        provider_token && !cJSON_IsNull(provider_token) ? strdup(provider_token->valuestring) : NULL,
        max_tip_amount ? max_tip_amount->valuedouble : 0,
        suggested_tip_amounts ? suggested_tip_amountsList : NULL,
        provider_data && !cJSON_IsNull(provider_data) ? strdup(provider_data->valuestring) : NULL,
        photo_url && !cJSON_IsNull(photo_url) ? strdup(photo_url->valuestring) : NULL,
        photo_size ? photo_size->valuedouble : 0,
        photo_width ? photo_width->valuedouble : 0,
        photo_height ? photo_height->valuedouble : 0,
        need_name ? need_name->valueint : 0,
        need_phone_number ? need_phone_number->valueint : 0,
        need_email ? need_email->valueint : 0,
        need_shipping_address ? need_shipping_address->valueint : 0,
        send_phone_number_to_provider ? send_phone_number_to_provider->valueint : 0,
        send_email_to_provider ? send_email_to_provider->valueint : 0,
        is_flexible ? is_flexible->valueint : 0
        );

    return input_message_content_local_var;
end:
    if (pricesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, pricesList) {
            labeled_price_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(pricesList);
        pricesList = NULL;
    }
    if (entitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, entitiesList) {
            message_entity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(entitiesList);
        entitiesList = NULL;
    }
    if (link_preview_options_local_nonprim) {
        link_preview_options_free(link_preview_options_local_nonprim);
        link_preview_options_local_nonprim = NULL;
    }
    if (suggested_tip_amountsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, suggested_tip_amountsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(suggested_tip_amountsList);
        suggested_tip_amountsList = NULL;
    }
    return NULL;

}
