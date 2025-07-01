#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "keyboard_button.h"



static keyboard_button_t *keyboard_button_create_internal(
    char *text,
    keyboard_button_request_users_t *request_users,
    keyboard_button_request_chat_t *request_chat,
    int request_contact,
    int request_location,
    keyboard_button_poll_type_t *request_poll,
    web_app_info_t *web_app
    ) {
    keyboard_button_t *keyboard_button_local_var = malloc(sizeof(keyboard_button_t));
    if (!keyboard_button_local_var) {
        return NULL;
    }
    keyboard_button_local_var->text = text;
    keyboard_button_local_var->request_users = request_users;
    keyboard_button_local_var->request_chat = request_chat;
    keyboard_button_local_var->request_contact = request_contact;
    keyboard_button_local_var->request_location = request_location;
    keyboard_button_local_var->request_poll = request_poll;
    keyboard_button_local_var->web_app = web_app;

    keyboard_button_local_var->_library_owned = 1;
    return keyboard_button_local_var;
}

__attribute__((deprecated)) keyboard_button_t *keyboard_button_create(
    char *text,
    keyboard_button_request_users_t *request_users,
    keyboard_button_request_chat_t *request_chat,
    int request_contact,
    int request_location,
    keyboard_button_poll_type_t *request_poll,
    web_app_info_t *web_app
    ) {
    return keyboard_button_create_internal (
        text,
        request_users,
        request_chat,
        request_contact,
        request_location,
        request_poll,
        web_app
        );
}

void keyboard_button_free(keyboard_button_t *keyboard_button) {
    if(NULL == keyboard_button){
        return ;
    }
    if(keyboard_button->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "keyboard_button_free");
        return ;
    }
    listEntry_t *listEntry;
    if (keyboard_button->text) {
        free(keyboard_button->text);
        keyboard_button->text = NULL;
    }
    if (keyboard_button->request_users) {
        keyboard_button_request_users_free(keyboard_button->request_users);
        keyboard_button->request_users = NULL;
    }
    if (keyboard_button->request_chat) {
        keyboard_button_request_chat_free(keyboard_button->request_chat);
        keyboard_button->request_chat = NULL;
    }
    if (keyboard_button->request_poll) {
        keyboard_button_poll_type_free(keyboard_button->request_poll);
        keyboard_button->request_poll = NULL;
    }
    if (keyboard_button->web_app) {
        web_app_info_free(keyboard_button->web_app);
        keyboard_button->web_app = NULL;
    }
    free(keyboard_button);
}

