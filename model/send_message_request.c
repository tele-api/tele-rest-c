#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_message_request.h"



static send_message_request_t *send_message_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    char *text,
    char *business_connection_id,
    int message_thread_id,
    char *parse_mode,
    list_t *entities,
    link_preview_options_t *link_preview_options,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
    ) {
    send_message_request_t *send_message_request_local_var = malloc(sizeof(send_message_request_t));
    if (!send_message_request_local_var) {
        return NULL;
    }
    send_message_request_local_var->chat_id = chat_id;
    send_message_request_local_var->text = text;
    send_message_request_local_var->business_connection_id = business_connection_id;
    send_message_request_local_var->message_thread_id = message_thread_id;
    send_message_request_local_var->parse_mode = parse_mode;
    send_message_request_local_var->entities = entities;
    send_message_request_local_var->link_preview_options = link_preview_options;
    send_message_request_local_var->disable_notification = disable_notification;
    send_message_request_local_var->protect_content = protect_content;
    send_message_request_local_var->allow_paid_broadcast = allow_paid_broadcast;
    send_message_request_local_var->message_effect_id = message_effect_id;
    send_message_request_local_var->reply_parameters = reply_parameters;
    send_message_request_local_var->reply_markup = reply_markup;

    send_message_request_local_var->_library_owned = 1;
    return send_message_request_local_var;
}

__attribute__((deprecated)) send_message_request_t *send_message_request_create(
    send_message_request_chat_id_t *chat_id,
    char *text,
    char *business_connection_id,
    int message_thread_id,
    char *parse_mode,
    list_t *entities,
    link_preview_options_t *link_preview_options,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
    ) {
    return send_message_request_create_internal (
        chat_id,
        text,
        business_connection_id,
        message_thread_id,
        parse_mode,
        entities,
        link_preview_options,
        disable_notification,
        protect_content,
        allow_paid_broadcast,
        message_effect_id,
        reply_parameters,
        reply_markup
        );
}

