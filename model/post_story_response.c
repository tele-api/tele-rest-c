#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_story_response.h"



static post_story_response_t *post_story_response_create_internal(
    int ok,
    story_t *result
    ) {
    post_story_response_t *post_story_response_local_var = malloc(sizeof(post_story_response_t));
    if (!post_story_response_local_var) {
        return NULL;
    }
    post_story_response_local_var->ok = ok;
    post_story_response_local_var->result = result;

    post_story_response_local_var->_library_owned = 1;
    return post_story_response_local_var;
}

__attribute__((deprecated)) post_story_response_t *post_story_response_create(
    int ok,
    story_t *result
    ) {
    return post_story_response_create_internal (
        ok,
        result
        );
}

void post_story_response_free(post_story_response_t *post_story_response) {
    if(NULL == post_story_response){
        return ;
    }
    if(post_story_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_story_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_story_response->result) {
        story_free(post_story_response->result);
        post_story_response->result = NULL;
    }
    free(post_story_response);
}

cJSON *post_story_response_convertToJSON(post_story_response_t *post_story_response) {
    cJSON *item = cJSON_CreateObject();

    // post_story_response->ok
    if (!post_story_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", post_story_response->ok) == NULL) {
    goto fail; //Bool
    }


    // post_story_response->result
    if (!post_story_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = story_convertToJSON(post_story_response->result);
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

post_story_response_t *post_story_response_parseFromJSON(cJSON *post_story_responseJSON){

    post_story_response_t *post_story_response_local_var = NULL;

    // define the local variable for post_story_response->result
    story_t *result_local_nonprim = NULL;

    // post_story_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(post_story_responseJSON, "ok");
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

    // post_story_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(post_story_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = story_parseFromJSON(result); //nonprimitive


    post_story_response_local_var = post_story_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return post_story_response_local_var;
end:
    if (result_local_nonprim) {
        story_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
