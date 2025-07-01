#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_query_result_cached_video.h"



static inline_query_result_cached_video_t *inline_query_result_cached_video_create_internal(
    char *type,
    char *id,
    char *video_file_id,
    char *title,
    char *description,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
    ) {
    inline_query_result_cached_video_t *inline_query_result_cached_video_local_var = malloc(sizeof(inline_query_result_cached_video_t));
    if (!inline_query_result_cached_video_local_var) {
        return NULL;
    }
    inline_query_result_cached_video_local_var->type = type;
    inline_query_result_cached_video_local_var->id = id;
    inline_query_result_cached_video_local_var->video_file_id = video_file_id;
    inline_query_result_cached_video_local_var->title = title;
    inline_query_result_cached_video_local_var->description = description;
    inline_query_result_cached_video_local_var->caption = caption;
    inline_query_result_cached_video_local_var->parse_mode = parse_mode;
    inline_query_result_cached_video_local_var->caption_entities = caption_entities;
    inline_query_result_cached_video_local_var->show_caption_above_media = show_caption_above_media;
    inline_query_result_cached_video_local_var->reply_markup = reply_markup;
    inline_query_result_cached_video_local_var->input_message_content = input_message_content;

    inline_query_result_cached_video_local_var->_library_owned = 1;
    return inline_query_result_cached_video_local_var;
}

