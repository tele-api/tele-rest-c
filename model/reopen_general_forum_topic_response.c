#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reopen_general_forum_topic_response.h"



static reopen_general_forum_topic_response_t *reopen_general_forum_topic_response_create_internal(
    int ok,
    int result
    ) {
    reopen_general_forum_topic_response_t *reopen_general_forum_topic_response_local_var = malloc(sizeof(reopen_general_forum_topic_response_t));
    if (!reopen_general_forum_topic_response_local_var) {
        return NULL;
    }
    reopen_general_forum_topic_response_local_var->ok = ok;
    reopen_general_forum_topic_response_local_var->result = result;

    reopen_general_forum_topic_response_local_var->_library_owned = 1;
    return reopen_general_forum_topic_response_local_var;
}

__attribute__((deprecated)) reopen_general_forum_topic_response_t *reopen_general_forum_topic_response_create(
    int ok,
    int result
    ) {
    return reopen_general_forum_topic_response_create_internal (
        ok,
        result
        );
}

void reopen_general_forum_topic_response_free(reopen_general_forum_topic_response_t *reopen_general_forum_topic_response) {
    if(NULL == reopen_general_forum_topic_response){
        return ;
    }
    if(reopen_general_forum_topic_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reopen_general_forum_topic_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(reopen_general_forum_topic_response);
}

cJSON *reopen_general_forum_topic_response_convertToJSON(reopen_general_forum_topic_response_t *reopen_general_forum_topic_response) {
    cJSON *item = cJSON_CreateObject();

    // reopen_general_forum_topic_response->ok
    if (!reopen_general_forum_topic_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", reopen_general_forum_topic_response->ok) == NULL) {
    goto fail; //Bool
    }


    // reopen_general_forum_topic_response->result
    if (!reopen_general_forum_topic_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", reopen_general_forum_topic_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reopen_general_forum_topic_response_t *reopen_general_forum_topic_response_parseFromJSON(cJSON *reopen_general_forum_topic_responseJSON){

    reopen_general_forum_topic_response_t *reopen_general_forum_topic_response_local_var = NULL;

    // reopen_general_forum_topic_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(reopen_general_forum_topic_responseJSON, "ok");
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

    // reopen_general_forum_topic_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(reopen_general_forum_topic_responseJSON, "result");
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


    reopen_general_forum_topic_response_local_var = reopen_general_forum_topic_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return reopen_general_forum_topic_response_local_var;
end:
    return NULL;

}
