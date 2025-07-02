#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_chat_subscription_invite_link_response.h"



static create_chat_subscription_invite_link_response_t *create_chat_subscription_invite_link_response_create_internal(
    int ok,
    chat_invite_link_t *result
    ) {
    create_chat_subscription_invite_link_response_t *create_chat_subscription_invite_link_response_local_var = malloc(sizeof(create_chat_subscription_invite_link_response_t));
    if (!create_chat_subscription_invite_link_response_local_var) {
        return NULL;
    }
    create_chat_subscription_invite_link_response_local_var->ok = ok;
    create_chat_subscription_invite_link_response_local_var->result = result;

    create_chat_subscription_invite_link_response_local_var->_library_owned = 1;
    return create_chat_subscription_invite_link_response_local_var;
}

__attribute__((deprecated)) create_chat_subscription_invite_link_response_t *create_chat_subscription_invite_link_response_create(
    int ok,
    chat_invite_link_t *result
    ) {
    return create_chat_subscription_invite_link_response_create_internal (
        ok,
        result
        );
}

void create_chat_subscription_invite_link_response_free(create_chat_subscription_invite_link_response_t *create_chat_subscription_invite_link_response) {
    if(NULL == create_chat_subscription_invite_link_response){
        return ;
    }
    if(create_chat_subscription_invite_link_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_chat_subscription_invite_link_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_chat_subscription_invite_link_response->result) {
        chat_invite_link_free(create_chat_subscription_invite_link_response->result);
        create_chat_subscription_invite_link_response->result = NULL;
    }
    free(create_chat_subscription_invite_link_response);
}

cJSON *create_chat_subscription_invite_link_response_convertToJSON(create_chat_subscription_invite_link_response_t *create_chat_subscription_invite_link_response) {
    cJSON *item = cJSON_CreateObject();

    // create_chat_subscription_invite_link_response->ok
    if (!create_chat_subscription_invite_link_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", create_chat_subscription_invite_link_response->ok) == NULL) {
    goto fail; //Bool
    }


    // create_chat_subscription_invite_link_response->result
    if (!create_chat_subscription_invite_link_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = chat_invite_link_convertToJSON(create_chat_subscription_invite_link_response->result);
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

create_chat_subscription_invite_link_response_t *create_chat_subscription_invite_link_response_parseFromJSON(cJSON *create_chat_subscription_invite_link_responseJSON){

    create_chat_subscription_invite_link_response_t *create_chat_subscription_invite_link_response_local_var = NULL;

    // define the local variable for create_chat_subscription_invite_link_response->result
    chat_invite_link_t *result_local_nonprim = NULL;

    // create_chat_subscription_invite_link_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(create_chat_subscription_invite_link_responseJSON, "ok");
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

    // create_chat_subscription_invite_link_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(create_chat_subscription_invite_link_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = chat_invite_link_parseFromJSON(result); //nonprimitive


    create_chat_subscription_invite_link_response_local_var = create_chat_subscription_invite_link_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return create_chat_subscription_invite_link_response_local_var;
end:
    if (result_local_nonprim) {
        chat_invite_link_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
