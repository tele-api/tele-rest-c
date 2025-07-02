#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "forward_message_response.h"



static forward_message_response_t *forward_message_response_create_internal(
    int ok,
    message_t *result
    ) {
    forward_message_response_t *forward_message_response_local_var = malloc(sizeof(forward_message_response_t));
    if (!forward_message_response_local_var) {
        return NULL;
    }
    forward_message_response_local_var->ok = ok;
    forward_message_response_local_var->result = result;

    forward_message_response_local_var->_library_owned = 1;
    return forward_message_response_local_var;
}

__attribute__((deprecated)) forward_message_response_t *forward_message_response_create(
    int ok,
    message_t *result
    ) {
    return forward_message_response_create_internal (
        ok,
        result
        );
}

void forward_message_response_free(forward_message_response_t *forward_message_response) {
    if(NULL == forward_message_response){
        return ;
    }
    if(forward_message_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "forward_message_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (forward_message_response->result) {
        message_free(forward_message_response->result);
        forward_message_response->result = NULL;
    }
    free(forward_message_response);
}

cJSON *forward_message_response_convertToJSON(forward_message_response_t *forward_message_response) {
    cJSON *item = cJSON_CreateObject();

    // forward_message_response->ok
    if (!forward_message_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", forward_message_response->ok) == NULL) {
    goto fail; //Bool
    }


    // forward_message_response->result
    if (!forward_message_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = message_convertToJSON(forward_message_response->result);
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

forward_message_response_t *forward_message_response_parseFromJSON(cJSON *forward_message_responseJSON){

    forward_message_response_t *forward_message_response_local_var = NULL;

    // define the local variable for forward_message_response->result
    message_t *result_local_nonprim = NULL;

    // forward_message_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(forward_message_responseJSON, "ok");
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

    // forward_message_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(forward_message_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = message_parseFromJSON(result); //nonprimitive


    forward_message_response_local_var = forward_message_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return forward_message_response_local_var;
end:
    if (result_local_nonprim) {
        message_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
