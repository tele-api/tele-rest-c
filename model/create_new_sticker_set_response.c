#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_new_sticker_set_response.h"



static create_new_sticker_set_response_t *create_new_sticker_set_response_create_internal(
    int ok,
    int result
    ) {
    create_new_sticker_set_response_t *create_new_sticker_set_response_local_var = malloc(sizeof(create_new_sticker_set_response_t));
    if (!create_new_sticker_set_response_local_var) {
        return NULL;
    }
    create_new_sticker_set_response_local_var->ok = ok;
    create_new_sticker_set_response_local_var->result = result;

    create_new_sticker_set_response_local_var->_library_owned = 1;
    return create_new_sticker_set_response_local_var;
}

__attribute__((deprecated)) create_new_sticker_set_response_t *create_new_sticker_set_response_create(
    int ok,
    int result
    ) {
    return create_new_sticker_set_response_create_internal (
        ok,
        result
        );
}

void create_new_sticker_set_response_free(create_new_sticker_set_response_t *create_new_sticker_set_response) {
    if(NULL == create_new_sticker_set_response){
        return ;
    }
    if(create_new_sticker_set_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_new_sticker_set_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(create_new_sticker_set_response);
}

cJSON *create_new_sticker_set_response_convertToJSON(create_new_sticker_set_response_t *create_new_sticker_set_response) {
    cJSON *item = cJSON_CreateObject();

    // create_new_sticker_set_response->ok
    if (!create_new_sticker_set_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", create_new_sticker_set_response->ok) == NULL) {
    goto fail; //Bool
    }


    // create_new_sticker_set_response->result
    if (!create_new_sticker_set_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", create_new_sticker_set_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_new_sticker_set_response_t *create_new_sticker_set_response_parseFromJSON(cJSON *create_new_sticker_set_responseJSON){

    create_new_sticker_set_response_t *create_new_sticker_set_response_local_var = NULL;

    // create_new_sticker_set_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(create_new_sticker_set_responseJSON, "ok");
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

    // create_new_sticker_set_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(create_new_sticker_set_responseJSON, "result");
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


    create_new_sticker_set_response_local_var = create_new_sticker_set_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return create_new_sticker_set_response_local_var;
end:
    return NULL;

}
