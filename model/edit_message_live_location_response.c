#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "edit_message_live_location_response.h"



static edit_message_live_location_response_t *edit_message_live_location_response_create_internal(
    int ok,
    edit_message_text_response_result_t *result
    ) {
    edit_message_live_location_response_t *edit_message_live_location_response_local_var = malloc(sizeof(edit_message_live_location_response_t));
    if (!edit_message_live_location_response_local_var) {
        return NULL;
    }
    edit_message_live_location_response_local_var->ok = ok;
    edit_message_live_location_response_local_var->result = result;

    edit_message_live_location_response_local_var->_library_owned = 1;
    return edit_message_live_location_response_local_var;
}

__attribute__((deprecated)) edit_message_live_location_response_t *edit_message_live_location_response_create(
    int ok,
    edit_message_text_response_result_t *result
    ) {
    return edit_message_live_location_response_create_internal (
        ok,
        result
        );
}

void edit_message_live_location_response_free(edit_message_live_location_response_t *edit_message_live_location_response) {
    if(NULL == edit_message_live_location_response){
        return ;
    }
    if(edit_message_live_location_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "edit_message_live_location_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (edit_message_live_location_response->result) {
        edit_message_text_response_result_free(edit_message_live_location_response->result);
        edit_message_live_location_response->result = NULL;
    }
    free(edit_message_live_location_response);
}

cJSON *edit_message_live_location_response_convertToJSON(edit_message_live_location_response_t *edit_message_live_location_response) {
    cJSON *item = cJSON_CreateObject();

    // edit_message_live_location_response->ok
    if (!edit_message_live_location_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", edit_message_live_location_response->ok) == NULL) {
    goto fail; //Bool
    }


    // edit_message_live_location_response->result
    if (!edit_message_live_location_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = edit_message_text_response_result_convertToJSON(edit_message_live_location_response->result);
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

edit_message_live_location_response_t *edit_message_live_location_response_parseFromJSON(cJSON *edit_message_live_location_responseJSON){

    edit_message_live_location_response_t *edit_message_live_location_response_local_var = NULL;

    // define the local variable for edit_message_live_location_response->result
    edit_message_text_response_result_t *result_local_nonprim = NULL;

    // edit_message_live_location_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(edit_message_live_location_responseJSON, "ok");
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

    // edit_message_live_location_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(edit_message_live_location_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = edit_message_text_response_result_parseFromJSON(result); //nonprimitive


    edit_message_live_location_response_local_var = edit_message_live_location_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return edit_message_live_location_response_local_var;
end:
    if (result_local_nonprim) {
        edit_message_text_response_result_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
