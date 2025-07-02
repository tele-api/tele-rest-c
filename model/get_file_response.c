#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_file_response.h"



static get_file_response_t *get_file_response_create_internal(
    int ok,
    binary_t*_t *result
    ) {
    get_file_response_t *get_file_response_local_var = malloc(sizeof(get_file_response_t));
    if (!get_file_response_local_var) {
        return NULL;
    }
    get_file_response_local_var->ok = ok;
    get_file_response_local_var->result = result;

    get_file_response_local_var->_library_owned = 1;
    return get_file_response_local_var;
}

__attribute__((deprecated)) get_file_response_t *get_file_response_create(
    int ok,
    binary_t*_t *result
    ) {
    return get_file_response_create_internal (
        ok,
        result
        );
}

void get_file_response_free(get_file_response_t *get_file_response) {
    if(NULL == get_file_response){
        return ;
    }
    if(get_file_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_file_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_file_response->result) {
        file_free(get_file_response->result);
        get_file_response->result = NULL;
    }
    free(get_file_response);
}

cJSON *get_file_response_convertToJSON(get_file_response_t *get_file_response) {
    cJSON *item = cJSON_CreateObject();

    // get_file_response->ok
    if (!get_file_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", get_file_response->ok) == NULL) {
    goto fail; //Bool
    }


    // get_file_response->result
    if (!get_file_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = file_convertToJSON(get_file_response->result);
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

get_file_response_t *get_file_response_parseFromJSON(cJSON *get_file_responseJSON){

    get_file_response_t *get_file_response_local_var = NULL;

    // define the local variable for get_file_response->result
    file_t *result_local_nonprim = NULL;

    // get_file_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(get_file_responseJSON, "ok");
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

    // get_file_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(get_file_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = file_parseFromJSON(result); //nonprimitive


    get_file_response_local_var = get_file_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return get_file_response_local_var;
end:
    if (result_local_nonprim) {
        file_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
