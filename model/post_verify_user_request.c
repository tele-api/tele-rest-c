#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_verify_user_request.h"



static post_verify_user_request_t *post_verify_user_request_create_internal(
    int user_id,
    char *custom_description
    ) {
    post_verify_user_request_t *post_verify_user_request_local_var = malloc(sizeof(post_verify_user_request_t));
    if (!post_verify_user_request_local_var) {
        return NULL;
    }
    post_verify_user_request_local_var->user_id = user_id;
    post_verify_user_request_local_var->custom_description = custom_description;

    post_verify_user_request_local_var->_library_owned = 1;
    return post_verify_user_request_local_var;
}

__attribute__((deprecated)) post_verify_user_request_t *post_verify_user_request_create(
    int user_id,
    char *custom_description
    ) {
    return post_verify_user_request_create_internal (
        user_id,
        custom_description
        );
}

void post_verify_user_request_free(post_verify_user_request_t *post_verify_user_request) {
    if(NULL == post_verify_user_request){
        return ;
    }
    if(post_verify_user_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_verify_user_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_verify_user_request->custom_description) {
        free(post_verify_user_request->custom_description);
        post_verify_user_request->custom_description = NULL;
    }
    free(post_verify_user_request);
}

cJSON *post_verify_user_request_convertToJSON(post_verify_user_request_t *post_verify_user_request) {
    cJSON *item = cJSON_CreateObject();

    // post_verify_user_request->user_id
    if (!post_verify_user_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", post_verify_user_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // post_verify_user_request->custom_description
    if(post_verify_user_request->custom_description) {
    if(cJSON_AddStringToObject(item, "custom_description", post_verify_user_request->custom_description) == NULL) {
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

post_verify_user_request_t *post_verify_user_request_parseFromJSON(cJSON *post_verify_user_requestJSON){

    post_verify_user_request_t *post_verify_user_request_local_var = NULL;

    // post_verify_user_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(post_verify_user_requestJSON, "user_id");
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

    // post_verify_user_request->custom_description
    cJSON *custom_description = cJSON_GetObjectItemCaseSensitive(post_verify_user_requestJSON, "custom_description");
    if (cJSON_IsNull(custom_description)) {
        custom_description = NULL;
    }
    if (custom_description) { 
    if(!cJSON_IsString(custom_description) && !cJSON_IsNull(custom_description))
    {
    goto end; //String
    }
    }


    post_verify_user_request_local_var = post_verify_user_request_create_internal (
        user_id->valuedouble,
        custom_description && !cJSON_IsNull(custom_description) ? strdup(custom_description->valuestring) : NULL
        );

    return post_verify_user_request_local_var;
end:
    return NULL;

}
