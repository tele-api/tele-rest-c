#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_get_business_account_gifts_post_200_response.h"



static _get_business_account_gifts_post_200_response_t *_get_business_account_gifts_post_200_response_create_internal(
    int ok,
    owned_gifts_t *result
    ) {
    _get_business_account_gifts_post_200_response_t *_get_business_account_gifts_post_200_response_local_var = malloc(sizeof(_get_business_account_gifts_post_200_response_t));
    if (!_get_business_account_gifts_post_200_response_local_var) {
        return NULL;
    }
    _get_business_account_gifts_post_200_response_local_var->ok = ok;
    _get_business_account_gifts_post_200_response_local_var->result = result;

    _get_business_account_gifts_post_200_response_local_var->_library_owned = 1;
    return _get_business_account_gifts_post_200_response_local_var;
}

__attribute__((deprecated)) _get_business_account_gifts_post_200_response_t *_get_business_account_gifts_post_200_response_create(
    int ok,
    owned_gifts_t *result
    ) {
    return _get_business_account_gifts_post_200_response_create_internal (
        ok,
        result
        );
}

void _get_business_account_gifts_post_200_response_free(_get_business_account_gifts_post_200_response_t *_get_business_account_gifts_post_200_response) {
    if(NULL == _get_business_account_gifts_post_200_response){
        return ;
    }
    if(_get_business_account_gifts_post_200_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_get_business_account_gifts_post_200_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_get_business_account_gifts_post_200_response->result) {
        owned_gifts_free(_get_business_account_gifts_post_200_response->result);
        _get_business_account_gifts_post_200_response->result = NULL;
    }
    free(_get_business_account_gifts_post_200_response);
}

cJSON *_get_business_account_gifts_post_200_response_convertToJSON(_get_business_account_gifts_post_200_response_t *_get_business_account_gifts_post_200_response) {
    cJSON *item = cJSON_CreateObject();

    // _get_business_account_gifts_post_200_response->ok
    if (!_get_business_account_gifts_post_200_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", _get_business_account_gifts_post_200_response->ok) == NULL) {
    goto fail; //Bool
    }


    // _get_business_account_gifts_post_200_response->result
    if (!_get_business_account_gifts_post_200_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = owned_gifts_convertToJSON(_get_business_account_gifts_post_200_response->result);
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

_get_business_account_gifts_post_200_response_t *_get_business_account_gifts_post_200_response_parseFromJSON(cJSON *_get_business_account_gifts_post_200_responseJSON){

    _get_business_account_gifts_post_200_response_t *_get_business_account_gifts_post_200_response_local_var = NULL;

    // define the local variable for _get_business_account_gifts_post_200_response->result
    owned_gifts_t *result_local_nonprim = NULL;

    // _get_business_account_gifts_post_200_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(_get_business_account_gifts_post_200_responseJSON, "ok");
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

    // _get_business_account_gifts_post_200_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(_get_business_account_gifts_post_200_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = owned_gifts_parseFromJSON(result); //nonprimitive


    _get_business_account_gifts_post_200_response_local_var = _get_business_account_gifts_post_200_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return _get_business_account_gifts_post_200_response_local_var;
end:
    if (result_local_nonprim) {
        owned_gifts_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
