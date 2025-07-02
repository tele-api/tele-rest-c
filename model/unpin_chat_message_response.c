#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unpin_chat_message_response.h"



static unpin_chat_message_response_t *unpin_chat_message_response_create_internal(
    int ok,
    int result
    ) {
    unpin_chat_message_response_t *unpin_chat_message_response_local_var = malloc(sizeof(unpin_chat_message_response_t));
    if (!unpin_chat_message_response_local_var) {
        return NULL;
    }
    unpin_chat_message_response_local_var->ok = ok;
    unpin_chat_message_response_local_var->result = result;

    unpin_chat_message_response_local_var->_library_owned = 1;
    return unpin_chat_message_response_local_var;
}

__attribute__((deprecated)) unpin_chat_message_response_t *unpin_chat_message_response_create(
    int ok,
    int result
    ) {
    return unpin_chat_message_response_create_internal (
        ok,
        result
        );
}

void unpin_chat_message_response_free(unpin_chat_message_response_t *unpin_chat_message_response) {
    if(NULL == unpin_chat_message_response){
        return ;
    }
    if(unpin_chat_message_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "unpin_chat_message_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(unpin_chat_message_response);
}

cJSON *unpin_chat_message_response_convertToJSON(unpin_chat_message_response_t *unpin_chat_message_response) {
    cJSON *item = cJSON_CreateObject();

    // unpin_chat_message_response->ok
    if (!unpin_chat_message_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", unpin_chat_message_response->ok) == NULL) {
    goto fail; //Bool
    }


    // unpin_chat_message_response->result
    if (!unpin_chat_message_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", unpin_chat_message_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

unpin_chat_message_response_t *unpin_chat_message_response_parseFromJSON(cJSON *unpin_chat_message_responseJSON){

    unpin_chat_message_response_t *unpin_chat_message_response_local_var = NULL;

    // unpin_chat_message_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(unpin_chat_message_responseJSON, "ok");
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

    // unpin_chat_message_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(unpin_chat_message_responseJSON, "result");
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


    unpin_chat_message_response_local_var = unpin_chat_message_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return unpin_chat_message_response_local_var;
end:
    return NULL;

}
