#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_send_video_note_post_request_video_note.h"



static _send_video_note_post_request_video_note_t *_send_video_note_post_request_video_note_create_internal(
    ) {
    _send_video_note_post_request_video_note_t *_send_video_note_post_request_video_note_local_var = malloc(sizeof(_send_video_note_post_request_video_note_t));
    if (!_send_video_note_post_request_video_note_local_var) {
        return NULL;
    }

    _send_video_note_post_request_video_note_local_var->_library_owned = 1;
    return _send_video_note_post_request_video_note_local_var;
}

__attribute__((deprecated)) _send_video_note_post_request_video_note_t *_send_video_note_post_request_video_note_create(
    ) {
    return _send_video_note_post_request_video_note_create_internal (
        );
}

void _send_video_note_post_request_video_note_free(_send_video_note_post_request_video_note_t *_send_video_note_post_request_video_note) {
    if(NULL == _send_video_note_post_request_video_note){
        return ;
    }
    if(_send_video_note_post_request_video_note->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_send_video_note_post_request_video_note_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_send_video_note_post_request_video_note);
}

cJSON *_send_video_note_post_request_video_note_convertToJSON(_send_video_note_post_request_video_note_t *_send_video_note_post_request_video_note) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_send_video_note_post_request_video_note_t *_send_video_note_post_request_video_note_parseFromJSON(cJSON *_send_video_note_post_request_video_noteJSON){

    _send_video_note_post_request_video_note_t *_send_video_note_post_request_video_note_local_var = NULL;


    _send_video_note_post_request_video_note_local_var = _send_video_note_post_request_video_note_create_internal (
        );

    return _send_video_note_post_request_video_note_local_var;
end:
    return NULL;

}
