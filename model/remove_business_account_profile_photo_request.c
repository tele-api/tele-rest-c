#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "remove_business_account_profile_photo_request.h"



static remove_business_account_profile_photo_request_t *remove_business_account_profile_photo_request_create_internal(
    char *business_connection_id,
    int is_public
    ) {
    remove_business_account_profile_photo_request_t *remove_business_account_profile_photo_request_local_var = malloc(sizeof(remove_business_account_profile_photo_request_t));
    if (!remove_business_account_profile_photo_request_local_var) {
        return NULL;
    }
    remove_business_account_profile_photo_request_local_var->business_connection_id = business_connection_id;
    remove_business_account_profile_photo_request_local_var->is_public = is_public;

    remove_business_account_profile_photo_request_local_var->_library_owned = 1;
    return remove_business_account_profile_photo_request_local_var;
}

__attribute__((deprecated)) remove_business_account_profile_photo_request_t *remove_business_account_profile_photo_request_create(
    char *business_connection_id,
    int is_public
    ) {
    return remove_business_account_profile_photo_request_create_internal (
        business_connection_id,
        is_public
        );
}

void remove_business_account_profile_photo_request_free(remove_business_account_profile_photo_request_t *remove_business_account_profile_photo_request) {
    if(NULL == remove_business_account_profile_photo_request){
        return ;
    }
    if(remove_business_account_profile_photo_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "remove_business_account_profile_photo_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (remove_business_account_profile_photo_request->business_connection_id) {
        free(remove_business_account_profile_photo_request->business_connection_id);
        remove_business_account_profile_photo_request->business_connection_id = NULL;
    }
    free(remove_business_account_profile_photo_request);
}

cJSON *remove_business_account_profile_photo_request_convertToJSON(remove_business_account_profile_photo_request_t *remove_business_account_profile_photo_request) {
    cJSON *item = cJSON_CreateObject();

    // remove_business_account_profile_photo_request->business_connection_id
    if (!remove_business_account_profile_photo_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", remove_business_account_profile_photo_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // remove_business_account_profile_photo_request->is_public
    if(remove_business_account_profile_photo_request->is_public) {
    if(cJSON_AddBoolToObject(item, "is_public", remove_business_account_profile_photo_request->is_public) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

remove_business_account_profile_photo_request_t *remove_business_account_profile_photo_request_parseFromJSON(cJSON *remove_business_account_profile_photo_requestJSON){

    remove_business_account_profile_photo_request_t *remove_business_account_profile_photo_request_local_var = NULL;

    // remove_business_account_profile_photo_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(remove_business_account_profile_photo_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (!business_connection_id) {
        goto end;
    }

    
    if(!cJSON_IsString(business_connection_id))
    {
    goto end; //String
    }

    // remove_business_account_profile_photo_request->is_public
    cJSON *is_public = cJSON_GetObjectItemCaseSensitive(remove_business_account_profile_photo_requestJSON, "is_public");
    if (cJSON_IsNull(is_public)) {
        is_public = NULL;
    }
    if (is_public) { 
    if(!cJSON_IsBool(is_public))
    {
    goto end; //Bool
    }
    }


    remove_business_account_profile_photo_request_local_var = remove_business_account_profile_photo_request_create_internal (
        strdup(business_connection_id->valuestring),
        is_public ? is_public->valueint : 0
        );

    return remove_business_account_profile_photo_request_local_var;
end:
    return NULL;

}
