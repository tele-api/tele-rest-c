#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_voice_request.h"



static send_voice_request_t *send_voice_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    char *voice,
    char *business_connection_id,
    int message_thread_id,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int duration,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
    ) {
    send_voice_request_t *send_voice_request_local_var = malloc(sizeof(send_voice_request_t));
    if (!send_voice_request_local_var) {
        return NULL;
    }
    send_voice_request_local_var->chat_id = chat_id;
    send_voice_request_local_var->voice = voice;
    send_voice_request_local_var->business_connection_id = business_connection_id;
    send_voice_request_local_var->message_thread_id = message_thread_id;
    send_voice_request_local_var->caption = caption;
    send_voice_request_local_var->parse_mode = parse_mode;
    send_voice_request_local_var->caption_entities = caption_entities;
    send_voice_request_local_var->duration = duration;
    send_voice_request_local_var->disable_notification = disable_notification;
    send_voice_request_local_var->protect_content = protect_content;
    send_voice_request_local_var->allow_paid_broadcast = allow_paid_broadcast;
    send_voice_request_local_var->message_effect_id = message_effect_id;
    send_voice_request_local_var->reply_parameters = reply_parameters;
    send_voice_request_local_var->reply_markup = reply_markup;

    send_voice_request_local_var->_library_owned = 1;
    return send_voice_request_local_var;
}

__attribute__((deprecated)) send_voice_request_t *send_voice_request_create(
    send_message_request_chat_id_t *chat_id,
    char *voice,
    char *business_connection_id,
    int message_thread_id,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int duration,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
    ) {
    return send_voice_request_create_internal (
        chat_id,
        voice,
        business_connection_id,
        message_thread_id,
        caption,
        parse_mode,
        caption_entities,
        duration,
        disable_notification,
        protect_content,
        allow_paid_broadcast,
        message_effect_id,
        reply_parameters,
        reply_markup
        );
}

