#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_promote_chat_member_request.h"



static post_promote_chat_member_request_t *post_promote_chat_member_request_create_internal(
    post_send_message_request_chat_id_t *chat_id,
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
    post_promote_chat_member_request_t *post_promote_chat_member_request_local_var = malloc(sizeof(post_promote_chat_member_request_t));
    if (!post_promote_chat_member_request_local_var) {
        return NULL;
    }
    post_promote_chat_member_request_local_var->chat_id = chat_id;
    post_promote_chat_member_request_local_var->user_id = user_id;
    post_promote_chat_member_request_local_var->is_anonymous = is_anonymous;
    post_promote_chat_member_request_local_var->can_manage_chat = can_manage_chat;
    post_promote_chat_member_request_local_var->can_delete_messages = can_delete_messages;
    post_promote_chat_member_request_local_var->can_manage_video_chats = can_manage_video_chats;
    post_promote_chat_member_request_local_var->can_restrict_members = can_restrict_members;
    post_promote_chat_member_request_local_var->can_promote_members = can_promote_members;
    post_promote_chat_member_request_local_var->can_change_info = can_change_info;
    post_promote_chat_member_request_local_var->can_invite_users = can_invite_users;
    post_promote_chat_member_request_local_var->can_post_stories = can_post_stories;
    post_promote_chat_member_request_local_var->can_edit_stories = can_edit_stories;
    post_promote_chat_member_request_local_var->can_delete_stories = can_delete_stories;
    post_promote_chat_member_request_local_var->can_post_messages = can_post_messages;
    post_promote_chat_member_request_local_var->can_edit_messages = can_edit_messages;
    post_promote_chat_member_request_local_var->can_pin_messages = can_pin_messages;
    post_promote_chat_member_request_local_var->can_manage_topics = can_manage_topics;

    post_promote_chat_member_request_local_var->_library_owned = 1;
    return post_promote_chat_member_request_local_var;
}

