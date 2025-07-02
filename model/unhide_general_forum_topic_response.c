#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unhide_general_forum_topic_response.h"



static unhide_general_forum_topic_response_t *unhide_general_forum_topic_response_create_internal(
    int ok,
    int result
    ) {
    unhide_general_forum_topic_response_t *unhide_general_forum_topic_response_local_var = malloc(sizeof(unhide_general_forum_topic_response_t));
    if (!unhide_general_forum_topic_response_local_var) {
        return NULL;
    }
    unhide_general_forum_topic_response_local_var->ok = ok;
    unhide_general_forum_topic_response_local_var->result = result;

    unhide_general_forum_topic_response_local_var->_library_owned = 1;
    return unhide_general_forum_topic_response_local_var;
}

__attribute__((deprecated)) unhide_general_forum_topic_response_t *unhide_general_forum_topic_response_create(
    int ok,
    int result
    ) {
    return unhide_general_forum_topic_response_create_internal (
        ok,
        result
        );
}

void unhide_general_forum_topic_response_free(unhide_general_forum_topic_response_t *unhide_general_forum_topic_response) {
    if(NULL == unhide_general_forum_topic_response){
        return ;
    }
    if(unhide_general_forum_topic_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "unhide_general_forum_topic_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(unhide_general_forum_topic_response);
}

cJSON *unhide_general_forum_topic_response_convertToJSON(unhide_general_forum_topic_response_t *unhide_general_forum_topic_response) {
    cJSON *item = cJSON_CreateObject();

    // unhide_general_forum_topic_response->ok
    if (!unhide_general_forum_topic_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", unhide_general_forum_topic_response->ok) == NULL) {
    goto fail; //Bool
    }


    // unhide_general_forum_topic_response->result
    if (!unhide_general_forum_topic_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", unhide_general_forum_topic_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

unhide_general_forum_topic_response_t *unhide_general_forum_topic_response_parseFromJSON(cJSON *unhide_general_forum_topic_responseJSON){

    unhide_general_forum_topic_response_t *unhide_general_forum_topic_response_local_var = NULL;

    // unhide_general_forum_topic_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(unhide_general_forum_topic_responseJSON, "ok");
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

    // unhide_general_forum_topic_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(unhide_general_forum_topic_responseJSON, "result");
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


    unhide_general_forum_topic_response_local_var = unhide_general_forum_topic_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return unhide_general_forum_topic_response_local_var;
end:
    return NULL;

}
