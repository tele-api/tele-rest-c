#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_webhook_info_response.h"



static get_webhook_info_response_t *get_webhook_info_response_create_internal(
    int ok,
    webhook_info_t *result
    ) {
    get_webhook_info_response_t *get_webhook_info_response_local_var = malloc(sizeof(get_webhook_info_response_t));
    if (!get_webhook_info_response_local_var) {
        return NULL;
    }
    get_webhook_info_response_local_var->ok = ok;
    get_webhook_info_response_local_var->result = result;

    get_webhook_info_response_local_var->_library_owned = 1;
    return get_webhook_info_response_local_var;
}

__attribute__((deprecated)) get_webhook_info_response_t *get_webhook_info_response_create(
    int ok,
    webhook_info_t *result
    ) {
    return get_webhook_info_response_create_internal (
        ok,
        result
        );
}

void get_webhook_info_response_free(get_webhook_info_response_t *get_webhook_info_response) {
    if(NULL == get_webhook_info_response){
        return ;
    }
    if(get_webhook_info_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_webhook_info_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_webhook_info_response->result) {
        webhook_info_free(get_webhook_info_response->result);
        get_webhook_info_response->result = NULL;
    }
    free(get_webhook_info_response);
}

cJSON *get_webhook_info_response_convertToJSON(get_webhook_info_response_t *get_webhook_info_response) {
    cJSON *item = cJSON_CreateObject();

    // get_webhook_info_response->ok
    if (!get_webhook_info_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", get_webhook_info_response->ok) == NULL) {
    goto fail; //Bool
    }


    // get_webhook_info_response->result
    if (!get_webhook_info_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = webhook_info_convertToJSON(get_webhook_info_response->result);
    if(result_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "result", result_local_JSON);
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

get_webhook_info_response_t *get_webhook_info_response_parseFromJSON(cJSON *get_webhook_info_responseJSON){

    get_webhook_info_response_t *get_webhook_info_response_local_var = NULL;

    // define the local variable for get_webhook_info_response->result
    webhook_info_t *result_local_nonprim = NULL;

    // get_webhook_info_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(get_webhook_info_responseJSON, "ok");
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

    // get_webhook_info_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(get_webhook_info_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = webhook_info_parseFromJSON(result); //nonprimitive


    get_webhook_info_response_local_var = get_webhook_info_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return get_webhook_info_response_local_var;
end:
    if (result_local_nonprim) {
        webhook_info_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
