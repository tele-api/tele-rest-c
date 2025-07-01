#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_media_document.h"



static input_media_document_t *input_media_document_create_internal(
    char *type,
    char *media,
    char *thumbnail,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int disable_content_type_detection
    ) {
    input_media_document_t *input_media_document_local_var = malloc(sizeof(input_media_document_t));
    if (!input_media_document_local_var) {
        return NULL;
    }
    input_media_document_local_var->type = type;
    input_media_document_local_var->media = media;
    input_media_document_local_var->thumbnail = thumbnail;
    input_media_document_local_var->caption = caption;
    input_media_document_local_var->parse_mode = parse_mode;
    input_media_document_local_var->caption_entities = caption_entities;
    input_media_document_local_var->disable_content_type_detection = disable_content_type_detection;

    input_media_document_local_var->_library_owned = 1;
    return input_media_document_local_var;
}

__attribute__((deprecated)) input_media_document_t *input_media_document_create(
    char *type,
    char *media,
    char *thumbnail,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int disable_content_type_detection
    ) {
    return input_media_document_create_internal (
        type,
        media,
        thumbnail,
        caption,
        parse_mode,
        caption_entities,
        disable_content_type_detection
        );
}

void input_media_document_free(input_media_document_t *input_media_document) {
    if(NULL == input_media_document){
        return ;
    }
    if(input_media_document->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_media_document_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_media_document->type) {
        free(input_media_document->type);
        input_media_document->type = NULL;
    }
    if (input_media_document->media) {
        free(input_media_document->media);
        input_media_document->media = NULL;
    }
    if (input_media_document->thumbnail) {
        free(input_media_document->thumbnail);
        input_media_document->thumbnail = NULL;
    }
    if (input_media_document->caption) {
        free(input_media_document->caption);
        input_media_document->caption = NULL;
    }
    if (input_media_document->parse_mode) {
        free(input_media_document->parse_mode);
        input_media_document->parse_mode = NULL;
    }
    if (input_media_document->caption_entities) {
        list_ForEach(listEntry, input_media_document->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(input_media_document->caption_entities);
        input_media_document->caption_entities = NULL;
    }
    free(input_media_document);
}

cJSON *input_media_document_convertToJSON(input_media_document_t *input_media_document) {
    cJSON *item = cJSON_CreateObject();

    // input_media_document->type
    if (!input_media_document->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", input_media_document->type) == NULL) {
    goto fail; //String
    }


    // input_media_document->media
    if (!input_media_document->media) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "media", input_media_document->media) == NULL) {
    goto fail; //String
    }


    // input_media_document->thumbnail
    if(input_media_document->thumbnail) {
    if(cJSON_AddStringToObject(item, "thumbnail", input_media_document->thumbnail) == NULL) {
    goto fail; //String
    }
    }


    // input_media_document->caption
    if(input_media_document->caption) {
    if(cJSON_AddStringToObject(item, "caption", input_media_document->caption) == NULL) {
    goto fail; //String
    }
    }


    // input_media_document->parse_mode
    if(input_media_document->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", input_media_document->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // input_media_document->caption_entities
    if(input_media_document->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (input_media_document->caption_entities) {
    list_ForEach(caption_entitiesListEntry, input_media_document->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // input_media_document->disable_content_type_detection
    if(input_media_document->disable_content_type_detection) {
    if(cJSON_AddBoolToObject(item, "disable_content_type_detection", input_media_document->disable_content_type_detection) == NULL) {
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

input_media_document_t *input_media_document_parseFromJSON(cJSON *input_media_documentJSON){

    input_media_document_t *input_media_document_local_var = NULL;

    // define the local list for input_media_document->caption_entities
    list_t *caption_entitiesList = NULL;

    // input_media_document->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(input_media_documentJSON, "type");
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

    // input_media_document->media
    cJSON *media = cJSON_GetObjectItemCaseSensitive(input_media_documentJSON, "media");
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

    // input_media_document->thumbnail
    cJSON *thumbnail = cJSON_GetObjectItemCaseSensitive(input_media_documentJSON, "thumbnail");
    if (cJSON_IsNull(thumbnail)) {
        thumbnail = NULL;
    }
    if (thumbnail) { 
    if(!cJSON_IsString(thumbnail) && !cJSON_IsNull(thumbnail))
    {
    goto end; //String
    }
    }

    // input_media_document->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(input_media_documentJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // input_media_document->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(input_media_documentJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // input_media_document->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(input_media_documentJSON, "caption_entities");
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

    // input_media_document->disable_content_type_detection
    cJSON *disable_content_type_detection = cJSON_GetObjectItemCaseSensitive(input_media_documentJSON, "disable_content_type_detection");
    if (cJSON_IsNull(disable_content_type_detection)) {
        disable_content_type_detection = NULL;
    }
    if (disable_content_type_detection) { 
    if(!cJSON_IsBool(disable_content_type_detection))
    {
    goto end; //Bool
    }
    }


    input_media_document_local_var = input_media_document_create_internal (
        strdup(type->valuestring),
        strdup(media->valuestring),
        thumbnail && !cJSON_IsNull(thumbnail) ? strdup(thumbnail->valuestring) : NULL,
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        disable_content_type_detection ? disable_content_type_detection->valueint : 0
        );

    return input_media_document_local_var;
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
