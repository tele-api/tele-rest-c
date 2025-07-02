#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_answer_callback_query_request.h"



static post_answer_callback_query_request_t *post_answer_callback_query_request_create_internal(
    char *callback_query_id,
    char *text,
    int show_alert,
    char *url,
    int cache_time
    ) {
    post_answer_callback_query_request_t *post_answer_callback_query_request_local_var = malloc(sizeof(post_answer_callback_query_request_t));
    if (!post_answer_callback_query_request_local_var) {
        return NULL;
    }
    post_answer_callback_query_request_local_var->callback_query_id = callback_query_id;
    post_answer_callback_query_request_local_var->text = text;
    post_answer_callback_query_request_local_var->show_alert = show_alert;
    post_answer_callback_query_request_local_var->url = url;
    post_answer_callback_query_request_local_var->cache_time = cache_time;

    post_answer_callback_query_request_local_var->_library_owned = 1;
    return post_answer_callback_query_request_local_var;
}

__attribute__((deprecated)) post_answer_callback_query_request_t *post_answer_callback_query_request_create(
    char *callback_query_id,
    char *text,
    int show_alert,
    char *url,
    int cache_time
    ) {
    return post_answer_callback_query_request_create_internal (
        callback_query_id,
        text,
        show_alert,
        url,
        cache_time
        );
}

void post_answer_callback_query_request_free(post_answer_callback_query_request_t *post_answer_callback_query_request) {
    if(NULL == post_answer_callback_query_request){
        return ;
    }
    if(post_answer_callback_query_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_answer_callback_query_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_answer_callback_query_request->callback_query_id) {
        free(post_answer_callback_query_request->callback_query_id);
        post_answer_callback_query_request->callback_query_id = NULL;
    }
    if (post_answer_callback_query_request->text) {
        free(post_answer_callback_query_request->text);
        post_answer_callback_query_request->text = NULL;
    }
    if (post_answer_callback_query_request->url) {
        free(post_answer_callback_query_request->url);
        post_answer_callback_query_request->url = NULL;
    }
    free(post_answer_callback_query_request);
}

cJSON *post_answer_callback_query_request_convertToJSON(post_answer_callback_query_request_t *post_answer_callback_query_request) {
    cJSON *item = cJSON_CreateObject();

    // post_answer_callback_query_request->callback_query_id
    if (!post_answer_callback_query_request->callback_query_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "callback_query_id", post_answer_callback_query_request->callback_query_id) == NULL) {
    goto fail; //String
    }


    // post_answer_callback_query_request->text
    if(post_answer_callback_query_request->text) {
    if(cJSON_AddStringToObject(item, "text", post_answer_callback_query_request->text) == NULL) {
    goto fail; //String
    }
    }


    // post_answer_callback_query_request->show_alert
    if(post_answer_callback_query_request->show_alert) {
    if(cJSON_AddBoolToObject(item, "show_alert", post_answer_callback_query_request->show_alert) == NULL) {
    goto fail; //Bool
    }
    }


    // post_answer_callback_query_request->url
    if(post_answer_callback_query_request->url) {
    if(cJSON_AddStringToObject(item, "url", post_answer_callback_query_request->url) == NULL) {
    goto fail; //String
    }
    }


    // post_answer_callback_query_request->cache_time
    if(post_answer_callback_query_request->cache_time) {
    if(cJSON_AddNumberToObject(item, "cache_time", post_answer_callback_query_request->cache_time) == NULL) {
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

post_answer_callback_query_request_t *post_answer_callback_query_request_parseFromJSON(cJSON *post_answer_callback_query_requestJSON){

    post_answer_callback_query_request_t *post_answer_callback_query_request_local_var = NULL;

    // post_answer_callback_query_request->callback_query_id
    cJSON *callback_query_id = cJSON_GetObjectItemCaseSensitive(post_answer_callback_query_requestJSON, "callback_query_id");
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

    // post_answer_callback_query_request->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(post_answer_callback_query_requestJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (text) { 
    if(!cJSON_IsString(text) && !cJSON_IsNull(text))
    {
    goto end; //String
    }
    }

    // post_answer_callback_query_request->show_alert
    cJSON *show_alert = cJSON_GetObjectItemCaseSensitive(post_answer_callback_query_requestJSON, "show_alert");
    if (cJSON_IsNull(show_alert)) {
        show_alert = NULL;
    }
    if (show_alert) { 
    if(!cJSON_IsBool(show_alert))
    {
    goto end; //Bool
    }
    }

    // post_answer_callback_query_request->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(post_answer_callback_query_requestJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }

    // post_answer_callback_query_request->cache_time
    cJSON *cache_time = cJSON_GetObjectItemCaseSensitive(post_answer_callback_query_requestJSON, "cache_time");
    if (cJSON_IsNull(cache_time)) {
        cache_time = NULL;
    }
    if (cache_time) { 
    if(!cJSON_IsNumber(cache_time))
    {
    goto end; //Numeric
    }
    }


    post_answer_callback_query_request_local_var = post_answer_callback_query_request_create_internal (
        strdup(callback_query_id->valuestring),
        text && !cJSON_IsNull(text) ? strdup(text->valuestring) : NULL,
        show_alert ? show_alert->valueint : 0,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL,
        cache_time ? cache_time->valuedouble : 0
        );

    return post_answer_callback_query_request_local_var;
end:
    return NULL;

}
