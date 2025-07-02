#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "refund_star_payment_response.h"



static refund_star_payment_response_t *refund_star_payment_response_create_internal(
    int ok,
    int result
    ) {
    refund_star_payment_response_t *refund_star_payment_response_local_var = malloc(sizeof(refund_star_payment_response_t));
    if (!refund_star_payment_response_local_var) {
        return NULL;
    }
    refund_star_payment_response_local_var->ok = ok;
    refund_star_payment_response_local_var->result = result;

    refund_star_payment_response_local_var->_library_owned = 1;
    return refund_star_payment_response_local_var;
}

__attribute__((deprecated)) refund_star_payment_response_t *refund_star_payment_response_create(
    int ok,
    int result
    ) {
    return refund_star_payment_response_create_internal (
        ok,
        result
        );
}

void refund_star_payment_response_free(refund_star_payment_response_t *refund_star_payment_response) {
    if(NULL == refund_star_payment_response){
        return ;
    }
    if(refund_star_payment_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "refund_star_payment_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(refund_star_payment_response);
}

cJSON *refund_star_payment_response_convertToJSON(refund_star_payment_response_t *refund_star_payment_response) {
    cJSON *item = cJSON_CreateObject();

    // refund_star_payment_response->ok
    if (!refund_star_payment_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", refund_star_payment_response->ok) == NULL) {
    goto fail; //Bool
    }


    // refund_star_payment_response->result
    if (!refund_star_payment_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", refund_star_payment_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

refund_star_payment_response_t *refund_star_payment_response_parseFromJSON(cJSON *refund_star_payment_responseJSON){

    refund_star_payment_response_t *refund_star_payment_response_local_var = NULL;

    // refund_star_payment_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(refund_star_payment_responseJSON, "ok");
    if (cJSON_IsNull(ok)) {
        ok = NULL;
    }
    if (!ok) {
        goto end;
    }

    
    if(!cJSON_IsBool(ok))
    {
    goto end; //Bool
    }

    // refund_star_payment_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(refund_star_payment_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    if(!cJSON_IsBool(result))
    {
    goto end; //Bool
    }


    refund_star_payment_response_local_var = refund_star_payment_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return refund_star_payment_response_local_var;
end:
    return NULL;

}
