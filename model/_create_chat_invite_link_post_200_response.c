#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_create_chat_invite_link_post_200_response.h"



static _create_chat_invite_link_post_200_response_t *_create_chat_invite_link_post_200_response_create_internal(
    int ok,
    chat_invite_link_t *result
    ) {
    _create_chat_invite_link_post_200_response_t *_create_chat_invite_link_post_200_response_local_var = malloc(sizeof(_create_chat_invite_link_post_200_response_t));
    if (!_create_chat_invite_link_post_200_response_local_var) {
        return NULL;
    }
    _create_chat_invite_link_post_200_response_local_var->ok = ok;
    _create_chat_invite_link_post_200_response_local_var->result = result;

    _create_chat_invite_link_post_200_response_local_var->_library_owned = 1;
    return _create_chat_invite_link_post_200_response_local_var;
}

__attribute__((deprecated)) _create_chat_invite_link_post_200_response_t *_create_chat_invite_link_post_200_response_create(
    int ok,
    chat_invite_link_t *result
    ) {
    return _create_chat_invite_link_post_200_response_create_internal (
        ok,
        result
        );
}

void _create_chat_invite_link_post_200_response_free(_create_chat_invite_link_post_200_response_t *_create_chat_invite_link_post_200_response) {
    if(NULL == _create_chat_invite_link_post_200_response){
        return ;
    }
    if(_create_chat_invite_link_post_200_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_create_chat_invite_link_post_200_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_create_chat_invite_link_post_200_response->result) {
        chat_invite_link_free(_create_chat_invite_link_post_200_response->result);
        _create_chat_invite_link_post_200_response->result = NULL;
    }
    free(_create_chat_invite_link_post_200_response);
}

cJSON *_create_chat_invite_link_post_200_response_convertToJSON(_create_chat_invite_link_post_200_response_t *_create_chat_invite_link_post_200_response) {
    cJSON *item = cJSON_CreateObject();

    // _create_chat_invite_link_post_200_response->ok
    if (!_create_chat_invite_link_post_200_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", _create_chat_invite_link_post_200_response->ok) == NULL) {
    goto fail; //Bool
    }


    // _create_chat_invite_link_post_200_response->result
    if (!_create_chat_invite_link_post_200_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = chat_invite_link_convertToJSON(_create_chat_invite_link_post_200_response->result);
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

_create_chat_invite_link_post_200_response_t *_create_chat_invite_link_post_200_response_parseFromJSON(cJSON *_create_chat_invite_link_post_200_responseJSON){

    _create_chat_invite_link_post_200_response_t *_create_chat_invite_link_post_200_response_local_var = NULL;

    // define the local variable for _create_chat_invite_link_post_200_response->result
    chat_invite_link_t *result_local_nonprim = NULL;

    // _create_chat_invite_link_post_200_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(_create_chat_invite_link_post_200_responseJSON, "ok");
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

    // _create_chat_invite_link_post_200_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(_create_chat_invite_link_post_200_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = chat_invite_link_parseFromJSON(result); //nonprimitive


    _create_chat_invite_link_post_200_response_local_var = _create_chat_invite_link_post_200_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return _create_chat_invite_link_post_200_response_local_var;
end:
    if (result_local_nonprim) {
        chat_invite_link_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
