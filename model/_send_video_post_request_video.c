#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_send_video_post_request_video.h"



static _send_video_post_request_video_t *_send_video_post_request_video_create_internal(
    ) {
    _send_video_post_request_video_t *_send_video_post_request_video_local_var = malloc(sizeof(_send_video_post_request_video_t));
    if (!_send_video_post_request_video_local_var) {
        return NULL;
    }

    _send_video_post_request_video_local_var->_library_owned = 1;
    return _send_video_post_request_video_local_var;
}

__attribute__((deprecated)) _send_video_post_request_video_t *_send_video_post_request_video_create(
    ) {
    return _send_video_post_request_video_create_internal (
        );
}

void _send_video_post_request_video_free(_send_video_post_request_video_t *_send_video_post_request_video) {
    if(NULL == _send_video_post_request_video){
        return ;
    }
    if(_send_video_post_request_video->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_send_video_post_request_video_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_send_video_post_request_video);
}

cJSON *_send_video_post_request_video_convertToJSON(_send_video_post_request_video_t *_send_video_post_request_video) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_send_video_post_request_video_t *_send_video_post_request_video_parseFromJSON(cJSON *_send_video_post_request_videoJSON){

    _send_video_post_request_video_t *_send_video_post_request_video_local_var = NULL;


    _send_video_post_request_video_local_var = _send_video_post_request_video_create_internal (
        );

    return _send_video_post_request_video_local_var;
end:
    return NULL;

}
