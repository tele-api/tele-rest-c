#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_send_video_request_cover.h"



static post_send_video_request_cover_t *post_send_video_request_cover_create_internal(
    ) {
    post_send_video_request_cover_t *post_send_video_request_cover_local_var = malloc(sizeof(post_send_video_request_cover_t));
    if (!post_send_video_request_cover_local_var) {
        return NULL;
    }

    post_send_video_request_cover_local_var->_library_owned = 1;
    return post_send_video_request_cover_local_var;
}

__attribute__((deprecated)) post_send_video_request_cover_t *post_send_video_request_cover_create(
    ) {
    return post_send_video_request_cover_create_internal (
        );
}

void post_send_video_request_cover_free(post_send_video_request_cover_t *post_send_video_request_cover) {
    if(NULL == post_send_video_request_cover){
        return ;
    }
    if(post_send_video_request_cover->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_send_video_request_cover_free");
        return ;
    }
    listEntry_t *listEntry;
    free(post_send_video_request_cover);
}

cJSON *post_send_video_request_cover_convertToJSON(post_send_video_request_cover_t *post_send_video_request_cover) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_send_video_request_cover_t *post_send_video_request_cover_parseFromJSON(cJSON *post_send_video_request_coverJSON){

    post_send_video_request_cover_t *post_send_video_request_cover_local_var = NULL;


    post_send_video_request_cover_local_var = post_send_video_request_cover_create_internal (
        );

    return post_send_video_request_cover_local_var;
end:
    return NULL;

}
