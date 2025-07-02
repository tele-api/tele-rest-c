#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_invoice_request.h"



static send_invoice_request_t *send_invoice_request_create_internal(
    send_message_request_chat_id_t *chat_id,
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
    ) {
    send_invoice_request_t *send_invoice_request_local_var = malloc(sizeof(send_invoice_request_t));
    if (!send_invoice_request_local_var) {
        return NULL;
    }
    send_invoice_request_local_var->chat_id = chat_id;
    send_invoice_request_local_var->title = title;
    send_invoice_request_local_var->description = description;
    send_invoice_request_local_var->payload = payload;
    send_invoice_request_local_var->currency = currency;
    send_invoice_request_local_var->prices = prices;
    send_invoice_request_local_var->message_thread_id = message_thread_id;
    send_invoice_request_local_var->provider_token = provider_token;
    send_invoice_request_local_var->max_tip_amount = max_tip_amount;
    send_invoice_request_local_var->suggested_tip_amounts = suggested_tip_amounts;
    send_invoice_request_local_var->start_parameter = start_parameter;
    send_invoice_request_local_var->provider_data = provider_data;
    send_invoice_request_local_var->photo_url = photo_url;
    send_invoice_request_local_var->photo_size = photo_size;
    send_invoice_request_local_var->photo_width = photo_width;
    send_invoice_request_local_var->photo_height = photo_height;
    send_invoice_request_local_var->need_name = need_name;
    send_invoice_request_local_var->need_phone_number = need_phone_number;
    send_invoice_request_local_var->need_email = need_email;
    send_invoice_request_local_var->need_shipping_address = need_shipping_address;
    send_invoice_request_local_var->send_phone_number_to_provider = send_phone_number_to_provider;
    send_invoice_request_local_var->send_email_to_provider = send_email_to_provider;
    send_invoice_request_local_var->is_flexible = is_flexible;
    send_invoice_request_local_var->disable_notification = disable_notification;
    send_invoice_request_local_var->protect_content = protect_content;
    send_invoice_request_local_var->allow_paid_broadcast = allow_paid_broadcast;
    send_invoice_request_local_var->message_effect_id = message_effect_id;
    send_invoice_request_local_var->reply_parameters = reply_parameters;
    send_invoice_request_local_var->reply_markup = reply_markup;

    send_invoice_request_local_var->_library_owned = 1;
    return send_invoice_request_local_var;
}

__attribute__((deprecated)) send_invoice_request_t *send_invoice_request_create(
    send_message_request_chat_id_t *chat_id,
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
    ) {
    return send_invoice_request_create_internal (
        chat_id,
        title,
        description,
        payload,
        currency,
        prices,
        message_thread_id,
        provider_token,
        max_tip_amount,
        suggested_tip_amounts,
        start_parameter,
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
        is_flexible,
        disable_notification,
        protect_content,
        allow_paid_broadcast,
        message_effect_id,
        reply_parameters,
        reply_markup
        );
}