__attribute__((deprecated)) inline_query_result_cached_video_t *inline_query_result_cached_video_create(
    char *type,
    char *id,
    char *video_file_id,
    char *title,
    char *description,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
    ) {
    return inline_query_result_cached_video_create_internal (
        type,
        id,
        video_file_id,
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

void inline_query_result_cached_video_free(inline_query_result_cached_video_t *inline_query_result_cached_video) {
    if(NULL == inline_query_result_cached_video){
        return ;
    }
    if(inline_query_result_cached_video->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inline_query_result_cached_video_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inline_query_result_cached_video->type) {
        free(inline_query_result_cached_video->type);
        inline_query_result_cached_video->type = NULL;
    }
    if (inline_query_result_cached_video->id) {
        free(inline_query_result_cached_video->id);
        inline_query_result_cached_video->id = NULL;
    }
    if (inline_query_result_cached_video->video_file_id) {
        free(inline_query_result_cached_video->video_file_id);
        inline_query_result_cached_video->video_file_id = NULL;
    }
    if (inline_query_result_cached_video->title) {
        free(inline_query_result_cached_video->title);
        inline_query_result_cached_video->title = NULL;
    }
    if (inline_query_result_cached_video->description) {
        free(inline_query_result_cached_video->description);
        inline_query_result_cached_video->description = NULL;
    }
    if (inline_query_result_cached_video->caption) {
        free(inline_query_result_cached_video->caption);
        inline_query_result_cached_video->caption = NULL;
    }
    if (inline_query_result_cached_video->parse_mode) {
        free(inline_query_result_cached_video->parse_mode);
        inline_query_result_cached_video->parse_mode = NULL;
    }
    if (inline_query_result_cached_video->caption_entities) {
        list_ForEach(listEntry, inline_query_result_cached_video->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(inline_query_result_cached_video->caption_entities);
        inline_query_result_cached_video->caption_entities = NULL;
    }
    if (inline_query_result_cached_video->reply_markup) {
        inline_keyboard_markup_free(inline_query_result_cached_video->reply_markup);
        inline_query_result_cached_video->reply_markup = NULL;
    }
    if (inline_query_result_cached_video->input_message_content) {
        input_message_content_free(inline_query_result_cached_video->input_message_content);
        inline_query_result_cached_video->input_message_content = NULL;
    }
    free(inline_query_result_cached_video);
}

cJSON *inline_query_result_cached_video_convertToJSON(inline_query_result_cached_video_t *inline_query_result_cached_video) {
    cJSON *item = cJSON_CreateObject();

    // inline_query_result_cached_video->type
    if (!inline_query_result_cached_video->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", inline_query_result_cached_video->type) == NULL) {
    goto fail; //String
    }


    // inline_query_result_cached_video->id
    if (!inline_query_result_cached_video->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", inline_query_result_cached_video->id) == NULL) {
    goto fail; //String
    }


    // inline_query_result_cached_video->video_file_id
    if (!inline_query_result_cached_video->video_file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "video_file_id", inline_query_result_cached_video->video_file_id) == NULL) {
    goto fail; //String
    }


    // inline_query_result_cached_video->title
    if (!inline_query_result_cached_video->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", inline_query_result_cached_video->title) == NULL) {
    goto fail; //String
    }


    // inline_query_result_cached_video->description
    if(inline_query_result_cached_video->description) {
    if(cJSON_AddStringToObject(item, "description", inline_query_result_cached_video->description) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_cached_video->caption
    if(inline_query_result_cached_video->caption) {
    if(cJSON_AddStringToObject(item, "caption", inline_query_result_cached_video->caption) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_cached_video->parse_mode
    if(inline_query_result_cached_video->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", inline_query_result_cached_video->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_cached_video->caption_entities
    if(inline_query_result_cached_video->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (inline_query_result_cached_video->caption_entities) {
    list_ForEach(caption_entitiesListEntry, inline_query_result_cached_video->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // inline_query_result_cached_video->show_caption_above_media
    if(inline_query_result_cached_video->show_caption_above_media) {
    if(cJSON_AddBoolToObject(item, "show_caption_above_media", inline_query_result_cached_video->show_caption_above_media) == NULL) {
    goto fail; //Bool
    }
    }


    // inline_query_result_cached_video->reply_markup
    if(inline_query_result_cached_video->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(inline_query_result_cached_video->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_query_result_cached_video->input_message_content
    if(inline_query_result_cached_video->input_message_content) {
    cJSON *input_message_content_local_JSON = input_message_content_convertToJSON(inline_query_result_cached_video->input_message_content);
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

inline_query_result_cached_video_t *inline_query_result_cached_video_parseFromJSON(cJSON *inline_query_result_cached_videoJSON){

    inline_query_result_cached_video_t *inline_query_result_cached_video_local_var = NULL;

    // define the local list for inline_query_result_cached_video->caption_entities
    list_t *caption_entitiesList = NULL;

    // define the local variable for inline_query_result_cached_video->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // define the local variable for inline_query_result_cached_video->input_message_content
    input_message_content_t *input_message_content_local_nonprim = NULL;

    // inline_query_result_cached_video->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_videoJSON, "type");
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

    // inline_query_result_cached_video->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_videoJSON, "id");
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

    // inline_query_result_cached_video->video_file_id
    cJSON *video_file_id = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_videoJSON, "video_file_id");
    if (cJSON_IsNull(video_file_id)) {
        video_file_id = NULL;
    }
    if (!video_file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(video_file_id))
    {
    goto end; //String
    }

    // inline_query_result_cached_video->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_videoJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }

    // inline_query_result_cached_video->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_videoJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // inline_query_result_cached_video->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_videoJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // inline_query_result_cached_video->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_videoJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // inline_query_result_cached_video->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_videoJSON, "caption_entities");
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

    // inline_query_result_cached_video->show_caption_above_media
    cJSON *show_caption_above_media = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_videoJSON, "show_caption_above_media");
    if (cJSON_IsNull(show_caption_above_media)) {
        show_caption_above_media = NULL;
    }
    if (show_caption_above_media) { 
    if(!cJSON_IsBool(show_caption_above_media))
    {
    goto end; //Bool
    }
    }

    // inline_query_result_cached_video->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_videoJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }

    // inline_query_result_cached_video->input_message_content
    cJSON *input_message_content = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_videoJSON, "input_message_content");
    if (cJSON_IsNull(input_message_content)) {
        input_message_content = NULL;
    }
    if (input_message_content) { 
    input_message_content_local_nonprim = input_message_content_parseFromJSON(input_message_content); //nonprimitive
    }


    inline_query_result_cached_video_local_var = inline_query_result_cached_video_create_internal (
        strdup(type->valuestring),
        strdup(id->valuestring),
        strdup(video_file_id->valuestring),
        strdup(title->valuestring),
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        show_caption_above_media ? show_caption_above_media->valueint : 0,
        reply_markup ? reply_markup_local_nonprim : NULL,
        input_message_content ? input_message_content_local_nonprim : NULL
        );

    return inline_query_result_cached_video_local_var;
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
