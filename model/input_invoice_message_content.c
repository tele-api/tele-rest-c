#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_invoice_message_content.h"



static input_invoice_message_content_t *input_invoice_message_content_create_internal(
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
    ) {
    input_invoice_message_content_t *input_invoice_message_content_local_var = malloc(sizeof(input_invoice_message_content_t));
    if (!input_invoice_message_content_local_var) {
        return NULL;
    }
    input_invoice_message_content_local_var->title = title;
    input_invoice_message_content_local_var->description = description;
    input_invoice_message_content_local_var->payload = payload;
    input_invoice_message_content_local_var->currency = currency;
    input_invoice_message_content_local_var->prices = prices;
    input_invoice_message_content_local_var->provider_token = provider_token;
    input_invoice_message_content_local_var->max_tip_amount = max_tip_amount;
    input_invoice_message_content_local_var->suggested_tip_amounts = suggested_tip_amounts;
    input_invoice_message_content_local_var->provider_data = provider_data;
    input_invoice_message_content_local_var->photo_url = photo_url;
    input_invoice_message_content_local_var->photo_size = photo_size;
    input_invoice_message_content_local_var->photo_width = photo_width;
    input_invoice_message_content_local_var->photo_height = photo_height;
    input_invoice_message_content_local_var->need_name = need_name;
    input_invoice_message_content_local_var->need_phone_number = need_phone_number;
    input_invoice_message_content_local_var->need_email = need_email;
    input_invoice_message_content_local_var->need_shipping_address = need_shipping_address;
    input_invoice_message_content_local_var->send_phone_number_to_provider = send_phone_number_to_provider;
    input_invoice_message_content_local_var->send_email_to_provider = send_email_to_provider;
    input_invoice_message_content_local_var->is_flexible = is_flexible;

    input_invoice_message_content_local_var->_library_owned = 1;
    return input_invoice_message_content_local_var;
}

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
    ) {
    return input_invoice_message_content_create_internal (
        title,
        description,
        payload,
        currency,
        prices,
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

void input_invoice_message_content_free(input_invoice_message_content_t *input_invoice_message_content) {
    if(NULL == input_invoice_message_content){
        return ;
    }
    if(input_invoice_message_content->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_invoice_message_content_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_invoice_message_content->title) {
        free(input_invoice_message_content->title);
        input_invoice_message_content->title = NULL;
    }
    if (input_invoice_message_content->description) {
        free(input_invoice_message_content->description);
        input_invoice_message_content->description = NULL;
    }
    if (input_invoice_message_content->payload) {
        free(input_invoice_message_content->payload);
        input_invoice_message_content->payload = NULL;
    }
    if (input_invoice_message_content->currency) {
        free(input_invoice_message_content->currency);
        input_invoice_message_content->currency = NULL;
    }
    if (input_invoice_message_content->prices) {
        list_ForEach(listEntry, input_invoice_message_content->prices) {
            labeled_price_free(listEntry->data);
        }
        list_freeList(input_invoice_message_content->prices);
        input_invoice_message_content->prices = NULL;
    }
    if (input_invoice_message_content->provider_token) {
        free(input_invoice_message_content->provider_token);
        input_invoice_message_content->provider_token = NULL;
    }
    if (input_invoice_message_content->suggested_tip_amounts) {
        list_ForEach(listEntry, input_invoice_message_content->suggested_tip_amounts) {
            free(listEntry->data);
        }
        list_freeList(input_invoice_message_content->suggested_tip_amounts);
        input_invoice_message_content->suggested_tip_amounts = NULL;
    }
    if (input_invoice_message_content->provider_data) {
        free(input_invoice_message_content->provider_data);
        input_invoice_message_content->provider_data = NULL;
    }
    if (input_invoice_message_content->photo_url) {
        free(input_invoice_message_content->photo_url);
        input_invoice_message_content->photo_url = NULL;
    }
    free(input_invoice_message_content);
}

cJSON *input_invoice_message_content_convertToJSON(input_invoice_message_content_t *input_invoice_message_content) {
    cJSON *item = cJSON_CreateObject();

    // input_invoice_message_content->title
    if (!input_invoice_message_content->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", input_invoice_message_content->title) == NULL) {
    goto fail; //String
    }


    // input_invoice_message_content->description
    if (!input_invoice_message_content->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", input_invoice_message_content->description) == NULL) {
    goto fail; //String
    }


    // input_invoice_message_content->payload
    if (!input_invoice_message_content->payload) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "payload", input_invoice_message_content->payload) == NULL) {
    goto fail; //String
    }


    // input_invoice_message_content->currency
    if (!input_invoice_message_content->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", input_invoice_message_content->currency) == NULL) {
    goto fail; //String
    }


    // input_invoice_message_content->prices
    if (!input_invoice_message_content->prices) {
        goto fail;
    }
    cJSON *prices = cJSON_AddArrayToObject(item, "prices");
    if(prices == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *pricesListEntry;
    if (input_invoice_message_content->prices) {
    list_ForEach(pricesListEntry, input_invoice_message_content->prices) {
    cJSON *itemLocal = labeled_price_convertToJSON(pricesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(prices, itemLocal);
    }
    }


    // input_invoice_message_content->provider_token
    if(input_invoice_message_content->provider_token) {
    if(cJSON_AddStringToObject(item, "provider_token", input_invoice_message_content->provider_token) == NULL) {
    goto fail; //String
    }
    }


    // input_invoice_message_content->max_tip_amount
    if(input_invoice_message_content->max_tip_amount) {
    if(cJSON_AddNumberToObject(item, "max_tip_amount", input_invoice_message_content->max_tip_amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_invoice_message_content->suggested_tip_amounts
    if(input_invoice_message_content->suggested_tip_amounts) {
    cJSON *suggested_tip_amounts = cJSON_AddArrayToObject(item, "suggested_tip_amounts");
    if(suggested_tip_amounts == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *suggested_tip_amountsListEntry;
    list_ForEach(suggested_tip_amountsListEntry, input_invoice_message_content->suggested_tip_amounts) {
    if(cJSON_AddNumberToObject(suggested_tip_amounts, "", *(double *)suggested_tip_amountsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // input_invoice_message_content->provider_data
    if(input_invoice_message_content->provider_data) {
    if(cJSON_AddStringToObject(item, "provider_data", input_invoice_message_content->provider_data) == NULL) {
    goto fail; //String
    }
    }


    // input_invoice_message_content->photo_url
    if(input_invoice_message_content->photo_url) {
    if(cJSON_AddStringToObject(item, "photo_url", input_invoice_message_content->photo_url) == NULL) {
    goto fail; //String
    }
    }


    // input_invoice_message_content->photo_size
    if(input_invoice_message_content->photo_size) {
    if(cJSON_AddNumberToObject(item, "photo_size", input_invoice_message_content->photo_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_invoice_message_content->photo_width
    if(input_invoice_message_content->photo_width) {
    if(cJSON_AddNumberToObject(item, "photo_width", input_invoice_message_content->photo_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_invoice_message_content->photo_height
    if(input_invoice_message_content->photo_height) {
    if(cJSON_AddNumberToObject(item, "photo_height", input_invoice_message_content->photo_height) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_invoice_message_content->need_name
    if(input_invoice_message_content->need_name) {
    if(cJSON_AddBoolToObject(item, "need_name", input_invoice_message_content->need_name) == NULL) {
    goto fail; //Bool
    }
    }


    // input_invoice_message_content->need_phone_number
    if(input_invoice_message_content->need_phone_number) {
    if(cJSON_AddBoolToObject(item, "need_phone_number", input_invoice_message_content->need_phone_number) == NULL) {
    goto fail; //Bool
    }
    }


    // input_invoice_message_content->need_email
    if(input_invoice_message_content->need_email) {
    if(cJSON_AddBoolToObject(item, "need_email", input_invoice_message_content->need_email) == NULL) {
    goto fail; //Bool
    }
    }


    // input_invoice_message_content->need_shipping_address
    if(input_invoice_message_content->need_shipping_address) {
    if(cJSON_AddBoolToObject(item, "need_shipping_address", input_invoice_message_content->need_shipping_address) == NULL) {
    goto fail; //Bool
    }
    }


    // input_invoice_message_content->send_phone_number_to_provider
    if(input_invoice_message_content->send_phone_number_to_provider) {
    if(cJSON_AddBoolToObject(item, "send_phone_number_to_provider", input_invoice_message_content->send_phone_number_to_provider) == NULL) {
    goto fail; //Bool
    }
    }


    // input_invoice_message_content->send_email_to_provider
    if(input_invoice_message_content->send_email_to_provider) {
    if(cJSON_AddBoolToObject(item, "send_email_to_provider", input_invoice_message_content->send_email_to_provider) == NULL) {
    goto fail; //Bool
    }
    }


    // input_invoice_message_content->is_flexible
    if(input_invoice_message_content->is_flexible) {
    if(cJSON_AddBoolToObject(item, "is_flexible", input_invoice_message_content->is_flexible) == NULL) {
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

input_invoice_message_content_t *input_invoice_message_content_parseFromJSON(cJSON *input_invoice_message_contentJSON){

    input_invoice_message_content_t *input_invoice_message_content_local_var = NULL;

    // define the local list for input_invoice_message_content->prices
    list_t *pricesList = NULL;

    // define the local list for input_invoice_message_content->suggested_tip_amounts
    list_t *suggested_tip_amountsList = NULL;

    // input_invoice_message_content->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "title");
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

    // input_invoice_message_content->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "description");
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

    // input_invoice_message_content->payload
    cJSON *payload = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "payload");
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

    // input_invoice_message_content->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "currency");
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

    // input_invoice_message_content->prices
    cJSON *prices = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "prices");
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

    // input_invoice_message_content->provider_token
    cJSON *provider_token = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "provider_token");
    if (cJSON_IsNull(provider_token)) {
        provider_token = NULL;
    }
    if (provider_token) { 
    if(!cJSON_IsString(provider_token) && !cJSON_IsNull(provider_token))
    {
    goto end; //String
    }
    }

    // input_invoice_message_content->max_tip_amount
    cJSON *max_tip_amount = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "max_tip_amount");
    if (cJSON_IsNull(max_tip_amount)) {
        max_tip_amount = NULL;
    }
    if (max_tip_amount) { 
    if(!cJSON_IsNumber(max_tip_amount))
    {
    goto end; //Numeric
    }
    }

    // input_invoice_message_content->suggested_tip_amounts
    cJSON *suggested_tip_amounts = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "suggested_tip_amounts");
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

    // input_invoice_message_content->provider_data
    cJSON *provider_data = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "provider_data");
    if (cJSON_IsNull(provider_data)) {
        provider_data = NULL;
    }
    if (provider_data) { 
    if(!cJSON_IsString(provider_data) && !cJSON_IsNull(provider_data))
    {
    goto end; //String
    }
    }

    // input_invoice_message_content->photo_url
    cJSON *photo_url = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "photo_url");
    if (cJSON_IsNull(photo_url)) {
        photo_url = NULL;
    }
    if (photo_url) { 
    if(!cJSON_IsString(photo_url) && !cJSON_IsNull(photo_url))
    {
    goto end; //String
    }
    }

    // input_invoice_message_content->photo_size
    cJSON *photo_size = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "photo_size");
    if (cJSON_IsNull(photo_size)) {
        photo_size = NULL;
    }
    if (photo_size) { 
    if(!cJSON_IsNumber(photo_size))
    {
    goto end; //Numeric
    }
    }

    // input_invoice_message_content->photo_width
    cJSON *photo_width = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "photo_width");
    if (cJSON_IsNull(photo_width)) {
        photo_width = NULL;
    }
    if (photo_width) { 
    if(!cJSON_IsNumber(photo_width))
    {
    goto end; //Numeric
    }
    }

    // input_invoice_message_content->photo_height
    cJSON *photo_height = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "photo_height");
    if (cJSON_IsNull(photo_height)) {
        photo_height = NULL;
    }
    if (photo_height) { 
    if(!cJSON_IsNumber(photo_height))
    {
    goto end; //Numeric
    }
    }

    // input_invoice_message_content->need_name
    cJSON *need_name = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "need_name");
    if (cJSON_IsNull(need_name)) {
        need_name = NULL;
    }
    if (need_name) { 
    if(!cJSON_IsBool(need_name))
    {
    goto end; //Bool
    }
    }

    // input_invoice_message_content->need_phone_number
    cJSON *need_phone_number = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "need_phone_number");
    if (cJSON_IsNull(need_phone_number)) {
        need_phone_number = NULL;
    }
    if (need_phone_number) { 
    if(!cJSON_IsBool(need_phone_number))
    {
    goto end; //Bool
    }
    }

    // input_invoice_message_content->need_email
    cJSON *need_email = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "need_email");
    if (cJSON_IsNull(need_email)) {
        need_email = NULL;
    }
    if (need_email) { 
    if(!cJSON_IsBool(need_email))
    {
    goto end; //Bool
    }
    }

    // input_invoice_message_content->need_shipping_address
    cJSON *need_shipping_address = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "need_shipping_address");
    if (cJSON_IsNull(need_shipping_address)) {
        need_shipping_address = NULL;
    }
    if (need_shipping_address) { 
    if(!cJSON_IsBool(need_shipping_address))
    {
    goto end; //Bool
    }
    }

    // input_invoice_message_content->send_phone_number_to_provider
    cJSON *send_phone_number_to_provider = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "send_phone_number_to_provider");
    if (cJSON_IsNull(send_phone_number_to_provider)) {
        send_phone_number_to_provider = NULL;
    }
    if (send_phone_number_to_provider) { 
    if(!cJSON_IsBool(send_phone_number_to_provider))
    {
    goto end; //Bool
    }
    }

    // input_invoice_message_content->send_email_to_provider
    cJSON *send_email_to_provider = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "send_email_to_provider");
    if (cJSON_IsNull(send_email_to_provider)) {
        send_email_to_provider = NULL;
    }
    if (send_email_to_provider) { 
    if(!cJSON_IsBool(send_email_to_provider))
    {
    goto end; //Bool
    }
    }

    // input_invoice_message_content->is_flexible
    cJSON *is_flexible = cJSON_GetObjectItemCaseSensitive(input_invoice_message_contentJSON, "is_flexible");
    if (cJSON_IsNull(is_flexible)) {
        is_flexible = NULL;
    }
    if (is_flexible) { 
    if(!cJSON_IsBool(is_flexible))
    {
    goto end; //Bool
    }
    }


    input_invoice_message_content_local_var = input_invoice_message_content_create_internal (
        strdup(title->valuestring),
        strdup(description->valuestring),
        strdup(payload->valuestring),
        strdup(currency->valuestring),
        pricesList,
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

    return input_invoice_message_content_local_var;
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
