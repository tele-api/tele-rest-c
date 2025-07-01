#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "video.h"



static video_t *video_create_internal(
    char *file_id,
    char *file_unique_id,
    int width,
    int height,
    int duration,
    photo_size_t *thumbnail,
    list_t *cover,
    int start_timestamp,
    char *file_name,
    char *mime_type,
    int file_size
    ) {
    video_t *video_local_var = malloc(sizeof(video_t));
    if (!video_local_var) {
        return NULL;
    }
    video_local_var->file_id = file_id;
    video_local_var->file_unique_id = file_unique_id;
    video_local_var->width = width;
    video_local_var->height = height;
    video_local_var->duration = duration;
    video_local_var->thumbnail = thumbnail;
    video_local_var->cover = cover;
    video_local_var->start_timestamp = start_timestamp;
    video_local_var->file_name = file_name;
    video_local_var->mime_type = mime_type;
    video_local_var->file_size = file_size;

    video_local_var->_library_owned = 1;
    return video_local_var;
}

__attribute__((deprecated)) video_t *video_create(
    char *file_id,
    char *file_unique_id,
    int width,
    int height,
    int duration,
    photo_size_t *thumbnail,
    list_t *cover,
    int start_timestamp,
    char *file_name,
    char *mime_type,
    int file_size
    ) {
    return video_create_internal (
        file_id,
        file_unique_id,
        width,
        height,
        duration,
        thumbnail,
        cover,
        start_timestamp,
        file_name,
        mime_type,
        file_size
        );
}

void video_free(video_t *video) {
    if(NULL == video){
        return ;
    }
    if(video->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "video_free");
        return ;
    }
    listEntry_t *listEntry;
    if (video->file_id) {
        free(video->file_id);
        video->file_id = NULL;
    }
    if (video->file_unique_id) {
        free(video->file_unique_id);
        video->file_unique_id = NULL;
    }
    if (video->thumbnail) {
        photo_size_free(video->thumbnail);
        video->thumbnail = NULL;
    }
    if (video->cover) {
        list_ForEach(listEntry, video->cover) {
            photo_size_free(listEntry->data);
        }
        list_freeList(video->cover);
        video->cover = NULL;
    }
    if (video->file_name) {
        free(video->file_name);
        video->file_name = NULL;
    }
    if (video->mime_type) {
        free(video->mime_type);
        video->mime_type = NULL;
    }
    free(video);
}

