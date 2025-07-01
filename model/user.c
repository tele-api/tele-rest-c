#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user.h"



static user_t *user_create_internal(
    int id,
    int is_bot,
    char *first_name,
    char *last_name,
    char *username,
    char *language_code,
    int is_premium,
    int added_to_attachment_menu,
    int can_join_groups,
    int can_read_all_group_messages,
    int supports_inline_queries,
    int can_connect_to_business,
    int has_main_web_app
    ) {
    user_t *user_local_var = malloc(sizeof(user_t));
    if (!user_local_var) {
        return NULL;
    }
    user_local_var->id = id;
    user_local_var->is_bot = is_bot;
    user_local_var->first_name = first_name;
    user_local_var->last_name = last_name;
    user_local_var->username = username;
    user_local_var->language_code = language_code;
    user_local_var->is_premium = is_premium;
    user_local_var->added_to_attachment_menu = added_to_attachment_menu;
    user_local_var->can_join_groups = can_join_groups;
    user_local_var->can_read_all_group_messages = can_read_all_group_messages;
    user_local_var->supports_inline_queries = supports_inline_queries;
    user_local_var->can_connect_to_business = can_connect_to_business;
    user_local_var->has_main_web_app = has_main_web_app;

    user_local_var->_library_owned = 1;
    return user_local_var;
}

__attribute__((deprecated)) user_t *user_create(
    int id,
    int is_bot,
    char *first_name,
    char *last_name,
    char *username,
    char *language_code,
    int is_premium,
    int added_to_attachment_menu,
    int can_join_groups,
    int can_read_all_group_messages,
    int supports_inline_queries,
    int can_connect_to_business,
    int has_main_web_app
    ) {
    return user_create_internal (
        id,
        is_bot,
        first_name,
        last_name,
        username,
        language_code,
        is_premium,
        added_to_attachment_menu,
        can_join_groups,
        can_read_all_group_messages,
        supports_inline_queries,
        can_connect_to_business,
        has_main_web_app
        );
}

void user_free(user_t *user) {
    if(NULL == user){
        return ;
    }
    if(user->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "user_free");
        return ;
    }
    listEntry_t *listEntry;
    if (user->first_name) {
        free(user->first_name);
        user->first_name = NULL;
    }
    if (user->last_name) {
        free(user->last_name);
        user->last_name = NULL;
    }
    if (user->username) {
        free(user->username);
        user->username = NULL;
    }
    if (user->language_code) {
        free(user->language_code);
        user->language_code = NULL;
    }
    free(user);
}

