#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_answer_web_app_query_request.h"



static post_answer_web_app_query_request_t *post_answer_web_app_query_request_create_internal(
    char *web_app_query_id,
    inline_query_result_t *result
    ) {
    post_answer_web_app_query_request_t *post_answer_web_app_query_request_local_var = malloc(sizeof(post_answer_web_app_query_request_t));
    if (!post_answer_web_app_query_request_local_var) {
        return NULL;
    }
    post_answer_web_app_query_request_local_var->web_app_query_id = web_app_query_id;
    post_answer_web_app_query_request_local_var->result = result;

    post_answer_web_app_query_request_local_var->_library_owned = 1;
    return post_answer_web_app_query_request_local_var;
}

__attribute__((deprecated)) post_answer_web_app_query_request_t *post_answer_web_app_query_request_create(
    char *web_app_query_id,
    inline_query_result_t *result
    ) {
    return post_answer_web_app_query_request_create_internal (
        web_app_query_id,
        result
        );
}

void post_answer_web_app_query_request_free(post_answer_web_app_query_request_t *post_answer_web_app_query_request) {
    if(NULL == post_answer_web_app_query_request){
        return ;
    }
    if(post_answer_web_app_query_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_answer_web_app_query_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_answer_web_app_query_request->web_app_query_id) {
        free(post_answer_web_app_query_request->web_app_query_id);
        post_answer_web_app_query_request->web_app_query_id = NULL;
    }
    if (post_answer_web_app_query_request->result) {
        inline_query_result_free(post_answer_web_app_query_request->result);
        post_answer_web_app_query_request->result = NULL;
    }
    free(post_answer_web_app_query_request);
}

cJSON *post_answer_web_app_query_request_convertToJSON(post_answer_web_app_query_request_t *post_answer_web_app_query_request) {
    cJSON *item = cJSON_CreateObject();

    // post_answer_web_app_query_request->web_app_query_id
    if (!post_answer_web_app_query_request->web_app_query_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "web_app_query_id", post_answer_web_app_query_request->web_app_query_id) == NULL) {
    goto fail; //String
    }


    // post_answer_web_app_query_request->result
    if (!post_answer_web_app_query_request->result) {
        goto fail;
    }
    cJSON *result_local_JSON = inline_query_result_convertToJSON(post_answer_web_app_query_request->result);
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

post_answer_web_app_query_request_t *post_answer_web_app_query_request_parseFromJSON(cJSON *post_answer_web_app_query_requestJSON){

    post_answer_web_app_query_request_t *post_answer_web_app_query_request_local_var = NULL;

    // define the local variable for post_answer_web_app_query_request->result
    inline_query_result_t *result_local_nonprim = NULL;

    // post_answer_web_app_query_request->web_app_query_id
    cJSON *web_app_query_id = cJSON_GetObjectItemCaseSensitive(post_answer_web_app_query_requestJSON, "web_app_query_id");
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

    // post_answer_web_app_query_request->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(post_answer_web_app_query_requestJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = inline_query_result_parseFromJSON(result); //nonprimitive


    post_answer_web_app_query_request_local_var = post_answer_web_app_query_request_create_internal (
        strdup(web_app_query_id->valuestring),
        result_local_nonprim
        );

    return post_answer_web_app_query_request_local_var;
end:
    if (result_local_nonprim) {
        inline_query_result_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
