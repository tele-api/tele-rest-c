#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stop_poll_response.h"



static stop_poll_response_t *stop_poll_response_create_internal(
    int ok,
    poll_t *result
    ) {
    stop_poll_response_t *stop_poll_response_local_var = malloc(sizeof(stop_poll_response_t));
    if (!stop_poll_response_local_var) {
        return NULL;
    }
    stop_poll_response_local_var->ok = ok;
    stop_poll_response_local_var->result = result;

    stop_poll_response_local_var->_library_owned = 1;
    return stop_poll_response_local_var;
}

__attribute__((deprecated)) stop_poll_response_t *stop_poll_response_create(
    int ok,
    poll_t *result
    ) {
    return stop_poll_response_create_internal (
        ok,
        result
        );
}

void stop_poll_response_free(stop_poll_response_t *stop_poll_response) {
    if(NULL == stop_poll_response){
        return ;
    }
    if(stop_poll_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "stop_poll_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (stop_poll_response->result) {
        poll_free(stop_poll_response->result);
        stop_poll_response->result = NULL;
    }
    free(stop_poll_response);
}

cJSON *stop_poll_response_convertToJSON(stop_poll_response_t *stop_poll_response) {
    cJSON *item = cJSON_CreateObject();

    // stop_poll_response->ok
    if (!stop_poll_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", stop_poll_response->ok) == NULL) {
    goto fail; //Bool
    }


    // stop_poll_response->result
    if (!stop_poll_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = poll_convertToJSON(stop_poll_response->result);
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

stop_poll_response_t *stop_poll_response_parseFromJSON(cJSON *stop_poll_responseJSON){

    stop_poll_response_t *stop_poll_response_local_var = NULL;

    // define the local variable for stop_poll_response->result
    poll_t *result_local_nonprim = NULL;

    // stop_poll_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(stop_poll_responseJSON, "ok");
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

    // stop_poll_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(stop_poll_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = poll_parseFromJSON(result); //nonprimitive


    stop_poll_response_local_var = stop_poll_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return stop_poll_response_local_var;
end:
    if (result_local_nonprim) {
        poll_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
