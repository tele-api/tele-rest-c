#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_keyboard_button.h"



static inline_keyboard_button_t *inline_keyboard_button_create_internal(
    char *text,
    char *url,
    char *callback_data,
    web_app_info_t *web_app,
    login_url_t *login_url,
    char *switch_inline_query,
    char *switch_inline_query_current_chat,
    switch_inline_query_chosen_chat_t *switch_inline_query_chosen_chat,
    copy_text_button_t *copy_text,
    any_type_t *callback_game,
    int pay
    ) {
    inline_keyboard_button_t *inline_keyboard_button_local_var = malloc(sizeof(inline_keyboard_button_t));
    if (!inline_keyboard_button_local_var) {
        return NULL;
    }
    inline_keyboard_button_local_var->text = text;
    inline_keyboard_button_local_var->url = url;
    inline_keyboard_button_local_var->callback_data = callback_data;
    inline_keyboard_button_local_var->web_app = web_app;
    inline_keyboard_button_local_var->login_url = login_url;
    inline_keyboard_button_local_var->switch_inline_query = switch_inline_query;
    inline_keyboard_button_local_var->switch_inline_query_current_chat = switch_inline_query_current_chat;
    inline_keyboard_button_local_var->switch_inline_query_chosen_chat = switch_inline_query_chosen_chat;
    inline_keyboard_button_local_var->copy_text = copy_text;
    inline_keyboard_button_local_var->callback_game = callback_game;
    inline_keyboard_button_local_var->pay = pay;

    inline_keyboard_button_local_var->_library_owned = 1;
    return inline_keyboard_button_local_var;
}

__attribute__((deprecated)) inline_keyboard_button_t *inline_keyboard_button_create(
    char *text,
    char *url,
    char *callback_data,
    web_app_info_t *web_app,
    login_url_t *login_url,
    char *switch_inline_query,
    char *switch_inline_query_current_chat,
    switch_inline_query_chosen_chat_t *switch_inline_query_chosen_chat,
    copy_text_button_t *copy_text,
    any_type_t *callback_game,
    int pay
    ) {
    return inline_keyboard_button_create_internal (
        text,
        url,
        callback_data,
        web_app,
        login_url,
        switch_inline_query,
        switch_inline_query_current_chat,
        switch_inline_query_chosen_chat,
        copy_text,
        callback_game,
        pay
        );
}

void inline_keyboard_button_free(inline_keyboard_button_t *inline_keyboard_button) {
    if(NULL == inline_keyboard_button){
        return ;
    }
    if(inline_keyboard_button->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inline_keyboard_button_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inline_keyboard_button->text) {
        free(inline_keyboard_button->text);
        inline_keyboard_button->text = NULL;
    }
    if (inline_keyboard_button->url) {
        free(inline_keyboard_button->url);
        inline_keyboard_button->url = NULL;
    }
    if (inline_keyboard_button->callback_data) {
        free(inline_keyboard_button->callback_data);
        inline_keyboard_button->callback_data = NULL;
    }
    if (inline_keyboard_button->web_app) {
        web_app_info_free(inline_keyboard_button->web_app);
        inline_keyboard_button->web_app = NULL;
    }
    if (inline_keyboard_button->login_url) {
        login_url_free(inline_keyboard_button->login_url);
        inline_keyboard_button->login_url = NULL;
    }
    if (inline_keyboard_button->switch_inline_query) {
        free(inline_keyboard_button->switch_inline_query);
        inline_keyboard_button->switch_inline_query = NULL;
    }
    if (inline_keyboard_button->switch_inline_query_current_chat) {
        free(inline_keyboard_button->switch_inline_query_current_chat);
        inline_keyboard_button->switch_inline_query_current_chat = NULL;
    }
    if (inline_keyboard_button->switch_inline_query_chosen_chat) {
        switch_inline_query_chosen_chat_free(inline_keyboard_button->switch_inline_query_chosen_chat);
        inline_keyboard_button->switch_inline_query_chosen_chat = NULL;
    }
    if (inline_keyboard_button->copy_text) {
        copy_text_button_free(inline_keyboard_button->copy_text);
        inline_keyboard_button->copy_text = NULL;
    }
    if (inline_keyboard_button->callback_game) {
        _free(inline_keyboard_button->callback_game);
        inline_keyboard_button->callback_game = NULL;
    }
    free(inline_keyboard_button);
}

