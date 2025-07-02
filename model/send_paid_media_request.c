#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_paid_media_request.h"



static send_paid_media_request_t *send_paid_media_request_create_internal(
    send_paid_media_request_chat_id_t *chat_id,
    int star_count,
    list_t *media,
    char *business_connection_id,
    char *payload,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
    ) {
    send_paid_media_request_t *send_paid_media_request_local_var = malloc(sizeof(send_paid_media_request_t));
    if (!send_paid_media_request_local_var) {
        return NULL;
    }
    send_paid_media_request_local_var->chat_id = chat_id;
    send_paid_media_request_local_var->star_count = star_count;
    send_paid_media_request_local_var->media = media;
    send_paid_media_request_local_var->business_connection_id = business_connection_id;
    send_paid_media_request_local_var->payload = payload;
    send_paid_media_request_local_var->caption = caption;
    send_paid_media_request_local_var->parse_mode = parse_mode;
    send_paid_media_request_local_var->caption_entities = caption_entities;
    send_paid_media_request_local_var->show_caption_above_media = show_caption_above_media;
    send_paid_media_request_local_var->disable_notification = disable_notification;
    send_paid_media_request_local_var->protect_content = protect_content;
    send_paid_media_request_local_var->allow_paid_broadcast = allow_paid_broadcast;
    send_paid_media_request_local_var->reply_parameters = reply_parameters;
    send_paid_media_request_local_var->reply_markup = reply_markup;

    send_paid_media_request_local_var->_library_owned = 1;
    return send_paid_media_request_local_var;
}

__attribute__((deprecated)) send_paid_media_request_t *send_paid_media_request_create(
    send_paid_media_request_chat_id_t *chat_id,
    int star_count,
    list_t *media,
    char *business_connection_id,
    char *payload,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
    ) {
    return send_paid_media_request_create_internal (
        chat_id,
        star_count,
        media,
        business_connection_id,
        payload,
        caption,
        parse_mode,
        caption_entities,
        show_caption_above_media,
        disable_notification,
        protect_content,
        allow_paid_broadcast,
        reply_parameters,
        reply_markup
        );
}

