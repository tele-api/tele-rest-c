#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_chat_response.h"



static get_chat_response_t *get_chat_response_create_internal(
    int ok,
    chat_full_info_t *result
    ) {
    get_chat_response_t *get_chat_response_local_var = malloc(sizeof(get_chat_response_t));
    if (!get_chat_response_local_var) {
        return NULL;
    }
    get_chat_response_local_var->ok = ok;
    get_chat_response_local_var->result = result;

    get_chat_response_local_var->_library_owned = 1;
    return get_chat_response_local_var;
}

__attribute__((deprecated)) get_chat_response_t *get_chat_response_create(
    int ok,
    chat_full_info_t *result
    ) {
    return get_chat_response_create_internal (
        ok,
        result
        );
}

void get_chat_response_free(get_chat_response_t *get_chat_response) {
    if(NULL == get_chat_response){
        return ;
    }
    if(get_chat_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_chat_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_chat_response->result) {
        chat_full_info_free(get_chat_response->result);
        get_chat_response->result = NULL;
    }
    free(get_chat_response);
}

cJSON *get_chat_response_convertToJSON(get_chat_response_t *get_chat_response) {
    cJSON *item = cJSON_CreateObject();

    // get_chat_response->ok
    if (!get_chat_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", get_chat_response->ok) == NULL) {
    goto fail; //Bool
    }


    // get_chat_response->result
    if (!get_chat_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = chat_full_info_convertToJSON(get_chat_response->result);
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

get_chat_response_t *get_chat_response_parseFromJSON(cJSON *get_chat_responseJSON){

    get_chat_response_t *get_chat_response_local_var = NULL;

    // define the local variable for get_chat_response->result
    chat_full_info_t *result_local_nonprim = NULL;

    // get_chat_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(get_chat_responseJSON, "ok");
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

    // get_chat_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(get_chat_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = chat_full_info_parseFromJSON(result); //nonprimitive


    get_chat_response_local_var = get_chat_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return get_chat_response_local_var;
end:
    if (result_local_nonprim) {
        chat_full_info_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
