#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_game_request.h"



static send_game_request_t *send_game_request_create_internal(
    int chat_id,
    char *game_short_name,
    char *business_connection_id,
    int message_thread_id,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    inline_keyboard_markup_t *reply_markup
    ) {
    send_game_request_t *send_game_request_local_var = malloc(sizeof(send_game_request_t));
    if (!send_game_request_local_var) {
        return NULL;
    }
    send_game_request_local_var->chat_id = chat_id;
    send_game_request_local_var->game_short_name = game_short_name;
    send_game_request_local_var->business_connection_id = business_connection_id;
    send_game_request_local_var->message_thread_id = message_thread_id;
    send_game_request_local_var->disable_notification = disable_notification;
    send_game_request_local_var->protect_content = protect_content;
    send_game_request_local_var->allow_paid_broadcast = allow_paid_broadcast;
    send_game_request_local_var->message_effect_id = message_effect_id;
    send_game_request_local_var->reply_parameters = reply_parameters;
    send_game_request_local_var->reply_markup = reply_markup;

    send_game_request_local_var->_library_owned = 1;
    return send_game_request_local_var;
}

__attribute__((deprecated)) send_game_request_t *send_game_request_create(
    int chat_id,
    char *game_short_name,
    char *business_connection_id,
    int message_thread_id,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    inline_keyboard_markup_t *reply_markup
    ) {
    return send_game_request_create_internal (
        chat_id,
        game_short_name,
        business_connection_id,
        message_thread_id,
        disable_notification,
        protect_content,
        allow_paid_broadcast,
        message_effect_id,
        reply_parameters,
        reply_markup
        );
}

void send_game_request_free(send_game_request_t *send_game_request) {
    if(NULL == send_game_request){
        return ;
    }
    if(send_game_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_game_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (send_game_request->game_short_name) {
        free(send_game_request->game_short_name);
        send_game_request->game_short_name = NULL;
    }
    if (send_game_request->business_connection_id) {
        free(send_game_request->business_connection_id);
        send_game_request->business_connection_id = NULL;
    }
    if (send_game_request->message_effect_id) {
        free(send_game_request->message_effect_id);
        send_game_request->message_effect_id = NULL;
    }
    if (send_game_request->reply_parameters) {
        reply_parameters_free(send_game_request->reply_parameters);
        send_game_request->reply_parameters = NULL;
    }
    if (send_game_request->reply_markup) {
        inline_keyboard_markup_free(send_game_request->reply_markup);
        send_game_request->reply_markup = NULL;
    }
    free(send_game_request);
}

cJSON *send_game_request_convertToJSON(send_game_request_t *send_game_request) {
    cJSON *item = cJSON_CreateObject();

    // send_game_request->chat_id
    if (!send_game_request->chat_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "chat_id", send_game_request->chat_id) == NULL) {
    goto fail; //Numeric
    }


    // send_game_request->game_short_name
    if (!send_game_request->game_short_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "game_short_name", send_game_request->game_short_name) == NULL) {
    goto fail; //String
    }


    // send_game_request->business_connection_id
    if(send_game_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", send_game_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // send_game_request->message_thread_id
    if(send_game_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", send_game_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // send_game_request->disable_notification
    if(send_game_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", send_game_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // send_game_request->protect_content
    if(send_game_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", send_game_request->protect_content) == NULL) {
    goto fail; //Bool
    }
    }


    // send_game_request->allow_paid_broadcast
    if(send_game_request->allow_paid_broadcast) {
    if(cJSON_AddBoolToObject(item, "allow_paid_broadcast", send_game_request->allow_paid_broadcast) == NULL) {
    goto fail; //Bool
    }
    }


    // send_game_request->message_effect_id
    if(send_game_request->message_effect_id) {
    if(cJSON_AddStringToObject(item, "message_effect_id", send_game_request->message_effect_id) == NULL) {
    goto fail; //String
    }
    }


    // send_game_request->reply_parameters
    if(send_game_request->reply_parameters) {
    cJSON *reply_parameters_local_JSON = reply_parameters_convertToJSON(send_game_request->reply_parameters);
    if(reply_parameters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_parameters", reply_parameters_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // send_game_request->reply_markup
    if(send_game_request->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(send_game_request->reply_markup);
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

send_game_request_t *send_game_request_parseFromJSON(cJSON *send_game_requestJSON){

    send_game_request_t *send_game_request_local_var = NULL;

    // define the local variable for send_game_request->reply_parameters
    reply_parameters_t *reply_parameters_local_nonprim = NULL;

    // define the local variable for send_game_request->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // send_game_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(send_game_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(chat_id))
    {
    goto end; //Numeric
    }

    // send_game_request->game_short_name
    cJSON *game_short_name = cJSON_GetObjectItemCaseSensitive(send_game_requestJSON, "game_short_name");
    if (cJSON_IsNull(game_short_name)) {
        game_short_name = NULL;
    }
    if (!game_short_name) {
        goto end;
    }

    
    if(!cJSON_IsString(game_short_name))
    {
    goto end; //String
    }

    // send_game_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(send_game_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // send_game_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(send_game_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // send_game_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(send_game_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // send_game_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(send_game_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }

    // send_game_request->allow_paid_broadcast
    cJSON *allow_paid_broadcast = cJSON_GetObjectItemCaseSensitive(send_game_requestJSON, "allow_paid_broadcast");
    if (cJSON_IsNull(allow_paid_broadcast)) {
        allow_paid_broadcast = NULL;
    }
    if (allow_paid_broadcast) { 
    if(!cJSON_IsBool(allow_paid_broadcast))
    {
    goto end; //Bool
    }
    }

    // send_game_request->message_effect_id
    cJSON *message_effect_id = cJSON_GetObjectItemCaseSensitive(send_game_requestJSON, "message_effect_id");
    if (cJSON_IsNull(message_effect_id)) {
        message_effect_id = NULL;
    }
    if (message_effect_id) { 
    if(!cJSON_IsString(message_effect_id) && !cJSON_IsNull(message_effect_id))
    {
    goto end; //String
    }
    }

    // send_game_request->reply_parameters
    cJSON *reply_parameters = cJSON_GetObjectItemCaseSensitive(send_game_requestJSON, "reply_parameters");
    if (cJSON_IsNull(reply_parameters)) {
        reply_parameters = NULL;
    }
    if (reply_parameters) { 
    reply_parameters_local_nonprim = reply_parameters_parseFromJSON(reply_parameters); //nonprimitive
    }

    // send_game_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(send_game_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    send_game_request_local_var = send_game_request_create_internal (
        chat_id->valuedouble,
        strdup(game_short_name->valuestring),
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        message_thread_id ? message_thread_id->valuedouble : 0,
        disable_notification ? disable_notification->valueint : 0,
        protect_content ? protect_content->valueint : 0,
        allow_paid_broadcast ? allow_paid_broadcast->valueint : 0,
        message_effect_id && !cJSON_IsNull(message_effect_id) ? strdup(message_effect_id->valuestring) : NULL,
        reply_parameters ? reply_parameters_local_nonprim : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return send_game_request_local_var;
end:
    if (reply_parameters_local_nonprim) {
        reply_parameters_free(reply_parameters_local_nonprim);
        reply_parameters_local_nonprim = NULL;
    }
    if (reply_markup_local_nonprim) {
        inline_keyboard_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    return NULL;

}
