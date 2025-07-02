#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_get_user_profile_photos_request.h"



static post_get_user_profile_photos_request_t *post_get_user_profile_photos_request_create_internal(
    int user_id,
    int offset,
    int limit
    ) {
    post_get_user_profile_photos_request_t *post_get_user_profile_photos_request_local_var = malloc(sizeof(post_get_user_profile_photos_request_t));
    if (!post_get_user_profile_photos_request_local_var) {
        return NULL;
    }
    post_get_user_profile_photos_request_local_var->user_id = user_id;
    post_get_user_profile_photos_request_local_var->offset = offset;
    post_get_user_profile_photos_request_local_var->limit = limit;

    post_get_user_profile_photos_request_local_var->_library_owned = 1;
    return post_get_user_profile_photos_request_local_var;
}

__attribute__((deprecated)) post_get_user_profile_photos_request_t *post_get_user_profile_photos_request_create(
    int user_id,
    int offset,
    int limit
    ) {
    return post_get_user_profile_photos_request_create_internal (
        user_id,
        offset,
        limit
        );
}

void post_get_user_profile_photos_request_free(post_get_user_profile_photos_request_t *post_get_user_profile_photos_request) {
    if(NULL == post_get_user_profile_photos_request){
        return ;
    }
    if(post_get_user_profile_photos_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_get_user_profile_photos_request_free");
        return ;
    }
    listEntry_t *listEntry;
    free(post_get_user_profile_photos_request);
}

cJSON *post_get_user_profile_photos_request_convertToJSON(post_get_user_profile_photos_request_t *post_get_user_profile_photos_request) {
    cJSON *item = cJSON_CreateObject();

    // post_get_user_profile_photos_request->user_id
    if (!post_get_user_profile_photos_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", post_get_user_profile_photos_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // post_get_user_profile_photos_request->offset
    if(post_get_user_profile_photos_request->offset) {
    if(cJSON_AddNumberToObject(item, "offset", post_get_user_profile_photos_request->offset) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_get_user_profile_photos_request->limit
    if(post_get_user_profile_photos_request->limit) {
    if(cJSON_AddNumberToObject(item, "limit", post_get_user_profile_photos_request->limit) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_get_user_profile_photos_request_t *post_get_user_profile_photos_request_parseFromJSON(cJSON *post_get_user_profile_photos_requestJSON){

    post_get_user_profile_photos_request_t *post_get_user_profile_photos_request_local_var = NULL;

    // post_get_user_profile_photos_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(post_get_user_profile_photos_requestJSON, "user_id");
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

    // post_get_user_profile_photos_request->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(post_get_user_profile_photos_requestJSON, "offset");
    if (cJSON_IsNull(offset)) {
        offset = NULL;
    }
    if (offset) { 
    if(!cJSON_IsNumber(offset))
    {
    goto end; //Numeric
    }
    }

    // post_get_user_profile_photos_request->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(post_get_user_profile_photos_requestJSON, "limit");
    if (cJSON_IsNull(limit)) {
        limit = NULL;
    }
    if (limit) { 
    if(!cJSON_IsNumber(limit))
    {
    goto end; //Numeric
    }
    }


    post_get_user_profile_photos_request_local_var = post_get_user_profile_photos_request_create_internal (
        user_id->valuedouble,
        offset ? offset->valuedouble : 0,
        limit ? limit->valuedouble : 0
        );

    return post_get_user_profile_photos_request_local_var;
end:
    return NULL;

}
