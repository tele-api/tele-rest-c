#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_get_my_default_administrator_rights_post_request.h"



static _get_my_default_administrator_rights_post_request_t *_get_my_default_administrator_rights_post_request_create_internal(
    int for_channels
    ) {
    _get_my_default_administrator_rights_post_request_t *_get_my_default_administrator_rights_post_request_local_var = malloc(sizeof(_get_my_default_administrator_rights_post_request_t));
    if (!_get_my_default_administrator_rights_post_request_local_var) {
        return NULL;
    }
    _get_my_default_administrator_rights_post_request_local_var->for_channels = for_channels;

    _get_my_default_administrator_rights_post_request_local_var->_library_owned = 1;
    return _get_my_default_administrator_rights_post_request_local_var;
}

__attribute__((deprecated)) _get_my_default_administrator_rights_post_request_t *_get_my_default_administrator_rights_post_request_create(
    int for_channels
    ) {
    return _get_my_default_administrator_rights_post_request_create_internal (
        for_channels
        );
}

void _get_my_default_administrator_rights_post_request_free(_get_my_default_administrator_rights_post_request_t *_get_my_default_administrator_rights_post_request) {
    if(NULL == _get_my_default_administrator_rights_post_request){
        return ;
    }
    if(_get_my_default_administrator_rights_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_get_my_default_administrator_rights_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_get_my_default_administrator_rights_post_request);
}

cJSON *_get_my_default_administrator_rights_post_request_convertToJSON(_get_my_default_administrator_rights_post_request_t *_get_my_default_administrator_rights_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _get_my_default_administrator_rights_post_request->for_channels
    if(_get_my_default_administrator_rights_post_request->for_channels) {
    if(cJSON_AddBoolToObject(item, "for_channels", _get_my_default_administrator_rights_post_request->for_channels) == NULL) {
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

_get_my_default_administrator_rights_post_request_t *_get_my_default_administrator_rights_post_request_parseFromJSON(cJSON *_get_my_default_administrator_rights_post_requestJSON){

    _get_my_default_administrator_rights_post_request_t *_get_my_default_administrator_rights_post_request_local_var = NULL;

    // _get_my_default_administrator_rights_post_request->for_channels
    cJSON *for_channels = cJSON_GetObjectItemCaseSensitive(_get_my_default_administrator_rights_post_requestJSON, "for_channels");
    if (cJSON_IsNull(for_channels)) {
        for_channels = NULL;
    }
    if (for_channels) { 
    if(!cJSON_IsBool(for_channels))
    {
    goto end; //Bool
    }
    }


    _get_my_default_administrator_rights_post_request_local_var = _get_my_default_administrator_rights_post_request_create_internal (
        for_channels ? for_channels->valueint : 0
        );

    return _get_my_default_administrator_rights_post_request_local_var;
end:
    return NULL;

}
