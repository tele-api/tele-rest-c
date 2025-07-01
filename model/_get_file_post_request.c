#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_get_file_post_request.h"



static _get_file_post_request_t *_get_file_post_request_create_internal(
    char *file_id
    ) {
    _get_file_post_request_t *_get_file_post_request_local_var = malloc(sizeof(_get_file_post_request_t));
    if (!_get_file_post_request_local_var) {
        return NULL;
    }
    _get_file_post_request_local_var->file_id = file_id;

    _get_file_post_request_local_var->_library_owned = 1;
    return _get_file_post_request_local_var;
}

__attribute__((deprecated)) _get_file_post_request_t *_get_file_post_request_create(
    char *file_id
    ) {
    return _get_file_post_request_create_internal (
        file_id
        );
}

void _get_file_post_request_free(_get_file_post_request_t *_get_file_post_request) {
    if(NULL == _get_file_post_request){
        return ;
    }
    if(_get_file_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_get_file_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_get_file_post_request->file_id) {
        free(_get_file_post_request->file_id);
        _get_file_post_request->file_id = NULL;
    }
    free(_get_file_post_request);
}

cJSON *_get_file_post_request_convertToJSON(_get_file_post_request_t *_get_file_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _get_file_post_request->file_id
    if (!_get_file_post_request->file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_id", _get_file_post_request->file_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_get_file_post_request_t *_get_file_post_request_parseFromJSON(cJSON *_get_file_post_requestJSON){

    _get_file_post_request_t *_get_file_post_request_local_var = NULL;

    // _get_file_post_request->file_id
    cJSON *file_id = cJSON_GetObjectItemCaseSensitive(_get_file_post_requestJSON, "file_id");
    if (cJSON_IsNull(file_id)) {
        file_id = NULL;
    }
    if (!file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(file_id))
    {
    goto end; //String
    }


    _get_file_post_request_local_var = _get_file_post_request_create_internal (
        strdup(file_id->valuestring)
        );

    return _get_file_post_request_local_var;
end:
    return NULL;

}
