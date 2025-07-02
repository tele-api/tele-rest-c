#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_business_account_bio_request.h"



static post_set_business_account_bio_request_t *post_set_business_account_bio_request_create_internal(
    char *business_connection_id,
    char *bio
    ) {
    post_set_business_account_bio_request_t *post_set_business_account_bio_request_local_var = malloc(sizeof(post_set_business_account_bio_request_t));
    if (!post_set_business_account_bio_request_local_var) {
        return NULL;
    }
    post_set_business_account_bio_request_local_var->business_connection_id = business_connection_id;
    post_set_business_account_bio_request_local_var->bio = bio;

    post_set_business_account_bio_request_local_var->_library_owned = 1;
    return post_set_business_account_bio_request_local_var;
}

__attribute__((deprecated)) post_set_business_account_bio_request_t *post_set_business_account_bio_request_create(
    char *business_connection_id,
    char *bio
    ) {
    return post_set_business_account_bio_request_create_internal (
        business_connection_id,
        bio
        );
}

void post_set_business_account_bio_request_free(post_set_business_account_bio_request_t *post_set_business_account_bio_request) {
    if(NULL == post_set_business_account_bio_request){
        return ;
    }
    if(post_set_business_account_bio_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_business_account_bio_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_business_account_bio_request->business_connection_id) {
        free(post_set_business_account_bio_request->business_connection_id);
        post_set_business_account_bio_request->business_connection_id = NULL;
    }
    if (post_set_business_account_bio_request->bio) {
        free(post_set_business_account_bio_request->bio);
        post_set_business_account_bio_request->bio = NULL;
    }
    free(post_set_business_account_bio_request);
}

cJSON *post_set_business_account_bio_request_convertToJSON(post_set_business_account_bio_request_t *post_set_business_account_bio_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_business_account_bio_request->business_connection_id
    if (!post_set_business_account_bio_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", post_set_business_account_bio_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // post_set_business_account_bio_request->bio
    if(post_set_business_account_bio_request->bio) {
    if(cJSON_AddStringToObject(item, "bio", post_set_business_account_bio_request->bio) == NULL) {
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

post_set_business_account_bio_request_t *post_set_business_account_bio_request_parseFromJSON(cJSON *post_set_business_account_bio_requestJSON){

    post_set_business_account_bio_request_t *post_set_business_account_bio_request_local_var = NULL;

    // post_set_business_account_bio_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_set_business_account_bio_requestJSON, "business_connection_id");
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

    // post_set_business_account_bio_request->bio
    cJSON *bio = cJSON_GetObjectItemCaseSensitive(post_set_business_account_bio_requestJSON, "bio");
    if (cJSON_IsNull(bio)) {
        bio = NULL;
    }
    if (bio) { 
    if(!cJSON_IsString(bio) && !cJSON_IsNull(bio))
    {
    goto end; //String
    }
    }


    post_set_business_account_bio_request_local_var = post_set_business_account_bio_request_create_internal (
        strdup(business_connection_id->valuestring),
        bio && !cJSON_IsNull(bio) ? strdup(bio->valuestring) : NULL
        );

    return post_set_business_account_bio_request_local_var;
end:
    return NULL;

}