void send_paid_media_request_free(send_paid_media_request_t *send_paid_media_request) {
    if(NULL == send_paid_media_request){
        return ;
    }
    if(send_paid_media_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_paid_media_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (send_paid_media_request->chat_id) {
        send_paid_media_request_chat_id_free(send_paid_media_request->chat_id);
        send_paid_media_request->chat_id = NULL;
    }
    if (send_paid_media_request->media) {
        list_ForEach(listEntry, send_paid_media_request->media) {
            input_paid_media_free(listEntry->data);
        }
        list_freeList(send_paid_media_request->media);
        send_paid_media_request->media = NULL;
    }
    if (send_paid_media_request->business_connection_id) {
        free(send_paid_media_request->business_connection_id);
        send_paid_media_request->business_connection_id = NULL;
    }
    if (send_paid_media_request->payload) {
        free(send_paid_media_request->payload);
        send_paid_media_request->payload = NULL;
    }
    if (send_paid_media_request->caption) {
        free(send_paid_media_request->caption);
        send_paid_media_request->caption = NULL;
    }
    if (send_paid_media_request->parse_mode) {
        free(send_paid_media_request->parse_mode);
        send_paid_media_request->parse_mode = NULL;
    }
    if (send_paid_media_request->caption_entities) {
        list_ForEach(listEntry, send_paid_media_request->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(send_paid_media_request->caption_entities);
        send_paid_media_request->caption_entities = NULL;
    }
    if (send_paid_media_request->reply_parameters) {
        reply_parameters_free(send_paid_media_request->reply_parameters);
        send_paid_media_request->reply_parameters = NULL;
    }
    if (send_paid_media_request->reply_markup) {
        send_message_request_reply_markup_free(send_paid_media_request->reply_markup);
        send_paid_media_request->reply_markup = NULL;
    }
    free(send_paid_media_request);
}

cJSON *send_paid_media_request_convertToJSON(send_paid_media_request_t *send_paid_media_request) {
    cJSON *item = cJSON_CreateObject();

    // send_paid_media_request->chat_id
    if (!send_paid_media_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_paid_media_request_chat_id_convertToJSON(send_paid_media_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // send_paid_media_request->star_count
    if (!send_paid_media_request->star_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "star_count", send_paid_media_request->star_count) == NULL) {
    goto fail; //Numeric
    }


    // send_paid_media_request->media
    if (!send_paid_media_request->media) {
        goto fail;
    }
    cJSON *media = cJSON_AddArrayToObject(item, "media");
    if(media == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *mediaListEntry;
    if (send_paid_media_request->media) {
    list_ForEach(mediaListEntry, send_paid_media_request->media) {
    cJSON *itemLocal = input_paid_media_convertToJSON(mediaListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(media, itemLocal);
    }
    }


    // send_paid_media_request->business_connection_id
    if(send_paid_media_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", send_paid_media_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // send_paid_media_request->payload
    if(send_paid_media_request->payload) {
    if(cJSON_AddStringToObject(item, "payload", send_paid_media_request->payload) == NULL) {
    goto fail; //String
    }
    }


    // send_paid_media_request->caption
    if(send_paid_media_request->caption) {
    if(cJSON_AddStringToObject(item, "caption", send_paid_media_request->caption) == NULL) {
    goto fail; //String
    }
    }


    // send_paid_media_request->parse_mode
    if(send_paid_media_request->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", send_paid_media_request->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // send_paid_media_request->caption_entities
    if(send_paid_media_request->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (send_paid_media_request->caption_entities) {
    list_ForEach(caption_entitiesListEntry, send_paid_media_request->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // send_paid_media_request->show_caption_above_media
    if(send_paid_media_request->show_caption_above_media) {
    if(cJSON_AddBoolToObject(item, "show_caption_above_media", send_paid_media_request->show_caption_above_media) == NULL) {
    goto fail; //Bool
    }
    }


    // send_paid_media_request->disable_notification
    if(send_paid_media_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", send_paid_media_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // send_paid_media_request->protect_content
    if(send_paid_media_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", send_paid_media_request->protect_content) == NULL) {
    goto fail; //Bool
    }
    }


    // send_paid_media_request->allow_paid_broadcast
    if(send_paid_media_request->allow_paid_broadcast) {
    if(cJSON_AddBoolToObject(item, "allow_paid_broadcast", send_paid_media_request->allow_paid_broadcast) == NULL) {
    goto fail; //Bool
    }
    }


    // send_paid_media_request->reply_parameters
    if(send_paid_media_request->reply_parameters) {
    cJSON *reply_parameters_local_JSON = reply_parameters_convertToJSON(send_paid_media_request->reply_parameters);
    if(reply_parameters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_parameters", reply_parameters_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // send_paid_media_request->reply_markup
    if(send_paid_media_request->reply_markup) {
    cJSON *reply_markup_local_JSON = send_message_request_reply_markup_convertToJSON(send_paid_media_request->reply_markup);
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

send_paid_media_request_t *send_paid_media_request_parseFromJSON(cJSON *send_paid_media_requestJSON){

    send_paid_media_request_t *send_paid_media_request_local_var = NULL;

    // define the local variable for send_paid_media_request->chat_id
    send_paid_media_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for send_paid_media_request->media
    list_t *mediaList = NULL;

    // define the local list for send_paid_media_request->caption_entities
    list_t *caption_entitiesList = NULL;

    // define the local variable for send_paid_media_request->reply_parameters
    reply_parameters_t *reply_parameters_local_nonprim = NULL;

    // define the local variable for send_paid_media_request->reply_markup
    send_message_request_reply_markup_t *reply_markup_local_nonprim = NULL;

    // send_paid_media_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(send_paid_media_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_paid_media_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // send_paid_media_request->star_count
    cJSON *star_count = cJSON_GetObjectItemCaseSensitive(send_paid_media_requestJSON, "star_count");
    if (cJSON_IsNull(star_count)) {
        star_count = NULL;
    }
    if (!star_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(star_count))
    {
    goto end; //Numeric
    }

    // send_paid_media_request->media
    cJSON *media = cJSON_GetObjectItemCaseSensitive(send_paid_media_requestJSON, "media");
    if (cJSON_IsNull(media)) {
        media = NULL;
    }
    if (!media) {
        goto end;
    }

    
    cJSON *media_local_nonprimitive = NULL;
    if(!cJSON_IsArray(media)){
        goto end; //nonprimitive container
    }

    mediaList = list_createList();

    cJSON_ArrayForEach(media_local_nonprimitive,media )
    {
        if(!cJSON_IsObject(media_local_nonprimitive)){
            goto end;
        }
        input_paid_media_t *mediaItem = input_paid_media_parseFromJSON(media_local_nonprimitive);

        list_addElement(mediaList, mediaItem);
    }

    // send_paid_media_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(send_paid_media_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // send_paid_media_request->payload
    cJSON *payload = cJSON_GetObjectItemCaseSensitive(send_paid_media_requestJSON, "payload");
    if (cJSON_IsNull(payload)) {
        payload = NULL;
    }
    if (payload) { 
    if(!cJSON_IsString(payload) && !cJSON_IsNull(payload))
    {
    goto end; //String
    }
    }

    // send_paid_media_request->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(send_paid_media_requestJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // send_paid_media_request->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(send_paid_media_requestJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // send_paid_media_request->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(send_paid_media_requestJSON, "caption_entities");
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

    // send_paid_media_request->show_caption_above_media
    cJSON *show_caption_above_media = cJSON_GetObjectItemCaseSensitive(send_paid_media_requestJSON, "show_caption_above_media");
    if (cJSON_IsNull(show_caption_above_media)) {
        show_caption_above_media = NULL;
    }
    if (show_caption_above_media) { 
    if(!cJSON_IsBool(show_caption_above_media))
    {
    goto end; //Bool
    }
    }

    // send_paid_media_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(send_paid_media_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // send_paid_media_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(send_paid_media_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }

    // send_paid_media_request->allow_paid_broadcast
    cJSON *allow_paid_broadcast = cJSON_GetObjectItemCaseSensitive(send_paid_media_requestJSON, "allow_paid_broadcast");
    if (cJSON_IsNull(allow_paid_broadcast)) {
        allow_paid_broadcast = NULL;
    }
    if (allow_paid_broadcast) { 
    if(!cJSON_IsBool(allow_paid_broadcast))
    {
    goto end; //Bool
    }
    }

    // send_paid_media_request->reply_parameters
    cJSON *reply_parameters = cJSON_GetObjectItemCaseSensitive(send_paid_media_requestJSON, "reply_parameters");
    if (cJSON_IsNull(reply_parameters)) {
        reply_parameters = NULL;
    }
    if (reply_parameters) { 
    reply_parameters_local_nonprim = reply_parameters_parseFromJSON(reply_parameters); //nonprimitive
    }

    // send_paid_media_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(send_paid_media_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = send_message_request_reply_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    send_paid_media_request_local_var = send_paid_media_request_create_internal (
        chat_id_local_nonprim,
        star_count->valuedouble,
        mediaList,
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        payload && !cJSON_IsNull(payload) ? strdup(payload->valuestring) : NULL,
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        show_caption_above_media ? show_caption_above_media->valueint : 0,
        disable_notification ? disable_notification->valueint : 0,
        protect_content ? protect_content->valueint : 0,
        allow_paid_broadcast ? allow_paid_broadcast->valueint : 0,
        reply_parameters ? reply_parameters_local_nonprim : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return send_paid_media_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_paid_media_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (mediaList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, mediaList) {
            input_paid_media_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(mediaList);
        mediaList = NULL;
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
