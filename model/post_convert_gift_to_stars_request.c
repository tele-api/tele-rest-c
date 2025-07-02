#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_convert_gift_to_stars_request.h"



static post_convert_gift_to_stars_request_t *post_convert_gift_to_stars_request_create_internal(
    char *business_connection_id,
    char *owned_gift_id
    ) {
    post_convert_gift_to_stars_request_t *post_convert_gift_to_stars_request_local_var = malloc(sizeof(post_convert_gift_to_stars_request_t));
    if (!post_convert_gift_to_stars_request_local_var) {
        return NULL;
    }
    post_convert_gift_to_stars_request_local_var->business_connection_id = business_connection_id;
    post_convert_gift_to_stars_request_local_var->owned_gift_id = owned_gift_id;

    post_convert_gift_to_stars_request_local_var->_library_owned = 1;
    return post_convert_gift_to_stars_request_local_var;
}

__attribute__((deprecated)) post_convert_gift_to_stars_request_t *post_convert_gift_to_stars_request_create(
    char *business_connection_id,
    char *owned_gift_id
    ) {
    return post_convert_gift_to_stars_request_create_internal (
        business_connection_id,
        owned_gift_id
        );
}

void post_convert_gift_to_stars_request_free(post_convert_gift_to_stars_request_t *post_convert_gift_to_stars_request) {
    if(NULL == post_convert_gift_to_stars_request){
        return ;
    }
    if(post_convert_gift_to_stars_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_convert_gift_to_stars_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_convert_gift_to_stars_request->business_connection_id) {
        free(post_convert_gift_to_stars_request->business_connection_id);
        post_convert_gift_to_stars_request->business_connection_id = NULL;
    }
    if (post_convert_gift_to_stars_request->owned_gift_id) {
        free(post_convert_gift_to_stars_request->owned_gift_id);
        post_convert_gift_to_stars_request->owned_gift_id = NULL;
    }
    free(post_convert_gift_to_stars_request);
}

cJSON *post_convert_gift_to_stars_request_convertToJSON(post_convert_gift_to_stars_request_t *post_convert_gift_to_stars_request) {
    cJSON *item = cJSON_CreateObject();

    // post_convert_gift_to_stars_request->business_connection_id
    if (!post_convert_gift_to_stars_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", post_convert_gift_to_stars_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // post_convert_gift_to_stars_request->owned_gift_id
    if (!post_convert_gift_to_stars_request->owned_gift_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "owned_gift_id", post_convert_gift_to_stars_request->owned_gift_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_convert_gift_to_stars_request_t *post_convert_gift_to_stars_request_parseFromJSON(cJSON *post_convert_gift_to_stars_requestJSON){

    post_convert_gift_to_stars_request_t *post_convert_gift_to_stars_request_local_var = NULL;

    // post_convert_gift_to_stars_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_convert_gift_to_stars_requestJSON, "business_connection_id");
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

    // post_convert_gift_to_stars_request->owned_gift_id
    cJSON *owned_gift_id = cJSON_GetObjectItemCaseSensitive(post_convert_gift_to_stars_requestJSON, "owned_gift_id");
    if (cJSON_IsNull(owned_gift_id)) {
        owned_gift_id = NULL;
    }
    if (!owned_gift_id) {
        goto end;
    }

    
    if(!cJSON_IsString(owned_gift_id))
    {
    goto end; //String
    }


    post_convert_gift_to_stars_request_local_var = post_convert_gift_to_stars_request_create_internal (
        strdup(business_connection_id->valuestring),
        strdup(owned_gift_id->valuestring)
        );

    return post_convert_gift_to_stars_request_local_var;
end:
    return NULL;

}
