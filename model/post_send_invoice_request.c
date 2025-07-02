#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_send_invoice_request.h"



static post_send_invoice_request_t *post_send_invoice_request_create_internal(
    post_send_message_request_chat_id_t *chat_id,
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
    post_send_invoice_request_t *post_send_invoice_request_local_var = malloc(sizeof(post_send_invoice_request_t));
    if (!post_send_invoice_request_local_var) {
        return NULL;
    }
    post_send_invoice_request_local_var->chat_id = chat_id;
    post_send_invoice_request_local_var->title = title;
    post_send_invoice_request_local_var->description = description;
    post_send_invoice_request_local_var->payload = payload;
    post_send_invoice_request_local_var->currency = currency;
    post_send_invoice_request_local_var->prices = prices;
    post_send_invoice_request_local_var->message_thread_id = message_thread_id;
    post_send_invoice_request_local_var->provider_token = provider_token;
    post_send_invoice_request_local_var->max_tip_amount = max_tip_amount;
    post_send_invoice_request_local_var->suggested_tip_amounts = suggested_tip_amounts;
    post_send_invoice_request_local_var->start_parameter = start_parameter;
    post_send_invoice_request_local_var->provider_data = provider_data;
    post_send_invoice_request_local_var->photo_url = photo_url;
    post_send_invoice_request_local_var->photo_size = photo_size;
    post_send_invoice_request_local_var->photo_width = photo_width;
    post_send_invoice_request_local_var->photo_height = photo_height;
    post_send_invoice_request_local_var->need_name = need_name;
    post_send_invoice_request_local_var->need_phone_number = need_phone_number;
    post_send_invoice_request_local_var->need_email = need_email;
    post_send_invoice_request_local_var->need_shipping_address = need_shipping_address;
    post_send_invoice_request_local_var->send_phone_number_to_provider = send_phone_number_to_provider;
    post_send_invoice_request_local_var->send_email_to_provider = send_email_to_provider;
    post_send_invoice_request_local_var->is_flexible = is_flexible;
    post_send_invoice_request_local_var->disable_notification = disable_notification;
    post_send_invoice_request_local_var->protect_content = protect_content;
    post_send_invoice_request_local_var->allow_paid_broadcast = allow_paid_broadcast;
    post_send_invoice_request_local_var->message_effect_id = message_effect_id;
    post_send_invoice_request_local_var->reply_parameters = reply_parameters;
    post_send_invoice_request_local_var->reply_markup = reply_markup;

    post_send_invoice_request_local_var->_library_owned = 1;
    return post_send_invoice_request_local_var;
}

