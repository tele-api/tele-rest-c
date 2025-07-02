#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_edit_message_text_200_response.h"



static post_edit_message_text_200_response_t *post_edit_message_text_200_response_create_internal(
    int ok,
    post_edit_message_text_200_response_result_t *result
    ) {
    post_edit_message_text_200_response_t *post_edit_message_text_200_response_local_var = malloc(sizeof(post_edit_message_text_200_response_t));
    if (!post_edit_message_text_200_response_local_var) {
        return NULL;
    }
    post_edit_message_text_200_response_local_var->ok = ok;
    post_edit_message_text_200_response_local_var->result = result;

    post_edit_message_text_200_response_local_var->_library_owned = 1;
    return post_edit_message_text_200_response_local_var;
}

__attribute__((deprecated)) post_edit_message_text_200_response_t *post_edit_message_text_200_response_create(
    int ok,
    post_edit_message_text_200_response_result_t *result
    ) {
    return post_edit_message_text_200_response_create_internal (
        ok,
        result
        );
}

void post_edit_message_text_200_response_free(post_edit_message_text_200_response_t *post_edit_message_text_200_response) {
    if(NULL == post_edit_message_text_200_response){
        return ;
    }
    if(post_edit_message_text_200_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_edit_message_text_200_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_edit_message_text_200_response->result) {
        post_edit_message_text_200_response_result_free(post_edit_message_text_200_response->result);
        post_edit_message_text_200_response->result = NULL;
    }
    free(post_edit_message_text_200_response);
}

cJSON *post_edit_message_text_200_response_convertToJSON(post_edit_message_text_200_response_t *post_edit_message_text_200_response) {
    cJSON *item = cJSON_CreateObject();

    // post_edit_message_text_200_response->ok
    if (!post_edit_message_text_200_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", post_edit_message_text_200_response->ok) == NULL) {
    goto fail; //Bool
    }


    // post_edit_message_text_200_response->result
    if (!post_edit_message_text_200_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = post_edit_message_text_200_response_result_convertToJSON(post_edit_message_text_200_response->result);
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

post_edit_message_text_200_response_t *post_edit_message_text_200_response_parseFromJSON(cJSON *post_edit_message_text_200_responseJSON){

    post_edit_message_text_200_response_t *post_edit_message_text_200_response_local_var = NULL;

    // define the local variable for post_edit_message_text_200_response->result
    post_edit_message_text_200_response_result_t *result_local_nonprim = NULL;

    // post_edit_message_text_200_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(post_edit_message_text_200_responseJSON, "ok");
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

    // post_edit_message_text_200_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(post_edit_message_text_200_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = post_edit_message_text_200_response_result_parseFromJSON(result); //nonprimitive


    post_edit_message_text_200_response_local_var = post_edit_message_text_200_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return post_edit_message_text_200_response_local_var;
end:
    if (result_local_nonprim) {
        post_edit_message_text_200_response_result_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
