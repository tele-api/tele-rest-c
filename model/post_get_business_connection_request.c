#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_get_business_connection_request.h"



static post_get_business_connection_request_t *post_get_business_connection_request_create_internal(
    char *business_connection_id
    ) {
    post_get_business_connection_request_t *post_get_business_connection_request_local_var = malloc(sizeof(post_get_business_connection_request_t));
    if (!post_get_business_connection_request_local_var) {
        return NULL;
    }
    post_get_business_connection_request_local_var->business_connection_id = business_connection_id;

    post_get_business_connection_request_local_var->_library_owned = 1;
    return post_get_business_connection_request_local_var;
}

__attribute__((deprecated)) post_get_business_connection_request_t *post_get_business_connection_request_create(
    char *business_connection_id
    ) {
    return post_get_business_connection_request_create_internal (
        business_connection_id
        );
}

void post_get_business_connection_request_free(post_get_business_connection_request_t *post_get_business_connection_request) {
    if(NULL == post_get_business_connection_request){
        return ;
    }
    if(post_get_business_connection_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_get_business_connection_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_get_business_connection_request->business_connection_id) {
        free(post_get_business_connection_request->business_connection_id);
        post_get_business_connection_request->business_connection_id = NULL;
    }
    free(post_get_business_connection_request);
}

cJSON *post_get_business_connection_request_convertToJSON(post_get_business_connection_request_t *post_get_business_connection_request) {
    cJSON *item = cJSON_CreateObject();

    // post_get_business_connection_request->business_connection_id
    if (!post_get_business_connection_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", post_get_business_connection_request->business_connection_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_get_business_connection_request_t *post_get_business_connection_request_parseFromJSON(cJSON *post_get_business_connection_requestJSON){

    post_get_business_connection_request_t *post_get_business_connection_request_local_var = NULL;

    // post_get_business_connection_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_get_business_connection_requestJSON, "business_connection_id");
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


    post_get_business_connection_request_local_var = post_get_business_connection_request_create_internal (
        strdup(business_connection_id->valuestring)
        );

    return post_get_business_connection_request_local_var;
end:
    return NULL;

}