void send_invoice_request_free(send_invoice_request_t *send_invoice_request) {
    if(NULL == send_invoice_request){
        return ;
    }
    if(send_invoice_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_invoice_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (send_invoice_request->chat_id) {
        send_message_request_chat_id_free(send_invoice_request->chat_id);
        send_invoice_request->chat_id = NULL;
    }
    if (send_invoice_request->title) {
        free(send_invoice_request->title);
        send_invoice_request->title = NULL;
    }
    if (send_invoice_request->description) {
        free(send_invoice_request->description);
        send_invoice_request->description = NULL;
    }
    if (send_invoice_request->payload) {
        free(send_invoice_request->payload);
        send_invoice_request->payload = NULL;
    }
    if (send_invoice_request->currency) {
        free(send_invoice_request->currency);
        send_invoice_request->currency = NULL;
    }
    if (send_invoice_request->prices) {
        list_ForEach(listEntry, send_invoice_request->prices) {
            labeled_price_free(listEntry->data);
        }
        list_freeList(send_invoice_request->prices);
        send_invoice_request->prices = NULL;
    }
    if (send_invoice_request->provider_token) {
        free(send_invoice_request->provider_token);
        send_invoice_request->provider_token = NULL;
    }
    if (send_invoice_request->suggested_tip_amounts) {
        list_ForEach(listEntry, send_invoice_request->suggested_tip_amounts) {
            free(listEntry->data);
        }
        list_freeList(send_invoice_request->suggested_tip_amounts);
        send_invoice_request->suggested_tip_amounts = NULL;
    }
    if (send_invoice_request->start_parameter) {
        free(send_invoice_request->start_parameter);
        send_invoice_request->start_parameter = NULL;
    }
    if (send_invoice_request->provider_data) {
        free(send_invoice_request->provider_data);
        send_invoice_request->provider_data = NULL;
    }
    if (send_invoice_request->photo_url) {
        free(send_invoice_request->photo_url);
        send_invoice_request->photo_url = NULL;
    }
    if (send_invoice_request->message_effect_id) {
        free(send_invoice_request->message_effect_id);
        send_invoice_request->message_effect_id = NULL;
    }
    if (send_invoice_request->reply_parameters) {
        reply_parameters_free(send_invoice_request->reply_parameters);
        send_invoice_request->reply_parameters = NULL;
    }
    if (send_invoice_request->reply_markup) {
        inline_keyboard_markup_free(send_invoice_request->reply_markup);
        send_invoice_request->reply_markup = NULL;
    }
    free(send_invoice_request);
}

cJSON *send_invoice_request_convertToJSON(send_invoice_request_t *send_invoice_request) {
    cJSON *item = cJSON_CreateObject();

    // send_invoice_request->chat_id
    if (!send_invoice_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(send_invoice_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // send_invoice_request->title
    if (!send_invoice_request->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", send_invoice_request->title) == NULL) {
    goto fail; //String
    }


    // send_invoice_request->description
    if (!send_invoice_request->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", send_invoice_request->description) == NULL) {
    goto fail; //String
    }


    // send_invoice_request->payload
    if (!send_invoice_request->payload) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "payload", send_invoice_request->payload) == NULL) {
    goto fail; //String
    }


    // send_invoice_request->currency
    if (!send_invoice_request->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", send_invoice_request->currency) == NULL) {
    goto fail; //String
    }


    // send_invoice_request->prices
    if (!send_invoice_request->prices) {
        goto fail;
    }
    cJSON *prices = cJSON_AddArrayToObject(item, "prices");
    if(prices == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *pricesListEntry;
    if (send_invoice_request->prices) {
    list_ForEach(pricesListEntry, send_invoice_request->prices) {
    cJSON *itemLocal = labeled_price_convertToJSON(pricesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(prices, itemLocal);
    }
    }


    // send_invoice_request->message_thread_id
    if(send_invoice_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", send_invoice_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // send_invoice_request->provider_token
    if(send_invoice_request->provider_token) {
    if(cJSON_AddStringToObject(item, "provider_token", send_invoice_request->provider_token) == NULL) {
    goto fail; //String
    }
    }


    // send_invoice_request->max_tip_amount
    if(send_invoice_request->max_tip_amount) {
    if(cJSON_AddNumberToObject(item, "max_tip_amount", send_invoice_request->max_tip_amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // send_invoice_request->suggested_tip_amounts
    if(send_invoice_request->suggested_tip_amounts) {
    cJSON *suggested_tip_amounts = cJSON_AddArrayToObject(item, "suggested_tip_amounts");
    if(suggested_tip_amounts == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *suggested_tip_amountsListEntry;
    list_ForEach(suggested_tip_amountsListEntry, send_invoice_request->suggested_tip_amounts) {
    if(cJSON_AddNumberToObject(suggested_tip_amounts, "", *(double *)suggested_tip_amountsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // send_invoice_request->start_parameter
    if(send_invoice_request->start_parameter) {
    if(cJSON_AddStringToObject(item, "start_parameter", send_invoice_request->start_parameter) == NULL) {
    goto fail; //String
    }
    }


    // send_invoice_request->provider_data
    if(send_invoice_request->provider_data) {
    if(cJSON_AddStringToObject(item, "provider_data", send_invoice_request->provider_data) == NULL) {
    goto fail; //String
    }
    }


    // send_invoice_request->photo_url
    if(send_invoice_request->photo_url) {
    if(cJSON_AddStringToObject(item, "photo_url", send_invoice_request->photo_url) == NULL) {
    goto fail; //String
    }
    }


    // send_invoice_request->photo_size
    if(send_invoice_request->photo_size) {
    if(cJSON_AddNumberToObject(item, "photo_size", send_invoice_request->photo_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // send_invoice_request->photo_width
    if(send_invoice_request->photo_width) {
    if(cJSON_AddNumberToObject(item, "photo_width", send_invoice_request->photo_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // send_invoice_request->photo_height
    if(send_invoice_request->photo_height) {
    if(cJSON_AddNumberToObject(item, "photo_height", send_invoice_request->photo_height) == NULL) {
    goto fail; //Numeric
    }
    }


    // send_invoice_request->need_name
    if(send_invoice_request->need_name) {
    if(cJSON_AddBoolToObject(item, "need_name", send_invoice_request->need_name) == NULL) {
    goto fail; //Bool
    }
    }


    // send_invoice_request->need_phone_number
    if(send_invoice_request->need_phone_number) {
    if(cJSON_AddBoolToObject(item, "need_phone_number", send_invoice_request->need_phone_number) == NULL) {
    goto fail; //Bool
    }
    }


    // send_invoice_request->need_email
    if(send_invoice_request->need_email) {
    if(cJSON_AddBoolToObject(item, "need_email", send_invoice_request->need_email) == NULL) {
    goto fail; //Bool
    }
    }


    // send_invoice_request->need_shipping_address
    if(send_invoice_request->need_shipping_address) {
    if(cJSON_AddBoolToObject(item, "need_shipping_address", send_invoice_request->need_shipping_address) == NULL) {
    goto fail; //Bool
    }
    }


    // send_invoice_request->send_phone_number_to_provider
    if(send_invoice_request->send_phone_number_to_provider) {
    if(cJSON_AddBoolToObject(item, "send_phone_number_to_provider", send_invoice_request->send_phone_number_to_provider) == NULL) {
    goto fail; //Bool
    }
    }


    // send_invoice_request->send_email_to_provider
    if(send_invoice_request->send_email_to_provider) {
    if(cJSON_AddBoolToObject(item, "send_email_to_provider", send_invoice_request->send_email_to_provider) == NULL) {
    goto fail; //Bool
    }
    }


    // send_invoice_request->is_flexible
    if(send_invoice_request->is_flexible) {
    if(cJSON_AddBoolToObject(item, "is_flexible", send_invoice_request->is_flexible) == NULL) {
    goto fail; //Bool
    }
    }


    // send_invoice_request->disable_notification
    if(send_invoice_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", send_invoice_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // send_invoice_request->protect_content
    if(send_invoice_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", send_invoice_request->protect_content) == NULL) {
    goto fail; //Bool
    }
    }


    // send_invoice_request->allow_paid_broadcast
    if(send_invoice_request->allow_paid_broadcast) {
    if(cJSON_AddBoolToObject(item, "allow_paid_broadcast", send_invoice_request->allow_paid_broadcast) == NULL) {
    goto fail; //Bool
    }
    }


    // send_invoice_request->message_effect_id
    if(send_invoice_request->message_effect_id) {
    if(cJSON_AddStringToObject(item, "message_effect_id", send_invoice_request->message_effect_id) == NULL) {
    goto fail; //String
    }
    }


    // send_invoice_request->reply_parameters
    if(send_invoice_request->reply_parameters) {
    cJSON *reply_parameters_local_JSON = reply_parameters_convertToJSON(send_invoice_request->reply_parameters);
    if(reply_parameters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_parameters", reply_parameters_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // send_invoice_request->reply_markup
    if(send_invoice_request->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(send_invoice_request->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

send_invoice_request_t *send_invoice_request_parseFromJSON(cJSON *send_invoice_requestJSON){

    send_invoice_request_t *send_invoice_request_local_var = NULL;

    // define the local variable for send_invoice_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for send_invoice_request->prices
    list_t *pricesList = NULL;

    // define the local list for send_invoice_request->suggested_tip_amounts
    list_t *suggested_tip_amountsList = NULL;

    // define the local variable for send_invoice_request->reply_parameters
    reply_parameters_t *reply_parameters_local_nonprim = NULL;

    // define the local variable for send_invoice_request->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // send_invoice_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // send_invoice_request->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "title");
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

    // send_invoice_request->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "description");
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

    // send_invoice_request->payload
    cJSON *payload = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "payload");
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

    // send_invoice_request->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "currency");
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

    // send_invoice_request->prices
    cJSON *prices = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "prices");
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

    // send_invoice_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // send_invoice_request->provider_token
    cJSON *provider_token = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "provider_token");
    if (cJSON_IsNull(provider_token)) {
        provider_token = NULL;
    }
    if (provider_token) { 
    if(!cJSON_IsString(provider_token) && !cJSON_IsNull(provider_token))
    {
    goto end; //String
    }
    }

    // send_invoice_request->max_tip_amount
    cJSON *max_tip_amount = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "max_tip_amount");
    if (cJSON_IsNull(max_tip_amount)) {
        max_tip_amount = NULL;
    }
    if (max_tip_amount) { 
    if(!cJSON_IsNumber(max_tip_amount))
    {
    goto end; //Numeric
    }
    }

    // send_invoice_request->suggested_tip_amounts
    cJSON *suggested_tip_amounts = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "suggested_tip_amounts");
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

    // send_invoice_request->start_parameter
    cJSON *start_parameter = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "start_parameter");
    if (cJSON_IsNull(start_parameter)) {
        start_parameter = NULL;
    }
    if (start_parameter) { 
    if(!cJSON_IsString(start_parameter) && !cJSON_IsNull(start_parameter))
    {
    goto end; //String
    }
    }

    // send_invoice_request->provider_data
    cJSON *provider_data = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "provider_data");
    if (cJSON_IsNull(provider_data)) {
        provider_data = NULL;
    }
    if (provider_data) { 
    if(!cJSON_IsString(provider_data) && !cJSON_IsNull(provider_data))
    {
    goto end; //String
    }
    }

    // send_invoice_request->photo_url
    cJSON *photo_url = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "photo_url");
    if (cJSON_IsNull(photo_url)) {
        photo_url = NULL;
    }
    if (photo_url) { 
    if(!cJSON_IsString(photo_url) && !cJSON_IsNull(photo_url))
    {
    goto end; //String
    }
    }

    // send_invoice_request->photo_size
    cJSON *photo_size = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "photo_size");
    if (cJSON_IsNull(photo_size)) {
        photo_size = NULL;
    }
    if (photo_size) { 
    if(!cJSON_IsNumber(photo_size))
    {
    goto end; //Numeric
    }
    }

    // send_invoice_request->photo_width
    cJSON *photo_width = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "photo_width");
    if (cJSON_IsNull(photo_width)) {
        photo_width = NULL;
    }
    if (photo_width) { 
    if(!cJSON_IsNumber(photo_width))
    {
    goto end; //Numeric
    }
    }

    // send_invoice_request->photo_height
    cJSON *photo_height = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "photo_height");
    if (cJSON_IsNull(photo_height)) {
        photo_height = NULL;
    }
    if (photo_height) { 
    if(!cJSON_IsNumber(photo_height))
    {
    goto end; //Numeric
    }
    }

    // send_invoice_request->need_name
    cJSON *need_name = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "need_name");
    if (cJSON_IsNull(need_name)) {
        need_name = NULL;
    }
    if (need_name) { 
    if(!cJSON_IsBool(need_name))
    {
    goto end; //Bool
    }
    }

    // send_invoice_request->need_phone_number
    cJSON *need_phone_number = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "need_phone_number");
    if (cJSON_IsNull(need_phone_number)) {
        need_phone_number = NULL;
    }
    if (need_phone_number) { 
    if(!cJSON_IsBool(need_phone_number))
    {
    goto end; //Bool
    }
    }

    // send_invoice_request->need_email
    cJSON *need_email = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "need_email");
    if (cJSON_IsNull(need_email)) {
        need_email = NULL;
    }
    if (need_email) { 
    if(!cJSON_IsBool(need_email))
    {
    goto end; //Bool
    }
    }

    // send_invoice_request->need_shipping_address
    cJSON *need_shipping_address = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "need_shipping_address");
    if (cJSON_IsNull(need_shipping_address)) {
        need_shipping_address = NULL;
    }
    if (need_shipping_address) { 
    if(!cJSON_IsBool(need_shipping_address))
    {
    goto end; //Bool
    }
    }

    // send_invoice_request->send_phone_number_to_provider
    cJSON *send_phone_number_to_provider = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "send_phone_number_to_provider");
    if (cJSON_IsNull(send_phone_number_to_provider)) {
        send_phone_number_to_provider = NULL;
    }
    if (send_phone_number_to_provider) { 
    if(!cJSON_IsBool(send_phone_number_to_provider))
    {
    goto end; //Bool
    }
    }

    // send_invoice_request->send_email_to_provider
    cJSON *send_email_to_provider = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "send_email_to_provider");
    if (cJSON_IsNull(send_email_to_provider)) {
        send_email_to_provider = NULL;
    }
    if (send_email_to_provider) { 
    if(!cJSON_IsBool(send_email_to_provider))
    {
    goto end; //Bool
    }
    }

    // send_invoice_request->is_flexible
    cJSON *is_flexible = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "is_flexible");
    if (cJSON_IsNull(is_flexible)) {
        is_flexible = NULL;
    }
    if (is_flexible) { 
    if(!cJSON_IsBool(is_flexible))
    {
    goto end; //Bool
    }
    }

    // send_invoice_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // send_invoice_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }

    // send_invoice_request->allow_paid_broadcast
    cJSON *allow_paid_broadcast = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "allow_paid_broadcast");
    if (cJSON_IsNull(allow_paid_broadcast)) {
        allow_paid_broadcast = NULL;
    }
    if (allow_paid_broadcast) { 
    if(!cJSON_IsBool(allow_paid_broadcast))
    {
    goto end; //Bool
    }
    }

    // send_invoice_request->message_effect_id
    cJSON *message_effect_id = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "message_effect_id");
    if (cJSON_IsNull(message_effect_id)) {
        message_effect_id = NULL;
    }
    if (message_effect_id) { 
    if(!cJSON_IsString(message_effect_id) && !cJSON_IsNull(message_effect_id))
    {
    goto end; //String
    }
    }

    // send_invoice_request->reply_parameters
    cJSON *reply_parameters = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "reply_parameters");
    if (cJSON_IsNull(reply_parameters)) {
        reply_parameters = NULL;
    }
    if (reply_parameters) { 
    reply_parameters_local_nonprim = reply_parameters_parseFromJSON(reply_parameters); //nonprimitive
    }

    // send_invoice_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(send_invoice_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    send_invoice_request_local_var = send_invoice_request_create_internal (
        chat_id_local_nonprim,
        strdup(title->valuestring),
        strdup(description->valuestring),
        strdup(payload->valuestring),
        strdup(currency->valuestring),
        pricesList,
        message_thread_id ? message_thread_id->valuedouble : 0,
        provider_token && !cJSON_IsNull(provider_token) ? strdup(provider_token->valuestring) : NULL,
        max_tip_amount ? max_tip_amount->valuedouble : 0,
        suggested_tip_amounts ? suggested_tip_amountsList : NULL,
        start_parameter && !cJSON_IsNull(start_parameter) ? strdup(start_parameter->valuestring) : NULL,
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
        is_flexible ? is_flexible->valueint : 0,
        disable_notification ? disable_notification->valueint : 0,
        protect_content ? protect_content->valueint : 0,
        allow_paid_broadcast ? allow_paid_broadcast->valueint : 0,
        message_effect_id && !cJSON_IsNull(message_effect_id) ? strdup(message_effect_id->valuestring) : NULL,
        reply_parameters ? reply_parameters_local_nonprim : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return send_invoice_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (pricesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, pricesList) {
            labeled_price_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(pricesList);
        pricesList = NULL;
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
    if (reply_parameters_local_nonprim) {
        reply_parameters_free(reply_parameters_local_nonprim);
        reply_parameters_local_nonprim = NULL;
    }
    if (reply_markup_local_nonprim) {
        inline_keyboard_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    return NULL;

}
