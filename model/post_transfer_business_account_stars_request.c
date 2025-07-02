#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_transfer_business_account_stars_request.h"



static post_transfer_business_account_stars_request_t *post_transfer_business_account_stars_request_create_internal(
    char *business_connection_id,
    int star_count
    ) {
    post_transfer_business_account_stars_request_t *post_transfer_business_account_stars_request_local_var = malloc(sizeof(post_transfer_business_account_stars_request_t));
    if (!post_transfer_business_account_stars_request_local_var) {
        return NULL;
    }
    post_transfer_business_account_stars_request_local_var->business_connection_id = business_connection_id;
    post_transfer_business_account_stars_request_local_var->star_count = star_count;

    post_transfer_business_account_stars_request_local_var->_library_owned = 1;
    return post_transfer_business_account_stars_request_local_var;
}

__attribute__((deprecated)) post_transfer_business_account_stars_request_t *post_transfer_business_account_stars_request_create(
    char *business_connection_id,
    int star_count
    ) {
    return post_transfer_business_account_stars_request_create_internal (
        business_connection_id,
        star_count
        );
}

void post_transfer_business_account_stars_request_free(post_transfer_business_account_stars_request_t *post_transfer_business_account_stars_request) {
    if(NULL == post_transfer_business_account_stars_request){
        return ;
    }
    if(post_transfer_business_account_stars_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_transfer_business_account_stars_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_transfer_business_account_stars_request->business_connection_id) {
        free(post_transfer_business_account_stars_request->business_connection_id);
        post_transfer_business_account_stars_request->business_connection_id = NULL;
    }
    free(post_transfer_business_account_stars_request);
}

cJSON *post_transfer_business_account_stars_request_convertToJSON(post_transfer_business_account_stars_request_t *post_transfer_business_account_stars_request) {
    cJSON *item = cJSON_CreateObject();

    // post_transfer_business_account_stars_request->business_connection_id
    if (!post_transfer_business_account_stars_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", post_transfer_business_account_stars_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // post_transfer_business_account_stars_request->star_count
    if (!post_transfer_business_account_stars_request->star_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "star_count", post_transfer_business_account_stars_request->star_count) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_transfer_business_account_stars_request_t *post_transfer_business_account_stars_request_parseFromJSON(cJSON *post_transfer_business_account_stars_requestJSON){

    post_transfer_business_account_stars_request_t *post_transfer_business_account_stars_request_local_var = NULL;

    // post_transfer_business_account_stars_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_transfer_business_account_stars_requestJSON, "business_connection_id");
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

    // post_transfer_business_account_stars_request->star_count
    cJSON *star_count = cJSON_GetObjectItemCaseSensitive(post_transfer_business_account_stars_requestJSON, "star_count");
    if (cJSON_IsNull(star_count)) {
        star_count = NULL;
    }
    if (!star_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(star_count))
    {
    goto end; //Numeric
    }


    post_transfer_business_account_stars_request_local_var = post_transfer_business_account_stars_request_create_internal (
        strdup(business_connection_id->valuestring),
        star_count->valuedouble
        );

    return post_transfer_business_account_stars_request_local_var;
end:
    return NULL;

}
