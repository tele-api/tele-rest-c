#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "keyboard_button_request_users.h"



static keyboard_button_request_users_t *keyboard_button_request_users_create_internal(
    int request_id,
    int user_is_bot,
    int user_is_premium,
    int max_quantity,
    int request_name,
    int request_username,
    int request_photo
    ) {
    keyboard_button_request_users_t *keyboard_button_request_users_local_var = malloc(sizeof(keyboard_button_request_users_t));
    if (!keyboard_button_request_users_local_var) {
        return NULL;
    }
    keyboard_button_request_users_local_var->request_id = request_id;
    keyboard_button_request_users_local_var->user_is_bot = user_is_bot;
    keyboard_button_request_users_local_var->user_is_premium = user_is_premium;
    keyboard_button_request_users_local_var->max_quantity = max_quantity;
    keyboard_button_request_users_local_var->request_name = request_name;
    keyboard_button_request_users_local_var->request_username = request_username;
    keyboard_button_request_users_local_var->request_photo = request_photo;

    keyboard_button_request_users_local_var->_library_owned = 1;
    return keyboard_button_request_users_local_var;
}

__attribute__((deprecated)) keyboard_button_request_users_t *keyboard_button_request_users_create(
    int request_id,
    int user_is_bot,
    int user_is_premium,
    int max_quantity,
    int request_name,
    int request_username,
    int request_photo
    ) {
    return keyboard_button_request_users_create_internal (
        request_id,
        user_is_bot,
        user_is_premium,
        max_quantity,
        request_name,
        request_username,
        request_photo
        );
}

void keyboard_button_request_users_free(keyboard_button_request_users_t *keyboard_button_request_users) {
    if(NULL == keyboard_button_request_users){
        return ;
    }
    if(keyboard_button_request_users->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "keyboard_button_request_users_free");
        return ;
    }
    listEntry_t *listEntry;
    free(keyboard_button_request_users);
}

cJSON *keyboard_button_request_users_convertToJSON(keyboard_button_request_users_t *keyboard_button_request_users) {
    cJSON *item = cJSON_CreateObject();

    // keyboard_button_request_users->request_id
    if (!keyboard_button_request_users->request_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "request_id", keyboard_button_request_users->request_id) == NULL) {
    goto fail; //Numeric
    }


    // keyboard_button_request_users->user_is_bot
    if(keyboard_button_request_users->user_is_bot) {
    if(cJSON_AddBoolToObject(item, "user_is_bot", keyboard_button_request_users->user_is_bot) == NULL) {
    goto fail; //Bool
    }
    }


    // keyboard_button_request_users->user_is_premium
    if(keyboard_button_request_users->user_is_premium) {
    if(cJSON_AddBoolToObject(item, "user_is_premium", keyboard_button_request_users->user_is_premium) == NULL) {
    goto fail; //Bool
    }
    }


    // keyboard_button_request_users->max_quantity
    if(keyboard_button_request_users->max_quantity) {
    if(cJSON_AddNumberToObject(item, "max_quantity", keyboard_button_request_users->max_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // keyboard_button_request_users->request_name
    if(keyboard_button_request_users->request_name) {
    if(cJSON_AddBoolToObject(item, "request_name", keyboard_button_request_users->request_name) == NULL) {
    goto fail; //Bool
    }
    }


    // keyboard_button_request_users->request_username
    if(keyboard_button_request_users->request_username) {
    if(cJSON_AddBoolToObject(item, "request_username", keyboard_button_request_users->request_username) == NULL) {
    goto fail; //Bool
    }
    }


    // keyboard_button_request_users->request_photo
    if(keyboard_button_request_users->request_photo) {
    if(cJSON_AddBoolToObject(item, "request_photo", keyboard_button_request_users->request_photo) == NULL) {
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

keyboard_button_request_users_t *keyboard_button_request_users_parseFromJSON(cJSON *keyboard_button_request_usersJSON){

    keyboard_button_request_users_t *keyboard_button_request_users_local_var = NULL;

    // keyboard_button_request_users->request_id
    cJSON *request_id = cJSON_GetObjectItemCaseSensitive(keyboard_button_request_usersJSON, "request_id");
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

    // keyboard_button_request_users->user_is_bot
    cJSON *user_is_bot = cJSON_GetObjectItemCaseSensitive(keyboard_button_request_usersJSON, "user_is_bot");
    if (cJSON_IsNull(user_is_bot)) {
        user_is_bot = NULL;
    }
    if (user_is_bot) { 
    if(!cJSON_IsBool(user_is_bot))
    {
    goto end; //Bool
    }
    }

    // keyboard_button_request_users->user_is_premium
    cJSON *user_is_premium = cJSON_GetObjectItemCaseSensitive(keyboard_button_request_usersJSON, "user_is_premium");
    if (cJSON_IsNull(user_is_premium)) {
        user_is_premium = NULL;
    }
    if (user_is_premium) { 
    if(!cJSON_IsBool(user_is_premium))
    {
    goto end; //Bool
    }
    }

    // keyboard_button_request_users->max_quantity
    cJSON *max_quantity = cJSON_GetObjectItemCaseSensitive(keyboard_button_request_usersJSON, "max_quantity");
    if (cJSON_IsNull(max_quantity)) {
        max_quantity = NULL;
    }
    if (max_quantity) { 
    if(!cJSON_IsNumber(max_quantity))
    {
    goto end; //Numeric
    }
    }

    // keyboard_button_request_users->request_name
    cJSON *request_name = cJSON_GetObjectItemCaseSensitive(keyboard_button_request_usersJSON, "request_name");
    if (cJSON_IsNull(request_name)) {
        request_name = NULL;
    }
    if (request_name) { 
    if(!cJSON_IsBool(request_name))
    {
    goto end; //Bool
    }
    }

    // keyboard_button_request_users->request_username
    cJSON *request_username = cJSON_GetObjectItemCaseSensitive(keyboard_button_request_usersJSON, "request_username");
    if (cJSON_IsNull(request_username)) {
        request_username = NULL;
    }
    if (request_username) { 
    if(!cJSON_IsBool(request_username))
    {
    goto end; //Bool
    }
    }

    // keyboard_button_request_users->request_photo
    cJSON *request_photo = cJSON_GetObjectItemCaseSensitive(keyboard_button_request_usersJSON, "request_photo");
    if (cJSON_IsNull(request_photo)) {
        request_photo = NULL;
    }
    if (request_photo) { 
    if(!cJSON_IsBool(request_photo))
    {
    goto end; //Bool
    }
    }


    keyboard_button_request_users_local_var = keyboard_button_request_users_create_internal (
        request_id->valuedouble,
        user_is_bot ? user_is_bot->valueint : 0,
        user_is_premium ? user_is_premium->valueint : 0,
        max_quantity ? max_quantity->valuedouble : 0,
        request_name ? request_name->valueint : 0,
        request_username ? request_username->valueint : 0,
        request_photo ? request_photo->valueint : 0
        );

    return keyboard_button_request_users_local_var;
end:
    return NULL;

}
