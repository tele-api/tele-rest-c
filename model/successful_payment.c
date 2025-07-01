#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "successful_payment.h"



static successful_payment_t *successful_payment_create_internal(
    char *currency,
    int total_amount,
    char *invoice_payload,
    char *telegram_payment_charge_id,
    char *provider_payment_charge_id,
    int subscription_expiration_date,
    int is_recurring,
    int is_first_recurring,
    char *shipping_option_id,
    order_info_t *order_info
    ) {
    successful_payment_t *successful_payment_local_var = malloc(sizeof(successful_payment_t));
    if (!successful_payment_local_var) {
        return NULL;
    }
    successful_payment_local_var->currency = currency;
    successful_payment_local_var->total_amount = total_amount;
    successful_payment_local_var->invoice_payload = invoice_payload;
    successful_payment_local_var->telegram_payment_charge_id = telegram_payment_charge_id;
    successful_payment_local_var->provider_payment_charge_id = provider_payment_charge_id;
    successful_payment_local_var->subscription_expiration_date = subscription_expiration_date;
    successful_payment_local_var->is_recurring = is_recurring;
    successful_payment_local_var->is_first_recurring = is_first_recurring;
    successful_payment_local_var->shipping_option_id = shipping_option_id;
    successful_payment_local_var->order_info = order_info;

    successful_payment_local_var->_library_owned = 1;
    return successful_payment_local_var;
}

__attribute__((deprecated)) successful_payment_t *successful_payment_create(
    char *currency,
    int total_amount,
    char *invoice_payload,
    char *telegram_payment_charge_id,
    char *provider_payment_charge_id,
    int subscription_expiration_date,
    int is_recurring,
    int is_first_recurring,
    char *shipping_option_id,
    order_info_t *order_info
    ) {
    return successful_payment_create_internal (
        currency,
        total_amount,
        invoice_payload,
        telegram_payment_charge_id,
        provider_payment_charge_id,
        subscription_expiration_date,
        is_recurring,
        is_first_recurring,
        shipping_option_id,
        order_info
        );
}

void successful_payment_free(successful_payment_t *successful_payment) {
    if(NULL == successful_payment){
        return ;
    }
    if(successful_payment->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "successful_payment_free");
        return ;
    }
    listEntry_t *listEntry;
    if (successful_payment->currency) {
        free(successful_payment->currency);
        successful_payment->currency = NULL;
    }
    if (successful_payment->invoice_payload) {
        free(successful_payment->invoice_payload);
        successful_payment->invoice_payload = NULL;
    }
    if (successful_payment->telegram_payment_charge_id) {
        free(successful_payment->telegram_payment_charge_id);
        successful_payment->telegram_payment_charge_id = NULL;
    }
    if (successful_payment->provider_payment_charge_id) {
        free(successful_payment->provider_payment_charge_id);
        successful_payment->provider_payment_charge_id = NULL;
    }
    if (successful_payment->shipping_option_id) {
        free(successful_payment->shipping_option_id);
        successful_payment->shipping_option_id = NULL;
    }
    if (successful_payment->order_info) {
        order_info_free(successful_payment->order_info);
        successful_payment->order_info = NULL;
    }
    free(successful_payment);
}

