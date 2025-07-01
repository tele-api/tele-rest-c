#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_sticker_set_title_post_request.h"



static _set_sticker_set_title_post_request_t *_set_sticker_set_title_post_request_create_internal(
    char *name,
    char *title
    ) {
    _set_sticker_set_title_post_request_t *_set_sticker_set_title_post_request_local_var = malloc(sizeof(_set_sticker_set_title_post_request_t));
    if (!_set_sticker_set_title_post_request_local_var) {
        return NULL;
    }
    _set_sticker_set_title_post_request_local_var->name = name;
    _set_sticker_set_title_post_request_local_var->title = title;

    _set_sticker_set_title_post_request_local_var->_library_owned = 1;
    return _set_sticker_set_title_post_request_local_var;
}

__attribute__((deprecated)) _set_sticker_set_title_post_request_t *_set_sticker_set_title_post_request_create(
    char *name,
    char *title
    ) {
    return _set_sticker_set_title_post_request_create_internal (
        name,
        title
        );
}

void _set_sticker_set_title_post_request_free(_set_sticker_set_title_post_request_t *_set_sticker_set_title_post_request) {
    if(NULL == _set_sticker_set_title_post_request){
        return ;
    }
    if(_set_sticker_set_title_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_sticker_set_title_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_sticker_set_title_post_request->name) {
        free(_set_sticker_set_title_post_request->name);
        _set_sticker_set_title_post_request->name = NULL;
    }
    if (_set_sticker_set_title_post_request->title) {
        free(_set_sticker_set_title_post_request->title);
        _set_sticker_set_title_post_request->title = NULL;
    }
    free(_set_sticker_set_title_post_request);
}

cJSON *_set_sticker_set_title_post_request_convertToJSON(_set_sticker_set_title_post_request_t *_set_sticker_set_title_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_sticker_set_title_post_request->name
    if (!_set_sticker_set_title_post_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", _set_sticker_set_title_post_request->name) == NULL) {
    goto fail; //String
    }


    // _set_sticker_set_title_post_request->title
    if (!_set_sticker_set_title_post_request->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", _set_sticker_set_title_post_request->title) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_set_sticker_set_title_post_request_t *_set_sticker_set_title_post_request_parseFromJSON(cJSON *_set_sticker_set_title_post_requestJSON){

    _set_sticker_set_title_post_request_t *_set_sticker_set_title_post_request_local_var = NULL;

    // _set_sticker_set_title_post_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(_set_sticker_set_title_post_requestJSON, "name");
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

    // _set_sticker_set_title_post_request->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(_set_sticker_set_title_post_requestJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }


    _set_sticker_set_title_post_request_local_var = _set_sticker_set_title_post_request_create_internal (
        strdup(name->valuestring),
        strdup(title->valuestring)
        );

    return _set_sticker_set_title_post_request_local_var;
end:
    return NULL;

}
