#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_send_photo_request_photo.h"



static post_send_photo_request_photo_t *post_send_photo_request_photo_create_internal(
    ) {
    post_send_photo_request_photo_t *post_send_photo_request_photo_local_var = malloc(sizeof(post_send_photo_request_photo_t));
    if (!post_send_photo_request_photo_local_var) {
        return NULL;
    }

    post_send_photo_request_photo_local_var->_library_owned = 1;
    return post_send_photo_request_photo_local_var;
}

__attribute__((deprecated)) post_send_photo_request_photo_t *post_send_photo_request_photo_create(
    ) {
    return post_send_photo_request_photo_create_internal (
        );
}

void post_send_photo_request_photo_free(post_send_photo_request_photo_t *post_send_photo_request_photo) {
    if(NULL == post_send_photo_request_photo){
        return ;
    }
    if(post_send_photo_request_photo->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_send_photo_request_photo_free");
        return ;
    }
    listEntry_t *listEntry;
    free(post_send_photo_request_photo);
}

cJSON *post_send_photo_request_photo_convertToJSON(post_send_photo_request_photo_t *post_send_photo_request_photo) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_send_photo_request_photo_t *post_send_photo_request_photo_parseFromJSON(cJSON *post_send_photo_request_photoJSON){

    post_send_photo_request_photo_t *post_send_photo_request_photo_local_var = NULL;


    post_send_photo_request_photo_local_var = post_send_photo_request_photo_create_internal (
        );

    return post_send_photo_request_photo_local_var;
end:
    return NULL;

}
