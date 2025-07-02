#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delete_forum_topic_response.h"



static delete_forum_topic_response_t *delete_forum_topic_response_create_internal(
    int ok,
    int result
    ) {
    delete_forum_topic_response_t *delete_forum_topic_response_local_var = malloc(sizeof(delete_forum_topic_response_t));
    if (!delete_forum_topic_response_local_var) {
        return NULL;
    }
    delete_forum_topic_response_local_var->ok = ok;
    delete_forum_topic_response_local_var->result = result;

    delete_forum_topic_response_local_var->_library_owned = 1;
    return delete_forum_topic_response_local_var;
}

__attribute__((deprecated)) delete_forum_topic_response_t *delete_forum_topic_response_create(
    int ok,
    int result
    ) {
    return delete_forum_topic_response_create_internal (
        ok,
        result
        );
}

void delete_forum_topic_response_free(delete_forum_topic_response_t *delete_forum_topic_response) {
    if(NULL == delete_forum_topic_response){
        return ;
    }
    if(delete_forum_topic_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delete_forum_topic_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(delete_forum_topic_response);
}

cJSON *delete_forum_topic_response_convertToJSON(delete_forum_topic_response_t *delete_forum_topic_response) {
    cJSON *item = cJSON_CreateObject();

    // delete_forum_topic_response->ok
    if (!delete_forum_topic_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", delete_forum_topic_response->ok) == NULL) {
    goto fail; //Bool
    }


    // delete_forum_topic_response->result
    if (!delete_forum_topic_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", delete_forum_topic_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

delete_forum_topic_response_t *delete_forum_topic_response_parseFromJSON(cJSON *delete_forum_topic_responseJSON){

    delete_forum_topic_response_t *delete_forum_topic_response_local_var = NULL;

    // delete_forum_topic_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(delete_forum_topic_responseJSON, "ok");
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

    // delete_forum_topic_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(delete_forum_topic_responseJSON, "result");
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


    delete_forum_topic_response_local_var = delete_forum_topic_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return delete_forum_topic_response_local_var;
end:
    return NULL;

}
