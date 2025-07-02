#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_audio_response.h"



static send_audio_response_t *send_audio_response_create_internal(
    int ok,
    message_t *result
    ) {
    send_audio_response_t *send_audio_response_local_var = malloc(sizeof(send_audio_response_t));
    if (!send_audio_response_local_var) {
        return NULL;
    }
    send_audio_response_local_var->ok = ok;
    send_audio_response_local_var->result = result;

    send_audio_response_local_var->_library_owned = 1;
    return send_audio_response_local_var;
}

__attribute__((deprecated)) send_audio_response_t *send_audio_response_create(
    int ok,
    message_t *result
    ) {
    return send_audio_response_create_internal (
        ok,
        result
        );
}

void send_audio_response_free(send_audio_response_t *send_audio_response) {
    if(NULL == send_audio_response){
        return ;
    }
    if(send_audio_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_audio_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (send_audio_response->result) {
        message_free(send_audio_response->result);
        send_audio_response->result = NULL;
    }
    free(send_audio_response);
}

cJSON *send_audio_response_convertToJSON(send_audio_response_t *send_audio_response) {
    cJSON *item = cJSON_CreateObject();

    // send_audio_response->ok
    if (!send_audio_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", send_audio_response->ok) == NULL) {
    goto fail; //Bool
    }


    // send_audio_response->result
    if (!send_audio_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = message_convertToJSON(send_audio_response->result);
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

send_audio_response_t *send_audio_response_parseFromJSON(cJSON *send_audio_responseJSON){

    send_audio_response_t *send_audio_response_local_var = NULL;

    // define the local variable for send_audio_response->result
    message_t *result_local_nonprim = NULL;

    // send_audio_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(send_audio_responseJSON, "ok");
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

    // send_audio_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(send_audio_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = message_parseFromJSON(result); //nonprimitive


    send_audio_response_local_var = send_audio_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return send_audio_response_local_var;
end:
    if (result_local_nonprim) {
        message_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
