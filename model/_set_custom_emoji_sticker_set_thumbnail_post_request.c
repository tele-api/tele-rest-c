#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_custom_emoji_sticker_set_thumbnail_post_request.h"



static _set_custom_emoji_sticker_set_thumbnail_post_request_t *_set_custom_emoji_sticker_set_thumbnail_post_request_create_internal(
    char *name,
    char *custom_emoji_id
    ) {
    _set_custom_emoji_sticker_set_thumbnail_post_request_t *_set_custom_emoji_sticker_set_thumbnail_post_request_local_var = malloc(sizeof(_set_custom_emoji_sticker_set_thumbnail_post_request_t));
    if (!_set_custom_emoji_sticker_set_thumbnail_post_request_local_var) {
        return NULL;
    }
    _set_custom_emoji_sticker_set_thumbnail_post_request_local_var->name = name;
    _set_custom_emoji_sticker_set_thumbnail_post_request_local_var->custom_emoji_id = custom_emoji_id;

    _set_custom_emoji_sticker_set_thumbnail_post_request_local_var->_library_owned = 1;
    return _set_custom_emoji_sticker_set_thumbnail_post_request_local_var;
}

__attribute__((deprecated)) _set_custom_emoji_sticker_set_thumbnail_post_request_t *_set_custom_emoji_sticker_set_thumbnail_post_request_create(
    char *name,
    char *custom_emoji_id
    ) {
    return _set_custom_emoji_sticker_set_thumbnail_post_request_create_internal (
        name,
        custom_emoji_id
        );
}

void _set_custom_emoji_sticker_set_thumbnail_post_request_free(_set_custom_emoji_sticker_set_thumbnail_post_request_t *_set_custom_emoji_sticker_set_thumbnail_post_request) {
    if(NULL == _set_custom_emoji_sticker_set_thumbnail_post_request){
        return ;
    }
    if(_set_custom_emoji_sticker_set_thumbnail_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_custom_emoji_sticker_set_thumbnail_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_custom_emoji_sticker_set_thumbnail_post_request->name) {
        free(_set_custom_emoji_sticker_set_thumbnail_post_request->name);
        _set_custom_emoji_sticker_set_thumbnail_post_request->name = NULL;
    }
    if (_set_custom_emoji_sticker_set_thumbnail_post_request->custom_emoji_id) {
        free(_set_custom_emoji_sticker_set_thumbnail_post_request->custom_emoji_id);
        _set_custom_emoji_sticker_set_thumbnail_post_request->custom_emoji_id = NULL;
    }
    free(_set_custom_emoji_sticker_set_thumbnail_post_request);
}

cJSON *_set_custom_emoji_sticker_set_thumbnail_post_request_convertToJSON(_set_custom_emoji_sticker_set_thumbnail_post_request_t *_set_custom_emoji_sticker_set_thumbnail_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_custom_emoji_sticker_set_thumbnail_post_request->name
    if (!_set_custom_emoji_sticker_set_thumbnail_post_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", _set_custom_emoji_sticker_set_thumbnail_post_request->name) == NULL) {
    goto fail; //String
    }


    // _set_custom_emoji_sticker_set_thumbnail_post_request->custom_emoji_id
    if(_set_custom_emoji_sticker_set_thumbnail_post_request->custom_emoji_id) {
    if(cJSON_AddStringToObject(item, "custom_emoji_id", _set_custom_emoji_sticker_set_thumbnail_post_request->custom_emoji_id) == NULL) {
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

_set_custom_emoji_sticker_set_thumbnail_post_request_t *_set_custom_emoji_sticker_set_thumbnail_post_request_parseFromJSON(cJSON *_set_custom_emoji_sticker_set_thumbnail_post_requestJSON){

    _set_custom_emoji_sticker_set_thumbnail_post_request_t *_set_custom_emoji_sticker_set_thumbnail_post_request_local_var = NULL;

    // _set_custom_emoji_sticker_set_thumbnail_post_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(_set_custom_emoji_sticker_set_thumbnail_post_requestJSON, "name");
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

    // _set_custom_emoji_sticker_set_thumbnail_post_request->custom_emoji_id
    cJSON *custom_emoji_id = cJSON_GetObjectItemCaseSensitive(_set_custom_emoji_sticker_set_thumbnail_post_requestJSON, "custom_emoji_id");
    if (cJSON_IsNull(custom_emoji_id)) {
        custom_emoji_id = NULL;
    }
    if (custom_emoji_id) { 
    if(!cJSON_IsString(custom_emoji_id) && !cJSON_IsNull(custom_emoji_id))
    {
    goto end; //String
    }
    }


    _set_custom_emoji_sticker_set_thumbnail_post_request_local_var = _set_custom_emoji_sticker_set_thumbnail_post_request_create_internal (
        strdup(name->valuestring),
        custom_emoji_id && !cJSON_IsNull(custom_emoji_id) ? strdup(custom_emoji_id->valuestring) : NULL
        );

    return _set_custom_emoji_sticker_set_thumbnail_post_request_local_var;
end:
    return NULL;

}
