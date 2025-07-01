#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_query_result_cached_photo.h"



static inline_query_result_cached_photo_t *inline_query_result_cached_photo_create_internal(
    char *type,
    char *id,
    char *photo_file_id,
    char *title,
    char *description,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
    ) {
    inline_query_result_cached_photo_t *inline_query_result_cached_photo_local_var = malloc(sizeof(inline_query_result_cached_photo_t));
    if (!inline_query_result_cached_photo_local_var) {
        return NULL;
    }
    inline_query_result_cached_photo_local_var->type = type;
    inline_query_result_cached_photo_local_var->id = id;
    inline_query_result_cached_photo_local_var->photo_file_id = photo_file_id;
    inline_query_result_cached_photo_local_var->title = title;
    inline_query_result_cached_photo_local_var->description = description;
    inline_query_result_cached_photo_local_var->caption = caption;
    inline_query_result_cached_photo_local_var->parse_mode = parse_mode;
    inline_query_result_cached_photo_local_var->caption_entities = caption_entities;
    inline_query_result_cached_photo_local_var->show_caption_above_media = show_caption_above_media;
    inline_query_result_cached_photo_local_var->reply_markup = reply_markup;
    inline_query_result_cached_photo_local_var->input_message_content = input_message_content;

    inline_query_result_cached_photo_local_var->_library_owned = 1;
    return inline_query_result_cached_photo_local_var;
}

__attribute__((deprecated)) inline_query_result_cached_photo_t *inline_query_result_cached_photo_create(
    char *type,
    char *id,
    char *photo_file_id,
    char *title,
    char *description,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
    ) {
    return inline_query_result_cached_photo_create_internal (
        type,
        id,
        photo_file_id,
        title,
        description,
        caption,
        parse_mode,
        caption_entities,
        show_caption_above_media,
        reply_markup,
        input_message_content
        );
}