cJSON *inline_keyboard_button_convertToJSON(inline_keyboard_button_t *inline_keyboard_button) {
    cJSON *item = cJSON_CreateObject();

    // inline_keyboard_button->text
    if (!inline_keyboard_button->text) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "text", inline_keyboard_button->text) == NULL) {
    goto fail; //String
    }


    // inline_keyboard_button->url
    if(inline_keyboard_button->url) {
    if(cJSON_AddStringToObject(item, "url", inline_keyboard_button->url) == NULL) {
    goto fail; //String
    }
    }


    // inline_keyboard_button->callback_data
    if(inline_keyboard_button->callback_data) {
    if(cJSON_AddStringToObject(item, "callback_data", inline_keyboard_button->callback_data) == NULL) {
    goto fail; //String
    }
    }


    // inline_keyboard_button->web_app
    if(inline_keyboard_button->web_app) {
    cJSON *web_app_local_JSON = web_app_info_convertToJSON(inline_keyboard_button->web_app);
    if(web_app_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "web_app", web_app_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_keyboard_button->login_url
    if(inline_keyboard_button->login_url) {
    cJSON *login_url_local_JSON = login_url_convertToJSON(inline_keyboard_button->login_url);
    if(login_url_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "login_url", login_url_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_keyboard_button->switch_inline_query
    if(inline_keyboard_button->switch_inline_query) {
    if(cJSON_AddStringToObject(item, "switch_inline_query", inline_keyboard_button->switch_inline_query) == NULL) {
    goto fail; //String
    }
    }


    // inline_keyboard_button->switch_inline_query_current_chat
    if(inline_keyboard_button->switch_inline_query_current_chat) {
    if(cJSON_AddStringToObject(item, "switch_inline_query_current_chat", inline_keyboard_button->switch_inline_query_current_chat) == NULL) {
    goto fail; //String
    }
    }


    // inline_keyboard_button->switch_inline_query_chosen_chat
    if(inline_keyboard_button->switch_inline_query_chosen_chat) {
    cJSON *switch_inline_query_chosen_chat_local_JSON = switch_inline_query_chosen_chat_convertToJSON(inline_keyboard_button->switch_inline_query_chosen_chat);
    if(switch_inline_query_chosen_chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "switch_inline_query_chosen_chat", switch_inline_query_chosen_chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_keyboard_button->copy_text
    if(inline_keyboard_button->copy_text) {
    cJSON *copy_text_local_JSON = copy_text_button_convertToJSON(inline_keyboard_button->copy_text);
    if(copy_text_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "copy_text", copy_text_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_keyboard_button->callback_game
    if(inline_keyboard_button->callback_game) {
    cJSON *callback_game_local_JSON = _convertToJSON(inline_keyboard_button->callback_game);
    if(callback_game_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "callback_game", callback_game_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // inline_keyboard_button->pay
    if(inline_keyboard_button->pay) {
    if(cJSON_AddBoolToObject(item, "pay", inline_keyboard_button->pay) == NULL) {
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

inline_keyboard_button_t *inline_keyboard_button_parseFromJSON(cJSON *inline_keyboard_buttonJSON){

    inline_keyboard_button_t *inline_keyboard_button_local_var = NULL;

    // define the local variable for inline_keyboard_button->web_app
    web_app_info_t *web_app_local_nonprim = NULL;

    // define the local variable for inline_keyboard_button->login_url
    login_url_t *login_url_local_nonprim = NULL;

    // define the local variable for inline_keyboard_button->switch_inline_query_chosen_chat
    switch_inline_query_chosen_chat_t *switch_inline_query_chosen_chat_local_nonprim = NULL;

    // define the local variable for inline_keyboard_button->copy_text
    copy_text_button_t *copy_text_local_nonprim = NULL;

    // define the local variable for inline_keyboard_button->callback_game
    _t *callback_game_local_nonprim = NULL;

    // inline_keyboard_button->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(inline_keyboard_buttonJSON, "text");
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

    // inline_keyboard_button->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(inline_keyboard_buttonJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }

    // inline_keyboard_button->callback_data
    cJSON *callback_data = cJSON_GetObjectItemCaseSensitive(inline_keyboard_buttonJSON, "callback_data");
    if (cJSON_IsNull(callback_data)) {
        callback_data = NULL;
    }
    if (callback_data) { 
    if(!cJSON_IsString(callback_data) && !cJSON_IsNull(callback_data))
    {
    goto end; //String
    }
    }

    // inline_keyboard_button->web_app
    cJSON *web_app = cJSON_GetObjectItemCaseSensitive(inline_keyboard_buttonJSON, "web_app");
    if (cJSON_IsNull(web_app)) {
        web_app = NULL;
    }
    if (web_app) { 
    web_app_local_nonprim = web_app_info_parseFromJSON(web_app); //nonprimitive
    }

    // inline_keyboard_button->login_url
    cJSON *login_url = cJSON_GetObjectItemCaseSensitive(inline_keyboard_buttonJSON, "login_url");
    if (cJSON_IsNull(login_url)) {
        login_url = NULL;
    }
    if (login_url) { 
    login_url_local_nonprim = login_url_parseFromJSON(login_url); //nonprimitive
    }

    // inline_keyboard_button->switch_inline_query
    cJSON *switch_inline_query = cJSON_GetObjectItemCaseSensitive(inline_keyboard_buttonJSON, "switch_inline_query");
    if (cJSON_IsNull(switch_inline_query)) {
        switch_inline_query = NULL;
    }
    if (switch_inline_query) { 
    if(!cJSON_IsString(switch_inline_query) && !cJSON_IsNull(switch_inline_query))
    {
    goto end; //String
    }
    }

    // inline_keyboard_button->switch_inline_query_current_chat
    cJSON *switch_inline_query_current_chat = cJSON_GetObjectItemCaseSensitive(inline_keyboard_buttonJSON, "switch_inline_query_current_chat");
    if (cJSON_IsNull(switch_inline_query_current_chat)) {
        switch_inline_query_current_chat = NULL;
    }
    if (switch_inline_query_current_chat) { 
    if(!cJSON_IsString(switch_inline_query_current_chat) && !cJSON_IsNull(switch_inline_query_current_chat))
    {
    goto end; //String
    }
    }

    // inline_keyboard_button->switch_inline_query_chosen_chat
    cJSON *switch_inline_query_chosen_chat = cJSON_GetObjectItemCaseSensitive(inline_keyboard_buttonJSON, "switch_inline_query_chosen_chat");
    if (cJSON_IsNull(switch_inline_query_chosen_chat)) {
        switch_inline_query_chosen_chat = NULL;
    }
    if (switch_inline_query_chosen_chat) { 
    switch_inline_query_chosen_chat_local_nonprim = switch_inline_query_chosen_chat_parseFromJSON(switch_inline_query_chosen_chat); //nonprimitive
    }

    // inline_keyboard_button->copy_text
    cJSON *copy_text = cJSON_GetObjectItemCaseSensitive(inline_keyboard_buttonJSON, "copy_text");
    if (cJSON_IsNull(copy_text)) {
        copy_text = NULL;
    }
    if (copy_text) { 
    copy_text_local_nonprim = copy_text_button_parseFromJSON(copy_text); //nonprimitive
    }

    // inline_keyboard_button->callback_game
    cJSON *callback_game = cJSON_GetObjectItemCaseSensitive(inline_keyboard_buttonJSON, "callback_game");
    if (cJSON_IsNull(callback_game)) {
        callback_game = NULL;
    }
    if (callback_game) { 
    callback_game_local_nonprim = _parseFromJSON(callback_game); //custom
    }

    // inline_keyboard_button->pay
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(inline_keyboard_buttonJSON, "pay");
    if (cJSON_IsNull(pay)) {
        pay = NULL;
    }
    if (pay) { 
    if(!cJSON_IsBool(pay))
    {
    goto end; //Bool
    }
    }


    inline_keyboard_button_local_var = inline_keyboard_button_create_internal (
        strdup(text->valuestring),
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL,
        callback_data && !cJSON_IsNull(callback_data) ? strdup(callback_data->valuestring) : NULL,
        web_app ? web_app_local_nonprim : NULL,
        login_url ? login_url_local_nonprim : NULL,
        switch_inline_query && !cJSON_IsNull(switch_inline_query) ? strdup(switch_inline_query->valuestring) : NULL,
        switch_inline_query_current_chat && !cJSON_IsNull(switch_inline_query_current_chat) ? strdup(switch_inline_query_current_chat->valuestring) : NULL,
        switch_inline_query_chosen_chat ? switch_inline_query_chosen_chat_local_nonprim : NULL,
        copy_text ? copy_text_local_nonprim : NULL,
        callback_game ? callback_game_local_nonprim : NULL,
        pay ? pay->valueint : 0
        );

    return inline_keyboard_button_local_var;
end:
    if (web_app_local_nonprim) {
        web_app_info_free(web_app_local_nonprim);
        web_app_local_nonprim = NULL;
    }
    if (login_url_local_nonprim) {
        login_url_free(login_url_local_nonprim);
        login_url_local_nonprim = NULL;
    }
    if (switch_inline_query_chosen_chat_local_nonprim) {
        switch_inline_query_chosen_chat_free(switch_inline_query_chosen_chat_local_nonprim);
        switch_inline_query_chosen_chat_local_nonprim = NULL;
    }
    if (copy_text_local_nonprim) {
        copy_text_button_free(copy_text_local_nonprim);
        copy_text_local_nonprim = NULL;
    }
    if (callback_game_local_nonprim) {
        _free(callback_game_local_nonprim);
        callback_game_local_nonprim = NULL;
    }
    return NULL;

}