cJSON *successful_payment_convertToJSON(successful_payment_t *successful_payment) {
    cJSON *item = cJSON_CreateObject();

    // successful_payment->currency
    if (!successful_payment->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", successful_payment->currency) == NULL) {
    goto fail; //String
    }


    // successful_payment->total_amount
    if (!successful_payment->total_amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total_amount", successful_payment->total_amount) == NULL) {
    goto fail; //Numeric
    }


    // successful_payment->invoice_payload
    if (!successful_payment->invoice_payload) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invoice_payload", successful_payment->invoice_payload) == NULL) {
    goto fail; //String
    }


    // successful_payment->telegram_payment_charge_id
    if (!successful_payment->telegram_payment_charge_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "telegram_payment_charge_id", successful_payment->telegram_payment_charge_id) == NULL) {
    goto fail; //String
    }


    // successful_payment->provider_payment_charge_id
    if (!successful_payment->provider_payment_charge_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "provider_payment_charge_id", successful_payment->provider_payment_charge_id) == NULL) {
    goto fail; //String
    }


    // successful_payment->subscription_expiration_date
    if(successful_payment->subscription_expiration_date) {
    if(cJSON_AddNumberToObject(item, "subscription_expiration_date", successful_payment->subscription_expiration_date) == NULL) {
    goto fail; //Numeric
    }
    }


    // successful_payment->is_recurring
    if(successful_payment->is_recurring) {
    if(cJSON_AddBoolToObject(item, "is_recurring", successful_payment->is_recurring) == NULL) {
    goto fail; //Bool
    }
    }


    // successful_payment->is_first_recurring
    if(successful_payment->is_first_recurring) {
    if(cJSON_AddBoolToObject(item, "is_first_recurring", successful_payment->is_first_recurring) == NULL) {
    goto fail; //Bool
    }
    }


    // successful_payment->shipping_option_id
    if(successful_payment->shipping_option_id) {
    if(cJSON_AddStringToObject(item, "shipping_option_id", successful_payment->shipping_option_id) == NULL) {
    goto fail; //String
    }
    }


    // successful_payment->order_info
    if(successful_payment->order_info) {
    cJSON *order_info_local_JSON = order_info_convertToJSON(successful_payment->order_info);
    if(order_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "order_info", order_info_local_JSON);
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

successful_payment_t *successful_payment_parseFromJSON(cJSON *successful_paymentJSON){

    successful_payment_t *successful_payment_local_var = NULL;

    // define the local variable for successful_payment->order_info
    order_info_t *order_info_local_nonprim = NULL;

    // successful_payment->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(successful_paymentJSON, "currency");
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

    // successful_payment->total_amount
    cJSON *total_amount = cJSON_GetObjectItemCaseSensitive(successful_paymentJSON, "total_amount");
    if (cJSON_IsNull(total_amount)) {
        total_amount = NULL;
    }
    if (!total_amount) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total_amount))
    {
    goto end; //Numeric
    }

    // successful_payment->invoice_payload
    cJSON *invoice_payload = cJSON_GetObjectItemCaseSensitive(successful_paymentJSON, "invoice_payload");
    if (cJSON_IsNull(invoice_payload)) {
        invoice_payload = NULL;
    }
    if (!invoice_payload) {
        goto end;
    }

    
    if(!cJSON_IsString(invoice_payload))
    {
    goto end; //String
    }

    // successful_payment->telegram_payment_charge_id
    cJSON *telegram_payment_charge_id = cJSON_GetObjectItemCaseSensitive(successful_paymentJSON, "telegram_payment_charge_id");
    if (cJSON_IsNull(telegram_payment_charge_id)) {
        telegram_payment_charge_id = NULL;
    }
    if (!telegram_payment_charge_id) {
        goto end;
    }

    
    if(!cJSON_IsString(telegram_payment_charge_id))
    {
    goto end; //String
    }

    // successful_payment->provider_payment_charge_id
    cJSON *provider_payment_charge_id = cJSON_GetObjectItemCaseSensitive(successful_paymentJSON, "provider_payment_charge_id");
    if (cJSON_IsNull(provider_payment_charge_id)) {
        provider_payment_charge_id = NULL;
    }
    if (!provider_payment_charge_id) {
        goto end;
    }

    
    if(!cJSON_IsString(provider_payment_charge_id))
    {
    goto end; //String
    }

    // successful_payment->subscription_expiration_date
    cJSON *subscription_expiration_date = cJSON_GetObjectItemCaseSensitive(successful_paymentJSON, "subscription_expiration_date");
    if (cJSON_IsNull(subscription_expiration_date)) {
        subscription_expiration_date = NULL;
    }
    if (subscription_expiration_date) { 
    if(!cJSON_IsNumber(subscription_expiration_date))
    {
    goto end; //Numeric
    }
    }

    // successful_payment->is_recurring
    cJSON *is_recurring = cJSON_GetObjectItemCaseSensitive(successful_paymentJSON, "is_recurring");
    if (cJSON_IsNull(is_recurring)) {
        is_recurring = NULL;
    }
    if (is_recurring) { 
    if(!cJSON_IsBool(is_recurring))
    {
    goto end; //Bool
    }
    }

    // successful_payment->is_first_recurring
    cJSON *is_first_recurring = cJSON_GetObjectItemCaseSensitive(successful_paymentJSON, "is_first_recurring");
    if (cJSON_IsNull(is_first_recurring)) {
        is_first_recurring = NULL;
    }
    if (is_first_recurring) { 
    if(!cJSON_IsBool(is_first_recurring))
    {
    goto end; //Bool
    }
    }

    // successful_payment->shipping_option_id
    cJSON *shipping_option_id = cJSON_GetObjectItemCaseSensitive(successful_paymentJSON, "shipping_option_id");
    if (cJSON_IsNull(shipping_option_id)) {
        shipping_option_id = NULL;
    }
    if (shipping_option_id) { 
    if(!cJSON_IsString(shipping_option_id) && !cJSON_IsNull(shipping_option_id))
    {
    goto end; //String
    }
    }

    // successful_payment->order_info
    cJSON *order_info = cJSON_GetObjectItemCaseSensitive(successful_paymentJSON, "order_info");
    if (cJSON_IsNull(order_info)) {
        order_info = NULL;
    }
    if (order_info) { 
    order_info_local_nonprim = order_info_parseFromJSON(order_info); //nonprimitive
    }


    successful_payment_local_var = successful_payment_create_internal (
        strdup(currency->valuestring),
        total_amount->valuedouble,
        strdup(invoice_payload->valuestring),
        strdup(telegram_payment_charge_id->valuestring),
        strdup(provider_payment_charge_id->valuestring),
        subscription_expiration_date ? subscription_expiration_date->valuedouble : 0,
        is_recurring ? is_recurring->valueint : 0,
        is_first_recurring ? is_first_recurring->valueint : 0,
        shipping_option_id && !cJSON_IsNull(shipping_option_id) ? strdup(shipping_option_id->valuestring) : NULL,
        order_info ? order_info_local_nonprim : NULL
        );

    return successful_payment_local_var;
end:
    if (order_info_local_nonprim) {
        order_info_free(order_info_local_nonprim);
        order_info_local_nonprim = NULL;
    }
    return NULL;

}
