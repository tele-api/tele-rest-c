#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "edit_story_response.h"



static edit_story_response_t *edit_story_response_create_internal(
    int ok,
    story_t *result
    ) {
    edit_story_response_t *edit_story_response_local_var = malloc(sizeof(edit_story_response_t));
    if (!edit_story_response_local_var) {
        return NULL;
    }
    edit_story_response_local_var->ok = ok;
    edit_story_response_local_var->result = result;

    edit_story_response_local_var->_library_owned = 1;
    return edit_story_response_local_var;
}

__attribute__((deprecated)) edit_story_response_t *edit_story_response_create(
    int ok,
    story_t *result
    ) {
    return edit_story_response_create_internal (
        ok,
        result
        );
}

void edit_story_response_free(edit_story_response_t *edit_story_response) {
    if(NULL == edit_story_response){
        return ;
    }
    if(edit_story_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "edit_story_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (edit_story_response->result) {
        story_free(edit_story_response->result);
        edit_story_response->result = NULL;
    }
    free(edit_story_response);
}

cJSON *edit_story_response_convertToJSON(edit_story_response_t *edit_story_response) {
    cJSON *item = cJSON_CreateObject();

    // edit_story_response->ok
    if (!edit_story_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", edit_story_response->ok) == NULL) {
    goto fail; //Bool
    }


    // edit_story_response->result
    if (!edit_story_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = story_convertToJSON(edit_story_response->result);
    if(result_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "result", result_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

edit_story_response_t *edit_story_response_parseFromJSON(cJSON *edit_story_responseJSON){

    edit_story_response_t *edit_story_response_local_var = NULL;

    // define the local variable for edit_story_response->result
    story_t *result_local_nonprim = NULL;

    // edit_story_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(edit_story_responseJSON, "ok");
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

    // edit_story_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(edit_story_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = story_parseFromJSON(result); //nonprimitive


    edit_story_response_local_var = edit_story_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return edit_story_response_local_var;
end:
    if (result_local_nonprim) {
        story_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
