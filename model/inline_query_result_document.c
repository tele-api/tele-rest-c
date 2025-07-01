#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_query_result_document.h"


char* inline_query_result_document_mime_type_ToString(telegram_bot_api_inline_query_result_document_MIMETYPE_e mime_type) {
    char* mime_typeArray[] =  { "NULL", "application/pdf", "application/zip" };
    return mime_typeArray[mime_type];
}

telegram_bot_api_inline_query_result_document_MIMETYPE_e inline_query_result_document_mime_type_FromString(char* mime_type){
    int stringToReturn = 0;
    char *mime_typeArray[] =  { "NULL", "application/pdf", "application/zip" };
    size_t sizeofArray = sizeof(mime_typeArray) / sizeof(mime_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(mime_type, mime_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static inline_query_result_document_t *inline_query_result_document_create_internal(
    char *type,
    char *id,
    char *title,
    char *document_url,
    telegram_bot_api_inline_query_result_document_MIMETYPE_e mime_type,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    char *description,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content,
    char *thumbnail_url,
    int thumbnail_width,
    int thumbnail_height
    ) {
    inline_query_result_document_t *inline_query_result_document_local_var = malloc(sizeof(inline_query_result_document_t));
    if (!inline_query_result_document_local_var) {
        return NULL;
    }
    inline_query_result_document_local_var->type = type;
    inline_query_result_document_local_var->id = id;
    inline_query_result_document_local_var->title = title;
    inline_query_result_document_local_var->document_url = document_url;
    inline_query_result_document_local_var->mime_type = mime_type;
    inline_query_result_document_local_var->caption = caption;
    inline_query_result_document_local_var->parse_mode = parse_mode;
    inline_query_result_document_local_var->caption_entities = caption_entities;
    inline_query_result_document_local_var->description = description;
    inline_query_result_document_local_var->reply_markup = reply_markup;
    inline_query_result_document_local_var->input_message_content = input_message_content;
    inline_query_result_document_local_var->thumbnail_url = thumbnail_url;
    inline_query_result_document_local_var->thumbnail_width = thumbnail_width;
    inline_query_result_document_local_var->thumbnail_height = thumbnail_height;

    inline_query_result_document_local_var->_library_owned = 1;
    return inline_query_result_document_local_var;
}

__attribute__((deprecated)) inline_query_result_document_t *inline_query_result_document_create(
    char *type,
    char *id,
    char *title,
    char *document_url,
    telegram_bot_api_inline_query_result_document_MIMETYPE_e mime_type,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    char *description,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content,
    char *thumbnail_url,
    int thumbnail_width,
    int thumbnail_height
    ) {
    return inline_query_result_document_create_internal (
        type,
        id,
        title,
        document_url,
        mime_type,
        caption,
        parse_mode,
        caption_entities,
        description,
        reply_markup,
        input_message_content,
        thumbnail_url,
        thumbnail_width,
        thumbnail_height
        );
}

void inline_query_result_document_free(inline_query_result_document_t *inline_query_result_document) {
    if(NULL == inline_query_result_document){
        return ;
    }
    if(inline_query_result_document->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inline_query_result_document_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inline_query_result_document->type) {
        free(inline_query_result_document->type);
        inline_query_result_document->type = NULL;
    }
    if (inline_query_result_document->id) {
        free(inline_query_result_document->id);
        inline_query_result_document->id = NULL;
    }
    if (inline_query_result_document->title) {
        free(inline_query_result_document->title);
        inline_query_result_document->title = NULL;
    }
    if (inline_query_result_document->document_url) {
        free(inline_query_result_document->document_url);
        inline_query_result_document->document_url = NULL;
    }
    if (inline_query_result_document->caption) {
        free(inline_query_result_document->caption);
        inline_query_result_document->caption = NULL;
    }
    if (inline_query_result_document->parse_mode) {
        free(inline_query_result_document->parse_mode);
        inline_query_result_document->parse_mode = NULL;
    }
    if (inline_query_result_document->caption_entities) {
        list_ForEach(listEntry, inline_query_result_document->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(inline_query_result_document->caption_entities);
        inline_query_result_document->caption_entities = NULL;
    }
    if (inline_query_result_document->description) {
        free(inline_query_result_document->description);
        inline_query_result_document->description = NULL;
    }
    if (inline_query_result_document->reply_markup) {
        inline_keyboard_markup_free(inline_query_result_document->reply_markup);
        inline_query_result_document->reply_markup = NULL;
    }
    if (inline_query_result_document->input_message_content) {
        input_message_content_free(inline_query_result_document->input_message_content);
        inline_query_result_document->input_message_content = NULL;
    }
    if (inline_query_result_document->thumbnail_url) {
        free(inline_query_result_document->thumbnail_url);
        inline_query_result_document->thumbnail_url = NULL;
    }
    free(inline_query_result_document);
}

cJSON *inline_query_result_document_convertToJSON(inline_query_result_document_t *inline_query_result_document) {
    cJSON *item = cJSON_CreateObject();

    // inline_query_result_document->type
    if (!inline_query_result_document->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", inline_query_result_document->type) == NULL) {
    goto fail; //String
    }


    // inline_query_result_document->id
    if (!inline_query_result_document->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", inline_query_result_document->id) == NULL) {
    goto fail; //String
    }


    // inline_query_result_document->title
    if (!inline_query_result_document->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", inline_query_result_document->title) == NULL) {
    goto fail; //String
    }


    // inline_query_result_document->document_url
    if (!inline_query_result_document->document_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "document_url", inline_query_result_document->document_url) == NULL) {
    goto fail; //String
    }


    // inline_query_result_document->mime_type
    if (telegram_bot_api_inline_query_result_document_MIMETYPE_NULL == inline_query_result_document->mime_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mime_type", inline_query_result_document_mime_type_ToString(inline_query_result_document->mime_type)) == NULL)
    {
    goto fail; //Enum
    }


    // inline_query_result_document->caption
    if(inline_query_result_document->caption) {
    if(cJSON_AddStringToObject(item, "caption", inline_query_result_document->caption) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_document->parse_mode
    if(inline_query_result_document->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", inline_query_result_document->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_document->caption_entities
    if(inline_query_result_document->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (inline_query_result_document->caption_entities) {
    list_ForEach(caption_entitiesListEntry, inline_query_result_document->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // inline_query_result_document->description
    if(inline_query_result_document->description) {
    if(cJSON_AddStringToObject(item, "description", inline_query_result_document->description) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_document->reply_markup
    if(inline_query_result_document->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(inline_query_result_document->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_query_result_document->input_message_content
    if(inline_query_result_document->input_message_content) {
    cJSON *input_message_content_local_JSON = input_message_content_convertToJSON(inline_query_result_document->input_message_content);
    if(input_message_content_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "input_message_content", input_message_content_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_query_result_document->thumbnail_url
    if(inline_query_result_document->thumbnail_url) {
    if(cJSON_AddStringToObject(item, "thumbnail_url", inline_query_result_document->thumbnail_url) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_document->thumbnail_width
    if(inline_query_result_document->thumbnail_width) {
    if(cJSON_AddNumberToObject(item, "thumbnail_width", inline_query_result_document->thumbnail_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result_document->thumbnail_height
    if(inline_query_result_document->thumbnail_height) {
    if(cJSON_AddNumberToObject(item, "thumbnail_height", inline_query_result_document->thumbnail_height) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

inline_query_result_document_t *inline_query_result_document_parseFromJSON(cJSON *inline_query_result_documentJSON){

    inline_query_result_document_t *inline_query_result_document_local_var = NULL;

    // define the local list for inline_query_result_document->caption_entities
    list_t *caption_entitiesList = NULL;

    // define the local variable for inline_query_result_document->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // define the local variable for inline_query_result_document->input_message_content
    input_message_content_t *input_message_content_local_nonprim = NULL;

    // inline_query_result_document->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(inline_query_result_documentJSON, "type");
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

    // inline_query_result_document->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(inline_query_result_documentJSON, "id");
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

    // inline_query_result_document->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(inline_query_result_documentJSON, "title");
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

    // inline_query_result_document->document_url
    cJSON *document_url = cJSON_GetObjectItemCaseSensitive(inline_query_result_documentJSON, "document_url");
    if (cJSON_IsNull(document_url)) {
        document_url = NULL;
    }
    if (!document_url) {
        goto end;
    }

    
    if(!cJSON_IsString(document_url))
    {
    goto end; //String
    }

    // inline_query_result_document->mime_type
    cJSON *mime_type = cJSON_GetObjectItemCaseSensitive(inline_query_result_documentJSON, "mime_type");
    if (cJSON_IsNull(mime_type)) {
        mime_type = NULL;
    }
    if (!mime_type) {
        goto end;
    }

    telegram_bot_api_inline_query_result_document_MIMETYPE_e mime_typeVariable;
    
    if(!cJSON_IsString(mime_type))
    {
    goto end; //Enum
    }
    mime_typeVariable = inline_query_result_document_mime_type_FromString(mime_type->valuestring);

    // inline_query_result_document->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(inline_query_result_documentJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // inline_query_result_document->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(inline_query_result_documentJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // inline_query_result_document->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(inline_query_result_documentJSON, "caption_entities");
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

    // inline_query_result_document->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(inline_query_result_documentJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // inline_query_result_document->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(inline_query_result_documentJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }

    // inline_query_result_document->input_message_content
    cJSON *input_message_content = cJSON_GetObjectItemCaseSensitive(inline_query_result_documentJSON, "input_message_content");
    if (cJSON_IsNull(input_message_content)) {
        input_message_content = NULL;
    }
    if (input_message_content) { 
    input_message_content_local_nonprim = input_message_content_parseFromJSON(input_message_content); //nonprimitive
    }

    // inline_query_result_document->thumbnail_url
    cJSON *thumbnail_url = cJSON_GetObjectItemCaseSensitive(inline_query_result_documentJSON, "thumbnail_url");
    if (cJSON_IsNull(thumbnail_url)) {
        thumbnail_url = NULL;
    }
    if (thumbnail_url) { 
    if(!cJSON_IsString(thumbnail_url) && !cJSON_IsNull(thumbnail_url))
    {
    goto end; //String
    }
    }

    // inline_query_result_document->thumbnail_width
    cJSON *thumbnail_width = cJSON_GetObjectItemCaseSensitive(inline_query_result_documentJSON, "thumbnail_width");
    if (cJSON_IsNull(thumbnail_width)) {
        thumbnail_width = NULL;
    }
    if (thumbnail_width) { 
    if(!cJSON_IsNumber(thumbnail_width))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result_document->thumbnail_height
    cJSON *thumbnail_height = cJSON_GetObjectItemCaseSensitive(inline_query_result_documentJSON, "thumbnail_height");
    if (cJSON_IsNull(thumbnail_height)) {
        thumbnail_height = NULL;
    }
    if (thumbnail_height) { 
    if(!cJSON_IsNumber(thumbnail_height))
    {
    goto end; //Numeric
    }
    }


    inline_query_result_document_local_var = inline_query_result_document_create_internal (
        strdup(type->valuestring),
        strdup(id->valuestring),
        strdup(title->valuestring),
        strdup(document_url->valuestring),
        mime_typeVariable,
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL,
        input_message_content ? input_message_content_local_nonprim : NULL,
        thumbnail_url && !cJSON_IsNull(thumbnail_url) ? strdup(thumbnail_url->valuestring) : NULL,
        thumbnail_width ? thumbnail_width->valuedouble : 0,
        thumbnail_height ? thumbnail_height->valuedouble : 0
        );

    return inline_query_result_document_local_var;
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