cJSON *user_convertToJSON(user_t *user) {
    cJSON *item = cJSON_CreateObject();

    // user->id
    if (!user->id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "id", user->id) == NULL) {
    goto fail; //Numeric
    }


    // user->is_bot
    if (!user->is_bot) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_bot", user->is_bot) == NULL) {
    goto fail; //Bool
    }


    // user->first_name
    if (!user->first_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "first_name", user->first_name) == NULL) {
    goto fail; //String
    }


    // user->last_name
    if(user->last_name) {
    if(cJSON_AddStringToObject(item, "last_name", user->last_name) == NULL) {
    goto fail; //String
    }
    }


    // user->username
    if(user->username) {
    if(cJSON_AddStringToObject(item, "username", user->username) == NULL) {
    goto fail; //String
    }
    }


    // user->language_code
    if(user->language_code) {
    if(cJSON_AddStringToObject(item, "language_code", user->language_code) == NULL) {
    goto fail; //String
    }
    }


    // user->is_premium
    if(user->is_premium) {
    if(cJSON_AddBoolToObject(item, "is_premium", user->is_premium) == NULL) {
    goto fail; //Bool
    }
    }


    // user->added_to_attachment_menu
    if(user->added_to_attachment_menu) {
    if(cJSON_AddBoolToObject(item, "added_to_attachment_menu", user->added_to_attachment_menu) == NULL) {
    goto fail; //Bool
    }
    }


    // user->can_join_groups
    if(user->can_join_groups) {
    if(cJSON_AddBoolToObject(item, "can_join_groups", user->can_join_groups) == NULL) {
    goto fail; //Bool
    }
    }


    // user->can_read_all_group_messages
    if(user->can_read_all_group_messages) {
    if(cJSON_AddBoolToObject(item, "can_read_all_group_messages", user->can_read_all_group_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // user->supports_inline_queries
    if(user->supports_inline_queries) {
    if(cJSON_AddBoolToObject(item, "supports_inline_queries", user->supports_inline_queries) == NULL) {
    goto fail; //Bool
    }
    }


    // user->can_connect_to_business
    if(user->can_connect_to_business) {
    if(cJSON_AddBoolToObject(item, "can_connect_to_business", user->can_connect_to_business) == NULL) {
    goto fail; //Bool
    }
    }


    // user->has_main_web_app
    if(user->has_main_web_app) {
    if(cJSON_AddBoolToObject(item, "has_main_web_app", user->has_main_web_app) == NULL) {
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

user_t *user_parseFromJSON(cJSON *userJSON){

    user_t *user_local_var = NULL;

    // user->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(userJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(id))
    {
    goto end; //Numeric
    }

    // user->is_bot
    cJSON *is_bot = cJSON_GetObjectItemCaseSensitive(userJSON, "is_bot");
    if (cJSON_IsNull(is_bot)) {
        is_bot = NULL;
    }
    if (!is_bot) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_bot))
    {
    goto end; //Bool
    }

    // user->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(userJSON, "first_name");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (!first_name) {
        goto end;
    }

    
    if(!cJSON_IsString(first_name))
    {
    goto end; //String
    }

    // user->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(userJSON, "last_name");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }

    // user->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(userJSON, "username");
    if (cJSON_IsNull(username)) {
        username = NULL;
    }
    if (username) { 
    if(!cJSON_IsString(username) && !cJSON_IsNull(username))
    {
    goto end; //String
    }
    }

    // user->language_code
    cJSON *language_code = cJSON_GetObjectItemCaseSensitive(userJSON, "language_code");
    if (cJSON_IsNull(language_code)) {
        language_code = NULL;
    }
    if (language_code) { 
    if(!cJSON_IsString(language_code) && !cJSON_IsNull(language_code))
    {
    goto end; //String
    }
    }

    // user->is_premium
    cJSON *is_premium = cJSON_GetObjectItemCaseSensitive(userJSON, "is_premium");
    if (cJSON_IsNull(is_premium)) {
        is_premium = NULL;
    }
    if (is_premium) { 
    if(!cJSON_IsBool(is_premium))
    {
    goto end; //Bool
    }
    }

    // user->added_to_attachment_menu
    cJSON *added_to_attachment_menu = cJSON_GetObjectItemCaseSensitive(userJSON, "added_to_attachment_menu");
    if (cJSON_IsNull(added_to_attachment_menu)) {
        added_to_attachment_menu = NULL;
    }
    if (added_to_attachment_menu) { 
    if(!cJSON_IsBool(added_to_attachment_menu))
    {
    goto end; //Bool
    }
    }

    // user->can_join_groups
    cJSON *can_join_groups = cJSON_GetObjectItemCaseSensitive(userJSON, "can_join_groups");
    if (cJSON_IsNull(can_join_groups)) {
        can_join_groups = NULL;
    }
    if (can_join_groups) { 
    if(!cJSON_IsBool(can_join_groups))
    {
    goto end; //Bool
    }
    }

    // user->can_read_all_group_messages
    cJSON *can_read_all_group_messages = cJSON_GetObjectItemCaseSensitive(userJSON, "can_read_all_group_messages");
    if (cJSON_IsNull(can_read_all_group_messages)) {
        can_read_all_group_messages = NULL;
    }
    if (can_read_all_group_messages) { 
    if(!cJSON_IsBool(can_read_all_group_messages))
    {
    goto end; //Bool
    }
    }

    // user->supports_inline_queries
    cJSON *supports_inline_queries = cJSON_GetObjectItemCaseSensitive(userJSON, "supports_inline_queries");
    if (cJSON_IsNull(supports_inline_queries)) {
        supports_inline_queries = NULL;
    }
    if (supports_inline_queries) { 
    if(!cJSON_IsBool(supports_inline_queries))
    {
    goto end; //Bool
    }
    }

    // user->can_connect_to_business
    cJSON *can_connect_to_business = cJSON_GetObjectItemCaseSensitive(userJSON, "can_connect_to_business");
    if (cJSON_IsNull(can_connect_to_business)) {
        can_connect_to_business = NULL;
    }
    if (can_connect_to_business) { 
    if(!cJSON_IsBool(can_connect_to_business))
    {
    goto end; //Bool
    }
    }

    // user->has_main_web_app
    cJSON *has_main_web_app = cJSON_GetObjectItemCaseSensitive(userJSON, "has_main_web_app");
    if (cJSON_IsNull(has_main_web_app)) {
        has_main_web_app = NULL;
    }
    if (has_main_web_app) { 
    if(!cJSON_IsBool(has_main_web_app))
    {
    goto end; //Bool
    }
    }


    user_local_var = user_create_internal (
        id->valuedouble,
        is_bot->valueint,
        strdup(first_name->valuestring),
        last_name && !cJSON_IsNull(last_name) ? strdup(last_name->valuestring) : NULL,
        username && !cJSON_IsNull(username) ? strdup(username->valuestring) : NULL,
        language_code && !cJSON_IsNull(language_code) ? strdup(language_code->valuestring) : NULL,
        is_premium ? is_premium->valueint : 0,
        added_to_attachment_menu ? added_to_attachment_menu->valueint : 0,
        can_join_groups ? can_join_groups->valueint : 0,
        can_read_all_group_messages ? can_read_all_group_messages->valueint : 0,
        supports_inline_queries ? supports_inline_queries->valueint : 0,
        can_connect_to_business ? can_connect_to_business->valueint : 0,
        has_main_web_app ? has_main_web_app->valueint : 0
        );

    return user_local_var;
end:
    return NULL;

}
