#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pre_checkout_query.h"



static pre_checkout_query_t *pre_checkout_query_create_internal(
    char *id,
    user_t *from,
    char *currency,
    int total_amount,
    char *invoice_payload,
    char *shipping_option_id,
    order_info_t *order_info
    ) {
    pre_checkout_query_t *pre_checkout_query_local_var = malloc(sizeof(pre_checkout_query_t));
    if (!pre_checkout_query_local_var) {
        return NULL;
    }
    pre_checkout_query_local_var->id = id;
    pre_checkout_query_local_var->from = from;
    pre_checkout_query_local_var->currency = currency;
    pre_checkout_query_local_var->total_amount = total_amount;
    pre_checkout_query_local_var->invoice_payload = invoice_payload;
    pre_checkout_query_local_var->shipping_option_id = shipping_option_id;
    pre_checkout_query_local_var->order_info = order_info;

    pre_checkout_query_local_var->_library_owned = 1;
    return pre_checkout_query_local_var;
}

__attribute__((deprecated)) pre_checkout_query_t *pre_checkout_query_create(
    char *id,
    user_t *from,
    char *currency,
    int total_amount,
    char *invoice_payload,
    char *shipping_option_id,
    order_info_t *order_info
    ) {
    return pre_checkout_query_create_internal (
        id,
        from,
        currency,
        total_amount,
        invoice_payload,
        shipping_option_id,
        order_info
        );
}

void pre_checkout_query_free(pre_checkout_query_t *pre_checkout_query) {
    if(NULL == pre_checkout_query){
        return ;
    }
    if(pre_checkout_query->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pre_checkout_query_free");
        return ;
    }
    listEntry_t *listEntry;
    if (pre_checkout_query->id) {
        free(pre_checkout_query->id);
        pre_checkout_query->id = NULL;
    }
    if (pre_checkout_query->from) {
        user_free(pre_checkout_query->from);
        pre_checkout_query->from = NULL;
    }
    if (pre_checkout_query->currency) {
        free(pre_checkout_query->currency);
        pre_checkout_query->currency = NULL;
    }
    if (pre_checkout_query->invoice_payload) {
        free(pre_checkout_query->invoice_payload);
        pre_checkout_query->invoice_payload = NULL;
    }
    if (pre_checkout_query->shipping_option_id) {
        free(pre_checkout_query->shipping_option_id);
        pre_checkout_query->shipping_option_id = NULL;
    }
    if (pre_checkout_query->order_info) {
        order_info_free(pre_checkout_query->order_info);
        pre_checkout_query->order_info = NULL;
    }
    free(pre_checkout_query);
}

cJSON *pre_checkout_query_convertToJSON(pre_checkout_query_t *pre_checkout_query) {
    cJSON *item = cJSON_CreateObject();

    // pre_checkout_query->id
    if (!pre_checkout_query->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", pre_checkout_query->id) == NULL) {
    goto fail; //String
    }


    // pre_checkout_query->from
    if (!pre_checkout_query->from) {
        goto fail;
    }
    cJSON *from_local_JSON = user_convertToJSON(pre_checkout_query->from);
    if(from_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "from", from_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // pre_checkout_query->currency
    if (!pre_checkout_query->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", pre_checkout_query->currency) == NULL) {
    goto fail; //String
    }


    // pre_checkout_query->total_amount
    if (!pre_checkout_query->total_amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total_amount", pre_checkout_query->total_amount) == NULL) {
    goto fail; //Numeric
    }


    // pre_checkout_query->invoice_payload
    if (!pre_checkout_query->invoice_payload) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invoice_payload", pre_checkout_query->invoice_payload) == NULL) {
    goto fail; //String
    }


    // pre_checkout_query->shipping_option_id
    if(pre_checkout_query->shipping_option_id) {
    if(cJSON_AddStringToObject(item, "shipping_option_id", pre_checkout_query->shipping_option_id) == NULL) {
    goto fail; //String
    }
    }


    // pre_checkout_query->order_info
    if(pre_checkout_query->order_info) {
    cJSON *order_info_local_JSON = order_info_convertToJSON(pre_checkout_query->order_info);
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

pre_checkout_query_t *pre_checkout_query_parseFromJSON(cJSON *pre_checkout_queryJSON){

    pre_checkout_query_t *pre_checkout_query_local_var = NULL;

    // define the local variable for pre_checkout_query->from
    user_t *from_local_nonprim = NULL;

    // define the local variable for pre_checkout_query->order_info
    order_info_t *order_info_local_nonprim = NULL;

    // pre_checkout_query->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(pre_checkout_queryJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // pre_checkout_query->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(pre_checkout_queryJSON, "from");
    if (cJSON_IsNull(from)) {
        from = NULL;
    }
    if (!from) {
        goto end;
    }

    
    from_local_nonprim = user_parseFromJSON(from); //nonprimitive

    // pre_checkout_query->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(pre_checkout_queryJSON, "currency");
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

    // pre_checkout_query->total_amount
    cJSON *total_amount = cJSON_GetObjectItemCaseSensitive(pre_checkout_queryJSON, "total_amount");
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

    // pre_checkout_query->invoice_payload
    cJSON *invoice_payload = cJSON_GetObjectItemCaseSensitive(pre_checkout_queryJSON, "invoice_payload");
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

    // pre_checkout_query->shipping_option_id
    cJSON *shipping_option_id = cJSON_GetObjectItemCaseSensitive(pre_checkout_queryJSON, "shipping_option_id");
    if (cJSON_IsNull(shipping_option_id)) {
        shipping_option_id = NULL;
    }
    if (shipping_option_id) { 
    if(!cJSON_IsString(shipping_option_id) && !cJSON_IsNull(shipping_option_id))
    {
    goto end; //String
    }
    }

    // pre_checkout_query->order_info
    cJSON *order_info = cJSON_GetObjectItemCaseSensitive(pre_checkout_queryJSON, "order_info");
    if (cJSON_IsNull(order_info)) {
        order_info = NULL;
    }
    if (order_info) { 
    order_info_local_nonprim = order_info_parseFromJSON(order_info); //nonprimitive
    }


    pre_checkout_query_local_var = pre_checkout_query_create_internal (
        strdup(id->valuestring),
        from_local_nonprim,
        strdup(currency->valuestring),
        total_amount->valuedouble,
        strdup(invoice_payload->valuestring),
        shipping_option_id && !cJSON_IsNull(shipping_option_id) ? strdup(shipping_option_id->valuestring) : NULL,
        order_info ? order_info_local_nonprim : NULL
        );

    return pre_checkout_query_local_var;
end:
    if (from_local_nonprim) {
        user_free(from_local_nonprim);
        from_local_nonprim = NULL;
    }
    if (order_info_local_nonprim) {
        order_info_free(order_info_local_nonprim);
        order_info_local_nonprim = NULL;
    }
    return NULL;

}
