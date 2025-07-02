#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_sticker_request.h"



static send_sticker_request_t *send_sticker_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    char *sticker,
    char *business_connection_id,
    int message_thread_id,
    char *emoji,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
    ) {
    send_sticker_request_t *send_sticker_request_local_var = malloc(sizeof(send_sticker_request_t));
    if (!send_sticker_request_local_var) {
        return NULL;
    }
    send_sticker_request_local_var->chat_id = chat_id;
    send_sticker_request_local_var->sticker = sticker;
    send_sticker_request_local_var->business_connection_id = business_connection_id;
    send_sticker_request_local_var->message_thread_id = message_thread_id;
    send_sticker_request_local_var->emoji = emoji;
    send_sticker_request_local_var->disable_notification = disable_notification;
    send_sticker_request_local_var->protect_content = protect_content;
    send_sticker_request_local_var->allow_paid_broadcast = allow_paid_broadcast;
    send_sticker_request_local_var->message_effect_id = message_effect_id;
    send_sticker_request_local_var->reply_parameters = reply_parameters;
    send_sticker_request_local_var->reply_markup = reply_markup;

    send_sticker_request_local_var->_library_owned = 1;
    return send_sticker_request_local_var;
}

__attribute__((deprecated)) send_sticker_request_t *send_sticker_request_create(
    send_message_request_chat_id_t *chat_id,
    char *sticker,
    char *business_connection_id,
    int message_thread_id,
    char *emoji,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
    ) {
    return send_sticker_request_create_internal (
        chat_id,
        sticker,
        business_connection_id,
        message_thread_id,
        emoji,
        disable_notification,
        protect_content,
        allow_paid_broadcast,
        message_effect_id,
        reply_parameters,
        reply_markup
        );
}

