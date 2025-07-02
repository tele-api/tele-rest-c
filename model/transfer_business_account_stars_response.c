#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transfer_business_account_stars_response.h"



static transfer_business_account_stars_response_t *transfer_business_account_stars_response_create_internal(
    int ok,
    int result
    ) {
    transfer_business_account_stars_response_t *transfer_business_account_stars_response_local_var = malloc(sizeof(transfer_business_account_stars_response_t));
    if (!transfer_business_account_stars_response_local_var) {
        return NULL;
    }
    transfer_business_account_stars_response_local_var->ok = ok;
    transfer_business_account_stars_response_local_var->result = result;

    transfer_business_account_stars_response_local_var->_library_owned = 1;
    return transfer_business_account_stars_response_local_var;
}

__attribute__((deprecated)) transfer_business_account_stars_response_t *transfer_business_account_stars_response_create(
    int ok,
    int result
    ) {
    return transfer_business_account_stars_response_create_internal (
        ok,
        result
        );
}

void transfer_business_account_stars_response_free(transfer_business_account_stars_response_t *transfer_business_account_stars_response) {
    if(NULL == transfer_business_account_stars_response){
        return ;
    }
    if(transfer_business_account_stars_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "transfer_business_account_stars_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(transfer_business_account_stars_response);
}

cJSON *transfer_business_account_stars_response_convertToJSON(transfer_business_account_stars_response_t *transfer_business_account_stars_response) {
    cJSON *item = cJSON_CreateObject();

    // transfer_business_account_stars_response->ok
    if (!transfer_business_account_stars_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", transfer_business_account_stars_response->ok) == NULL) {
    goto fail; //Bool
    }


    // transfer_business_account_stars_response->result
    if (!transfer_business_account_stars_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", transfer_business_account_stars_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

transfer_business_account_stars_response_t *transfer_business_account_stars_response_parseFromJSON(cJSON *transfer_business_account_stars_responseJSON){

    transfer_business_account_stars_response_t *transfer_business_account_stars_response_local_var = NULL;

    // transfer_business_account_stars_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(transfer_business_account_stars_responseJSON, "ok");
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

    // transfer_business_account_stars_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(transfer_business_account_stars_responseJSON, "result");
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


    transfer_business_account_stars_response_local_var = transfer_business_account_stars_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return transfer_business_account_stars_response_local_var;
end:
    return NULL;

}
