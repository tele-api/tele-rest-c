#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "close_response.h"



static close_response_t *close_response_create_internal(
    int ok,
    int result
    ) {
    close_response_t *close_response_local_var = malloc(sizeof(close_response_t));
    if (!close_response_local_var) {
        return NULL;
    }
    close_response_local_var->ok = ok;
    close_response_local_var->result = result;

    close_response_local_var->_library_owned = 1;
    return close_response_local_var;
}

__attribute__((deprecated)) close_response_t *close_response_create(
    int ok,
    int result
    ) {
    return close_response_create_internal (
        ok,
        result
        );
}

void close_response_free(close_response_t *close_response) {
    if(NULL == close_response){
        return ;
    }
    if(close_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "close_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(close_response);
}

cJSON *close_response_convertToJSON(close_response_t *close_response) {
    cJSON *item = cJSON_CreateObject();

    // close_response->ok
    if (!close_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", close_response->ok) == NULL) {
    goto fail; //Bool
    }


    // close_response->result
    if (!close_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", close_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

close_response_t *close_response_parseFromJSON(cJSON *close_responseJSON){

    close_response_t *close_response_local_var = NULL;

    // close_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(close_responseJSON, "ok");
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

    // close_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(close_responseJSON, "result");
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


    close_response_local_var = close_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return close_response_local_var;
end:
    return NULL;

}
