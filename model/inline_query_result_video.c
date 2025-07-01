#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_query_result_video.h"


char* inline_query_result_video_mime_type_ToString(telegram_bot_api_inline_query_result_video_MIMETYPE_e mime_type) {
    char* mime_typeArray[] =  { "NULL", "text/html", "video/mp4" };
    return mime_typeArray[mime_type];
}

telegram_bot_api_inline_query_result_video_MIMETYPE_e inline_query_result_video_mime_type_FromString(char* mime_type){
    int stringToReturn = 0;
    char *mime_typeArray[] =  { "NULL", "text/html", "video/mp4" };
    size_t sizeofArray = sizeof(mime_typeArray) / sizeof(mime_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(mime_type, mime_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static inline_query_result_video_t *inline_query_result_video_create_internal(
    char *type,
    char *id,
    char *video_url,
    telegram_bot_api_inline_query_result_video_MIMETYPE_e mime_type,
    char *thumbnail_url,
    char *title,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    int video_width,
    int video_height,
    int video_duration,
    char *description,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
    ) {
    inline_query_result_video_t *inline_query_result_video_local_var = malloc(sizeof(inline_query_result_video_t));
    if (!inline_query_result_video_local_var) {
        return NULL;
    }
    inline_query_result_video_local_var->type = type;
    inline_query_result_video_local_var->id = id;
    inline_query_result_video_local_var->video_url = video_url;
    inline_query_result_video_local_var->mime_type = mime_type;
    inline_query_result_video_local_var->thumbnail_url = thumbnail_url;
    inline_query_result_video_local_var->title = title;
    inline_query_result_video_local_var->caption = caption;
    inline_query_result_video_local_var->parse_mode = parse_mode;
    inline_query_result_video_local_var->caption_entities = caption_entities;
    inline_query_result_video_local_var->show_caption_above_media = show_caption_above_media;
    inline_query_result_video_local_var->video_width = video_width;
    inline_query_result_video_local_var->video_height = video_height;
    inline_query_result_video_local_var->video_duration = video_duration;
    inline_query_result_video_local_var->description = description;
    inline_query_result_video_local_var->reply_markup = reply_markup;
    inline_query_result_video_local_var->input_message_content = input_message_content;

    inline_query_result_video_local_var->_library_owned = 1;
    return inline_query_result_video_local_var;
}

__attribute__((deprecated)) inline_query_result_video_t *inline_query_result_video_create(
    char *type,
    char *id,
    char *video_url,
    telegram_bot_api_inline_query_result_video_MIMETYPE_e mime_type,
    char *thumbnail_url,
    char *title,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    int video_width,
    int video_height,
    int video_duration,
    char *description,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
    ) {
    return inline_query_result_video_create_internal (
        type,
        id,
        video_url,
        mime_type,
        thumbnail_url,
        title,
        caption,
        parse_mode,
        caption_entities,
        show_caption_above_media,
        video_width,
        video_height,
        video_duration,
        description,
        reply_markup,
        input_message_content
        );
}

void inline_query_result_video_free(inline_query_result_video_t *inline_query_result_video) {
    if(NULL == inline_query_result_video){
        return ;
    }
    if(inline_query_result_video->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inline_query_result_video_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inline_query_result_video->type) {
        free(inline_query_result_video->type);
        inline_query_result_video->type = NULL;
    }
    if (inline_query_result_video->id) {
        free(inline_query_result_video->id);
        inline_query_result_video->id = NULL;
    }
    if (inline_query_result_video->video_url) {
        free(inline_query_result_video->video_url);
        inline_query_result_video->video_url = NULL;
    }
    if (inline_query_result_video->thumbnail_url) {
        free(inline_query_result_video->thumbnail_url);
        inline_query_result_video->thumbnail_url = NULL;
    }
    if (inline_query_result_video->title) {
        free(inline_query_result_video->title);
        inline_query_result_video->title = NULL;
    }
    if (inline_query_result_video->caption) {
        free(inline_query_result_video->caption);
        inline_query_result_video->caption = NULL;
    }
    if (inline_query_result_video->parse_mode) {
        free(inline_query_result_video->parse_mode);
        inline_query_result_video->parse_mode = NULL;
    }
    if (inline_query_result_video->caption_entities) {
        list_ForEach(listEntry, inline_query_result_video->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(inline_query_result_video->caption_entities);
        inline_query_result_video->caption_entities = NULL;
    }
    if (inline_query_result_video->description) {
        free(inline_query_result_video->description);
        inline_query_result_video->description = NULL;
    }
    if (inline_query_result_video->reply_markup) {
        inline_keyboard_markup_free(inline_query_result_video->reply_markup);
        inline_query_result_video->reply_markup = NULL;
    }
    if (inline_query_result_video->input_message_content) {
        input_message_content_free(inline_query_result_video->input_message_content);
        inline_query_result_video->input_message_content = NULL;
    }
    free(inline_query_result_video);
}

cJSON *inline_query_result_video_convertToJSON(inline_query_result_video_t *inline_query_result_video) {
    cJSON *item = cJSON_CreateObject();

    // inline_query_result_video->type
    if (!inline_query_result_video->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", inline_query_result_video->type) == NULL) {
    goto fail; //String
    }


    // inline_query_result_video->id
    if (!inline_query_result_video->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", inline_query_result_video->id) == NULL) {
    goto fail; //String
    }


    // inline_query_result_video->video_url
    if (!inline_query_result_video->video_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "video_url", inline_query_result_video->video_url) == NULL) {
    goto fail; //String
    }


    // inline_query_result_video->mime_type
    if (telegram_bot_api_inline_query_result_video_MIMETYPE_NULL == inline_query_result_video->mime_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mime_type", inline_query_result_video_mime_type_ToString(inline_query_result_video->mime_type)) == NULL)
    {
    goto fail; //Enum
    }


    // inline_query_result_video->thumbnail_url
    if (!inline_query_result_video->thumbnail_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "thumbnail_url", inline_query_result_video->thumbnail_url) == NULL) {
    goto fail; //String
    }


    // inline_query_result_video->title
    if (!inline_query_result_video->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", inline_query_result_video->title) == NULL) {
    goto fail; //String
    }


    // inline_query_result_video->caption
    if(inline_query_result_video->caption) {
    if(cJSON_AddStringToObject(item, "caption", inline_query_result_video->caption) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_video->parse_mode
    if(inline_query_result_video->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", inline_query_result_video->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_video->caption_entities
    if(inline_query_result_video->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (inline_query_result_video->caption_entities) {
    list_ForEach(caption_entitiesListEntry, inline_query_result_video->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // inline_query_result_video->show_caption_above_media
    if(inline_query_result_video->show_caption_above_media) {
    if(cJSON_AddBoolToObject(item, "show_caption_above_media", inline_query_result_video->show_caption_above_media) == NULL) {
    goto fail; //Bool
    }
    }


    // inline_query_result_video->video_width
    if(inline_query_result_video->video_width) {
    if(cJSON_AddNumberToObject(item, "video_width", inline_query_result_video->video_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result_video->video_height
    if(inline_query_result_video->video_height) {
    if(cJSON_AddNumberToObject(item, "video_height", inline_query_result_video->video_height) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result_video->video_duration
    if(inline_query_result_video->video_duration) {
    if(cJSON_AddNumberToObject(item, "video_duration", inline_query_result_video->video_duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result_video->description
    if(inline_query_result_video->description) {
    if(cJSON_AddStringToObject(item, "description", inline_query_result_video->description) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_video->reply_markup
    if(inline_query_result_video->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(inline_query_result_video->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_query_result_video->input_message_content
    if(inline_query_result_video->input_message_content) {
    cJSON *input_message_content_local_JSON = input_message_content_convertToJSON(inline_query_result_video->input_message_content);
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

inline_query_result_video_t *inline_query_result_video_parseFromJSON(cJSON *inline_query_result_videoJSON){

    inline_query_result_video_t *inline_query_result_video_local_var = NULL;

    // define the local list for inline_query_result_video->caption_entities
    list_t *caption_entitiesList = NULL;

    // define the local variable for inline_query_result_video->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // define the local variable for inline_query_result_video->input_message_content
    input_message_content_t *input_message_content_local_nonprim = NULL;

    // inline_query_result_video->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(inline_query_result_videoJSON, "type");
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

    // inline_query_result_video->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(inline_query_result_videoJSON, "id");
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

    // inline_query_result_video->video_url
    cJSON *video_url = cJSON_GetObjectItemCaseSensitive(inline_query_result_videoJSON, "video_url");
    if (cJSON_IsNull(video_url)) {
        video_url = NULL;
    }
    if (!video_url) {
        goto end;
    }

    
    if(!cJSON_IsString(video_url))
    {
    goto end; //String
    }

    // inline_query_result_video->mime_type
    cJSON *mime_type = cJSON_GetObjectItemCaseSensitive(inline_query_result_videoJSON, "mime_type");
    if (cJSON_IsNull(mime_type)) {
        mime_type = NULL;
    }
    if (!mime_type) {
        goto end;
    }

    telegram_bot_api_inline_query_result_video_MIMETYPE_e mime_typeVariable;
    
    if(!cJSON_IsString(mime_type))
    {
    goto end; //Enum
    }
    mime_typeVariable = inline_query_result_video_mime_type_FromString(mime_type->valuestring);

    // inline_query_result_video->thumbnail_url
    cJSON *thumbnail_url = cJSON_GetObjectItemCaseSensitive(inline_query_result_videoJSON, "thumbnail_url");
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

    // inline_query_result_video->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(inline_query_result_videoJSON, "title");
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

    // inline_query_result_video->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(inline_query_result_videoJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // inline_query_result_video->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(inline_query_result_videoJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // inline_query_result_video->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(inline_query_result_videoJSON, "caption_entities");
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

    // inline_query_result_video->show_caption_above_media
    cJSON *show_caption_above_media = cJSON_GetObjectItemCaseSensitive(inline_query_result_videoJSON, "show_caption_above_media");
    if (cJSON_IsNull(show_caption_above_media)) {
        show_caption_above_media = NULL;
    }
    if (show_caption_above_media) { 
    if(!cJSON_IsBool(show_caption_above_media))
    {
    goto end; //Bool
    }
    }

    // inline_query_result_video->video_width
    cJSON *video_width = cJSON_GetObjectItemCaseSensitive(inline_query_result_videoJSON, "video_width");
    if (cJSON_IsNull(video_width)) {
        video_width = NULL;
    }
    if (video_width) { 
    if(!cJSON_IsNumber(video_width))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result_video->video_height
    cJSON *video_height = cJSON_GetObjectItemCaseSensitive(inline_query_result_videoJSON, "video_height");
    if (cJSON_IsNull(video_height)) {
        video_height = NULL;
    }
    if (video_height) { 
    if(!cJSON_IsNumber(video_height))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result_video->video_duration
    cJSON *video_duration = cJSON_GetObjectItemCaseSensitive(inline_query_result_videoJSON, "video_duration");
    if (cJSON_IsNull(video_duration)) {
        video_duration = NULL;
    }
    if (video_duration) { 
    if(!cJSON_IsNumber(video_duration))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result_video->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(inline_query_result_videoJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // inline_query_result_video->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(inline_query_result_videoJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }

    // inline_query_result_video->input_message_content
    cJSON *input_message_content = cJSON_GetObjectItemCaseSensitive(inline_query_result_videoJSON, "input_message_content");
    if (cJSON_IsNull(input_message_content)) {
        input_message_content = NULL;
    }
    if (input_message_content) { 
    input_message_content_local_nonprim = input_message_content_parseFromJSON(input_message_content); //nonprimitive
    }


    inline_query_result_video_local_var = inline_query_result_video_create_internal (
        strdup(type->valuestring),
        strdup(id->valuestring),
        strdup(video_url->valuestring),
        mime_typeVariable,
        strdup(thumbnail_url->valuestring),
        strdup(title->valuestring),
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        show_caption_above_media ? show_caption_above_media->valueint : 0,
        video_width ? video_width->valuedouble : 0,
        video_height ? video_height->valuedouble : 0,
        video_duration ? video_duration->valuedouble : 0,
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL,
        input_message_content ? input_message_content_local_nonprim : NULL
        );

    return inline_query_result_video_local_var;
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