cJSON *video_convertToJSON(video_t *video) {
    cJSON *item = cJSON_CreateObject();

    // video->file_id
    if (!video->file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_id", video->file_id) == NULL) {
    goto fail; //String
    }


    // video->file_unique_id
    if (!video->file_unique_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_unique_id", video->file_unique_id) == NULL) {
    goto fail; //String
    }


    // video->width
    if (!video->width) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "width", video->width) == NULL) {
    goto fail; //Numeric
    }


    // video->height
    if (!video->height) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "height", video->height) == NULL) {
    goto fail; //Numeric
    }


    // video->duration
    if (!video->duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "duration", video->duration) == NULL) {
    goto fail; //Numeric
    }


    // video->thumbnail
    if(video->thumbnail) {
    cJSON *thumbnail_local_JSON = photo_size_convertToJSON(video->thumbnail);
    if(thumbnail_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "thumbnail", thumbnail_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // video->cover
    if(video->cover) {
    cJSON *cover = cJSON_AddArrayToObject(item, "cover");
    if(cover == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *coverListEntry;
    if (video->cover) {
    list_ForEach(coverListEntry, video->cover) {
    cJSON *itemLocal = photo_size_convertToJSON(coverListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(cover, itemLocal);
    }
    }
    }


    // video->start_timestamp
    if(video->start_timestamp) {
    if(cJSON_AddNumberToObject(item, "start_timestamp", video->start_timestamp) == NULL) {
    goto fail; //Numeric
    }
    }


    // video->file_name
    if(video->file_name) {
    if(cJSON_AddStringToObject(item, "file_name", video->file_name) == NULL) {
    goto fail; //String
    }
    }


    // video->mime_type
    if(video->mime_type) {
    if(cJSON_AddStringToObject(item, "mime_type", video->mime_type) == NULL) {
    goto fail; //String
    }
    }


    // video->file_size
    if(video->file_size) {
    if(cJSON_AddNumberToObject(item, "file_size", video->file_size) == NULL) {
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

video_t *video_parseFromJSON(cJSON *videoJSON){

    video_t *video_local_var = NULL;

    // define the local variable for video->thumbnail
    photo_size_t *thumbnail_local_nonprim = NULL;

    // define the local list for video->cover
    list_t *coverList = NULL;

    // video->file_id
    cJSON *file_id = cJSON_GetObjectItemCaseSensitive(videoJSON, "file_id");
    if (cJSON_IsNull(file_id)) {
        file_id = NULL;
    }
    if (!file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(file_id))
    {
    goto end; //String
    }

    // video->file_unique_id
    cJSON *file_unique_id = cJSON_GetObjectItemCaseSensitive(videoJSON, "file_unique_id");
    if (cJSON_IsNull(file_unique_id)) {
        file_unique_id = NULL;
    }
    if (!file_unique_id) {
        goto end;
    }

    
    if(!cJSON_IsString(file_unique_id))
    {
    goto end; //String
    }

    // video->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(videoJSON, "width");
    if (cJSON_IsNull(width)) {
        width = NULL;
    }
    if (!width) {
        goto end;
    }

    
    if(!cJSON_IsNumber(width))
    {
    goto end; //Numeric
    }

    // video->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(videoJSON, "height");
    if (cJSON_IsNull(height)) {
        height = NULL;
    }
    if (!height) {
        goto end;
    }

    
    if(!cJSON_IsNumber(height))
    {
    goto end; //Numeric
    }

    // video->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(videoJSON, "duration");
    if (cJSON_IsNull(duration)) {
        duration = NULL;
    }
    if (!duration) {
        goto end;
    }

    
    if(!cJSON_IsNumber(duration))
    {
    goto end; //Numeric
    }

    // video->thumbnail
    cJSON *thumbnail = cJSON_GetObjectItemCaseSensitive(videoJSON, "thumbnail");
    if (cJSON_IsNull(thumbnail)) {
        thumbnail = NULL;
    }
    if (thumbnail) { 
    thumbnail_local_nonprim = photo_size_parseFromJSON(thumbnail); //nonprimitive
    }

    // video->cover
    cJSON *cover = cJSON_GetObjectItemCaseSensitive(videoJSON, "cover");
    if (cJSON_IsNull(cover)) {
        cover = NULL;
    }
    if (cover) { 
    cJSON *cover_local_nonprimitive = NULL;
    if(!cJSON_IsArray(cover)){
        goto end; //nonprimitive container
    }

    coverList = list_createList();

    cJSON_ArrayForEach(cover_local_nonprimitive,cover )
    {
        if(!cJSON_IsObject(cover_local_nonprimitive)){
            goto end;
        }
        photo_size_t *coverItem = photo_size_parseFromJSON(cover_local_nonprimitive);

        list_addElement(coverList, coverItem);
    }
    }

    // video->start_timestamp
    cJSON *start_timestamp = cJSON_GetObjectItemCaseSensitive(videoJSON, "start_timestamp");
    if (cJSON_IsNull(start_timestamp)) {
        start_timestamp = NULL;
    }
    if (start_timestamp) { 
    if(!cJSON_IsNumber(start_timestamp))
    {
    goto end; //Numeric
    }
    }

    // video->file_name
    cJSON *file_name = cJSON_GetObjectItemCaseSensitive(videoJSON, "file_name");
    if (cJSON_IsNull(file_name)) {
        file_name = NULL;
    }
    if (file_name) { 
    if(!cJSON_IsString(file_name) && !cJSON_IsNull(file_name))
    {
    goto end; //String
    }
    }

    // video->mime_type
    cJSON *mime_type = cJSON_GetObjectItemCaseSensitive(videoJSON, "mime_type");
    if (cJSON_IsNull(mime_type)) {
        mime_type = NULL;
    }
    if (mime_type) { 
    if(!cJSON_IsString(mime_type) && !cJSON_IsNull(mime_type))
    {
    goto end; //String
    }
    }

    // video->file_size
    cJSON *file_size = cJSON_GetObjectItemCaseSensitive(videoJSON, "file_size");
    if (cJSON_IsNull(file_size)) {
        file_size = NULL;
    }
    if (file_size) { 
    if(!cJSON_IsNumber(file_size))
    {
    goto end; //Numeric
    }
    }


    video_local_var = video_create_internal (
        strdup(file_id->valuestring),
        strdup(file_unique_id->valuestring),
        width->valuedouble,
        height->valuedouble,
        duration->valuedouble,
        thumbnail ? thumbnail_local_nonprim : NULL,
        cover ? coverList : NULL,
        start_timestamp ? start_timestamp->valuedouble : 0,
        file_name && !cJSON_IsNull(file_name) ? strdup(file_name->valuestring) : NULL,
        mime_type && !cJSON_IsNull(mime_type) ? strdup(mime_type->valuestring) : NULL,
        file_size ? file_size->valuedouble : 0
        );

    return video_local_var;
end:
    if (thumbnail_local_nonprim) {
        photo_size_free(thumbnail_local_nonprim);
        thumbnail_local_nonprim = NULL;
    }
    if (coverList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, coverList) {
            photo_size_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(coverList);
        coverList = NULL;
    }
    return NULL;

}
