#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "add_sticker_to_set_response.h"



static add_sticker_to_set_response_t *add_sticker_to_set_response_create_internal(
    int ok,
    int result
    ) {
    add_sticker_to_set_response_t *add_sticker_to_set_response_local_var = malloc(sizeof(add_sticker_to_set_response_t));
    if (!add_sticker_to_set_response_local_var) {
        return NULL;
    }
    add_sticker_to_set_response_local_var->ok = ok;
    add_sticker_to_set_response_local_var->result = result;

    add_sticker_to_set_response_local_var->_library_owned = 1;
    return add_sticker_to_set_response_local_var;
}

__attribute__((deprecated)) add_sticker_to_set_response_t *add_sticker_to_set_response_create(
    int ok,
    int result
    ) {
    return add_sticker_to_set_response_create_internal (
        ok,
        result
        );
}

void add_sticker_to_set_response_free(add_sticker_to_set_response_t *add_sticker_to_set_response) {
    if(NULL == add_sticker_to_set_response){
        return ;
    }
    if(add_sticker_to_set_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "add_sticker_to_set_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(add_sticker_to_set_response);
}

cJSON *add_sticker_to_set_response_convertToJSON(add_sticker_to_set_response_t *add_sticker_to_set_response) {
    cJSON *item = cJSON_CreateObject();

    // add_sticker_to_set_response->ok
    if (!add_sticker_to_set_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", add_sticker_to_set_response->ok) == NULL) {
    goto fail; //Bool
    }


    // add_sticker_to_set_response->result
    if (!add_sticker_to_set_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", add_sticker_to_set_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

add_sticker_to_set_response_t *add_sticker_to_set_response_parseFromJSON(cJSON *add_sticker_to_set_responseJSON){

    add_sticker_to_set_response_t *add_sticker_to_set_response_local_var = NULL;

    // add_sticker_to_set_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(add_sticker_to_set_responseJSON, "ok");
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

    // add_sticker_to_set_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(add_sticker_to_set_responseJSON, "result");
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


    add_sticker_to_set_response_local_var = add_sticker_to_set_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return add_sticker_to_set_response_local_var;
end:
    return NULL;

}
