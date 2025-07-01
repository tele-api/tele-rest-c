#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_media.h"



static input_media_t *input_media_create_internal(
    char *type,
    char *media,
    char *thumbnail,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    int width,
    int height,
    int duration,
    int has_spoiler,
    int disable_content_type_detection,
    char *performer,
    char *title,
    char *cover,
    int start_timestamp,
    int supports_streaming
    ) {
    input_media_t *input_media_local_var = malloc(sizeof(input_media_t));
    if (!input_media_local_var) {
        return NULL;
    }
    input_media_local_var->type = type;
    input_media_local_var->media = media;
    input_media_local_var->thumbnail = thumbnail;
    input_media_local_var->caption = caption;
    input_media_local_var->parse_mode = parse_mode;
    input_media_local_var->caption_entities = caption_entities;
    input_media_local_var->show_caption_above_media = show_caption_above_media;
    input_media_local_var->width = width;
    input_media_local_var->height = height;
    input_media_local_var->duration = duration;
    input_media_local_var->has_spoiler = has_spoiler;
    input_media_local_var->disable_content_type_detection = disable_content_type_detection;
    input_media_local_var->performer = performer;
    input_media_local_var->title = title;
    input_media_local_var->cover = cover;
    input_media_local_var->start_timestamp = start_timestamp;
    input_media_local_var->supports_streaming = supports_streaming;

    input_media_local_var->_library_owned = 1;
    return input_media_local_var;
}

__attribute__((deprecated)) input_media_t *input_media_create(
    char *type,
    char *media,
    char *thumbnail,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    int width,
    int height,
    int duration,
    int has_spoiler,
    int disable_content_type_detection,
    char *performer,
    char *title,
    char *cover,
    int start_timestamp,
    int supports_streaming
    ) {
    return input_media_create_internal (
        type,
        media,
        thumbnail,
        caption,
        parse_mode,
        caption_entities,
        show_caption_above_media,
        width,
        height,
        duration,
        has_spoiler,
        disable_content_type_detection,
        performer,
        title,
        cover,
        start_timestamp,
        supports_streaming
        );
}

