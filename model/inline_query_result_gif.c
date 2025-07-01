#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_query_result_gif.h"


char* inline_query_result_gif_thumbnail_mime_type_ToString(telegram_bot_api_inline_query_result_gif_THUMBNAILMIMETYPE_e thumbnail_mime_type) {
    char* thumbnail_mime_typeArray[] =  { "NULL", "image/jpeg", "image/gif", "video/mp4" };
    return thumbnail_mime_typeArray[thumbnail_mime_type];
}

telegram_bot_api_inline_query_result_gif_THUMBNAILMIMETYPE_e inline_query_result_gif_thumbnail_mime_type_FromString(char* thumbnail_mime_type){
    int stringToReturn = 0;
    char *thumbnail_mime_typeArray[] =  { "NULL", "image/jpeg", "image/gif", "video/mp4" };
    size_t sizeofArray = sizeof(thumbnail_mime_typeArray) / sizeof(thumbnail_mime_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(thumbnail_mime_type, thumbnail_mime_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static inline_query_result_gif_t *inline_query_result_gif_create_internal(
    char *type,
    char *id,
    char *gif_url,
    char *thumbnail_url,
    int gif_width,
    int gif_height,
    int gif_duration,
    telegram_bot_api_inline_query_result_gif_THUMBNAILMIMETYPE_e thumbnail_mime_type,
    char *title,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
    ) {
    inline_query_result_gif_t *inline_query_result_gif_local_var = malloc(sizeof(inline_query_result_gif_t));
    if (!inline_query_result_gif_local_var) {
        return NULL;
    }
    inline_query_result_gif_local_var->type = type;
    inline_query_result_gif_local_var->id = id;
    inline_query_result_gif_local_var->gif_url = gif_url;
    inline_query_result_gif_local_var->thumbnail_url = thumbnail_url;
    inline_query_result_gif_local_var->gif_width = gif_width;
    inline_query_result_gif_local_var->gif_height = gif_height;
    inline_query_result_gif_local_var->gif_duration = gif_duration;
    inline_query_result_gif_local_var->thumbnail_mime_type = thumbnail_mime_type;
    inline_query_result_gif_local_var->title = title;
    inline_query_result_gif_local_var->caption = caption;
    inline_query_result_gif_local_var->parse_mode = parse_mode;
    inline_query_result_gif_local_var->caption_entities = caption_entities;
    inline_query_result_gif_local_var->show_caption_above_media = show_caption_above_media;
    inline_query_result_gif_local_var->reply_markup = reply_markup;
    inline_query_result_gif_local_var->input_message_content = input_message_content;

    inline_query_result_gif_local_var->_library_owned = 1;
    return inline_query_result_gif_local_var;
}

__attribute__((deprecated)) inline_query_result_gif_t *inline_query_result_gif_create(
    char *type,
    char *id,
    char *gif_url,
    char *thumbnail_url,
    int gif_width,
    int gif_height,
    int gif_duration,
    telegram_bot_api_inline_query_result_gif_THUMBNAILMIMETYPE_e thumbnail_mime_type,
    char *title,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
    ) {
    return inline_query_result_gif_create_internal (
        type,
        id,
        gif_url,
        thumbnail_url,
        gif_width,
        gif_height,
        gif_duration,
        thumbnail_mime_type,
        title,
        caption,
        parse_mode,
        caption_entities,
        show_caption_above_media,
        reply_markup,
        input_message_content
        );
}

void inline_query_result_gif_free(inline_query_result_gif_t *inline_query_result_gif) {
    if(NULL == inline_query_result_gif){
        return ;
    }
    if(inline_query_result_gif->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inline_query_result_gif_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inline_query_result_gif->type) {
        free(inline_query_result_gif->type);
        inline_query_result_gif->type = NULL;
    }
    if (inline_query_result_gif->id) {
        free(inline_query_result_gif->id);
        inline_query_result_gif->id = NULL;
    }
    if (inline_query_result_gif->gif_url) {
        free(inline_query_result_gif->gif_url);
        inline_query_result_gif->gif_url = NULL;
    }
    if (inline_query_result_gif->thumbnail_url) {
        free(inline_query_result_gif->thumbnail_url);
        inline_query_result_gif->thumbnail_url = NULL;
    }
    if (inline_query_result_gif->title) {
        free(inline_query_result_gif->title);
        inline_query_result_gif->title = NULL;
    }
    if (inline_query_result_gif->caption) {
        free(inline_query_result_gif->caption);
        inline_query_result_gif->caption = NULL;
    }
    if (inline_query_result_gif->parse_mode) {
        free(inline_query_result_gif->parse_mode);
        inline_query_result_gif->parse_mode = NULL;
    }
    if (inline_query_result_gif->caption_entities) {
        list_ForEach(listEntry, inline_query_result_gif->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(inline_query_result_gif->caption_entities);
        inline_query_result_gif->caption_entities = NULL;
    }
    if (inline_query_result_gif->reply_markup) {
        inline_keyboard_markup_free(inline_query_result_gif->reply_markup);
        inline_query_result_gif->reply_markup = NULL;
    }
    if (inline_query_result_gif->input_message_content) {
        input_message_content_free(inline_query_result_gif->input_message_content);
        inline_query_result_gif->input_message_content = NULL;
    }
    free(inline_query_result_gif);
}

cJSON *inline_query_result_gif_convertToJSON(inline_query_result_gif_t *inline_query_result_gif) {
    cJSON *item = cJSON_CreateObject();

    // inline_query_result_gif->type
    if (!inline_query_result_gif->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", inline_query_result_gif->type) == NULL) {
    goto fail; //String
    }


    // inline_query_result_gif->id
    if (!inline_query_result_gif->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", inline_query_result_gif->id) == NULL) {
    goto fail; //String
    }


    // inline_query_result_gif->gif_url
    if (!inline_query_result_gif->gif_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gif_url", inline_query_result_gif->gif_url) == NULL) {
    goto fail; //String
    }


    // inline_query_result_gif->thumbnail_url
    if (!inline_query_result_gif->thumbnail_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "thumbnail_url", inline_query_result_gif->thumbnail_url) == NULL) {
    goto fail; //String
    }


    // inline_query_result_gif->gif_width
    if(inline_query_result_gif->gif_width) {
    if(cJSON_AddNumberToObject(item, "gif_width", inline_query_result_gif->gif_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result_gif->gif_height
    if(inline_query_result_gif->gif_height) {
    if(cJSON_AddNumberToObject(item, "gif_height", inline_query_result_gif->gif_height) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result_gif->gif_duration
    if(inline_query_result_gif->gif_duration) {
    if(cJSON_AddNumberToObject(item, "gif_duration", inline_query_result_gif->gif_duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result_gif->thumbnail_mime_type
    if(inline_query_result_gif->thumbnail_mime_type != telegram_bot_api_inline_query_result_gif_THUMBNAILMIMETYPE_NULL) {
    if(cJSON_AddStringToObject(item, "thumbnail_mime_type", inline_query_result_gif_thumbnail_mime_type_ToString(inline_query_result_gif->thumbnail_mime_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // inline_query_result_gif->title
    if(inline_query_result_gif->title) {
    if(cJSON_AddStringToObject(item, "title", inline_query_result_gif->title) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_gif->caption
    if(inline_query_result_gif->caption) {
    if(cJSON_AddStringToObject(item, "caption", inline_query_result_gif->caption) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_gif->parse_mode
    if(inline_query_result_gif->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", inline_query_result_gif->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_gif->caption_entities
    if(inline_query_result_gif->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (inline_query_result_gif->caption_entities) {
    list_ForEach(caption_entitiesListEntry, inline_query_result_gif->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // inline_query_result_gif->show_caption_above_media
    if(inline_query_result_gif->show_caption_above_media) {
    if(cJSON_AddBoolToObject(item, "show_caption_above_media", inline_query_result_gif->show_caption_above_media) == NULL) {
    goto fail; //Bool
    }
    }


    // inline_query_result_gif->reply_markup
    if(inline_query_result_gif->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(inline_query_result_gif->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_query_result_gif->input_message_content
    if(inline_query_result_gif->input_message_content) {
    cJSON *input_message_content_local_JSON = input_message_content_convertToJSON(inline_query_result_gif->input_message_content);
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

inline_query_result_gif_t *inline_query_result_gif_parseFromJSON(cJSON *inline_query_result_gifJSON){

    inline_query_result_gif_t *inline_query_result_gif_local_var = NULL;

    // define the local list for inline_query_result_gif->caption_entities
    list_t *caption_entitiesList = NULL;

    // define the local variable for inline_query_result_gif->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // define the local variable for inline_query_result_gif->input_message_content
    input_message_content_t *input_message_content_local_nonprim = NULL;

    // inline_query_result_gif->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(inline_query_result_gifJSON, "type");
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

    // inline_query_result_gif->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(inline_query_result_gifJSON, "id");
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

    // inline_query_result_gif->gif_url
    cJSON *gif_url = cJSON_GetObjectItemCaseSensitive(inline_query_result_gifJSON, "gif_url");
    if (cJSON_IsNull(gif_url)) {
        gif_url = NULL;
    }
    if (!gif_url) {
        goto end;
    }

    
    if(!cJSON_IsString(gif_url))
    {
    goto end; //String
    }

    // inline_query_result_gif->thumbnail_url
    cJSON *thumbnail_url = cJSON_GetObjectItemCaseSensitive(inline_query_result_gifJSON, "thumbnail_url");
    if (cJSON_IsNull(thumbnail_url)) {
        thumbnail_url = NULL;
    }
    if (!thumbnail_url) {
        goto end;
    }

    
    if(!cJSON_IsString(thumbnail_url))
    {
    goto end; //String
    }

    // inline_query_result_gif->gif_width
    cJSON *gif_width = cJSON_GetObjectItemCaseSensitive(inline_query_result_gifJSON, "gif_width");
    if (cJSON_IsNull(gif_width)) {
        gif_width = NULL;
    }
    if (gif_width) { 
    if(!cJSON_IsNumber(gif_width))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result_gif->gif_height
    cJSON *gif_height = cJSON_GetObjectItemCaseSensitive(inline_query_result_gifJSON, "gif_height");
    if (cJSON_IsNull(gif_height)) {
        gif_height = NULL;
    }
    if (gif_height) { 
    if(!cJSON_IsNumber(gif_height))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result_gif->gif_duration
    cJSON *gif_duration = cJSON_GetObjectItemCaseSensitive(inline_query_result_gifJSON, "gif_duration");
    if (cJSON_IsNull(gif_duration)) {
        gif_duration = NULL;
    }
    if (gif_duration) { 
    if(!cJSON_IsNumber(gif_duration))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result_gif->thumbnail_mime_type
    cJSON *thumbnail_mime_type = cJSON_GetObjectItemCaseSensitive(inline_query_result_gifJSON, "thumbnail_mime_type");
    if (cJSON_IsNull(thumbnail_mime_type)) {
        thumbnail_mime_type = NULL;
    }
    telegram_bot_api_inline_query_result_gif_THUMBNAILMIMETYPE_e thumbnail_mime_typeVariable;
    if (thumbnail_mime_type) { 
    if(!cJSON_IsString(thumbnail_mime_type))
    {
    goto end; //Enum
    }
    thumbnail_mime_typeVariable = inline_query_result_gif_thumbnail_mime_type_FromString(thumbnail_mime_type->valuestring);
    }

    // inline_query_result_gif->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(inline_query_result_gifJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // inline_query_result_gif->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(inline_query_result_gifJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // inline_query_result_gif->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(inline_query_result_gifJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // inline_query_result_gif->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(inline_query_result_gifJSON, "caption_entities");
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

    // inline_query_result_gif->show_caption_above_media
    cJSON *show_caption_above_media = cJSON_GetObjectItemCaseSensitive(inline_query_result_gifJSON, "show_caption_above_media");
    if (cJSON_IsNull(show_caption_above_media)) {
        show_caption_above_media = NULL;
    }
    if (show_caption_above_media) { 
    if(!cJSON_IsBool(show_caption_above_media))
    {
    goto end; //Bool
    }
    }

    // inline_query_result_gif->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(inline_query_result_gifJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }

    // inline_query_result_gif->input_message_content
    cJSON *input_message_content = cJSON_GetObjectItemCaseSensitive(inline_query_result_gifJSON, "input_message_content");
    if (cJSON_IsNull(input_message_content)) {
        input_message_content = NULL;
    }
    if (input_message_content) { 
    input_message_content_local_nonprim = input_message_content_parseFromJSON(input_message_content); //nonprimitive
    }


    inline_query_result_gif_local_var = inline_query_result_gif_create_internal (
        strdup(type->valuestring),
        strdup(id->valuestring),
        strdup(gif_url->valuestring),
        strdup(thumbnail_url->valuestring),
        gif_width ? gif_width->valuedouble : 0,
        gif_height ? gif_height->valuedouble : 0,
        gif_duration ? gif_duration->valuedouble : 0,
        thumbnail_mime_type ? thumbnail_mime_typeVariable : telegram_bot_api_inline_query_result_gif_THUMBNAILMIMETYPE_NULL,
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        show_caption_above_media ? show_caption_above_media->valueint : 0,
        reply_markup ? reply_markup_local_nonprim : NULL,
        input_message_content ? input_message_content_local_nonprim : NULL
        );

    return inline_query_result_gif_local_var;
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
