#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_my_default_administrator_rights_post_request.h"



static _set_my_default_administrator_rights_post_request_t *_set_my_default_administrator_rights_post_request_create_internal(
    chat_administrator_rights_t *rights,
    int for_channels
    ) {
    _set_my_default_administrator_rights_post_request_t *_set_my_default_administrator_rights_post_request_local_var = malloc(sizeof(_set_my_default_administrator_rights_post_request_t));
    if (!_set_my_default_administrator_rights_post_request_local_var) {
        return NULL;
    }
    _set_my_default_administrator_rights_post_request_local_var->rights = rights;
    _set_my_default_administrator_rights_post_request_local_var->for_channels = for_channels;

    _set_my_default_administrator_rights_post_request_local_var->_library_owned = 1;
    return _set_my_default_administrator_rights_post_request_local_var;
}

__attribute__((deprecated)) _set_my_default_administrator_rights_post_request_t *_set_my_default_administrator_rights_post_request_create(
    chat_administrator_rights_t *rights,
    int for_channels
    ) {
    return _set_my_default_administrator_rights_post_request_create_internal (
        rights,
        for_channels
        );
}

void _set_my_default_administrator_rights_post_request_free(_set_my_default_administrator_rights_post_request_t *_set_my_default_administrator_rights_post_request) {
    if(NULL == _set_my_default_administrator_rights_post_request){
        return ;
    }
    if(_set_my_default_administrator_rights_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_my_default_administrator_rights_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_my_default_administrator_rights_post_request->rights) {
        chat_administrator_rights_free(_set_my_default_administrator_rights_post_request->rights);
        _set_my_default_administrator_rights_post_request->rights = NULL;
    }
    free(_set_my_default_administrator_rights_post_request);
}

cJSON *_set_my_default_administrator_rights_post_request_convertToJSON(_set_my_default_administrator_rights_post_request_t *_set_my_default_administrator_rights_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_my_default_administrator_rights_post_request->rights
    if(_set_my_default_administrator_rights_post_request->rights) {
    cJSON *rights_local_JSON = chat_administrator_rights_convertToJSON(_set_my_default_administrator_rights_post_request->rights);
    if(rights_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rights", rights_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _set_my_default_administrator_rights_post_request->for_channels
    if(_set_my_default_administrator_rights_post_request->for_channels) {
    if(cJSON_AddBoolToObject(item, "for_channels", _set_my_default_administrator_rights_post_request->for_channels) == NULL) {
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

_set_my_default_administrator_rights_post_request_t *_set_my_default_administrator_rights_post_request_parseFromJSON(cJSON *_set_my_default_administrator_rights_post_requestJSON){

    _set_my_default_administrator_rights_post_request_t *_set_my_default_administrator_rights_post_request_local_var = NULL;

    // define the local variable for _set_my_default_administrator_rights_post_request->rights
    chat_administrator_rights_t *rights_local_nonprim = NULL;

    // _set_my_default_administrator_rights_post_request->rights
    cJSON *rights = cJSON_GetObjectItemCaseSensitive(_set_my_default_administrator_rights_post_requestJSON, "rights");
    if (cJSON_IsNull(rights)) {
        rights = NULL;
    }
    if (rights) { 
    rights_local_nonprim = chat_administrator_rights_parseFromJSON(rights); //nonprimitive
    }

    // _set_my_default_administrator_rights_post_request->for_channels
    cJSON *for_channels = cJSON_GetObjectItemCaseSensitive(_set_my_default_administrator_rights_post_requestJSON, "for_channels");
    if (cJSON_IsNull(for_channels)) {
        for_channels = NULL;
    }
    if (for_channels) { 
    if(!cJSON_IsBool(for_channels))
    {
    goto end; //Bool
    }
    }


    _set_my_default_administrator_rights_post_request_local_var = _set_my_default_administrator_rights_post_request_create_internal (
        rights ? rights_local_nonprim : NULL,
        for_channels ? for_channels->valueint : 0
        );

    return _set_my_default_administrator_rights_post_request_local_var;
end:
    if (rights_local_nonprim) {
        chat_administrator_rights_free(rights_local_nonprim);
        rights_local_nonprim = NULL;
    }
    return NULL;

}
