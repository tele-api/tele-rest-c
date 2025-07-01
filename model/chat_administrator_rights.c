#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_administrator_rights.h"



static chat_administrator_rights_t *chat_administrator_rights_create_internal(
    int is_anonymous,
    int can_manage_chat,
    int can_delete_messages,
    int can_manage_video_chats,
    int can_restrict_members,
    int can_promote_members,
    int can_change_info,
    int can_invite_users,
    int can_post_stories,
    int can_edit_stories,
    int can_delete_stories,
    int can_post_messages,
    int can_edit_messages,
    int can_pin_messages,
    int can_manage_topics
    ) {
    chat_administrator_rights_t *chat_administrator_rights_local_var = malloc(sizeof(chat_administrator_rights_t));
    if (!chat_administrator_rights_local_var) {
        return NULL;
    }
    chat_administrator_rights_local_var->is_anonymous = is_anonymous;
    chat_administrator_rights_local_var->can_manage_chat = can_manage_chat;
    chat_administrator_rights_local_var->can_delete_messages = can_delete_messages;
    chat_administrator_rights_local_var->can_manage_video_chats = can_manage_video_chats;
    chat_administrator_rights_local_var->can_restrict_members = can_restrict_members;
    chat_administrator_rights_local_var->can_promote_members = can_promote_members;
    chat_administrator_rights_local_var->can_change_info = can_change_info;
    chat_administrator_rights_local_var->can_invite_users = can_invite_users;
    chat_administrator_rights_local_var->can_post_stories = can_post_stories;
    chat_administrator_rights_local_var->can_edit_stories = can_edit_stories;
    chat_administrator_rights_local_var->can_delete_stories = can_delete_stories;
    chat_administrator_rights_local_var->can_post_messages = can_post_messages;
    chat_administrator_rights_local_var->can_edit_messages = can_edit_messages;
    chat_administrator_rights_local_var->can_pin_messages = can_pin_messages;
    chat_administrator_rights_local_var->can_manage_topics = can_manage_topics;

    chat_administrator_rights_local_var->_library_owned = 1;
    return chat_administrator_rights_local_var;
}

__attribute__((deprecated)) chat_administrator_rights_t *chat_administrator_rights_create(
    int is_anonymous,
    int can_manage_chat,
    int can_delete_messages,
    int can_manage_video_chats,
    int can_restrict_members,
    int can_promote_members,
    int can_change_info,
    int can_invite_users,
    int can_post_stories,
    int can_edit_stories,
    int can_delete_stories,
    int can_post_messages,
    int can_edit_messages,
    int can_pin_messages,
    int can_manage_topics
    ) {
    return chat_administrator_rights_create_internal (
        is_anonymous,
        can_manage_chat,
        can_delete_messages,
        can_manage_video_chats,
        can_restrict_members,
        can_promote_members,
        can_change_info,
        can_invite_users,
        can_post_stories,
        can_edit_stories,
        can_delete_stories,
        can_post_messages,
        can_edit_messages,
        can_pin_messages,
        can_manage_topics
        );
}

void chat_administrator_rights_free(chat_administrator_rights_t *chat_administrator_rights) {
    if(NULL == chat_administrator_rights){
        return ;
    }
    if(chat_administrator_rights->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_administrator_rights_free");
        return ;
    }
    listEntry_t *listEntry;
    free(chat_administrator_rights);
}

