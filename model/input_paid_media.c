#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_paid_media.h"



static input_paid_media_t *input_paid_media_create_internal(
    char *type,
    char *media,
    char *thumbnail,
    char *cover,
    int start_timestamp,
    int width,
    int height,
    int duration,
    int supports_streaming
    ) {
    input_paid_media_t *input_paid_media_local_var = malloc(sizeof(input_paid_media_t));
    if (!input_paid_media_local_var) {
        return NULL;
    }
    input_paid_media_local_var->type = type;
    input_paid_media_local_var->media = media;
    input_paid_media_local_var->thumbnail = thumbnail;
    input_paid_media_local_var->cover = cover;
    input_paid_media_local_var->start_timestamp = start_timestamp;
    input_paid_media_local_var->width = width;
    input_paid_media_local_var->height = height;
    input_paid_media_local_var->duration = duration;
    input_paid_media_local_var->supports_streaming = supports_streaming;

    input_paid_media_local_var->_library_owned = 1;
    return input_paid_media_local_var;
}

__attribute__((deprecated)) input_paid_media_t *input_paid_media_create(
    char *type,
    char *media,
    char *thumbnail,
    char *cover,
    int start_timestamp,
    int width,
    int height,
    int duration,
    int supports_streaming
    ) {
    return input_paid_media_create_internal (
        type,
        media,
        thumbnail,
        cover,
        start_timestamp,
        width,
        height,
        duration,
        supports_streaming
        );
}

void input_paid_media_free(input_paid_media_t *input_paid_media) {
    if(NULL == input_paid_media){
        return ;
    }
    if(input_paid_media->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_paid_media_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_paid_media->type) {
        free(input_paid_media->type);
        input_paid_media->type = NULL;
    }
    if (input_paid_media->media) {
        free(input_paid_media->media);
        input_paid_media->media = NULL;
    }
    if (input_paid_media->thumbnail) {
        free(input_paid_media->thumbnail);
        input_paid_media->thumbnail = NULL;
    }
    if (input_paid_media->cover) {
        free(input_paid_media->cover);
        input_paid_media->cover = NULL;
    }
    free(input_paid_media);
}

cJSON *input_paid_media_convertToJSON(input_paid_media_t *input_paid_media) {
    cJSON *item = cJSON_CreateObject();

    // input_paid_media->type
    if (!input_paid_media->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", input_paid_media->type) == NULL) {
    goto fail; //String
    }


    // input_paid_media->media
    if (!input_paid_media->media) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "media", input_paid_media->media) == NULL) {
    goto fail; //String
    }


    // input_paid_media->thumbnail
    if(input_paid_media->thumbnail) {
    if(cJSON_AddStringToObject(item, "thumbnail", input_paid_media->thumbnail) == NULL) {
    goto fail; //String
    }
    }


    // input_paid_media->cover
    if(input_paid_media->cover) {
    if(cJSON_AddStringToObject(item, "cover", input_paid_media->cover) == NULL) {
    goto fail; //String
    }
    }


    // input_paid_media->start_timestamp
    if(input_paid_media->start_timestamp) {
    if(cJSON_AddNumberToObject(item, "start_timestamp", input_paid_media->start_timestamp) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_paid_media->width
    if(input_paid_media->width) {
    if(cJSON_AddNumberToObject(item, "width", input_paid_media->width) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_paid_media->height
    if(input_paid_media->height) {
    if(cJSON_AddNumberToObject(item, "height", input_paid_media->height) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_paid_media->duration
    if(input_paid_media->duration) {
    if(cJSON_AddNumberToObject(item, "duration", input_paid_media->duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_paid_media->supports_streaming
    if(input_paid_media->supports_streaming) {
    if(cJSON_AddBoolToObject(item, "supports_streaming", input_paid_media->supports_streaming) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

input_paid_media_t *input_paid_media_parseFromJSON(cJSON *input_paid_mediaJSON){

    input_paid_media_t *input_paid_media_local_var = NULL;

    // input_paid_media->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(input_paid_mediaJSON, "type");
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

    // input_paid_media->media
    cJSON *media = cJSON_GetObjectItemCaseSensitive(input_paid_mediaJSON, "media");
    if (cJSON_IsNull(media)) {
        media = NULL;
    }
    if (!media) {
        goto end;
    }

    
    if(!cJSON_IsString(media))
    {
    goto end; //String
    }

    // input_paid_media->thumbnail
    cJSON *thumbnail = cJSON_GetObjectItemCaseSensitive(input_paid_mediaJSON, "thumbnail");
    if (cJSON_IsNull(thumbnail)) {
        thumbnail = NULL;
    }
    if (thumbnail) { 
    if(!cJSON_IsString(thumbnail) && !cJSON_IsNull(thumbnail))
    {
    goto end; //String
    }
    }

    // input_paid_media->cover
    cJSON *cover = cJSON_GetObjectItemCaseSensitive(input_paid_mediaJSON, "cover");
    if (cJSON_IsNull(cover)) {
        cover = NULL;
    }
    if (cover) { 
    if(!cJSON_IsString(cover) && !cJSON_IsNull(cover))
    {
    goto end; //String
    }
    }

    // input_paid_media->start_timestamp
    cJSON *start_timestamp = cJSON_GetObjectItemCaseSensitive(input_paid_mediaJSON, "start_timestamp");
    if (cJSON_IsNull(start_timestamp)) {
        start_timestamp = NULL;
    }
    if (start_timestamp) { 
    if(!cJSON_IsNumber(start_timestamp))
    {
    goto end; //Numeric
    }
    }

    // input_paid_media->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(input_paid_mediaJSON, "width");
    if (cJSON_IsNull(width)) {
        width = NULL;
    }
    if (width) { 
    if(!cJSON_IsNumber(width))
    {
    goto end; //Numeric
    }
    }

    // input_paid_media->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(input_paid_mediaJSON, "height");
    if (cJSON_IsNull(height)) {
        height = NULL;
    }
    if (height) { 
    if(!cJSON_IsNumber(height))
    {
    goto end; //Numeric
    }
    }

    // input_paid_media->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(input_paid_mediaJSON, "duration");
    if (cJSON_IsNull(duration)) {
        duration = NULL;
    }
    if (duration) { 
    if(!cJSON_IsNumber(duration))
    {
    goto end; //Numeric
    }
    }

    // input_paid_media->supports_streaming
    cJSON *supports_streaming = cJSON_GetObjectItemCaseSensitive(input_paid_mediaJSON, "supports_streaming");
    if (cJSON_IsNull(supports_streaming)) {
        supports_streaming = NULL;
    }
    if (supports_streaming) { 
    if(!cJSON_IsBool(supports_streaming))
    {
    goto end; //Bool
    }
    }


    input_paid_media_local_var = input_paid_media_create_internal (
        strdup(type->valuestring),
        strdup(media->valuestring),
        thumbnail && !cJSON_IsNull(thumbnail) ? strdup(thumbnail->valuestring) : NULL,
        cover && !cJSON_IsNull(cover) ? strdup(cover->valuestring) : NULL,
        start_timestamp ? start_timestamp->valuedouble : 0,
        width ? width->valuedouble : 0,
        height ? height->valuedouble : 0,
        duration ? duration->valuedouble : 0,
        supports_streaming ? supports_streaming->valueint : 0
        );

    return input_paid_media_local_var;
end:
    return NULL;

}
