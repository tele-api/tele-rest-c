#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "copy_message_response.h"



static copy_message_response_t *copy_message_response_create_internal(
    int ok,
    message_id_t *result
    ) {
    copy_message_response_t *copy_message_response_local_var = malloc(sizeof(copy_message_response_t));
    if (!copy_message_response_local_var) {
        return NULL;
    }
    copy_message_response_local_var->ok = ok;
    copy_message_response_local_var->result = result;

    copy_message_response_local_var->_library_owned = 1;
    return copy_message_response_local_var;
}

__attribute__((deprecated)) copy_message_response_t *copy_message_response_create(
    int ok,
    message_id_t *result
    ) {
    return copy_message_response_create_internal (
        ok,
        result
        );
}

void copy_message_response_free(copy_message_response_t *copy_message_response) {
    if(NULL == copy_message_response){
        return ;
    }
    if(copy_message_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "copy_message_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (copy_message_response->result) {
        message_id_free(copy_message_response->result);
        copy_message_response->result = NULL;
    }
    free(copy_message_response);
}

cJSON *copy_message_response_convertToJSON(copy_message_response_t *copy_message_response) {
    cJSON *item = cJSON_CreateObject();

    // copy_message_response->ok
    if (!copy_message_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", copy_message_response->ok) == NULL) {
    goto fail; //Bool
    }


    // copy_message_response->result
    if (!copy_message_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = message_id_convertToJSON(copy_message_response->result);
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

copy_message_response_t *copy_message_response_parseFromJSON(cJSON *copy_message_responseJSON){

    copy_message_response_t *copy_message_response_local_var = NULL;

    // define the local variable for copy_message_response->result
    message_id_t *result_local_nonprim = NULL;

    // copy_message_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(copy_message_responseJSON, "ok");
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

    // copy_message_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(copy_message_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = message_id_parseFromJSON(result); //nonprimitive


    copy_message_response_local_var = copy_message_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return copy_message_response_local_var;
end:
    if (result_local_nonprim) {
        message_id_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
