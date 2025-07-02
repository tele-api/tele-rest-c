#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "edit_message_text_request.h"



static edit_message_text_request_t *edit_message_text_request_create_internal(
    char *text,
    char *business_connection_id,
    edit_message_text_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    char *parse_mode,
    list_t *entities,
    link_preview_options_t *link_preview_options,
    inline_keyboard_markup_t *reply_markup
    ) {
    edit_message_text_request_t *edit_message_text_request_local_var = malloc(sizeof(edit_message_text_request_t));
    if (!edit_message_text_request_local_var) {
        return NULL;
    }
    edit_message_text_request_local_var->text = text;
    edit_message_text_request_local_var->business_connection_id = business_connection_id;
    edit_message_text_request_local_var->chat_id = chat_id;
    edit_message_text_request_local_var->message_id = message_id;
    edit_message_text_request_local_var->inline_message_id = inline_message_id;
    edit_message_text_request_local_var->parse_mode = parse_mode;
    edit_message_text_request_local_var->entities = entities;
    edit_message_text_request_local_var->link_preview_options = link_preview_options;
    edit_message_text_request_local_var->reply_markup = reply_markup;

    edit_message_text_request_local_var->_library_owned = 1;
    return edit_message_text_request_local_var;
}

__attribute__((deprecated)) edit_message_text_request_t *edit_message_text_request_create(
    char *text,
    char *business_connection_id,
    edit_message_text_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    char *parse_mode,
    list_t *entities,
    link_preview_options_t *link_preview_options,
    inline_keyboard_markup_t *reply_markup
    ) {
    return edit_message_text_request_create_internal (
        text,
        business_connection_id,
        chat_id,
        message_id,
        inline_message_id,
        parse_mode,
        entities,
        link_preview_options,
        reply_markup
        );
}

