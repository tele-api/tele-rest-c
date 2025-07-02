#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delete_story_request.h"



static delete_story_request_t *delete_story_request_create_internal(
    char *business_connection_id,
    int story_id
    ) {
    delete_story_request_t *delete_story_request_local_var = malloc(sizeof(delete_story_request_t));
    if (!delete_story_request_local_var) {
        return NULL;
    }
    delete_story_request_local_var->business_connection_id = business_connection_id;
    delete_story_request_local_var->story_id = story_id;

    delete_story_request_local_var->_library_owned = 1;
    return delete_story_request_local_var;
}

__attribute__((deprecated)) delete_story_request_t *delete_story_request_create(
    char *business_connection_id,
    int story_id
    ) {
    return delete_story_request_create_internal (
        business_connection_id,
        story_id
        );
}

void delete_story_request_free(delete_story_request_t *delete_story_request) {
    if(NULL == delete_story_request){
        return ;
    }
    if(delete_story_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delete_story_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (delete_story_request->business_connection_id) {
        free(delete_story_request->business_connection_id);
        delete_story_request->business_connection_id = NULL;
    }
    free(delete_story_request);
}

cJSON *delete_story_request_convertToJSON(delete_story_request_t *delete_story_request) {
    cJSON *item = cJSON_CreateObject();

    // delete_story_request->business_connection_id
    if (!delete_story_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", delete_story_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // delete_story_request->story_id
    if (!delete_story_request->story_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "story_id", delete_story_request->story_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

delete_story_request_t *delete_story_request_parseFromJSON(cJSON *delete_story_requestJSON){

    delete_story_request_t *delete_story_request_local_var = NULL;

    // delete_story_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(delete_story_requestJSON, "business_connection_id");
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

    // delete_story_request->story_id
    cJSON *story_id = cJSON_GetObjectItemCaseSensitive(delete_story_requestJSON, "story_id");
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


    delete_story_request_local_var = delete_story_request_create_internal (
        strdup(business_connection_id->valuestring),
        story_id->valuedouble
        );

    return delete_story_request_local_var;
end:
    return NULL;

}