void send_sticker_request_free(send_sticker_request_t *send_sticker_request) {
    if(NULL == send_sticker_request){
        return ;
    }
    if(send_sticker_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_sticker_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (send_sticker_request->chat_id) {
        send_message_request_chat_id_free(send_sticker_request->chat_id);
        send_sticker_request->chat_id = NULL;
    }
    if (send_sticker_request->sticker) {
        free(send_sticker_request->sticker);
        send_sticker_request->sticker = NULL;
    }
    if (send_sticker_request->business_connection_id) {
        free(send_sticker_request->business_connection_id);
        send_sticker_request->business_connection_id = NULL;
    }
    if (send_sticker_request->emoji) {
        free(send_sticker_request->emoji);
        send_sticker_request->emoji = NULL;
    }
    if (send_sticker_request->message_effect_id) {
        free(send_sticker_request->message_effect_id);
        send_sticker_request->message_effect_id = NULL;
    }
    if (send_sticker_request->reply_parameters) {
        reply_parameters_free(send_sticker_request->reply_parameters);
        send_sticker_request->reply_parameters = NULL;
    }
    if (send_sticker_request->reply_markup) {
        send_message_request_reply_markup_free(send_sticker_request->reply_markup);
        send_sticker_request->reply_markup = NULL;
    }
    free(send_sticker_request);
}

cJSON *send_sticker_request_convertToJSON(send_sticker_request_t *send_sticker_request) {
    cJSON *item = cJSON_CreateObject();

    // send_sticker_request->chat_id
    if (!send_sticker_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(send_sticker_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // send_sticker_request->sticker
    if (!send_sticker_request->sticker) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker", send_sticker_request->sticker) == NULL) {
    goto fail; //String
    }


    // send_sticker_request->business_connection_id
    if(send_sticker_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", send_sticker_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // send_sticker_request->message_thread_id
    if(send_sticker_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", send_sticker_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // send_sticker_request->emoji
    if(send_sticker_request->emoji) {
    if(cJSON_AddStringToObject(item, "emoji", send_sticker_request->emoji) == NULL) {
    goto fail; //String
    }
    }


    // send_sticker_request->disable_notification
    if(send_sticker_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", send_sticker_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // send_sticker_request->protect_content
    if(send_sticker_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", send_sticker_request->protect_content) == NULL) {
    goto fail; //Bool
    }
    }


    // send_sticker_request->allow_paid_broadcast
    if(send_sticker_request->allow_paid_broadcast) {
    if(cJSON_AddBoolToObject(item, "allow_paid_broadcast", send_sticker_request->allow_paid_broadcast) == NULL) {
    goto fail; //Bool
    }
    }


    // send_sticker_request->message_effect_id
    if(send_sticker_request->message_effect_id) {
    if(cJSON_AddStringToObject(item, "message_effect_id", send_sticker_request->message_effect_id) == NULL) {
    goto fail; //String
    }
    }


    // send_sticker_request->reply_parameters
    if(send_sticker_request->reply_parameters) {
    cJSON *reply_parameters_local_JSON = reply_parameters_convertToJSON(send_sticker_request->reply_parameters);
    if(reply_parameters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_parameters", reply_parameters_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // send_sticker_request->reply_markup
    if(send_sticker_request->reply_markup) {
    cJSON *reply_markup_local_JSON = send_message_request_reply_markup_convertToJSON(send_sticker_request->reply_markup);
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

send_sticker_request_t *send_sticker_request_parseFromJSON(cJSON *send_sticker_requestJSON){

    send_sticker_request_t *send_sticker_request_local_var = NULL;

    // define the local variable for send_sticker_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for send_sticker_request->reply_parameters
    reply_parameters_t *reply_parameters_local_nonprim = NULL;

    // define the local variable for send_sticker_request->reply_markup
    send_message_request_reply_markup_t *reply_markup_local_nonprim = NULL;

    // send_sticker_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(send_sticker_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // send_sticker_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(send_sticker_requestJSON, "sticker");
    if (cJSON_IsNull(sticker)) {
        sticker = NULL;
    }
    if (!sticker) {
        goto end;
    }

    
    if(!cJSON_IsString(sticker))
    {
    goto end; //String
    }

    // send_sticker_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(send_sticker_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // send_sticker_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(send_sticker_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // send_sticker_request->emoji
    cJSON *emoji = cJSON_GetObjectItemCaseSensitive(send_sticker_requestJSON, "emoji");
    if (cJSON_IsNull(emoji)) {
        emoji = NULL;
    }
    if (emoji) { 
    if(!cJSON_IsString(emoji) && !cJSON_IsNull(emoji))
    {
    goto end; //String
    }
    }

    // send_sticker_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(send_sticker_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // send_sticker_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(send_sticker_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }

    // send_sticker_request->allow_paid_broadcast
    cJSON *allow_paid_broadcast = cJSON_GetObjectItemCaseSensitive(send_sticker_requestJSON, "allow_paid_broadcast");
    if (cJSON_IsNull(allow_paid_broadcast)) {
        allow_paid_broadcast = NULL;
    }
    if (allow_paid_broadcast) { 
    if(!cJSON_IsBool(allow_paid_broadcast))
    {
    goto end; //Bool
    }
    }

    // send_sticker_request->message_effect_id
    cJSON *message_effect_id = cJSON_GetObjectItemCaseSensitive(send_sticker_requestJSON, "message_effect_id");
    if (cJSON_IsNull(message_effect_id)) {
        message_effect_id = NULL;
    }
    if (message_effect_id) { 
    if(!cJSON_IsString(message_effect_id) && !cJSON_IsNull(message_effect_id))
    {
    goto end; //String
    }
    }

    // send_sticker_request->reply_parameters
    cJSON *reply_parameters = cJSON_GetObjectItemCaseSensitive(send_sticker_requestJSON, "reply_parameters");
    if (cJSON_IsNull(reply_parameters)) {
        reply_parameters = NULL;
    }
    if (reply_parameters) { 
    reply_parameters_local_nonprim = reply_parameters_parseFromJSON(reply_parameters); //nonprimitive
    }

    // send_sticker_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(send_sticker_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = send_message_request_reply_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    send_sticker_request_local_var = send_sticker_request_create_internal (
        chat_id_local_nonprim,
        strdup(sticker->valuestring),
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        message_thread_id ? message_thread_id->valuedouble : 0,
        emoji && !cJSON_IsNull(emoji) ? strdup(emoji->valuestring) : NULL,
        disable_notification ? disable_notification->valueint : 0,
        protect_content ? protect_content->valueint : 0,
        allow_paid_broadcast ? allow_paid_broadcast->valueint : 0,
        message_effect_id && !cJSON_IsNull(message_effect_id) ? strdup(message_effect_id->valuestring) : NULL,
        reply_parameters ? reply_parameters_local_nonprim : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return send_sticker_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
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