void edit_message_text_request_free(edit_message_text_request_t *edit_message_text_request) {
    if(NULL == edit_message_text_request){
        return ;
    }
    if(edit_message_text_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "edit_message_text_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (edit_message_text_request->text) {
        free(edit_message_text_request->text);
        edit_message_text_request->text = NULL;
    }
    if (edit_message_text_request->business_connection_id) {
        free(edit_message_text_request->business_connection_id);
        edit_message_text_request->business_connection_id = NULL;
    }
    if (edit_message_text_request->chat_id) {
        edit_message_text_request_chat_id_free(edit_message_text_request->chat_id);
        edit_message_text_request->chat_id = NULL;
    }
    if (edit_message_text_request->inline_message_id) {
        free(edit_message_text_request->inline_message_id);
        edit_message_text_request->inline_message_id = NULL;
    }
    if (edit_message_text_request->parse_mode) {
        free(edit_message_text_request->parse_mode);
        edit_message_text_request->parse_mode = NULL;
    }
    if (edit_message_text_request->entities) {
        list_ForEach(listEntry, edit_message_text_request->entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(edit_message_text_request->entities);
        edit_message_text_request->entities = NULL;
    }
    if (edit_message_text_request->link_preview_options) {
        link_preview_options_free(edit_message_text_request->link_preview_options);
        edit_message_text_request->link_preview_options = NULL;
    }
    if (edit_message_text_request->reply_markup) {
        inline_keyboard_markup_free(edit_message_text_request->reply_markup);
        edit_message_text_request->reply_markup = NULL;
    }
    free(edit_message_text_request);
}

cJSON *edit_message_text_request_convertToJSON(edit_message_text_request_t *edit_message_text_request) {
    cJSON *item = cJSON_CreateObject();

    // edit_message_text_request->text
    if (!edit_message_text_request->text) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "text", edit_message_text_request->text) == NULL) {
    goto fail; //String
    }


    // edit_message_text_request->business_connection_id
    if(edit_message_text_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", edit_message_text_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // edit_message_text_request->chat_id
    if(edit_message_text_request->chat_id) {
    cJSON *chat_id_local_JSON = edit_message_text_request_chat_id_convertToJSON(edit_message_text_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // edit_message_text_request->message_id
    if(edit_message_text_request->message_id) {
    if(cJSON_AddNumberToObject(item, "message_id", edit_message_text_request->message_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // edit_message_text_request->inline_message_id
    if(edit_message_text_request->inline_message_id) {
    if(cJSON_AddStringToObject(item, "inline_message_id", edit_message_text_request->inline_message_id) == NULL) {
    goto fail; //String
    }
    }


    // edit_message_text_request->parse_mode
    if(edit_message_text_request->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", edit_message_text_request->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // edit_message_text_request->entities
    if(edit_message_text_request->entities) {
    cJSON *entities = cJSON_AddArrayToObject(item, "entities");
    if(entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *entitiesListEntry;
    if (edit_message_text_request->entities) {
    list_ForEach(entitiesListEntry, edit_message_text_request->entities) {
    cJSON *itemLocal = message_entity_convertToJSON(entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(entities, itemLocal);
    }
    }
    }


    // edit_message_text_request->link_preview_options
    if(edit_message_text_request->link_preview_options) {
    cJSON *link_preview_options_local_JSON = link_preview_options_convertToJSON(edit_message_text_request->link_preview_options);
    if(link_preview_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "link_preview_options", link_preview_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // edit_message_text_request->reply_markup
    if(edit_message_text_request->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(edit_message_text_request->reply_markup);
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

edit_message_text_request_t *edit_message_text_request_parseFromJSON(cJSON *edit_message_text_requestJSON){

    edit_message_text_request_t *edit_message_text_request_local_var = NULL;

    // define the local variable for edit_message_text_request->chat_id
    edit_message_text_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for edit_message_text_request->entities
    list_t *entitiesList = NULL;

    // define the local variable for edit_message_text_request->link_preview_options
    link_preview_options_t *link_preview_options_local_nonprim = NULL;

    // define the local variable for edit_message_text_request->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // edit_message_text_request->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(edit_message_text_requestJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (!text) {
        goto end;
    }

    
    if(!cJSON_IsString(text))
    {
    goto end; //String
    }

    // edit_message_text_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(edit_message_text_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // edit_message_text_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(edit_message_text_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (chat_id) { 
    chat_id_local_nonprim = edit_message_text_request_chat_id_parseFromJSON(chat_id); //nonprimitive
    }

    // edit_message_text_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(edit_message_text_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (message_id) { 
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }
    }

    // edit_message_text_request->inline_message_id
    cJSON *inline_message_id = cJSON_GetObjectItemCaseSensitive(edit_message_text_requestJSON, "inline_message_id");
    if (cJSON_IsNull(inline_message_id)) {
        inline_message_id = NULL;
    }
    if (inline_message_id) { 
    if(!cJSON_IsString(inline_message_id) && !cJSON_IsNull(inline_message_id))
    {
    goto end; //String
    }
    }

    // edit_message_text_request->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(edit_message_text_requestJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // edit_message_text_request->entities
    cJSON *entities = cJSON_GetObjectItemCaseSensitive(edit_message_text_requestJSON, "entities");
    if (cJSON_IsNull(entities)) {
        entities = NULL;
    }
    if (entities) { 
    cJSON *entities_local_nonprimitive = NULL;
    if(!cJSON_IsArray(entities)){
        goto end; //nonprimitive container
    }

    entitiesList = list_createList();

    cJSON_ArrayForEach(entities_local_nonprimitive,entities )
    {
        if(!cJSON_IsObject(entities_local_nonprimitive)){
            goto end;
        }
        message_entity_t *entitiesItem = message_entity_parseFromJSON(entities_local_nonprimitive);

        list_addElement(entitiesList, entitiesItem);
    }
    }

    // edit_message_text_request->link_preview_options
    cJSON *link_preview_options = cJSON_GetObjectItemCaseSensitive(edit_message_text_requestJSON, "link_preview_options");
    if (cJSON_IsNull(link_preview_options)) {
        link_preview_options = NULL;
    }
    if (link_preview_options) { 
    link_preview_options_local_nonprim = link_preview_options_parseFromJSON(link_preview_options); //nonprimitive
    }

    // edit_message_text_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(edit_message_text_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    edit_message_text_request_local_var = edit_message_text_request_create_internal (
        strdup(text->valuestring),
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        chat_id ? chat_id_local_nonprim : NULL,
        message_id ? message_id->valuedouble : 0,
        inline_message_id && !cJSON_IsNull(inline_message_id) ? strdup(inline_message_id->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        entities ? entitiesList : NULL,
        link_preview_options ? link_preview_options_local_nonprim : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return edit_message_text_request_local_var;
end:
    if (chat_id_local_nonprim) {
        edit_message_text_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (entitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, entitiesList) {
            message_entity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(entitiesList);
        entitiesList = NULL;
    }
    if (link_preview_options_local_nonprim) {
        link_preview_options_free(link_preview_options_local_nonprim);
        link_preview_options_local_nonprim = NULL;
    }
    if (reply_markup_local_nonprim) {
        inline_keyboard_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    return NULL;

}
