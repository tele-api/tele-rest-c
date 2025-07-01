#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_story_content_video.h"



static input_story_content_video_t *input_story_content_video_create_internal(
    char *type,
    char *video,
    double duration,
    double cover_frame_timestamp,
    int is_animation
    ) {
    input_story_content_video_t *input_story_content_video_local_var = malloc(sizeof(input_story_content_video_t));
    if (!input_story_content_video_local_var) {
        return NULL;
    }
    input_story_content_video_local_var->type = type;
    input_story_content_video_local_var->video = video;
    input_story_content_video_local_var->duration = duration;
    input_story_content_video_local_var->cover_frame_timestamp = cover_frame_timestamp;
    input_story_content_video_local_var->is_animation = is_animation;

    input_story_content_video_local_var->_library_owned = 1;
    return input_story_content_video_local_var;
}

__attribute__((deprecated)) input_story_content_video_t *input_story_content_video_create(
    char *type,
    char *video,
    double duration,
    double cover_frame_timestamp,
    int is_animation
    ) {
    return input_story_content_video_create_internal (
        type,
        video,
        duration,
        cover_frame_timestamp,
        is_animation
        );
}

void input_story_content_video_free(input_story_content_video_t *input_story_content_video) {
    if(NULL == input_story_content_video){
        return ;
    }
    if(input_story_content_video->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_story_content_video_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_story_content_video->type) {
        free(input_story_content_video->type);
        input_story_content_video->type = NULL;
    }
    if (input_story_content_video->video) {
        free(input_story_content_video->video);
        input_story_content_video->video = NULL;
    }
    free(input_story_content_video);
}

cJSON *input_story_content_video_convertToJSON(input_story_content_video_t *input_story_content_video) {
    cJSON *item = cJSON_CreateObject();

    // input_story_content_video->type
    if (!input_story_content_video->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", input_story_content_video->type) == NULL) {
    goto fail; //String
    }


    // input_story_content_video->video
    if (!input_story_content_video->video) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "video", input_story_content_video->video) == NULL) {
    goto fail; //String
    }


    // input_story_content_video->duration
    if(input_story_content_video->duration) {
    if(cJSON_AddNumberToObject(item, "duration", input_story_content_video->duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_story_content_video->cover_frame_timestamp
    if(input_story_content_video->cover_frame_timestamp) {
    if(cJSON_AddNumberToObject(item, "cover_frame_timestamp", input_story_content_video->cover_frame_timestamp) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_story_content_video->is_animation
    if(input_story_content_video->is_animation) {
    if(cJSON_AddBoolToObject(item, "is_animation", input_story_content_video->is_animation) == NULL) {
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

input_story_content_video_t *input_story_content_video_parseFromJSON(cJSON *input_story_content_videoJSON){

    input_story_content_video_t *input_story_content_video_local_var = NULL;

    // input_story_content_video->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(input_story_content_videoJSON, "type");
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

    // input_story_content_video->video
    cJSON *video = cJSON_GetObjectItemCaseSensitive(input_story_content_videoJSON, "video");
    if (cJSON_IsNull(video)) {
        video = NULL;
    }
    if (!video) {
        goto end;
    }

    
    if(!cJSON_IsString(video))
    {
    goto end; //String
    }

    // input_story_content_video->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(input_story_content_videoJSON, "duration");
    if (cJSON_IsNull(duration)) {
        duration = NULL;
    }
    if (duration) { 
    if(!cJSON_IsNumber(duration))
    {
    goto end; //Numeric
    }
    }

    // input_story_content_video->cover_frame_timestamp
    cJSON *cover_frame_timestamp = cJSON_GetObjectItemCaseSensitive(input_story_content_videoJSON, "cover_frame_timestamp");
    if (cJSON_IsNull(cover_frame_timestamp)) {
        cover_frame_timestamp = NULL;
    }
    if (cover_frame_timestamp) { 
    if(!cJSON_IsNumber(cover_frame_timestamp))
    {
    goto end; //Numeric
    }
    }

    // input_story_content_video->is_animation
    cJSON *is_animation = cJSON_GetObjectItemCaseSensitive(input_story_content_videoJSON, "is_animation");
    if (cJSON_IsNull(is_animation)) {
        is_animation = NULL;
    }
    if (is_animation) { 
    if(!cJSON_IsBool(is_animation))
    {
    goto end; //Bool
    }
    }


    input_story_content_video_local_var = input_story_content_video_create_internal (
        strdup(type->valuestring),
        strdup(video->valuestring),
        duration ? duration->valuedouble : 0,
        cover_frame_timestamp ? cover_frame_timestamp->valuedouble : 0,
        is_animation ? is_animation->valueint : 0
        );

    return input_story_content_video_local_var;
end:
    return NULL;

}
