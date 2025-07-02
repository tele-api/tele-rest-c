#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "restrict_chat_member_response.h"



static restrict_chat_member_response_t *restrict_chat_member_response_create_internal(
    int ok,
    int result
    ) {
    restrict_chat_member_response_t *restrict_chat_member_response_local_var = malloc(sizeof(restrict_chat_member_response_t));
    if (!restrict_chat_member_response_local_var) {
        return NULL;
    }
    restrict_chat_member_response_local_var->ok = ok;
    restrict_chat_member_response_local_var->result = result;

    restrict_chat_member_response_local_var->_library_owned = 1;
    return restrict_chat_member_response_local_var;
}

__attribute__((deprecated)) restrict_chat_member_response_t *restrict_chat_member_response_create(
    int ok,
    int result
    ) {
    return restrict_chat_member_response_create_internal (
        ok,
        result
        );
}

void restrict_chat_member_response_free(restrict_chat_member_response_t *restrict_chat_member_response) {
    if(NULL == restrict_chat_member_response){
        return ;
    }
    if(restrict_chat_member_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "restrict_chat_member_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(restrict_chat_member_response);
}

cJSON *restrict_chat_member_response_convertToJSON(restrict_chat_member_response_t *restrict_chat_member_response) {
    cJSON *item = cJSON_CreateObject();

    // restrict_chat_member_response->ok
    if (!restrict_chat_member_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", restrict_chat_member_response->ok) == NULL) {
    goto fail; //Bool
    }


    // restrict_chat_member_response->result
    if (!restrict_chat_member_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", restrict_chat_member_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

restrict_chat_member_response_t *restrict_chat_member_response_parseFromJSON(cJSON *restrict_chat_member_responseJSON){

    restrict_chat_member_response_t *restrict_chat_member_response_local_var = NULL;

    // restrict_chat_member_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(restrict_chat_member_responseJSON, "ok");
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

    // restrict_chat_member_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(restrict_chat_member_responseJSON, "result");
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


    restrict_chat_member_response_local_var = restrict_chat_member_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return restrict_chat_member_response_local_var;
end:
    return NULL;

}
