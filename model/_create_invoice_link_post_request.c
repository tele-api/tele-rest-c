#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_create_invoice_link_post_request.h"



static _create_invoice_link_post_request_t *_create_invoice_link_post_request_create_internal(
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
    ) {
    _create_invoice_link_post_request_t *_create_invoice_link_post_request_local_var = malloc(sizeof(_create_invoice_link_post_request_t));
    if (!_create_invoice_link_post_request_local_var) {
        return NULL;
    }
    _create_invoice_link_post_request_local_var->title = title;
    _create_invoice_link_post_request_local_var->description = description;
    _create_invoice_link_post_request_local_var->payload = payload;
    _create_invoice_link_post_request_local_var->currency = currency;
    _create_invoice_link_post_request_local_var->prices = prices;
    _create_invoice_link_post_request_local_var->business_connection_id = business_connection_id;
    _create_invoice_link_post_request_local_var->provider_token = provider_token;
    _create_invoice_link_post_request_local_var->subscription_period = subscription_period;
    _create_invoice_link_post_request_local_var->max_tip_amount = max_tip_amount;
    _create_invoice_link_post_request_local_var->suggested_tip_amounts = suggested_tip_amounts;
    _create_invoice_link_post_request_local_var->provider_data = provider_data;
    _create_invoice_link_post_request_local_var->photo_url = photo_url;
    _create_invoice_link_post_request_local_var->photo_size = photo_size;
    _create_invoice_link_post_request_local_var->photo_width = photo_width;
    _create_invoice_link_post_request_local_var->photo_height = photo_height;
    _create_invoice_link_post_request_local_var->need_name = need_name;
    _create_invoice_link_post_request_local_var->need_phone_number = need_phone_number;
    _create_invoice_link_post_request_local_var->need_email = need_email;
    _create_invoice_link_post_request_local_var->need_shipping_address = need_shipping_address;
    _create_invoice_link_post_request_local_var->send_phone_number_to_provider = send_phone_number_to_provider;
    _create_invoice_link_post_request_local_var->send_email_to_provider = send_email_to_provider;
    _create_invoice_link_post_request_local_var->is_flexible = is_flexible;

    _create_invoice_link_post_request_local_var->_library_owned = 1;
    return _create_invoice_link_post_request_local_var;
}

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
    ) {
    return _create_invoice_link_post_request_create_internal (
        title,
        description,
        payload,
        currency,
        prices,
        business_connection_id,
        provider_token,
        subscription_period,
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

void _create_invoice_link_post_request_free(_create_invoice_link_post_request_t *_create_invoice_link_post_request) {
    if(NULL == _create_invoice_link_post_request){
        return ;
    }
    if(_create_invoice_link_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_create_invoice_link_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_create_invoice_link_post_request->title) {
        free(_create_invoice_link_post_request->title);
        _create_invoice_link_post_request->title = NULL;
    }
    if (_create_invoice_link_post_request->description) {
        free(_create_invoice_link_post_request->description);
        _create_invoice_link_post_request->description = NULL;
    }
    if (_create_invoice_link_post_request->payload) {
        free(_create_invoice_link_post_request->payload);
        _create_invoice_link_post_request->payload = NULL;
    }
    if (_create_invoice_link_post_request->currency) {
        free(_create_invoice_link_post_request->currency);
        _create_invoice_link_post_request->currency = NULL;
    }
    if (_create_invoice_link_post_request->prices) {
        list_ForEach(listEntry, _create_invoice_link_post_request->prices) {
            labeled_price_free(listEntry->data);
        }
        list_freeList(_create_invoice_link_post_request->prices);
        _create_invoice_link_post_request->prices = NULL;
    }
    if (_create_invoice_link_post_request->business_connection_id) {
        free(_create_invoice_link_post_request->business_connection_id);
        _create_invoice_link_post_request->business_connection_id = NULL;
    }
    if (_create_invoice_link_post_request->provider_token) {
        free(_create_invoice_link_post_request->provider_token);
        _create_invoice_link_post_request->provider_token = NULL;
    }
    if (_create_invoice_link_post_request->suggested_tip_amounts) {
        list_ForEach(listEntry, _create_invoice_link_post_request->suggested_tip_amounts) {
            free(listEntry->data);
        }
        list_freeList(_create_invoice_link_post_request->suggested_tip_amounts);
        _create_invoice_link_post_request->suggested_tip_amounts = NULL;
    }
    if (_create_invoice_link_post_request->provider_data) {
        free(_create_invoice_link_post_request->provider_data);
        _create_invoice_link_post_request->provider_data = NULL;
    }
    if (_create_invoice_link_post_request->photo_url) {
        free(_create_invoice_link_post_request->photo_url);
        _create_invoice_link_post_request->photo_url = NULL;
    }
    free(_create_invoice_link_post_request);
}

cJSON *_create_invoice_link_post_request_convertToJSON(_create_invoice_link_post_request_t *_create_invoice_link_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _create_invoice_link_post_request->title
    if (!_create_invoice_link_post_request->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", _create_invoice_link_post_request->title) == NULL) {
    goto fail; //String
    }


    // _create_invoice_link_post_request->description
    if (!_create_invoice_link_post_request->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", _create_invoice_link_post_request->description) == NULL) {
    goto fail; //String
    }


    // _create_invoice_link_post_request->payload
    if (!_create_invoice_link_post_request->payload) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "payload", _create_invoice_link_post_request->payload) == NULL) {
    goto fail; //String
    }


    // _create_invoice_link_post_request->currency
    if (!_create_invoice_link_post_request->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", _create_invoice_link_post_request->currency) == NULL) {
    goto fail; //String
    }


    // _create_invoice_link_post_request->prices
    if (!_create_invoice_link_post_request->prices) {
        goto fail;
    }
    cJSON *prices = cJSON_AddArrayToObject(item, "prices");
    if(prices == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *pricesListEntry;
    if (_create_invoice_link_post_request->prices) {
    list_ForEach(pricesListEntry, _create_invoice_link_post_request->prices) {
    cJSON *itemLocal = labeled_price_convertToJSON(pricesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(prices, itemLocal);
    }
    }


    // _create_invoice_link_post_request->business_connection_id
    if(_create_invoice_link_post_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", _create_invoice_link_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // _create_invoice_link_post_request->provider_token
    if(_create_invoice_link_post_request->provider_token) {
    if(cJSON_AddStringToObject(item, "provider_token", _create_invoice_link_post_request->provider_token) == NULL) {
    goto fail; //String
    }
    }


    // _create_invoice_link_post_request->subscription_period
    if(_create_invoice_link_post_request->subscription_period) {
    if(cJSON_AddNumberToObject(item, "subscription_period", _create_invoice_link_post_request->subscription_period) == NULL) {
    goto fail; //Numeric
    }
    }


    // _create_invoice_link_post_request->max_tip_amount
    if(_create_invoice_link_post_request->max_tip_amount) {
    if(cJSON_AddNumberToObject(item, "max_tip_amount", _create_invoice_link_post_request->max_tip_amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // _create_invoice_link_post_request->suggested_tip_amounts
    if(_create_invoice_link_post_request->suggested_tip_amounts) {
    cJSON *suggested_tip_amounts = cJSON_AddArrayToObject(item, "suggested_tip_amounts");
    if(suggested_tip_amounts == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *suggested_tip_amountsListEntry;
    list_ForEach(suggested_tip_amountsListEntry, _create_invoice_link_post_request->suggested_tip_amounts) {
    if(cJSON_AddNumberToObject(suggested_tip_amounts, "", *(double *)suggested_tip_amountsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // _create_invoice_link_post_request->provider_data
    if(_create_invoice_link_post_request->provider_data) {
    if(cJSON_AddStringToObject(item, "provider_data", _create_invoice_link_post_request->provider_data) == NULL) {
    goto fail; //String
    }
    }


    // _create_invoice_link_post_request->photo_url
    if(_create_invoice_link_post_request->photo_url) {
    if(cJSON_AddStringToObject(item, "photo_url", _create_invoice_link_post_request->photo_url) == NULL) {
    goto fail; //String
    }
    }


    // _create_invoice_link_post_request->photo_size
    if(_create_invoice_link_post_request->photo_size) {
    if(cJSON_AddNumberToObject(item, "photo_size", _create_invoice_link_post_request->photo_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // _create_invoice_link_post_request->photo_width
    if(_create_invoice_link_post_request->photo_width) {
    if(cJSON_AddNumberToObject(item, "photo_width", _create_invoice_link_post_request->photo_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // _create_invoice_link_post_request->photo_height
    if(_create_invoice_link_post_request->photo_height) {
    if(cJSON_AddNumberToObject(item, "photo_height", _create_invoice_link_post_request->photo_height) == NULL) {
    goto fail; //Numeric
    }
    }


    // _create_invoice_link_post_request->need_name
    if(_create_invoice_link_post_request->need_name) {
    if(cJSON_AddBoolToObject(item, "need_name", _create_invoice_link_post_request->need_name) == NULL) {
    goto fail; //Bool
    }
    }


    // _create_invoice_link_post_request->need_phone_number
    if(_create_invoice_link_post_request->need_phone_number) {
    if(cJSON_AddBoolToObject(item, "need_phone_number", _create_invoice_link_post_request->need_phone_number) == NULL) {
    goto fail; //Bool
    }
    }


    // _create_invoice_link_post_request->need_email
    if(_create_invoice_link_post_request->need_email) {
    if(cJSON_AddBoolToObject(item, "need_email", _create_invoice_link_post_request->need_email) == NULL) {
    goto fail; //Bool
    }
    }


    // _create_invoice_link_post_request->need_shipping_address
    if(_create_invoice_link_post_request->need_shipping_address) {
    if(cJSON_AddBoolToObject(item, "need_shipping_address", _create_invoice_link_post_request->need_shipping_address) == NULL) {
    goto fail; //Bool
    }
    }


    // _create_invoice_link_post_request->send_phone_number_to_provider
    if(_create_invoice_link_post_request->send_phone_number_to_provider) {
    if(cJSON_AddBoolToObject(item, "send_phone_number_to_provider", _create_invoice_link_post_request->send_phone_number_to_provider) == NULL) {
    goto fail; //Bool
    }
    }


    // _create_invoice_link_post_request->send_email_to_provider
    if(_create_invoice_link_post_request->send_email_to_provider) {
    if(cJSON_AddBoolToObject(item, "send_email_to_provider", _create_invoice_link_post_request->send_email_to_provider) == NULL) {
    goto fail; //Bool
    }
    }


    // _create_invoice_link_post_request->is_flexible
    if(_create_invoice_link_post_request->is_flexible) {
    if(cJSON_AddBoolToObject(item, "is_flexible", _create_invoice_link_post_request->is_flexible) == NULL) {
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

_create_invoice_link_post_request_t *_create_invoice_link_post_request_parseFromJSON(cJSON *_create_invoice_link_post_requestJSON){

    _create_invoice_link_post_request_t *_create_invoice_link_post_request_local_var = NULL;

    // define the local list for _create_invoice_link_post_request->prices
    list_t *pricesList = NULL;

    // define the local list for _create_invoice_link_post_request->suggested_tip_amounts
    list_t *suggested_tip_amountsList = NULL;

    // _create_invoice_link_post_request->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "title");
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

    // _create_invoice_link_post_request->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "description");
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

    // _create_invoice_link_post_request->payload
    cJSON *payload = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "payload");
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

    // _create_invoice_link_post_request->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "currency");
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

    // _create_invoice_link_post_request->prices
    cJSON *prices = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "prices");
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

    // _create_invoice_link_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // _create_invoice_link_post_request->provider_token
    cJSON *provider_token = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "provider_token");
    if (cJSON_IsNull(provider_token)) {
        provider_token = NULL;
    }
    if (provider_token) { 
    if(!cJSON_IsString(provider_token) && !cJSON_IsNull(provider_token))
    {
    goto end; //String
    }
    }

    // _create_invoice_link_post_request->subscription_period
    cJSON *subscription_period = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "subscription_period");
    if (cJSON_IsNull(subscription_period)) {
        subscription_period = NULL;
    }
    if (subscription_period) { 
    if(!cJSON_IsNumber(subscription_period))
    {
    goto end; //Numeric
    }
    }

    // _create_invoice_link_post_request->max_tip_amount
    cJSON *max_tip_amount = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "max_tip_amount");
    if (cJSON_IsNull(max_tip_amount)) {
        max_tip_amount = NULL;
    }
    if (max_tip_amount) { 
    if(!cJSON_IsNumber(max_tip_amount))
    {
    goto end; //Numeric
    }
    }

    // _create_invoice_link_post_request->suggested_tip_amounts
    cJSON *suggested_tip_amounts = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "suggested_tip_amounts");
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

    // _create_invoice_link_post_request->provider_data
    cJSON *provider_data = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "provider_data");
    if (cJSON_IsNull(provider_data)) {
        provider_data = NULL;
    }
    if (provider_data) { 
    if(!cJSON_IsString(provider_data) && !cJSON_IsNull(provider_data))
    {
    goto end; //String
    }
    }

    // _create_invoice_link_post_request->photo_url
    cJSON *photo_url = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "photo_url");
    if (cJSON_IsNull(photo_url)) {
        photo_url = NULL;
    }
    if (photo_url) { 
    if(!cJSON_IsString(photo_url) && !cJSON_IsNull(photo_url))
    {
    goto end; //String
    }
    }

    // _create_invoice_link_post_request->photo_size
    cJSON *photo_size = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "photo_size");
    if (cJSON_IsNull(photo_size)) {
        photo_size = NULL;
    }
    if (photo_size) { 
    if(!cJSON_IsNumber(photo_size))
    {
    goto end; //Numeric
    }
    }

    // _create_invoice_link_post_request->photo_width
    cJSON *photo_width = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "photo_width");
    if (cJSON_IsNull(photo_width)) {
        photo_width = NULL;
    }
    if (photo_width) { 
    if(!cJSON_IsNumber(photo_width))
    {
    goto end; //Numeric
    }
    }

    // _create_invoice_link_post_request->photo_height
    cJSON *photo_height = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "photo_height");
    if (cJSON_IsNull(photo_height)) {
        photo_height = NULL;
    }
    if (photo_height) { 
    if(!cJSON_IsNumber(photo_height))
    {
    goto end; //Numeric
    }
    }

    // _create_invoice_link_post_request->need_name
    cJSON *need_name = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "need_name");
    if (cJSON_IsNull(need_name)) {
        need_name = NULL;
    }
    if (need_name) { 
    if(!cJSON_IsBool(need_name))
    {
    goto end; //Bool
    }
    }

    // _create_invoice_link_post_request->need_phone_number
    cJSON *need_phone_number = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "need_phone_number");
    if (cJSON_IsNull(need_phone_number)) {
        need_phone_number = NULL;
    }
    if (need_phone_number) { 
    if(!cJSON_IsBool(need_phone_number))
    {
    goto end; //Bool
    }
    }

    // _create_invoice_link_post_request->need_email
    cJSON *need_email = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "need_email");
    if (cJSON_IsNull(need_email)) {
        need_email = NULL;
    }
    if (need_email) { 
    if(!cJSON_IsBool(need_email))
    {
    goto end; //Bool
    }
    }

    // _create_invoice_link_post_request->need_shipping_address
    cJSON *need_shipping_address = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "need_shipping_address");
    if (cJSON_IsNull(need_shipping_address)) {
        need_shipping_address = NULL;
    }
    if (need_shipping_address) { 
    if(!cJSON_IsBool(need_shipping_address))
    {
    goto end; //Bool
    }
    }

    // _create_invoice_link_post_request->send_phone_number_to_provider
    cJSON *send_phone_number_to_provider = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "send_phone_number_to_provider");
    if (cJSON_IsNull(send_phone_number_to_provider)) {
        send_phone_number_to_provider = NULL;
    }
    if (send_phone_number_to_provider) { 
    if(!cJSON_IsBool(send_phone_number_to_provider))
    {
    goto end; //Bool
    }
    }

    // _create_invoice_link_post_request->send_email_to_provider
    cJSON *send_email_to_provider = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "send_email_to_provider");
    if (cJSON_IsNull(send_email_to_provider)) {
        send_email_to_provider = NULL;
    }
    if (send_email_to_provider) { 
    if(!cJSON_IsBool(send_email_to_provider))
    {
    goto end; //Bool
    }
    }

    // _create_invoice_link_post_request->is_flexible
    cJSON *is_flexible = cJSON_GetObjectItemCaseSensitive(_create_invoice_link_post_requestJSON, "is_flexible");
    if (cJSON_IsNull(is_flexible)) {
        is_flexible = NULL;
    }
    if (is_flexible) { 
    if(!cJSON_IsBool(is_flexible))
    {
    goto end; //Bool
    }
    }


    _create_invoice_link_post_request_local_var = _create_invoice_link_post_request_create_internal (
        strdup(title->valuestring),
        strdup(description->valuestring),
        strdup(payload->valuestring),
        strdup(currency->valuestring),
        pricesList,
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        provider_token && !cJSON_IsNull(provider_token) ? strdup(provider_token->valuestring) : NULL,
        subscription_period ? subscription_period->valuedouble : 0,
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

    return _create_invoice_link_post_request_local_var;
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