void inline_query_result_cached_photo_free(inline_query_result_cached_photo_t *inline_query_result_cached_photo) {
    if(NULL == inline_query_result_cached_photo){
        return ;
    }
    if(inline_query_result_cached_photo->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inline_query_result_cached_photo_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inline_query_result_cached_photo->type) {
        free(inline_query_result_cached_photo->type);
        inline_query_result_cached_photo->type = NULL;
    }
    if (inline_query_result_cached_photo->id) {
        free(inline_query_result_cached_photo->id);
        inline_query_result_cached_photo->id = NULL;
    }
    if (inline_query_result_cached_photo->photo_file_id) {
        free(inline_query_result_cached_photo->photo_file_id);
        inline_query_result_cached_photo->photo_file_id = NULL;
    }
    if (inline_query_result_cached_photo->title) {
        free(inline_query_result_cached_photo->title);
        inline_query_result_cached_photo->title = NULL;
    }
    if (inline_query_result_cached_photo->description) {
        free(inline_query_result_cached_photo->description);
        inline_query_result_cached_photo->description = NULL;
    }
    if (inline_query_result_cached_photo->caption) {
        free(inline_query_result_cached_photo->caption);
        inline_query_result_cached_photo->caption = NULL;
    }
    if (inline_query_result_cached_photo->parse_mode) {
        free(inline_query_result_cached_photo->parse_mode);
        inline_query_result_cached_photo->parse_mode = NULL;
    }
    if (inline_query_result_cached_photo->caption_entities) {
        list_ForEach(listEntry, inline_query_result_cached_photo->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(inline_query_result_cached_photo->caption_entities);
        inline_query_result_cached_photo->caption_entities = NULL;
    }
    if (inline_query_result_cached_photo->reply_markup) {
        inline_keyboard_markup_free(inline_query_result_cached_photo->reply_markup);
        inline_query_result_cached_photo->reply_markup = NULL;
    }
    if (inline_query_result_cached_photo->input_message_content) {
        input_message_content_free(inline_query_result_cached_photo->input_message_content);
        inline_query_result_cached_photo->input_message_content = NULL;
    }
    free(inline_query_result_cached_photo);
}

cJSON *inline_query_result_cached_photo_convertToJSON(inline_query_result_cached_photo_t *inline_query_result_cached_photo) {
    cJSON *item = cJSON_CreateObject();

    // inline_query_result_cached_photo->type
    if (!inline_query_result_cached_photo->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", inline_query_result_cached_photo->type) == NULL) {
    goto fail; //String
    }


    // inline_query_result_cached_photo->id
    if (!inline_query_result_cached_photo->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", inline_query_result_cached_photo->id) == NULL) {
    goto fail; //String
    }


    // inline_query_result_cached_photo->photo_file_id
    if (!inline_query_result_cached_photo->photo_file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "photo_file_id", inline_query_result_cached_photo->photo_file_id) == NULL) {
    goto fail; //String
    }


    // inline_query_result_cached_photo->title
    if(inline_query_result_cached_photo->title) {
    if(cJSON_AddStringToObject(item, "title", inline_query_result_cached_photo->title) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_cached_photo->description
    if(inline_query_result_cached_photo->description) {
    if(cJSON_AddStringToObject(item, "description", inline_query_result_cached_photo->description) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_cached_photo->caption
    if(inline_query_result_cached_photo->caption) {
    if(cJSON_AddStringToObject(item, "caption", inline_query_result_cached_photo->caption) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_cached_photo->parse_mode
    if(inline_query_result_cached_photo->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", inline_query_result_cached_photo->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_cached_photo->caption_entities
    if(inline_query_result_cached_photo->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (inline_query_result_cached_photo->caption_entities) {
    list_ForEach(caption_entitiesListEntry, inline_query_result_cached_photo->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // inline_query_result_cached_photo->show_caption_above_media
    if(inline_query_result_cached_photo->show_caption_above_media) {
    if(cJSON_AddBoolToObject(item, "show_caption_above_media", inline_query_result_cached_photo->show_caption_above_media) == NULL) {
    goto fail; //Bool
    }
    }


    // inline_query_result_cached_photo->reply_markup
    if(inline_query_result_cached_photo->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(inline_query_result_cached_photo->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_query_result_cached_photo->input_message_content
    if(inline_query_result_cached_photo->input_message_content) {
    cJSON *input_message_content_local_JSON = input_message_content_convertToJSON(inline_query_result_cached_photo->input_message_content);
    if(input_message_content_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "input_message_content", input_message_content_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

inline_query_result_cached_photo_t *inline_query_result_cached_photo_parseFromJSON(cJSON *inline_query_result_cached_photoJSON){

    inline_query_result_cached_photo_t *inline_query_result_cached_photo_local_var = NULL;

    // define the local list for inline_query_result_cached_photo->caption_entities
    list_t *caption_entitiesList = NULL;

    // define the local variable for inline_query_result_cached_photo->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // define the local variable for inline_query_result_cached_photo->input_message_content
    input_message_content_t *input_message_content_local_nonprim = NULL;

    // inline_query_result_cached_photo->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_photoJSON, "type");
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

    // inline_query_result_cached_photo->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_photoJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // inline_query_result_cached_photo->photo_file_id
    cJSON *photo_file_id = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_photoJSON, "photo_file_id");
    if (cJSON_IsNull(photo_file_id)) {
        photo_file_id = NULL;
    }
    if (!photo_file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(photo_file_id))
    {
    goto end; //String
    }

    // inline_query_result_cached_photo->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_photoJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // inline_query_result_cached_photo->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_photoJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // inline_query_result_cached_photo->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_photoJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // inline_query_result_cached_photo->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_photoJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // inline_query_result_cached_photo->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_photoJSON, "caption_entities");
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

    // inline_query_result_cached_photo->show_caption_above_media
    cJSON *show_caption_above_media = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_photoJSON, "show_caption_above_media");
    if (cJSON_IsNull(show_caption_above_media)) {
        show_caption_above_media = NULL;
    }
    if (show_caption_above_media) { 
    if(!cJSON_IsBool(show_caption_above_media))
    {
    goto end; //Bool
    }
    }

    // inline_query_result_cached_photo->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_photoJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }

    // inline_query_result_cached_photo->input_message_content
    cJSON *input_message_content = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_photoJSON, "input_message_content");
    if (cJSON_IsNull(input_message_content)) {
        input_message_content = NULL;
    }
    if (input_message_content) { 
    input_message_content_local_nonprim = input_message_content_parseFromJSON(input_message_content); //nonprimitive
    }


    inline_query_result_cached_photo_local_var = inline_query_result_cached_photo_create_internal (
        strdup(type->valuestring),
        strdup(id->valuestring),
        strdup(photo_file_id->valuestring),
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        show_caption_above_media ? show_caption_above_media->valueint : 0,
        reply_markup ? reply_markup_local_nonprim : NULL,
        input_message_content ? input_message_content_local_nonprim : NULL
        );

    return inline_query_result_cached_photo_local_var;
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
    if (reply_markup_local_nonprim) {
        inline_keyboard_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    if (input_message_content_local_nonprim) {
        input_message_content_free(input_message_content_local_nonprim);
        input_message_content_local_nonprim = NULL;
    }
    return NULL;

}
