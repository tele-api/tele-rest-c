#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "promote_chat_member_response.h"



static promote_chat_member_response_t *promote_chat_member_response_create_internal(
    int ok,
    int result
    ) {
    promote_chat_member_response_t *promote_chat_member_response_local_var = malloc(sizeof(promote_chat_member_response_t));
    if (!promote_chat_member_response_local_var) {
        return NULL;
    }
    promote_chat_member_response_local_var->ok = ok;
    promote_chat_member_response_local_var->result = result;

    promote_chat_member_response_local_var->_library_owned = 1;
    return promote_chat_member_response_local_var;
}

__attribute__((deprecated)) promote_chat_member_response_t *promote_chat_member_response_create(
    int ok,
    int result
    ) {
    return promote_chat_member_response_create_internal (
        ok,
        result
        );
}

void promote_chat_member_response_free(promote_chat_member_response_t *promote_chat_member_response) {
    if(NULL == promote_chat_member_response){
        return ;
    }
    if(promote_chat_member_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "promote_chat_member_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(promote_chat_member_response);
}

cJSON *promote_chat_member_response_convertToJSON(promote_chat_member_response_t *promote_chat_member_response) {
    cJSON *item = cJSON_CreateObject();

    // promote_chat_member_response->ok
    if (!promote_chat_member_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", promote_chat_member_response->ok) == NULL) {
    goto fail; //Bool
    }


    // promote_chat_member_response->result
    if (!promote_chat_member_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", promote_chat_member_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

promote_chat_member_response_t *promote_chat_member_response_parseFromJSON(cJSON *promote_chat_member_responseJSON){

    promote_chat_member_response_t *promote_chat_member_response_local_var = NULL;

    // promote_chat_member_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(promote_chat_member_responseJSON, "ok");
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

    // promote_chat_member_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(promote_chat_member_responseJSON, "result");
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


    promote_chat_member_response_local_var = promote_chat_member_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return promote_chat_member_response_local_var;
end:
    return NULL;

}
