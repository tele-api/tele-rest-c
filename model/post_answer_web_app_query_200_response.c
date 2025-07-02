#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_answer_web_app_query_200_response.h"



static post_answer_web_app_query_200_response_t *post_answer_web_app_query_200_response_create_internal(
    int ok,
    sent_web_app_message_t *result
    ) {
    post_answer_web_app_query_200_response_t *post_answer_web_app_query_200_response_local_var = malloc(sizeof(post_answer_web_app_query_200_response_t));
    if (!post_answer_web_app_query_200_response_local_var) {
        return NULL;
    }
    post_answer_web_app_query_200_response_local_var->ok = ok;
    post_answer_web_app_query_200_response_local_var->result = result;

    post_answer_web_app_query_200_response_local_var->_library_owned = 1;
    return post_answer_web_app_query_200_response_local_var;
}

__attribute__((deprecated)) post_answer_web_app_query_200_response_t *post_answer_web_app_query_200_response_create(
    int ok,
    sent_web_app_message_t *result
    ) {
    return post_answer_web_app_query_200_response_create_internal (
        ok,
        result
        );
}

void post_answer_web_app_query_200_response_free(post_answer_web_app_query_200_response_t *post_answer_web_app_query_200_response) {
    if(NULL == post_answer_web_app_query_200_response){
        return ;
    }
    if(post_answer_web_app_query_200_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_answer_web_app_query_200_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_answer_web_app_query_200_response->result) {
        sent_web_app_message_free(post_answer_web_app_query_200_response->result);
        post_answer_web_app_query_200_response->result = NULL;
    }
    free(post_answer_web_app_query_200_response);
}

cJSON *post_answer_web_app_query_200_response_convertToJSON(post_answer_web_app_query_200_response_t *post_answer_web_app_query_200_response) {
    cJSON *item = cJSON_CreateObject();

    // post_answer_web_app_query_200_response->ok
    if (!post_answer_web_app_query_200_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", post_answer_web_app_query_200_response->ok) == NULL) {
    goto fail; //Bool
    }


    // post_answer_web_app_query_200_response->result
    if (!post_answer_web_app_query_200_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = sent_web_app_message_convertToJSON(post_answer_web_app_query_200_response->result);
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

post_answer_web_app_query_200_response_t *post_answer_web_app_query_200_response_parseFromJSON(cJSON *post_answer_web_app_query_200_responseJSON){

    post_answer_web_app_query_200_response_t *post_answer_web_app_query_200_response_local_var = NULL;

    // define the local variable for post_answer_web_app_query_200_response->result
    sent_web_app_message_t *result_local_nonprim = NULL;

    // post_answer_web_app_query_200_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(post_answer_web_app_query_200_responseJSON, "ok");
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

    // post_answer_web_app_query_200_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(post_answer_web_app_query_200_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = sent_web_app_message_parseFromJSON(result); //nonprimitive


    post_answer_web_app_query_200_response_local_var = post_answer_web_app_query_200_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return post_answer_web_app_query_200_response_local_var;
end:
    if (result_local_nonprim) {
        sent_web_app_message_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
