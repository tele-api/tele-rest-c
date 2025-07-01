#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_get_sticker_set_post_request.h"



static _get_sticker_set_post_request_t *_get_sticker_set_post_request_create_internal(
    char *name
    ) {
    _get_sticker_set_post_request_t *_get_sticker_set_post_request_local_var = malloc(sizeof(_get_sticker_set_post_request_t));
    if (!_get_sticker_set_post_request_local_var) {
        return NULL;
    }
    _get_sticker_set_post_request_local_var->name = name;

    _get_sticker_set_post_request_local_var->_library_owned = 1;
    return _get_sticker_set_post_request_local_var;
}

__attribute__((deprecated)) _get_sticker_set_post_request_t *_get_sticker_set_post_request_create(
    char *name
    ) {
    return _get_sticker_set_post_request_create_internal (
        name
        );
}

void _get_sticker_set_post_request_free(_get_sticker_set_post_request_t *_get_sticker_set_post_request) {
    if(NULL == _get_sticker_set_post_request){
        return ;
    }
    if(_get_sticker_set_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_get_sticker_set_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_get_sticker_set_post_request->name) {
        free(_get_sticker_set_post_request->name);
        _get_sticker_set_post_request->name = NULL;
    }
    free(_get_sticker_set_post_request);
}

cJSON *_get_sticker_set_post_request_convertToJSON(_get_sticker_set_post_request_t *_get_sticker_set_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _get_sticker_set_post_request->name
    if (!_get_sticker_set_post_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", _get_sticker_set_post_request->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_get_sticker_set_post_request_t *_get_sticker_set_post_request_parseFromJSON(cJSON *_get_sticker_set_post_requestJSON){

    _get_sticker_set_post_request_t *_get_sticker_set_post_request_local_var = NULL;

    // _get_sticker_set_post_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(_get_sticker_set_post_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    _get_sticker_set_post_request_local_var = _get_sticker_set_post_request_create_internal (
        strdup(name->valuestring)
        );

    return _get_sticker_set_post_request_local_var;
end:
    return NULL;

}
