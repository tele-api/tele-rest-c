#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_send_audio_post_request_thumbnail.h"



static _send_audio_post_request_thumbnail_t *_send_audio_post_request_thumbnail_create_internal(
    ) {
    _send_audio_post_request_thumbnail_t *_send_audio_post_request_thumbnail_local_var = malloc(sizeof(_send_audio_post_request_thumbnail_t));
    if (!_send_audio_post_request_thumbnail_local_var) {
        return NULL;
    }

    _send_audio_post_request_thumbnail_local_var->_library_owned = 1;
    return _send_audio_post_request_thumbnail_local_var;
}

__attribute__((deprecated)) _send_audio_post_request_thumbnail_t *_send_audio_post_request_thumbnail_create(
    ) {
    return _send_audio_post_request_thumbnail_create_internal (
        );
}

void _send_audio_post_request_thumbnail_free(_send_audio_post_request_thumbnail_t *_send_audio_post_request_thumbnail) {
    if(NULL == _send_audio_post_request_thumbnail){
        return ;
    }
    if(_send_audio_post_request_thumbnail->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_send_audio_post_request_thumbnail_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_send_audio_post_request_thumbnail);
}

cJSON *_send_audio_post_request_thumbnail_convertToJSON(_send_audio_post_request_thumbnail_t *_send_audio_post_request_thumbnail) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_send_audio_post_request_thumbnail_t *_send_audio_post_request_thumbnail_parseFromJSON(cJSON *_send_audio_post_request_thumbnailJSON){

    _send_audio_post_request_thumbnail_t *_send_audio_post_request_thumbnail_local_var = NULL;


    _send_audio_post_request_thumbnail_local_var = _send_audio_post_request_thumbnail_create_internal (
        );

    return _send_audio_post_request_thumbnail_local_var;
end:
    return NULL;

}
