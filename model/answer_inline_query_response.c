#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "answer_inline_query_response.h"



static answer_inline_query_response_t *answer_inline_query_response_create_internal(
    int ok,
    int result
    ) {
    answer_inline_query_response_t *answer_inline_query_response_local_var = malloc(sizeof(answer_inline_query_response_t));
    if (!answer_inline_query_response_local_var) {
        return NULL;
    }
    answer_inline_query_response_local_var->ok = ok;
    answer_inline_query_response_local_var->result = result;

    answer_inline_query_response_local_var->_library_owned = 1;
    return answer_inline_query_response_local_var;
}

__attribute__((deprecated)) answer_inline_query_response_t *answer_inline_query_response_create(
    int ok,
    int result
    ) {
    return answer_inline_query_response_create_internal (
        ok,
        result
        );
}

void answer_inline_query_response_free(answer_inline_query_response_t *answer_inline_query_response) {
    if(NULL == answer_inline_query_response){
        return ;
    }
    if(answer_inline_query_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "answer_inline_query_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(answer_inline_query_response);
}

cJSON *answer_inline_query_response_convertToJSON(answer_inline_query_response_t *answer_inline_query_response) {
    cJSON *item = cJSON_CreateObject();

    // answer_inline_query_response->ok
    if (!answer_inline_query_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", answer_inline_query_response->ok) == NULL) {
    goto fail; //Bool
    }


    // answer_inline_query_response->result
    if (!answer_inline_query_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", answer_inline_query_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

answer_inline_query_response_t *answer_inline_query_response_parseFromJSON(cJSON *answer_inline_query_responseJSON){

    answer_inline_query_response_t *answer_inline_query_response_local_var = NULL;

    // answer_inline_query_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(answer_inline_query_responseJSON, "ok");
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

    // answer_inline_query_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(answer_inline_query_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    if(!cJSON_IsBool(result))
    {
    goto end; //Bool
    }


    answer_inline_query_response_local_var = answer_inline_query_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return answer_inline_query_response_local_var;
end:
    return NULL;

}
