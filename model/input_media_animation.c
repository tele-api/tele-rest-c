#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_media_animation.h"



static input_media_animation_t *input_media_animation_create_internal(
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
    int has_spoiler
    ) {
    input_media_animation_t *input_media_animation_local_var = malloc(sizeof(input_media_animation_t));
    if (!input_media_animation_local_var) {
        return NULL;
    }
    input_media_animation_local_var->type = type;
    input_media_animation_local_var->media = media;
    input_media_animation_local_var->thumbnail = thumbnail;
    input_media_animation_local_var->caption = caption;
    input_media_animation_local_var->parse_mode = parse_mode;
    input_media_animation_local_var->caption_entities = caption_entities;
    input_media_animation_local_var->show_caption_above_media = show_caption_above_media;
    input_media_animation_local_var->width = width;
    input_media_animation_local_var->height = height;
    input_media_animation_local_var->duration = duration;
    input_media_animation_local_var->has_spoiler = has_spoiler;

    input_media_animation_local_var->_library_owned = 1;
    return input_media_animation_local_var;
}

__attribute__((deprecated)) input_media_animation_t *input_media_animation_create(
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
    int has_spoiler
    ) {
    return input_media_animation_create_internal (
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
        has_spoiler
        );
}

void input_media_animation_free(input_media_animation_t *input_media_animation) {
    if(NULL == input_media_animation){
        return ;
    }
    if(input_media_animation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_media_animation_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_media_animation->type) {
        free(input_media_animation->type);
        input_media_animation->type = NULL;
    }
    if (input_media_animation->media) {
        free(input_media_animation->media);
        input_media_animation->media = NULL;
    }
    if (input_media_animation->thumbnail) {
        free(input_media_animation->thumbnail);
        input_media_animation->thumbnail = NULL;
    }
    if (input_media_animation->caption) {
        free(input_media_animation->caption);
        input_media_animation->caption = NULL;
    }
    if (input_media_animation->parse_mode) {
        free(input_media_animation->parse_mode);
        input_media_animation->parse_mode = NULL;
    }
    if (input_media_animation->caption_entities) {
        list_ForEach(listEntry, input_media_animation->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(input_media_animation->caption_entities);
        input_media_animation->caption_entities = NULL;
    }
    free(input_media_animation);
}

cJSON *input_media_animation_convertToJSON(input_media_animation_t *input_media_animation) {
    cJSON *item = cJSON_CreateObject();

    // input_media_animation->type
    if (!input_media_animation->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", input_media_animation->type) == NULL) {
    goto fail; //String
    }


    // input_media_animation->media
    if (!input_media_animation->media) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "media", input_media_animation->media) == NULL) {
    goto fail; //String
    }


    // input_media_animation->thumbnail
    if(input_media_animation->thumbnail) {
    if(cJSON_AddStringToObject(item, "thumbnail", input_media_animation->thumbnail) == NULL) {
    goto fail; //String
    }
    }


    // input_media_animation->caption
    if(input_media_animation->caption) {
    if(cJSON_AddStringToObject(item, "caption", input_media_animation->caption) == NULL) {
    goto fail; //String
    }
    }


    // input_media_animation->parse_mode
    if(input_media_animation->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", input_media_animation->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // input_media_animation->caption_entities
    if(input_media_animation->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (input_media_animation->caption_entities) {
    list_ForEach(caption_entitiesListEntry, input_media_animation->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // input_media_animation->show_caption_above_media
    if(input_media_animation->show_caption_above_media) {
    if(cJSON_AddBoolToObject(item, "show_caption_above_media", input_media_animation->show_caption_above_media) == NULL) {
    goto fail; //Bool
    }
    }


    // input_media_animation->width
    if(input_media_animation->width) {
    if(cJSON_AddNumberToObject(item, "width", input_media_animation->width) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_media_animation->height
    if(input_media_animation->height) {
    if(cJSON_AddNumberToObject(item, "height", input_media_animation->height) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_media_animation->duration
    if(input_media_animation->duration) {
    if(cJSON_AddNumberToObject(item, "duration", input_media_animation->duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_media_animation->has_spoiler
    if(input_media_animation->has_spoiler) {
    if(cJSON_AddBoolToObject(item, "has_spoiler", input_media_animation->has_spoiler) == NULL) {
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

input_media_animation_t *input_media_animation_parseFromJSON(cJSON *input_media_animationJSON){

    input_media_animation_t *input_media_animation_local_var = NULL;

    // define the local list for input_media_animation->caption_entities
    list_t *caption_entitiesList = NULL;

    // input_media_animation->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(input_media_animationJSON, "type");
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

    // input_media_animation->media
    cJSON *media = cJSON_GetObjectItemCaseSensitive(input_media_animationJSON, "media");
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

    // input_media_animation->thumbnail
    cJSON *thumbnail = cJSON_GetObjectItemCaseSensitive(input_media_animationJSON, "thumbnail");
    if (cJSON_IsNull(thumbnail)) {
        thumbnail = NULL;
    }
    if (thumbnail) { 
    if(!cJSON_IsString(thumbnail) && !cJSON_IsNull(thumbnail))
    {
    goto end; //String
    }
    }

    // input_media_animation->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(input_media_animationJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // input_media_animation->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(input_media_animationJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // input_media_animation->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(input_media_animationJSON, "caption_entities");
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

    // input_media_animation->show_caption_above_media
    cJSON *show_caption_above_media = cJSON_GetObjectItemCaseSensitive(input_media_animationJSON, "show_caption_above_media");
    if (cJSON_IsNull(show_caption_above_media)) {
        show_caption_above_media = NULL;
    }
    if (show_caption_above_media) { 
    if(!cJSON_IsBool(show_caption_above_media))
    {
    goto end; //Bool
    }
    }

    // input_media_animation->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(input_media_animationJSON, "width");
    if (cJSON_IsNull(width)) {
        width = NULL;
    }
    if (width) { 
    if(!cJSON_IsNumber(width))
    {
    goto end; //Numeric
    }
    }

    // input_media_animation->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(input_media_animationJSON, "height");
    if (cJSON_IsNull(height)) {
        height = NULL;
    }
    if (height) { 
    if(!cJSON_IsNumber(height))
    {
    goto end; //Numeric
    }
    }

    // input_media_animation->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(input_media_animationJSON, "duration");
    if (cJSON_IsNull(duration)) {
        duration = NULL;
    }
    if (duration) { 
    if(!cJSON_IsNumber(duration))
    {
    goto end; //Numeric
    }
    }

    // input_media_animation->has_spoiler
    cJSON *has_spoiler = cJSON_GetObjectItemCaseSensitive(input_media_animationJSON, "has_spoiler");
    if (cJSON_IsNull(has_spoiler)) {
        has_spoiler = NULL;
    }
    if (has_spoiler) { 
    if(!cJSON_IsBool(has_spoiler))
    {
    goto end; //Bool
    }
    }


    input_media_animation_local_var = input_media_animation_create_internal (
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
        has_spoiler ? has_spoiler->valueint : 0
        );

    return input_media_animation_local_var;
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
