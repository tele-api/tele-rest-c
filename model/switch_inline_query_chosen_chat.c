#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "switch_inline_query_chosen_chat.h"



static switch_inline_query_chosen_chat_t *switch_inline_query_chosen_chat_create_internal(
    char *query,
    int allow_user_chats,
    int allow_bot_chats,
    int allow_group_chats,
    int allow_channel_chats
    ) {
    switch_inline_query_chosen_chat_t *switch_inline_query_chosen_chat_local_var = malloc(sizeof(switch_inline_query_chosen_chat_t));
    if (!switch_inline_query_chosen_chat_local_var) {
        return NULL;
    }
    switch_inline_query_chosen_chat_local_var->query = query;
    switch_inline_query_chosen_chat_local_var->allow_user_chats = allow_user_chats;
    switch_inline_query_chosen_chat_local_var->allow_bot_chats = allow_bot_chats;
    switch_inline_query_chosen_chat_local_var->allow_group_chats = allow_group_chats;
    switch_inline_query_chosen_chat_local_var->allow_channel_chats = allow_channel_chats;

    switch_inline_query_chosen_chat_local_var->_library_owned = 1;
    return switch_inline_query_chosen_chat_local_var;
}

__attribute__((deprecated)) switch_inline_query_chosen_chat_t *switch_inline_query_chosen_chat_create(
    char *query,
    int allow_user_chats,
    int allow_bot_chats,
    int allow_group_chats,
    int allow_channel_chats
    ) {
    return switch_inline_query_chosen_chat_create_internal (
        query,
        allow_user_chats,
        allow_bot_chats,
        allow_group_chats,
        allow_channel_chats
        );
}

void switch_inline_query_chosen_chat_free(switch_inline_query_chosen_chat_t *switch_inline_query_chosen_chat) {
    if(NULL == switch_inline_query_chosen_chat){
        return ;
    }
    if(switch_inline_query_chosen_chat->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "switch_inline_query_chosen_chat_free");
        return ;
    }
    listEntry_t *listEntry;
    if (switch_inline_query_chosen_chat->query) {
        free(switch_inline_query_chosen_chat->query);
        switch_inline_query_chosen_chat->query = NULL;
    }
    free(switch_inline_query_chosen_chat);
}

cJSON *switch_inline_query_chosen_chat_convertToJSON(switch_inline_query_chosen_chat_t *switch_inline_query_chosen_chat) {
    cJSON *item = cJSON_CreateObject();

    // switch_inline_query_chosen_chat->query
    if(switch_inline_query_chosen_chat->query) {
    if(cJSON_AddStringToObject(item, "query", switch_inline_query_chosen_chat->query) == NULL) {
    goto fail; //String
    }
    }


    // switch_inline_query_chosen_chat->allow_user_chats
    if(switch_inline_query_chosen_chat->allow_user_chats) {
    if(cJSON_AddBoolToObject(item, "allow_user_chats", switch_inline_query_chosen_chat->allow_user_chats) == NULL) {
    goto fail; //Bool
    }
    }


    // switch_inline_query_chosen_chat->allow_bot_chats
    if(switch_inline_query_chosen_chat->allow_bot_chats) {
    if(cJSON_AddBoolToObject(item, "allow_bot_chats", switch_inline_query_chosen_chat->allow_bot_chats) == NULL) {
    goto fail; //Bool
    }
    }


    // switch_inline_query_chosen_chat->allow_group_chats
    if(switch_inline_query_chosen_chat->allow_group_chats) {
    if(cJSON_AddBoolToObject(item, "allow_group_chats", switch_inline_query_chosen_chat->allow_group_chats) == NULL) {
    goto fail; //Bool
    }
    }


    // switch_inline_query_chosen_chat->allow_channel_chats
    if(switch_inline_query_chosen_chat->allow_channel_chats) {
    if(cJSON_AddBoolToObject(item, "allow_channel_chats", switch_inline_query_chosen_chat->allow_channel_chats) == NULL) {
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

switch_inline_query_chosen_chat_t *switch_inline_query_chosen_chat_parseFromJSON(cJSON *switch_inline_query_chosen_chatJSON){

    switch_inline_query_chosen_chat_t *switch_inline_query_chosen_chat_local_var = NULL;

    // switch_inline_query_chosen_chat->query
    cJSON *query = cJSON_GetObjectItemCaseSensitive(switch_inline_query_chosen_chatJSON, "query");
    if (cJSON_IsNull(query)) {
        query = NULL;
    }
    if (query) { 
    if(!cJSON_IsString(query) && !cJSON_IsNull(query))
    {
    goto end; //String
    }
    }

    // switch_inline_query_chosen_chat->allow_user_chats
    cJSON *allow_user_chats = cJSON_GetObjectItemCaseSensitive(switch_inline_query_chosen_chatJSON, "allow_user_chats");
    if (cJSON_IsNull(allow_user_chats)) {
        allow_user_chats = NULL;
    }
    if (allow_user_chats) { 
    if(!cJSON_IsBool(allow_user_chats))
    {
    goto end; //Bool
    }
    }

    // switch_inline_query_chosen_chat->allow_bot_chats
    cJSON *allow_bot_chats = cJSON_GetObjectItemCaseSensitive(switch_inline_query_chosen_chatJSON, "allow_bot_chats");
    if (cJSON_IsNull(allow_bot_chats)) {
        allow_bot_chats = NULL;
    }
    if (allow_bot_chats) { 
    if(!cJSON_IsBool(allow_bot_chats))
    {
    goto end; //Bool
    }
    }

    // switch_inline_query_chosen_chat->allow_group_chats
    cJSON *allow_group_chats = cJSON_GetObjectItemCaseSensitive(switch_inline_query_chosen_chatJSON, "allow_group_chats");
    if (cJSON_IsNull(allow_group_chats)) {
        allow_group_chats = NULL;
    }
    if (allow_group_chats) { 
    if(!cJSON_IsBool(allow_group_chats))
    {
    goto end; //Bool
    }
    }

    // switch_inline_query_chosen_chat->allow_channel_chats
    cJSON *allow_channel_chats = cJSON_GetObjectItemCaseSensitive(switch_inline_query_chosen_chatJSON, "allow_channel_chats");
    if (cJSON_IsNull(allow_channel_chats)) {
        allow_channel_chats = NULL;
    }
    if (allow_channel_chats) { 
    if(!cJSON_IsBool(allow_channel_chats))
    {
    goto end; //Bool
    }
    }


    switch_inline_query_chosen_chat_local_var = switch_inline_query_chosen_chat_create_internal (
        query && !cJSON_IsNull(query) ? strdup(query->valuestring) : NULL,
        allow_user_chats ? allow_user_chats->valueint : 0,
        allow_bot_chats ? allow_bot_chats->valueint : 0,
        allow_group_chats ? allow_group_chats->valueint : 0,
        allow_channel_chats ? allow_channel_chats->valueint : 0
        );

    return switch_inline_query_chosen_chat_local_var;
end:
    return NULL;

}
