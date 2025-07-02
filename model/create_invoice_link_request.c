#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_invoice_link_request.h"



static create_invoice_link_request_t *create_invoice_link_request_create_internal(
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
    create_invoice_link_request_t *create_invoice_link_request_local_var = malloc(sizeof(create_invoice_link_request_t));
    if (!create_invoice_link_request_local_var) {
        return NULL;
    }
    create_invoice_link_request_local_var->title = title;
    create_invoice_link_request_local_var->description = description;
    create_invoice_link_request_local_var->payload = payload;
    create_invoice_link_request_local_var->currency = currency;
    create_invoice_link_request_local_var->prices = prices;
    create_invoice_link_request_local_var->business_connection_id = business_connection_id;
    create_invoice_link_request_local_var->provider_token = provider_token;
    create_invoice_link_request_local_var->subscription_period = subscription_period;
    create_invoice_link_request_local_var->max_tip_amount = max_tip_amount;
    create_invoice_link_request_local_var->suggested_tip_amounts = suggested_tip_amounts;
    create_invoice_link_request_local_var->provider_data = provider_data;
    create_invoice_link_request_local_var->photo_url = photo_url;
    create_invoice_link_request_local_var->photo_size = photo_size;
    create_invoice_link_request_local_var->photo_width = photo_width;
    create_invoice_link_request_local_var->photo_height = photo_height;
    create_invoice_link_request_local_var->need_name = need_name;
    create_invoice_link_request_local_var->need_phone_number = need_phone_number;
    create_invoice_link_request_local_var->need_email = need_email;
    create_invoice_link_request_local_var->need_shipping_address = need_shipping_address;
    create_invoice_link_request_local_var->send_phone_number_to_provider = send_phone_number_to_provider;
    create_invoice_link_request_local_var->send_email_to_provider = send_email_to_provider;
    create_invoice_link_request_local_var->is_flexible = is_flexible;

    create_invoice_link_request_local_var->_library_owned = 1;
    return create_invoice_link_request_local_var;
}

