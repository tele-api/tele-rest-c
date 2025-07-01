#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_media_audio.h"



static input_media_audio_t *input_media_audio_create_internal(
    char *type,
    char *media,
    char *thumbnail,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int duration,
    char *performer,
    char *title
    ) {
    input_media_audio_t *input_media_audio_local_var = malloc(sizeof(input_media_audio_t));
    if (!input_media_audio_local_var) {
        return NULL;
    }
    input_media_audio_local_var->type = type;
    input_media_audio_local_var->media = media;
    input_media_audio_local_var->thumbnail = thumbnail;
    input_media_audio_local_var->caption = caption;
    input_media_audio_local_var->parse_mode = parse_mode;
    input_media_audio_local_var->caption_entities = caption_entities;
    input_media_audio_local_var->duration = duration;
    input_media_audio_local_var->performer = performer;
    input_media_audio_local_var->title = title;

    input_media_audio_local_var->_library_owned = 1;
    return input_media_audio_local_var;
}

__attribute__((deprecated)) input_media_audio_t *input_media_audio_create(
    char *type,
    char *media,
    char *thumbnail,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int duration,
    char *performer,
    char *title
    ) {
    return input_media_audio_create_internal (
        type,
        media,
        thumbnail,
        caption,
        parse_mode,
        caption_entities,
        duration,
        performer,
        title
        );
}

void input_media_audio_free(input_media_audio_t *input_media_audio) {
    if(NULL == input_media_audio){
        return ;
    }
    if(input_media_audio->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_media_audio_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_media_audio->type) {
        free(input_media_audio->type);
        input_media_audio->type = NULL;
    }
    if (input_media_audio->media) {
        free(input_media_audio->media);
        input_media_audio->media = NULL;
    }
    if (input_media_audio->thumbnail) {
        free(input_media_audio->thumbnail);
        input_media_audio->thumbnail = NULL;
    }
    if (input_media_audio->caption) {
        free(input_media_audio->caption);
        input_media_audio->caption = NULL;
    }
    if (input_media_audio->parse_mode) {
        free(input_media_audio->parse_mode);
        input_media_audio->parse_mode = NULL;
    }
    if (input_media_audio->caption_entities) {
        list_ForEach(listEntry, input_media_audio->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(input_media_audio->caption_entities);
        input_media_audio->caption_entities = NULL;
    }
    if (input_media_audio->performer) {
        free(input_media_audio->performer);
        input_media_audio->performer = NULL;
    }
    if (input_media_audio->title) {
        free(input_media_audio->title);
        input_media_audio->title = NULL;
    }
    free(input_media_audio);
}

cJSON *input_media_audio_convertToJSON(input_media_audio_t *input_media_audio) {
    cJSON *item = cJSON_CreateObject();

    // input_media_audio->type
    if (!input_media_audio->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", input_media_audio->type) == NULL) {
    goto fail; //String
    }


    // input_media_audio->media
    if (!input_media_audio->media) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "media", input_media_audio->media) == NULL) {
    goto fail; //String
    }


    // input_media_audio->thumbnail
    if(input_media_audio->thumbnail) {
    if(cJSON_AddStringToObject(item, "thumbnail", input_media_audio->thumbnail) == NULL) {
    goto fail; //String
    }
    }


    // input_media_audio->caption
    if(input_media_audio->caption) {
    if(cJSON_AddStringToObject(item, "caption", input_media_audio->caption) == NULL) {
    goto fail; //String
    }
    }


    // input_media_audio->parse_mode
    if(input_media_audio->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", input_media_audio->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // input_media_audio->caption_entities
    if(input_media_audio->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (input_media_audio->caption_entities) {
    list_ForEach(caption_entitiesListEntry, input_media_audio->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // input_media_audio->duration
    if(input_media_audio->duration) {
    if(cJSON_AddNumberToObject(item, "duration", input_media_audio->duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_media_audio->performer
    if(input_media_audio->performer) {
    if(cJSON_AddStringToObject(item, "performer", input_media_audio->performer) == NULL) {
    goto fail; //String
    }
    }


    // input_media_audio->title
    if(input_media_audio->title) {
    if(cJSON_AddStringToObject(item, "title", input_media_audio->title) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

input_media_audio_t *input_media_audio_parseFromJSON(cJSON *input_media_audioJSON){

    input_media_audio_t *input_media_audio_local_var = NULL;

    // define the local list for input_media_audio->caption_entities
    list_t *caption_entitiesList = NULL;

    // input_media_audio->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(input_media_audioJSON, "type");
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

    // input_media_audio->media
    cJSON *media = cJSON_GetObjectItemCaseSensitive(input_media_audioJSON, "media");
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

    // input_media_audio->thumbnail
    cJSON *thumbnail = cJSON_GetObjectItemCaseSensitive(input_media_audioJSON, "thumbnail");
    if (cJSON_IsNull(thumbnail)) {
        thumbnail = NULL;
    }
    if (thumbnail) { 
    if(!cJSON_IsString(thumbnail) && !cJSON_IsNull(thumbnail))
    {
    goto end; //String
    }
    }

    // input_media_audio->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(input_media_audioJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // input_media_audio->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(input_media_audioJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // input_media_audio->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(input_media_audioJSON, "caption_entities");
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

    // input_media_audio->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(input_media_audioJSON, "duration");
    if (cJSON_IsNull(duration)) {
        duration = NULL;
    }
    if (duration) { 
    if(!cJSON_IsNumber(duration))
    {
    goto end; //Numeric
    }
    }

    // input_media_audio->performer
    cJSON *performer = cJSON_GetObjectItemCaseSensitive(input_media_audioJSON, "performer");
    if (cJSON_IsNull(performer)) {
        performer = NULL;
    }
    if (performer) { 
    if(!cJSON_IsString(performer) && !cJSON_IsNull(performer))
    {
    goto end; //String
    }
    }

    // input_media_audio->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(input_media_audioJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }


    input_media_audio_local_var = input_media_audio_create_internal (
        strdup(type->valuestring),
        strdup(media->valuestring),
        thumbnail && !cJSON_IsNull(thumbnail) ? strdup(thumbnail->valuestring) : NULL,
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        duration ? duration->valuedouble : 0,
        performer && !cJSON_IsNull(performer) ? strdup(performer->valuestring) : NULL,
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL
        );

    return input_media_audio_local_var;
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
