#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_send_voice_post_request_voice.h"



static _send_voice_post_request_voice_t *_send_voice_post_request_voice_create_internal(
    ) {
    _send_voice_post_request_voice_t *_send_voice_post_request_voice_local_var = malloc(sizeof(_send_voice_post_request_voice_t));
    if (!_send_voice_post_request_voice_local_var) {
        return NULL;
    }

    _send_voice_post_request_voice_local_var->_library_owned = 1;
    return _send_voice_post_request_voice_local_var;
}

__attribute__((deprecated)) _send_voice_post_request_voice_t *_send_voice_post_request_voice_create(
    ) {
    return _send_voice_post_request_voice_create_internal (
        );
}

void _send_voice_post_request_voice_free(_send_voice_post_request_voice_t *_send_voice_post_request_voice) {
    if(NULL == _send_voice_post_request_voice){
        return ;
    }
    if(_send_voice_post_request_voice->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_send_voice_post_request_voice_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_send_voice_post_request_voice);
}

cJSON *_send_voice_post_request_voice_convertToJSON(_send_voice_post_request_voice_t *_send_voice_post_request_voice) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_send_voice_post_request_voice_t *_send_voice_post_request_voice_parseFromJSON(cJSON *_send_voice_post_request_voiceJSON){

    _send_voice_post_request_voice_t *_send_voice_post_request_voice_local_var = NULL;


    _send_voice_post_request_voice_local_var = _send_voice_post_request_voice_create_internal (
        );

    return _send_voice_post_request_voice_local_var;
end:
    return NULL;

}
