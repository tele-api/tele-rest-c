#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_delete_sticker_from_set_post_request.h"



static _delete_sticker_from_set_post_request_t *_delete_sticker_from_set_post_request_create_internal(
    char *sticker
    ) {
    _delete_sticker_from_set_post_request_t *_delete_sticker_from_set_post_request_local_var = malloc(sizeof(_delete_sticker_from_set_post_request_t));
    if (!_delete_sticker_from_set_post_request_local_var) {
        return NULL;
    }
    _delete_sticker_from_set_post_request_local_var->sticker = sticker;

    _delete_sticker_from_set_post_request_local_var->_library_owned = 1;
    return _delete_sticker_from_set_post_request_local_var;
}

__attribute__((deprecated)) _delete_sticker_from_set_post_request_t *_delete_sticker_from_set_post_request_create(
    char *sticker
    ) {
    return _delete_sticker_from_set_post_request_create_internal (
        sticker
        );
}

void _delete_sticker_from_set_post_request_free(_delete_sticker_from_set_post_request_t *_delete_sticker_from_set_post_request) {
    if(NULL == _delete_sticker_from_set_post_request){
        return ;
    }
    if(_delete_sticker_from_set_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_delete_sticker_from_set_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_delete_sticker_from_set_post_request->sticker) {
        free(_delete_sticker_from_set_post_request->sticker);
        _delete_sticker_from_set_post_request->sticker = NULL;
    }
    free(_delete_sticker_from_set_post_request);
}

cJSON *_delete_sticker_from_set_post_request_convertToJSON(_delete_sticker_from_set_post_request_t *_delete_sticker_from_set_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _delete_sticker_from_set_post_request->sticker
    if (!_delete_sticker_from_set_post_request->sticker) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker", _delete_sticker_from_set_post_request->sticker) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_delete_sticker_from_set_post_request_t *_delete_sticker_from_set_post_request_parseFromJSON(cJSON *_delete_sticker_from_set_post_requestJSON){

    _delete_sticker_from_set_post_request_t *_delete_sticker_from_set_post_request_local_var = NULL;

    // _delete_sticker_from_set_post_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(_delete_sticker_from_set_post_requestJSON, "sticker");
    if (cJSON_IsNull(sticker)) {
        sticker = NULL;
    }
    if (!sticker) {
        goto end;
    }

    
    if(!cJSON_IsString(sticker))
    {
    goto end; //String
    }


    _delete_sticker_from_set_post_request_local_var = _delete_sticker_from_set_post_request_create_internal (
        strdup(sticker->valuestring)
        );

    return _delete_sticker_from_set_post_request_local_var;
end:
    return NULL;

}
