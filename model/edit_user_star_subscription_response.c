#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "edit_user_star_subscription_response.h"



static edit_user_star_subscription_response_t *edit_user_star_subscription_response_create_internal(
    int ok,
    int result
    ) {
    edit_user_star_subscription_response_t *edit_user_star_subscription_response_local_var = malloc(sizeof(edit_user_star_subscription_response_t));
    if (!edit_user_star_subscription_response_local_var) {
        return NULL;
    }
    edit_user_star_subscription_response_local_var->ok = ok;
    edit_user_star_subscription_response_local_var->result = result;

    edit_user_star_subscription_response_local_var->_library_owned = 1;
    return edit_user_star_subscription_response_local_var;
}

__attribute__((deprecated)) edit_user_star_subscription_response_t *edit_user_star_subscription_response_create(
    int ok,
    int result
    ) {
    return edit_user_star_subscription_response_create_internal (
        ok,
        result
        );
}

void edit_user_star_subscription_response_free(edit_user_star_subscription_response_t *edit_user_star_subscription_response) {
    if(NULL == edit_user_star_subscription_response){
        return ;
    }
    if(edit_user_star_subscription_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "edit_user_star_subscription_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(edit_user_star_subscription_response);
}

cJSON *edit_user_star_subscription_response_convertToJSON(edit_user_star_subscription_response_t *edit_user_star_subscription_response) {
    cJSON *item = cJSON_CreateObject();

    // edit_user_star_subscription_response->ok
    if (!edit_user_star_subscription_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", edit_user_star_subscription_response->ok) == NULL) {
    goto fail; //Bool
    }


    // edit_user_star_subscription_response->result
    if (!edit_user_star_subscription_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", edit_user_star_subscription_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

edit_user_star_subscription_response_t *edit_user_star_subscription_response_parseFromJSON(cJSON *edit_user_star_subscription_responseJSON){

    edit_user_star_subscription_response_t *edit_user_star_subscription_response_local_var = NULL;

    // edit_user_star_subscription_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(edit_user_star_subscription_responseJSON, "ok");
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

    // edit_user_star_subscription_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(edit_user_star_subscription_responseJSON, "result");
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


    edit_user_star_subscription_response_local_var = edit_user_star_subscription_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return edit_user_star_subscription_response_local_var;
end:
    return NULL;

}
