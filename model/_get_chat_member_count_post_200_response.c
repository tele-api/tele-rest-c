#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_get_chat_member_count_post_200_response.h"



static _get_chat_member_count_post_200_response_t *_get_chat_member_count_post_200_response_create_internal(
    int ok,
    int result
    ) {
    _get_chat_member_count_post_200_response_t *_get_chat_member_count_post_200_response_local_var = malloc(sizeof(_get_chat_member_count_post_200_response_t));
    if (!_get_chat_member_count_post_200_response_local_var) {
        return NULL;
    }
    _get_chat_member_count_post_200_response_local_var->ok = ok;
    _get_chat_member_count_post_200_response_local_var->result = result;

    _get_chat_member_count_post_200_response_local_var->_library_owned = 1;
    return _get_chat_member_count_post_200_response_local_var;
}

__attribute__((deprecated)) _get_chat_member_count_post_200_response_t *_get_chat_member_count_post_200_response_create(
    int ok,
    int result
    ) {
    return _get_chat_member_count_post_200_response_create_internal (
        ok,
        result
        );
}

void _get_chat_member_count_post_200_response_free(_get_chat_member_count_post_200_response_t *_get_chat_member_count_post_200_response) {
    if(NULL == _get_chat_member_count_post_200_response){
        return ;
    }
    if(_get_chat_member_count_post_200_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_get_chat_member_count_post_200_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_get_chat_member_count_post_200_response);
}

cJSON *_get_chat_member_count_post_200_response_convertToJSON(_get_chat_member_count_post_200_response_t *_get_chat_member_count_post_200_response) {
    cJSON *item = cJSON_CreateObject();

    // _get_chat_member_count_post_200_response->ok
    if (!_get_chat_member_count_post_200_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", _get_chat_member_count_post_200_response->ok) == NULL) {
    goto fail; //Bool
    }


    // _get_chat_member_count_post_200_response->result
    if (!_get_chat_member_count_post_200_response->result) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "result", _get_chat_member_count_post_200_response->result) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_get_chat_member_count_post_200_response_t *_get_chat_member_count_post_200_response_parseFromJSON(cJSON *_get_chat_member_count_post_200_responseJSON){

    _get_chat_member_count_post_200_response_t *_get_chat_member_count_post_200_response_local_var = NULL;

    // _get_chat_member_count_post_200_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(_get_chat_member_count_post_200_responseJSON, "ok");
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

    // _get_chat_member_count_post_200_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(_get_chat_member_count_post_200_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    if(!cJSON_IsNumber(result))
    {
    goto end; //Numeric
    }


    _get_chat_member_count_post_200_response_local_var = _get_chat_member_count_post_200_response_create_internal (
        ok->valueint,
        result->valuedouble
        );

    return _get_chat_member_count_post_200_response_local_var;
end:
    return NULL;

}
