#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_answer_inline_query_post_request.h"



static _answer_inline_query_post_request_t *_answer_inline_query_post_request_create_internal(
    char *inline_query_id,
    list_t *results,
    int cache_time,
    int is_personal,
    char *next_offset,
    inline_query_results_button_t *button
    ) {
    _answer_inline_query_post_request_t *_answer_inline_query_post_request_local_var = malloc(sizeof(_answer_inline_query_post_request_t));
    if (!_answer_inline_query_post_request_local_var) {
        return NULL;
    }
    _answer_inline_query_post_request_local_var->inline_query_id = inline_query_id;
    _answer_inline_query_post_request_local_var->results = results;
    _answer_inline_query_post_request_local_var->cache_time = cache_time;
    _answer_inline_query_post_request_local_var->is_personal = is_personal;
    _answer_inline_query_post_request_local_var->next_offset = next_offset;
    _answer_inline_query_post_request_local_var->button = button;

    _answer_inline_query_post_request_local_var->_library_owned = 1;
    return _answer_inline_query_post_request_local_var;
}

__attribute__((deprecated)) _answer_inline_query_post_request_t *_answer_inline_query_post_request_create(
    char *inline_query_id,
    list_t *results,
    int cache_time,
    int is_personal,
    char *next_offset,
    inline_query_results_button_t *button
    ) {
    return _answer_inline_query_post_request_create_internal (
        inline_query_id,
        results,
        cache_time,
        is_personal,
        next_offset,
        button
        );
}

void _answer_inline_query_post_request_free(_answer_inline_query_post_request_t *_answer_inline_query_post_request) {
    if(NULL == _answer_inline_query_post_request){
        return ;
    }
    if(_answer_inline_query_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_answer_inline_query_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_answer_inline_query_post_request->inline_query_id) {
        free(_answer_inline_query_post_request->inline_query_id);
        _answer_inline_query_post_request->inline_query_id = NULL;
    }
    if (_answer_inline_query_post_request->results) {
        list_ForEach(listEntry, _answer_inline_query_post_request->results) {
            inline_query_result_free(listEntry->data);
        }
        list_freeList(_answer_inline_query_post_request->results);
        _answer_inline_query_post_request->results = NULL;
    }
    if (_answer_inline_query_post_request->next_offset) {
        free(_answer_inline_query_post_request->next_offset);
        _answer_inline_query_post_request->next_offset = NULL;
    }
    if (_answer_inline_query_post_request->button) {
        inline_query_results_button_free(_answer_inline_query_post_request->button);
        _answer_inline_query_post_request->button = NULL;
    }
    free(_answer_inline_query_post_request);
}

