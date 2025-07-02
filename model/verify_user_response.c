#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "verify_user_response.h"



static verify_user_response_t *verify_user_response_create_internal(
    int ok,
    int result
    ) {
    verify_user_response_t *verify_user_response_local_var = malloc(sizeof(verify_user_response_t));
    if (!verify_user_response_local_var) {
        return NULL;
    }
    verify_user_response_local_var->ok = ok;
    verify_user_response_local_var->result = result;

    verify_user_response_local_var->_library_owned = 1;
    return verify_user_response_local_var;
}

__attribute__((deprecated)) verify_user_response_t *verify_user_response_create(
    int ok,
    int result
    ) {
    return verify_user_response_create_internal (
        ok,
        result
        );
}

void verify_user_response_free(verify_user_response_t *verify_user_response) {
    if(NULL == verify_user_response){
        return ;
    }
    if(verify_user_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "verify_user_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(verify_user_response);
}

cJSON *verify_user_response_convertToJSON(verify_user_response_t *verify_user_response) {
    cJSON *item = cJSON_CreateObject();

    // verify_user_response->ok
    if (!verify_user_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", verify_user_response->ok) == NULL) {
    goto fail; //Bool
    }


    // verify_user_response->result
    if (!verify_user_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", verify_user_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

verify_user_response_t *verify_user_response_parseFromJSON(cJSON *verify_user_responseJSON){

    verify_user_response_t *verify_user_response_local_var = NULL;

    // verify_user_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(verify_user_responseJSON, "ok");
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

    // verify_user_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(verify_user_responseJSON, "result");
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


    verify_user_response_local_var = verify_user_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return verify_user_response_local_var;
end:
    return NULL;

}
