#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_my_name_response.h"



static get_my_name_response_t *get_my_name_response_create_internal(
    int ok,
    bot_name_t *result
    ) {
    get_my_name_response_t *get_my_name_response_local_var = malloc(sizeof(get_my_name_response_t));
    if (!get_my_name_response_local_var) {
        return NULL;
    }
    get_my_name_response_local_var->ok = ok;
    get_my_name_response_local_var->result = result;

    get_my_name_response_local_var->_library_owned = 1;
    return get_my_name_response_local_var;
}

__attribute__((deprecated)) get_my_name_response_t *get_my_name_response_create(
    int ok,
    bot_name_t *result
    ) {
    return get_my_name_response_create_internal (
        ok,
        result
        );
}

void get_my_name_response_free(get_my_name_response_t *get_my_name_response) {
    if(NULL == get_my_name_response){
        return ;
    }
    if(get_my_name_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_my_name_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_my_name_response->result) {
        bot_name_free(get_my_name_response->result);
        get_my_name_response->result = NULL;
    }
    free(get_my_name_response);
}

cJSON *get_my_name_response_convertToJSON(get_my_name_response_t *get_my_name_response) {
    cJSON *item = cJSON_CreateObject();

    // get_my_name_response->ok
    if (!get_my_name_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", get_my_name_response->ok) == NULL) {
    goto fail; //Bool
    }


    // get_my_name_response->result
    if (!get_my_name_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = bot_name_convertToJSON(get_my_name_response->result);
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

get_my_name_response_t *get_my_name_response_parseFromJSON(cJSON *get_my_name_responseJSON){

    get_my_name_response_t *get_my_name_response_local_var = NULL;

    // define the local variable for get_my_name_response->result
    bot_name_t *result_local_nonprim = NULL;

    // get_my_name_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(get_my_name_responseJSON, "ok");
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

    // get_my_name_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(get_my_name_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = bot_name_parseFromJSON(result); //nonprimitive


    get_my_name_response_local_var = get_my_name_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return get_my_name_response_local_var;
end:
    if (result_local_nonprim) {
        bot_name_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
