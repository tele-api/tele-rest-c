#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_answer_callback_query_post_request.h"



static _answer_callback_query_post_request_t *_answer_callback_query_post_request_create_internal(
    char *callback_query_id,
    char *text,
    int show_alert,
    char *url,
    int cache_time
    ) {
    _answer_callback_query_post_request_t *_answer_callback_query_post_request_local_var = malloc(sizeof(_answer_callback_query_post_request_t));
    if (!_answer_callback_query_post_request_local_var) {
        return NULL;
    }
    _answer_callback_query_post_request_local_var->callback_query_id = callback_query_id;
    _answer_callback_query_post_request_local_var->text = text;
    _answer_callback_query_post_request_local_var->show_alert = show_alert;
    _answer_callback_query_post_request_local_var->url = url;
    _answer_callback_query_post_request_local_var->cache_time = cache_time;

    _answer_callback_query_post_request_local_var->_library_owned = 1;
    return _answer_callback_query_post_request_local_var;
}

__attribute__((deprecated)) _answer_callback_query_post_request_t *_answer_callback_query_post_request_create(
    char *callback_query_id,
    char *text,
    int show_alert,
    char *url,
    int cache_time
    ) {
    return _answer_callback_query_post_request_create_internal (
        callback_query_id,
        text,
        show_alert,
        url,
        cache_time
        );
}

void _answer_callback_query_post_request_free(_answer_callback_query_post_request_t *_answer_callback_query_post_request) {
    if(NULL == _answer_callback_query_post_request){
        return ;
    }
    if(_answer_callback_query_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_answer_callback_query_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_answer_callback_query_post_request->callback_query_id) {
        free(_answer_callback_query_post_request->callback_query_id);
        _answer_callback_query_post_request->callback_query_id = NULL;
    }
    if (_answer_callback_query_post_request->text) {
        free(_answer_callback_query_post_request->text);
        _answer_callback_query_post_request->text = NULL;
    }
    if (_answer_callback_query_post_request->url) {
        free(_answer_callback_query_post_request->url);
        _answer_callback_query_post_request->url = NULL;
    }
    free(_answer_callback_query_post_request);
}

cJSON *_answer_callback_query_post_request_convertToJSON(_answer_callback_query_post_request_t *_answer_callback_query_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _answer_callback_query_post_request->callback_query_id
    if (!_answer_callback_query_post_request->callback_query_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "callback_query_id", _answer_callback_query_post_request->callback_query_id) == NULL) {
    goto fail; //String
    }


    // _answer_callback_query_post_request->text
    if(_answer_callback_query_post_request->text) {
    if(cJSON_AddStringToObject(item, "text", _answer_callback_query_post_request->text) == NULL) {
    goto fail; //String
    }
    }


    // _answer_callback_query_post_request->show_alert
    if(_answer_callback_query_post_request->show_alert) {
    if(cJSON_AddBoolToObject(item, "show_alert", _answer_callback_query_post_request->show_alert) == NULL) {
    goto fail; //Bool
    }
    }


    // _answer_callback_query_post_request->url
    if(_answer_callback_query_post_request->url) {
    if(cJSON_AddStringToObject(item, "url", _answer_callback_query_post_request->url) == NULL) {
    goto fail; //String
    }
    }


    // _answer_callback_query_post_request->cache_time
    if(_answer_callback_query_post_request->cache_time) {
    if(cJSON_AddNumberToObject(item, "cache_time", _answer_callback_query_post_request->cache_time) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_answer_callback_query_post_request_t *_answer_callback_query_post_request_parseFromJSON(cJSON *_answer_callback_query_post_requestJSON){

    _answer_callback_query_post_request_t *_answer_callback_query_post_request_local_var = NULL;

    // _answer_callback_query_post_request->callback_query_id
    cJSON *callback_query_id = cJSON_GetObjectItemCaseSensitive(_answer_callback_query_post_requestJSON, "callback_query_id");
    if (cJSON_IsNull(callback_query_id)) {
        callback_query_id = NULL;
    }
    if (!callback_query_id) {
        goto end;
    }

    
    if(!cJSON_IsString(callback_query_id))
    {
    goto end; //String
    }

    // _answer_callback_query_post_request->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(_answer_callback_query_post_requestJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (text) { 
    if(!cJSON_IsString(text) && !cJSON_IsNull(text))
    {
    goto end; //String
    }
    }

    // _answer_callback_query_post_request->show_alert
    cJSON *show_alert = cJSON_GetObjectItemCaseSensitive(_answer_callback_query_post_requestJSON, "show_alert");
    if (cJSON_IsNull(show_alert)) {
        show_alert = NULL;
    }
    if (show_alert) { 
    if(!cJSON_IsBool(show_alert))
    {
    goto end; //Bool
    }
    }

    // _answer_callback_query_post_request->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(_answer_callback_query_post_requestJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }

    // _answer_callback_query_post_request->cache_time
    cJSON *cache_time = cJSON_GetObjectItemCaseSensitive(_answer_callback_query_post_requestJSON, "cache_time");
    if (cJSON_IsNull(cache_time)) {
        cache_time = NULL;
    }
    if (cache_time) { 
    if(!cJSON_IsNumber(cache_time))
    {
    goto end; //Numeric
    }
    }


    _answer_callback_query_post_request_local_var = _answer_callback_query_post_request_create_internal (
        strdup(callback_query_id->valuestring),
        text && !cJSON_IsNull(text) ? strdup(text->valuestring) : NULL,
        show_alert ? show_alert->valueint : 0,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL,
        cache_time ? cache_time->valuedouble : 0
        );

    return _answer_callback_query_post_request_local_var;
end:
    return NULL;

}
