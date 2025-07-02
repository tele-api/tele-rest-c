#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "edit_forum_topic_response.h"



static edit_forum_topic_response_t *edit_forum_topic_response_create_internal(
    int ok,
    int result
    ) {
    edit_forum_topic_response_t *edit_forum_topic_response_local_var = malloc(sizeof(edit_forum_topic_response_t));
    if (!edit_forum_topic_response_local_var) {
        return NULL;
    }
    edit_forum_topic_response_local_var->ok = ok;
    edit_forum_topic_response_local_var->result = result;

    edit_forum_topic_response_local_var->_library_owned = 1;
    return edit_forum_topic_response_local_var;
}

__attribute__((deprecated)) edit_forum_topic_response_t *edit_forum_topic_response_create(
    int ok,
    int result
    ) {
    return edit_forum_topic_response_create_internal (
        ok,
        result
        );
}

void edit_forum_topic_response_free(edit_forum_topic_response_t *edit_forum_topic_response) {
    if(NULL == edit_forum_topic_response){
        return ;
    }
    if(edit_forum_topic_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "edit_forum_topic_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(edit_forum_topic_response);
}

cJSON *edit_forum_topic_response_convertToJSON(edit_forum_topic_response_t *edit_forum_topic_response) {
    cJSON *item = cJSON_CreateObject();

    // edit_forum_topic_response->ok
    if (!edit_forum_topic_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", edit_forum_topic_response->ok) == NULL) {
    goto fail; //Bool
    }


    // edit_forum_topic_response->result
    if (!edit_forum_topic_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", edit_forum_topic_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

edit_forum_topic_response_t *edit_forum_topic_response_parseFromJSON(cJSON *edit_forum_topic_responseJSON){

    edit_forum_topic_response_t *edit_forum_topic_response_local_var = NULL;

    // edit_forum_topic_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(edit_forum_topic_responseJSON, "ok");
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

    // edit_forum_topic_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(edit_forum_topic_responseJSON, "result");
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


    edit_forum_topic_response_local_var = edit_forum_topic_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return edit_forum_topic_response_local_var;
end:
    return NULL;

}
