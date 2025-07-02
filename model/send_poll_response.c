#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_poll_response.h"



static send_poll_response_t *send_poll_response_create_internal(
    int ok,
    message_t *result
    ) {
    send_poll_response_t *send_poll_response_local_var = malloc(sizeof(send_poll_response_t));
    if (!send_poll_response_local_var) {
        return NULL;
    }
    send_poll_response_local_var->ok = ok;
    send_poll_response_local_var->result = result;

    send_poll_response_local_var->_library_owned = 1;
    return send_poll_response_local_var;
}

__attribute__((deprecated)) send_poll_response_t *send_poll_response_create(
    int ok,
    message_t *result
    ) {
    return send_poll_response_create_internal (
        ok,
        result
        );
}

void send_poll_response_free(send_poll_response_t *send_poll_response) {
    if(NULL == send_poll_response){
        return ;
    }
    if(send_poll_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_poll_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (send_poll_response->result) {
        message_free(send_poll_response->result);
        send_poll_response->result = NULL;
    }
    free(send_poll_response);
}

cJSON *send_poll_response_convertToJSON(send_poll_response_t *send_poll_response) {
    cJSON *item = cJSON_CreateObject();

    // send_poll_response->ok
    if (!send_poll_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", send_poll_response->ok) == NULL) {
    goto fail; //Bool
    }


    // send_poll_response->result
    if (!send_poll_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = message_convertToJSON(send_poll_response->result);
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

send_poll_response_t *send_poll_response_parseFromJSON(cJSON *send_poll_responseJSON){

    send_poll_response_t *send_poll_response_local_var = NULL;

    // define the local variable for send_poll_response->result
    message_t *result_local_nonprim = NULL;

    // send_poll_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(send_poll_responseJSON, "ok");
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

    // send_poll_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(send_poll_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = message_parseFromJSON(result); //nonprimitive


    send_poll_response_local_var = send_poll_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return send_poll_response_local_var;
end:
    if (result_local_nonprim) {
        message_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
