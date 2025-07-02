#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "save_prepared_inline_message_response.h"



static save_prepared_inline_message_response_t *save_prepared_inline_message_response_create_internal(
    int ok,
    prepared_inline_message_t *result
    ) {
    save_prepared_inline_message_response_t *save_prepared_inline_message_response_local_var = malloc(sizeof(save_prepared_inline_message_response_t));
    if (!save_prepared_inline_message_response_local_var) {
        return NULL;
    }
    save_prepared_inline_message_response_local_var->ok = ok;
    save_prepared_inline_message_response_local_var->result = result;

    save_prepared_inline_message_response_local_var->_library_owned = 1;
    return save_prepared_inline_message_response_local_var;
}

__attribute__((deprecated)) save_prepared_inline_message_response_t *save_prepared_inline_message_response_create(
    int ok,
    prepared_inline_message_t *result
    ) {
    return save_prepared_inline_message_response_create_internal (
        ok,
        result
        );
}

void save_prepared_inline_message_response_free(save_prepared_inline_message_response_t *save_prepared_inline_message_response) {
    if(NULL == save_prepared_inline_message_response){
        return ;
    }
    if(save_prepared_inline_message_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "save_prepared_inline_message_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (save_prepared_inline_message_response->result) {
        prepared_inline_message_free(save_prepared_inline_message_response->result);
        save_prepared_inline_message_response->result = NULL;
    }
    free(save_prepared_inline_message_response);
}

cJSON *save_prepared_inline_message_response_convertToJSON(save_prepared_inline_message_response_t *save_prepared_inline_message_response) {
    cJSON *item = cJSON_CreateObject();

    // save_prepared_inline_message_response->ok
    if (!save_prepared_inline_message_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", save_prepared_inline_message_response->ok) == NULL) {
    goto fail; //Bool
    }


    // save_prepared_inline_message_response->result
    if (!save_prepared_inline_message_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = prepared_inline_message_convertToJSON(save_prepared_inline_message_response->result);
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

save_prepared_inline_message_response_t *save_prepared_inline_message_response_parseFromJSON(cJSON *save_prepared_inline_message_responseJSON){

    save_prepared_inline_message_response_t *save_prepared_inline_message_response_local_var = NULL;

    // define the local variable for save_prepared_inline_message_response->result
    prepared_inline_message_t *result_local_nonprim = NULL;

    // save_prepared_inline_message_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(save_prepared_inline_message_responseJSON, "ok");
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

    // save_prepared_inline_message_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(save_prepared_inline_message_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = prepared_inline_message_parseFromJSON(result); //nonprimitive


    save_prepared_inline_message_response_local_var = save_prepared_inline_message_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return save_prepared_inline_message_response_local_var;
end:
    if (result_local_nonprim) {
        prepared_inline_message_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
