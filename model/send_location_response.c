#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_location_response.h"



static send_location_response_t *send_location_response_create_internal(
    int ok,
    message_t *result
    ) {
    send_location_response_t *send_location_response_local_var = malloc(sizeof(send_location_response_t));
    if (!send_location_response_local_var) {
        return NULL;
    }
    send_location_response_local_var->ok = ok;
    send_location_response_local_var->result = result;

    send_location_response_local_var->_library_owned = 1;
    return send_location_response_local_var;
}

__attribute__((deprecated)) send_location_response_t *send_location_response_create(
    int ok,
    message_t *result
    ) {
    return send_location_response_create_internal (
        ok,
        result
        );
}

void send_location_response_free(send_location_response_t *send_location_response) {
    if(NULL == send_location_response){
        return ;
    }
    if(send_location_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_location_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (send_location_response->result) {
        message_free(send_location_response->result);
        send_location_response->result = NULL;
    }
    free(send_location_response);
}

cJSON *send_location_response_convertToJSON(send_location_response_t *send_location_response) {
    cJSON *item = cJSON_CreateObject();

    // send_location_response->ok
    if (!send_location_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", send_location_response->ok) == NULL) {
    goto fail; //Bool
    }


    // send_location_response->result
    if (!send_location_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = message_convertToJSON(send_location_response->result);
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

send_location_response_t *send_location_response_parseFromJSON(cJSON *send_location_responseJSON){

    send_location_response_t *send_location_response_local_var = NULL;

    // define the local variable for send_location_response->result
    message_t *result_local_nonprim = NULL;

    // send_location_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(send_location_responseJSON, "ok");
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

    // send_location_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(send_location_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = message_parseFromJSON(result); //nonprimitive


    send_location_response_local_var = send_location_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return send_location_response_local_var;
end:
    if (result_local_nonprim) {
        message_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
