#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_answer_web_app_query_post_200_response.h"



static _answer_web_app_query_post_200_response_t *_answer_web_app_query_post_200_response_create_internal(
    int ok,
    sent_web_app_message_t *result
    ) {
    _answer_web_app_query_post_200_response_t *_answer_web_app_query_post_200_response_local_var = malloc(sizeof(_answer_web_app_query_post_200_response_t));
    if (!_answer_web_app_query_post_200_response_local_var) {
        return NULL;
    }
    _answer_web_app_query_post_200_response_local_var->ok = ok;
    _answer_web_app_query_post_200_response_local_var->result = result;

    _answer_web_app_query_post_200_response_local_var->_library_owned = 1;
    return _answer_web_app_query_post_200_response_local_var;
}

__attribute__((deprecated)) _answer_web_app_query_post_200_response_t *_answer_web_app_query_post_200_response_create(
    int ok,
    sent_web_app_message_t *result
    ) {
    return _answer_web_app_query_post_200_response_create_internal (
        ok,
        result
        );
}

void _answer_web_app_query_post_200_response_free(_answer_web_app_query_post_200_response_t *_answer_web_app_query_post_200_response) {
    if(NULL == _answer_web_app_query_post_200_response){
        return ;
    }
    if(_answer_web_app_query_post_200_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_answer_web_app_query_post_200_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_answer_web_app_query_post_200_response->result) {
        sent_web_app_message_free(_answer_web_app_query_post_200_response->result);
        _answer_web_app_query_post_200_response->result = NULL;
    }
    free(_answer_web_app_query_post_200_response);
}

cJSON *_answer_web_app_query_post_200_response_convertToJSON(_answer_web_app_query_post_200_response_t *_answer_web_app_query_post_200_response) {
    cJSON *item = cJSON_CreateObject();

    // _answer_web_app_query_post_200_response->ok
    if (!_answer_web_app_query_post_200_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", _answer_web_app_query_post_200_response->ok) == NULL) {
    goto fail; //Bool
    }


    // _answer_web_app_query_post_200_response->result
    if (!_answer_web_app_query_post_200_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = sent_web_app_message_convertToJSON(_answer_web_app_query_post_200_response->result);
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

_answer_web_app_query_post_200_response_t *_answer_web_app_query_post_200_response_parseFromJSON(cJSON *_answer_web_app_query_post_200_responseJSON){

    _answer_web_app_query_post_200_response_t *_answer_web_app_query_post_200_response_local_var = NULL;

    // define the local variable for _answer_web_app_query_post_200_response->result
    sent_web_app_message_t *result_local_nonprim = NULL;

    // _answer_web_app_query_post_200_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(_answer_web_app_query_post_200_responseJSON, "ok");
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

    // _answer_web_app_query_post_200_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(_answer_web_app_query_post_200_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = sent_web_app_message_parseFromJSON(result); //nonprimitive


    _answer_web_app_query_post_200_response_local_var = _answer_web_app_query_post_200_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return _answer_web_app_query_post_200_response_local_var;
end:
    if (result_local_nonprim) {
        sent_web_app_message_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