__attribute__((deprecated)) create_invoice_link_request_t *create_invoice_link_request_create(
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
    return create_invoice_link_request_create_internal (
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

void create_invoice_link_request_free(create_invoice_link_request_t *create_invoice_link_request) {
    if(NULL == create_invoice_link_request){
        return ;
    }
    if(create_invoice_link_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_invoice_link_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_invoice_link_request->title) {
        free(create_invoice_link_request->title);
        create_invoice_link_request->title = NULL;
    }
    if (create_invoice_link_request->description) {
        free(create_invoice_link_request->description);
        create_invoice_link_request->description = NULL;
    }
    if (create_invoice_link_request->payload) {
        free(create_invoice_link_request->payload);
        create_invoice_link_request->payload = NULL;
    }
    if (create_invoice_link_request->currency) {
        free(create_invoice_link_request->currency);
        create_invoice_link_request->currency = NULL;
    }
    if (create_invoice_link_request->prices) {
        list_ForEach(listEntry, create_invoice_link_request->prices) {
            labeled_price_free(listEntry->data);
        }
        list_freeList(create_invoice_link_request->prices);
        create_invoice_link_request->prices = NULL;
    }
    if (create_invoice_link_request->business_connection_id) {
        free(create_invoice_link_request->business_connection_id);
        create_invoice_link_request->business_connection_id = NULL;
    }
    if (create_invoice_link_request->provider_token) {
        free(create_invoice_link_request->provider_token);
        create_invoice_link_request->provider_token = NULL;
    }
    if (create_invoice_link_request->suggested_tip_amounts) {
        list_ForEach(listEntry, create_invoice_link_request->suggested_tip_amounts) {
            free(listEntry->data);
        }
        list_freeList(create_invoice_link_request->suggested_tip_amounts);
        create_invoice_link_request->suggested_tip_amounts = NULL;
    }
    if (create_invoice_link_request->provider_data) {
        free(create_invoice_link_request->provider_data);
        create_invoice_link_request->provider_data = NULL;
    }
    if (create_invoice_link_request->photo_url) {
        free(create_invoice_link_request->photo_url);
        create_invoice_link_request->photo_url = NULL;
    }
    free(create_invoice_link_request);
}

cJSON *create_invoice_link_request_convertToJSON(create_invoice_link_request_t *create_invoice_link_request) {
    cJSON *item = cJSON_CreateObject();

    // create_invoice_link_request->title
    if (!create_invoice_link_request->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", create_invoice_link_request->title) == NULL) {
    goto fail; //String
    }


    // create_invoice_link_request->description
    if (!create_invoice_link_request->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", create_invoice_link_request->description) == NULL) {
    goto fail; //String
    }


    // create_invoice_link_request->payload
    if (!create_invoice_link_request->payload) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "payload", create_invoice_link_request->payload) == NULL) {
    goto fail; //String
    }


    // create_invoice_link_request->currency
    if (!create_invoice_link_request->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", create_invoice_link_request->currency) == NULL) {
    goto fail; //String
    }


    // create_invoice_link_request->prices
    if (!create_invoice_link_request->prices) {
        goto fail;
    }
    cJSON *prices = cJSON_AddArrayToObject(item, "prices");
    if(prices == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *pricesListEntry;
    if (create_invoice_link_request->prices) {
    list_ForEach(pricesListEntry, create_invoice_link_request->prices) {
    cJSON *itemLocal = labeled_price_convertToJSON(pricesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(prices, itemLocal);
    }
    }


    // create_invoice_link_request->business_connection_id
    if(create_invoice_link_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", create_invoice_link_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // create_invoice_link_request->provider_token
    if(create_invoice_link_request->provider_token) {
    if(cJSON_AddStringToObject(item, "provider_token", create_invoice_link_request->provider_token) == NULL) {
    goto fail; //String
    }
    }


    // create_invoice_link_request->subscription_period
    if(create_invoice_link_request->subscription_period) {
    if(cJSON_AddNumberToObject(item, "subscription_period", create_invoice_link_request->subscription_period) == NULL) {
    goto fail; //Numeric
    }
    }


    // create_invoice_link_request->max_tip_amount
    if(create_invoice_link_request->max_tip_amount) {
    if(cJSON_AddNumberToObject(item, "max_tip_amount", create_invoice_link_request->max_tip_amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // create_invoice_link_request->suggested_tip_amounts
    if(create_invoice_link_request->suggested_tip_amounts) {
    cJSON *suggested_tip_amounts = cJSON_AddArrayToObject(item, "suggested_tip_amounts");
    if(suggested_tip_amounts == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *suggested_tip_amountsListEntry;
    list_ForEach(suggested_tip_amountsListEntry, create_invoice_link_request->suggested_tip_amounts) {
    if(cJSON_AddNumberToObject(suggested_tip_amounts, "", *(double *)suggested_tip_amountsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // create_invoice_link_request->provider_data
    if(create_invoice_link_request->provider_data) {
    if(cJSON_AddStringToObject(item, "provider_data", create_invoice_link_request->provider_data) == NULL) {
    goto fail; //String
    }
    }


    // create_invoice_link_request->photo_url
    if(create_invoice_link_request->photo_url) {
    if(cJSON_AddStringToObject(item, "photo_url", create_invoice_link_request->photo_url) == NULL) {
    goto fail; //String
    }
    }


    // create_invoice_link_request->photo_size
    if(create_invoice_link_request->photo_size) {
    if(cJSON_AddNumberToObject(item, "photo_size", create_invoice_link_request->photo_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // create_invoice_link_request->photo_width
    if(create_invoice_link_request->photo_width) {
    if(cJSON_AddNumberToObject(item, "photo_width", create_invoice_link_request->photo_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // create_invoice_link_request->photo_height
    if(create_invoice_link_request->photo_height) {
    if(cJSON_AddNumberToObject(item, "photo_height", create_invoice_link_request->photo_height) == NULL) {
    goto fail; //Numeric
    }
    }


    // create_invoice_link_request->need_name
    if(create_invoice_link_request->need_name) {
    if(cJSON_AddBoolToObject(item, "need_name", create_invoice_link_request->need_name) == NULL) {
    goto fail; //Bool
    }
    }


    // create_invoice_link_request->need_phone_number
    if(create_invoice_link_request->need_phone_number) {
    if(cJSON_AddBoolToObject(item, "need_phone_number", create_invoice_link_request->need_phone_number) == NULL) {
    goto fail; //Bool
    }
    }


    // create_invoice_link_request->need_email
    if(create_invoice_link_request->need_email) {
    if(cJSON_AddBoolToObject(item, "need_email", create_invoice_link_request->need_email) == NULL) {
    goto fail; //Bool
    }
    }


    // create_invoice_link_request->need_shipping_address
    if(create_invoice_link_request->need_shipping_address) {
    if(cJSON_AddBoolToObject(item, "need_shipping_address", create_invoice_link_request->need_shipping_address) == NULL) {
    goto fail; //Bool
    }
    }


    // create_invoice_link_request->send_phone_number_to_provider
    if(create_invoice_link_request->send_phone_number_to_provider) {
    if(cJSON_AddBoolToObject(item, "send_phone_number_to_provider", create_invoice_link_request->send_phone_number_to_provider) == NULL) {
    goto fail; //Bool
    }
    }


    // create_invoice_link_request->send_email_to_provider
    if(create_invoice_link_request->send_email_to_provider) {
    if(cJSON_AddBoolToObject(item, "send_email_to_provider", create_invoice_link_request->send_email_to_provider) == NULL) {
    goto fail; //Bool
    }
    }


    // create_invoice_link_request->is_flexible
    if(create_invoice_link_request->is_flexible) {
    if(cJSON_AddBoolToObject(item, "is_flexible", create_invoice_link_request->is_flexible) == NULL) {
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

create_invoice_link_request_t *create_invoice_link_request_parseFromJSON(cJSON *create_invoice_link_requestJSON){

    create_invoice_link_request_t *create_invoice_link_request_local_var = NULL;

    // define the local list for create_invoice_link_request->prices
    list_t *pricesList = NULL;

    // define the local list for create_invoice_link_request->suggested_tip_amounts
    list_t *suggested_tip_amountsList = NULL;

    // create_invoice_link_request->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "title");
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

    // create_invoice_link_request->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "description");
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

    // create_invoice_link_request->payload
    cJSON *payload = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "payload");
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

    // create_invoice_link_request->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "currency");
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

    // create_invoice_link_request->prices
    cJSON *prices = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "prices");
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

    // create_invoice_link_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // create_invoice_link_request->provider_token
    cJSON *provider_token = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "provider_token");
    if (cJSON_IsNull(provider_token)) {
        provider_token = NULL;
    }
    if (provider_token) { 
    if(!cJSON_IsString(provider_token) && !cJSON_IsNull(provider_token))
    {
    goto end; //String
    }
    }

    // create_invoice_link_request->subscription_period
    cJSON *subscription_period = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "subscription_period");
    if (cJSON_IsNull(subscription_period)) {
        subscription_period = NULL;
    }
    if (subscription_period) { 
    if(!cJSON_IsNumber(subscription_period))
    {
    goto end; //Numeric
    }
    }

    // create_invoice_link_request->max_tip_amount
    cJSON *max_tip_amount = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "max_tip_amount");
    if (cJSON_IsNull(max_tip_amount)) {
        max_tip_amount = NULL;
    }
    if (max_tip_amount) { 
    if(!cJSON_IsNumber(max_tip_amount))
    {
    goto end; //Numeric
    }
    }

    // create_invoice_link_request->suggested_tip_amounts
    cJSON *suggested_tip_amounts = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "suggested_tip_amounts");
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

    // create_invoice_link_request->provider_data
    cJSON *provider_data = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "provider_data");
    if (cJSON_IsNull(provider_data)) {
        provider_data = NULL;
    }
    if (provider_data) { 
    if(!cJSON_IsString(provider_data) && !cJSON_IsNull(provider_data))
    {
    goto end; //String
    }
    }

    // create_invoice_link_request->photo_url
    cJSON *photo_url = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "photo_url");
    if (cJSON_IsNull(photo_url)) {
        photo_url = NULL;
    }
    if (photo_url) { 
    if(!cJSON_IsString(photo_url) && !cJSON_IsNull(photo_url))
    {
    goto end; //String
    }
    }

    // create_invoice_link_request->photo_size
    cJSON *photo_size = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "photo_size");
    if (cJSON_IsNull(photo_size)) {
        photo_size = NULL;
    }
    if (photo_size) { 
    if(!cJSON_IsNumber(photo_size))
    {
    goto end; //Numeric
    }
    }

    // create_invoice_link_request->photo_width
    cJSON *photo_width = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "photo_width");
    if (cJSON_IsNull(photo_width)) {
        photo_width = NULL;
    }
    if (photo_width) { 
    if(!cJSON_IsNumber(photo_width))
    {
    goto end; //Numeric
    }
    }

    // create_invoice_link_request->photo_height
    cJSON *photo_height = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "photo_height");
    if (cJSON_IsNull(photo_height)) {
        photo_height = NULL;
    }
    if (photo_height) { 
    if(!cJSON_IsNumber(photo_height))
    {
    goto end; //Numeric
    }
    }

    // create_invoice_link_request->need_name
    cJSON *need_name = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "need_name");
    if (cJSON_IsNull(need_name)) {
        need_name = NULL;
    }
    if (need_name) { 
    if(!cJSON_IsBool(need_name))
    {
    goto end; //Bool
    }
    }

    // create_invoice_link_request->need_phone_number
    cJSON *need_phone_number = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "need_phone_number");
    if (cJSON_IsNull(need_phone_number)) {
        need_phone_number = NULL;
    }
    if (need_phone_number) { 
    if(!cJSON_IsBool(need_phone_number))
    {
    goto end; //Bool
    }
    }

    // create_invoice_link_request->need_email
    cJSON *need_email = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "need_email");
    if (cJSON_IsNull(need_email)) {
        need_email = NULL;
    }
    if (need_email) { 
    if(!cJSON_IsBool(need_email))
    {
    goto end; //Bool
    }
    }

    // create_invoice_link_request->need_shipping_address
    cJSON *need_shipping_address = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "need_shipping_address");
    if (cJSON_IsNull(need_shipping_address)) {
        need_shipping_address = NULL;
    }
    if (need_shipping_address) { 
    if(!cJSON_IsBool(need_shipping_address))
    {
    goto end; //Bool
    }
    }

    // create_invoice_link_request->send_phone_number_to_provider
    cJSON *send_phone_number_to_provider = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "send_phone_number_to_provider");
    if (cJSON_IsNull(send_phone_number_to_provider)) {
        send_phone_number_to_provider = NULL;
    }
    if (send_phone_number_to_provider) { 
    if(!cJSON_IsBool(send_phone_number_to_provider))
    {
    goto end; //Bool
    }
    }

    // create_invoice_link_request->send_email_to_provider
    cJSON *send_email_to_provider = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "send_email_to_provider");
    if (cJSON_IsNull(send_email_to_provider)) {
        send_email_to_provider = NULL;
    }
    if (send_email_to_provider) { 
    if(!cJSON_IsBool(send_email_to_provider))
    {
    goto end; //Bool
    }
    }

    // create_invoice_link_request->is_flexible
    cJSON *is_flexible = cJSON_GetObjectItemCaseSensitive(create_invoice_link_requestJSON, "is_flexible");
    if (cJSON_IsNull(is_flexible)) {
        is_flexible = NULL;
    }
    if (is_flexible) { 
    if(!cJSON_IsBool(is_flexible))
    {
    goto end; //Bool
    }
    }


    create_invoice_link_request_local_var = create_invoice_link_request_create_internal (
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

    return create_invoice_link_request_local_var;
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