__attribute__((deprecated)) post_promote_chat_member_request_t *post_promote_chat_member_request_create(
    post_send_message_request_chat_id_t *chat_id,
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
    return post_promote_chat_member_request_create_internal (
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

void post_promote_chat_member_request_free(post_promote_chat_member_request_t *post_promote_chat_member_request) {
    if(NULL == post_promote_chat_member_request){
        return ;
    }
    if(post_promote_chat_member_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_promote_chat_member_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_promote_chat_member_request->chat_id) {
        post_send_message_request_chat_id_free(post_promote_chat_member_request->chat_id);
        post_promote_chat_member_request->chat_id = NULL;
    }
    free(post_promote_chat_member_request);
}

cJSON *post_promote_chat_member_request_convertToJSON(post_promote_chat_member_request_t *post_promote_chat_member_request) {
    cJSON *item = cJSON_CreateObject();

    // post_promote_chat_member_request->chat_id
    if (!post_promote_chat_member_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_send_message_request_chat_id_convertToJSON(post_promote_chat_member_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_promote_chat_member_request->user_id
    if (!post_promote_chat_member_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", post_promote_chat_member_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // post_promote_chat_member_request->is_anonymous
    if(post_promote_chat_member_request->is_anonymous) {
    if(cJSON_AddBoolToObject(item, "is_anonymous", post_promote_chat_member_request->is_anonymous) == NULL) {
    goto fail; //Bool
    }
    }


    // post_promote_chat_member_request->can_manage_chat
    if(post_promote_chat_member_request->can_manage_chat) {
    if(cJSON_AddBoolToObject(item, "can_manage_chat", post_promote_chat_member_request->can_manage_chat) == NULL) {
    goto fail; //Bool
    }
    }


    // post_promote_chat_member_request->can_delete_messages
    if(post_promote_chat_member_request->can_delete_messages) {
    if(cJSON_AddBoolToObject(item, "can_delete_messages", post_promote_chat_member_request->can_delete_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // post_promote_chat_member_request->can_manage_video_chats
    if(post_promote_chat_member_request->can_manage_video_chats) {
    if(cJSON_AddBoolToObject(item, "can_manage_video_chats", post_promote_chat_member_request->can_manage_video_chats) == NULL) {
    goto fail; //Bool
    }
    }


    // post_promote_chat_member_request->can_restrict_members
    if(post_promote_chat_member_request->can_restrict_members) {
    if(cJSON_AddBoolToObject(item, "can_restrict_members", post_promote_chat_member_request->can_restrict_members) == NULL) {
    goto fail; //Bool
    }
    }


    // post_promote_chat_member_request->can_promote_members
    if(post_promote_chat_member_request->can_promote_members) {
    if(cJSON_AddBoolToObject(item, "can_promote_members", post_promote_chat_member_request->can_promote_members) == NULL) {
    goto fail; //Bool
    }
    }


    // post_promote_chat_member_request->can_change_info
    if(post_promote_chat_member_request->can_change_info) {
    if(cJSON_AddBoolToObject(item, "can_change_info", post_promote_chat_member_request->can_change_info) == NULL) {
    goto fail; //Bool
    }
    }


    // post_promote_chat_member_request->can_invite_users
    if(post_promote_chat_member_request->can_invite_users) {
    if(cJSON_AddBoolToObject(item, "can_invite_users", post_promote_chat_member_request->can_invite_users) == NULL) {
    goto fail; //Bool
    }
    }


    // post_promote_chat_member_request->can_post_stories
    if(post_promote_chat_member_request->can_post_stories) {
    if(cJSON_AddBoolToObject(item, "can_post_stories", post_promote_chat_member_request->can_post_stories) == NULL) {
    goto fail; //Bool
    }
    }


    // post_promote_chat_member_request->can_edit_stories
    if(post_promote_chat_member_request->can_edit_stories) {
    if(cJSON_AddBoolToObject(item, "can_edit_stories", post_promote_chat_member_request->can_edit_stories) == NULL) {
    goto fail; //Bool
    }
    }


    // post_promote_chat_member_request->can_delete_stories
    if(post_promote_chat_member_request->can_delete_stories) {
    if(cJSON_AddBoolToObject(item, "can_delete_stories", post_promote_chat_member_request->can_delete_stories) == NULL) {
    goto fail; //Bool
    }
    }


    // post_promote_chat_member_request->can_post_messages
    if(post_promote_chat_member_request->can_post_messages) {
    if(cJSON_AddBoolToObject(item, "can_post_messages", post_promote_chat_member_request->can_post_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // post_promote_chat_member_request->can_edit_messages
    if(post_promote_chat_member_request->can_edit_messages) {
    if(cJSON_AddBoolToObject(item, "can_edit_messages", post_promote_chat_member_request->can_edit_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // post_promote_chat_member_request->can_pin_messages
    if(post_promote_chat_member_request->can_pin_messages) {
    if(cJSON_AddBoolToObject(item, "can_pin_messages", post_promote_chat_member_request->can_pin_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // post_promote_chat_member_request->can_manage_topics
    if(post_promote_chat_member_request->can_manage_topics) {
    if(cJSON_AddBoolToObject(item, "can_manage_topics", post_promote_chat_member_request->can_manage_topics) == NULL) {
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

post_promote_chat_member_request_t *post_promote_chat_member_request_parseFromJSON(cJSON *post_promote_chat_member_requestJSON){

    post_promote_chat_member_request_t *post_promote_chat_member_request_local_var = NULL;

    // define the local variable for post_promote_chat_member_request->chat_id
    post_send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // post_promote_chat_member_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_promote_chat_member_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_promote_chat_member_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(post_promote_chat_member_requestJSON, "user_id");
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

    // post_promote_chat_member_request->is_anonymous
    cJSON *is_anonymous = cJSON_GetObjectItemCaseSensitive(post_promote_chat_member_requestJSON, "is_anonymous");
    if (cJSON_IsNull(is_anonymous)) {
        is_anonymous = NULL;
    }
    if (is_anonymous) { 
    if(!cJSON_IsBool(is_anonymous))
    {
    goto end; //Bool
    }
    }

    // post_promote_chat_member_request->can_manage_chat
    cJSON *can_manage_chat = cJSON_GetObjectItemCaseSensitive(post_promote_chat_member_requestJSON, "can_manage_chat");
    if (cJSON_IsNull(can_manage_chat)) {
        can_manage_chat = NULL;
    }
    if (can_manage_chat) { 
    if(!cJSON_IsBool(can_manage_chat))
    {
    goto end; //Bool
    }
    }

    // post_promote_chat_member_request->can_delete_messages
    cJSON *can_delete_messages = cJSON_GetObjectItemCaseSensitive(post_promote_chat_member_requestJSON, "can_delete_messages");
    if (cJSON_IsNull(can_delete_messages)) {
        can_delete_messages = NULL;
    }
    if (can_delete_messages) { 
    if(!cJSON_IsBool(can_delete_messages))
    {
    goto end; //Bool
    }
    }

    // post_promote_chat_member_request->can_manage_video_chats
    cJSON *can_manage_video_chats = cJSON_GetObjectItemCaseSensitive(post_promote_chat_member_requestJSON, "can_manage_video_chats");
    if (cJSON_IsNull(can_manage_video_chats)) {
        can_manage_video_chats = NULL;
    }
    if (can_manage_video_chats) { 
    if(!cJSON_IsBool(can_manage_video_chats))
    {
    goto end; //Bool
    }
    }

    // post_promote_chat_member_request->can_restrict_members
    cJSON *can_restrict_members = cJSON_GetObjectItemCaseSensitive(post_promote_chat_member_requestJSON, "can_restrict_members");
    if (cJSON_IsNull(can_restrict_members)) {
        can_restrict_members = NULL;
    }
    if (can_restrict_members) { 
    if(!cJSON_IsBool(can_restrict_members))
    {
    goto end; //Bool
    }
    }

    // post_promote_chat_member_request->can_promote_members
    cJSON *can_promote_members = cJSON_GetObjectItemCaseSensitive(post_promote_chat_member_requestJSON, "can_promote_members");
    if (cJSON_IsNull(can_promote_members)) {
        can_promote_members = NULL;
    }
    if (can_promote_members) { 
    if(!cJSON_IsBool(can_promote_members))
    {
    goto end; //Bool
    }
    }

    // post_promote_chat_member_request->can_change_info
    cJSON *can_change_info = cJSON_GetObjectItemCaseSensitive(post_promote_chat_member_requestJSON, "can_change_info");
    if (cJSON_IsNull(can_change_info)) {
        can_change_info = NULL;
    }
    if (can_change_info) { 
    if(!cJSON_IsBool(can_change_info))
    {
    goto end; //Bool
    }
    }

    // post_promote_chat_member_request->can_invite_users
    cJSON *can_invite_users = cJSON_GetObjectItemCaseSensitive(post_promote_chat_member_requestJSON, "can_invite_users");
    if (cJSON_IsNull(can_invite_users)) {
        can_invite_users = NULL;
    }
    if (can_invite_users) { 
    if(!cJSON_IsBool(can_invite_users))
    {
    goto end; //Bool
    }
    }

    // post_promote_chat_member_request->can_post_stories
    cJSON *can_post_stories = cJSON_GetObjectItemCaseSensitive(post_promote_chat_member_requestJSON, "can_post_stories");
    if (cJSON_IsNull(can_post_stories)) {
        can_post_stories = NULL;
    }
    if (can_post_stories) { 
    if(!cJSON_IsBool(can_post_stories))
    {
    goto end; //Bool
    }
    }

    // post_promote_chat_member_request->can_edit_stories
    cJSON *can_edit_stories = cJSON_GetObjectItemCaseSensitive(post_promote_chat_member_requestJSON, "can_edit_stories");
    if (cJSON_IsNull(can_edit_stories)) {
        can_edit_stories = NULL;
    }
    if (can_edit_stories) { 
    if(!cJSON_IsBool(can_edit_stories))
    {
    goto end; //Bool
    }
    }

    // post_promote_chat_member_request->can_delete_stories
    cJSON *can_delete_stories = cJSON_GetObjectItemCaseSensitive(post_promote_chat_member_requestJSON, "can_delete_stories");
    if (cJSON_IsNull(can_delete_stories)) {
        can_delete_stories = NULL;
    }
    if (can_delete_stories) { 
    if(!cJSON_IsBool(can_delete_stories))
    {
    goto end; //Bool
    }
    }

    // post_promote_chat_member_request->can_post_messages
    cJSON *can_post_messages = cJSON_GetObjectItemCaseSensitive(post_promote_chat_member_requestJSON, "can_post_messages");
    if (cJSON_IsNull(can_post_messages)) {
        can_post_messages = NULL;
    }
    if (can_post_messages) { 
    if(!cJSON_IsBool(can_post_messages))
    {
    goto end; //Bool
    }
    }

    // post_promote_chat_member_request->can_edit_messages
    cJSON *can_edit_messages = cJSON_GetObjectItemCaseSensitive(post_promote_chat_member_requestJSON, "can_edit_messages");
    if (cJSON_IsNull(can_edit_messages)) {
        can_edit_messages = NULL;
    }
    if (can_edit_messages) { 
    if(!cJSON_IsBool(can_edit_messages))
    {
    goto end; //Bool
    }
    }

    // post_promote_chat_member_request->can_pin_messages
    cJSON *can_pin_messages = cJSON_GetObjectItemCaseSensitive(post_promote_chat_member_requestJSON, "can_pin_messages");
    if (cJSON_IsNull(can_pin_messages)) {
        can_pin_messages = NULL;
    }
    if (can_pin_messages) { 
    if(!cJSON_IsBool(can_pin_messages))
    {
    goto end; //Bool
    }
    }

    // post_promote_chat_member_request->can_manage_topics
    cJSON *can_manage_topics = cJSON_GetObjectItemCaseSensitive(post_promote_chat_member_requestJSON, "can_manage_topics");
    if (cJSON_IsNull(can_manage_topics)) {
        can_manage_topics = NULL;
    }
    if (can_manage_topics) { 
    if(!cJSON_IsBool(can_manage_topics))
    {
    goto end; //Bool
    }
    }


    post_promote_chat_member_request_local_var = post_promote_chat_member_request_create_internal (
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

    return post_promote_chat_member_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
