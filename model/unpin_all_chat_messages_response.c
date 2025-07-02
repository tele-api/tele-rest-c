#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unpin_all_chat_messages_response.h"



static unpin_all_chat_messages_response_t *unpin_all_chat_messages_response_create_internal(
    int ok,
    int result
    ) {
    unpin_all_chat_messages_response_t *unpin_all_chat_messages_response_local_var = malloc(sizeof(unpin_all_chat_messages_response_t));
    if (!unpin_all_chat_messages_response_local_var) {
        return NULL;
    }
    unpin_all_chat_messages_response_local_var->ok = ok;
    unpin_all_chat_messages_response_local_var->result = result;

    unpin_all_chat_messages_response_local_var->_library_owned = 1;
    return unpin_all_chat_messages_response_local_var;
}

__attribute__((deprecated)) unpin_all_chat_messages_response_t *unpin_all_chat_messages_response_create(
    int ok,
    int result
    ) {
    return unpin_all_chat_messages_response_create_internal (
        ok,
        result
        );
}

void unpin_all_chat_messages_response_free(unpin_all_chat_messages_response_t *unpin_all_chat_messages_response) {
    if(NULL == unpin_all_chat_messages_response){
        return ;
    }
    if(unpin_all_chat_messages_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "unpin_all_chat_messages_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(unpin_all_chat_messages_response);
}

cJSON *unpin_all_chat_messages_response_convertToJSON(unpin_all_chat_messages_response_t *unpin_all_chat_messages_response) {
    cJSON *item = cJSON_CreateObject();

    // unpin_all_chat_messages_response->ok
    if (!unpin_all_chat_messages_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", unpin_all_chat_messages_response->ok) == NULL) {
    goto fail; //Bool
    }


    // unpin_all_chat_messages_response->result
    if (!unpin_all_chat_messages_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", unpin_all_chat_messages_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

unpin_all_chat_messages_response_t *unpin_all_chat_messages_response_parseFromJSON(cJSON *unpin_all_chat_messages_responseJSON){

    unpin_all_chat_messages_response_t *unpin_all_chat_messages_response_local_var = NULL;

    // unpin_all_chat_messages_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(unpin_all_chat_messages_responseJSON, "ok");
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

    // unpin_all_chat_messages_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(unpin_all_chat_messages_responseJSON, "result");
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


    unpin_all_chat_messages_response_local_var = unpin_all_chat_messages_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return unpin_all_chat_messages_response_local_var;
end:
    return NULL;

}
