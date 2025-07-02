#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unban_chat_sender_chat_response.h"



static unban_chat_sender_chat_response_t *unban_chat_sender_chat_response_create_internal(
    int ok,
    int result
    ) {
    unban_chat_sender_chat_response_t *unban_chat_sender_chat_response_local_var = malloc(sizeof(unban_chat_sender_chat_response_t));
    if (!unban_chat_sender_chat_response_local_var) {
        return NULL;
    }
    unban_chat_sender_chat_response_local_var->ok = ok;
    unban_chat_sender_chat_response_local_var->result = result;

    unban_chat_sender_chat_response_local_var->_library_owned = 1;
    return unban_chat_sender_chat_response_local_var;
}

__attribute__((deprecated)) unban_chat_sender_chat_response_t *unban_chat_sender_chat_response_create(
    int ok,
    int result
    ) {
    return unban_chat_sender_chat_response_create_internal (
        ok,
        result
        );
}

void unban_chat_sender_chat_response_free(unban_chat_sender_chat_response_t *unban_chat_sender_chat_response) {
    if(NULL == unban_chat_sender_chat_response){
        return ;
    }
    if(unban_chat_sender_chat_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "unban_chat_sender_chat_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(unban_chat_sender_chat_response);
}

cJSON *unban_chat_sender_chat_response_convertToJSON(unban_chat_sender_chat_response_t *unban_chat_sender_chat_response) {
    cJSON *item = cJSON_CreateObject();

    // unban_chat_sender_chat_response->ok
    if (!unban_chat_sender_chat_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", unban_chat_sender_chat_response->ok) == NULL) {
    goto fail; //Bool
    }


    // unban_chat_sender_chat_response->result
    if (!unban_chat_sender_chat_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", unban_chat_sender_chat_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

unban_chat_sender_chat_response_t *unban_chat_sender_chat_response_parseFromJSON(cJSON *unban_chat_sender_chat_responseJSON){

    unban_chat_sender_chat_response_t *unban_chat_sender_chat_response_local_var = NULL;

    // unban_chat_sender_chat_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(unban_chat_sender_chat_responseJSON, "ok");
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

    // unban_chat_sender_chat_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(unban_chat_sender_chat_responseJSON, "result");
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


    unban_chat_sender_chat_response_local_var = unban_chat_sender_chat_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return unban_chat_sender_chat_response_local_var;
end:
    return NULL;

}
