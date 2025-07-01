#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shipping_query.h"



static shipping_query_t *shipping_query_create_internal(
    char *id,
    user_t *from,
    char *invoice_payload,
    shipping_address_t *shipping_address
    ) {
    shipping_query_t *shipping_query_local_var = malloc(sizeof(shipping_query_t));
    if (!shipping_query_local_var) {
        return NULL;
    }
    shipping_query_local_var->id = id;
    shipping_query_local_var->from = from;
    shipping_query_local_var->invoice_payload = invoice_payload;
    shipping_query_local_var->shipping_address = shipping_address;

    shipping_query_local_var->_library_owned = 1;
    return shipping_query_local_var;
}

__attribute__((deprecated)) shipping_query_t *shipping_query_create(
    char *id,
    user_t *from,
    char *invoice_payload,
    shipping_address_t *shipping_address
    ) {
    return shipping_query_create_internal (
        id,
        from,
        invoice_payload,
        shipping_address
        );
}

void shipping_query_free(shipping_query_t *shipping_query) {
    if(NULL == shipping_query){
        return ;
    }
    if(shipping_query->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "shipping_query_free");
        return ;
    }
    listEntry_t *listEntry;
    if (shipping_query->id) {
        free(shipping_query->id);
        shipping_query->id = NULL;
    }
    if (shipping_query->from) {
        user_free(shipping_query->from);
        shipping_query->from = NULL;
    }
    if (shipping_query->invoice_payload) {
        free(shipping_query->invoice_payload);
        shipping_query->invoice_payload = NULL;
    }
    if (shipping_query->shipping_address) {
        shipping_address_free(shipping_query->shipping_address);
        shipping_query->shipping_address = NULL;
    }
    free(shipping_query);
}

cJSON *shipping_query_convertToJSON(shipping_query_t *shipping_query) {
    cJSON *item = cJSON_CreateObject();

    // shipping_query->id
    if (!shipping_query->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", shipping_query->id) == NULL) {
    goto fail; //String
    }


    // shipping_query->from
    if (!shipping_query->from) {
        goto fail;
    }
    cJSON *from_local_JSON = user_convertToJSON(shipping_query->from);
    if(from_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "from", from_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // shipping_query->invoice_payload
    if (!shipping_query->invoice_payload) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invoice_payload", shipping_query->invoice_payload) == NULL) {
    goto fail; //String
    }


    // shipping_query->shipping_address
    if (!shipping_query->shipping_address) {
        goto fail;
    }
    cJSON *shipping_address_local_JSON = shipping_address_convertToJSON(shipping_query->shipping_address);
    if(shipping_address_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "shipping_address", shipping_address_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

shipping_query_t *shipping_query_parseFromJSON(cJSON *shipping_queryJSON){

    shipping_query_t *shipping_query_local_var = NULL;

    // define the local variable for shipping_query->from
    user_t *from_local_nonprim = NULL;

    // define the local variable for shipping_query->shipping_address
    shipping_address_t *shipping_address_local_nonprim = NULL;

    // shipping_query->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(shipping_queryJSON, "id");
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

    // shipping_query->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(shipping_queryJSON, "from");
    if (cJSON_IsNull(from)) {
        from = NULL;
    }
    if (!from) {
        goto end;
    }

    
    from_local_nonprim = user_parseFromJSON(from); //nonprimitive

    // shipping_query->invoice_payload
    cJSON *invoice_payload = cJSON_GetObjectItemCaseSensitive(shipping_queryJSON, "invoice_payload");
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

    // shipping_query->shipping_address
    cJSON *shipping_address = cJSON_GetObjectItemCaseSensitive(shipping_queryJSON, "shipping_address");
    if (cJSON_IsNull(shipping_address)) {
        shipping_address = NULL;
    }
    if (!shipping_address) {
        goto end;
    }

    
    shipping_address_local_nonprim = shipping_address_parseFromJSON(shipping_address); //nonprimitive


    shipping_query_local_var = shipping_query_create_internal (
        strdup(id->valuestring),
        from_local_nonprim,
        strdup(invoice_payload->valuestring),
        shipping_address_local_nonprim
        );

    return shipping_query_local_var;
end:
    if (from_local_nonprim) {
        user_free(from_local_nonprim);
        from_local_nonprim = NULL;
    }
    if (shipping_address_local_nonprim) {
        shipping_address_free(shipping_address_local_nonprim);
        shipping_address_local_nonprim = NULL;
    }
    return NULL;

}
