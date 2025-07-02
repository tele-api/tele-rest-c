#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "answer_web_app_query_response.h"



static answer_web_app_query_response_t *answer_web_app_query_response_create_internal(
    int ok,
    sent_web_app_message_t *result
    ) {
    answer_web_app_query_response_t *answer_web_app_query_response_local_var = malloc(sizeof(answer_web_app_query_response_t));
    if (!answer_web_app_query_response_local_var) {
        return NULL;
    }
    answer_web_app_query_response_local_var->ok = ok;
    answer_web_app_query_response_local_var->result = result;

    answer_web_app_query_response_local_var->_library_owned = 1;
    return answer_web_app_query_response_local_var;
}

__attribute__((deprecated)) answer_web_app_query_response_t *answer_web_app_query_response_create(
    int ok,
    sent_web_app_message_t *result
    ) {
    return answer_web_app_query_response_create_internal (
        ok,
        result
        );
}

void answer_web_app_query_response_free(answer_web_app_query_response_t *answer_web_app_query_response) {
    if(NULL == answer_web_app_query_response){
        return ;
    }
    if(answer_web_app_query_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "answer_web_app_query_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (answer_web_app_query_response->result) {
        sent_web_app_message_free(answer_web_app_query_response->result);
        answer_web_app_query_response->result = NULL;
    }
    free(answer_web_app_query_response);
}

cJSON *answer_web_app_query_response_convertToJSON(answer_web_app_query_response_t *answer_web_app_query_response) {
    cJSON *item = cJSON_CreateObject();

    // answer_web_app_query_response->ok
    if (!answer_web_app_query_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", answer_web_app_query_response->ok) == NULL) {
    goto fail; //Bool
    }


    // answer_web_app_query_response->result
    if (!answer_web_app_query_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = sent_web_app_message_convertToJSON(answer_web_app_query_response->result);
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

answer_web_app_query_response_t *answer_web_app_query_response_parseFromJSON(cJSON *answer_web_app_query_responseJSON){

    answer_web_app_query_response_t *answer_web_app_query_response_local_var = NULL;

    // define the local variable for answer_web_app_query_response->result
    sent_web_app_message_t *result_local_nonprim = NULL;

    // answer_web_app_query_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(answer_web_app_query_responseJSON, "ok");
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

    // answer_web_app_query_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(answer_web_app_query_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = sent_web_app_message_parseFromJSON(result); //nonprimitive


    answer_web_app_query_response_local_var = answer_web_app_query_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return answer_web_app_query_response_local_var;
end:
    if (result_local_nonprim) {
        sent_web_app_message_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
