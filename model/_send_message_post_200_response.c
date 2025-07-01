#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_send_message_post_200_response.h"



static _send_message_post_200_response_t *_send_message_post_200_response_create_internal(
    int ok,
    message_t *result
    ) {
    _send_message_post_200_response_t *_send_message_post_200_response_local_var = malloc(sizeof(_send_message_post_200_response_t));
    if (!_send_message_post_200_response_local_var) {
        return NULL;
    }
    _send_message_post_200_response_local_var->ok = ok;
    _send_message_post_200_response_local_var->result = result;

    _send_message_post_200_response_local_var->_library_owned = 1;
    return _send_message_post_200_response_local_var;
}

__attribute__((deprecated)) _send_message_post_200_response_t *_send_message_post_200_response_create(
    int ok,
    message_t *result
    ) {
    return _send_message_post_200_response_create_internal (
        ok,
        result
        );
}

void _send_message_post_200_response_free(_send_message_post_200_response_t *_send_message_post_200_response) {
    if(NULL == _send_message_post_200_response){
        return ;
    }
    if(_send_message_post_200_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_send_message_post_200_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_send_message_post_200_response->result) {
        message_free(_send_message_post_200_response->result);
        _send_message_post_200_response->result = NULL;
    }
    free(_send_message_post_200_response);
}

cJSON *_send_message_post_200_response_convertToJSON(_send_message_post_200_response_t *_send_message_post_200_response) {
    cJSON *item = cJSON_CreateObject();

    // _send_message_post_200_response->ok
    if (!_send_message_post_200_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", _send_message_post_200_response->ok) == NULL) {
    goto fail; //Bool
    }


    // _send_message_post_200_response->result
    if (!_send_message_post_200_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = message_convertToJSON(_send_message_post_200_response->result);
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

_send_message_post_200_response_t *_send_message_post_200_response_parseFromJSON(cJSON *_send_message_post_200_responseJSON){

    _send_message_post_200_response_t *_send_message_post_200_response_local_var = NULL;

    // define the local variable for _send_message_post_200_response->result
    message_t *result_local_nonprim = NULL;

    // _send_message_post_200_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(_send_message_post_200_responseJSON, "ok");
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

    // _send_message_post_200_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(_send_message_post_200_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = message_parseFromJSON(result); //nonprimitive


    _send_message_post_200_response_local_var = _send_message_post_200_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return _send_message_post_200_response_local_var;
end:
    if (result_local_nonprim) {
        message_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