void input_media_free(input_media_t *input_media) {
    if(NULL == input_media){
        return ;
    }
    if(input_media->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_media_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_media->type) {
        free(input_media->type);
        input_media->type = NULL;
    }
    if (input_media->media) {
        free(input_media->media);
        input_media->media = NULL;
    }
    if (input_media->thumbnail) {
        free(input_media->thumbnail);
        input_media->thumbnail = NULL;
    }
    if (input_media->caption) {
        free(input_media->caption);
        input_media->caption = NULL;
    }
    if (input_media->parse_mode) {
        free(input_media->parse_mode);
        input_media->parse_mode = NULL;
    }
    if (input_media->caption_entities) {
        list_ForEach(listEntry, input_media->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(input_media->caption_entities);
        input_media->caption_entities = NULL;
    }
    if (input_media->performer) {
        free(input_media->performer);
        input_media->performer = NULL;
    }
    if (input_media->title) {
        free(input_media->title);
        input_media->title = NULL;
    }
    if (input_media->cover) {
        free(input_media->cover);
        input_media->cover = NULL;
    }
    free(input_media);
}

cJSON *input_media_convertToJSON(input_media_t *input_media) {
    cJSON *item = cJSON_CreateObject();

    // input_media->type
    if (!input_media->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", input_media->type) == NULL) {
    goto fail; //String
    }


    // input_media->media
    if (!input_media->media) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "media", input_media->media) == NULL) {
    goto fail; //String
    }


    // input_media->thumbnail
    if(input_media->thumbnail) {
    if(cJSON_AddStringToObject(item, "thumbnail", input_media->thumbnail) == NULL) {
    goto fail; //String
    }
    }


    // input_media->caption
    if(input_media->caption) {
    if(cJSON_AddStringToObject(item, "caption", input_media->caption) == NULL) {
    goto fail; //String
    }
    }


    // input_media->parse_mode
    if(input_media->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", input_media->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // input_media->caption_entities
    if(input_media->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (input_media->caption_entities) {
    list_ForEach(caption_entitiesListEntry, input_media->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // input_media->show_caption_above_media
    if(input_media->show_caption_above_media) {
    if(cJSON_AddBoolToObject(item, "show_caption_above_media", input_media->show_caption_above_media) == NULL) {
    goto fail; //Bool
    }
    }


    // input_media->width
    if(input_media->width) {
    if(cJSON_AddNumberToObject(item, "width", input_media->width) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_media->height
    if(input_media->height) {
    if(cJSON_AddNumberToObject(item, "height", input_media->height) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_media->duration
    if(input_media->duration) {
    if(cJSON_AddNumberToObject(item, "duration", input_media->duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_media->has_spoiler
    if(input_media->has_spoiler) {
    if(cJSON_AddBoolToObject(item, "has_spoiler", input_media->has_spoiler) == NULL) {
    goto fail; //Bool
    }
    }


    // input_media->disable_content_type_detection
    if(input_media->disable_content_type_detection) {
    if(cJSON_AddBoolToObject(item, "disable_content_type_detection", input_media->disable_content_type_detection) == NULL) {
    goto fail; //Bool
    }
    }


    // input_media->performer
    if(input_media->performer) {
    if(cJSON_AddStringToObject(item, "performer", input_media->performer) == NULL) {
    goto fail; //String
    }
    }


    // input_media->title
    if(input_media->title) {
    if(cJSON_AddStringToObject(item, "title", input_media->title) == NULL) {
    goto fail; //String
    }
    }


    // input_media->cover
    if(input_media->cover) {
    if(cJSON_AddStringToObject(item, "cover", input_media->cover) == NULL) {
    goto fail; //String
    }
    }


    // input_media->start_timestamp
    if(input_media->start_timestamp) {
    if(cJSON_AddNumberToObject(item, "start_timestamp", input_media->start_timestamp) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_media->supports_streaming
    if(input_media->supports_streaming) {
    if(cJSON_AddBoolToObject(item, "supports_streaming", input_media->supports_streaming) == NULL) {
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

input_media_t *input_media_parseFromJSON(cJSON *input_mediaJSON){

    input_media_t *input_media_local_var = NULL;

    // define the local list for input_media->caption_entities
    list_t *caption_entitiesList = NULL;

    // input_media->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(input_mediaJSON, "type");
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

    // input_media->media
    cJSON *media = cJSON_GetObjectItemCaseSensitive(input_mediaJSON, "media");
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

    // input_media->thumbnail
    cJSON *thumbnail = cJSON_GetObjectItemCaseSensitive(input_mediaJSON, "thumbnail");
    if (cJSON_IsNull(thumbnail)) {
        thumbnail = NULL;
    }
    if (thumbnail) { 
    if(!cJSON_IsString(thumbnail) && !cJSON_IsNull(thumbnail))
    {
    goto end; //String
    }
    }

    // input_media->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(input_mediaJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // input_media->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(input_mediaJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // input_media->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(input_mediaJSON, "caption_entities");
    if (cJSON_IsNull(caption_entities)) {
        caption_entities = NULL;
    }
    if (caption_entities) { 
    cJSON *caption_entities_local_nonprimitive = NULL;
    if(!cJSON_IsArray(caption_entities)){
        goto end; //nonprimitive container
    }

    caption_entitiesList = list_createList();

    cJSON_ArrayForEach(caption_entities_local_nonprimitive,caption_entities )
    {
        if(!cJSON_IsObject(caption_entities_local_nonprimitive)){
            goto end;
        }
        message_entity_t *caption_entitiesItem = message_entity_parseFromJSON(caption_entities_local_nonprimitive);

        list_addElement(caption_entitiesList, caption_entitiesItem);
    }
    }

    // input_media->show_caption_above_media
    cJSON *show_caption_above_media = cJSON_GetObjectItemCaseSensitive(input_mediaJSON, "show_caption_above_media");
    if (cJSON_IsNull(show_caption_above_media)) {
        show_caption_above_media = NULL;
    }
    if (show_caption_above_media) { 
    if(!cJSON_IsBool(show_caption_above_media))
    {
    goto end; //Bool
    }
    }

    // input_media->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(input_mediaJSON, "width");
    if (cJSON_IsNull(width)) {
        width = NULL;
    }
    if (width) { 
    if(!cJSON_IsNumber(width))
    {
    goto end; //Numeric
    }
    }

    // input_media->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(input_mediaJSON, "height");
    if (cJSON_IsNull(height)) {
        height = NULL;
    }
    if (height) { 
    if(!cJSON_IsNumber(height))
    {
    goto end; //Numeric
    }
    }

    // input_media->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(input_mediaJSON, "duration");
    if (cJSON_IsNull(duration)) {
        duration = NULL;
    }
    if (duration) { 
    if(!cJSON_IsNumber(duration))
    {
    goto end; //Numeric
    }
    }

    // input_media->has_spoiler
    cJSON *has_spoiler = cJSON_GetObjectItemCaseSensitive(input_mediaJSON, "has_spoiler");
    if (cJSON_IsNull(has_spoiler)) {
        has_spoiler = NULL;
    }
    if (has_spoiler) { 
    if(!cJSON_IsBool(has_spoiler))
    {
    goto end; //Bool
    }
    }

    // input_media->disable_content_type_detection
    cJSON *disable_content_type_detection = cJSON_GetObjectItemCaseSensitive(input_mediaJSON, "disable_content_type_detection");
    if (cJSON_IsNull(disable_content_type_detection)) {
        disable_content_type_detection = NULL;
    }
    if (disable_content_type_detection) { 
    if(!cJSON_IsBool(disable_content_type_detection))
    {
    goto end; //Bool
    }
    }

    // input_media->performer
    cJSON *performer = cJSON_GetObjectItemCaseSensitive(input_mediaJSON, "performer");
    if (cJSON_IsNull(performer)) {
        performer = NULL;
    }
    if (performer) { 
    if(!cJSON_IsString(performer) && !cJSON_IsNull(performer))
    {
    goto end; //String
    }
    }

    // input_media->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(input_mediaJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // input_media->cover
    cJSON *cover = cJSON_GetObjectItemCaseSensitive(input_mediaJSON, "cover");
    if (cJSON_IsNull(cover)) {
        cover = NULL;
    }
    if (cover) { 
    if(!cJSON_IsString(cover) && !cJSON_IsNull(cover))
    {
    goto end; //String
    }
    }

    // input_media->start_timestamp
    cJSON *start_timestamp = cJSON_GetObjectItemCaseSensitive(input_mediaJSON, "start_timestamp");
    if (cJSON_IsNull(start_timestamp)) {
        start_timestamp = NULL;
    }
    if (start_timestamp) { 
    if(!cJSON_IsNumber(start_timestamp))
    {
    goto end; //Numeric
    }
    }

    // input_media->supports_streaming
    cJSON *supports_streaming = cJSON_GetObjectItemCaseSensitive(input_mediaJSON, "supports_streaming");
    if (cJSON_IsNull(supports_streaming)) {
        supports_streaming = NULL;
    }
    if (supports_streaming) { 
    if(!cJSON_IsBool(supports_streaming))
    {
    goto end; //Bool
    }
    }


    input_media_local_var = input_media_create_internal (
        strdup(type->valuestring),
        strdup(media->valuestring),
        thumbnail && !cJSON_IsNull(thumbnail) ? strdup(thumbnail->valuestring) : NULL,
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        show_caption_above_media ? show_caption_above_media->valueint : 0,
        width ? width->valuedouble : 0,
        height ? height->valuedouble : 0,
        duration ? duration->valuedouble : 0,
        has_spoiler ? has_spoiler->valueint : 0,
        disable_content_type_detection ? disable_content_type_detection->valueint : 0,
        performer && !cJSON_IsNull(performer) ? strdup(performer->valuestring) : NULL,
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        cover && !cJSON_IsNull(cover) ? strdup(cover->valuestring) : NULL,
        start_timestamp ? start_timestamp->valuedouble : 0,
        supports_streaming ? supports_streaming->valueint : 0
        );

    return input_media_local_var;
end:
    if (caption_entitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, caption_entitiesList) {
            message_entity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(caption_entitiesList);
        caption_entitiesList = NULL;
    }
    return NULL;

}
