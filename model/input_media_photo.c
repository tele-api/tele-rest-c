#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_media_photo.h"



static input_media_photo_t *input_media_photo_create_internal(
    char *type,
    char *media,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    int has_spoiler
    ) {
    input_media_photo_t *input_media_photo_local_var = malloc(sizeof(input_media_photo_t));
    if (!input_media_photo_local_var) {
        return NULL;
    }
    input_media_photo_local_var->type = type;
    input_media_photo_local_var->media = media;
    input_media_photo_local_var->caption = caption;
    input_media_photo_local_var->parse_mode = parse_mode;
    input_media_photo_local_var->caption_entities = caption_entities;
    input_media_photo_local_var->show_caption_above_media = show_caption_above_media;
    input_media_photo_local_var->has_spoiler = has_spoiler;

    input_media_photo_local_var->_library_owned = 1;
    return input_media_photo_local_var;
}

__attribute__((deprecated)) input_media_photo_t *input_media_photo_create(
    char *type,
    char *media,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    int has_spoiler
    ) {
    return input_media_photo_create_internal (
        type,
        media,
        caption,
        parse_mode,
        caption_entities,
        show_caption_above_media,
        has_spoiler
        );
}

void input_media_photo_free(input_media_photo_t *input_media_photo) {
    if(NULL == input_media_photo){
        return ;
    }
    if(input_media_photo->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_media_photo_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_media_photo->type) {
        free(input_media_photo->type);
        input_media_photo->type = NULL;
    }
    if (input_media_photo->media) {
        free(input_media_photo->media);
        input_media_photo->media = NULL;
    }
    if (input_media_photo->caption) {
        free(input_media_photo->caption);
        input_media_photo->caption = NULL;
    }
    if (input_media_photo->parse_mode) {
        free(input_media_photo->parse_mode);
        input_media_photo->parse_mode = NULL;
    }
    if (input_media_photo->caption_entities) {
        list_ForEach(listEntry, input_media_photo->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(input_media_photo->caption_entities);
        input_media_photo->caption_entities = NULL;
    }
    free(input_media_photo);
}

cJSON *input_media_photo_convertToJSON(input_media_photo_t *input_media_photo) {
    cJSON *item = cJSON_CreateObject();

    // input_media_photo->type
    if (!input_media_photo->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", input_media_photo->type) == NULL) {
    goto fail; //String
    }


    // input_media_photo->media
    if (!input_media_photo->media) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "media", input_media_photo->media) == NULL) {
    goto fail; //String
    }


    // input_media_photo->caption
    if(input_media_photo->caption) {
    if(cJSON_AddStringToObject(item, "caption", input_media_photo->caption) == NULL) {
    goto fail; //String
    }
    }


    // input_media_photo->parse_mode
    if(input_media_photo->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", input_media_photo->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // input_media_photo->caption_entities
    if(input_media_photo->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (input_media_photo->caption_entities) {
    list_ForEach(caption_entitiesListEntry, input_media_photo->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // input_media_photo->show_caption_above_media
    if(input_media_photo->show_caption_above_media) {
    if(cJSON_AddBoolToObject(item, "show_caption_above_media", input_media_photo->show_caption_above_media) == NULL) {
    goto fail; //Bool
    }
    }


    // input_media_photo->has_spoiler
    if(input_media_photo->has_spoiler) {
    if(cJSON_AddBoolToObject(item, "has_spoiler", input_media_photo->has_spoiler) == NULL) {
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

input_media_photo_t *input_media_photo_parseFromJSON(cJSON *input_media_photoJSON){

    input_media_photo_t *input_media_photo_local_var = NULL;

    // define the local list for input_media_photo->caption_entities
    list_t *caption_entitiesList = NULL;

    // input_media_photo->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(input_media_photoJSON, "type");
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

    // input_media_photo->media
    cJSON *media = cJSON_GetObjectItemCaseSensitive(input_media_photoJSON, "media");
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

    // input_media_photo->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(input_media_photoJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // input_media_photo->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(input_media_photoJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // input_media_photo->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(input_media_photoJSON, "caption_entities");
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

    // input_media_photo->show_caption_above_media
    cJSON *show_caption_above_media = cJSON_GetObjectItemCaseSensitive(input_media_photoJSON, "show_caption_above_media");
    if (cJSON_IsNull(show_caption_above_media)) {
        show_caption_above_media = NULL;
    }
    if (show_caption_above_media) { 
    if(!cJSON_IsBool(show_caption_above_media))
    {
    goto end; //Bool
    }
    }

    // input_media_photo->has_spoiler
    cJSON *has_spoiler = cJSON_GetObjectItemCaseSensitive(input_media_photoJSON, "has_spoiler");
    if (cJSON_IsNull(has_spoiler)) {
        has_spoiler = NULL;
    }
    if (has_spoiler) { 
    if(!cJSON_IsBool(has_spoiler))
    {
    goto end; //Bool
    }
    }


    input_media_photo_local_var = input_media_photo_create_internal (
        strdup(type->valuestring),
        strdup(media->valuestring),
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        show_caption_above_media ? show_caption_above_media->valueint : 0,
        has_spoiler ? has_spoiler->valueint : 0
        );

    return input_media_photo_local_var;
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
