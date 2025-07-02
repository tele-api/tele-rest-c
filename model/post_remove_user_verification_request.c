#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_remove_user_verification_request.h"



static post_remove_user_verification_request_t *post_remove_user_verification_request_create_internal(
    int user_id
    ) {
    post_remove_user_verification_request_t *post_remove_user_verification_request_local_var = malloc(sizeof(post_remove_user_verification_request_t));
    if (!post_remove_user_verification_request_local_var) {
        return NULL;
    }
    post_remove_user_verification_request_local_var->user_id = user_id;

    post_remove_user_verification_request_local_var->_library_owned = 1;
    return post_remove_user_verification_request_local_var;
}

__attribute__((deprecated)) post_remove_user_verification_request_t *post_remove_user_verification_request_create(
    int user_id
    ) {
    return post_remove_user_verification_request_create_internal (
        user_id
        );
}

void post_remove_user_verification_request_free(post_remove_user_verification_request_t *post_remove_user_verification_request) {
    if(NULL == post_remove_user_verification_request){
        return ;
    }
    if(post_remove_user_verification_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_remove_user_verification_request_free");
        return ;
    }
    listEntry_t *listEntry;
    free(post_remove_user_verification_request);
}

cJSON *post_remove_user_verification_request_convertToJSON(post_remove_user_verification_request_t *post_remove_user_verification_request) {
    cJSON *item = cJSON_CreateObject();

    // post_remove_user_verification_request->user_id
    if (!post_remove_user_verification_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", post_remove_user_verification_request->user_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_remove_user_verification_request_t *post_remove_user_verification_request_parseFromJSON(cJSON *post_remove_user_verification_requestJSON){

    post_remove_user_verification_request_t *post_remove_user_verification_request_local_var = NULL;

    // post_remove_user_verification_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(post_remove_user_verification_requestJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(user_id))
    {
    goto end; //Numeric
    }


    post_remove_user_verification_request_local_var = post_remove_user_verification_request_create_internal (
        user_id->valuedouble
        );

    return post_remove_user_verification_request_local_var;
end:
    return NULL;

}