__attribute__((deprecated)) post_send_invoice_request_t *post_send_invoice_request_create(
    post_send_message_request_chat_id_t *chat_id,
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
    return post_send_invoice_request_create_internal (
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

void post_send_invoice_request_free(post_send_invoice_request_t *post_send_invoice_request) {
    if(NULL == post_send_invoice_request){
        return ;
    }
    if(post_send_invoice_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_send_invoice_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_send_invoice_request->chat_id) {
        post_send_message_request_chat_id_free(post_send_invoice_request->chat_id);
        post_send_invoice_request->chat_id = NULL;
    }
    if (post_send_invoice_request->title) {
        free(post_send_invoice_request->title);
        post_send_invoice_request->title = NULL;
    }
    if (post_send_invoice_request->description) {
        free(post_send_invoice_request->description);
        post_send_invoice_request->description = NULL;
    }
    if (post_send_invoice_request->payload) {
        free(post_send_invoice_request->payload);
        post_send_invoice_request->payload = NULL;
    }
    if (post_send_invoice_request->currency) {
        free(post_send_invoice_request->currency);
        post_send_invoice_request->currency = NULL;
    }
    if (post_send_invoice_request->prices) {
        list_ForEach(listEntry, post_send_invoice_request->prices) {
            labeled_price_free(listEntry->data);
        }
        list_freeList(post_send_invoice_request->prices);
        post_send_invoice_request->prices = NULL;
    }
    if (post_send_invoice_request->provider_token) {
        free(post_send_invoice_request->provider_token);
        post_send_invoice_request->provider_token = NULL;
    }
    if (post_send_invoice_request->suggested_tip_amounts) {
        list_ForEach(listEntry, post_send_invoice_request->suggested_tip_amounts) {
            free(listEntry->data);
        }
        list_freeList(post_send_invoice_request->suggested_tip_amounts);
        post_send_invoice_request->suggested_tip_amounts = NULL;
    }
    if (post_send_invoice_request->start_parameter) {
        free(post_send_invoice_request->start_parameter);
        post_send_invoice_request->start_parameter = NULL;
    }
    if (post_send_invoice_request->provider_data) {
        free(post_send_invoice_request->provider_data);
        post_send_invoice_request->provider_data = NULL;
    }
    if (post_send_invoice_request->photo_url) {
        free(post_send_invoice_request->photo_url);
        post_send_invoice_request->photo_url = NULL;
    }
    if (post_send_invoice_request->message_effect_id) {
        free(post_send_invoice_request->message_effect_id);
        post_send_invoice_request->message_effect_id = NULL;
    }
    if (post_send_invoice_request->reply_parameters) {
        reply_parameters_free(post_send_invoice_request->reply_parameters);
        post_send_invoice_request->reply_parameters = NULL;
    }
    if (post_send_invoice_request->reply_markup) {
        inline_keyboard_markup_free(post_send_invoice_request->reply_markup);
        post_send_invoice_request->reply_markup = NULL;
    }
    free(post_send_invoice_request);
}

cJSON *post_send_invoice_request_convertToJSON(post_send_invoice_request_t *post_send_invoice_request) {
    cJSON *item = cJSON_CreateObject();

    // post_send_invoice_request->chat_id
    if (!post_send_invoice_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_send_message_request_chat_id_convertToJSON(post_send_invoice_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_send_invoice_request->title
    if (!post_send_invoice_request->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", post_send_invoice_request->title) == NULL) {
    goto fail; //String
    }


    // post_send_invoice_request->description
    if (!post_send_invoice_request->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", post_send_invoice_request->description) == NULL) {
    goto fail; //String
    }


    // post_send_invoice_request->payload
    if (!post_send_invoice_request->payload) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "payload", post_send_invoice_request->payload) == NULL) {
    goto fail; //String
    }


    // post_send_invoice_request->currency
    if (!post_send_invoice_request->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", post_send_invoice_request->currency) == NULL) {
    goto fail; //String
    }


    // post_send_invoice_request->prices
    if (!post_send_invoice_request->prices) {
        goto fail;
    }
    cJSON *prices = cJSON_AddArrayToObject(item, "prices");
    if(prices == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *pricesListEntry;
    if (post_send_invoice_request->prices) {
    list_ForEach(pricesListEntry, post_send_invoice_request->prices) {
    cJSON *itemLocal = labeled_price_convertToJSON(pricesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(prices, itemLocal);
    }
    }


    // post_send_invoice_request->message_thread_id
    if(post_send_invoice_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", post_send_invoice_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_send_invoice_request->provider_token
    if(post_send_invoice_request->provider_token) {
    if(cJSON_AddStringToObject(item, "provider_token", post_send_invoice_request->provider_token) == NULL) {
    goto fail; //String
    }
    }


    // post_send_invoice_request->max_tip_amount
    if(post_send_invoice_request->max_tip_amount) {
    if(cJSON_AddNumberToObject(item, "max_tip_amount", post_send_invoice_request->max_tip_amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_send_invoice_request->suggested_tip_amounts
    if(post_send_invoice_request->suggested_tip_amounts) {
    cJSON *suggested_tip_amounts = cJSON_AddArrayToObject(item, "suggested_tip_amounts");
    if(suggested_tip_amounts == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *suggested_tip_amountsListEntry;
    list_ForEach(suggested_tip_amountsListEntry, post_send_invoice_request->suggested_tip_amounts) {
    if(cJSON_AddNumberToObject(suggested_tip_amounts, "", *(double *)suggested_tip_amountsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // post_send_invoice_request->start_parameter
    if(post_send_invoice_request->start_parameter) {
    if(cJSON_AddStringToObject(item, "start_parameter", post_send_invoice_request->start_parameter) == NULL) {
    goto fail; //String
    }
    }


    // post_send_invoice_request->provider_data
    if(post_send_invoice_request->provider_data) {
    if(cJSON_AddStringToObject(item, "provider_data", post_send_invoice_request->provider_data) == NULL) {
    goto fail; //String
    }
    }


    // post_send_invoice_request->photo_url
    if(post_send_invoice_request->photo_url) {
    if(cJSON_AddStringToObject(item, "photo_url", post_send_invoice_request->photo_url) == NULL) {
    goto fail; //String
    }
    }


    // post_send_invoice_request->photo_size
    if(post_send_invoice_request->photo_size) {
    if(cJSON_AddNumberToObject(item, "photo_size", post_send_invoice_request->photo_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_send_invoice_request->photo_width
    if(post_send_invoice_request->photo_width) {
    if(cJSON_AddNumberToObject(item, "photo_width", post_send_invoice_request->photo_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_send_invoice_request->photo_height
    if(post_send_invoice_request->photo_height) {
    if(cJSON_AddNumberToObject(item, "photo_height", post_send_invoice_request->photo_height) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_send_invoice_request->need_name
    if(post_send_invoice_request->need_name) {
    if(cJSON_AddBoolToObject(item, "need_name", post_send_invoice_request->need_name) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_invoice_request->need_phone_number
    if(post_send_invoice_request->need_phone_number) {
    if(cJSON_AddBoolToObject(item, "need_phone_number", post_send_invoice_request->need_phone_number) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_invoice_request->need_email
    if(post_send_invoice_request->need_email) {
    if(cJSON_AddBoolToObject(item, "need_email", post_send_invoice_request->need_email) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_invoice_request->need_shipping_address
    if(post_send_invoice_request->need_shipping_address) {
    if(cJSON_AddBoolToObject(item, "need_shipping_address", post_send_invoice_request->need_shipping_address) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_invoice_request->send_phone_number_to_provider
    if(post_send_invoice_request->send_phone_number_to_provider) {
    if(cJSON_AddBoolToObject(item, "send_phone_number_to_provider", post_send_invoice_request->send_phone_number_to_provider) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_invoice_request->send_email_to_provider
    if(post_send_invoice_request->send_email_to_provider) {
    if(cJSON_AddBoolToObject(item, "send_email_to_provider", post_send_invoice_request->send_email_to_provider) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_invoice_request->is_flexible
    if(post_send_invoice_request->is_flexible) {
    if(cJSON_AddBoolToObject(item, "is_flexible", post_send_invoice_request->is_flexible) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_invoice_request->disable_notification
    if(post_send_invoice_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", post_send_invoice_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_invoice_request->protect_content
    if(post_send_invoice_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", post_send_invoice_request->protect_content) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_invoice_request->allow_paid_broadcast
    if(post_send_invoice_request->allow_paid_broadcast) {
    if(cJSON_AddBoolToObject(item, "allow_paid_broadcast", post_send_invoice_request->allow_paid_broadcast) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_invoice_request->message_effect_id
    if(post_send_invoice_request->message_effect_id) {
    if(cJSON_AddStringToObject(item, "message_effect_id", post_send_invoice_request->message_effect_id) == NULL) {
    goto fail; //String
    }
    }


    // post_send_invoice_request->reply_parameters
    if(post_send_invoice_request->reply_parameters) {
    cJSON *reply_parameters_local_JSON = reply_parameters_convertToJSON(post_send_invoice_request->reply_parameters);
    if(reply_parameters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_parameters", reply_parameters_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // post_send_invoice_request->reply_markup
    if(post_send_invoice_request->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(post_send_invoice_request->reply_markup);
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

post_send_invoice_request_t *post_send_invoice_request_parseFromJSON(cJSON *post_send_invoice_requestJSON){

    post_send_invoice_request_t *post_send_invoice_request_local_var = NULL;

    // define the local variable for post_send_invoice_request->chat_id
    post_send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for post_send_invoice_request->prices
    list_t *pricesList = NULL;

    // define the local list for post_send_invoice_request->suggested_tip_amounts
    list_t *suggested_tip_amountsList = NULL;

    // define the local variable for post_send_invoice_request->reply_parameters
    reply_parameters_t *reply_parameters_local_nonprim = NULL;

    // define the local variable for post_send_invoice_request->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // post_send_invoice_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_send_invoice_request->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "title");
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

    // post_send_invoice_request->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "description");
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

    // post_send_invoice_request->payload
    cJSON *payload = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "payload");
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

    // post_send_invoice_request->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "currency");
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

    // post_send_invoice_request->prices
    cJSON *prices = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "prices");
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

    // post_send_invoice_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // post_send_invoice_request->provider_token
    cJSON *provider_token = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "provider_token");
    if (cJSON_IsNull(provider_token)) {
        provider_token = NULL;
    }
    if (provider_token) { 
    if(!cJSON_IsString(provider_token) && !cJSON_IsNull(provider_token))
    {
    goto end; //String
    }
    }

    // post_send_invoice_request->max_tip_amount
    cJSON *max_tip_amount = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "max_tip_amount");
    if (cJSON_IsNull(max_tip_amount)) {
        max_tip_amount = NULL;
    }
    if (max_tip_amount) { 
    if(!cJSON_IsNumber(max_tip_amount))
    {
    goto end; //Numeric
    }
    }

    // post_send_invoice_request->suggested_tip_amounts
    cJSON *suggested_tip_amounts = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "suggested_tip_amounts");
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

    // post_send_invoice_request->start_parameter
    cJSON *start_parameter = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "start_parameter");
    if (cJSON_IsNull(start_parameter)) {
        start_parameter = NULL;
    }
    if (start_parameter) { 
    if(!cJSON_IsString(start_parameter) && !cJSON_IsNull(start_parameter))
    {
    goto end; //String
    }
    }

    // post_send_invoice_request->provider_data
    cJSON *provider_data = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "provider_data");
    if (cJSON_IsNull(provider_data)) {
        provider_data = NULL;
    }
    if (provider_data) { 
    if(!cJSON_IsString(provider_data) && !cJSON_IsNull(provider_data))
    {
    goto end; //String
    }
    }

    // post_send_invoice_request->photo_url
    cJSON *photo_url = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "photo_url");
    if (cJSON_IsNull(photo_url)) {
        photo_url = NULL;
    }
    if (photo_url) { 
    if(!cJSON_IsString(photo_url) && !cJSON_IsNull(photo_url))
    {
    goto end; //String
    }
    }

    // post_send_invoice_request->photo_size
    cJSON *photo_size = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "photo_size");
    if (cJSON_IsNull(photo_size)) {
        photo_size = NULL;
    }
    if (photo_size) { 
    if(!cJSON_IsNumber(photo_size))
    {
    goto end; //Numeric
    }
    }

    // post_send_invoice_request->photo_width
    cJSON *photo_width = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "photo_width");
    if (cJSON_IsNull(photo_width)) {
        photo_width = NULL;
    }
    if (photo_width) { 
    if(!cJSON_IsNumber(photo_width))
    {
    goto end; //Numeric
    }
    }

    // post_send_invoice_request->photo_height
    cJSON *photo_height = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "photo_height");
    if (cJSON_IsNull(photo_height)) {
        photo_height = NULL;
    }
    if (photo_height) { 
    if(!cJSON_IsNumber(photo_height))
    {
    goto end; //Numeric
    }
    }

    // post_send_invoice_request->need_name
    cJSON *need_name = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "need_name");
    if (cJSON_IsNull(need_name)) {
        need_name = NULL;
    }
    if (need_name) { 
    if(!cJSON_IsBool(need_name))
    {
    goto end; //Bool
    }
    }

    // post_send_invoice_request->need_phone_number
    cJSON *need_phone_number = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "need_phone_number");
    if (cJSON_IsNull(need_phone_number)) {
        need_phone_number = NULL;
    }
    if (need_phone_number) { 
    if(!cJSON_IsBool(need_phone_number))
    {
    goto end; //Bool
    }
    }

    // post_send_invoice_request->need_email
    cJSON *need_email = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "need_email");
    if (cJSON_IsNull(need_email)) {
        need_email = NULL;
    }
    if (need_email) { 
    if(!cJSON_IsBool(need_email))
    {
    goto end; //Bool
    }
    }

    // post_send_invoice_request->need_shipping_address
    cJSON *need_shipping_address = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "need_shipping_address");
    if (cJSON_IsNull(need_shipping_address)) {
        need_shipping_address = NULL;
    }
    if (need_shipping_address) { 
    if(!cJSON_IsBool(need_shipping_address))
    {
    goto end; //Bool
    }
    }

    // post_send_invoice_request->send_phone_number_to_provider
    cJSON *send_phone_number_to_provider = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "send_phone_number_to_provider");
    if (cJSON_IsNull(send_phone_number_to_provider)) {
        send_phone_number_to_provider = NULL;
    }
    if (send_phone_number_to_provider) { 
    if(!cJSON_IsBool(send_phone_number_to_provider))
    {
    goto end; //Bool
    }
    }

    // post_send_invoice_request->send_email_to_provider
    cJSON *send_email_to_provider = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "send_email_to_provider");
    if (cJSON_IsNull(send_email_to_provider)) {
        send_email_to_provider = NULL;
    }
    if (send_email_to_provider) { 
    if(!cJSON_IsBool(send_email_to_provider))
    {
    goto end; //Bool
    }
    }

    // post_send_invoice_request->is_flexible
    cJSON *is_flexible = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "is_flexible");
    if (cJSON_IsNull(is_flexible)) {
        is_flexible = NULL;
    }
    if (is_flexible) { 
    if(!cJSON_IsBool(is_flexible))
    {
    goto end; //Bool
    }
    }

    // post_send_invoice_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // post_send_invoice_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }

    // post_send_invoice_request->allow_paid_broadcast
    cJSON *allow_paid_broadcast = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "allow_paid_broadcast");
    if (cJSON_IsNull(allow_paid_broadcast)) {
        allow_paid_broadcast = NULL;
    }
    if (allow_paid_broadcast) { 
    if(!cJSON_IsBool(allow_paid_broadcast))
    {
    goto end; //Bool
    }
    }

    // post_send_invoice_request->message_effect_id
    cJSON *message_effect_id = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "message_effect_id");
    if (cJSON_IsNull(message_effect_id)) {
        message_effect_id = NULL;
    }
    if (message_effect_id) { 
    if(!cJSON_IsString(message_effect_id) && !cJSON_IsNull(message_effect_id))
    {
    goto end; //String
    }
    }

    // post_send_invoice_request->reply_parameters
    cJSON *reply_parameters = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "reply_parameters");
    if (cJSON_IsNull(reply_parameters)) {
        reply_parameters = NULL;
    }
    if (reply_parameters) { 
    reply_parameters_local_nonprim = reply_parameters_parseFromJSON(reply_parameters); //nonprimitive
    }

    // post_send_invoice_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(post_send_invoice_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    post_send_invoice_request_local_var = post_send_invoice_request_create_internal (
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

    return post_send_invoice_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_send_message_request_chat_id_free(chat_id_local_nonprim);
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
