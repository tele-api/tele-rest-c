#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "close_forum_topic_response.h"



static close_forum_topic_response_t *close_forum_topic_response_create_internal(
    int ok,
    int result
    ) {
    close_forum_topic_response_t *close_forum_topic_response_local_var = malloc(sizeof(close_forum_topic_response_t));
    if (!close_forum_topic_response_local_var) {
        return NULL;
    }
    close_forum_topic_response_local_var->ok = ok;
    close_forum_topic_response_local_var->result = result;

    close_forum_topic_response_local_var->_library_owned = 1;
    return close_forum_topic_response_local_var;
}

__attribute__((deprecated)) close_forum_topic_response_t *close_forum_topic_response_create(
    int ok,
    int result
    ) {
    return close_forum_topic_response_create_internal (
        ok,
        result
        );
}

void close_forum_topic_response_free(close_forum_topic_response_t *close_forum_topic_response) {
    if(NULL == close_forum_topic_response){
        return ;
    }
    if(close_forum_topic_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "close_forum_topic_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(close_forum_topic_response);
}

cJSON *close_forum_topic_response_convertToJSON(close_forum_topic_response_t *close_forum_topic_response) {
    cJSON *item = cJSON_CreateObject();

    // close_forum_topic_response->ok
    if (!close_forum_topic_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", close_forum_topic_response->ok) == NULL) {
    goto fail; //Bool
    }


    // close_forum_topic_response->result
    if (!close_forum_topic_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", close_forum_topic_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

close_forum_topic_response_t *close_forum_topic_response_parseFromJSON(cJSON *close_forum_topic_responseJSON){

    close_forum_topic_response_t *close_forum_topic_response_local_var = NULL;

    // close_forum_topic_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(close_forum_topic_responseJSON, "ok");
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

    // close_forum_topic_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(close_forum_topic_responseJSON, "result");
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


    close_forum_topic_response_local_var = close_forum_topic_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return close_forum_topic_response_local_var;
end:
    return NULL;

}
