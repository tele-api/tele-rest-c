#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_send_photo_post_request_photo.h"



static _send_photo_post_request_photo_t *_send_photo_post_request_photo_create_internal(
    ) {
    _send_photo_post_request_photo_t *_send_photo_post_request_photo_local_var = malloc(sizeof(_send_photo_post_request_photo_t));
    if (!_send_photo_post_request_photo_local_var) {
        return NULL;
    }

    _send_photo_post_request_photo_local_var->_library_owned = 1;
    return _send_photo_post_request_photo_local_var;
}

__attribute__((deprecated)) _send_photo_post_request_photo_t *_send_photo_post_request_photo_create(
    ) {
    return _send_photo_post_request_photo_create_internal (
        );
}

void _send_photo_post_request_photo_free(_send_photo_post_request_photo_t *_send_photo_post_request_photo) {
    if(NULL == _send_photo_post_request_photo){
        return ;
    }
    if(_send_photo_post_request_photo->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_send_photo_post_request_photo_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_send_photo_post_request_photo);
}

cJSON *_send_photo_post_request_photo_convertToJSON(_send_photo_post_request_photo_t *_send_photo_post_request_photo) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_send_photo_post_request_photo_t *_send_photo_post_request_photo_parseFromJSON(cJSON *_send_photo_post_request_photoJSON){

    _send_photo_post_request_photo_t *_send_photo_post_request_photo_local_var = NULL;


    _send_photo_post_request_photo_local_var = _send_photo_post_request_photo_create_internal (
        );

    return _send_photo_post_request_photo_local_var;
end:
    return NULL;

}
