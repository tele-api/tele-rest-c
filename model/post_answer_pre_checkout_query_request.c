#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_answer_pre_checkout_query_request.h"



static post_answer_pre_checkout_query_request_t *post_answer_pre_checkout_query_request_create_internal(
    char *pre_checkout_query_id,
    int ok,
    char *error_message
    ) {
    post_answer_pre_checkout_query_request_t *post_answer_pre_checkout_query_request_local_var = malloc(sizeof(post_answer_pre_checkout_query_request_t));
    if (!post_answer_pre_checkout_query_request_local_var) {
        return NULL;
    }
    post_answer_pre_checkout_query_request_local_var->pre_checkout_query_id = pre_checkout_query_id;
    post_answer_pre_checkout_query_request_local_var->ok = ok;
    post_answer_pre_checkout_query_request_local_var->error_message = error_message;

    post_answer_pre_checkout_query_request_local_var->_library_owned = 1;
    return post_answer_pre_checkout_query_request_local_var;
}

__attribute__((deprecated)) post_answer_pre_checkout_query_request_t *post_answer_pre_checkout_query_request_create(
    char *pre_checkout_query_id,
    int ok,
    char *error_message
    ) {
    return post_answer_pre_checkout_query_request_create_internal (
        pre_checkout_query_id,
        ok,
        error_message
        );
}

void post_answer_pre_checkout_query_request_free(post_answer_pre_checkout_query_request_t *post_answer_pre_checkout_query_request) {
    if(NULL == post_answer_pre_checkout_query_request){
        return ;
    }
    if(post_answer_pre_checkout_query_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_answer_pre_checkout_query_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_answer_pre_checkout_query_request->pre_checkout_query_id) {
        free(post_answer_pre_checkout_query_request->pre_checkout_query_id);
        post_answer_pre_checkout_query_request->pre_checkout_query_id = NULL;
    }
    if (post_answer_pre_checkout_query_request->error_message) {
        free(post_answer_pre_checkout_query_request->error_message);
        post_answer_pre_checkout_query_request->error_message = NULL;
    }
    free(post_answer_pre_checkout_query_request);
}

cJSON *post_answer_pre_checkout_query_request_convertToJSON(post_answer_pre_checkout_query_request_t *post_answer_pre_checkout_query_request) {
    cJSON *item = cJSON_CreateObject();

    // post_answer_pre_checkout_query_request->pre_checkout_query_id
    if (!post_answer_pre_checkout_query_request->pre_checkout_query_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "pre_checkout_query_id", post_answer_pre_checkout_query_request->pre_checkout_query_id) == NULL) {
    goto fail; //String
    }


    // post_answer_pre_checkout_query_request->ok
    if (!post_answer_pre_checkout_query_request->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", post_answer_pre_checkout_query_request->ok) == NULL) {
    goto fail; //Bool
    }


    // post_answer_pre_checkout_query_request->error_message
    if(post_answer_pre_checkout_query_request->error_message) {
    if(cJSON_AddStringToObject(item, "error_message", post_answer_pre_checkout_query_request->error_message) == NULL) {
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

post_answer_pre_checkout_query_request_t *post_answer_pre_checkout_query_request_parseFromJSON(cJSON *post_answer_pre_checkout_query_requestJSON){

    post_answer_pre_checkout_query_request_t *post_answer_pre_checkout_query_request_local_var = NULL;

    // post_answer_pre_checkout_query_request->pre_checkout_query_id
    cJSON *pre_checkout_query_id = cJSON_GetObjectItemCaseSensitive(post_answer_pre_checkout_query_requestJSON, "pre_checkout_query_id");
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

    // post_answer_pre_checkout_query_request->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(post_answer_pre_checkout_query_requestJSON, "ok");
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

    // post_answer_pre_checkout_query_request->error_message
    cJSON *error_message = cJSON_GetObjectItemCaseSensitive(post_answer_pre_checkout_query_requestJSON, "error_message");
    if (cJSON_IsNull(error_message)) {
        error_message = NULL;
    }
    if (error_message) { 
    if(!cJSON_IsString(error_message) && !cJSON_IsNull(error_message))
    {
    goto end; //String
    }
    }


    post_answer_pre_checkout_query_request_local_var = post_answer_pre_checkout_query_request_create_internal (
        strdup(pre_checkout_query_id->valuestring),
        ok->valueint,
        error_message && !cJSON_IsNull(error_message) ? strdup(error_message->valuestring) : NULL
        );

    return post_answer_pre_checkout_query_request_local_var;
end:
    return NULL;

}
