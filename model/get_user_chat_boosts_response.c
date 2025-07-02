#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_user_chat_boosts_response.h"



static get_user_chat_boosts_response_t *get_user_chat_boosts_response_create_internal(
    int ok,
    user_chat_boosts_t *result
    ) {
    get_user_chat_boosts_response_t *get_user_chat_boosts_response_local_var = malloc(sizeof(get_user_chat_boosts_response_t));
    if (!get_user_chat_boosts_response_local_var) {
        return NULL;
    }
    get_user_chat_boosts_response_local_var->ok = ok;
    get_user_chat_boosts_response_local_var->result = result;

    get_user_chat_boosts_response_local_var->_library_owned = 1;
    return get_user_chat_boosts_response_local_var;
}

__attribute__((deprecated)) get_user_chat_boosts_response_t *get_user_chat_boosts_response_create(
    int ok,
    user_chat_boosts_t *result
    ) {
    return get_user_chat_boosts_response_create_internal (
        ok,
        result
        );
}

void get_user_chat_boosts_response_free(get_user_chat_boosts_response_t *get_user_chat_boosts_response) {
    if(NULL == get_user_chat_boosts_response){
        return ;
    }
    if(get_user_chat_boosts_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_user_chat_boosts_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_user_chat_boosts_response->result) {
        user_chat_boosts_free(get_user_chat_boosts_response->result);
        get_user_chat_boosts_response->result = NULL;
    }
    free(get_user_chat_boosts_response);
}

cJSON *get_user_chat_boosts_response_convertToJSON(get_user_chat_boosts_response_t *get_user_chat_boosts_response) {
    cJSON *item = cJSON_CreateObject();

    // get_user_chat_boosts_response->ok
    if (!get_user_chat_boosts_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", get_user_chat_boosts_response->ok) == NULL) {
    goto fail; //Bool
    }


    // get_user_chat_boosts_response->result
    if (!get_user_chat_boosts_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = user_chat_boosts_convertToJSON(get_user_chat_boosts_response->result);
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

get_user_chat_boosts_response_t *get_user_chat_boosts_response_parseFromJSON(cJSON *get_user_chat_boosts_responseJSON){

    get_user_chat_boosts_response_t *get_user_chat_boosts_response_local_var = NULL;

    // define the local variable for get_user_chat_boosts_response->result
    user_chat_boosts_t *result_local_nonprim = NULL;

    // get_user_chat_boosts_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(get_user_chat_boosts_responseJSON, "ok");
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

    // get_user_chat_boosts_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(get_user_chat_boosts_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = user_chat_boosts_parseFromJSON(result); //nonprimitive


    get_user_chat_boosts_response_local_var = get_user_chat_boosts_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return get_user_chat_boosts_response_local_var;
end:
    if (result_local_nonprim) {
        user_chat_boosts_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
