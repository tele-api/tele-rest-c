#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hide_general_forum_topic_response.h"



static hide_general_forum_topic_response_t *hide_general_forum_topic_response_create_internal(
    int ok,
    int result
    ) {
    hide_general_forum_topic_response_t *hide_general_forum_topic_response_local_var = malloc(sizeof(hide_general_forum_topic_response_t));
    if (!hide_general_forum_topic_response_local_var) {
        return NULL;
    }
    hide_general_forum_topic_response_local_var->ok = ok;
    hide_general_forum_topic_response_local_var->result = result;

    hide_general_forum_topic_response_local_var->_library_owned = 1;
    return hide_general_forum_topic_response_local_var;
}

__attribute__((deprecated)) hide_general_forum_topic_response_t *hide_general_forum_topic_response_create(
    int ok,
    int result
    ) {
    return hide_general_forum_topic_response_create_internal (
        ok,
        result
        );
}

void hide_general_forum_topic_response_free(hide_general_forum_topic_response_t *hide_general_forum_topic_response) {
    if(NULL == hide_general_forum_topic_response){
        return ;
    }
    if(hide_general_forum_topic_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "hide_general_forum_topic_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(hide_general_forum_topic_response);
}

cJSON *hide_general_forum_topic_response_convertToJSON(hide_general_forum_topic_response_t *hide_general_forum_topic_response) {
    cJSON *item = cJSON_CreateObject();

    // hide_general_forum_topic_response->ok
    if (!hide_general_forum_topic_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", hide_general_forum_topic_response->ok) == NULL) {
    goto fail; //Bool
    }


    // hide_general_forum_topic_response->result
    if (!hide_general_forum_topic_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", hide_general_forum_topic_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

hide_general_forum_topic_response_t *hide_general_forum_topic_response_parseFromJSON(cJSON *hide_general_forum_topic_responseJSON){

    hide_general_forum_topic_response_t *hide_general_forum_topic_response_local_var = NULL;

    // hide_general_forum_topic_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(hide_general_forum_topic_responseJSON, "ok");
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

    // hide_general_forum_topic_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(hide_general_forum_topic_responseJSON, "result");
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


    hide_general_forum_topic_response_local_var = hide_general_forum_topic_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return hide_general_forum_topic_response_local_var;
end:
    return NULL;

}
