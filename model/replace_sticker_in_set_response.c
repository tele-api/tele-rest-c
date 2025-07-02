#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "replace_sticker_in_set_response.h"



static replace_sticker_in_set_response_t *replace_sticker_in_set_response_create_internal(
    int ok,
    int result
    ) {
    replace_sticker_in_set_response_t *replace_sticker_in_set_response_local_var = malloc(sizeof(replace_sticker_in_set_response_t));
    if (!replace_sticker_in_set_response_local_var) {
        return NULL;
    }
    replace_sticker_in_set_response_local_var->ok = ok;
    replace_sticker_in_set_response_local_var->result = result;

    replace_sticker_in_set_response_local_var->_library_owned = 1;
    return replace_sticker_in_set_response_local_var;
}

__attribute__((deprecated)) replace_sticker_in_set_response_t *replace_sticker_in_set_response_create(
    int ok,
    int result
    ) {
    return replace_sticker_in_set_response_create_internal (
        ok,
        result
        );
}

void replace_sticker_in_set_response_free(replace_sticker_in_set_response_t *replace_sticker_in_set_response) {
    if(NULL == replace_sticker_in_set_response){
        return ;
    }
    if(replace_sticker_in_set_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "replace_sticker_in_set_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(replace_sticker_in_set_response);
}

cJSON *replace_sticker_in_set_response_convertToJSON(replace_sticker_in_set_response_t *replace_sticker_in_set_response) {
    cJSON *item = cJSON_CreateObject();

    // replace_sticker_in_set_response->ok
    if (!replace_sticker_in_set_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", replace_sticker_in_set_response->ok) == NULL) {
    goto fail; //Bool
    }


    // replace_sticker_in_set_response->result
    if (!replace_sticker_in_set_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", replace_sticker_in_set_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

replace_sticker_in_set_response_t *replace_sticker_in_set_response_parseFromJSON(cJSON *replace_sticker_in_set_responseJSON){

    replace_sticker_in_set_response_t *replace_sticker_in_set_response_local_var = NULL;

    // replace_sticker_in_set_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(replace_sticker_in_set_responseJSON, "ok");
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

    // replace_sticker_in_set_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(replace_sticker_in_set_responseJSON, "result");
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


    replace_sticker_in_set_response_local_var = replace_sticker_in_set_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return replace_sticker_in_set_response_local_var;
end:
    return NULL;

}
