#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_answer_web_app_query_post_request.h"



static _answer_web_app_query_post_request_t *_answer_web_app_query_post_request_create_internal(
    char *web_app_query_id,
    inline_query_result_t *result
    ) {
    _answer_web_app_query_post_request_t *_answer_web_app_query_post_request_local_var = malloc(sizeof(_answer_web_app_query_post_request_t));
    if (!_answer_web_app_query_post_request_local_var) {
        return NULL;
    }
    _answer_web_app_query_post_request_local_var->web_app_query_id = web_app_query_id;
    _answer_web_app_query_post_request_local_var->result = result;

    _answer_web_app_query_post_request_local_var->_library_owned = 1;
    return _answer_web_app_query_post_request_local_var;
}

__attribute__((deprecated)) _answer_web_app_query_post_request_t *_answer_web_app_query_post_request_create(
    char *web_app_query_id,
    inline_query_result_t *result
    ) {
    return _answer_web_app_query_post_request_create_internal (
        web_app_query_id,
        result
        );
}

void _answer_web_app_query_post_request_free(_answer_web_app_query_post_request_t *_answer_web_app_query_post_request) {
    if(NULL == _answer_web_app_query_post_request){
        return ;
    }
    if(_answer_web_app_query_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_answer_web_app_query_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_answer_web_app_query_post_request->web_app_query_id) {
        free(_answer_web_app_query_post_request->web_app_query_id);
        _answer_web_app_query_post_request->web_app_query_id = NULL;
    }
    if (_answer_web_app_query_post_request->result) {
        inline_query_result_free(_answer_web_app_query_post_request->result);
        _answer_web_app_query_post_request->result = NULL;
    }
    free(_answer_web_app_query_post_request);
}

cJSON *_answer_web_app_query_post_request_convertToJSON(_answer_web_app_query_post_request_t *_answer_web_app_query_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _answer_web_app_query_post_request->web_app_query_id
    if (!_answer_web_app_query_post_request->web_app_query_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "web_app_query_id", _answer_web_app_query_post_request->web_app_query_id) == NULL) {
    goto fail; //String
    }


    // _answer_web_app_query_post_request->result
    if (!_answer_web_app_query_post_request->result) {
        goto fail;
    }
    cJSON *result_local_JSON = inline_query_result_convertToJSON(_answer_web_app_query_post_request->result);
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

_answer_web_app_query_post_request_t *_answer_web_app_query_post_request_parseFromJSON(cJSON *_answer_web_app_query_post_requestJSON){

    _answer_web_app_query_post_request_t *_answer_web_app_query_post_request_local_var = NULL;

    // define the local variable for _answer_web_app_query_post_request->result
    inline_query_result_t *result_local_nonprim = NULL;

    // _answer_web_app_query_post_request->web_app_query_id
    cJSON *web_app_query_id = cJSON_GetObjectItemCaseSensitive(_answer_web_app_query_post_requestJSON, "web_app_query_id");
    if (cJSON_IsNull(web_app_query_id)) {
        web_app_query_id = NULL;
    }
    if (!web_app_query_id) {
        goto end;
    }

    
    if(!cJSON_IsString(web_app_query_id))
    {
    goto end; //String
    }

    // _answer_web_app_query_post_request->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(_answer_web_app_query_post_requestJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = inline_query_result_parseFromJSON(result); //nonprimitive


    _answer_web_app_query_post_request_local_var = _answer_web_app_query_post_request_create_internal (
        strdup(web_app_query_id->valuestring),
        result_local_nonprim
        );

    return _answer_web_app_query_post_request_local_var;
end:
    if (result_local_nonprim) {
        inline_query_result_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
