#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "approve_chat_join_request_response.h"



static approve_chat_join_request_response_t *approve_chat_join_request_response_create_internal(
    int ok,
    int result
    ) {
    approve_chat_join_request_response_t *approve_chat_join_request_response_local_var = malloc(sizeof(approve_chat_join_request_response_t));
    if (!approve_chat_join_request_response_local_var) {
        return NULL;
    }
    approve_chat_join_request_response_local_var->ok = ok;
    approve_chat_join_request_response_local_var->result = result;

    approve_chat_join_request_response_local_var->_library_owned = 1;
    return approve_chat_join_request_response_local_var;
}

__attribute__((deprecated)) approve_chat_join_request_response_t *approve_chat_join_request_response_create(
    int ok,
    int result
    ) {
    return approve_chat_join_request_response_create_internal (
        ok,
        result
        );
}

void approve_chat_join_request_response_free(approve_chat_join_request_response_t *approve_chat_join_request_response) {
    if(NULL == approve_chat_join_request_response){
        return ;
    }
    if(approve_chat_join_request_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "approve_chat_join_request_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(approve_chat_join_request_response);
}

cJSON *approve_chat_join_request_response_convertToJSON(approve_chat_join_request_response_t *approve_chat_join_request_response) {
    cJSON *item = cJSON_CreateObject();

    // approve_chat_join_request_response->ok
    if (!approve_chat_join_request_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", approve_chat_join_request_response->ok) == NULL) {
    goto fail; //Bool
    }


    // approve_chat_join_request_response->result
    if (!approve_chat_join_request_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", approve_chat_join_request_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

approve_chat_join_request_response_t *approve_chat_join_request_response_parseFromJSON(cJSON *approve_chat_join_request_responseJSON){

    approve_chat_join_request_response_t *approve_chat_join_request_response_local_var = NULL;

    // approve_chat_join_request_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(approve_chat_join_request_responseJSON, "ok");
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

    // approve_chat_join_request_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(approve_chat_join_request_responseJSON, "result");
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


    approve_chat_join_request_response_local_var = approve_chat_join_request_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return approve_chat_join_request_response_local_var;
end:
    return NULL;

}
