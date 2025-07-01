#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "keyboard_button_request_chat.h"



static keyboard_button_request_chat_t *keyboard_button_request_chat_create_internal(
    int request_id,
    int chat_is_channel,
    int chat_is_forum,
    int chat_has_username,
    int chat_is_created,
    chat_administrator_rights_t *user_administrator_rights,
    chat_administrator_rights_t *bot_administrator_rights,
    int bot_is_member,
    int request_title,
    int request_username,
    int request_photo
    ) {
    keyboard_button_request_chat_t *keyboard_button_request_chat_local_var = malloc(sizeof(keyboard_button_request_chat_t));
    if (!keyboard_button_request_chat_local_var) {
        return NULL;
    }
    keyboard_button_request_chat_local_var->request_id = request_id;
    keyboard_button_request_chat_local_var->chat_is_channel = chat_is_channel;
    keyboard_button_request_chat_local_var->chat_is_forum = chat_is_forum;
    keyboard_button_request_chat_local_var->chat_has_username = chat_has_username;
    keyboard_button_request_chat_local_var->chat_is_created = chat_is_created;
    keyboard_button_request_chat_local_var->user_administrator_rights = user_administrator_rights;
    keyboard_button_request_chat_local_var->bot_administrator_rights = bot_administrator_rights;
    keyboard_button_request_chat_local_var->bot_is_member = bot_is_member;
    keyboard_button_request_chat_local_var->request_title = request_title;
    keyboard_button_request_chat_local_var->request_username = request_username;
    keyboard_button_request_chat_local_var->request_photo = request_photo;

    keyboard_button_request_chat_local_var->_library_owned = 1;
    return keyboard_button_request_chat_local_var;
}

__attribute__((deprecated)) keyboard_button_request_chat_t *keyboard_button_request_chat_create(
    int request_id,
    int chat_is_channel,
    int chat_is_forum,
    int chat_has_username,
    int chat_is_created,
    chat_administrator_rights_t *user_administrator_rights,
    chat_administrator_rights_t *bot_administrator_rights,
    int bot_is_member,
    int request_title,
    int request_username,
    int request_photo
    ) {
    return keyboard_button_request_chat_create_internal (
        request_id,
        chat_is_channel,
        chat_is_forum,
        chat_has_username,
        chat_is_created,
        user_administrator_rights,
        bot_administrator_rights,
        bot_is_member,
        request_title,
        request_username,
        request_photo
        );
}

void keyboard_button_request_chat_free(keyboard_button_request_chat_t *keyboard_button_request_chat) {
    if(NULL == keyboard_button_request_chat){
        return ;
    }
    if(keyboard_button_request_chat->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "keyboard_button_request_chat_free");
        return ;
    }
    listEntry_t *listEntry;
    if (keyboard_button_request_chat->user_administrator_rights) {
        chat_administrator_rights_free(keyboard_button_request_chat->user_administrator_rights);
        keyboard_button_request_chat->user_administrator_rights = NULL;
    }
    if (keyboard_button_request_chat->bot_administrator_rights) {
        chat_administrator_rights_free(keyboard_button_request_chat->bot_administrator_rights);
        keyboard_button_request_chat->bot_administrator_rights = NULL;
    }
    free(keyboard_button_request_chat);
}

