#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_send_animation_post_request_animation.h"



static _send_animation_post_request_animation_t *_send_animation_post_request_animation_create_internal(
    ) {
    _send_animation_post_request_animation_t *_send_animation_post_request_animation_local_var = malloc(sizeof(_send_animation_post_request_animation_t));
    if (!_send_animation_post_request_animation_local_var) {
        return NULL;
    }

    _send_animation_post_request_animation_local_var->_library_owned = 1;
    return _send_animation_post_request_animation_local_var;
}

__attribute__((deprecated)) _send_animation_post_request_animation_t *_send_animation_post_request_animation_create(
    ) {
    return _send_animation_post_request_animation_create_internal (
        );
}

void _send_animation_post_request_animation_free(_send_animation_post_request_animation_t *_send_animation_post_request_animation) {
    if(NULL == _send_animation_post_request_animation){
        return ;
    }
    if(_send_animation_post_request_animation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_send_animation_post_request_animation_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_send_animation_post_request_animation);
}

cJSON *_send_animation_post_request_animation_convertToJSON(_send_animation_post_request_animation_t *_send_animation_post_request_animation) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_send_animation_post_request_animation_t *_send_animation_post_request_animation_parseFromJSON(cJSON *_send_animation_post_request_animationJSON){

    _send_animation_post_request_animation_t *_send_animation_post_request_animation_local_var = NULL;


    _send_animation_post_request_animation_local_var = _send_animation_post_request_animation_create_internal (
        );

    return _send_animation_post_request_animation_local_var;
end:
    return NULL;

}
