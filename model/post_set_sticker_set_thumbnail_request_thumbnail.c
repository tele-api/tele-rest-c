#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_sticker_set_thumbnail_request_thumbnail.h"



static post_set_sticker_set_thumbnail_request_thumbnail_t *post_set_sticker_set_thumbnail_request_thumbnail_create_internal(
    ) {
    post_set_sticker_set_thumbnail_request_thumbnail_t *post_set_sticker_set_thumbnail_request_thumbnail_local_var = malloc(sizeof(post_set_sticker_set_thumbnail_request_thumbnail_t));
    if (!post_set_sticker_set_thumbnail_request_thumbnail_local_var) {
        return NULL;
    }

    post_set_sticker_set_thumbnail_request_thumbnail_local_var->_library_owned = 1;
    return post_set_sticker_set_thumbnail_request_thumbnail_local_var;
}

__attribute__((deprecated)) post_set_sticker_set_thumbnail_request_thumbnail_t *post_set_sticker_set_thumbnail_request_thumbnail_create(
    ) {
    return post_set_sticker_set_thumbnail_request_thumbnail_create_internal (
        );
}

void post_set_sticker_set_thumbnail_request_thumbnail_free(post_set_sticker_set_thumbnail_request_thumbnail_t *post_set_sticker_set_thumbnail_request_thumbnail) {
    if(NULL == post_set_sticker_set_thumbnail_request_thumbnail){
        return ;
    }
    if(post_set_sticker_set_thumbnail_request_thumbnail->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_sticker_set_thumbnail_request_thumbnail_free");
        return ;
    }
    listEntry_t *listEntry;
    free(post_set_sticker_set_thumbnail_request_thumbnail);
}

cJSON *post_set_sticker_set_thumbnail_request_thumbnail_convertToJSON(post_set_sticker_set_thumbnail_request_thumbnail_t *post_set_sticker_set_thumbnail_request_thumbnail) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_set_sticker_set_thumbnail_request_thumbnail_t *post_set_sticker_set_thumbnail_request_thumbnail_parseFromJSON(cJSON *post_set_sticker_set_thumbnail_request_thumbnailJSON){

    post_set_sticker_set_thumbnail_request_thumbnail_t *post_set_sticker_set_thumbnail_request_thumbnail_local_var = NULL;


    post_set_sticker_set_thumbnail_request_thumbnail_local_var = post_set_sticker_set_thumbnail_request_thumbnail_create_internal (
        );

    return post_set_sticker_set_thumbnail_request_thumbnail_local_var;
end:
    return NULL;

}