cJSON *keyboard_button_request_chat_convertToJSON(keyboard_button_request_chat_t *keyboard_button_request_chat) {
    cJSON *item = cJSON_CreateObject();

    // keyboard_button_request_chat->request_id
    if (!keyboard_button_request_chat->request_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "request_id", keyboard_button_request_chat->request_id) == NULL) {
    goto fail; //Numeric
    }


    // keyboard_button_request_chat->chat_is_channel
    if (!keyboard_button_request_chat->chat_is_channel) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "chat_is_channel", keyboard_button_request_chat->chat_is_channel) == NULL) {
    goto fail; //Bool
    }


    // keyboard_button_request_chat->chat_is_forum
    if(keyboard_button_request_chat->chat_is_forum) {
    if(cJSON_AddBoolToObject(item, "chat_is_forum", keyboard_button_request_chat->chat_is_forum) == NULL) {
    goto fail; //Bool
    }
    }


    // keyboard_button_request_chat->chat_has_username
    if(keyboard_button_request_chat->chat_has_username) {
    if(cJSON_AddBoolToObject(item, "chat_has_username", keyboard_button_request_chat->chat_has_username) == NULL) {
    goto fail; //Bool
    }
    }


    // keyboard_button_request_chat->chat_is_created
    if(keyboard_button_request_chat->chat_is_created) {
    if(cJSON_AddBoolToObject(item, "chat_is_created", keyboard_button_request_chat->chat_is_created) == NULL) {
    goto fail; //Bool
    }
    }


    // keyboard_button_request_chat->user_administrator_rights
    if(keyboard_button_request_chat->user_administrator_rights) {
    cJSON *user_administrator_rights_local_JSON = chat_administrator_rights_convertToJSON(keyboard_button_request_chat->user_administrator_rights);
    if(user_administrator_rights_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user_administrator_rights", user_administrator_rights_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // keyboard_button_request_chat->bot_administrator_rights
    if(keyboard_button_request_chat->bot_administrator_rights) {
    cJSON *bot_administrator_rights_local_JSON = chat_administrator_rights_convertToJSON(keyboard_button_request_chat->bot_administrator_rights);
    if(bot_administrator_rights_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "bot_administrator_rights", bot_administrator_rights_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // keyboard_button_request_chat->bot_is_member
    if(keyboard_button_request_chat->bot_is_member) {
    if(cJSON_AddBoolToObject(item, "bot_is_member", keyboard_button_request_chat->bot_is_member) == NULL) {
    goto fail; //Bool
    }
    }


    // keyboard_button_request_chat->request_title
    if(keyboard_button_request_chat->request_title) {
    if(cJSON_AddBoolToObject(item, "request_title", keyboard_button_request_chat->request_title) == NULL) {
    goto fail; //Bool
    }
    }


    // keyboard_button_request_chat->request_username
    if(keyboard_button_request_chat->request_username) {
    if(cJSON_AddBoolToObject(item, "request_username", keyboard_button_request_chat->request_username) == NULL) {
    goto fail; //Bool
    }
    }


    // keyboard_button_request_chat->request_photo
    if(keyboard_button_request_chat->request_photo) {
    if(cJSON_AddBoolToObject(item, "request_photo", keyboard_button_request_chat->request_photo) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

keyboard_button_request_chat_t *keyboard_button_request_chat_parseFromJSON(cJSON *keyboard_button_request_chatJSON){

    keyboard_button_request_chat_t *keyboard_button_request_chat_local_var = NULL;

    // define the local variable for keyboard_button_request_chat->user_administrator_rights
    chat_administrator_rights_t *user_administrator_rights_local_nonprim = NULL;

    // define the local variable for keyboard_button_request_chat->bot_administrator_rights
    chat_administrator_rights_t *bot_administrator_rights_local_nonprim = NULL;

    // keyboard_button_request_chat->request_id
    cJSON *request_id = cJSON_GetObjectItemCaseSensitive(keyboard_button_request_chatJSON, "request_id");
    if (cJSON_IsNull(request_id)) {
        request_id = NULL;
    }
    if (!request_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(request_id))
    {
    goto end; //Numeric
    }

    // keyboard_button_request_chat->chat_is_channel
    cJSON *chat_is_channel = cJSON_GetObjectItemCaseSensitive(keyboard_button_request_chatJSON, "chat_is_channel");
    if (cJSON_IsNull(chat_is_channel)) {
        chat_is_channel = NULL;
    }
    if (!chat_is_channel) {
        goto end;
    }

    
    if(!cJSON_IsBool(chat_is_channel))
    {
    goto end; //Bool
    }

    // keyboard_button_request_chat->chat_is_forum
    cJSON *chat_is_forum = cJSON_GetObjectItemCaseSensitive(keyboard_button_request_chatJSON, "chat_is_forum");
    if (cJSON_IsNull(chat_is_forum)) {
        chat_is_forum = NULL;
    }
    if (chat_is_forum) { 
    if(!cJSON_IsBool(chat_is_forum))
    {
    goto end; //Bool
    }
    }

    // keyboard_button_request_chat->chat_has_username
    cJSON *chat_has_username = cJSON_GetObjectItemCaseSensitive(keyboard_button_request_chatJSON, "chat_has_username");
    if (cJSON_IsNull(chat_has_username)) {
        chat_has_username = NULL;
    }
    if (chat_has_username) { 
    if(!cJSON_IsBool(chat_has_username))
    {
    goto end; //Bool
    }
    }

    // keyboard_button_request_chat->chat_is_created
    cJSON *chat_is_created = cJSON_GetObjectItemCaseSensitive(keyboard_button_request_chatJSON, "chat_is_created");
    if (cJSON_IsNull(chat_is_created)) {
        chat_is_created = NULL;
    }
    if (chat_is_created) { 
    if(!cJSON_IsBool(chat_is_created))
    {
    goto end; //Bool
    }
    }

    // keyboard_button_request_chat->user_administrator_rights
    cJSON *user_administrator_rights = cJSON_GetObjectItemCaseSensitive(keyboard_button_request_chatJSON, "user_administrator_rights");
    if (cJSON_IsNull(user_administrator_rights)) {
        user_administrator_rights = NULL;
    }
    if (user_administrator_rights) { 
    user_administrator_rights_local_nonprim = chat_administrator_rights_parseFromJSON(user_administrator_rights); //nonprimitive
    }

    // keyboard_button_request_chat->bot_administrator_rights
    cJSON *bot_administrator_rights = cJSON_GetObjectItemCaseSensitive(keyboard_button_request_chatJSON, "bot_administrator_rights");
    if (cJSON_IsNull(bot_administrator_rights)) {
        bot_administrator_rights = NULL;
    }
    if (bot_administrator_rights) { 
    bot_administrator_rights_local_nonprim = chat_administrator_rights_parseFromJSON(bot_administrator_rights); //nonprimitive
    }

    // keyboard_button_request_chat->bot_is_member
    cJSON *bot_is_member = cJSON_GetObjectItemCaseSensitive(keyboard_button_request_chatJSON, "bot_is_member");
    if (cJSON_IsNull(bot_is_member)) {
        bot_is_member = NULL;
    }
    if (bot_is_member) { 
    if(!cJSON_IsBool(bot_is_member))
    {
    goto end; //Bool
    }
    }

    // keyboard_button_request_chat->request_title
    cJSON *request_title = cJSON_GetObjectItemCaseSensitive(keyboard_button_request_chatJSON, "request_title");
    if (cJSON_IsNull(request_title)) {
        request_title = NULL;
    }
    if (request_title) { 
    if(!cJSON_IsBool(request_title))
    {
    goto end; //Bool
    }
    }

    // keyboard_button_request_chat->request_username
    cJSON *request_username = cJSON_GetObjectItemCaseSensitive(keyboard_button_request_chatJSON, "request_username");
    if (cJSON_IsNull(request_username)) {
        request_username = NULL;
    }
    if (request_username) { 
    if(!cJSON_IsBool(request_username))
    {
    goto end; //Bool
    }
    }

    // keyboard_button_request_chat->request_photo
    cJSON *request_photo = cJSON_GetObjectItemCaseSensitive(keyboard_button_request_chatJSON, "request_photo");
    if (cJSON_IsNull(request_photo)) {
        request_photo = NULL;
    }
    if (request_photo) { 
    if(!cJSON_IsBool(request_photo))
    {
    goto end; //Bool
    }
    }


    keyboard_button_request_chat_local_var = keyboard_button_request_chat_create_internal (
        request_id->valuedouble,
        chat_is_channel->valueint,
        chat_is_forum ? chat_is_forum->valueint : 0,
        chat_has_username ? chat_has_username->valueint : 0,
        chat_is_created ? chat_is_created->valueint : 0,
        user_administrator_rights ? user_administrator_rights_local_nonprim : NULL,
        bot_administrator_rights ? bot_administrator_rights_local_nonprim : NULL,
        bot_is_member ? bot_is_member->valueint : 0,
        request_title ? request_title->valueint : 0,
        request_username ? request_username->valueint : 0,
        request_photo ? request_photo->valueint : 0
        );

    return keyboard_button_request_chat_local_var;
end:
    if (user_administrator_rights_local_nonprim) {
        chat_administrator_rights_free(user_administrator_rights_local_nonprim);
        user_administrator_rights_local_nonprim = NULL;
    }
    if (bot_administrator_rights_local_nonprim) {
        chat_administrator_rights_free(bot_administrator_rights_local_nonprim);
        bot_administrator_rights_local_nonprim = NULL;
    }
    return NULL;

}
