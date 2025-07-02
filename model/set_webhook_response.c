#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_webhook_response.h"



static set_webhook_response_t *set_webhook_response_create_internal(
    int ok,
    int result
    ) {
    set_webhook_response_t *set_webhook_response_local_var = malloc(sizeof(set_webhook_response_t));
    if (!set_webhook_response_local_var) {
        return NULL;
    }
    set_webhook_response_local_var->ok = ok;
    set_webhook_response_local_var->result = result;

    set_webhook_response_local_var->_library_owned = 1;
    return set_webhook_response_local_var;
}

__attribute__((deprecated)) set_webhook_response_t *set_webhook_response_create(
    int ok,
    int result
    ) {
    return set_webhook_response_create_internal (
        ok,
        result
        );
}

void set_webhook_response_free(set_webhook_response_t *set_webhook_response) {
    if(NULL == set_webhook_response){
        return ;
    }
    if(set_webhook_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_webhook_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(set_webhook_response);
}

cJSON *set_webhook_response_convertToJSON(set_webhook_response_t *set_webhook_response) {
    cJSON *item = cJSON_CreateObject();

    // set_webhook_response->ok
    if (!set_webhook_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", set_webhook_response->ok) == NULL) {
    goto fail; //Bool
    }


    // set_webhook_response->result
    if (!set_webhook_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", set_webhook_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

set_webhook_response_t *set_webhook_response_parseFromJSON(cJSON *set_webhook_responseJSON){

    set_webhook_response_t *set_webhook_response_local_var = NULL;

    // set_webhook_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(set_webhook_responseJSON, "ok");
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

    // set_webhook_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(set_webhook_responseJSON, "result");
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


    set_webhook_response_local_var = set_webhook_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return set_webhook_response_local_var;
end:
    return NULL;

}
