#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_send_video_post_request_cover.h"



static _send_video_post_request_cover_t *_send_video_post_request_cover_create_internal(
    ) {
    _send_video_post_request_cover_t *_send_video_post_request_cover_local_var = malloc(sizeof(_send_video_post_request_cover_t));
    if (!_send_video_post_request_cover_local_var) {
        return NULL;
    }

    _send_video_post_request_cover_local_var->_library_owned = 1;
    return _send_video_post_request_cover_local_var;
}

__attribute__((deprecated)) _send_video_post_request_cover_t *_send_video_post_request_cover_create(
    ) {
    return _send_video_post_request_cover_create_internal (
        );
}

void _send_video_post_request_cover_free(_send_video_post_request_cover_t *_send_video_post_request_cover) {
    if(NULL == _send_video_post_request_cover){
        return ;
    }
    if(_send_video_post_request_cover->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_send_video_post_request_cover_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_send_video_post_request_cover);
}

cJSON *_send_video_post_request_cover_convertToJSON(_send_video_post_request_cover_t *_send_video_post_request_cover) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_send_video_post_request_cover_t *_send_video_post_request_cover_parseFromJSON(cJSON *_send_video_post_request_coverJSON){

    _send_video_post_request_cover_t *_send_video_post_request_cover_local_var = NULL;


    _send_video_post_request_cover_local_var = _send_video_post_request_cover_create_internal (
        );

    return _send_video_post_request_cover_local_var;
end:
    return NULL;

}
