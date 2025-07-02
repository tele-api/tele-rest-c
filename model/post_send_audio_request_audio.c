#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_send_audio_request_audio.h"



static post_send_audio_request_audio_t *post_send_audio_request_audio_create_internal(
    ) {
    post_send_audio_request_audio_t *post_send_audio_request_audio_local_var = malloc(sizeof(post_send_audio_request_audio_t));
    if (!post_send_audio_request_audio_local_var) {
        return NULL;
    }

    post_send_audio_request_audio_local_var->_library_owned = 1;
    return post_send_audio_request_audio_local_var;
}

__attribute__((deprecated)) post_send_audio_request_audio_t *post_send_audio_request_audio_create(
    ) {
    return post_send_audio_request_audio_create_internal (
        );
}

void post_send_audio_request_audio_free(post_send_audio_request_audio_t *post_send_audio_request_audio) {
    if(NULL == post_send_audio_request_audio){
        return ;
    }
    if(post_send_audio_request_audio->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_send_audio_request_audio_free");
        return ;
    }
    listEntry_t *listEntry;
    free(post_send_audio_request_audio);
}

cJSON *post_send_audio_request_audio_convertToJSON(post_send_audio_request_audio_t *post_send_audio_request_audio) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_send_audio_request_audio_t *post_send_audio_request_audio_parseFromJSON(cJSON *post_send_audio_request_audioJSON){

    post_send_audio_request_audio_t *post_send_audio_request_audio_local_var = NULL;


    post_send_audio_request_audio_local_var = post_send_audio_request_audio_create_internal (
        );

    return post_send_audio_request_audio_local_var;
end:
    return NULL;

}
