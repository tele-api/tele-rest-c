#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_business_account_username_post_request.h"



static _set_business_account_username_post_request_t *_set_business_account_username_post_request_create_internal(
    char *business_connection_id,
    char *username
    ) {
    _set_business_account_username_post_request_t *_set_business_account_username_post_request_local_var = malloc(sizeof(_set_business_account_username_post_request_t));
    if (!_set_business_account_username_post_request_local_var) {
        return NULL;
    }
    _set_business_account_username_post_request_local_var->business_connection_id = business_connection_id;
    _set_business_account_username_post_request_local_var->username = username;

    _set_business_account_username_post_request_local_var->_library_owned = 1;
    return _set_business_account_username_post_request_local_var;
}

__attribute__((deprecated)) _set_business_account_username_post_request_t *_set_business_account_username_post_request_create(
    char *business_connection_id,
    char *username
    ) {
    return _set_business_account_username_post_request_create_internal (
        business_connection_id,
        username
        );
}

void _set_business_account_username_post_request_free(_set_business_account_username_post_request_t *_set_business_account_username_post_request) {
    if(NULL == _set_business_account_username_post_request){
        return ;
    }
    if(_set_business_account_username_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_business_account_username_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_business_account_username_post_request->business_connection_id) {
        free(_set_business_account_username_post_request->business_connection_id);
        _set_business_account_username_post_request->business_connection_id = NULL;
    }
    if (_set_business_account_username_post_request->username) {
        free(_set_business_account_username_post_request->username);
        _set_business_account_username_post_request->username = NULL;
    }
    free(_set_business_account_username_post_request);
}

cJSON *_set_business_account_username_post_request_convertToJSON(_set_business_account_username_post_request_t *_set_business_account_username_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_business_account_username_post_request->business_connection_id
    if (!_set_business_account_username_post_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", _set_business_account_username_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // _set_business_account_username_post_request->username
    if(_set_business_account_username_post_request->username) {
    if(cJSON_AddStringToObject(item, "username", _set_business_account_username_post_request->username) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_set_business_account_username_post_request_t *_set_business_account_username_post_request_parseFromJSON(cJSON *_set_business_account_username_post_requestJSON){

    _set_business_account_username_post_request_t *_set_business_account_username_post_request_local_var = NULL;

    // _set_business_account_username_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_set_business_account_username_post_requestJSON, "business_connection_id");
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

    // _set_business_account_username_post_request->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(_set_business_account_username_post_requestJSON, "username");
    if (cJSON_IsNull(username)) {
        username = NULL;
    }
    if (username) { 
    if(!cJSON_IsString(username) && !cJSON_IsNull(username))
    {
    goto end; //String
    }
    }


    _set_business_account_username_post_request_local_var = _set_business_account_username_post_request_create_internal (
        strdup(business_connection_id->valuestring),
        username && !cJSON_IsNull(username) ? strdup(username->valuestring) : NULL
        );

    return _set_business_account_username_post_request_local_var;
end:
    return NULL;

}
