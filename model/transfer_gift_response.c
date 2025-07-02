#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transfer_gift_response.h"



static transfer_gift_response_t *transfer_gift_response_create_internal(
    int ok,
    int result
    ) {
    transfer_gift_response_t *transfer_gift_response_local_var = malloc(sizeof(transfer_gift_response_t));
    if (!transfer_gift_response_local_var) {
        return NULL;
    }
    transfer_gift_response_local_var->ok = ok;
    transfer_gift_response_local_var->result = result;

    transfer_gift_response_local_var->_library_owned = 1;
    return transfer_gift_response_local_var;
}

__attribute__((deprecated)) transfer_gift_response_t *transfer_gift_response_create(
    int ok,
    int result
    ) {
    return transfer_gift_response_create_internal (
        ok,
        result
        );
}

void transfer_gift_response_free(transfer_gift_response_t *transfer_gift_response) {
    if(NULL == transfer_gift_response){
        return ;
    }
    if(transfer_gift_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "transfer_gift_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(transfer_gift_response);
}

cJSON *transfer_gift_response_convertToJSON(transfer_gift_response_t *transfer_gift_response) {
    cJSON *item = cJSON_CreateObject();

    // transfer_gift_response->ok
    if (!transfer_gift_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", transfer_gift_response->ok) == NULL) {
    goto fail; //Bool
    }


    // transfer_gift_response->result
    if (!transfer_gift_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", transfer_gift_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

transfer_gift_response_t *transfer_gift_response_parseFromJSON(cJSON *transfer_gift_responseJSON){

    transfer_gift_response_t *transfer_gift_response_local_var = NULL;

    // transfer_gift_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(transfer_gift_responseJSON, "ok");
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

    // transfer_gift_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(transfer_gift_responseJSON, "result");
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


    transfer_gift_response_local_var = transfer_gift_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return transfer_gift_response_local_var;
end:
    return NULL;

}
