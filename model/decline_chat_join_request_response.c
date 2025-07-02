#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "decline_chat_join_request_response.h"



static decline_chat_join_request_response_t *decline_chat_join_request_response_create_internal(
    int ok,
    int result
    ) {
    decline_chat_join_request_response_t *decline_chat_join_request_response_local_var = malloc(sizeof(decline_chat_join_request_response_t));
    if (!decline_chat_join_request_response_local_var) {
        return NULL;
    }
    decline_chat_join_request_response_local_var->ok = ok;
    decline_chat_join_request_response_local_var->result = result;

    decline_chat_join_request_response_local_var->_library_owned = 1;
    return decline_chat_join_request_response_local_var;
}

__attribute__((deprecated)) decline_chat_join_request_response_t *decline_chat_join_request_response_create(
    int ok,
    int result
    ) {
    return decline_chat_join_request_response_create_internal (
        ok,
        result
        );
}

void decline_chat_join_request_response_free(decline_chat_join_request_response_t *decline_chat_join_request_response) {
    if(NULL == decline_chat_join_request_response){
        return ;
    }
    if(decline_chat_join_request_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "decline_chat_join_request_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(decline_chat_join_request_response);
}

cJSON *decline_chat_join_request_response_convertToJSON(decline_chat_join_request_response_t *decline_chat_join_request_response) {
    cJSON *item = cJSON_CreateObject();

    // decline_chat_join_request_response->ok
    if (!decline_chat_join_request_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", decline_chat_join_request_response->ok) == NULL) {
    goto fail; //Bool
    }


    // decline_chat_join_request_response->result
    if (!decline_chat_join_request_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", decline_chat_join_request_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

decline_chat_join_request_response_t *decline_chat_join_request_response_parseFromJSON(cJSON *decline_chat_join_request_responseJSON){

    decline_chat_join_request_response_t *decline_chat_join_request_response_local_var = NULL;

    // decline_chat_join_request_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(decline_chat_join_request_responseJSON, "ok");
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

    // decline_chat_join_request_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(decline_chat_join_request_responseJSON, "result");
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


    decline_chat_join_request_response_local_var = decline_chat_join_request_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return decline_chat_join_request_response_local_var;
end:
    return NULL;

}
