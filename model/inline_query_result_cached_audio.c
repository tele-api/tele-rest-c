#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_query_result_cached_audio.h"



static inline_query_result_cached_audio_t *inline_query_result_cached_audio_create_internal(
    char *type,
    char *id,
    char *audio_file_id,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
    ) {
    inline_query_result_cached_audio_t *inline_query_result_cached_audio_local_var = malloc(sizeof(inline_query_result_cached_audio_t));
    if (!inline_query_result_cached_audio_local_var) {
        return NULL;
    }
    inline_query_result_cached_audio_local_var->type = type;
    inline_query_result_cached_audio_local_var->id = id;
    inline_query_result_cached_audio_local_var->audio_file_id = audio_file_id;
    inline_query_result_cached_audio_local_var->caption = caption;
    inline_query_result_cached_audio_local_var->parse_mode = parse_mode;
    inline_query_result_cached_audio_local_var->caption_entities = caption_entities;
    inline_query_result_cached_audio_local_var->reply_markup = reply_markup;
    inline_query_result_cached_audio_local_var->input_message_content = input_message_content;

    inline_query_result_cached_audio_local_var->_library_owned = 1;
    return inline_query_result_cached_audio_local_var;
}

__attribute__((deprecated)) inline_query_result_cached_audio_t *inline_query_result_cached_audio_create(
    char *type,
    char *id,
    char *audio_file_id,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
    ) {
    return inline_query_result_cached_audio_create_internal (
        type,
        id,
        audio_file_id,
        caption,
        parse_mode,
        caption_entities,
        reply_markup,
        input_message_content
        );
}

void inline_query_result_cached_audio_free(inline_query_result_cached_audio_t *inline_query_result_cached_audio) {
    if(NULL == inline_query_result_cached_audio){
        return ;
    }
    if(inline_query_result_cached_audio->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inline_query_result_cached_audio_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inline_query_result_cached_audio->type) {
        free(inline_query_result_cached_audio->type);
        inline_query_result_cached_audio->type = NULL;
    }
    if (inline_query_result_cached_audio->id) {
        free(inline_query_result_cached_audio->id);
        inline_query_result_cached_audio->id = NULL;
    }
    if (inline_query_result_cached_audio->audio_file_id) {
        free(inline_query_result_cached_audio->audio_file_id);
        inline_query_result_cached_audio->audio_file_id = NULL;
    }
    if (inline_query_result_cached_audio->caption) {
        free(inline_query_result_cached_audio->caption);
        inline_query_result_cached_audio->caption = NULL;
    }
    if (inline_query_result_cached_audio->parse_mode) {
        free(inline_query_result_cached_audio->parse_mode);
        inline_query_result_cached_audio->parse_mode = NULL;
    }
    if (inline_query_result_cached_audio->caption_entities) {
        list_ForEach(listEntry, inline_query_result_cached_audio->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(inline_query_result_cached_audio->caption_entities);
        inline_query_result_cached_audio->caption_entities = NULL;
    }
    if (inline_query_result_cached_audio->reply_markup) {
        inline_keyboard_markup_free(inline_query_result_cached_audio->reply_markup);
        inline_query_result_cached_audio->reply_markup = NULL;
    }
    if (inline_query_result_cached_audio->input_message_content) {
        input_message_content_free(inline_query_result_cached_audio->input_message_content);
        inline_query_result_cached_audio->input_message_content = NULL;
    }
    free(inline_query_result_cached_audio);
}

cJSON *inline_query_result_cached_audio_convertToJSON(inline_query_result_cached_audio_t *inline_query_result_cached_audio) {
    cJSON *item = cJSON_CreateObject();

    // inline_query_result_cached_audio->type
    if (!inline_query_result_cached_audio->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", inline_query_result_cached_audio->type) == NULL) {
    goto fail; //String
    }


    // inline_query_result_cached_audio->id
    if (!inline_query_result_cached_audio->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", inline_query_result_cached_audio->id) == NULL) {
    goto fail; //String
    }


    // inline_query_result_cached_audio->audio_file_id
    if (!inline_query_result_cached_audio->audio_file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "audio_file_id", inline_query_result_cached_audio->audio_file_id) == NULL) {
    goto fail; //String
    }


    // inline_query_result_cached_audio->caption
    if(inline_query_result_cached_audio->caption) {
    if(cJSON_AddStringToObject(item, "caption", inline_query_result_cached_audio->caption) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_cached_audio->parse_mode
    if(inline_query_result_cached_audio->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", inline_query_result_cached_audio->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_cached_audio->caption_entities
    if(inline_query_result_cached_audio->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (inline_query_result_cached_audio->caption_entities) {
    list_ForEach(caption_entitiesListEntry, inline_query_result_cached_audio->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // inline_query_result_cached_audio->reply_markup
    if(inline_query_result_cached_audio->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(inline_query_result_cached_audio->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_query_result_cached_audio->input_message_content
    if(inline_query_result_cached_audio->input_message_content) {
    cJSON *input_message_content_local_JSON = input_message_content_convertToJSON(inline_query_result_cached_audio->input_message_content);
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

inline_query_result_cached_audio_t *inline_query_result_cached_audio_parseFromJSON(cJSON *inline_query_result_cached_audioJSON){

    inline_query_result_cached_audio_t *inline_query_result_cached_audio_local_var = NULL;

    // define the local list for inline_query_result_cached_audio->caption_entities
    list_t *caption_entitiesList = NULL;

    // define the local variable for inline_query_result_cached_audio->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // define the local variable for inline_query_result_cached_audio->input_message_content
    input_message_content_t *input_message_content_local_nonprim = NULL;

    // inline_query_result_cached_audio->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_audioJSON, "type");
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

    // inline_query_result_cached_audio->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_audioJSON, "id");
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

    // inline_query_result_cached_audio->audio_file_id
    cJSON *audio_file_id = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_audioJSON, "audio_file_id");
    if (cJSON_IsNull(audio_file_id)) {
        audio_file_id = NULL;
    }
    if (!audio_file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(audio_file_id))
    {
    goto end; //String
    }

    // inline_query_result_cached_audio->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_audioJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // inline_query_result_cached_audio->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_audioJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // inline_query_result_cached_audio->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_audioJSON, "caption_entities");
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

    // inline_query_result_cached_audio->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_audioJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }

    // inline_query_result_cached_audio->input_message_content
    cJSON *input_message_content = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_audioJSON, "input_message_content");
    if (cJSON_IsNull(input_message_content)) {
        input_message_content = NULL;
    }
    if (input_message_content) { 
    input_message_content_local_nonprim = input_message_content_parseFromJSON(input_message_content); //nonprimitive
    }


    inline_query_result_cached_audio_local_var = inline_query_result_cached_audio_create_internal (
        strdup(type->valuestring),
        strdup(id->valuestring),
        strdup(audio_file_id->valuestring),
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL,
        input_message_content ? input_message_content_local_nonprim : NULL
        );

    return inline_query_result_cached_audio_local_var;
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
