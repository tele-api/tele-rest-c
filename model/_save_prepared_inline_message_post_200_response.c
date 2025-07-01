#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_save_prepared_inline_message_post_200_response.h"



static _save_prepared_inline_message_post_200_response_t *_save_prepared_inline_message_post_200_response_create_internal(
    int ok,
    prepared_inline_message_t *result
    ) {
    _save_prepared_inline_message_post_200_response_t *_save_prepared_inline_message_post_200_response_local_var = malloc(sizeof(_save_prepared_inline_message_post_200_response_t));
    if (!_save_prepared_inline_message_post_200_response_local_var) {
        return NULL;
    }
    _save_prepared_inline_message_post_200_response_local_var->ok = ok;
    _save_prepared_inline_message_post_200_response_local_var->result = result;

    _save_prepared_inline_message_post_200_response_local_var->_library_owned = 1;
    return _save_prepared_inline_message_post_200_response_local_var;
}

__attribute__((deprecated)) _save_prepared_inline_message_post_200_response_t *_save_prepared_inline_message_post_200_response_create(
    int ok,
    prepared_inline_message_t *result
    ) {
    return _save_prepared_inline_message_post_200_response_create_internal (
        ok,
        result
        );
}

void _save_prepared_inline_message_post_200_response_free(_save_prepared_inline_message_post_200_response_t *_save_prepared_inline_message_post_200_response) {
    if(NULL == _save_prepared_inline_message_post_200_response){
        return ;
    }
    if(_save_prepared_inline_message_post_200_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_save_prepared_inline_message_post_200_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_save_prepared_inline_message_post_200_response->result) {
        prepared_inline_message_free(_save_prepared_inline_message_post_200_response->result);
        _save_prepared_inline_message_post_200_response->result = NULL;
    }
    free(_save_prepared_inline_message_post_200_response);
}

cJSON *_save_prepared_inline_message_post_200_response_convertToJSON(_save_prepared_inline_message_post_200_response_t *_save_prepared_inline_message_post_200_response) {
    cJSON *item = cJSON_CreateObject();

    // _save_prepared_inline_message_post_200_response->ok
    if (!_save_prepared_inline_message_post_200_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", _save_prepared_inline_message_post_200_response->ok) == NULL) {
    goto fail; //Bool
    }


    // _save_prepared_inline_message_post_200_response->result
    if (!_save_prepared_inline_message_post_200_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = prepared_inline_message_convertToJSON(_save_prepared_inline_message_post_200_response->result);
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

_save_prepared_inline_message_post_200_response_t *_save_prepared_inline_message_post_200_response_parseFromJSON(cJSON *_save_prepared_inline_message_post_200_responseJSON){

    _save_prepared_inline_message_post_200_response_t *_save_prepared_inline_message_post_200_response_local_var = NULL;

    // define the local variable for _save_prepared_inline_message_post_200_response->result
    prepared_inline_message_t *result_local_nonprim = NULL;

    // _save_prepared_inline_message_post_200_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(_save_prepared_inline_message_post_200_responseJSON, "ok");
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

    // _save_prepared_inline_message_post_200_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(_save_prepared_inline_message_post_200_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = prepared_inline_message_parseFromJSON(result); //nonprimitive


    _save_prepared_inline_message_post_200_response_local_var = _save_prepared_inline_message_post_200_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return _save_prepared_inline_message_post_200_response_local_var;
end:
    if (result_local_nonprim) {
        prepared_inline_message_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
