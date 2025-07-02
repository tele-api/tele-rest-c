#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_media_group_request.h"



static send_media_group_request_t *send_media_group_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    list_t *media,
    char *business_connection_id,
    int message_thread_id,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters
    ) {
    send_media_group_request_t *send_media_group_request_local_var = malloc(sizeof(send_media_group_request_t));
    if (!send_media_group_request_local_var) {
        return NULL;
    }
    send_media_group_request_local_var->chat_id = chat_id;
    send_media_group_request_local_var->media = media;
    send_media_group_request_local_var->business_connection_id = business_connection_id;
    send_media_group_request_local_var->message_thread_id = message_thread_id;
    send_media_group_request_local_var->disable_notification = disable_notification;
    send_media_group_request_local_var->protect_content = protect_content;
    send_media_group_request_local_var->allow_paid_broadcast = allow_paid_broadcast;
    send_media_group_request_local_var->message_effect_id = message_effect_id;
    send_media_group_request_local_var->reply_parameters = reply_parameters;

    send_media_group_request_local_var->_library_owned = 1;
    return send_media_group_request_local_var;
}

__attribute__((deprecated)) send_media_group_request_t *send_media_group_request_create(
    send_message_request_chat_id_t *chat_id,
    list_t *media,
    char *business_connection_id,
    int message_thread_id,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters
    ) {
    return send_media_group_request_create_internal (
        chat_id,
        media,
        business_connection_id,
        message_thread_id,
        disable_notification,
        protect_content,
        allow_paid_broadcast,
        message_effect_id,
        reply_parameters
        );
}

