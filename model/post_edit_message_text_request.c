#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_edit_message_text_request.h"



static post_edit_message_text_request_t *post_edit_message_text_request_create_internal(
    char *text,
    char *business_connection_id,
    post_edit_message_text_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    char *parse_mode,
    list_t *entities,
    link_preview_options_t *link_preview_options,
    inline_keyboard_markup_t *reply_markup
    ) {
    post_edit_message_text_request_t *post_edit_message_text_request_local_var = malloc(sizeof(post_edit_message_text_request_t));
    if (!post_edit_message_text_request_local_var) {
        return NULL;
    }
    post_edit_message_text_request_local_var->text = text;
    post_edit_message_text_request_local_var->business_connection_id = business_connection_id;
    post_edit_message_text_request_local_var->chat_id = chat_id;
    post_edit_message_text_request_local_var->message_id = message_id;
    post_edit_message_text_request_local_var->inline_message_id = inline_message_id;
    post_edit_message_text_request_local_var->parse_mode = parse_mode;
    post_edit_message_text_request_local_var->entities = entities;
    post_edit_message_text_request_local_var->link_preview_options = link_preview_options;
    post_edit_message_text_request_local_var->reply_markup = reply_markup;

    post_edit_message_text_request_local_var->_library_owned = 1;
    return post_edit_message_text_request_local_var;
}

