#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_sticker_set_thumbnail_post_request_thumbnail.h"



static _set_sticker_set_thumbnail_post_request_thumbnail_t *_set_sticker_set_thumbnail_post_request_thumbnail_create_internal(
    ) {
    _set_sticker_set_thumbnail_post_request_thumbnail_t *_set_sticker_set_thumbnail_post_request_thumbnail_local_var = malloc(sizeof(_set_sticker_set_thumbnail_post_request_thumbnail_t));
    if (!_set_sticker_set_thumbnail_post_request_thumbnail_local_var) {
        return NULL;
    }

    _set_sticker_set_thumbnail_post_request_thumbnail_local_var->_library_owned = 1;
    return _set_sticker_set_thumbnail_post_request_thumbnail_local_var;
}

__attribute__((deprecated)) _set_sticker_set_thumbnail_post_request_thumbnail_t *_set_sticker_set_thumbnail_post_request_thumbnail_create(
    ) {
    return _set_sticker_set_thumbnail_post_request_thumbnail_create_internal (
        );
}

void _set_sticker_set_thumbnail_post_request_thumbnail_free(_set_sticker_set_thumbnail_post_request_thumbnail_t *_set_sticker_set_thumbnail_post_request_thumbnail) {
    if(NULL == _set_sticker_set_thumbnail_post_request_thumbnail){
        return ;
    }
    if(_set_sticker_set_thumbnail_post_request_thumbnail->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_sticker_set_thumbnail_post_request_thumbnail_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_set_sticker_set_thumbnail_post_request_thumbnail);
}

cJSON *_set_sticker_set_thumbnail_post_request_thumbnail_convertToJSON(_set_sticker_set_thumbnail_post_request_thumbnail_t *_set_sticker_set_thumbnail_post_request_thumbnail) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_set_sticker_set_thumbnail_post_request_thumbnail_t *_set_sticker_set_thumbnail_post_request_thumbnail_parseFromJSON(cJSON *_set_sticker_set_thumbnail_post_request_thumbnailJSON){

    _set_sticker_set_thumbnail_post_request_thumbnail_t *_set_sticker_set_thumbnail_post_request_thumbnail_local_var = NULL;


    _set_sticker_set_thumbnail_post_request_thumbnail_local_var = _set_sticker_set_thumbnail_post_request_thumbnail_create_internal (
        );

    return _set_sticker_set_thumbnail_post_request_thumbnail_local_var;
end:
    return NULL;

}