void send_voice_request_free(send_voice_request_t *send_voice_request) {
    if(NULL == send_voice_request){
        return ;
    }
    if(send_voice_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_voice_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (send_voice_request->chat_id) {
        send_message_request_chat_id_free(send_voice_request->chat_id);
        send_voice_request->chat_id = NULL;
    }
    if (send_voice_request->voice) {
        free(send_voice_request->voice);
        send_voice_request->voice = NULL;
    }
    if (send_voice_request->business_connection_id) {
        free(send_voice_request->business_connection_id);
        send_voice_request->business_connection_id = NULL;
    }
    if (send_voice_request->caption) {
        free(send_voice_request->caption);
        send_voice_request->caption = NULL;
    }
    if (send_voice_request->parse_mode) {
        free(send_voice_request->parse_mode);
        send_voice_request->parse_mode = NULL;
    }
    if (send_voice_request->caption_entities) {
        list_ForEach(listEntry, send_voice_request->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(send_voice_request->caption_entities);
        send_voice_request->caption_entities = NULL;
    }
    if (send_voice_request->message_effect_id) {
        free(send_voice_request->message_effect_id);
        send_voice_request->message_effect_id = NULL;
    }
    if (send_voice_request->reply_parameters) {
        reply_parameters_free(send_voice_request->reply_parameters);
        send_voice_request->reply_parameters = NULL;
    }
    if (send_voice_request->reply_markup) {
        send_message_request_reply_markup_free(send_voice_request->reply_markup);
        send_voice_request->reply_markup = NULL;
    }
    free(send_voice_request);
}

cJSON *send_voice_request_convertToJSON(send_voice_request_t *send_voice_request) {
    cJSON *item = cJSON_CreateObject();

    // send_voice_request->chat_id
    if (!send_voice_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(send_voice_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // send_voice_request->voice
    if (!send_voice_request->voice) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "voice", send_voice_request->voice) == NULL) {
    goto fail; //String
    }


    // send_voice_request->business_connection_id
    if(send_voice_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", send_voice_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // send_voice_request->message_thread_id
    if(send_voice_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", send_voice_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // send_voice_request->caption
    if(send_voice_request->caption) {
    if(cJSON_AddStringToObject(item, "caption", send_voice_request->caption) == NULL) {
    goto fail; //String
    }
    }


    // send_voice_request->parse_mode
    if(send_voice_request->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", send_voice_request->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // send_voice_request->caption_entities
    if(send_voice_request->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (send_voice_request->caption_entities) {
    list_ForEach(caption_entitiesListEntry, send_voice_request->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // send_voice_request->duration
    if(send_voice_request->duration) {
    if(cJSON_AddNumberToObject(item, "duration", send_voice_request->duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // send_voice_request->disable_notification
    if(send_voice_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", send_voice_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // send_voice_request->protect_content
    if(send_voice_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", send_voice_request->protect_content) == NULL) {
    goto fail; //Bool
    }
    }


    // send_voice_request->allow_paid_broadcast
    if(send_voice_request->allow_paid_broadcast) {
    if(cJSON_AddBoolToObject(item, "allow_paid_broadcast", send_voice_request->allow_paid_broadcast) == NULL) {
    goto fail; //Bool
    }
    }


    // send_voice_request->message_effect_id
    if(send_voice_request->message_effect_id) {
    if(cJSON_AddStringToObject(item, "message_effect_id", send_voice_request->message_effect_id) == NULL) {
    goto fail; //String
    }
    }


    // send_voice_request->reply_parameters
    if(send_voice_request->reply_parameters) {
    cJSON *reply_parameters_local_JSON = reply_parameters_convertToJSON(send_voice_request->reply_parameters);
    if(reply_parameters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_parameters", reply_parameters_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // send_voice_request->reply_markup
    if(send_voice_request->reply_markup) {
    cJSON *reply_markup_local_JSON = send_message_request_reply_markup_convertToJSON(send_voice_request->reply_markup);
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

send_voice_request_t *send_voice_request_parseFromJSON(cJSON *send_voice_requestJSON){

    send_voice_request_t *send_voice_request_local_var = NULL;

    // define the local variable for send_voice_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for send_voice_request->caption_entities
    list_t *caption_entitiesList = NULL;

    // define the local variable for send_voice_request->reply_parameters
    reply_parameters_t *reply_parameters_local_nonprim = NULL;

    // define the local variable for send_voice_request->reply_markup
    send_message_request_reply_markup_t *reply_markup_local_nonprim = NULL;

    // send_voice_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(send_voice_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // send_voice_request->voice
    cJSON *voice = cJSON_GetObjectItemCaseSensitive(send_voice_requestJSON, "voice");
    if (cJSON_IsNull(voice)) {
        voice = NULL;
    }
    if (!voice) {
        goto end;
    }

    
    if(!cJSON_IsString(voice))
    {
    goto end; //String
    }

    // send_voice_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(send_voice_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // send_voice_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(send_voice_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // send_voice_request->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(send_voice_requestJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // send_voice_request->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(send_voice_requestJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // send_voice_request->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(send_voice_requestJSON, "caption_entities");
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

    // send_voice_request->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(send_voice_requestJSON, "duration");
    if (cJSON_IsNull(duration)) {
        duration = NULL;
    }
    if (duration) { 
    if(!cJSON_IsNumber(duration))
    {
    goto end; //Numeric
    }
    }

    // send_voice_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(send_voice_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // send_voice_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(send_voice_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }

    // send_voice_request->allow_paid_broadcast
    cJSON *allow_paid_broadcast = cJSON_GetObjectItemCaseSensitive(send_voice_requestJSON, "allow_paid_broadcast");
    if (cJSON_IsNull(allow_paid_broadcast)) {
        allow_paid_broadcast = NULL;
    }
    if (allow_paid_broadcast) { 
    if(!cJSON_IsBool(allow_paid_broadcast))
    {
    goto end; //Bool
    }
    }

    // send_voice_request->message_effect_id
    cJSON *message_effect_id = cJSON_GetObjectItemCaseSensitive(send_voice_requestJSON, "message_effect_id");
    if (cJSON_IsNull(message_effect_id)) {
        message_effect_id = NULL;
    }
    if (message_effect_id) { 
    if(!cJSON_IsString(message_effect_id) && !cJSON_IsNull(message_effect_id))
    {
    goto end; //String
    }
    }

    // send_voice_request->reply_parameters
    cJSON *reply_parameters = cJSON_GetObjectItemCaseSensitive(send_voice_requestJSON, "reply_parameters");
    if (cJSON_IsNull(reply_parameters)) {
        reply_parameters = NULL;
    }
    if (reply_parameters) { 
    reply_parameters_local_nonprim = reply_parameters_parseFromJSON(reply_parameters); //nonprimitive
    }

    // send_voice_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(send_voice_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = send_message_request_reply_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    send_voice_request_local_var = send_voice_request_create_internal (
        chat_id_local_nonprim,
        strdup(voice->valuestring),
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        message_thread_id ? message_thread_id->valuedouble : 0,
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        duration ? duration->valuedouble : 0,
        disable_notification ? disable_notification->valueint : 0,
        protect_content ? protect_content->valueint : 0,
        allow_paid_broadcast ? allow_paid_broadcast->valueint : 0,
        message_effect_id && !cJSON_IsNull(message_effect_id) ? strdup(message_effect_id->valuestring) : NULL,
        reply_parameters ? reply_parameters_local_nonprim : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return send_voice_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
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
