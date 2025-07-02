#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_remove_business_account_profile_photo_request.h"



static post_remove_business_account_profile_photo_request_t *post_remove_business_account_profile_photo_request_create_internal(
    char *business_connection_id,
    int is_public
    ) {
    post_remove_business_account_profile_photo_request_t *post_remove_business_account_profile_photo_request_local_var = malloc(sizeof(post_remove_business_account_profile_photo_request_t));
    if (!post_remove_business_account_profile_photo_request_local_var) {
        return NULL;
    }
    post_remove_business_account_profile_photo_request_local_var->business_connection_id = business_connection_id;
    post_remove_business_account_profile_photo_request_local_var->is_public = is_public;

    post_remove_business_account_profile_photo_request_local_var->_library_owned = 1;
    return post_remove_business_account_profile_photo_request_local_var;
}

__attribute__((deprecated)) post_remove_business_account_profile_photo_request_t *post_remove_business_account_profile_photo_request_create(
    char *business_connection_id,
    int is_public
    ) {
    return post_remove_business_account_profile_photo_request_create_internal (
        business_connection_id,
        is_public
        );
}

void post_remove_business_account_profile_photo_request_free(post_remove_business_account_profile_photo_request_t *post_remove_business_account_profile_photo_request) {
    if(NULL == post_remove_business_account_profile_photo_request){
        return ;
    }
    if(post_remove_business_account_profile_photo_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_remove_business_account_profile_photo_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_remove_business_account_profile_photo_request->business_connection_id) {
        free(post_remove_business_account_profile_photo_request->business_connection_id);
        post_remove_business_account_profile_photo_request->business_connection_id = NULL;
    }
    free(post_remove_business_account_profile_photo_request);
}

cJSON *post_remove_business_account_profile_photo_request_convertToJSON(post_remove_business_account_profile_photo_request_t *post_remove_business_account_profile_photo_request) {
    cJSON *item = cJSON_CreateObject();

    // post_remove_business_account_profile_photo_request->business_connection_id
    if (!post_remove_business_account_profile_photo_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", post_remove_business_account_profile_photo_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // post_remove_business_account_profile_photo_request->is_public
    if(post_remove_business_account_profile_photo_request->is_public) {
    if(cJSON_AddBoolToObject(item, "is_public", post_remove_business_account_profile_photo_request->is_public) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_remove_business_account_profile_photo_request_t *post_remove_business_account_profile_photo_request_parseFromJSON(cJSON *post_remove_business_account_profile_photo_requestJSON){

    post_remove_business_account_profile_photo_request_t *post_remove_business_account_profile_photo_request_local_var = NULL;

    // post_remove_business_account_profile_photo_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_remove_business_account_profile_photo_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (!business_connection_id) {
        goto end;
    }

    
    if(!cJSON_IsString(business_connection_id))
    {
    goto end; //String
    }

    // post_remove_business_account_profile_photo_request->is_public
    cJSON *is_public = cJSON_GetObjectItemCaseSensitive(post_remove_business_account_profile_photo_requestJSON, "is_public");
    if (cJSON_IsNull(is_public)) {
        is_public = NULL;
    }
    if (is_public) { 
    if(!cJSON_IsBool(is_public))
    {
    goto end; //Bool
    }
    }


    post_remove_business_account_profile_photo_request_local_var = post_remove_business_account_profile_photo_request_create_internal (
        strdup(business_connection_id->valuestring),
        is_public ? is_public->valueint : 0
        );

    return post_remove_business_account_profile_photo_request_local_var;
end:
    return NULL;

}
