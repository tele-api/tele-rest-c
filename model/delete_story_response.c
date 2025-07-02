#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delete_story_response.h"



static delete_story_response_t *delete_story_response_create_internal(
    int ok,
    int result
    ) {
    delete_story_response_t *delete_story_response_local_var = malloc(sizeof(delete_story_response_t));
    if (!delete_story_response_local_var) {
        return NULL;
    }
    delete_story_response_local_var->ok = ok;
    delete_story_response_local_var->result = result;

    delete_story_response_local_var->_library_owned = 1;
    return delete_story_response_local_var;
}

__attribute__((deprecated)) delete_story_response_t *delete_story_response_create(
    int ok,
    int result
    ) {
    return delete_story_response_create_internal (
        ok,
        result
        );
}

void delete_story_response_free(delete_story_response_t *delete_story_response) {
    if(NULL == delete_story_response){
        return ;
    }
    if(delete_story_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delete_story_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(delete_story_response);
}

cJSON *delete_story_response_convertToJSON(delete_story_response_t *delete_story_response) {
    cJSON *item = cJSON_CreateObject();

    // delete_story_response->ok
    if (!delete_story_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", delete_story_response->ok) == NULL) {
    goto fail; //Bool
    }


    // delete_story_response->result
    if (!delete_story_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", delete_story_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

delete_story_response_t *delete_story_response_parseFromJSON(cJSON *delete_story_responseJSON){

    delete_story_response_t *delete_story_response_local_var = NULL;

    // delete_story_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(delete_story_responseJSON, "ok");
    if (cJSON_IsNull(ok)) {
        ok = NULL;
    }
    if (!ok) {
        goto end;
    }

    
    if(!cJSON_IsBool(ok))
    {
    goto end; //Bool
    }

    // delete_story_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(delete_story_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    if(!cJSON_IsBool(result))
    {
    goto end; //Bool
    }


    delete_story_response_local_var = delete_story_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return delete_story_response_local_var;
end:
    return NULL;

}