__attribute__((deprecated)) post_edit_message_text_request_t *post_edit_message_text_request_create(
    char *text,
    char *business_connection_id,
    post_edit_message_text_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    char *parse_mode,
    list_t *entities,
    link_preview_options_t *link_preview_options,
    inline_keyboard_markup_t *reply_markup
    ) {
    return post_edit_message_text_request_create_internal (
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

void post_edit_message_text_request_free(post_edit_message_text_request_t *post_edit_message_text_request) {
    if(NULL == post_edit_message_text_request){
        return ;
    }
    if(post_edit_message_text_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_edit_message_text_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_edit_message_text_request->text) {
        free(post_edit_message_text_request->text);
        post_edit_message_text_request->text = NULL;
    }
    if (post_edit_message_text_request->business_connection_id) {
        free(post_edit_message_text_request->business_connection_id);
        post_edit_message_text_request->business_connection_id = NULL;
    }
    if (post_edit_message_text_request->chat_id) {
        post_edit_message_text_request_chat_id_free(post_edit_message_text_request->chat_id);
        post_edit_message_text_request->chat_id = NULL;
    }
    if (post_edit_message_text_request->inline_message_id) {
        free(post_edit_message_text_request->inline_message_id);
        post_edit_message_text_request->inline_message_id = NULL;
    }
    if (post_edit_message_text_request->parse_mode) {
        free(post_edit_message_text_request->parse_mode);
        post_edit_message_text_request->parse_mode = NULL;
    }
    if (post_edit_message_text_request->entities) {
        list_ForEach(listEntry, post_edit_message_text_request->entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(post_edit_message_text_request->entities);
        post_edit_message_text_request->entities = NULL;
    }
    if (post_edit_message_text_request->link_preview_options) {
        link_preview_options_free(post_edit_message_text_request->link_preview_options);
        post_edit_message_text_request->link_preview_options = NULL;
    }
    if (post_edit_message_text_request->reply_markup) {
        inline_keyboard_markup_free(post_edit_message_text_request->reply_markup);
        post_edit_message_text_request->reply_markup = NULL;
    }
    free(post_edit_message_text_request);
}

cJSON *post_edit_message_text_request_convertToJSON(post_edit_message_text_request_t *post_edit_message_text_request) {
    cJSON *item = cJSON_CreateObject();

    // post_edit_message_text_request->text
    if (!post_edit_message_text_request->text) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "text", post_edit_message_text_request->text) == NULL) {
    goto fail; //String
    }


    // post_edit_message_text_request->business_connection_id
    if(post_edit_message_text_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", post_edit_message_text_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // post_edit_message_text_request->chat_id
    if(post_edit_message_text_request->chat_id) {
    cJSON *chat_id_local_JSON = post_edit_message_text_request_chat_id_convertToJSON(post_edit_message_text_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // post_edit_message_text_request->message_id
    if(post_edit_message_text_request->message_id) {
    if(cJSON_AddNumberToObject(item, "message_id", post_edit_message_text_request->message_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_edit_message_text_request->inline_message_id
    if(post_edit_message_text_request->inline_message_id) {
    if(cJSON_AddStringToObject(item, "inline_message_id", post_edit_message_text_request->inline_message_id) == NULL) {
    goto fail; //String
    }
    }


    // post_edit_message_text_request->parse_mode
    if(post_edit_message_text_request->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", post_edit_message_text_request->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // post_edit_message_text_request->entities
    if(post_edit_message_text_request->entities) {
    cJSON *entities = cJSON_AddArrayToObject(item, "entities");
    if(entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *entitiesListEntry;
    if (post_edit_message_text_request->entities) {
    list_ForEach(entitiesListEntry, post_edit_message_text_request->entities) {
    cJSON *itemLocal = message_entity_convertToJSON(entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(entities, itemLocal);
    }
    }
    }


    // post_edit_message_text_request->link_preview_options
    if(post_edit_message_text_request->link_preview_options) {
    cJSON *link_preview_options_local_JSON = link_preview_options_convertToJSON(post_edit_message_text_request->link_preview_options);
    if(link_preview_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "link_preview_options", link_preview_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // post_edit_message_text_request->reply_markup
    if(post_edit_message_text_request->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(post_edit_message_text_request->reply_markup);
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

post_edit_message_text_request_t *post_edit_message_text_request_parseFromJSON(cJSON *post_edit_message_text_requestJSON){

    post_edit_message_text_request_t *post_edit_message_text_request_local_var = NULL;

    // define the local variable for post_edit_message_text_request->chat_id
    post_edit_message_text_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for post_edit_message_text_request->entities
    list_t *entitiesList = NULL;

    // define the local variable for post_edit_message_text_request->link_preview_options
    link_preview_options_t *link_preview_options_local_nonprim = NULL;

    // define the local variable for post_edit_message_text_request->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // post_edit_message_text_request->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(post_edit_message_text_requestJSON, "text");
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

    // post_edit_message_text_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_edit_message_text_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // post_edit_message_text_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_edit_message_text_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (chat_id) { 
    chat_id_local_nonprim = post_edit_message_text_request_chat_id_parseFromJSON(chat_id); //nonprimitive
    }

    // post_edit_message_text_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(post_edit_message_text_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (message_id) { 
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }
    }

    // post_edit_message_text_request->inline_message_id
    cJSON *inline_message_id = cJSON_GetObjectItemCaseSensitive(post_edit_message_text_requestJSON, "inline_message_id");
    if (cJSON_IsNull(inline_message_id)) {
        inline_message_id = NULL;
    }
    if (inline_message_id) { 
    if(!cJSON_IsString(inline_message_id) && !cJSON_IsNull(inline_message_id))
    {
    goto end; //String
    }
    }

    // post_edit_message_text_request->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(post_edit_message_text_requestJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // post_edit_message_text_request->entities
    cJSON *entities = cJSON_GetObjectItemCaseSensitive(post_edit_message_text_requestJSON, "entities");
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

    // post_edit_message_text_request->link_preview_options
    cJSON *link_preview_options = cJSON_GetObjectItemCaseSensitive(post_edit_message_text_requestJSON, "link_preview_options");
    if (cJSON_IsNull(link_preview_options)) {
        link_preview_options = NULL;
    }
    if (link_preview_options) { 
    link_preview_options_local_nonprim = link_preview_options_parseFromJSON(link_preview_options); //nonprimitive
    }

    // post_edit_message_text_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(post_edit_message_text_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    post_edit_message_text_request_local_var = post_edit_message_text_request_create_internal (
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

    return post_edit_message_text_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_edit_message_text_request_chat_id_free(chat_id_local_nonprim);
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
