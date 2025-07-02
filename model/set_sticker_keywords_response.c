#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_sticker_keywords_response.h"



static set_sticker_keywords_response_t *set_sticker_keywords_response_create_internal(
    int ok,
    int result
    ) {
    set_sticker_keywords_response_t *set_sticker_keywords_response_local_var = malloc(sizeof(set_sticker_keywords_response_t));
    if (!set_sticker_keywords_response_local_var) {
        return NULL;
    }
    set_sticker_keywords_response_local_var->ok = ok;
    set_sticker_keywords_response_local_var->result = result;

    set_sticker_keywords_response_local_var->_library_owned = 1;
    return set_sticker_keywords_response_local_var;
}

__attribute__((deprecated)) set_sticker_keywords_response_t *set_sticker_keywords_response_create(
    int ok,
    int result
    ) {
    return set_sticker_keywords_response_create_internal (
        ok,
        result
        );
}

void set_sticker_keywords_response_free(set_sticker_keywords_response_t *set_sticker_keywords_response) {
    if(NULL == set_sticker_keywords_response){
        return ;
    }
    if(set_sticker_keywords_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_sticker_keywords_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(set_sticker_keywords_response);
}

cJSON *set_sticker_keywords_response_convertToJSON(set_sticker_keywords_response_t *set_sticker_keywords_response) {
    cJSON *item = cJSON_CreateObject();

    // set_sticker_keywords_response->ok
    if (!set_sticker_keywords_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", set_sticker_keywords_response->ok) == NULL) {
    goto fail; //Bool
    }


    // set_sticker_keywords_response->result
    if (!set_sticker_keywords_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", set_sticker_keywords_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

set_sticker_keywords_response_t *set_sticker_keywords_response_parseFromJSON(cJSON *set_sticker_keywords_responseJSON){

    set_sticker_keywords_response_t *set_sticker_keywords_response_local_var = NULL;

    // set_sticker_keywords_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(set_sticker_keywords_responseJSON, "ok");
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

    // set_sticker_keywords_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(set_sticker_keywords_responseJSON, "result");
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


    set_sticker_keywords_response_local_var = set_sticker_keywords_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return set_sticker_keywords_response_local_var;
end:
    return NULL;

}
