#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "edit_message_caption_request.h"



static edit_message_caption_request_t *edit_message_caption_request_create_internal(
    char *business_connection_id,
    edit_message_text_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    inline_keyboard_markup_t *reply_markup
    ) {
    edit_message_caption_request_t *edit_message_caption_request_local_var = malloc(sizeof(edit_message_caption_request_t));
    if (!edit_message_caption_request_local_var) {
        return NULL;
    }
    edit_message_caption_request_local_var->business_connection_id = business_connection_id;
    edit_message_caption_request_local_var->chat_id = chat_id;
    edit_message_caption_request_local_var->message_id = message_id;
    edit_message_caption_request_local_var->inline_message_id = inline_message_id;
    edit_message_caption_request_local_var->caption = caption;
    edit_message_caption_request_local_var->parse_mode = parse_mode;
    edit_message_caption_request_local_var->caption_entities = caption_entities;
    edit_message_caption_request_local_var->show_caption_above_media = show_caption_above_media;
    edit_message_caption_request_local_var->reply_markup = reply_markup;

    edit_message_caption_request_local_var->_library_owned = 1;
    return edit_message_caption_request_local_var;
}

__attribute__((deprecated)) edit_message_caption_request_t *edit_message_caption_request_create(
    char *business_connection_id,
    edit_message_text_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    inline_keyboard_markup_t *reply_markup
    ) {
    return edit_message_caption_request_create_internal (
        business_connection_id,
        chat_id,
        message_id,
        inline_message_id,
        caption,
        parse_mode,
        caption_entities,
        show_caption_above_media,
        reply_markup
        );
}

void edit_message_caption_request_free(edit_message_caption_request_t *edit_message_caption_request) {
    if(NULL == edit_message_caption_request){
        return ;
    }
    if(edit_message_caption_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "edit_message_caption_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (edit_message_caption_request->business_connection_id) {
        free(edit_message_caption_request->business_connection_id);
        edit_message_caption_request->business_connection_id = NULL;
    }
    if (edit_message_caption_request->chat_id) {
        edit_message_text_request_chat_id_free(edit_message_caption_request->chat_id);
        edit_message_caption_request->chat_id = NULL;
    }
    if (edit_message_caption_request->inline_message_id) {
        free(edit_message_caption_request->inline_message_id);
        edit_message_caption_request->inline_message_id = NULL;
    }
    if (edit_message_caption_request->caption) {
        free(edit_message_caption_request->caption);
        edit_message_caption_request->caption = NULL;
    }
    if (edit_message_caption_request->parse_mode) {
        free(edit_message_caption_request->parse_mode);
        edit_message_caption_request->parse_mode = NULL;
    }
    if (edit_message_caption_request->caption_entities) {
        list_ForEach(listEntry, edit_message_caption_request->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(edit_message_caption_request->caption_entities);
        edit_message_caption_request->caption_entities = NULL;
    }
    if (edit_message_caption_request->reply_markup) {
        inline_keyboard_markup_free(edit_message_caption_request->reply_markup);
        edit_message_caption_request->reply_markup = NULL;
    }
    free(edit_message_caption_request);
}

cJSON *edit_message_caption_request_convertToJSON(edit_message_caption_request_t *edit_message_caption_request) {
    cJSON *item = cJSON_CreateObject();

    // edit_message_caption_request->business_connection_id
    if(edit_message_caption_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", edit_message_caption_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // edit_message_caption_request->chat_id
    if(edit_message_caption_request->chat_id) {
    cJSON *chat_id_local_JSON = edit_message_text_request_chat_id_convertToJSON(edit_message_caption_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // edit_message_caption_request->message_id
    if(edit_message_caption_request->message_id) {
    if(cJSON_AddNumberToObject(item, "message_id", edit_message_caption_request->message_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // edit_message_caption_request->inline_message_id
    if(edit_message_caption_request->inline_message_id) {
    if(cJSON_AddStringToObject(item, "inline_message_id", edit_message_caption_request->inline_message_id) == NULL) {
    goto fail; //String
    }
    }


    // edit_message_caption_request->caption
    if(edit_message_caption_request->caption) {
    if(cJSON_AddStringToObject(item, "caption", edit_message_caption_request->caption) == NULL) {
    goto fail; //String
    }
    }


    // edit_message_caption_request->parse_mode
    if(edit_message_caption_request->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", edit_message_caption_request->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // edit_message_caption_request->caption_entities
    if(edit_message_caption_request->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (edit_message_caption_request->caption_entities) {
    list_ForEach(caption_entitiesListEntry, edit_message_caption_request->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // edit_message_caption_request->show_caption_above_media
    if(edit_message_caption_request->show_caption_above_media) {
    if(cJSON_AddBoolToObject(item, "show_caption_above_media", edit_message_caption_request->show_caption_above_media) == NULL) {
    goto fail; //Bool
    }
    }


    // edit_message_caption_request->reply_markup
    if(edit_message_caption_request->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(edit_message_caption_request->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
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

edit_message_caption_request_t *edit_message_caption_request_parseFromJSON(cJSON *edit_message_caption_requestJSON){

    edit_message_caption_request_t *edit_message_caption_request_local_var = NULL;

    // define the local variable for edit_message_caption_request->chat_id
    edit_message_text_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for edit_message_caption_request->caption_entities
    list_t *caption_entitiesList = NULL;

    // define the local variable for edit_message_caption_request->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // edit_message_caption_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(edit_message_caption_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // edit_message_caption_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(edit_message_caption_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (chat_id) { 
    chat_id_local_nonprim = edit_message_text_request_chat_id_parseFromJSON(chat_id); //nonprimitive
    }

    // edit_message_caption_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(edit_message_caption_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (message_id) { 
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }
    }

    // edit_message_caption_request->inline_message_id
    cJSON *inline_message_id = cJSON_GetObjectItemCaseSensitive(edit_message_caption_requestJSON, "inline_message_id");
    if (cJSON_IsNull(inline_message_id)) {
        inline_message_id = NULL;
    }
    if (inline_message_id) { 
    if(!cJSON_IsString(inline_message_id) && !cJSON_IsNull(inline_message_id))
    {
    goto end; //String
    }
    }

    // edit_message_caption_request->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(edit_message_caption_requestJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // edit_message_caption_request->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(edit_message_caption_requestJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // edit_message_caption_request->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(edit_message_caption_requestJSON, "caption_entities");
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

    // edit_message_caption_request->show_caption_above_media
    cJSON *show_caption_above_media = cJSON_GetObjectItemCaseSensitive(edit_message_caption_requestJSON, "show_caption_above_media");
    if (cJSON_IsNull(show_caption_above_media)) {
        show_caption_above_media = NULL;
    }
    if (show_caption_above_media) { 
    if(!cJSON_IsBool(show_caption_above_media))
    {
    goto end; //Bool
    }
    }

    // edit_message_caption_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(edit_message_caption_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    edit_message_caption_request_local_var = edit_message_caption_request_create_internal (
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        chat_id ? chat_id_local_nonprim : NULL,
        message_id ? message_id->valuedouble : 0,
        inline_message_id && !cJSON_IsNull(inline_message_id) ? strdup(inline_message_id->valuestring) : NULL,
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        show_caption_above_media ? show_caption_above_media->valueint : 0,
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return edit_message_caption_request_local_var;
end:
    if (chat_id_local_nonprim) {
        edit_message_text_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
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
    return NULL;

}
