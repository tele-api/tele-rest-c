#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "promote_chat_member_request.h"



static promote_chat_member_request_t *promote_chat_member_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    int user_id,
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
    promote_chat_member_request_t *promote_chat_member_request_local_var = malloc(sizeof(promote_chat_member_request_t));
    if (!promote_chat_member_request_local_var) {
        return NULL;
    }
    promote_chat_member_request_local_var->chat_id = chat_id;
    promote_chat_member_request_local_var->user_id = user_id;
    promote_chat_member_request_local_var->is_anonymous = is_anonymous;
    promote_chat_member_request_local_var->can_manage_chat = can_manage_chat;
    promote_chat_member_request_local_var->can_delete_messages = can_delete_messages;
    promote_chat_member_request_local_var->can_manage_video_chats = can_manage_video_chats;
    promote_chat_member_request_local_var->can_restrict_members = can_restrict_members;
    promote_chat_member_request_local_var->can_promote_members = can_promote_members;
    promote_chat_member_request_local_var->can_change_info = can_change_info;
    promote_chat_member_request_local_var->can_invite_users = can_invite_users;
    promote_chat_member_request_local_var->can_post_stories = can_post_stories;
    promote_chat_member_request_local_var->can_edit_stories = can_edit_stories;
    promote_chat_member_request_local_var->can_delete_stories = can_delete_stories;
    promote_chat_member_request_local_var->can_post_messages = can_post_messages;
    promote_chat_member_request_local_var->can_edit_messages = can_edit_messages;
    promote_chat_member_request_local_var->can_pin_messages = can_pin_messages;
    promote_chat_member_request_local_var->can_manage_topics = can_manage_topics;

    promote_chat_member_request_local_var->_library_owned = 1;
    return promote_chat_member_request_local_var;
}