void send_message_request_free(send_message_request_t *send_message_request) {
    if(NULL == send_message_request){
        return ;
    }
    if(send_message_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_message_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (send_message_request->chat_id) {
        send_message_request_chat_id_free(send_message_request->chat_id);
        send_message_request->chat_id = NULL;
    }
    if (send_message_request->text) {
        free(send_message_request->text);
        send_message_request->text = NULL;
    }
    if (send_message_request->business_connection_id) {
        free(send_message_request->business_connection_id);
        send_message_request->business_connection_id = NULL;
    }
    if (send_message_request->parse_mode) {
        free(send_message_request->parse_mode);
        send_message_request->parse_mode = NULL;
    }
    if (send_message_request->entities) {
        list_ForEach(listEntry, send_message_request->entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(send_message_request->entities);
        send_message_request->entities = NULL;
    }
    if (send_message_request->link_preview_options) {
        link_preview_options_free(send_message_request->link_preview_options);
        send_message_request->link_preview_options = NULL;
    }
    if (send_message_request->message_effect_id) {
        free(send_message_request->message_effect_id);
        send_message_request->message_effect_id = NULL;
    }
    if (send_message_request->reply_parameters) {
        reply_parameters_free(send_message_request->reply_parameters);
        send_message_request->reply_parameters = NULL;
    }
    if (send_message_request->reply_markup) {
        send_message_request_reply_markup_free(send_message_request->reply_markup);
        send_message_request->reply_markup = NULL;
    }
    free(send_message_request);
}

cJSON *send_message_request_convertToJSON(send_message_request_t *send_message_request) {
    cJSON *item = cJSON_CreateObject();

    // send_message_request->chat_id
    if (!send_message_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(send_message_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // send_message_request->text
    if (!send_message_request->text) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "text", send_message_request->text) == NULL) {
    goto fail; //String
    }


    // send_message_request->business_connection_id
    if(send_message_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", send_message_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // send_message_request->message_thread_id
    if(send_message_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", send_message_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // send_message_request->parse_mode
    if(send_message_request->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", send_message_request->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // send_message_request->entities
    if(send_message_request->entities) {
    cJSON *entities = cJSON_AddArrayToObject(item, "entities");
    if(entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *entitiesListEntry;
    if (send_message_request->entities) {
    list_ForEach(entitiesListEntry, send_message_request->entities) {
    cJSON *itemLocal = message_entity_convertToJSON(entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(entities, itemLocal);
    }
    }
    }


    // send_message_request->link_preview_options
    if(send_message_request->link_preview_options) {
    cJSON *link_preview_options_local_JSON = link_preview_options_convertToJSON(send_message_request->link_preview_options);
    if(link_preview_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "link_preview_options", link_preview_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // send_message_request->disable_notification
    if(send_message_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", send_message_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // send_message_request->protect_content
    if(send_message_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", send_message_request->protect_content) == NULL) {
    goto fail; //Bool
    }
    }


    // send_message_request->allow_paid_broadcast
    if(send_message_request->allow_paid_broadcast) {
    if(cJSON_AddBoolToObject(item, "allow_paid_broadcast", send_message_request->allow_paid_broadcast) == NULL) {
    goto fail; //Bool
    }
    }


    // send_message_request->message_effect_id
    if(send_message_request->message_effect_id) {
    if(cJSON_AddStringToObject(item, "message_effect_id", send_message_request->message_effect_id) == NULL) {
    goto fail; //String
    }
    }


    // send_message_request->reply_parameters
    if(send_message_request->reply_parameters) {
    cJSON *reply_parameters_local_JSON = reply_parameters_convertToJSON(send_message_request->reply_parameters);
    if(reply_parameters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_parameters", reply_parameters_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // send_message_request->reply_markup
    if(send_message_request->reply_markup) {
    cJSON *reply_markup_local_JSON = send_message_request_reply_markup_convertToJSON(send_message_request->reply_markup);
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

send_message_request_t *send_message_request_parseFromJSON(cJSON *send_message_requestJSON){

    send_message_request_t *send_message_request_local_var = NULL;

    // define the local variable for send_message_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for send_message_request->entities
    list_t *entitiesList = NULL;

    // define the local variable for send_message_request->link_preview_options
    link_preview_options_t *link_preview_options_local_nonprim = NULL;

    // define the local variable for send_message_request->reply_parameters
    reply_parameters_t *reply_parameters_local_nonprim = NULL;

    // define the local variable for send_message_request->reply_markup
    send_message_request_reply_markup_t *reply_markup_local_nonprim = NULL;

    // send_message_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(send_message_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // send_message_request->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(send_message_requestJSON, "text");
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

    // send_message_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(send_message_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // send_message_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(send_message_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // send_message_request->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(send_message_requestJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // send_message_request->entities
    cJSON *entities = cJSON_GetObjectItemCaseSensitive(send_message_requestJSON, "entities");
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

    // send_message_request->link_preview_options
    cJSON *link_preview_options = cJSON_GetObjectItemCaseSensitive(send_message_requestJSON, "link_preview_options");
    if (cJSON_IsNull(link_preview_options)) {
        link_preview_options = NULL;
    }
    if (link_preview_options) { 
    link_preview_options_local_nonprim = link_preview_options_parseFromJSON(link_preview_options); //nonprimitive
    }

    // send_message_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(send_message_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // send_message_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(send_message_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }

    // send_message_request->allow_paid_broadcast
    cJSON *allow_paid_broadcast = cJSON_GetObjectItemCaseSensitive(send_message_requestJSON, "allow_paid_broadcast");
    if (cJSON_IsNull(allow_paid_broadcast)) {
        allow_paid_broadcast = NULL;
    }
    if (allow_paid_broadcast) { 
    if(!cJSON_IsBool(allow_paid_broadcast))
    {
    goto end; //Bool
    }
    }

    // send_message_request->message_effect_id
    cJSON *message_effect_id = cJSON_GetObjectItemCaseSensitive(send_message_requestJSON, "message_effect_id");
    if (cJSON_IsNull(message_effect_id)) {
        message_effect_id = NULL;
    }
    if (message_effect_id) { 
    if(!cJSON_IsString(message_effect_id) && !cJSON_IsNull(message_effect_id))
    {
    goto end; //String
    }
    }

    // send_message_request->reply_parameters
    cJSON *reply_parameters = cJSON_GetObjectItemCaseSensitive(send_message_requestJSON, "reply_parameters");
    if (cJSON_IsNull(reply_parameters)) {
        reply_parameters = NULL;
    }
    if (reply_parameters) { 
    reply_parameters_local_nonprim = reply_parameters_parseFromJSON(reply_parameters); //nonprimitive
    }

    // send_message_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(send_message_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = send_message_request_reply_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    send_message_request_local_var = send_message_request_create_internal (
        chat_id_local_nonprim,
        strdup(text->valuestring),
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        message_thread_id ? message_thread_id->valuedouble : 0,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        entities ? entitiesList : NULL,
        link_preview_options ? link_preview_options_local_nonprim : NULL,
        disable_notification ? disable_notification->valueint : 0,
        protect_content ? protect_content->valueint : 0,
        allow_paid_broadcast ? allow_paid_broadcast->valueint : 0,
        message_effect_id && !cJSON_IsNull(message_effect_id) ? strdup(message_effect_id->valuestring) : NULL,
        reply_parameters ? reply_parameters_local_nonprim : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return send_message_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
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
    if (reply_parameters_local_nonprim) {
        reply_parameters_free(reply_parameters_local_nonprim);
        reply_parameters_local_nonprim = NULL;
    }
    if (reply_markup_local_nonprim) {
        send_message_request_reply_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    return NULL;

}