void send_media_group_request_free(send_media_group_request_t *send_media_group_request) {
    if(NULL == send_media_group_request){
        return ;
    }
    if(send_media_group_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_media_group_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (send_media_group_request->chat_id) {
        send_message_request_chat_id_free(send_media_group_request->chat_id);
        send_media_group_request->chat_id = NULL;
    }
    if (send_media_group_request->media) {
        list_ForEach(listEntry, send_media_group_request->media) {
            send_media_group_request_media_inner_free(listEntry->data);
        }
        list_freeList(send_media_group_request->media);
        send_media_group_request->media = NULL;
    }
    if (send_media_group_request->business_connection_id) {
        free(send_media_group_request->business_connection_id);
        send_media_group_request->business_connection_id = NULL;
    }
    if (send_media_group_request->message_effect_id) {
        free(send_media_group_request->message_effect_id);
        send_media_group_request->message_effect_id = NULL;
    }
    if (send_media_group_request->reply_parameters) {
        reply_parameters_free(send_media_group_request->reply_parameters);
        send_media_group_request->reply_parameters = NULL;
    }
    free(send_media_group_request);
}

cJSON *send_media_group_request_convertToJSON(send_media_group_request_t *send_media_group_request) {
    cJSON *item = cJSON_CreateObject();

    // send_media_group_request->chat_id
    if (!send_media_group_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(send_media_group_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // send_media_group_request->media
    if (!send_media_group_request->media) {
        goto fail;
    }
    cJSON *media = cJSON_AddArrayToObject(item, "media");
    if(media == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *mediaListEntry;
    if (send_media_group_request->media) {
    list_ForEach(mediaListEntry, send_media_group_request->media) {
    cJSON *itemLocal = send_media_group_request_media_inner_convertToJSON(mediaListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(media, itemLocal);
    }
    }


    // send_media_group_request->business_connection_id
    if(send_media_group_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", send_media_group_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // send_media_group_request->message_thread_id
    if(send_media_group_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", send_media_group_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // send_media_group_request->disable_notification
    if(send_media_group_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", send_media_group_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // send_media_group_request->protect_content
    if(send_media_group_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", send_media_group_request->protect_content) == NULL) {
    goto fail; //Bool
    }
    }


    // send_media_group_request->allow_paid_broadcast
    if(send_media_group_request->allow_paid_broadcast) {
    if(cJSON_AddBoolToObject(item, "allow_paid_broadcast", send_media_group_request->allow_paid_broadcast) == NULL) {
    goto fail; //Bool
    }
    }


    // send_media_group_request->message_effect_id
    if(send_media_group_request->message_effect_id) {
    if(cJSON_AddStringToObject(item, "message_effect_id", send_media_group_request->message_effect_id) == NULL) {
    goto fail; //String
    }
    }


    // send_media_group_request->reply_parameters
    if(send_media_group_request->reply_parameters) {
    cJSON *reply_parameters_local_JSON = reply_parameters_convertToJSON(send_media_group_request->reply_parameters);
    if(reply_parameters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_parameters", reply_parameters_local_JSON);
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

send_media_group_request_t *send_media_group_request_parseFromJSON(cJSON *send_media_group_requestJSON){

    send_media_group_request_t *send_media_group_request_local_var = NULL;

    // define the local variable for send_media_group_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for send_media_group_request->media
    list_t *mediaList = NULL;

    // define the local variable for send_media_group_request->reply_parameters
    reply_parameters_t *reply_parameters_local_nonprim = NULL;

    // send_media_group_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(send_media_group_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // send_media_group_request->media
    cJSON *media = cJSON_GetObjectItemCaseSensitive(send_media_group_requestJSON, "media");
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
        send_media_group_request_media_inner_t *mediaItem = send_media_group_request_media_inner_parseFromJSON(media_local_nonprimitive);

        list_addElement(mediaList, mediaItem);
    }

    // send_media_group_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(send_media_group_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // send_media_group_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(send_media_group_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // send_media_group_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(send_media_group_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // send_media_group_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(send_media_group_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }

    // send_media_group_request->allow_paid_broadcast
    cJSON *allow_paid_broadcast = cJSON_GetObjectItemCaseSensitive(send_media_group_requestJSON, "allow_paid_broadcast");
    if (cJSON_IsNull(allow_paid_broadcast)) {
        allow_paid_broadcast = NULL;
    }
    if (allow_paid_broadcast) { 
    if(!cJSON_IsBool(allow_paid_broadcast))
    {
    goto end; //Bool
    }
    }

    // send_media_group_request->message_effect_id
    cJSON *message_effect_id = cJSON_GetObjectItemCaseSensitive(send_media_group_requestJSON, "message_effect_id");
    if (cJSON_IsNull(message_effect_id)) {
        message_effect_id = NULL;
    }
    if (message_effect_id) { 
    if(!cJSON_IsString(message_effect_id) && !cJSON_IsNull(message_effect_id))
    {
    goto end; //String
    }
    }

    // send_media_group_request->reply_parameters
    cJSON *reply_parameters = cJSON_GetObjectItemCaseSensitive(send_media_group_requestJSON, "reply_parameters");
    if (cJSON_IsNull(reply_parameters)) {
        reply_parameters = NULL;
    }
    if (reply_parameters) { 
    reply_parameters_local_nonprim = reply_parameters_parseFromJSON(reply_parameters); //nonprimitive
    }


    send_media_group_request_local_var = send_media_group_request_create_internal (
        chat_id_local_nonprim,
        mediaList,
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        message_thread_id ? message_thread_id->valuedouble : 0,
        disable_notification ? disable_notification->valueint : 0,
        protect_content ? protect_content->valueint : 0,
        allow_paid_broadcast ? allow_paid_broadcast->valueint : 0,
        message_effect_id && !cJSON_IsNull(message_effect_id) ? strdup(message_effect_id->valuestring) : NULL,
        reply_parameters ? reply_parameters_local_nonprim : NULL
        );

    return send_media_group_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (mediaList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, mediaList) {
            send_media_group_request_media_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(mediaList);
        mediaList = NULL;
    }
    if (reply_parameters_local_nonprim) {
        reply_parameters_free(reply_parameters_local_nonprim);
        reply_parameters_local_nonprim = NULL;
    }
    return NULL;

}
