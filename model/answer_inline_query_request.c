#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "answer_inline_query_request.h"



static answer_inline_query_request_t *answer_inline_query_request_create_internal(
    char *inline_query_id,
    list_t *results,
    int cache_time,
    int is_personal,
    char *next_offset,
    inline_query_results_button_t *button
    ) {
    answer_inline_query_request_t *answer_inline_query_request_local_var = malloc(sizeof(answer_inline_query_request_t));
    if (!answer_inline_query_request_local_var) {
        return NULL;
    }
    answer_inline_query_request_local_var->inline_query_id = inline_query_id;
    answer_inline_query_request_local_var->results = results;
    answer_inline_query_request_local_var->cache_time = cache_time;
    answer_inline_query_request_local_var->is_personal = is_personal;
    answer_inline_query_request_local_var->next_offset = next_offset;
    answer_inline_query_request_local_var->button = button;

    answer_inline_query_request_local_var->_library_owned = 1;
    return answer_inline_query_request_local_var;
}

__attribute__((deprecated)) answer_inline_query_request_t *answer_inline_query_request_create(
    char *inline_query_id,
    list_t *results,
    int cache_time,
    int is_personal,
    char *next_offset,
    inline_query_results_button_t *button
    ) {
    return answer_inline_query_request_create_internal (
        inline_query_id,
        results,
        cache_time,
        is_personal,
        next_offset,
        button
        );
}

void answer_inline_query_request_free(answer_inline_query_request_t *answer_inline_query_request) {
    if(NULL == answer_inline_query_request){
        return ;
    }
    if(answer_inline_query_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "answer_inline_query_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (answer_inline_query_request->inline_query_id) {
        free(answer_inline_query_request->inline_query_id);
        answer_inline_query_request->inline_query_id = NULL;
    }
    if (answer_inline_query_request->results) {
        list_ForEach(listEntry, answer_inline_query_request->results) {
            inline_query_result_free(listEntry->data);
        }
        list_freeList(answer_inline_query_request->results);
        answer_inline_query_request->results = NULL;
    }
    if (answer_inline_query_request->next_offset) {
        free(answer_inline_query_request->next_offset);
        answer_inline_query_request->next_offset = NULL;
    }
    if (answer_inline_query_request->button) {
        inline_query_results_button_free(answer_inline_query_request->button);
        answer_inline_query_request->button = NULL;
    }
    free(answer_inline_query_request);
}

cJSON *answer_inline_query_request_convertToJSON(answer_inline_query_request_t *answer_inline_query_request) {
    cJSON *item = cJSON_CreateObject();

    // answer_inline_query_request->inline_query_id
    if (!answer_inline_query_request->inline_query_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "inline_query_id", answer_inline_query_request->inline_query_id) == NULL) {
    goto fail; //String
    }


    // answer_inline_query_request->results
    if (!answer_inline_query_request->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (answer_inline_query_request->results) {
    list_ForEach(resultsListEntry, answer_inline_query_request->results) {
    cJSON *itemLocal = inline_query_result_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // answer_inline_query_request->cache_time
    if(answer_inline_query_request->cache_time) {
    if(cJSON_AddNumberToObject(item, "cache_time", answer_inline_query_request->cache_time) == NULL) {
    goto fail; //Numeric
    }
    }


    // answer_inline_query_request->is_personal
    if(answer_inline_query_request->is_personal) {
    if(cJSON_AddBoolToObject(item, "is_personal", answer_inline_query_request->is_personal) == NULL) {
    goto fail; //Bool
    }
    }


    // answer_inline_query_request->next_offset
    if(answer_inline_query_request->next_offset) {
    if(cJSON_AddStringToObject(item, "next_offset", answer_inline_query_request->next_offset) == NULL) {
    goto fail; //String
    }
    }


    // answer_inline_query_request->button
    if(answer_inline_query_request->button) {
    cJSON *button_local_JSON = inline_query_results_button_convertToJSON(answer_inline_query_request->button);
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

answer_inline_query_request_t *answer_inline_query_request_parseFromJSON(cJSON *answer_inline_query_requestJSON){

    answer_inline_query_request_t *answer_inline_query_request_local_var = NULL;

    // define the local list for answer_inline_query_request->results
    list_t *resultsList = NULL;

    // define the local variable for answer_inline_query_request->button
    inline_query_results_button_t *button_local_nonprim = NULL;

    // answer_inline_query_request->inline_query_id
    cJSON *inline_query_id = cJSON_GetObjectItemCaseSensitive(answer_inline_query_requestJSON, "inline_query_id");
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

    // answer_inline_query_request->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(answer_inline_query_requestJSON, "results");
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

    // answer_inline_query_request->cache_time
    cJSON *cache_time = cJSON_GetObjectItemCaseSensitive(answer_inline_query_requestJSON, "cache_time");
    if (cJSON_IsNull(cache_time)) {
        cache_time = NULL;
    }
    if (cache_time) { 
    if(!cJSON_IsNumber(cache_time))
    {
    goto end; //Numeric
    }
    }

    // answer_inline_query_request->is_personal
    cJSON *is_personal = cJSON_GetObjectItemCaseSensitive(answer_inline_query_requestJSON, "is_personal");
    if (cJSON_IsNull(is_personal)) {
        is_personal = NULL;
    }
    if (is_personal) { 
    if(!cJSON_IsBool(is_personal))
    {
    goto end; //Bool
    }
    }

    // answer_inline_query_request->next_offset
    cJSON *next_offset = cJSON_GetObjectItemCaseSensitive(answer_inline_query_requestJSON, "next_offset");
    if (cJSON_IsNull(next_offset)) {
        next_offset = NULL;
    }
    if (next_offset) { 
    if(!cJSON_IsString(next_offset) && !cJSON_IsNull(next_offset))
    {
    goto end; //String
    }
    }

    // answer_inline_query_request->button
    cJSON *button = cJSON_GetObjectItemCaseSensitive(answer_inline_query_requestJSON, "button");
    if (cJSON_IsNull(button)) {
        button = NULL;
    }
    if (button) { 
    button_local_nonprim = inline_query_results_button_parseFromJSON(button); //nonprimitive
    }


    answer_inline_query_request_local_var = answer_inline_query_request_create_internal (
        strdup(inline_query_id->valuestring),
        resultsList,
        cache_time ? cache_time->valuedouble : 0,
        is_personal ? is_personal->valueint : 0,
        next_offset && !cJSON_IsNull(next_offset) ? strdup(next_offset->valuestring) : NULL,
        button ? button_local_nonprim : NULL
        );

    return answer_inline_query_request_local_var;
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
