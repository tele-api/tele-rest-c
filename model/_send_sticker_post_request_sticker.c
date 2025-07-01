#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_send_sticker_post_request_sticker.h"



static _send_sticker_post_request_sticker_t *_send_sticker_post_request_sticker_create_internal(
    ) {
    _send_sticker_post_request_sticker_t *_send_sticker_post_request_sticker_local_var = malloc(sizeof(_send_sticker_post_request_sticker_t));
    if (!_send_sticker_post_request_sticker_local_var) {
        return NULL;
    }

    _send_sticker_post_request_sticker_local_var->_library_owned = 1;
    return _send_sticker_post_request_sticker_local_var;
}

__attribute__((deprecated)) _send_sticker_post_request_sticker_t *_send_sticker_post_request_sticker_create(
    ) {
    return _send_sticker_post_request_sticker_create_internal (
        );
}

void _send_sticker_post_request_sticker_free(_send_sticker_post_request_sticker_t *_send_sticker_post_request_sticker) {
    if(NULL == _send_sticker_post_request_sticker){
        return ;
    }
    if(_send_sticker_post_request_sticker->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_send_sticker_post_request_sticker_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_send_sticker_post_request_sticker);
}

cJSON *_send_sticker_post_request_sticker_convertToJSON(_send_sticker_post_request_sticker_t *_send_sticker_post_request_sticker) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_send_sticker_post_request_sticker_t *_send_sticker_post_request_sticker_parseFromJSON(cJSON *_send_sticker_post_request_stickerJSON){

    _send_sticker_post_request_sticker_t *_send_sticker_post_request_sticker_local_var = NULL;


    _send_sticker_post_request_sticker_local_var = _send_sticker_post_request_sticker_create_internal (
        );

    return _send_sticker_post_request_sticker_local_var;
end:
    return NULL;

}
