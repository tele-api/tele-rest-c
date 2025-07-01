#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_remove_business_account_profile_photo_post_request.h"



static _remove_business_account_profile_photo_post_request_t *_remove_business_account_profile_photo_post_request_create_internal(
    char *business_connection_id,
    int is_public
    ) {
    _remove_business_account_profile_photo_post_request_t *_remove_business_account_profile_photo_post_request_local_var = malloc(sizeof(_remove_business_account_profile_photo_post_request_t));
    if (!_remove_business_account_profile_photo_post_request_local_var) {
        return NULL;
    }
    _remove_business_account_profile_photo_post_request_local_var->business_connection_id = business_connection_id;
    _remove_business_account_profile_photo_post_request_local_var->is_public = is_public;

    _remove_business_account_profile_photo_post_request_local_var->_library_owned = 1;
    return _remove_business_account_profile_photo_post_request_local_var;
}

__attribute__((deprecated)) _remove_business_account_profile_photo_post_request_t *_remove_business_account_profile_photo_post_request_create(
    char *business_connection_id,
    int is_public
    ) {
    return _remove_business_account_profile_photo_post_request_create_internal (
        business_connection_id,
        is_public
        );
}

void _remove_business_account_profile_photo_post_request_free(_remove_business_account_profile_photo_post_request_t *_remove_business_account_profile_photo_post_request) {
    if(NULL == _remove_business_account_profile_photo_post_request){
        return ;
    }
    if(_remove_business_account_profile_photo_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_remove_business_account_profile_photo_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_remove_business_account_profile_photo_post_request->business_connection_id) {
        free(_remove_business_account_profile_photo_post_request->business_connection_id);
        _remove_business_account_profile_photo_post_request->business_connection_id = NULL;
    }
    free(_remove_business_account_profile_photo_post_request);
}

cJSON *_remove_business_account_profile_photo_post_request_convertToJSON(_remove_business_account_profile_photo_post_request_t *_remove_business_account_profile_photo_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _remove_business_account_profile_photo_post_request->business_connection_id
    if (!_remove_business_account_profile_photo_post_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", _remove_business_account_profile_photo_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // _remove_business_account_profile_photo_post_request->is_public
    if(_remove_business_account_profile_photo_post_request->is_public) {
    if(cJSON_AddBoolToObject(item, "is_public", _remove_business_account_profile_photo_post_request->is_public) == NULL) {
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

_remove_business_account_profile_photo_post_request_t *_remove_business_account_profile_photo_post_request_parseFromJSON(cJSON *_remove_business_account_profile_photo_post_requestJSON){

    _remove_business_account_profile_photo_post_request_t *_remove_business_account_profile_photo_post_request_local_var = NULL;

    // _remove_business_account_profile_photo_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_remove_business_account_profile_photo_post_requestJSON, "business_connection_id");
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

    // _remove_business_account_profile_photo_post_request->is_public
    cJSON *is_public = cJSON_GetObjectItemCaseSensitive(_remove_business_account_profile_photo_post_requestJSON, "is_public");
    if (cJSON_IsNull(is_public)) {
        is_public = NULL;
    }
    if (is_public) { 
    if(!cJSON_IsBool(is_public))
    {
    goto end; //Bool
    }
    }


    _remove_business_account_profile_photo_post_request_local_var = _remove_business_account_profile_photo_post_request_create_internal (
        strdup(business_connection_id->valuestring),
        is_public ? is_public->valueint : 0
        );

    return _remove_business_account_profile_photo_post_request_local_var;
end:
    return NULL;

}