cJSON *_answer_inline_query_post_request_convertToJSON(_answer_inline_query_post_request_t *_answer_inline_query_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _answer_inline_query_post_request->inline_query_id
    if (!_answer_inline_query_post_request->inline_query_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "inline_query_id", _answer_inline_query_post_request->inline_query_id) == NULL) {
    goto fail; //String
    }


    // _answer_inline_query_post_request->results
    if (!_answer_inline_query_post_request->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (_answer_inline_query_post_request->results) {
    list_ForEach(resultsListEntry, _answer_inline_query_post_request->results) {
    cJSON *itemLocal = inline_query_result_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // _answer_inline_query_post_request->cache_time
    if(_answer_inline_query_post_request->cache_time) {
    if(cJSON_AddNumberToObject(item, "cache_time", _answer_inline_query_post_request->cache_time) == NULL) {
    goto fail; //Numeric
    }
    }


    // _answer_inline_query_post_request->is_personal
    if(_answer_inline_query_post_request->is_personal) {
    if(cJSON_AddBoolToObject(item, "is_personal", _answer_inline_query_post_request->is_personal) == NULL) {
    goto fail; //Bool
    }
    }


    // _answer_inline_query_post_request->next_offset
    if(_answer_inline_query_post_request->next_offset) {
    if(cJSON_AddStringToObject(item, "next_offset", _answer_inline_query_post_request->next_offset) == NULL) {
    goto fail; //String
    }
    }


    // _answer_inline_query_post_request->button
    if(_answer_inline_query_post_request->button) {
    cJSON *button_local_JSON = inline_query_results_button_convertToJSON(_answer_inline_query_post_request->button);
    if(button_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "button", button_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_answer_inline_query_post_request_t *_answer_inline_query_post_request_parseFromJSON(cJSON *_answer_inline_query_post_requestJSON){

    _answer_inline_query_post_request_t *_answer_inline_query_post_request_local_var = NULL;

    // define the local list for _answer_inline_query_post_request->results
    list_t *resultsList = NULL;

    // define the local variable for _answer_inline_query_post_request->button
    inline_query_results_button_t *button_local_nonprim = NULL;

    // _answer_inline_query_post_request->inline_query_id
    cJSON *inline_query_id = cJSON_GetObjectItemCaseSensitive(_answer_inline_query_post_requestJSON, "inline_query_id");
    if (cJSON_IsNull(inline_query_id)) {
        inline_query_id = NULL;
    }
    if (!inline_query_id) {
        goto end;
    }

    
    if(!cJSON_IsString(inline_query_id))
    {
    goto end; //String
    }

    // _answer_inline_query_post_request->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(_answer_inline_query_post_requestJSON, "results");
    if (cJSON_IsNull(results)) {
        results = NULL;
    }
    if (!results) {
        goto end;
    }

    
    cJSON *results_local_nonprimitive = NULL;
    if(!cJSON_IsArray(results)){
        goto end; //nonprimitive container
    }

    resultsList = list_createList();

    cJSON_ArrayForEach(results_local_nonprimitive,results )
    {
        if(!cJSON_IsObject(results_local_nonprimitive)){
            goto end;
        }
        inline_query_result_t *resultsItem = inline_query_result_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // _answer_inline_query_post_request->cache_time
    cJSON *cache_time = cJSON_GetObjectItemCaseSensitive(_answer_inline_query_post_requestJSON, "cache_time");
    if (cJSON_IsNull(cache_time)) {
        cache_time = NULL;
    }
    if (cache_time) { 
    if(!cJSON_IsNumber(cache_time))
    {
    goto end; //Numeric
    }
    }

    // _answer_inline_query_post_request->is_personal
    cJSON *is_personal = cJSON_GetObjectItemCaseSensitive(_answer_inline_query_post_requestJSON, "is_personal");
    if (cJSON_IsNull(is_personal)) {
        is_personal = NULL;
    }
    if (is_personal) { 
    if(!cJSON_IsBool(is_personal))
    {
    goto end; //Bool
    }
    }

    // _answer_inline_query_post_request->next_offset
    cJSON *next_offset = cJSON_GetObjectItemCaseSensitive(_answer_inline_query_post_requestJSON, "next_offset");
    if (cJSON_IsNull(next_offset)) {
        next_offset = NULL;
    }
    if (next_offset) { 
    if(!cJSON_IsString(next_offset) && !cJSON_IsNull(next_offset))
    {
    goto end; //String
    }
    }

    // _answer_inline_query_post_request->button
    cJSON *button = cJSON_GetObjectItemCaseSensitive(_answer_inline_query_post_requestJSON, "button");
    if (cJSON_IsNull(button)) {
        button = NULL;
    }
    if (button) { 
    button_local_nonprim = inline_query_results_button_parseFromJSON(button); //nonprimitive
    }


    _answer_inline_query_post_request_local_var = _answer_inline_query_post_request_create_internal (
        strdup(inline_query_id->valuestring),
        resultsList,
        cache_time ? cache_time->valuedouble : 0,
        is_personal ? is_personal->valueint : 0,
        next_offset && !cJSON_IsNull(next_offset) ? strdup(next_offset->valuestring) : NULL,
        button ? button_local_nonprim : NULL
        );

    return _answer_inline_query_post_request_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            inline_query_result_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    if (button_local_nonprim) {
        inline_query_results_button_free(button_local_nonprim);
        button_local_nonprim = NULL;
    }
    return NULL;

}
