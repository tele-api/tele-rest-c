#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_document_response.h"



static send_document_response_t *send_document_response_create_internal(
    int ok,
    message_t *result
    ) {
    send_document_response_t *send_document_response_local_var = malloc(sizeof(send_document_response_t));
    if (!send_document_response_local_var) {
        return NULL;
    }
    send_document_response_local_var->ok = ok;
    send_document_response_local_var->result = result;

    send_document_response_local_var->_library_owned = 1;
    return send_document_response_local_var;
}

__attribute__((deprecated)) send_document_response_t *send_document_response_create(
    int ok,
    message_t *result
    ) {
    return send_document_response_create_internal (
        ok,
        result
        );
}

void send_document_response_free(send_document_response_t *send_document_response) {
    if(NULL == send_document_response){
        return ;
    }
    if(send_document_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_document_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (send_document_response->result) {
        message_free(send_document_response->result);
        send_document_response->result = NULL;
    }
    free(send_document_response);
}

cJSON *send_document_response_convertToJSON(send_document_response_t *send_document_response) {
    cJSON *item = cJSON_CreateObject();

    // send_document_response->ok
    if (!send_document_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", send_document_response->ok) == NULL) {
    goto fail; //Bool
    }


    // send_document_response->result
    if (!send_document_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = message_convertToJSON(send_document_response->result);
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

send_document_response_t *send_document_response_parseFromJSON(cJSON *send_document_responseJSON){

    send_document_response_t *send_document_response_local_var = NULL;

    // define the local variable for send_document_response->result
    message_t *result_local_nonprim = NULL;

    // send_document_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(send_document_responseJSON, "ok");
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

    // send_document_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(send_document_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = message_parseFromJSON(result); //nonprimitive


    send_document_response_local_var = send_document_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return send_document_response_local_var;
end:
    if (result_local_nonprim) {
        message_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
