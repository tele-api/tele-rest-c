#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_send_dice_request.h"


char* post_send_dice_request_emoji_ToString(telegram_bot_api_post_send_dice_request_EMOJI_e emoji) {
    char* emojiArray[] =  { "NULL", "🎲", "🎯", "🏀", "⚽", "🎳", "🎰" };
    return emojiArray[emoji];
}

telegram_bot_api_post_send_dice_request_EMOJI_e post_send_dice_request_emoji_FromString(char* emoji){
    int stringToReturn = 0;
    char *emojiArray[] =  { "NULL", "🎲", "🎯", "🏀", "⚽", "🎳", "🎰" };
    size_t sizeofArray = sizeof(emojiArray) / sizeof(emojiArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(emoji, emojiArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static post_send_dice_request_t *post_send_dice_request_create_internal(
    post_send_message_request_chat_id_t *chat_id,
    char *business_connection_id,
    int message_thread_id,
    telegram_bot_api_post_send_dice_request_EMOJI_e emoji,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    post_send_message_request_reply_markup_t *reply_markup
    ) {
    post_send_dice_request_t *post_send_dice_request_local_var = malloc(sizeof(post_send_dice_request_t));
    if (!post_send_dice_request_local_var) {
        return NULL;
    }
    post_send_dice_request_local_var->chat_id = chat_id;
    post_send_dice_request_local_var->business_connection_id = business_connection_id;
    post_send_dice_request_local_var->message_thread_id = message_thread_id;
    post_send_dice_request_local_var->emoji = emoji;
    post_send_dice_request_local_var->disable_notification = disable_notification;
    post_send_dice_request_local_var->protect_content = protect_content;
    post_send_dice_request_local_var->allow_paid_broadcast = allow_paid_broadcast;
    post_send_dice_request_local_var->message_effect_id = message_effect_id;
    post_send_dice_request_local_var->reply_parameters = reply_parameters;
    post_send_dice_request_local_var->reply_markup = reply_markup;

    post_send_dice_request_local_var->_library_owned = 1;
    return post_send_dice_request_local_var;
}

__attribute__((deprecated)) post_send_dice_request_t *post_send_dice_request_create(
    post_send_message_request_chat_id_t *chat_id,
    char *business_connection_id,
    int message_thread_id,
    telegram_bot_api_post_send_dice_request_EMOJI_e emoji,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    post_send_message_request_reply_markup_t *reply_markup
    ) {
    return post_send_dice_request_create_internal (
        chat_id,
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

void post_send_dice_request_free(post_send_dice_request_t *post_send_dice_request) {
    if(NULL == post_send_dice_request){
        return ;
    }
    if(post_send_dice_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_send_dice_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_send_dice_request->chat_id) {
        post_send_message_request_chat_id_free(post_send_dice_request->chat_id);
        post_send_dice_request->chat_id = NULL;
    }
    if (post_send_dice_request->business_connection_id) {
        free(post_send_dice_request->business_connection_id);
        post_send_dice_request->business_connection_id = NULL;
    }
    if (post_send_dice_request->message_effect_id) {
        free(post_send_dice_request->message_effect_id);
        post_send_dice_request->message_effect_id = NULL;
    }
    if (post_send_dice_request->reply_parameters) {
        reply_parameters_free(post_send_dice_request->reply_parameters);
        post_send_dice_request->reply_parameters = NULL;
    }
    if (post_send_dice_request->reply_markup) {
        post_send_message_request_reply_markup_free(post_send_dice_request->reply_markup);
        post_send_dice_request->reply_markup = NULL;
    }
    free(post_send_dice_request);
}

cJSON *post_send_dice_request_convertToJSON(post_send_dice_request_t *post_send_dice_request) {
    cJSON *item = cJSON_CreateObject();

    // post_send_dice_request->chat_id
    if (!post_send_dice_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_send_message_request_chat_id_convertToJSON(post_send_dice_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_send_dice_request->business_connection_id
    if(post_send_dice_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", post_send_dice_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // post_send_dice_request->message_thread_id
    if(post_send_dice_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", post_send_dice_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_send_dice_request->emoji
    if(post_send_dice_request->emoji != telegram_bot_api_post_send_dice_request_EMOJI_NULL) {
    if(cJSON_AddStringToObject(item, "emoji", post_send_dice_request_emoji_ToString(post_send_dice_request->emoji)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // post_send_dice_request->disable_notification
    if(post_send_dice_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", post_send_dice_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_dice_request->protect_content
    if(post_send_dice_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", post_send_dice_request->protect_content) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_dice_request->allow_paid_broadcast
    if(post_send_dice_request->allow_paid_broadcast) {
    if(cJSON_AddBoolToObject(item, "allow_paid_broadcast", post_send_dice_request->allow_paid_broadcast) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_dice_request->message_effect_id
    if(post_send_dice_request->message_effect_id) {
    if(cJSON_AddStringToObject(item, "message_effect_id", post_send_dice_request->message_effect_id) == NULL) {
    goto fail; //String
    }
    }


    // post_send_dice_request->reply_parameters
    if(post_send_dice_request->reply_parameters) {
    cJSON *reply_parameters_local_JSON = reply_parameters_convertToJSON(post_send_dice_request->reply_parameters);
    if(reply_parameters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_parameters", reply_parameters_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // post_send_dice_request->reply_markup
    if(post_send_dice_request->reply_markup) {
    cJSON *reply_markup_local_JSON = post_send_message_request_reply_markup_convertToJSON(post_send_dice_request->reply_markup);
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

post_send_dice_request_t *post_send_dice_request_parseFromJSON(cJSON *post_send_dice_requestJSON){

    post_send_dice_request_t *post_send_dice_request_local_var = NULL;

    // define the local variable for post_send_dice_request->chat_id
    post_send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for post_send_dice_request->reply_parameters
    reply_parameters_t *reply_parameters_local_nonprim = NULL;

    // define the local variable for post_send_dice_request->reply_markup
    post_send_message_request_reply_markup_t *reply_markup_local_nonprim = NULL;

    // post_send_dice_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_send_dice_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_send_dice_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_send_dice_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // post_send_dice_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(post_send_dice_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // post_send_dice_request->emoji
    cJSON *emoji = cJSON_GetObjectItemCaseSensitive(post_send_dice_requestJSON, "emoji");
    if (cJSON_IsNull(emoji)) {
        emoji = NULL;
    }
    telegram_bot_api_post_send_dice_request_EMOJI_e emojiVariable;
    if (emoji) { 
    if(!cJSON_IsString(emoji))
    {
    goto end; //Enum
    }
    emojiVariable = post_send_dice_request_emoji_FromString(emoji->valuestring);
    }

    // post_send_dice_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(post_send_dice_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // post_send_dice_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(post_send_dice_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }

    // post_send_dice_request->allow_paid_broadcast
    cJSON *allow_paid_broadcast = cJSON_GetObjectItemCaseSensitive(post_send_dice_requestJSON, "allow_paid_broadcast");
    if (cJSON_IsNull(allow_paid_broadcast)) {
        allow_paid_broadcast = NULL;
    }
    if (allow_paid_broadcast) { 
    if(!cJSON_IsBool(allow_paid_broadcast))
    {
    goto end; //Bool
    }
    }

    // post_send_dice_request->message_effect_id
    cJSON *message_effect_id = cJSON_GetObjectItemCaseSensitive(post_send_dice_requestJSON, "message_effect_id");
    if (cJSON_IsNull(message_effect_id)) {
        message_effect_id = NULL;
    }
    if (message_effect_id) { 
    if(!cJSON_IsString(message_effect_id) && !cJSON_IsNull(message_effect_id))
    {
    goto end; //String
    }
    }

    // post_send_dice_request->reply_parameters
    cJSON *reply_parameters = cJSON_GetObjectItemCaseSensitive(post_send_dice_requestJSON, "reply_parameters");
    if (cJSON_IsNull(reply_parameters)) {
        reply_parameters = NULL;
    }
    if (reply_parameters) { 
    reply_parameters_local_nonprim = reply_parameters_parseFromJSON(reply_parameters); //nonprimitive
    }

    // post_send_dice_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(post_send_dice_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = post_send_message_request_reply_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    post_send_dice_request_local_var = post_send_dice_request_create_internal (
        chat_id_local_nonprim,
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        message_thread_id ? message_thread_id->valuedouble : 0,
        emoji ? emojiVariable : telegram_bot_api_post_send_dice_request_EMOJI_NULL,
        disable_notification ? disable_notification->valueint : 0,
        protect_content ? protect_content->valueint : 0,
        allow_paid_broadcast ? allow_paid_broadcast->valueint : 0,
        message_effect_id && !cJSON_IsNull(message_effect_id) ? strdup(message_effect_id->valuestring) : NULL,
        reply_parameters ? reply_parameters_local_nonprim : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return post_send_dice_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (reply_parameters_local_nonprim) {
        reply_parameters_free(reply_parameters_local_nonprim);
        reply_parameters_local_nonprim = NULL;
    }
    if (reply_markup_local_nonprim) {
        post_send_message_request_reply_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    return NULL;

}
