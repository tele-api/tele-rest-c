#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_upgrade_gift_request.h"



static post_upgrade_gift_request_t *post_upgrade_gift_request_create_internal(
    char *business_connection_id,
    char *owned_gift_id,
    int keep_original_details,
    int star_count
    ) {
    post_upgrade_gift_request_t *post_upgrade_gift_request_local_var = malloc(sizeof(post_upgrade_gift_request_t));
    if (!post_upgrade_gift_request_local_var) {
        return NULL;
    }
    post_upgrade_gift_request_local_var->business_connection_id = business_connection_id;
    post_upgrade_gift_request_local_var->owned_gift_id = owned_gift_id;
    post_upgrade_gift_request_local_var->keep_original_details = keep_original_details;
    post_upgrade_gift_request_local_var->star_count = star_count;

    post_upgrade_gift_request_local_var->_library_owned = 1;
    return post_upgrade_gift_request_local_var;
}

__attribute__((deprecated)) post_upgrade_gift_request_t *post_upgrade_gift_request_create(
    char *business_connection_id,
    char *owned_gift_id,
    int keep_original_details,
    int star_count
    ) {
    return post_upgrade_gift_request_create_internal (
        business_connection_id,
        owned_gift_id,
        keep_original_details,
        star_count
        );
}

void post_upgrade_gift_request_free(post_upgrade_gift_request_t *post_upgrade_gift_request) {
    if(NULL == post_upgrade_gift_request){
        return ;
    }
    if(post_upgrade_gift_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_upgrade_gift_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_upgrade_gift_request->business_connection_id) {
        free(post_upgrade_gift_request->business_connection_id);
        post_upgrade_gift_request->business_connection_id = NULL;
    }
    if (post_upgrade_gift_request->owned_gift_id) {
        free(post_upgrade_gift_request->owned_gift_id);
        post_upgrade_gift_request->owned_gift_id = NULL;
    }
    free(post_upgrade_gift_request);
}

cJSON *post_upgrade_gift_request_convertToJSON(post_upgrade_gift_request_t *post_upgrade_gift_request) {
    cJSON *item = cJSON_CreateObject();

    // post_upgrade_gift_request->business_connection_id
    if (!post_upgrade_gift_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", post_upgrade_gift_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // post_upgrade_gift_request->owned_gift_id
    if (!post_upgrade_gift_request->owned_gift_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "owned_gift_id", post_upgrade_gift_request->owned_gift_id) == NULL) {
    goto fail; //String
    }


    // post_upgrade_gift_request->keep_original_details
    if(post_upgrade_gift_request->keep_original_details) {
    if(cJSON_AddBoolToObject(item, "keep_original_details", post_upgrade_gift_request->keep_original_details) == NULL) {
    goto fail; //Bool
    }
    }


    // post_upgrade_gift_request->star_count
    if(post_upgrade_gift_request->star_count) {
    if(cJSON_AddNumberToObject(item, "star_count", post_upgrade_gift_request->star_count) == NULL) {
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

post_upgrade_gift_request_t *post_upgrade_gift_request_parseFromJSON(cJSON *post_upgrade_gift_requestJSON){

    post_upgrade_gift_request_t *post_upgrade_gift_request_local_var = NULL;

    // post_upgrade_gift_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_upgrade_gift_requestJSON, "business_connection_id");
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

    // post_upgrade_gift_request->owned_gift_id
    cJSON *owned_gift_id = cJSON_GetObjectItemCaseSensitive(post_upgrade_gift_requestJSON, "owned_gift_id");
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

    // post_upgrade_gift_request->keep_original_details
    cJSON *keep_original_details = cJSON_GetObjectItemCaseSensitive(post_upgrade_gift_requestJSON, "keep_original_details");
    if (cJSON_IsNull(keep_original_details)) {
        keep_original_details = NULL;
    }
    if (keep_original_details) { 
    if(!cJSON_IsBool(keep_original_details))
    {
    goto end; //Bool
    }
    }

    // post_upgrade_gift_request->star_count
    cJSON *star_count = cJSON_GetObjectItemCaseSensitive(post_upgrade_gift_requestJSON, "star_count");
    if (cJSON_IsNull(star_count)) {
        star_count = NULL;
    }
    if (star_count) { 
    if(!cJSON_IsNumber(star_count))
    {
    goto end; //Numeric
    }
    }


    post_upgrade_gift_request_local_var = post_upgrade_gift_request_create_internal (
        strdup(business_connection_id->valuestring),
        strdup(owned_gift_id->valuestring),
        keep_original_details ? keep_original_details->valueint : 0,
        star_count ? star_count->valuedouble : 0
        );

    return post_upgrade_gift_request_local_var;
end:
    return NULL;

}