cJSON *keyboard_button_convertToJSON(keyboard_button_t *keyboard_button) {
    cJSON *item = cJSON_CreateObject();

    // keyboard_button->text
    if (!keyboard_button->text) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "text", keyboard_button->text) == NULL) {
    goto fail; //String
    }


    // keyboard_button->request_users
    if(keyboard_button->request_users) {
    cJSON *request_users_local_JSON = keyboard_button_request_users_convertToJSON(keyboard_button->request_users);
    if(request_users_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "request_users", request_users_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // keyboard_button->request_chat
    if(keyboard_button->request_chat) {
    cJSON *request_chat_local_JSON = keyboard_button_request_chat_convertToJSON(keyboard_button->request_chat);
    if(request_chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "request_chat", request_chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // keyboard_button->request_contact
    if(keyboard_button->request_contact) {
    if(cJSON_AddBoolToObject(item, "request_contact", keyboard_button->request_contact) == NULL) {
    goto fail; //Bool
    }
    }


    // keyboard_button->request_location
    if(keyboard_button->request_location) {
    if(cJSON_AddBoolToObject(item, "request_location", keyboard_button->request_location) == NULL) {
    goto fail; //Bool
    }
    }


    // keyboard_button->request_poll
    if(keyboard_button->request_poll) {
    cJSON *request_poll_local_JSON = keyboard_button_poll_type_convertToJSON(keyboard_button->request_poll);
    if(request_poll_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "request_poll", request_poll_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // keyboard_button->web_app
    if(keyboard_button->web_app) {
    cJSON *web_app_local_JSON = web_app_info_convertToJSON(keyboard_button->web_app);
    if(web_app_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "web_app", web_app_local_JSON);
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

keyboard_button_t *keyboard_button_parseFromJSON(cJSON *keyboard_buttonJSON){

    keyboard_button_t *keyboard_button_local_var = NULL;

    // define the local variable for keyboard_button->request_users
    keyboard_button_request_users_t *request_users_local_nonprim = NULL;

    // define the local variable for keyboard_button->request_chat
    keyboard_button_request_chat_t *request_chat_local_nonprim = NULL;

    // define the local variable for keyboard_button->request_poll
    keyboard_button_poll_type_t *request_poll_local_nonprim = NULL;

    // define the local variable for keyboard_button->web_app
    web_app_info_t *web_app_local_nonprim = NULL;

    // keyboard_button->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(keyboard_buttonJSON, "text");
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

    // keyboard_button->request_users
    cJSON *request_users = cJSON_GetObjectItemCaseSensitive(keyboard_buttonJSON, "request_users");
    if (cJSON_IsNull(request_users)) {
        request_users = NULL;
    }
    if (request_users) { 
    request_users_local_nonprim = keyboard_button_request_users_parseFromJSON(request_users); //nonprimitive
    }

    // keyboard_button->request_chat
    cJSON *request_chat = cJSON_GetObjectItemCaseSensitive(keyboard_buttonJSON, "request_chat");
    if (cJSON_IsNull(request_chat)) {
        request_chat = NULL;
    }
    if (request_chat) { 
    request_chat_local_nonprim = keyboard_button_request_chat_parseFromJSON(request_chat); //nonprimitive
    }

    // keyboard_button->request_contact
    cJSON *request_contact = cJSON_GetObjectItemCaseSensitive(keyboard_buttonJSON, "request_contact");
    if (cJSON_IsNull(request_contact)) {
        request_contact = NULL;
    }
    if (request_contact) { 
    if(!cJSON_IsBool(request_contact))
    {
    goto end; //Bool
    }
    }

    // keyboard_button->request_location
    cJSON *request_location = cJSON_GetObjectItemCaseSensitive(keyboard_buttonJSON, "request_location");
    if (cJSON_IsNull(request_location)) {
        request_location = NULL;
    }
    if (request_location) { 
    if(!cJSON_IsBool(request_location))
    {
    goto end; //Bool
    }
    }

    // keyboard_button->request_poll
    cJSON *request_poll = cJSON_GetObjectItemCaseSensitive(keyboard_buttonJSON, "request_poll");
    if (cJSON_IsNull(request_poll)) {
        request_poll = NULL;
    }
    if (request_poll) { 
    request_poll_local_nonprim = keyboard_button_poll_type_parseFromJSON(request_poll); //nonprimitive
    }

    // keyboard_button->web_app
    cJSON *web_app = cJSON_GetObjectItemCaseSensitive(keyboard_buttonJSON, "web_app");
    if (cJSON_IsNull(web_app)) {
        web_app = NULL;
    }
    if (web_app) { 
    web_app_local_nonprim = web_app_info_parseFromJSON(web_app); //nonprimitive
    }


    keyboard_button_local_var = keyboard_button_create_internal (
        strdup(text->valuestring),
        request_users ? request_users_local_nonprim : NULL,
        request_chat ? request_chat_local_nonprim : NULL,
        request_contact ? request_contact->valueint : 0,
        request_location ? request_location->valueint : 0,
        request_poll ? request_poll_local_nonprim : NULL,
        web_app ? web_app_local_nonprim : NULL
        );

    return keyboard_button_local_var;
end:
    if (request_users_local_nonprim) {
        keyboard_button_request_users_free(request_users_local_nonprim);
        request_users_local_nonprim = NULL;
    }
    if (request_chat_local_nonprim) {
        keyboard_button_request_chat_free(request_chat_local_nonprim);
        request_chat_local_nonprim = NULL;
    }
    if (request_poll_local_nonprim) {
        keyboard_button_poll_type_free(request_poll_local_nonprim);
        request_poll_local_nonprim = NULL;
    }
    if (web_app_local_nonprim) {
        web_app_info_free(web_app_local_nonprim);
        web_app_local_nonprim = NULL;
    }
    return NULL;

}
