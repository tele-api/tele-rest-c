#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_edit_message_text_post_200_response.h"



static _edit_message_text_post_200_response_t *_edit_message_text_post_200_response_create_internal(
    int ok,
    _edit_message_text_post_200_response_result_t *result
    ) {
    _edit_message_text_post_200_response_t *_edit_message_text_post_200_response_local_var = malloc(sizeof(_edit_message_text_post_200_response_t));
    if (!_edit_message_text_post_200_response_local_var) {
        return NULL;
    }
    _edit_message_text_post_200_response_local_var->ok = ok;
    _edit_message_text_post_200_response_local_var->result = result;

    _edit_message_text_post_200_response_local_var->_library_owned = 1;
    return _edit_message_text_post_200_response_local_var;
}

__attribute__((deprecated)) _edit_message_text_post_200_response_t *_edit_message_text_post_200_response_create(
    int ok,
    _edit_message_text_post_200_response_result_t *result
    ) {
    return _edit_message_text_post_200_response_create_internal (
        ok,
        result
        );
}

void _edit_message_text_post_200_response_free(_edit_message_text_post_200_response_t *_edit_message_text_post_200_response) {
    if(NULL == _edit_message_text_post_200_response){
        return ;
    }
    if(_edit_message_text_post_200_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_edit_message_text_post_200_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_edit_message_text_post_200_response->result) {
        _edit_message_text_post_200_response_result_free(_edit_message_text_post_200_response->result);
        _edit_message_text_post_200_response->result = NULL;
    }
    free(_edit_message_text_post_200_response);
}

cJSON *_edit_message_text_post_200_response_convertToJSON(_edit_message_text_post_200_response_t *_edit_message_text_post_200_response) {
    cJSON *item = cJSON_CreateObject();

    // _edit_message_text_post_200_response->ok
    if (!_edit_message_text_post_200_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", _edit_message_text_post_200_response->ok) == NULL) {
    goto fail; //Bool
    }


    // _edit_message_text_post_200_response->result
    if (!_edit_message_text_post_200_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = _edit_message_text_post_200_response_result_convertToJSON(_edit_message_text_post_200_response->result);
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

_edit_message_text_post_200_response_t *_edit_message_text_post_200_response_parseFromJSON(cJSON *_edit_message_text_post_200_responseJSON){

    _edit_message_text_post_200_response_t *_edit_message_text_post_200_response_local_var = NULL;

    // define the local variable for _edit_message_text_post_200_response->result
    _edit_message_text_post_200_response_result_t *result_local_nonprim = NULL;

    // _edit_message_text_post_200_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_responseJSON, "ok");
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

    // _edit_message_text_post_200_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = _edit_message_text_post_200_response_result_parseFromJSON(result); //nonprimitive


    _edit_message_text_post_200_response_local_var = _edit_message_text_post_200_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return _edit_message_text_post_200_response_local_var;
end:
    if (result_local_nonprim) {
        _edit_message_text_post_200_response_result_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
