#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_available_gifts_response.h"



static get_available_gifts_response_t *get_available_gifts_response_create_internal(
    int ok,
    gifts_t *result
    ) {
    get_available_gifts_response_t *get_available_gifts_response_local_var = malloc(sizeof(get_available_gifts_response_t));
    if (!get_available_gifts_response_local_var) {
        return NULL;
    }
    get_available_gifts_response_local_var->ok = ok;
    get_available_gifts_response_local_var->result = result;

    get_available_gifts_response_local_var->_library_owned = 1;
    return get_available_gifts_response_local_var;
}

__attribute__((deprecated)) get_available_gifts_response_t *get_available_gifts_response_create(
    int ok,
    gifts_t *result
    ) {
    return get_available_gifts_response_create_internal (
        ok,
        result
        );
}

void get_available_gifts_response_free(get_available_gifts_response_t *get_available_gifts_response) {
    if(NULL == get_available_gifts_response){
        return ;
    }
    if(get_available_gifts_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_available_gifts_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_available_gifts_response->result) {
        gifts_free(get_available_gifts_response->result);
        get_available_gifts_response->result = NULL;
    }
    free(get_available_gifts_response);
}

cJSON *get_available_gifts_response_convertToJSON(get_available_gifts_response_t *get_available_gifts_response) {
    cJSON *item = cJSON_CreateObject();

    // get_available_gifts_response->ok
    if (!get_available_gifts_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", get_available_gifts_response->ok) == NULL) {
    goto fail; //Bool
    }


    // get_available_gifts_response->result
    if (!get_available_gifts_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = gifts_convertToJSON(get_available_gifts_response->result);
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

get_available_gifts_response_t *get_available_gifts_response_parseFromJSON(cJSON *get_available_gifts_responseJSON){

    get_available_gifts_response_t *get_available_gifts_response_local_var = NULL;

    // define the local variable for get_available_gifts_response->result
    gifts_t *result_local_nonprim = NULL;

    // get_available_gifts_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(get_available_gifts_responseJSON, "ok");
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

    // get_available_gifts_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(get_available_gifts_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = gifts_parseFromJSON(result); //nonprimitive


    get_available_gifts_response_local_var = get_available_gifts_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return get_available_gifts_response_local_var;
end:
    if (result_local_nonprim) {
        gifts_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
