#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "edit_chat_subscription_invite_link_response.h"



static edit_chat_subscription_invite_link_response_t *edit_chat_subscription_invite_link_response_create_internal(
    int ok,
    chat_invite_link_t *result
    ) {
    edit_chat_subscription_invite_link_response_t *edit_chat_subscription_invite_link_response_local_var = malloc(sizeof(edit_chat_subscription_invite_link_response_t));
    if (!edit_chat_subscription_invite_link_response_local_var) {
        return NULL;
    }
    edit_chat_subscription_invite_link_response_local_var->ok = ok;
    edit_chat_subscription_invite_link_response_local_var->result = result;

    edit_chat_subscription_invite_link_response_local_var->_library_owned = 1;
    return edit_chat_subscription_invite_link_response_local_var;
}

__attribute__((deprecated)) edit_chat_subscription_invite_link_response_t *edit_chat_subscription_invite_link_response_create(
    int ok,
    chat_invite_link_t *result
    ) {
    return edit_chat_subscription_invite_link_response_create_internal (
        ok,
        result
        );
}

void edit_chat_subscription_invite_link_response_free(edit_chat_subscription_invite_link_response_t *edit_chat_subscription_invite_link_response) {
    if(NULL == edit_chat_subscription_invite_link_response){
        return ;
    }
    if(edit_chat_subscription_invite_link_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "edit_chat_subscription_invite_link_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (edit_chat_subscription_invite_link_response->result) {
        chat_invite_link_free(edit_chat_subscription_invite_link_response->result);
        edit_chat_subscription_invite_link_response->result = NULL;
    }
    free(edit_chat_subscription_invite_link_response);
}

cJSON *edit_chat_subscription_invite_link_response_convertToJSON(edit_chat_subscription_invite_link_response_t *edit_chat_subscription_invite_link_response) {
    cJSON *item = cJSON_CreateObject();

    // edit_chat_subscription_invite_link_response->ok
    if (!edit_chat_subscription_invite_link_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", edit_chat_subscription_invite_link_response->ok) == NULL) {
    goto fail; //Bool
    }


    // edit_chat_subscription_invite_link_response->result
    if (!edit_chat_subscription_invite_link_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = chat_invite_link_convertToJSON(edit_chat_subscription_invite_link_response->result);
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

edit_chat_subscription_invite_link_response_t *edit_chat_subscription_invite_link_response_parseFromJSON(cJSON *edit_chat_subscription_invite_link_responseJSON){

    edit_chat_subscription_invite_link_response_t *edit_chat_subscription_invite_link_response_local_var = NULL;

    // define the local variable for edit_chat_subscription_invite_link_response->result
    chat_invite_link_t *result_local_nonprim = NULL;

    // edit_chat_subscription_invite_link_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(edit_chat_subscription_invite_link_responseJSON, "ok");
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

    // edit_chat_subscription_invite_link_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(edit_chat_subscription_invite_link_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = chat_invite_link_parseFromJSON(result); //nonprimitive


    edit_chat_subscription_invite_link_response_local_var = edit_chat_subscription_invite_link_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return edit_chat_subscription_invite_link_response_local_var;
end:
    if (result_local_nonprim) {
        chat_invite_link_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
