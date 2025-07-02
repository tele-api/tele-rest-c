#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "remove_business_account_profile_photo_response.h"



static remove_business_account_profile_photo_response_t *remove_business_account_profile_photo_response_create_internal(
    int ok,
    int result
    ) {
    remove_business_account_profile_photo_response_t *remove_business_account_profile_photo_response_local_var = malloc(sizeof(remove_business_account_profile_photo_response_t));
    if (!remove_business_account_profile_photo_response_local_var) {
        return NULL;
    }
    remove_business_account_profile_photo_response_local_var->ok = ok;
    remove_business_account_profile_photo_response_local_var->result = result;

    remove_business_account_profile_photo_response_local_var->_library_owned = 1;
    return remove_business_account_profile_photo_response_local_var;
}

__attribute__((deprecated)) remove_business_account_profile_photo_response_t *remove_business_account_profile_photo_response_create(
    int ok,
    int result
    ) {
    return remove_business_account_profile_photo_response_create_internal (
        ok,
        result
        );
}

void remove_business_account_profile_photo_response_free(remove_business_account_profile_photo_response_t *remove_business_account_profile_photo_response) {
    if(NULL == remove_business_account_profile_photo_response){
        return ;
    }
    if(remove_business_account_profile_photo_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "remove_business_account_profile_photo_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(remove_business_account_profile_photo_response);
}

cJSON *remove_business_account_profile_photo_response_convertToJSON(remove_business_account_profile_photo_response_t *remove_business_account_profile_photo_response) {
    cJSON *item = cJSON_CreateObject();

    // remove_business_account_profile_photo_response->ok
    if (!remove_business_account_profile_photo_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", remove_business_account_profile_photo_response->ok) == NULL) {
    goto fail; //Bool
    }


    // remove_business_account_profile_photo_response->result
    if (!remove_business_account_profile_photo_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", remove_business_account_profile_photo_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

remove_business_account_profile_photo_response_t *remove_business_account_profile_photo_response_parseFromJSON(cJSON *remove_business_account_profile_photo_responseJSON){

    remove_business_account_profile_photo_response_t *remove_business_account_profile_photo_response_local_var = NULL;

    // remove_business_account_profile_photo_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(remove_business_account_profile_photo_responseJSON, "ok");
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

    // remove_business_account_profile_photo_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(remove_business_account_profile_photo_responseJSON, "result");
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


    remove_business_account_profile_photo_response_local_var = remove_business_account_profile_photo_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return remove_business_account_profile_photo_response_local_var;
end:
    return NULL;

}
