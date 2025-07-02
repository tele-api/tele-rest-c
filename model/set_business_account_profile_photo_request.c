#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_business_account_profile_photo_request.h"



static set_business_account_profile_photo_request_t *set_business_account_profile_photo_request_create_internal(
    char *business_connection_id,
    input_profile_photo_t *photo,
    int is_public
    ) {
    set_business_account_profile_photo_request_t *set_business_account_profile_photo_request_local_var = malloc(sizeof(set_business_account_profile_photo_request_t));
    if (!set_business_account_profile_photo_request_local_var) {
        return NULL;
    }
    set_business_account_profile_photo_request_local_var->business_connection_id = business_connection_id;
    set_business_account_profile_photo_request_local_var->photo = photo;
    set_business_account_profile_photo_request_local_var->is_public = is_public;

    set_business_account_profile_photo_request_local_var->_library_owned = 1;
    return set_business_account_profile_photo_request_local_var;
}

__attribute__((deprecated)) set_business_account_profile_photo_request_t *set_business_account_profile_photo_request_create(
    char *business_connection_id,
    input_profile_photo_t *photo,
    int is_public
    ) {
    return set_business_account_profile_photo_request_create_internal (
        business_connection_id,
        photo,
        is_public
        );
}

void set_business_account_profile_photo_request_free(set_business_account_profile_photo_request_t *set_business_account_profile_photo_request) {
    if(NULL == set_business_account_profile_photo_request){
        return ;
    }
    if(set_business_account_profile_photo_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_business_account_profile_photo_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_business_account_profile_photo_request->business_connection_id) {
        free(set_business_account_profile_photo_request->business_connection_id);
        set_business_account_profile_photo_request->business_connection_id = NULL;
    }
    if (set_business_account_profile_photo_request->photo) {
        input_profile_photo_free(set_business_account_profile_photo_request->photo);
        set_business_account_profile_photo_request->photo = NULL;
    }
    free(set_business_account_profile_photo_request);
}

cJSON *set_business_account_profile_photo_request_convertToJSON(set_business_account_profile_photo_request_t *set_business_account_profile_photo_request) {
    cJSON *item = cJSON_CreateObject();

    // set_business_account_profile_photo_request->business_connection_id
    if (!set_business_account_profile_photo_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", set_business_account_profile_photo_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // set_business_account_profile_photo_request->photo
    if (!set_business_account_profile_photo_request->photo) {
        goto fail;
    }
    cJSON *photo_local_JSON = input_profile_photo_convertToJSON(set_business_account_profile_photo_request->photo);
    if(photo_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "photo", photo_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // set_business_account_profile_photo_request->is_public
    if(set_business_account_profile_photo_request->is_public) {
    if(cJSON_AddBoolToObject(item, "is_public", set_business_account_profile_photo_request->is_public) == NULL) {
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

set_business_account_profile_photo_request_t *set_business_account_profile_photo_request_parseFromJSON(cJSON *set_business_account_profile_photo_requestJSON){

    set_business_account_profile_photo_request_t *set_business_account_profile_photo_request_local_var = NULL;

    // define the local variable for set_business_account_profile_photo_request->photo
    input_profile_photo_t *photo_local_nonprim = NULL;

    // set_business_account_profile_photo_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(set_business_account_profile_photo_requestJSON, "business_connection_id");
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

    // set_business_account_profile_photo_request->photo
    cJSON *photo = cJSON_GetObjectItemCaseSensitive(set_business_account_profile_photo_requestJSON, "photo");
    if (cJSON_IsNull(photo)) {
        photo = NULL;
    }
    if (!photo) {
        goto end;
    }

    
    photo_local_nonprim = input_profile_photo_parseFromJSON(photo); //nonprimitive

    // set_business_account_profile_photo_request->is_public
    cJSON *is_public = cJSON_GetObjectItemCaseSensitive(set_business_account_profile_photo_requestJSON, "is_public");
    if (cJSON_IsNull(is_public)) {
        is_public = NULL;
    }
    if (is_public) { 
    if(!cJSON_IsBool(is_public))
    {
    goto end; //Bool
    }
    }


    set_business_account_profile_photo_request_local_var = set_business_account_profile_photo_request_create_internal (
        strdup(business_connection_id->valuestring),
        photo_local_nonprim,
        is_public ? is_public->valueint : 0
        );

    return set_business_account_profile_photo_request_local_var;
end:
    if (photo_local_nonprim) {
        input_profile_photo_free(photo_local_nonprim);
        photo_local_nonprim = NULL;
    }
    return NULL;

}
