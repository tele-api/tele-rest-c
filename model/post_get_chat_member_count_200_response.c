#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_get_chat_member_count_200_response.h"



static post_get_chat_member_count_200_response_t *post_get_chat_member_count_200_response_create_internal(
    int ok,
    int result
    ) {
    post_get_chat_member_count_200_response_t *post_get_chat_member_count_200_response_local_var = malloc(sizeof(post_get_chat_member_count_200_response_t));
    if (!post_get_chat_member_count_200_response_local_var) {
        return NULL;
    }
    post_get_chat_member_count_200_response_local_var->ok = ok;
    post_get_chat_member_count_200_response_local_var->result = result;

    post_get_chat_member_count_200_response_local_var->_library_owned = 1;
    return post_get_chat_member_count_200_response_local_var;
}

__attribute__((deprecated)) post_get_chat_member_count_200_response_t *post_get_chat_member_count_200_response_create(
    int ok,
    int result
    ) {
    return post_get_chat_member_count_200_response_create_internal (
        ok,
        result
        );
}

void post_get_chat_member_count_200_response_free(post_get_chat_member_count_200_response_t *post_get_chat_member_count_200_response) {
    if(NULL == post_get_chat_member_count_200_response){
        return ;
    }
    if(post_get_chat_member_count_200_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_get_chat_member_count_200_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(post_get_chat_member_count_200_response);
}

cJSON *post_get_chat_member_count_200_response_convertToJSON(post_get_chat_member_count_200_response_t *post_get_chat_member_count_200_response) {
    cJSON *item = cJSON_CreateObject();

    // post_get_chat_member_count_200_response->ok
    if (!post_get_chat_member_count_200_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", post_get_chat_member_count_200_response->ok) == NULL) {
    goto fail; //Bool
    }


    // post_get_chat_member_count_200_response->result
    if (!post_get_chat_member_count_200_response->result) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "result", post_get_chat_member_count_200_response->result) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_get_chat_member_count_200_response_t *post_get_chat_member_count_200_response_parseFromJSON(cJSON *post_get_chat_member_count_200_responseJSON){

    post_get_chat_member_count_200_response_t *post_get_chat_member_count_200_response_local_var = NULL;

    // post_get_chat_member_count_200_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(post_get_chat_member_count_200_responseJSON, "ok");
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

    // post_get_chat_member_count_200_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(post_get_chat_member_count_200_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    if(!cJSON_IsNumber(result))
    {
    goto end; //Numeric
    }


    post_get_chat_member_count_200_response_local_var = post_get_chat_member_count_200_response_create_internal (
        ok->valueint,
        result->valuedouble
        );

    return post_get_chat_member_count_200_response_local_var;
end:
    return NULL;

}
