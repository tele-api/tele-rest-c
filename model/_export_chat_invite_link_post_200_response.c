#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_export_chat_invite_link_post_200_response.h"



static _export_chat_invite_link_post_200_response_t *_export_chat_invite_link_post_200_response_create_internal(
    int ok,
    char *result
    ) {
    _export_chat_invite_link_post_200_response_t *_export_chat_invite_link_post_200_response_local_var = malloc(sizeof(_export_chat_invite_link_post_200_response_t));
    if (!_export_chat_invite_link_post_200_response_local_var) {
        return NULL;
    }
    _export_chat_invite_link_post_200_response_local_var->ok = ok;
    _export_chat_invite_link_post_200_response_local_var->result = result;

    _export_chat_invite_link_post_200_response_local_var->_library_owned = 1;
    return _export_chat_invite_link_post_200_response_local_var;
}

__attribute__((deprecated)) _export_chat_invite_link_post_200_response_t *_export_chat_invite_link_post_200_response_create(
    int ok,
    char *result
    ) {
    return _export_chat_invite_link_post_200_response_create_internal (
        ok,
        result
        );
}

void _export_chat_invite_link_post_200_response_free(_export_chat_invite_link_post_200_response_t *_export_chat_invite_link_post_200_response) {
    if(NULL == _export_chat_invite_link_post_200_response){
        return ;
    }
    if(_export_chat_invite_link_post_200_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_export_chat_invite_link_post_200_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_export_chat_invite_link_post_200_response->result) {
        free(_export_chat_invite_link_post_200_response->result);
        _export_chat_invite_link_post_200_response->result = NULL;
    }
    free(_export_chat_invite_link_post_200_response);
}

cJSON *_export_chat_invite_link_post_200_response_convertToJSON(_export_chat_invite_link_post_200_response_t *_export_chat_invite_link_post_200_response) {
    cJSON *item = cJSON_CreateObject();

    // _export_chat_invite_link_post_200_response->ok
    if (!_export_chat_invite_link_post_200_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", _export_chat_invite_link_post_200_response->ok) == NULL) {
    goto fail; //Bool
    }


    // _export_chat_invite_link_post_200_response->result
    if (!_export_chat_invite_link_post_200_response->result) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "result", _export_chat_invite_link_post_200_response->result) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_export_chat_invite_link_post_200_response_t *_export_chat_invite_link_post_200_response_parseFromJSON(cJSON *_export_chat_invite_link_post_200_responseJSON){

    _export_chat_invite_link_post_200_response_t *_export_chat_invite_link_post_200_response_local_var = NULL;

    // _export_chat_invite_link_post_200_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(_export_chat_invite_link_post_200_responseJSON, "ok");
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

    // _export_chat_invite_link_post_200_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(_export_chat_invite_link_post_200_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    if(!cJSON_IsString(result))
    {
    goto end; //String
    }


    _export_chat_invite_link_post_200_response_local_var = _export_chat_invite_link_post_200_response_create_internal (
        ok->valueint,
        strdup(result->valuestring)
        );

    return _export_chat_invite_link_post_200_response_local_var;
end:
    return NULL;

}
