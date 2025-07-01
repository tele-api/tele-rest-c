#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "paid_media.h"



static paid_media_t *paid_media_create_internal(
    char *type,
    list_t *photo,
    video_t *video,
    int width,
    int height,
    int duration
    ) {
    paid_media_t *paid_media_local_var = malloc(sizeof(paid_media_t));
    if (!paid_media_local_var) {
        return NULL;
    }
    paid_media_local_var->type = type;
    paid_media_local_var->photo = photo;
    paid_media_local_var->video = video;
    paid_media_local_var->width = width;
    paid_media_local_var->height = height;
    paid_media_local_var->duration = duration;

    paid_media_local_var->_library_owned = 1;
    return paid_media_local_var;
}

__attribute__((deprecated)) paid_media_t *paid_media_create(
    char *type,
    list_t *photo,
    video_t *video,
    int width,
    int height,
    int duration
    ) {
    return paid_media_create_internal (
        type,
        photo,
        video,
        width,
        height,
        duration
        );
}

void paid_media_free(paid_media_t *paid_media) {
    if(NULL == paid_media){
        return ;
    }
    if(paid_media->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "paid_media_free");
        return ;
    }
    listEntry_t *listEntry;
    if (paid_media->type) {
        free(paid_media->type);
        paid_media->type = NULL;
    }
    if (paid_media->photo) {
        list_ForEach(listEntry, paid_media->photo) {
            photo_size_free(listEntry->data);
        }
        list_freeList(paid_media->photo);
        paid_media->photo = NULL;
    }
    if (paid_media->video) {
        video_free(paid_media->video);
        paid_media->video = NULL;
    }
    free(paid_media);
}

cJSON *paid_media_convertToJSON(paid_media_t *paid_media) {
    cJSON *item = cJSON_CreateObject();

    // paid_media->type
    if (!paid_media->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", paid_media->type) == NULL) {
    goto fail; //String
    }


    // paid_media->photo
    if (!paid_media->photo) {
        goto fail;
    }
    cJSON *photo = cJSON_AddArrayToObject(item, "photo");
    if(photo == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *photoListEntry;
    if (paid_media->photo) {
    list_ForEach(photoListEntry, paid_media->photo) {
    cJSON *itemLocal = photo_size_convertToJSON(photoListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(photo, itemLocal);
    }
    }


    // paid_media->video
    if (!paid_media->video) {
        goto fail;
    }
    cJSON *video_local_JSON = video_convertToJSON(paid_media->video);
    if(video_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "video", video_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // paid_media->width
    if(paid_media->width) {
    if(cJSON_AddNumberToObject(item, "width", paid_media->width) == NULL) {
    goto fail; //Numeric
    }
    }


    // paid_media->height
    if(paid_media->height) {
    if(cJSON_AddNumberToObject(item, "height", paid_media->height) == NULL) {
    goto fail; //Numeric
    }
    }


    // paid_media->duration
    if(paid_media->duration) {
    if(cJSON_AddNumberToObject(item, "duration", paid_media->duration) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

paid_media_t *paid_media_parseFromJSON(cJSON *paid_mediaJSON){

    paid_media_t *paid_media_local_var = NULL;

    // define the local list for paid_media->photo
    list_t *photoList = NULL;

    // define the local variable for paid_media->video
    video_t *video_local_nonprim = NULL;

    // paid_media->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(paid_mediaJSON, "type");
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

    // paid_media->photo
    cJSON *photo = cJSON_GetObjectItemCaseSensitive(paid_mediaJSON, "photo");
    if (cJSON_IsNull(photo)) {
        photo = NULL;
    }
    if (!photo) {
        goto end;
    }

    
    cJSON *photo_local_nonprimitive = NULL;
    if(!cJSON_IsArray(photo)){
        goto end; //nonprimitive container
    }

    photoList = list_createList();

    cJSON_ArrayForEach(photo_local_nonprimitive,photo )
    {
        if(!cJSON_IsObject(photo_local_nonprimitive)){
            goto end;
        }
        photo_size_t *photoItem = photo_size_parseFromJSON(photo_local_nonprimitive);

        list_addElement(photoList, photoItem);
    }

    // paid_media->video
    cJSON *video = cJSON_GetObjectItemCaseSensitive(paid_mediaJSON, "video");
    if (cJSON_IsNull(video)) {
        video = NULL;
    }
    if (!video) {
        goto end;
    }

    
    video_local_nonprim = video_parseFromJSON(video); //nonprimitive

    // paid_media->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(paid_mediaJSON, "width");
    if (cJSON_IsNull(width)) {
        width = NULL;
    }
    if (width) { 
    if(!cJSON_IsNumber(width))
    {
    goto end; //Numeric
    }
    }

    // paid_media->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(paid_mediaJSON, "height");
    if (cJSON_IsNull(height)) {
        height = NULL;
    }
    if (height) { 
    if(!cJSON_IsNumber(height))
    {
    goto end; //Numeric
    }
    }

    // paid_media->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(paid_mediaJSON, "duration");
    if (cJSON_IsNull(duration)) {
        duration = NULL;
    }
    if (duration) { 
    if(!cJSON_IsNumber(duration))
    {
    goto end; //Numeric
    }
    }


    paid_media_local_var = paid_media_create_internal (
        strdup(type->valuestring),
        photoList,
        video_local_nonprim,
        width ? width->valuedouble : 0,
        height ? height->valuedouble : 0,
        duration ? duration->valuedouble : 0
        );

    return paid_media_local_var;
end:
    if (photoList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, photoList) {
            photo_size_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(photoList);
        photoList = NULL;
    }
    if (video_local_nonprim) {
        video_free(video_local_nonprim);
        video_local_nonprim = NULL;
    }
    return NULL;

}
