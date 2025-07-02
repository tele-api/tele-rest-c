#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "answer_web_app_query_request.h"



static answer_web_app_query_request_t *answer_web_app_query_request_create_internal(
    char *web_app_query_id,
    inline_query_result_t *result
    ) {
    answer_web_app_query_request_t *answer_web_app_query_request_local_var = malloc(sizeof(answer_web_app_query_request_t));
    if (!answer_web_app_query_request_local_var) {
        return NULL;
    }
    answer_web_app_query_request_local_var->web_app_query_id = web_app_query_id;
    answer_web_app_query_request_local_var->result = result;

    answer_web_app_query_request_local_var->_library_owned = 1;
    return answer_web_app_query_request_local_var;
}

__attribute__((deprecated)) answer_web_app_query_request_t *answer_web_app_query_request_create(
    char *web_app_query_id,
    inline_query_result_t *result
    ) {
    return answer_web_app_query_request_create_internal (
        web_app_query_id,
        result
        );
}

void answer_web_app_query_request_free(answer_web_app_query_request_t *answer_web_app_query_request) {
    if(NULL == answer_web_app_query_request){
        return ;
    }
    if(answer_web_app_query_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "answer_web_app_query_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (answer_web_app_query_request->web_app_query_id) {
        free(answer_web_app_query_request->web_app_query_id);
        answer_web_app_query_request->web_app_query_id = NULL;
    }
    if (answer_web_app_query_request->result) {
        inline_query_result_free(answer_web_app_query_request->result);
        answer_web_app_query_request->result = NULL;
    }
    free(answer_web_app_query_request);
}

cJSON *answer_web_app_query_request_convertToJSON(answer_web_app_query_request_t *answer_web_app_query_request) {
    cJSON *item = cJSON_CreateObject();

    // answer_web_app_query_request->web_app_query_id
    if (!answer_web_app_query_request->web_app_query_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "web_app_query_id", answer_web_app_query_request->web_app_query_id) == NULL) {
    goto fail; //String
    }


    // answer_web_app_query_request->result
    if (!answer_web_app_query_request->result) {
        goto fail;
    }
    cJSON *result_local_JSON = inline_query_result_convertToJSON(answer_web_app_query_request->result);
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

answer_web_app_query_request_t *answer_web_app_query_request_parseFromJSON(cJSON *answer_web_app_query_requestJSON){

    answer_web_app_query_request_t *answer_web_app_query_request_local_var = NULL;

    // define the local variable for answer_web_app_query_request->result
    inline_query_result_t *result_local_nonprim = NULL;

    // answer_web_app_query_request->web_app_query_id
    cJSON *web_app_query_id = cJSON_GetObjectItemCaseSensitive(answer_web_app_query_requestJSON, "web_app_query_id");
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

    // answer_web_app_query_request->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(answer_web_app_query_requestJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = inline_query_result_parseFromJSON(result); //nonprimitive


    answer_web_app_query_request_local_var = answer_web_app_query_request_create_internal (
        strdup(web_app_query_id->valuestring),
        result_local_nonprim
        );

    return answer_web_app_query_request_local_var;
end:
    if (result_local_nonprim) {
        inline_query_result_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
