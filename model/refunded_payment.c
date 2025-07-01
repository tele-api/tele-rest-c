#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "refunded_payment.h"



static refunded_payment_t *refunded_payment_create_internal(
    char *currency,
    int total_amount,
    char *invoice_payload,
    char *telegram_payment_charge_id,
    char *provider_payment_charge_id
    ) {
    refunded_payment_t *refunded_payment_local_var = malloc(sizeof(refunded_payment_t));
    if (!refunded_payment_local_var) {
        return NULL;
    }
    refunded_payment_local_var->currency = currency;
    refunded_payment_local_var->total_amount = total_amount;
    refunded_payment_local_var->invoice_payload = invoice_payload;
    refunded_payment_local_var->telegram_payment_charge_id = telegram_payment_charge_id;
    refunded_payment_local_var->provider_payment_charge_id = provider_payment_charge_id;

    refunded_payment_local_var->_library_owned = 1;
    return refunded_payment_local_var;
}

__attribute__((deprecated)) refunded_payment_t *refunded_payment_create(
    char *currency,
    int total_amount,
    char *invoice_payload,
    char *telegram_payment_charge_id,
    char *provider_payment_charge_id
    ) {
    return refunded_payment_create_internal (
        currency,
        total_amount,
        invoice_payload,
        telegram_payment_charge_id,
        provider_payment_charge_id
        );
}

void refunded_payment_free(refunded_payment_t *refunded_payment) {
    if(NULL == refunded_payment){
        return ;
    }
    if(refunded_payment->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "refunded_payment_free");
        return ;
    }
    listEntry_t *listEntry;
    if (refunded_payment->currency) {
        free(refunded_payment->currency);
        refunded_payment->currency = NULL;
    }
    if (refunded_payment->invoice_payload) {
        free(refunded_payment->invoice_payload);
        refunded_payment->invoice_payload = NULL;
    }
    if (refunded_payment->telegram_payment_charge_id) {
        free(refunded_payment->telegram_payment_charge_id);
        refunded_payment->telegram_payment_charge_id = NULL;
    }
    if (refunded_payment->provider_payment_charge_id) {
        free(refunded_payment->provider_payment_charge_id);
        refunded_payment->provider_payment_charge_id = NULL;
    }
    free(refunded_payment);
}

cJSON *refunded_payment_convertToJSON(refunded_payment_t *refunded_payment) {
    cJSON *item = cJSON_CreateObject();

    // refunded_payment->currency
    if (!refunded_payment->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", refunded_payment->currency) == NULL) {
    goto fail; //String
    }


    // refunded_payment->total_amount
    if (!refunded_payment->total_amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total_amount", refunded_payment->total_amount) == NULL) {
    goto fail; //Numeric
    }


    // refunded_payment->invoice_payload
    if (!refunded_payment->invoice_payload) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invoice_payload", refunded_payment->invoice_payload) == NULL) {
    goto fail; //String
    }


    // refunded_payment->telegram_payment_charge_id
    if (!refunded_payment->telegram_payment_charge_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "telegram_payment_charge_id", refunded_payment->telegram_payment_charge_id) == NULL) {
    goto fail; //String
    }


    // refunded_payment->provider_payment_charge_id
    if(refunded_payment->provider_payment_charge_id) {
    if(cJSON_AddStringToObject(item, "provider_payment_charge_id", refunded_payment->provider_payment_charge_id) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

refunded_payment_t *refunded_payment_parseFromJSON(cJSON *refunded_paymentJSON){

    refunded_payment_t *refunded_payment_local_var = NULL;

    // refunded_payment->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(refunded_paymentJSON, "currency");
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

    // refunded_payment->total_amount
    cJSON *total_amount = cJSON_GetObjectItemCaseSensitive(refunded_paymentJSON, "total_amount");
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

    // refunded_payment->invoice_payload
    cJSON *invoice_payload = cJSON_GetObjectItemCaseSensitive(refunded_paymentJSON, "invoice_payload");
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

    // refunded_payment->telegram_payment_charge_id
    cJSON *telegram_payment_charge_id = cJSON_GetObjectItemCaseSensitive(refunded_paymentJSON, "telegram_payment_charge_id");
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

    // refunded_payment->provider_payment_charge_id
    cJSON *provider_payment_charge_id = cJSON_GetObjectItemCaseSensitive(refunded_paymentJSON, "provider_payment_charge_id");
    if (cJSON_IsNull(provider_payment_charge_id)) {
        provider_payment_charge_id = NULL;
    }
    if (provider_payment_charge_id) { 
    if(!cJSON_IsString(provider_payment_charge_id) && !cJSON_IsNull(provider_payment_charge_id))
    {
    goto end; //String
    }
    }


    refunded_payment_local_var = refunded_payment_create_internal (
        strdup(currency->valuestring),
        total_amount->valuedouble,
        strdup(invoice_payload->valuestring),
        strdup(telegram_payment_charge_id->valuestring),
        provider_payment_charge_id && !cJSON_IsNull(provider_payment_charge_id) ? strdup(provider_payment_charge_id->valuestring) : NULL
        );

    return refunded_payment_local_var;
end:
    return NULL;

}
