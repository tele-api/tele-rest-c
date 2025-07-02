#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_star_transactions_response.h"



static get_star_transactions_response_t *get_star_transactions_response_create_internal(
    int ok,
    star_transactions_t *result
    ) {
    get_star_transactions_response_t *get_star_transactions_response_local_var = malloc(sizeof(get_star_transactions_response_t));
    if (!get_star_transactions_response_local_var) {
        return NULL;
    }
    get_star_transactions_response_local_var->ok = ok;
    get_star_transactions_response_local_var->result = result;

    get_star_transactions_response_local_var->_library_owned = 1;
    return get_star_transactions_response_local_var;
}

__attribute__((deprecated)) get_star_transactions_response_t *get_star_transactions_response_create(
    int ok,
    star_transactions_t *result
    ) {
    return get_star_transactions_response_create_internal (
        ok,
        result
        );
}

void get_star_transactions_response_free(get_star_transactions_response_t *get_star_transactions_response) {
    if(NULL == get_star_transactions_response){
        return ;
    }
    if(get_star_transactions_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_star_transactions_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_star_transactions_response->result) {
        star_transactions_free(get_star_transactions_response->result);
        get_star_transactions_response->result = NULL;
    }
    free(get_star_transactions_response);
}

cJSON *get_star_transactions_response_convertToJSON(get_star_transactions_response_t *get_star_transactions_response) {
    cJSON *item = cJSON_CreateObject();

    // get_star_transactions_response->ok
    if (!get_star_transactions_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", get_star_transactions_response->ok) == NULL) {
    goto fail; //Bool
    }


    // get_star_transactions_response->result
    if (!get_star_transactions_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = star_transactions_convertToJSON(get_star_transactions_response->result);
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

get_star_transactions_response_t *get_star_transactions_response_parseFromJSON(cJSON *get_star_transactions_responseJSON){

    get_star_transactions_response_t *get_star_transactions_response_local_var = NULL;

    // define the local variable for get_star_transactions_response->result
    star_transactions_t *result_local_nonprim = NULL;

    // get_star_transactions_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(get_star_transactions_responseJSON, "ok");
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

    // get_star_transactions_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(get_star_transactions_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = star_transactions_parseFromJSON(result); //nonprimitive


    get_star_transactions_response_local_var = get_star_transactions_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return get_star_transactions_response_local_var;
end:
    if (result_local_nonprim) {
        star_transactions_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
