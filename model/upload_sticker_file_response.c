#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "upload_sticker_file_response.h"



static upload_sticker_file_response_t *upload_sticker_file_response_create_internal(
    int ok,
    binary_t*_t *result
    ) {
    upload_sticker_file_response_t *upload_sticker_file_response_local_var = malloc(sizeof(upload_sticker_file_response_t));
    if (!upload_sticker_file_response_local_var) {
        return NULL;
    }
    upload_sticker_file_response_local_var->ok = ok;
    upload_sticker_file_response_local_var->result = result;

    upload_sticker_file_response_local_var->_library_owned = 1;
    return upload_sticker_file_response_local_var;
}

__attribute__((deprecated)) upload_sticker_file_response_t *upload_sticker_file_response_create(
    int ok,
    binary_t*_t *result
    ) {
    return upload_sticker_file_response_create_internal (
        ok,
        result
        );
}

void upload_sticker_file_response_free(upload_sticker_file_response_t *upload_sticker_file_response) {
    if(NULL == upload_sticker_file_response){
        return ;
    }
    if(upload_sticker_file_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "upload_sticker_file_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (upload_sticker_file_response->result) {
        file_free(upload_sticker_file_response->result);
        upload_sticker_file_response->result = NULL;
    }
    free(upload_sticker_file_response);
}

cJSON *upload_sticker_file_response_convertToJSON(upload_sticker_file_response_t *upload_sticker_file_response) {
    cJSON *item = cJSON_CreateObject();

    // upload_sticker_file_response->ok
    if (!upload_sticker_file_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", upload_sticker_file_response->ok) == NULL) {
    goto fail; //Bool
    }


    // upload_sticker_file_response->result
    if (!upload_sticker_file_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = file_convertToJSON(upload_sticker_file_response->result);
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

upload_sticker_file_response_t *upload_sticker_file_response_parseFromJSON(cJSON *upload_sticker_file_responseJSON){

    upload_sticker_file_response_t *upload_sticker_file_response_local_var = NULL;

    // define the local variable for upload_sticker_file_response->result
    file_t *result_local_nonprim = NULL;

    // upload_sticker_file_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(upload_sticker_file_responseJSON, "ok");
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

    // upload_sticker_file_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(upload_sticker_file_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = file_parseFromJSON(result); //nonprimitive


    upload_sticker_file_response_local_var = upload_sticker_file_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return upload_sticker_file_response_local_var;
end:
    if (result_local_nonprim) {
        file_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
