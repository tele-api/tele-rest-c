#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_business_account_star_balance_response.h"



static get_business_account_star_balance_response_t *get_business_account_star_balance_response_create_internal(
    int ok,
    star_amount_t *result
    ) {
    get_business_account_star_balance_response_t *get_business_account_star_balance_response_local_var = malloc(sizeof(get_business_account_star_balance_response_t));
    if (!get_business_account_star_balance_response_local_var) {
        return NULL;
    }
    get_business_account_star_balance_response_local_var->ok = ok;
    get_business_account_star_balance_response_local_var->result = result;

    get_business_account_star_balance_response_local_var->_library_owned = 1;
    return get_business_account_star_balance_response_local_var;
}

__attribute__((deprecated)) get_business_account_star_balance_response_t *get_business_account_star_balance_response_create(
    int ok,
    star_amount_t *result
    ) {
    return get_business_account_star_balance_response_create_internal (
        ok,
        result
        );
}

void get_business_account_star_balance_response_free(get_business_account_star_balance_response_t *get_business_account_star_balance_response) {
    if(NULL == get_business_account_star_balance_response){
        return ;
    }
    if(get_business_account_star_balance_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_business_account_star_balance_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_business_account_star_balance_response->result) {
        star_amount_free(get_business_account_star_balance_response->result);
        get_business_account_star_balance_response->result = NULL;
    }
    free(get_business_account_star_balance_response);
}

cJSON *get_business_account_star_balance_response_convertToJSON(get_business_account_star_balance_response_t *get_business_account_star_balance_response) {
    cJSON *item = cJSON_CreateObject();

    // get_business_account_star_balance_response->ok
    if (!get_business_account_star_balance_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", get_business_account_star_balance_response->ok) == NULL) {
    goto fail; //Bool
    }


    // get_business_account_star_balance_response->result
    if (!get_business_account_star_balance_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = star_amount_convertToJSON(get_business_account_star_balance_response->result);
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

get_business_account_star_balance_response_t *get_business_account_star_balance_response_parseFromJSON(cJSON *get_business_account_star_balance_responseJSON){

    get_business_account_star_balance_response_t *get_business_account_star_balance_response_local_var = NULL;

    // define the local variable for get_business_account_star_balance_response->result
    star_amount_t *result_local_nonprim = NULL;

    // get_business_account_star_balance_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(get_business_account_star_balance_responseJSON, "ok");
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

    // get_business_account_star_balance_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(get_business_account_star_balance_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = star_amount_parseFromJSON(result); //nonprimitive


    get_business_account_star_balance_response_local_var = get_business_account_star_balance_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return get_business_account_star_balance_response_local_var;
end:
    if (result_local_nonprim) {
        star_amount_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
