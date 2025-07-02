#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_edit_message_caption_request.h"



static post_edit_message_caption_request_t *post_edit_message_caption_request_create_internal(
    char *business_connection_id,
    post_edit_message_text_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    inline_keyboard_markup_t *reply_markup
    ) {
    post_edit_message_caption_request_t *post_edit_message_caption_request_local_var = malloc(sizeof(post_edit_message_caption_request_t));
    if (!post_edit_message_caption_request_local_var) {
        return NULL;
    }
    post_edit_message_caption_request_local_var->business_connection_id = business_connection_id;
    post_edit_message_caption_request_local_var->chat_id = chat_id;
    post_edit_message_caption_request_local_var->message_id = message_id;
    post_edit_message_caption_request_local_var->inline_message_id = inline_message_id;
    post_edit_message_caption_request_local_var->caption = caption;
    post_edit_message_caption_request_local_var->parse_mode = parse_mode;
    post_edit_message_caption_request_local_var->caption_entities = caption_entities;
    post_edit_message_caption_request_local_var->show_caption_above_media = show_caption_above_media;
    post_edit_message_caption_request_local_var->reply_markup = reply_markup;

    post_edit_message_caption_request_local_var->_library_owned = 1;
    return post_edit_message_caption_request_local_var;
}

__attribute__((deprecated)) post_edit_message_caption_request_t *post_edit_message_caption_request_create(
    char *business_connection_id,
    post_edit_message_text_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    inline_keyboard_markup_t *reply_markup
    ) {
    return post_edit_message_caption_request_create_internal (
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

void post_edit_message_caption_request_free(post_edit_message_caption_request_t *post_edit_message_caption_request) {
    if(NULL == post_edit_message_caption_request){
        return ;
    }
    if(post_edit_message_caption_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_edit_message_caption_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_edit_message_caption_request->business_connection_id) {
        free(post_edit_message_caption_request->business_connection_id);
        post_edit_message_caption_request->business_connection_id = NULL;
    }
    if (post_edit_message_caption_request->chat_id) {
        post_edit_message_text_request_chat_id_free(post_edit_message_caption_request->chat_id);
        post_edit_message_caption_request->chat_id = NULL;
    }
    if (post_edit_message_caption_request->inline_message_id) {
        free(post_edit_message_caption_request->inline_message_id);
        post_edit_message_caption_request->inline_message_id = NULL;
    }
    if (post_edit_message_caption_request->caption) {
        free(post_edit_message_caption_request->caption);
        post_edit_message_caption_request->caption = NULL;
    }
    if (post_edit_message_caption_request->parse_mode) {
        free(post_edit_message_caption_request->parse_mode);
        post_edit_message_caption_request->parse_mode = NULL;
    }
    if (post_edit_message_caption_request->caption_entities) {
        list_ForEach(listEntry, post_edit_message_caption_request->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(post_edit_message_caption_request->caption_entities);
        post_edit_message_caption_request->caption_entities = NULL;
    }
    if (post_edit_message_caption_request->reply_markup) {
        inline_keyboard_markup_free(post_edit_message_caption_request->reply_markup);
        post_edit_message_caption_request->reply_markup = NULL;
    }
    free(post_edit_message_caption_request);
}

cJSON *post_edit_message_caption_request_convertToJSON(post_edit_message_caption_request_t *post_edit_message_caption_request) {
    cJSON *item = cJSON_CreateObject();

    // post_edit_message_caption_request->business_connection_id
    if(post_edit_message_caption_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", post_edit_message_caption_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // post_edit_message_caption_request->chat_id
    if(post_edit_message_caption_request->chat_id) {
    cJSON *chat_id_local_JSON = post_edit_message_text_request_chat_id_convertToJSON(post_edit_message_caption_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // post_edit_message_caption_request->message_id
    if(post_edit_message_caption_request->message_id) {
    if(cJSON_AddNumberToObject(item, "message_id", post_edit_message_caption_request->message_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_edit_message_caption_request->inline_message_id
    if(post_edit_message_caption_request->inline_message_id) {
    if(cJSON_AddStringToObject(item, "inline_message_id", post_edit_message_caption_request->inline_message_id) == NULL) {
    goto fail; //String
    }
    }


    // post_edit_message_caption_request->caption
    if(post_edit_message_caption_request->caption) {
    if(cJSON_AddStringToObject(item, "caption", post_edit_message_caption_request->caption) == NULL) {
    goto fail; //String
    }
    }


    // post_edit_message_caption_request->parse_mode
    if(post_edit_message_caption_request->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", post_edit_message_caption_request->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // post_edit_message_caption_request->caption_entities
    if(post_edit_message_caption_request->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (post_edit_message_caption_request->caption_entities) {
    list_ForEach(caption_entitiesListEntry, post_edit_message_caption_request->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // post_edit_message_caption_request->show_caption_above_media
    if(post_edit_message_caption_request->show_caption_above_media) {
    if(cJSON_AddBoolToObject(item, "show_caption_above_media", post_edit_message_caption_request->show_caption_above_media) == NULL) {
    goto fail; //Bool
    }
    }


    // post_edit_message_caption_request->reply_markup
    if(post_edit_message_caption_request->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(post_edit_message_caption_request->reply_markup);
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

post_edit_message_caption_request_t *post_edit_message_caption_request_parseFromJSON(cJSON *post_edit_message_caption_requestJSON){

    post_edit_message_caption_request_t *post_edit_message_caption_request_local_var = NULL;

    // define the local variable for post_edit_message_caption_request->chat_id
    post_edit_message_text_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for post_edit_message_caption_request->caption_entities
    list_t *caption_entitiesList = NULL;

    // define the local variable for post_edit_message_caption_request->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // post_edit_message_caption_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_edit_message_caption_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // post_edit_message_caption_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_edit_message_caption_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (chat_id) { 
    chat_id_local_nonprim = post_edit_message_text_request_chat_id_parseFromJSON(chat_id); //nonprimitive
    }

    // post_edit_message_caption_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(post_edit_message_caption_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (message_id) { 
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }
    }

    // post_edit_message_caption_request->inline_message_id
    cJSON *inline_message_id = cJSON_GetObjectItemCaseSensitive(post_edit_message_caption_requestJSON, "inline_message_id");
    if (cJSON_IsNull(inline_message_id)) {
        inline_message_id = NULL;
    }
    if (inline_message_id) { 
    if(!cJSON_IsString(inline_message_id) && !cJSON_IsNull(inline_message_id))
    {
    goto end; //String
    }
    }

    // post_edit_message_caption_request->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(post_edit_message_caption_requestJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // post_edit_message_caption_request->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(post_edit_message_caption_requestJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // post_edit_message_caption_request->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(post_edit_message_caption_requestJSON, "caption_entities");
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

    // post_edit_message_caption_request->show_caption_above_media
    cJSON *show_caption_above_media = cJSON_GetObjectItemCaseSensitive(post_edit_message_caption_requestJSON, "show_caption_above_media");
    if (cJSON_IsNull(show_caption_above_media)) {
        show_caption_above_media = NULL;
    }
    if (show_caption_above_media) { 
    if(!cJSON_IsBool(show_caption_above_media))
    {
    goto end; //Bool
    }
    }

    // post_edit_message_caption_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(post_edit_message_caption_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    post_edit_message_caption_request_local_var = post_edit_message_caption_request_create_internal (
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

    return post_edit_message_caption_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_edit_message_text_request_chat_id_free(chat_id_local_nonprim);
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
