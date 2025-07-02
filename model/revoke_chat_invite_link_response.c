#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "revoke_chat_invite_link_response.h"



static revoke_chat_invite_link_response_t *revoke_chat_invite_link_response_create_internal(
    int ok,
    chat_invite_link_t *result
    ) {
    revoke_chat_invite_link_response_t *revoke_chat_invite_link_response_local_var = malloc(sizeof(revoke_chat_invite_link_response_t));
    if (!revoke_chat_invite_link_response_local_var) {
        return NULL;
    }
    revoke_chat_invite_link_response_local_var->ok = ok;
    revoke_chat_invite_link_response_local_var->result = result;

    revoke_chat_invite_link_response_local_var->_library_owned = 1;
    return revoke_chat_invite_link_response_local_var;
}

__attribute__((deprecated)) revoke_chat_invite_link_response_t *revoke_chat_invite_link_response_create(
    int ok,
    chat_invite_link_t *result
    ) {
    return revoke_chat_invite_link_response_create_internal (
        ok,
        result
        );
}

void revoke_chat_invite_link_response_free(revoke_chat_invite_link_response_t *revoke_chat_invite_link_response) {
    if(NULL == revoke_chat_invite_link_response){
        return ;
    }
    if(revoke_chat_invite_link_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "revoke_chat_invite_link_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (revoke_chat_invite_link_response->result) {
        chat_invite_link_free(revoke_chat_invite_link_response->result);
        revoke_chat_invite_link_response->result = NULL;
    }
    free(revoke_chat_invite_link_response);
}

cJSON *revoke_chat_invite_link_response_convertToJSON(revoke_chat_invite_link_response_t *revoke_chat_invite_link_response) {
    cJSON *item = cJSON_CreateObject();

    // revoke_chat_invite_link_response->ok
    if (!revoke_chat_invite_link_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", revoke_chat_invite_link_response->ok) == NULL) {
    goto fail; //Bool
    }


    // revoke_chat_invite_link_response->result
    if (!revoke_chat_invite_link_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = chat_invite_link_convertToJSON(revoke_chat_invite_link_response->result);
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

revoke_chat_invite_link_response_t *revoke_chat_invite_link_response_parseFromJSON(cJSON *revoke_chat_invite_link_responseJSON){

    revoke_chat_invite_link_response_t *revoke_chat_invite_link_response_local_var = NULL;

    // define the local variable for revoke_chat_invite_link_response->result
    chat_invite_link_t *result_local_nonprim = NULL;

    // revoke_chat_invite_link_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(revoke_chat_invite_link_responseJSON, "ok");
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

    // revoke_chat_invite_link_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(revoke_chat_invite_link_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = chat_invite_link_parseFromJSON(result); //nonprimitive


    revoke_chat_invite_link_response_local_var = revoke_chat_invite_link_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return revoke_chat_invite_link_response_local_var;
end:
    if (result_local_nonprim) {
        chat_invite_link_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
