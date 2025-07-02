#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_delete_story_request.h"



static post_delete_story_request_t *post_delete_story_request_create_internal(
    char *business_connection_id,
    int story_id
    ) {
    post_delete_story_request_t *post_delete_story_request_local_var = malloc(sizeof(post_delete_story_request_t));
    if (!post_delete_story_request_local_var) {
        return NULL;
    }
    post_delete_story_request_local_var->business_connection_id = business_connection_id;
    post_delete_story_request_local_var->story_id = story_id;

    post_delete_story_request_local_var->_library_owned = 1;
    return post_delete_story_request_local_var;
}

__attribute__((deprecated)) post_delete_story_request_t *post_delete_story_request_create(
    char *business_connection_id,
    int story_id
    ) {
    return post_delete_story_request_create_internal (
        business_connection_id,
        story_id
        );
}

void post_delete_story_request_free(post_delete_story_request_t *post_delete_story_request) {
    if(NULL == post_delete_story_request){
        return ;
    }
    if(post_delete_story_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_delete_story_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_delete_story_request->business_connection_id) {
        free(post_delete_story_request->business_connection_id);
        post_delete_story_request->business_connection_id = NULL;
    }
    free(post_delete_story_request);
}

cJSON *post_delete_story_request_convertToJSON(post_delete_story_request_t *post_delete_story_request) {
    cJSON *item = cJSON_CreateObject();

    // post_delete_story_request->business_connection_id
    if (!post_delete_story_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", post_delete_story_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // post_delete_story_request->story_id
    if (!post_delete_story_request->story_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "story_id", post_delete_story_request->story_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_delete_story_request_t *post_delete_story_request_parseFromJSON(cJSON *post_delete_story_requestJSON){

    post_delete_story_request_t *post_delete_story_request_local_var = NULL;

    // post_delete_story_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_delete_story_requestJSON, "business_connection_id");
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

    // post_delete_story_request->story_id
    cJSON *story_id = cJSON_GetObjectItemCaseSensitive(post_delete_story_requestJSON, "story_id");
    if (cJSON_IsNull(story_id)) {
        story_id = NULL;
    }
    if (!story_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(story_id))
    {
    goto end; //Numeric
    }


    post_delete_story_request_local_var = post_delete_story_request_create_internal (
        strdup(business_connection_id->valuestring),
        story_id->valuedouble
        );

    return post_delete_story_request_local_var;
end:
    return NULL;

}