cJSON *chat_administrator_rights_convertToJSON(chat_administrator_rights_t *chat_administrator_rights) {
    cJSON *item = cJSON_CreateObject();

    // chat_administrator_rights->is_anonymous
    if (!chat_administrator_rights->is_anonymous) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_anonymous", chat_administrator_rights->is_anonymous) == NULL) {
    goto fail; //Bool
    }


    // chat_administrator_rights->can_manage_chat
    if (!chat_administrator_rights->can_manage_chat) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_manage_chat", chat_administrator_rights->can_manage_chat) == NULL) {
    goto fail; //Bool
    }


    // chat_administrator_rights->can_delete_messages
    if (!chat_administrator_rights->can_delete_messages) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_delete_messages", chat_administrator_rights->can_delete_messages) == NULL) {
    goto fail; //Bool
    }


    // chat_administrator_rights->can_manage_video_chats
    if (!chat_administrator_rights->can_manage_video_chats) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_manage_video_chats", chat_administrator_rights->can_manage_video_chats) == NULL) {
    goto fail; //Bool
    }


    // chat_administrator_rights->can_restrict_members
    if (!chat_administrator_rights->can_restrict_members) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_restrict_members", chat_administrator_rights->can_restrict_members) == NULL) {
    goto fail; //Bool
    }


    // chat_administrator_rights->can_promote_members
    if (!chat_administrator_rights->can_promote_members) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_promote_members", chat_administrator_rights->can_promote_members) == NULL) {
    goto fail; //Bool
    }


    // chat_administrator_rights->can_change_info
    if (!chat_administrator_rights->can_change_info) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_change_info", chat_administrator_rights->can_change_info) == NULL) {
    goto fail; //Bool
    }


    // chat_administrator_rights->can_invite_users
    if (!chat_administrator_rights->can_invite_users) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_invite_users", chat_administrator_rights->can_invite_users) == NULL) {
    goto fail; //Bool
    }


    // chat_administrator_rights->can_post_stories
    if (!chat_administrator_rights->can_post_stories) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_post_stories", chat_administrator_rights->can_post_stories) == NULL) {
    goto fail; //Bool
    }


    // chat_administrator_rights->can_edit_stories
    if (!chat_administrator_rights->can_edit_stories) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_edit_stories", chat_administrator_rights->can_edit_stories) == NULL) {
    goto fail; //Bool
    }


    // chat_administrator_rights->can_delete_stories
    if (!chat_administrator_rights->can_delete_stories) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_delete_stories", chat_administrator_rights->can_delete_stories) == NULL) {
    goto fail; //Bool
    }


    // chat_administrator_rights->can_post_messages
    if(chat_administrator_rights->can_post_messages) {
    if(cJSON_AddBoolToObject(item, "can_post_messages", chat_administrator_rights->can_post_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_administrator_rights->can_edit_messages
    if(chat_administrator_rights->can_edit_messages) {
    if(cJSON_AddBoolToObject(item, "can_edit_messages", chat_administrator_rights->can_edit_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_administrator_rights->can_pin_messages
    if(chat_administrator_rights->can_pin_messages) {
    if(cJSON_AddBoolToObject(item, "can_pin_messages", chat_administrator_rights->can_pin_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_administrator_rights->can_manage_topics
    if(chat_administrator_rights->can_manage_topics) {
    if(cJSON_AddBoolToObject(item, "can_manage_topics", chat_administrator_rights->can_manage_topics) == NULL) {
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

chat_administrator_rights_t *chat_administrator_rights_parseFromJSON(cJSON *chat_administrator_rightsJSON){

    chat_administrator_rights_t *chat_administrator_rights_local_var = NULL;

    // chat_administrator_rights->is_anonymous
    cJSON *is_anonymous = cJSON_GetObjectItemCaseSensitive(chat_administrator_rightsJSON, "is_anonymous");
    if (cJSON_IsNull(is_anonymous)) {
        is_anonymous = NULL;
    }
    if (!is_anonymous) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_anonymous))
    {
    goto end; //Bool
    }

    // chat_administrator_rights->can_manage_chat
    cJSON *can_manage_chat = cJSON_GetObjectItemCaseSensitive(chat_administrator_rightsJSON, "can_manage_chat");
    if (cJSON_IsNull(can_manage_chat)) {
        can_manage_chat = NULL;
    }
    if (!can_manage_chat) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_manage_chat))
    {
    goto end; //Bool
    }

    // chat_administrator_rights->can_delete_messages
    cJSON *can_delete_messages = cJSON_GetObjectItemCaseSensitive(chat_administrator_rightsJSON, "can_delete_messages");
    if (cJSON_IsNull(can_delete_messages)) {
        can_delete_messages = NULL;
    }
    if (!can_delete_messages) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_delete_messages))
    {
    goto end; //Bool
    }

    // chat_administrator_rights->can_manage_video_chats
    cJSON *can_manage_video_chats = cJSON_GetObjectItemCaseSensitive(chat_administrator_rightsJSON, "can_manage_video_chats");
    if (cJSON_IsNull(can_manage_video_chats)) {
        can_manage_video_chats = NULL;
    }
    if (!can_manage_video_chats) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_manage_video_chats))
    {
    goto end; //Bool
    }

    // chat_administrator_rights->can_restrict_members
    cJSON *can_restrict_members = cJSON_GetObjectItemCaseSensitive(chat_administrator_rightsJSON, "can_restrict_members");
    if (cJSON_IsNull(can_restrict_members)) {
        can_restrict_members = NULL;
    }
    if (!can_restrict_members) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_restrict_members))
    {
    goto end; //Bool
    }

    // chat_administrator_rights->can_promote_members
    cJSON *can_promote_members = cJSON_GetObjectItemCaseSensitive(chat_administrator_rightsJSON, "can_promote_members");
    if (cJSON_IsNull(can_promote_members)) {
        can_promote_members = NULL;
    }
    if (!can_promote_members) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_promote_members))
    {
    goto end; //Bool
    }

    // chat_administrator_rights->can_change_info
    cJSON *can_change_info = cJSON_GetObjectItemCaseSensitive(chat_administrator_rightsJSON, "can_change_info");
    if (cJSON_IsNull(can_change_info)) {
        can_change_info = NULL;
    }
    if (!can_change_info) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_change_info))
    {
    goto end; //Bool
    }

    // chat_administrator_rights->can_invite_users
    cJSON *can_invite_users = cJSON_GetObjectItemCaseSensitive(chat_administrator_rightsJSON, "can_invite_users");
    if (cJSON_IsNull(can_invite_users)) {
        can_invite_users = NULL;
    }
    if (!can_invite_users) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_invite_users))
    {
    goto end; //Bool
    }

    // chat_administrator_rights->can_post_stories
    cJSON *can_post_stories = cJSON_GetObjectItemCaseSensitive(chat_administrator_rightsJSON, "can_post_stories");
    if (cJSON_IsNull(can_post_stories)) {
        can_post_stories = NULL;
    }
    if (!can_post_stories) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_post_stories))
    {
    goto end; //Bool
    }

    // chat_administrator_rights->can_edit_stories
    cJSON *can_edit_stories = cJSON_GetObjectItemCaseSensitive(chat_administrator_rightsJSON, "can_edit_stories");
    if (cJSON_IsNull(can_edit_stories)) {
        can_edit_stories = NULL;
    }
    if (!can_edit_stories) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_edit_stories))
    {
    goto end; //Bool
    }

    // chat_administrator_rights->can_delete_stories
    cJSON *can_delete_stories = cJSON_GetObjectItemCaseSensitive(chat_administrator_rightsJSON, "can_delete_stories");
    if (cJSON_IsNull(can_delete_stories)) {
        can_delete_stories = NULL;
    }
    if (!can_delete_stories) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_delete_stories))
    {
    goto end; //Bool
    }

    // chat_administrator_rights->can_post_messages
    cJSON *can_post_messages = cJSON_GetObjectItemCaseSensitive(chat_administrator_rightsJSON, "can_post_messages");
    if (cJSON_IsNull(can_post_messages)) {
        can_post_messages = NULL;
    }
    if (can_post_messages) { 
    if(!cJSON_IsBool(can_post_messages))
    {
    goto end; //Bool
    }
    }

    // chat_administrator_rights->can_edit_messages
    cJSON *can_edit_messages = cJSON_GetObjectItemCaseSensitive(chat_administrator_rightsJSON, "can_edit_messages");
    if (cJSON_IsNull(can_edit_messages)) {
        can_edit_messages = NULL;
    }
    if (can_edit_messages) { 
    if(!cJSON_IsBool(can_edit_messages))
    {
    goto end; //Bool
    }
    }

    // chat_administrator_rights->can_pin_messages
    cJSON *can_pin_messages = cJSON_GetObjectItemCaseSensitive(chat_administrator_rightsJSON, "can_pin_messages");
    if (cJSON_IsNull(can_pin_messages)) {
        can_pin_messages = NULL;
    }
    if (can_pin_messages) { 
    if(!cJSON_IsBool(can_pin_messages))
    {
    goto end; //Bool
    }
    }

    // chat_administrator_rights->can_manage_topics
    cJSON *can_manage_topics = cJSON_GetObjectItemCaseSensitive(chat_administrator_rightsJSON, "can_manage_topics");
    if (cJSON_IsNull(can_manage_topics)) {
        can_manage_topics = NULL;
    }
    if (can_manage_topics) { 
    if(!cJSON_IsBool(can_manage_topics))
    {
    goto end; //Bool
    }
    }


    chat_administrator_rights_local_var = chat_administrator_rights_create_internal (
        is_anonymous->valueint,
        can_manage_chat->valueint,
        can_delete_messages->valueint,
        can_manage_video_chats->valueint,
        can_restrict_members->valueint,
        can_promote_members->valueint,
        can_change_info->valueint,
        can_invite_users->valueint,
        can_post_stories->valueint,
        can_edit_stories->valueint,
        can_delete_stories->valueint,
        can_post_messages ? can_post_messages->valueint : 0,
        can_edit_messages ? can_edit_messages->valueint : 0,
        can_pin_messages ? can_pin_messages->valueint : 0,
        can_manage_topics ? can_manage_topics->valueint : 0
        );

    return chat_administrator_rights_local_var;
end:
    return NULL;

}
