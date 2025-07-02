#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "remove_chat_verification_response.h"



static remove_chat_verification_response_t *remove_chat_verification_response_create_internal(
    int ok,
    int result
    ) {
    remove_chat_verification_response_t *remove_chat_verification_response_local_var = malloc(sizeof(remove_chat_verification_response_t));
    if (!remove_chat_verification_response_local_var) {
        return NULL;
    }
    remove_chat_verification_response_local_var->ok = ok;
    remove_chat_verification_response_local_var->result = result;

    remove_chat_verification_response_local_var->_library_owned = 1;
    return remove_chat_verification_response_local_var;
}

__attribute__((deprecated)) remove_chat_verification_response_t *remove_chat_verification_response_create(
    int ok,
    int result
    ) {
    return remove_chat_verification_response_create_internal (
        ok,
        result
        );
}

void remove_chat_verification_response_free(remove_chat_verification_response_t *remove_chat_verification_response) {
    if(NULL == remove_chat_verification_response){
        return ;
    }
    if(remove_chat_verification_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "remove_chat_verification_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(remove_chat_verification_response);
}

cJSON *remove_chat_verification_response_convertToJSON(remove_chat_verification_response_t *remove_chat_verification_response) {
    cJSON *item = cJSON_CreateObject();

    // remove_chat_verification_response->ok
    if (!remove_chat_verification_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", remove_chat_verification_response->ok) == NULL) {
    goto fail; //Bool
    }


    // remove_chat_verification_response->result
    if (!remove_chat_verification_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", remove_chat_verification_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

remove_chat_verification_response_t *remove_chat_verification_response_parseFromJSON(cJSON *remove_chat_verification_responseJSON){

    remove_chat_verification_response_t *remove_chat_verification_response_local_var = NULL;

    // remove_chat_verification_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(remove_chat_verification_responseJSON, "ok");
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

    // remove_chat_verification_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(remove_chat_verification_responseJSON, "result");
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


    remove_chat_verification_response_local_var = remove_chat_verification_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return remove_chat_verification_response_local_var;
end:
    return NULL;

}
