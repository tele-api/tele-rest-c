#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stop_message_live_location_response.h"



static stop_message_live_location_response_t *stop_message_live_location_response_create_internal(
    int ok,
    edit_message_text_response_result_t *result
    ) {
    stop_message_live_location_response_t *stop_message_live_location_response_local_var = malloc(sizeof(stop_message_live_location_response_t));
    if (!stop_message_live_location_response_local_var) {
        return NULL;
    }
    stop_message_live_location_response_local_var->ok = ok;
    stop_message_live_location_response_local_var->result = result;

    stop_message_live_location_response_local_var->_library_owned = 1;
    return stop_message_live_location_response_local_var;
}

__attribute__((deprecated)) stop_message_live_location_response_t *stop_message_live_location_response_create(
    int ok,
    edit_message_text_response_result_t *result
    ) {
    return stop_message_live_location_response_create_internal (
        ok,
        result
        );
}

void stop_message_live_location_response_free(stop_message_live_location_response_t *stop_message_live_location_response) {
    if(NULL == stop_message_live_location_response){
        return ;
    }
    if(stop_message_live_location_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "stop_message_live_location_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (stop_message_live_location_response->result) {
        edit_message_text_response_result_free(stop_message_live_location_response->result);
        stop_message_live_location_response->result = NULL;
    }
    free(stop_message_live_location_response);
}

cJSON *stop_message_live_location_response_convertToJSON(stop_message_live_location_response_t *stop_message_live_location_response) {
    cJSON *item = cJSON_CreateObject();

    // stop_message_live_location_response->ok
    if (!stop_message_live_location_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", stop_message_live_location_response->ok) == NULL) {
    goto fail; //Bool
    }


    // stop_message_live_location_response->result
    if (!stop_message_live_location_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = edit_message_text_response_result_convertToJSON(stop_message_live_location_response->result);
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

stop_message_live_location_response_t *stop_message_live_location_response_parseFromJSON(cJSON *stop_message_live_location_responseJSON){

    stop_message_live_location_response_t *stop_message_live_location_response_local_var = NULL;

    // define the local variable for stop_message_live_location_response->result
    edit_message_text_response_result_t *result_local_nonprim = NULL;

    // stop_message_live_location_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(stop_message_live_location_responseJSON, "ok");
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

    // stop_message_live_location_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(stop_message_live_location_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = edit_message_text_response_result_parseFromJSON(result); //nonprimitive


    stop_message_live_location_response_local_var = stop_message_live_location_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return stop_message_live_location_response_local_var;
end:
    if (result_local_nonprim) {
        edit_message_text_response_result_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
