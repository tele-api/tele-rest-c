#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_get_business_connection_post_request.h"



static _get_business_connection_post_request_t *_get_business_connection_post_request_create_internal(
    char *business_connection_id
    ) {
    _get_business_connection_post_request_t *_get_business_connection_post_request_local_var = malloc(sizeof(_get_business_connection_post_request_t));
    if (!_get_business_connection_post_request_local_var) {
        return NULL;
    }
    _get_business_connection_post_request_local_var->business_connection_id = business_connection_id;

    _get_business_connection_post_request_local_var->_library_owned = 1;
    return _get_business_connection_post_request_local_var;
}

__attribute__((deprecated)) _get_business_connection_post_request_t *_get_business_connection_post_request_create(
    char *business_connection_id
    ) {
    return _get_business_connection_post_request_create_internal (
        business_connection_id
        );
}

void _get_business_connection_post_request_free(_get_business_connection_post_request_t *_get_business_connection_post_request) {
    if(NULL == _get_business_connection_post_request){
        return ;
    }
    if(_get_business_connection_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_get_business_connection_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_get_business_connection_post_request->business_connection_id) {
        free(_get_business_connection_post_request->business_connection_id);
        _get_business_connection_post_request->business_connection_id = NULL;
    }
    free(_get_business_connection_post_request);
}

cJSON *_get_business_connection_post_request_convertToJSON(_get_business_connection_post_request_t *_get_business_connection_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _get_business_connection_post_request->business_connection_id
    if (!_get_business_connection_post_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", _get_business_connection_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_get_business_connection_post_request_t *_get_business_connection_post_request_parseFromJSON(cJSON *_get_business_connection_post_requestJSON){

    _get_business_connection_post_request_t *_get_business_connection_post_request_local_var = NULL;

    // _get_business_connection_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_get_business_connection_post_requestJSON, "business_connection_id");
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


    _get_business_connection_post_request_local_var = _get_business_connection_post_request_create_internal (
        strdup(business_connection_id->valuestring)
        );

    return _get_business_connection_post_request_local_var;
end:
    return NULL;

}