__attribute__((deprecated)) promote_chat_member_request_t *promote_chat_member_request_create(
    send_message_request_chat_id_t *chat_id,
    int user_id,
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
    return promote_chat_member_request_create_internal (
        chat_id,
        user_id,
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

void promote_chat_member_request_free(promote_chat_member_request_t *promote_chat_member_request) {
    if(NULL == promote_chat_member_request){
        return ;
    }
    if(promote_chat_member_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "promote_chat_member_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (promote_chat_member_request->chat_id) {
        send_message_request_chat_id_free(promote_chat_member_request->chat_id);
        promote_chat_member_request->chat_id = NULL;
    }
    free(promote_chat_member_request);
}

cJSON *promote_chat_member_request_convertToJSON(promote_chat_member_request_t *promote_chat_member_request) {
    cJSON *item = cJSON_CreateObject();

    // promote_chat_member_request->chat_id
    if (!promote_chat_member_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(promote_chat_member_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // promote_chat_member_request->user_id
    if (!promote_chat_member_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", promote_chat_member_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // promote_chat_member_request->is_anonymous
    if(promote_chat_member_request->is_anonymous) {
    if(cJSON_AddBoolToObject(item, "is_anonymous", promote_chat_member_request->is_anonymous) == NULL) {
    goto fail; //Bool
    }
    }


    // promote_chat_member_request->can_manage_chat
    if(promote_chat_member_request->can_manage_chat) {
    if(cJSON_AddBoolToObject(item, "can_manage_chat", promote_chat_member_request->can_manage_chat) == NULL) {
    goto fail; //Bool
    }
    }


    // promote_chat_member_request->can_delete_messages
    if(promote_chat_member_request->can_delete_messages) {
    if(cJSON_AddBoolToObject(item, "can_delete_messages", promote_chat_member_request->can_delete_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // promote_chat_member_request->can_manage_video_chats
    if(promote_chat_member_request->can_manage_video_chats) {
    if(cJSON_AddBoolToObject(item, "can_manage_video_chats", promote_chat_member_request->can_manage_video_chats) == NULL) {
    goto fail; //Bool
    }
    }


    // promote_chat_member_request->can_restrict_members
    if(promote_chat_member_request->can_restrict_members) {
    if(cJSON_AddBoolToObject(item, "can_restrict_members", promote_chat_member_request->can_restrict_members) == NULL) {
    goto fail; //Bool
    }
    }


    // promote_chat_member_request->can_promote_members
    if(promote_chat_member_request->can_promote_members) {
    if(cJSON_AddBoolToObject(item, "can_promote_members", promote_chat_member_request->can_promote_members) == NULL) {
    goto fail; //Bool
    }
    }


    // promote_chat_member_request->can_change_info
    if(promote_chat_member_request->can_change_info) {
    if(cJSON_AddBoolToObject(item, "can_change_info", promote_chat_member_request->can_change_info) == NULL) {
    goto fail; //Bool
    }
    }


    // promote_chat_member_request->can_invite_users
    if(promote_chat_member_request->can_invite_users) {
    if(cJSON_AddBoolToObject(item, "can_invite_users", promote_chat_member_request->can_invite_users) == NULL) {
    goto fail; //Bool
    }
    }


    // promote_chat_member_request->can_post_stories
    if(promote_chat_member_request->can_post_stories) {
    if(cJSON_AddBoolToObject(item, "can_post_stories", promote_chat_member_request->can_post_stories) == NULL) {
    goto fail; //Bool
    }
    }


    // promote_chat_member_request->can_edit_stories
    if(promote_chat_member_request->can_edit_stories) {
    if(cJSON_AddBoolToObject(item, "can_edit_stories", promote_chat_member_request->can_edit_stories) == NULL) {
    goto fail; //Bool
    }
    }


    // promote_chat_member_request->can_delete_stories
    if(promote_chat_member_request->can_delete_stories) {
    if(cJSON_AddBoolToObject(item, "can_delete_stories", promote_chat_member_request->can_delete_stories) == NULL) {
    goto fail; //Bool
    }
    }


    // promote_chat_member_request->can_post_messages
    if(promote_chat_member_request->can_post_messages) {
    if(cJSON_AddBoolToObject(item, "can_post_messages", promote_chat_member_request->can_post_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // promote_chat_member_request->can_edit_messages
    if(promote_chat_member_request->can_edit_messages) {
    if(cJSON_AddBoolToObject(item, "can_edit_messages", promote_chat_member_request->can_edit_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // promote_chat_member_request->can_pin_messages
    if(promote_chat_member_request->can_pin_messages) {
    if(cJSON_AddBoolToObject(item, "can_pin_messages", promote_chat_member_request->can_pin_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // promote_chat_member_request->can_manage_topics
    if(promote_chat_member_request->can_manage_topics) {
    if(cJSON_AddBoolToObject(item, "can_manage_topics", promote_chat_member_request->can_manage_topics) == NULL) {
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

promote_chat_member_request_t *promote_chat_member_request_parseFromJSON(cJSON *promote_chat_member_requestJSON){

    promote_chat_member_request_t *promote_chat_member_request_local_var = NULL;

    // define the local variable for promote_chat_member_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // promote_chat_member_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(promote_chat_member_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // promote_chat_member_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(promote_chat_member_requestJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(user_id))
    {
    goto end; //Numeric
    }

    // promote_chat_member_request->is_anonymous
    cJSON *is_anonymous = cJSON_GetObjectItemCaseSensitive(promote_chat_member_requestJSON, "is_anonymous");
    if (cJSON_IsNull(is_anonymous)) {
        is_anonymous = NULL;
    }
    if (is_anonymous) { 
    if(!cJSON_IsBool(is_anonymous))
    {
    goto end; //Bool
    }
    }

    // promote_chat_member_request->can_manage_chat
    cJSON *can_manage_chat = cJSON_GetObjectItemCaseSensitive(promote_chat_member_requestJSON, "can_manage_chat");
    if (cJSON_IsNull(can_manage_chat)) {
        can_manage_chat = NULL;
    }
    if (can_manage_chat) { 
    if(!cJSON_IsBool(can_manage_chat))
    {
    goto end; //Bool
    }
    }

    // promote_chat_member_request->can_delete_messages
    cJSON *can_delete_messages = cJSON_GetObjectItemCaseSensitive(promote_chat_member_requestJSON, "can_delete_messages");
    if (cJSON_IsNull(can_delete_messages)) {
        can_delete_messages = NULL;
    }
    if (can_delete_messages) { 
    if(!cJSON_IsBool(can_delete_messages))
    {
    goto end; //Bool
    }
    }

    // promote_chat_member_request->can_manage_video_chats
    cJSON *can_manage_video_chats = cJSON_GetObjectItemCaseSensitive(promote_chat_member_requestJSON, "can_manage_video_chats");
    if (cJSON_IsNull(can_manage_video_chats)) {
        can_manage_video_chats = NULL;
    }
    if (can_manage_video_chats) { 
    if(!cJSON_IsBool(can_manage_video_chats))
    {
    goto end; //Bool
    }
    }

    // promote_chat_member_request->can_restrict_members
    cJSON *can_restrict_members = cJSON_GetObjectItemCaseSensitive(promote_chat_member_requestJSON, "can_restrict_members");
    if (cJSON_IsNull(can_restrict_members)) {
        can_restrict_members = NULL;
    }
    if (can_restrict_members) { 
    if(!cJSON_IsBool(can_restrict_members))
    {
    goto end; //Bool
    }
    }

    // promote_chat_member_request->can_promote_members
    cJSON *can_promote_members = cJSON_GetObjectItemCaseSensitive(promote_chat_member_requestJSON, "can_promote_members");
    if (cJSON_IsNull(can_promote_members)) {
        can_promote_members = NULL;
    }
    if (can_promote_members) { 
    if(!cJSON_IsBool(can_promote_members))
    {
    goto end; //Bool
    }
    }

    // promote_chat_member_request->can_change_info
    cJSON *can_change_info = cJSON_GetObjectItemCaseSensitive(promote_chat_member_requestJSON, "can_change_info");
    if (cJSON_IsNull(can_change_info)) {
        can_change_info = NULL;
    }
    if (can_change_info) { 
    if(!cJSON_IsBool(can_change_info))
    {
    goto end; //Bool
    }
    }

    // promote_chat_member_request->can_invite_users
    cJSON *can_invite_users = cJSON_GetObjectItemCaseSensitive(promote_chat_member_requestJSON, "can_invite_users");
    if (cJSON_IsNull(can_invite_users)) {
        can_invite_users = NULL;
    }
    if (can_invite_users) { 
    if(!cJSON_IsBool(can_invite_users))
    {
    goto end; //Bool
    }
    }

    // promote_chat_member_request->can_post_stories
    cJSON *can_post_stories = cJSON_GetObjectItemCaseSensitive(promote_chat_member_requestJSON, "can_post_stories");
    if (cJSON_IsNull(can_post_stories)) {
        can_post_stories = NULL;
    }
    if (can_post_stories) { 
    if(!cJSON_IsBool(can_post_stories))
    {
    goto end; //Bool
    }
    }

    // promote_chat_member_request->can_edit_stories
    cJSON *can_edit_stories = cJSON_GetObjectItemCaseSensitive(promote_chat_member_requestJSON, "can_edit_stories");
    if (cJSON_IsNull(can_edit_stories)) {
        can_edit_stories = NULL;
    }
    if (can_edit_stories) { 
    if(!cJSON_IsBool(can_edit_stories))
    {
    goto end; //Bool
    }
    }

    // promote_chat_member_request->can_delete_stories
    cJSON *can_delete_stories = cJSON_GetObjectItemCaseSensitive(promote_chat_member_requestJSON, "can_delete_stories");
    if (cJSON_IsNull(can_delete_stories)) {
        can_delete_stories = NULL;
    }
    if (can_delete_stories) { 
    if(!cJSON_IsBool(can_delete_stories))
    {
    goto end; //Bool
    }
    }

    // promote_chat_member_request->can_post_messages
    cJSON *can_post_messages = cJSON_GetObjectItemCaseSensitive(promote_chat_member_requestJSON, "can_post_messages");
    if (cJSON_IsNull(can_post_messages)) {
        can_post_messages = NULL;
    }
    if (can_post_messages) { 
    if(!cJSON_IsBool(can_post_messages))
    {
    goto end; //Bool
    }
    }

    // promote_chat_member_request->can_edit_messages
    cJSON *can_edit_messages = cJSON_GetObjectItemCaseSensitive(promote_chat_member_requestJSON, "can_edit_messages");
    if (cJSON_IsNull(can_edit_messages)) {
        can_edit_messages = NULL;
    }
    if (can_edit_messages) { 
    if(!cJSON_IsBool(can_edit_messages))
    {
    goto end; //Bool
    }
    }

    // promote_chat_member_request->can_pin_messages
    cJSON *can_pin_messages = cJSON_GetObjectItemCaseSensitive(promote_chat_member_requestJSON, "can_pin_messages");
    if (cJSON_IsNull(can_pin_messages)) {
        can_pin_messages = NULL;
    }
    if (can_pin_messages) { 
    if(!cJSON_IsBool(can_pin_messages))
    {
    goto end; //Bool
    }
    }

    // promote_chat_member_request->can_manage_topics
    cJSON *can_manage_topics = cJSON_GetObjectItemCaseSensitive(promote_chat_member_requestJSON, "can_manage_topics");
    if (cJSON_IsNull(can_manage_topics)) {
        can_manage_topics = NULL;
    }
    if (can_manage_topics) { 
    if(!cJSON_IsBool(can_manage_topics))
    {
    goto end; //Bool
    }
    }


    promote_chat_member_request_local_var = promote_chat_member_request_create_internal (
        chat_id_local_nonprim,
        user_id->valuedouble,
        is_anonymous ? is_anonymous->valueint : 0,
        can_manage_chat ? can_manage_chat->valueint : 0,
        can_delete_messages ? can_delete_messages->valueint : 0,
        can_manage_video_chats ? can_manage_video_chats->valueint : 0,
        can_restrict_members ? can_restrict_members->valueint : 0,
        can_promote_members ? can_promote_members->valueint : 0,
        can_change_info ? can_change_info->valueint : 0,
        can_invite_users ? can_invite_users->valueint : 0,
        can_post_stories ? can_post_stories->valueint : 0,
        can_edit_stories ? can_edit_stories->valueint : 0,
        can_delete_stories ? can_delete_stories->valueint : 0,
        can_post_messages ? can_post_messages->valueint : 0,
        can_edit_messages ? can_edit_messages->valueint : 0,
        can_pin_messages ? can_pin_messages->valueint : 0,
        can_manage_topics ? can_manage_topics->valueint : 0
        );

    return promote_chat_member_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
