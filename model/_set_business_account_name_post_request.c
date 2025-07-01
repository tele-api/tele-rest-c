#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_business_account_name_post_request.h"



static _set_business_account_name_post_request_t *_set_business_account_name_post_request_create_internal(
    char *business_connection_id,
    char *first_name,
    char *last_name
    ) {
    _set_business_account_name_post_request_t *_set_business_account_name_post_request_local_var = malloc(sizeof(_set_business_account_name_post_request_t));
    if (!_set_business_account_name_post_request_local_var) {
        return NULL;
    }
    _set_business_account_name_post_request_local_var->business_connection_id = business_connection_id;
    _set_business_account_name_post_request_local_var->first_name = first_name;
    _set_business_account_name_post_request_local_var->last_name = last_name;

    _set_business_account_name_post_request_local_var->_library_owned = 1;
    return _set_business_account_name_post_request_local_var;
}

__attribute__((deprecated)) _set_business_account_name_post_request_t *_set_business_account_name_post_request_create(
    char *business_connection_id,
    char *first_name,
    char *last_name
    ) {
    return _set_business_account_name_post_request_create_internal (
        business_connection_id,
        first_name,
        last_name
        );
}

void _set_business_account_name_post_request_free(_set_business_account_name_post_request_t *_set_business_account_name_post_request) {
    if(NULL == _set_business_account_name_post_request){
        return ;
    }
    if(_set_business_account_name_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_business_account_name_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_business_account_name_post_request->business_connection_id) {
        free(_set_business_account_name_post_request->business_connection_id);
        _set_business_account_name_post_request->business_connection_id = NULL;
    }
    if (_set_business_account_name_post_request->first_name) {
        free(_set_business_account_name_post_request->first_name);
        _set_business_account_name_post_request->first_name = NULL;
    }
    if (_set_business_account_name_post_request->last_name) {
        free(_set_business_account_name_post_request->last_name);
        _set_business_account_name_post_request->last_name = NULL;
    }
    free(_set_business_account_name_post_request);
}

cJSON *_set_business_account_name_post_request_convertToJSON(_set_business_account_name_post_request_t *_set_business_account_name_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_business_account_name_post_request->business_connection_id
    if (!_set_business_account_name_post_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", _set_business_account_name_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // _set_business_account_name_post_request->first_name
    if (!_set_business_account_name_post_request->first_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "first_name", _set_business_account_name_post_request->first_name) == NULL) {
    goto fail; //String
    }


    // _set_business_account_name_post_request->last_name
    if(_set_business_account_name_post_request->last_name) {
    if(cJSON_AddStringToObject(item, "last_name", _set_business_account_name_post_request->last_name) == NULL) {
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

_set_business_account_name_post_request_t *_set_business_account_name_post_request_parseFromJSON(cJSON *_set_business_account_name_post_requestJSON){

    _set_business_account_name_post_request_t *_set_business_account_name_post_request_local_var = NULL;

    // _set_business_account_name_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_set_business_account_name_post_requestJSON, "business_connection_id");
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

    // _set_business_account_name_post_request->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(_set_business_account_name_post_requestJSON, "first_name");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (!first_name) {
        goto end;
    }

    
    if(!cJSON_IsString(first_name))
    {
    goto end; //String
    }

    // _set_business_account_name_post_request->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(_set_business_account_name_post_requestJSON, "last_name");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }


    _set_business_account_name_post_request_local_var = _set_business_account_name_post_request_create_internal (
        strdup(business_connection_id->valuestring),
        strdup(first_name->valuestring),
        last_name && !cJSON_IsNull(last_name) ? strdup(last_name->valuestring) : NULL
        );

    return _set_business_account_name_post_request_local_var;
end:
    return NULL;

}
