#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_delete_sticker_set_post_request.h"



static _delete_sticker_set_post_request_t *_delete_sticker_set_post_request_create_internal(
    char *name
    ) {
    _delete_sticker_set_post_request_t *_delete_sticker_set_post_request_local_var = malloc(sizeof(_delete_sticker_set_post_request_t));
    if (!_delete_sticker_set_post_request_local_var) {
        return NULL;
    }
    _delete_sticker_set_post_request_local_var->name = name;

    _delete_sticker_set_post_request_local_var->_library_owned = 1;
    return _delete_sticker_set_post_request_local_var;
}

__attribute__((deprecated)) _delete_sticker_set_post_request_t *_delete_sticker_set_post_request_create(
    char *name
    ) {
    return _delete_sticker_set_post_request_create_internal (
        name
        );
}

void _delete_sticker_set_post_request_free(_delete_sticker_set_post_request_t *_delete_sticker_set_post_request) {
    if(NULL == _delete_sticker_set_post_request){
        return ;
    }
    if(_delete_sticker_set_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_delete_sticker_set_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_delete_sticker_set_post_request->name) {
        free(_delete_sticker_set_post_request->name);
        _delete_sticker_set_post_request->name = NULL;
    }
    free(_delete_sticker_set_post_request);
}

cJSON *_delete_sticker_set_post_request_convertToJSON(_delete_sticker_set_post_request_t *_delete_sticker_set_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _delete_sticker_set_post_request->name
    if (!_delete_sticker_set_post_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", _delete_sticker_set_post_request->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_delete_sticker_set_post_request_t *_delete_sticker_set_post_request_parseFromJSON(cJSON *_delete_sticker_set_post_requestJSON){

    _delete_sticker_set_post_request_t *_delete_sticker_set_post_request_local_var = NULL;

    // _delete_sticker_set_post_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(_delete_sticker_set_post_requestJSON, "name");
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


    _delete_sticker_set_post_request_local_var = _delete_sticker_set_post_request_create_internal (
        strdup(name->valuestring)
        );

    return _delete_sticker_set_post_request_local_var;
end:
    return NULL;

}
