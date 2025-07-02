#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "leave_chat_response.h"



static leave_chat_response_t *leave_chat_response_create_internal(
    int ok,
    int result
    ) {
    leave_chat_response_t *leave_chat_response_local_var = malloc(sizeof(leave_chat_response_t));
    if (!leave_chat_response_local_var) {
        return NULL;
    }
    leave_chat_response_local_var->ok = ok;
    leave_chat_response_local_var->result = result;

    leave_chat_response_local_var->_library_owned = 1;
    return leave_chat_response_local_var;
}

__attribute__((deprecated)) leave_chat_response_t *leave_chat_response_create(
    int ok,
    int result
    ) {
    return leave_chat_response_create_internal (
        ok,
        result
        );
}

void leave_chat_response_free(leave_chat_response_t *leave_chat_response) {
    if(NULL == leave_chat_response){
        return ;
    }
    if(leave_chat_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "leave_chat_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(leave_chat_response);
}

cJSON *leave_chat_response_convertToJSON(leave_chat_response_t *leave_chat_response) {
    cJSON *item = cJSON_CreateObject();

    // leave_chat_response->ok
    if (!leave_chat_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", leave_chat_response->ok) == NULL) {
    goto fail; //Bool
    }


    // leave_chat_response->result
    if (!leave_chat_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", leave_chat_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

leave_chat_response_t *leave_chat_response_parseFromJSON(cJSON *leave_chat_responseJSON){

    leave_chat_response_t *leave_chat_response_local_var = NULL;

    // leave_chat_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(leave_chat_responseJSON, "ok");
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

    // leave_chat_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(leave_chat_responseJSON, "result");
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


    leave_chat_response_local_var = leave_chat_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return leave_chat_response_local_var;
end:
    return NULL;

}
