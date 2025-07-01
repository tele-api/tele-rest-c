#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "paid_media_video.h"



static paid_media_video_t *paid_media_video_create_internal(
    char *type,
    video_t *video
    ) {
    paid_media_video_t *paid_media_video_local_var = malloc(sizeof(paid_media_video_t));
    if (!paid_media_video_local_var) {
        return NULL;
    }
    paid_media_video_local_var->type = type;
    paid_media_video_local_var->video = video;

    paid_media_video_local_var->_library_owned = 1;
    return paid_media_video_local_var;
}

__attribute__((deprecated)) paid_media_video_t *paid_media_video_create(
    char *type,
    video_t *video
    ) {
    return paid_media_video_create_internal (
        type,
        video
        );
}

void paid_media_video_free(paid_media_video_t *paid_media_video) {
    if(NULL == paid_media_video){
        return ;
    }
    if(paid_media_video->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "paid_media_video_free");
        return ;
    }
    listEntry_t *listEntry;
    if (paid_media_video->type) {
        free(paid_media_video->type);
        paid_media_video->type = NULL;
    }
    if (paid_media_video->video) {
        video_free(paid_media_video->video);
        paid_media_video->video = NULL;
    }
    free(paid_media_video);
}

cJSON *paid_media_video_convertToJSON(paid_media_video_t *paid_media_video) {
    cJSON *item = cJSON_CreateObject();

    // paid_media_video->type
    if (!paid_media_video->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", paid_media_video->type) == NULL) {
    goto fail; //String
    }


    // paid_media_video->video
    if (!paid_media_video->video) {
        goto fail;
    }
    cJSON *video_local_JSON = video_convertToJSON(paid_media_video->video);
    if(video_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "video", video_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

paid_media_video_t *paid_media_video_parseFromJSON(cJSON *paid_media_videoJSON){

    paid_media_video_t *paid_media_video_local_var = NULL;

    // define the local variable for paid_media_video->video
    video_t *video_local_nonprim = NULL;

    // paid_media_video->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(paid_media_videoJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // paid_media_video->video
    cJSON *video = cJSON_GetObjectItemCaseSensitive(paid_media_videoJSON, "video");
    if (cJSON_IsNull(video)) {
        video = NULL;
    }
    if (!video) {
        goto end;
    }

    
    video_local_nonprim = video_parseFromJSON(video); //nonprimitive


    paid_media_video_local_var = paid_media_video_create_internal (
        strdup(type->valuestring),
        video_local_nonprim
        );

    return paid_media_video_local_var;
end:
    if (video_local_nonprim) {
        video_free(video_local_nonprim);
        video_local_nonprim = NULL;
    }
    return NULL;

}
