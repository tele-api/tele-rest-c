#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_send_voice_request_voice.h"



static post_send_voice_request_voice_t *post_send_voice_request_voice_create_internal(
    ) {
    post_send_voice_request_voice_t *post_send_voice_request_voice_local_var = malloc(sizeof(post_send_voice_request_voice_t));
    if (!post_send_voice_request_voice_local_var) {
        return NULL;
    }

    post_send_voice_request_voice_local_var->_library_owned = 1;
    return post_send_voice_request_voice_local_var;
}

__attribute__((deprecated)) post_send_voice_request_voice_t *post_send_voice_request_voice_create(
    ) {
    return post_send_voice_request_voice_create_internal (
        );
}

void post_send_voice_request_voice_free(post_send_voice_request_voice_t *post_send_voice_request_voice) {
    if(NULL == post_send_voice_request_voice){
        return ;
    }
    if(post_send_voice_request_voice->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_send_voice_request_voice_free");
        return ;
    }
    listEntry_t *listEntry;
    free(post_send_voice_request_voice);
}

cJSON *post_send_voice_request_voice_convertToJSON(post_send_voice_request_voice_t *post_send_voice_request_voice) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_send_voice_request_voice_t *post_send_voice_request_voice_parseFromJSON(cJSON *post_send_voice_request_voiceJSON){

    post_send_voice_request_voice_t *post_send_voice_request_voice_local_var = NULL;


    post_send_voice_request_voice_local_var = post_send_voice_request_voice_create_internal (
        );

    return post_send_voice_request_voice_local_var;
end:
    return NULL;

}
