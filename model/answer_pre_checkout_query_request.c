#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "answer_pre_checkout_query_request.h"



static answer_pre_checkout_query_request_t *answer_pre_checkout_query_request_create_internal(
    char *pre_checkout_query_id,
    int ok,
    char *error_message
    ) {
    answer_pre_checkout_query_request_t *answer_pre_checkout_query_request_local_var = malloc(sizeof(answer_pre_checkout_query_request_t));
    if (!answer_pre_checkout_query_request_local_var) {
        return NULL;
    }
    answer_pre_checkout_query_request_local_var->pre_checkout_query_id = pre_checkout_query_id;
    answer_pre_checkout_query_request_local_var->ok = ok;
    answer_pre_checkout_query_request_local_var->error_message = error_message;

    answer_pre_checkout_query_request_local_var->_library_owned = 1;
    return answer_pre_checkout_query_request_local_var;
}

__attribute__((deprecated)) answer_pre_checkout_query_request_t *answer_pre_checkout_query_request_create(
    char *pre_checkout_query_id,
    int ok,
    char *error_message
    ) {
    return answer_pre_checkout_query_request_create_internal (
        pre_checkout_query_id,
        ok,
        error_message
        );
}

void answer_pre_checkout_query_request_free(answer_pre_checkout_query_request_t *answer_pre_checkout_query_request) {
    if(NULL == answer_pre_checkout_query_request){
        return ;
    }
    if(answer_pre_checkout_query_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "answer_pre_checkout_query_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (answer_pre_checkout_query_request->pre_checkout_query_id) {
        free(answer_pre_checkout_query_request->pre_checkout_query_id);
        answer_pre_checkout_query_request->pre_checkout_query_id = NULL;
    }
    if (answer_pre_checkout_query_request->error_message) {
        free(answer_pre_checkout_query_request->error_message);
        answer_pre_checkout_query_request->error_message = NULL;
    }
    free(answer_pre_checkout_query_request);
}

cJSON *answer_pre_checkout_query_request_convertToJSON(answer_pre_checkout_query_request_t *answer_pre_checkout_query_request) {
    cJSON *item = cJSON_CreateObject();

    // answer_pre_checkout_query_request->pre_checkout_query_id
    if (!answer_pre_checkout_query_request->pre_checkout_query_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "pre_checkout_query_id", answer_pre_checkout_query_request->pre_checkout_query_id) == NULL) {
    goto fail; //String
    }


    // answer_pre_checkout_query_request->ok
    if (!answer_pre_checkout_query_request->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", answer_pre_checkout_query_request->ok) == NULL) {
    goto fail; //Bool
    }


    // answer_pre_checkout_query_request->error_message
    if(answer_pre_checkout_query_request->error_message) {
    if(cJSON_AddStringToObject(item, "error_message", answer_pre_checkout_query_request->error_message) == NULL) {
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

answer_pre_checkout_query_request_t *answer_pre_checkout_query_request_parseFromJSON(cJSON *answer_pre_checkout_query_requestJSON){

    answer_pre_checkout_query_request_t *answer_pre_checkout_query_request_local_var = NULL;

    // answer_pre_checkout_query_request->pre_checkout_query_id
    cJSON *pre_checkout_query_id = cJSON_GetObjectItemCaseSensitive(answer_pre_checkout_query_requestJSON, "pre_checkout_query_id");
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

    // answer_pre_checkout_query_request->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(answer_pre_checkout_query_requestJSON, "ok");
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

    // answer_pre_checkout_query_request->error_message
    cJSON *error_message = cJSON_GetObjectItemCaseSensitive(answer_pre_checkout_query_requestJSON, "error_message");
    if (cJSON_IsNull(error_message)) {
        error_message = NULL;
    }
    if (error_message) { 
    if(!cJSON_IsString(error_message) && !cJSON_IsNull(error_message))
    {
    goto end; //String
    }
    }


    answer_pre_checkout_query_request_local_var = answer_pre_checkout_query_request_create_internal (
        strdup(pre_checkout_query_id->valuestring),
        ok->valueint,
        error_message && !cJSON_IsNull(error_message) ? strdup(error_message->valuestring) : NULL
        );

    return answer_pre_checkout_query_request_local_var;
end:
    return NULL;

}
