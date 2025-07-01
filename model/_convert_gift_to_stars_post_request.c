#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_convert_gift_to_stars_post_request.h"



static _convert_gift_to_stars_post_request_t *_convert_gift_to_stars_post_request_create_internal(
    char *business_connection_id,
    char *owned_gift_id
    ) {
    _convert_gift_to_stars_post_request_t *_convert_gift_to_stars_post_request_local_var = malloc(sizeof(_convert_gift_to_stars_post_request_t));
    if (!_convert_gift_to_stars_post_request_local_var) {
        return NULL;
    }
    _convert_gift_to_stars_post_request_local_var->business_connection_id = business_connection_id;
    _convert_gift_to_stars_post_request_local_var->owned_gift_id = owned_gift_id;

    _convert_gift_to_stars_post_request_local_var->_library_owned = 1;
    return _convert_gift_to_stars_post_request_local_var;
}

__attribute__((deprecated)) _convert_gift_to_stars_post_request_t *_convert_gift_to_stars_post_request_create(
    char *business_connection_id,
    char *owned_gift_id
    ) {
    return _convert_gift_to_stars_post_request_create_internal (
        business_connection_id,
        owned_gift_id
        );
}

void _convert_gift_to_stars_post_request_free(_convert_gift_to_stars_post_request_t *_convert_gift_to_stars_post_request) {
    if(NULL == _convert_gift_to_stars_post_request){
        return ;
    }
    if(_convert_gift_to_stars_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_convert_gift_to_stars_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_convert_gift_to_stars_post_request->business_connection_id) {
        free(_convert_gift_to_stars_post_request->business_connection_id);
        _convert_gift_to_stars_post_request->business_connection_id = NULL;
    }
    if (_convert_gift_to_stars_post_request->owned_gift_id) {
        free(_convert_gift_to_stars_post_request->owned_gift_id);
        _convert_gift_to_stars_post_request->owned_gift_id = NULL;
    }
    free(_convert_gift_to_stars_post_request);
}

cJSON *_convert_gift_to_stars_post_request_convertToJSON(_convert_gift_to_stars_post_request_t *_convert_gift_to_stars_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _convert_gift_to_stars_post_request->business_connection_id
    if (!_convert_gift_to_stars_post_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", _convert_gift_to_stars_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // _convert_gift_to_stars_post_request->owned_gift_id
    if (!_convert_gift_to_stars_post_request->owned_gift_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "owned_gift_id", _convert_gift_to_stars_post_request->owned_gift_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_convert_gift_to_stars_post_request_t *_convert_gift_to_stars_post_request_parseFromJSON(cJSON *_convert_gift_to_stars_post_requestJSON){

    _convert_gift_to_stars_post_request_t *_convert_gift_to_stars_post_request_local_var = NULL;

    // _convert_gift_to_stars_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_convert_gift_to_stars_post_requestJSON, "business_connection_id");
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

    // _convert_gift_to_stars_post_request->owned_gift_id
    cJSON *owned_gift_id = cJSON_GetObjectItemCaseSensitive(_convert_gift_to_stars_post_requestJSON, "owned_gift_id");
    if (cJSON_IsNull(owned_gift_id)) {
        owned_gift_id = NULL;
    }
    if (!owned_gift_id) {
        goto end;
    }

    
    if(!cJSON_IsString(owned_gift_id))
    {
    goto end; //String
    }


    _convert_gift_to_stars_post_request_local_var = _convert_gift_to_stars_post_request_create_internal (
        strdup(business_connection_id->valuestring),
        strdup(owned_gift_id->valuestring)
        );

    return _convert_gift_to_stars_post_request_local_var;
end:
    return NULL;

}
