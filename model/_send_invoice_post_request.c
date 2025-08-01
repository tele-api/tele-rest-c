#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_send_invoice_post_request.h"



static _send_invoice_post_request_t *_send_invoice_post_request_create_internal(
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
    ) {
    _send_invoice_post_request_t *_send_invoice_post_request_local_var = malloc(sizeof(_send_invoice_post_request_t));
    if (!_send_invoice_post_request_local_var) {
        return NULL;
    }
    _send_invoice_post_request_local_var->chat_id = chat_id;
    _send_invoice_post_request_local_var->title = title;
    _send_invoice_post_request_local_var->description = description;
    _send_invoice_post_request_local_var->payload = payload;
    _send_invoice_post_request_local_var->currency = currency;
    _send_invoice_post_request_local_var->prices = prices;
    _send_invoice_post_request_local_var->message_thread_id = message_thread_id;
    _send_invoice_post_request_local_var->provider_token = provider_token;
    _send_invoice_post_request_local_var->max_tip_amount = max_tip_amount;
    _send_invoice_post_request_local_var->suggested_tip_amounts = suggested_tip_amounts;
    _send_invoice_post_request_local_var->start_parameter = start_parameter;
    _send_invoice_post_request_local_var->provider_data = provider_data;
    _send_invoice_post_request_local_var->photo_url = photo_url;
    _send_invoice_post_request_local_var->photo_size = photo_size;
    _send_invoice_post_request_local_var->photo_width = photo_width;
    _send_invoice_post_request_local_var->photo_height = photo_height;
    _send_invoice_post_request_local_var->need_name = need_name;
    _send_invoice_post_request_local_var->need_phone_number = need_phone_number;
    _send_invoice_post_request_local_var->need_email = need_email;
    _send_invoice_post_request_local_var->need_shipping_address = need_shipping_address;
    _send_invoice_post_request_local_var->send_phone_number_to_provider = send_phone_number_to_provider;
    _send_invoice_post_request_local_var->send_email_to_provider = send_email_to_provider;
    _send_invoice_post_request_local_var->is_flexible = is_flexible;
    _send_invoice_post_request_local_var->disable_notification = disable_notification;
    _send_invoice_post_request_local_var->protect_content = protect_content;
    _send_invoice_post_request_local_var->allow_paid_broadcast = allow_paid_broadcast;
    _send_invoice_post_request_local_var->message_effect_id = message_effect_id;
    _send_invoice_post_request_local_var->reply_parameters = reply_parameters;
    _send_invoice_post_request_local_var->reply_markup = reply_markup;

    _send_invoice_post_request_local_var->_library_owned = 1;
    return _send_invoice_post_request_local_var;
}

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
    ) {
    return _send_invoice_post_request_create_internal (
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

void _send_invoice_post_request_free(_send_invoice_post_request_t *_send_invoice_post_request) {
    if(NULL == _send_invoice_post_request){
        return ;
    }
    if(_send_invoice_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_send_invoice_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_send_invoice_post_request->chat_id) {
        _send_message_post_request_chat_id_free(_send_invoice_post_request->chat_id);
        _send_invoice_post_request->chat_id = NULL;
    }
    if (_send_invoice_post_request->title) {
        free(_send_invoice_post_request->title);
        _send_invoice_post_request->title = NULL;
    }
    if (_send_invoice_post_request->description) {
        free(_send_invoice_post_request->description);
        _send_invoice_post_request->description = NULL;
    }
    if (_send_invoice_post_request->payload) {
        free(_send_invoice_post_request->payload);
        _send_invoice_post_request->payload = NULL;
    }
    if (_send_invoice_post_request->currency) {
        free(_send_invoice_post_request->currency);
        _send_invoice_post_request->currency = NULL;
    }
    if (_send_invoice_post_request->prices) {
        list_ForEach(listEntry, _send_invoice_post_request->prices) {
            labeled_price_free(listEntry->data);
        }
        list_freeList(_send_invoice_post_request->prices);
        _send_invoice_post_request->prices = NULL;
    }
    if (_send_invoice_post_request->provider_token) {
        free(_send_invoice_post_request->provider_token);
        _send_invoice_post_request->provider_token = NULL;
    }
    if (_send_invoice_post_request->suggested_tip_amounts) {
        list_ForEach(listEntry, _send_invoice_post_request->suggested_tip_amounts) {
            free(listEntry->data);
        }
        list_freeList(_send_invoice_post_request->suggested_tip_amounts);
        _send_invoice_post_request->suggested_tip_amounts = NULL;
    }
    if (_send_invoice_post_request->start_parameter) {
        free(_send_invoice_post_request->start_parameter);
        _send_invoice_post_request->start_parameter = NULL;
    }
    if (_send_invoice_post_request->provider_data) {
        free(_send_invoice_post_request->provider_data);
        _send_invoice_post_request->provider_data = NULL;
    }
    if (_send_invoice_post_request->photo_url) {
        free(_send_invoice_post_request->photo_url);
        _send_invoice_post_request->photo_url = NULL;
    }
    if (_send_invoice_post_request->message_effect_id) {
        free(_send_invoice_post_request->message_effect_id);
        _send_invoice_post_request->message_effect_id = NULL;
    }
    if (_send_invoice_post_request->reply_parameters) {
        reply_parameters_free(_send_invoice_post_request->reply_parameters);
        _send_invoice_post_request->reply_parameters = NULL;
    }
    if (_send_invoice_post_request->reply_markup) {
        inline_keyboard_markup_free(_send_invoice_post_request->reply_markup);
        _send_invoice_post_request->reply_markup = NULL;
    }
    free(_send_invoice_post_request);
}

cJSON *_send_invoice_post_request_convertToJSON(_send_invoice_post_request_t *_send_invoice_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _send_invoice_post_request->chat_id
    if (!_send_invoice_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _send_message_post_request_chat_id_convertToJSON(_send_invoice_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _send_invoice_post_request->title
    if (!_send_invoice_post_request->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", _send_invoice_post_request->title) == NULL) {
    goto fail; //String
    }


    // _send_invoice_post_request->description
    if (!_send_invoice_post_request->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", _send_invoice_post_request->description) == NULL) {
    goto fail; //String
    }


    // _send_invoice_post_request->payload
    if (!_send_invoice_post_request->payload) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "payload", _send_invoice_post_request->payload) == NULL) {
    goto fail; //String
    }


    // _send_invoice_post_request->currency
    if (!_send_invoice_post_request->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", _send_invoice_post_request->currency) == NULL) {
    goto fail; //String
    }


    // _send_invoice_post_request->prices
    if (!_send_invoice_post_request->prices) {
        goto fail;
    }
    cJSON *prices = cJSON_AddArrayToObject(item, "prices");
    if(prices == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *pricesListEntry;
    if (_send_invoice_post_request->prices) {
    list_ForEach(pricesListEntry, _send_invoice_post_request->prices) {
    cJSON *itemLocal = labeled_price_convertToJSON(pricesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(prices, itemLocal);
    }
    }


    // _send_invoice_post_request->message_thread_id
    if(_send_invoice_post_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", _send_invoice_post_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_invoice_post_request->provider_token
    if(_send_invoice_post_request->provider_token) {
    if(cJSON_AddStringToObject(item, "provider_token", _send_invoice_post_request->provider_token) == NULL) {
    goto fail; //String
    }
    }


    // _send_invoice_post_request->max_tip_amount
    if(_send_invoice_post_request->max_tip_amount) {
    if(cJSON_AddNumberToObject(item, "max_tip_amount", _send_invoice_post_request->max_tip_amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_invoice_post_request->suggested_tip_amounts
    if(_send_invoice_post_request->suggested_tip_amounts) {
    cJSON *suggested_tip_amounts = cJSON_AddArrayToObject(item, "suggested_tip_amounts");
    if(suggested_tip_amounts == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *suggested_tip_amountsListEntry;
    list_ForEach(suggested_tip_amountsListEntry, _send_invoice_post_request->suggested_tip_amounts) {
    if(cJSON_AddNumberToObject(suggested_tip_amounts, "", *(double *)suggested_tip_amountsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // _send_invoice_post_request->start_parameter
    if(_send_invoice_post_request->start_parameter) {
    if(cJSON_AddStringToObject(item, "start_parameter", _send_invoice_post_request->start_parameter) == NULL) {
    goto fail; //String
    }
    }


    // _send_invoice_post_request->provider_data
    if(_send_invoice_post_request->provider_data) {
    if(cJSON_AddStringToObject(item, "provider_data", _send_invoice_post_request->provider_data) == NULL) {
    goto fail; //String
    }
    }


    // _send_invoice_post_request->photo_url
    if(_send_invoice_post_request->photo_url) {
    if(cJSON_AddStringToObject(item, "photo_url", _send_invoice_post_request->photo_url) == NULL) {
    goto fail; //String
    }
    }


    // _send_invoice_post_request->photo_size
    if(_send_invoice_post_request->photo_size) {
    if(cJSON_AddNumberToObject(item, "photo_size", _send_invoice_post_request->photo_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_invoice_post_request->photo_width
    if(_send_invoice_post_request->photo_width) {
    if(cJSON_AddNumberToObject(item, "photo_width", _send_invoice_post_request->photo_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_invoice_post_request->photo_height
    if(_send_invoice_post_request->photo_height) {
    if(cJSON_AddNumberToObject(item, "photo_height", _send_invoice_post_request->photo_height) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_invoice_post_request->need_name
    if(_send_invoice_post_request->need_name) {
    if(cJSON_AddBoolToObject(item, "need_name", _send_invoice_post_request->need_name) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_invoice_post_request->need_phone_number
    if(_send_invoice_post_request->need_phone_number) {
    if(cJSON_AddBoolToObject(item, "need_phone_number", _send_invoice_post_request->need_phone_number) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_invoice_post_request->need_email
    if(_send_invoice_post_request->need_email) {
    if(cJSON_AddBoolToObject(item, "need_email", _send_invoice_post_request->need_email) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_invoice_post_request->need_shipping_address
    if(_send_invoice_post_request->need_shipping_address) {
    if(cJSON_AddBoolToObject(item, "need_shipping_address", _send_invoice_post_request->need_shipping_address) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_invoice_post_request->send_phone_number_to_provider
    if(_send_invoice_post_request->send_phone_number_to_provider) {
    if(cJSON_AddBoolToObject(item, "send_phone_number_to_provider", _send_invoice_post_request->send_phone_number_to_provider) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_invoice_post_request->send_email_to_provider
    if(_send_invoice_post_request->send_email_to_provider) {
    if(cJSON_AddBoolToObject(item, "send_email_to_provider", _send_invoice_post_request->send_email_to_provider) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_invoice_post_request->is_flexible
    if(_send_invoice_post_request->is_flexible) {
    if(cJSON_AddBoolToObject(item, "is_flexible", _send_invoice_post_request->is_flexible) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_invoice_post_request->disable_notification
    if(_send_invoice_post_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", _send_invoice_post_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_invoice_post_request->protect_content
    if(_send_invoice_post_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", _send_invoice_post_request->protect_content) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_invoice_post_request->allow_paid_broadcast
    if(_send_invoice_post_request->allow_paid_broadcast) {
    if(cJSON_AddBoolToObject(item, "allow_paid_broadcast", _send_invoice_post_request->allow_paid_broadcast) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_invoice_post_request->message_effect_id
    if(_send_invoice_post_request->message_effect_id) {
    if(cJSON_AddStringToObject(item, "message_effect_id", _send_invoice_post_request->message_effect_id) == NULL) {
    goto fail; //String
    }
    }


    // _send_invoice_post_request->reply_parameters
    if(_send_invoice_post_request->reply_parameters) {
    cJSON *reply_parameters_local_JSON = reply_parameters_convertToJSON(_send_invoice_post_request->reply_parameters);
    if(reply_parameters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_parameters", reply_parameters_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _send_invoice_post_request->reply_markup
    if(_send_invoice_post_request->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(_send_invoice_post_request->reply_markup);
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

_send_invoice_post_request_t *_send_invoice_post_request_parseFromJSON(cJSON *_send_invoice_post_requestJSON){

    _send_invoice_post_request_t *_send_invoice_post_request_local_var = NULL;

    // define the local variable for _send_invoice_post_request->chat_id
    _send_message_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for _send_invoice_post_request->prices
    list_t *pricesList = NULL;

    // define the local list for _send_invoice_post_request->suggested_tip_amounts
    list_t *suggested_tip_amountsList = NULL;

    // define the local variable for _send_invoice_post_request->reply_parameters
    reply_parameters_t *reply_parameters_local_nonprim = NULL;

    // define the local variable for _send_invoice_post_request->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // _send_invoice_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _send_message_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _send_invoice_post_request->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "title");
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

    // _send_invoice_post_request->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "description");
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

    // _send_invoice_post_request->payload
    cJSON *payload = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "payload");
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

    // _send_invoice_post_request->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "currency");
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

    // _send_invoice_post_request->prices
    cJSON *prices = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "prices");
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

    // _send_invoice_post_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // _send_invoice_post_request->provider_token
    cJSON *provider_token = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "provider_token");
    if (cJSON_IsNull(provider_token)) {
        provider_token = NULL;
    }
    if (provider_token) { 
    if(!cJSON_IsString(provider_token) && !cJSON_IsNull(provider_token))
    {
    goto end; //String
    }
    }

    // _send_invoice_post_request->max_tip_amount
    cJSON *max_tip_amount = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "max_tip_amount");
    if (cJSON_IsNull(max_tip_amount)) {
        max_tip_amount = NULL;
    }
    if (max_tip_amount) { 
    if(!cJSON_IsNumber(max_tip_amount))
    {
    goto end; //Numeric
    }
    }

    // _send_invoice_post_request->suggested_tip_amounts
    cJSON *suggested_tip_amounts = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "suggested_tip_amounts");
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

    // _send_invoice_post_request->start_parameter
    cJSON *start_parameter = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "start_parameter");
    if (cJSON_IsNull(start_parameter)) {
        start_parameter = NULL;
    }
    if (start_parameter) { 
    if(!cJSON_IsString(start_parameter) && !cJSON_IsNull(start_parameter))
    {
    goto end; //String
    }
    }

    // _send_invoice_post_request->provider_data
    cJSON *provider_data = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "provider_data");
    if (cJSON_IsNull(provider_data)) {
        provider_data = NULL;
    }
    if (provider_data) { 
    if(!cJSON_IsString(provider_data) && !cJSON_IsNull(provider_data))
    {
    goto end; //String
    }
    }

    // _send_invoice_post_request->photo_url
    cJSON *photo_url = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "photo_url");
    if (cJSON_IsNull(photo_url)) {
        photo_url = NULL;
    }
    if (photo_url) { 
    if(!cJSON_IsString(photo_url) && !cJSON_IsNull(photo_url))
    {
    goto end; //String
    }
    }

    // _send_invoice_post_request->photo_size
    cJSON *photo_size = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "photo_size");
    if (cJSON_IsNull(photo_size)) {
        photo_size = NULL;
    }
    if (photo_size) { 
    if(!cJSON_IsNumber(photo_size))
    {
    goto end; //Numeric
    }
    }

    // _send_invoice_post_request->photo_width
    cJSON *photo_width = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "photo_width");
    if (cJSON_IsNull(photo_width)) {
        photo_width = NULL;
    }
    if (photo_width) { 
    if(!cJSON_IsNumber(photo_width))
    {
    goto end; //Numeric
    }
    }

    // _send_invoice_post_request->photo_height
    cJSON *photo_height = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "photo_height");
    if (cJSON_IsNull(photo_height)) {
        photo_height = NULL;
    }
    if (photo_height) { 
    if(!cJSON_IsNumber(photo_height))
    {
    goto end; //Numeric
    }
    }

    // _send_invoice_post_request->need_name
    cJSON *need_name = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "need_name");
    if (cJSON_IsNull(need_name)) {
        need_name = NULL;
    }
    if (need_name) { 
    if(!cJSON_IsBool(need_name))
    {
    goto end; //Bool
    }
    }

    // _send_invoice_post_request->need_phone_number
    cJSON *need_phone_number = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "need_phone_number");
    if (cJSON_IsNull(need_phone_number)) {
        need_phone_number = NULL;
    }
    if (need_phone_number) { 
    if(!cJSON_IsBool(need_phone_number))
    {
    goto end; //Bool
    }
    }

    // _send_invoice_post_request->need_email
    cJSON *need_email = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "need_email");
    if (cJSON_IsNull(need_email)) {
        need_email = NULL;
    }
    if (need_email) { 
    if(!cJSON_IsBool(need_email))
    {
    goto end; //Bool
    }
    }

    // _send_invoice_post_request->need_shipping_address
    cJSON *need_shipping_address = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "need_shipping_address");
    if (cJSON_IsNull(need_shipping_address)) {
        need_shipping_address = NULL;
    }
    if (need_shipping_address) { 
    if(!cJSON_IsBool(need_shipping_address))
    {
    goto end; //Bool
    }
    }

    // _send_invoice_post_request->send_phone_number_to_provider
    cJSON *send_phone_number_to_provider = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "send_phone_number_to_provider");
    if (cJSON_IsNull(send_phone_number_to_provider)) {
        send_phone_number_to_provider = NULL;
    }
    if (send_phone_number_to_provider) { 
    if(!cJSON_IsBool(send_phone_number_to_provider))
    {
    goto end; //Bool
    }
    }

    // _send_invoice_post_request->send_email_to_provider
    cJSON *send_email_to_provider = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "send_email_to_provider");
    if (cJSON_IsNull(send_email_to_provider)) {
        send_email_to_provider = NULL;
    }
    if (send_email_to_provider) { 
    if(!cJSON_IsBool(send_email_to_provider))
    {
    goto end; //Bool
    }
    }

    // _send_invoice_post_request->is_flexible
    cJSON *is_flexible = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "is_flexible");
    if (cJSON_IsNull(is_flexible)) {
        is_flexible = NULL;
    }
    if (is_flexible) { 
    if(!cJSON_IsBool(is_flexible))
    {
    goto end; //Bool
    }
    }

    // _send_invoice_post_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // _send_invoice_post_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }

    // _send_invoice_post_request->allow_paid_broadcast
    cJSON *allow_paid_broadcast = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "allow_paid_broadcast");
    if (cJSON_IsNull(allow_paid_broadcast)) {
        allow_paid_broadcast = NULL;
    }
    if (allow_paid_broadcast) { 
    if(!cJSON_IsBool(allow_paid_broadcast))
    {
    goto end; //Bool
    }
    }

    // _send_invoice_post_request->message_effect_id
    cJSON *message_effect_id = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "message_effect_id");
    if (cJSON_IsNull(message_effect_id)) {
        message_effect_id = NULL;
    }
    if (message_effect_id) { 
    if(!cJSON_IsString(message_effect_id) && !cJSON_IsNull(message_effect_id))
    {
    goto end; //String
    }
    }

    // _send_invoice_post_request->reply_parameters
    cJSON *reply_parameters = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "reply_parameters");
    if (cJSON_IsNull(reply_parameters)) {
        reply_parameters = NULL;
    }
    if (reply_parameters) { 
    reply_parameters_local_nonprim = reply_parameters_parseFromJSON(reply_parameters); //nonprimitive
    }

    // _send_invoice_post_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(_send_invoice_post_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    _send_invoice_post_request_local_var = _send_invoice_post_request_create_internal (
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

    return _send_invoice_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _send_message_post_request_chat_id_free(chat_id_local_nonprim);
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
