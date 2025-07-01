#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_answer_pre_checkout_query_post_request.h"



static _answer_pre_checkout_query_post_request_t *_answer_pre_checkout_query_post_request_create_internal(
    char *pre_checkout_query_id,
    int ok,
    char *error_message
    ) {
    _answer_pre_checkout_query_post_request_t *_answer_pre_checkout_query_post_request_local_var = malloc(sizeof(_answer_pre_checkout_query_post_request_t));
    if (!_answer_pre_checkout_query_post_request_local_var) {
        return NULL;
    }
    _answer_pre_checkout_query_post_request_local_var->pre_checkout_query_id = pre_checkout_query_id;
    _answer_pre_checkout_query_post_request_local_var->ok = ok;
    _answer_pre_checkout_query_post_request_local_var->error_message = error_message;

    _answer_pre_checkout_query_post_request_local_var->_library_owned = 1;
    return _answer_pre_checkout_query_post_request_local_var;
}

__attribute__((deprecated)) _answer_pre_checkout_query_post_request_t *_answer_pre_checkout_query_post_request_create(
    char *pre_checkout_query_id,
    int ok,
    char *error_message
    ) {
    return _answer_pre_checkout_query_post_request_create_internal (
        pre_checkout_query_id,
        ok,
        error_message
        );
}

void _answer_pre_checkout_query_post_request_free(_answer_pre_checkout_query_post_request_t *_answer_pre_checkout_query_post_request) {
    if(NULL == _answer_pre_checkout_query_post_request){
        return ;
    }
    if(_answer_pre_checkout_query_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_answer_pre_checkout_query_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_answer_pre_checkout_query_post_request->pre_checkout_query_id) {
        free(_answer_pre_checkout_query_post_request->pre_checkout_query_id);
        _answer_pre_checkout_query_post_request->pre_checkout_query_id = NULL;
    }
    if (_answer_pre_checkout_query_post_request->error_message) {
        free(_answer_pre_checkout_query_post_request->error_message);
        _answer_pre_checkout_query_post_request->error_message = NULL;
    }
    free(_answer_pre_checkout_query_post_request);
}

cJSON *_answer_pre_checkout_query_post_request_convertToJSON(_answer_pre_checkout_query_post_request_t *_answer_pre_checkout_query_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _answer_pre_checkout_query_post_request->pre_checkout_query_id
    if (!_answer_pre_checkout_query_post_request->pre_checkout_query_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "pre_checkout_query_id", _answer_pre_checkout_query_post_request->pre_checkout_query_id) == NULL) {
    goto fail; //String
    }


    // _answer_pre_checkout_query_post_request->ok
    if (!_answer_pre_checkout_query_post_request->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", _answer_pre_checkout_query_post_request->ok) == NULL) {
    goto fail; //Bool
    }


    // _answer_pre_checkout_query_post_request->error_message
    if(_answer_pre_checkout_query_post_request->error_message) {
    if(cJSON_AddStringToObject(item, "error_message", _answer_pre_checkout_query_post_request->error_message) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_answer_pre_checkout_query_post_request_t *_answer_pre_checkout_query_post_request_parseFromJSON(cJSON *_answer_pre_checkout_query_post_requestJSON){

    _answer_pre_checkout_query_post_request_t *_answer_pre_checkout_query_post_request_local_var = NULL;

    // _answer_pre_checkout_query_post_request->pre_checkout_query_id
    cJSON *pre_checkout_query_id = cJSON_GetObjectItemCaseSensitive(_answer_pre_checkout_query_post_requestJSON, "pre_checkout_query_id");
    if (cJSON_IsNull(pre_checkout_query_id)) {
        pre_checkout_query_id = NULL;
    }
    if (!pre_checkout_query_id) {
        goto end;
    }

    
    if(!cJSON_IsString(pre_checkout_query_id))
    {
    goto end; //String
    }

    // _answer_pre_checkout_query_post_request->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(_answer_pre_checkout_query_post_requestJSON, "ok");
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

    // _answer_pre_checkout_query_post_request->error_message
    cJSON *error_message = cJSON_GetObjectItemCaseSensitive(_answer_pre_checkout_query_post_requestJSON, "error_message");
    if (cJSON_IsNull(error_message)) {
        error_message = NULL;
    }
    if (error_message) { 
    if(!cJSON_IsString(error_message) && !cJSON_IsNull(error_message))
    {
    goto end; //String
    }
    }


    _answer_pre_checkout_query_post_request_local_var = _answer_pre_checkout_query_post_request_create_internal (
        strdup(pre_checkout_query_id->valuestring),
        ok->valueint,
        error_message && !cJSON_IsNull(error_message) ? strdup(error_message->valuestring) : NULL
        );

    return _answer_pre_checkout_query_post_request_local_var;
end:
    return NULL;

}
