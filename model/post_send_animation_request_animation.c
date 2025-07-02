#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_send_animation_request_animation.h"



static post_send_animation_request_animation_t *post_send_animation_request_animation_create_internal(
    ) {
    post_send_animation_request_animation_t *post_send_animation_request_animation_local_var = malloc(sizeof(post_send_animation_request_animation_t));
    if (!post_send_animation_request_animation_local_var) {
        return NULL;
    }

    post_send_animation_request_animation_local_var->_library_owned = 1;
    return post_send_animation_request_animation_local_var;
}

__attribute__((deprecated)) post_send_animation_request_animation_t *post_send_animation_request_animation_create(
    ) {
    return post_send_animation_request_animation_create_internal (
        );
}

void post_send_animation_request_animation_free(post_send_animation_request_animation_t *post_send_animation_request_animation) {
    if(NULL == post_send_animation_request_animation){
        return ;
    }
    if(post_send_animation_request_animation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_send_animation_request_animation_free");
        return ;
    }
    listEntry_t *listEntry;
    free(post_send_animation_request_animation);
}

cJSON *post_send_animation_request_animation_convertToJSON(post_send_animation_request_animation_t *post_send_animation_request_animation) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_send_animation_request_animation_t *post_send_animation_request_animation_parseFromJSON(cJSON *post_send_animation_request_animationJSON){

    post_send_animation_request_animation_t *post_send_animation_request_animation_local_var = NULL;


    post_send_animation_request_animation_local_var = post_send_animation_request_animation_create_internal (
        );

    return post_send_animation_request_animation_local_var;
end:
    return NULL;

}
