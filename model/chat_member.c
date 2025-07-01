#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_member.h"



static chat_member_t *chat_member_create_internal(
    char *status,
    user_t *user,
    int is_anonymous,
    int can_be_edited,
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
    int can_pin_messages,
    int can_manage_topics,
    int until_date,
    int is_member,
    int can_send_messages,
    int can_send_audios,
    int can_send_documents,
    int can_send_photos,
    int can_send_videos,
    int can_send_video_notes,
    int can_send_voice_notes,
    int can_send_polls,
    int can_send_other_messages,
    int can_add_web_page_previews,
    char *custom_title,
    int can_post_messages,
    int can_edit_messages
    ) {
    chat_member_t *chat_member_local_var = malloc(sizeof(chat_member_t));
    if (!chat_member_local_var) {
        return NULL;
    }
    chat_member_local_var->status = status;
    chat_member_local_var->user = user;
    chat_member_local_var->is_anonymous = is_anonymous;
    chat_member_local_var->can_be_edited = can_be_edited;
    chat_member_local_var->can_manage_chat = can_manage_chat;
    chat_member_local_var->can_delete_messages = can_delete_messages;
    chat_member_local_var->can_manage_video_chats = can_manage_video_chats;
    chat_member_local_var->can_restrict_members = can_restrict_members;
    chat_member_local_var->can_promote_members = can_promote_members;
    chat_member_local_var->can_change_info = can_change_info;
    chat_member_local_var->can_invite_users = can_invite_users;
    chat_member_local_var->can_post_stories = can_post_stories;
    chat_member_local_var->can_edit_stories = can_edit_stories;
    chat_member_local_var->can_delete_stories = can_delete_stories;
    chat_member_local_var->can_pin_messages = can_pin_messages;
    chat_member_local_var->can_manage_topics = can_manage_topics;
    chat_member_local_var->until_date = until_date;
    chat_member_local_var->is_member = is_member;
    chat_member_local_var->can_send_messages = can_send_messages;
    chat_member_local_var->can_send_audios = can_send_audios;
    chat_member_local_var->can_send_documents = can_send_documents;
    chat_member_local_var->can_send_photos = can_send_photos;
    chat_member_local_var->can_send_videos = can_send_videos;
    chat_member_local_var->can_send_video_notes = can_send_video_notes;
    chat_member_local_var->can_send_voice_notes = can_send_voice_notes;
    chat_member_local_var->can_send_polls = can_send_polls;
    chat_member_local_var->can_send_other_messages = can_send_other_messages;
    chat_member_local_var->can_add_web_page_previews = can_add_web_page_previews;
    chat_member_local_var->custom_title = custom_title;
    chat_member_local_var->can_post_messages = can_post_messages;
    chat_member_local_var->can_edit_messages = can_edit_messages;

    chat_member_local_var->_library_owned = 1;
    return chat_member_local_var;
}

__attribute__((deprecated)) chat_member_t *chat_member_create(
    char *status,
    user_t *user,
    int is_anonymous,
    int can_be_edited,
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
    int can_pin_messages,
    int can_manage_topics,
    int until_date,
    int is_member,
    int can_send_messages,
    int can_send_audios,
    int can_send_documents,
    int can_send_photos,
    int can_send_videos,
    int can_send_video_notes,
    int can_send_voice_notes,
    int can_send_polls,
    int can_send_other_messages,
    int can_add_web_page_previews,
    char *custom_title,
    int can_post_messages,
    int can_edit_messages
    ) {
    return chat_member_create_internal (
        status,
        user,
        is_anonymous,
        can_be_edited,
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
        can_pin_messages,
        can_manage_topics,
        until_date,
        is_member,
        can_send_messages,
        can_send_audios,
        can_send_documents,
        can_send_photos,
        can_send_videos,
        can_send_video_notes,
        can_send_voice_notes,
        can_send_polls,
        can_send_other_messages,
        can_add_web_page_previews,
        custom_title,
        can_post_messages,
        can_edit_messages
        );
}

void chat_member_free(chat_member_t *chat_member) {
    if(NULL == chat_member){
        return ;
    }
    if(chat_member->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_member_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_member->status) {
        free(chat_member->status);
        chat_member->status = NULL;
    }
    if (chat_member->user) {
        user_free(chat_member->user);
        chat_member->user = NULL;
    }
    if (chat_member->custom_title) {
        free(chat_member->custom_title);
        chat_member->custom_title = NULL;
    }
    free(chat_member);
}

cJSON *chat_member_convertToJSON(chat_member_t *chat_member) {
    cJSON *item = cJSON_CreateObject();

    // chat_member->status
    if (!chat_member->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", chat_member->status) == NULL) {
    goto fail; //String
    }


    // chat_member->user
    if (!chat_member->user) {
        goto fail;
    }
    cJSON *user_local_JSON = user_convertToJSON(chat_member->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // chat_member->is_anonymous
    if (!chat_member->is_anonymous) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_anonymous", chat_member->is_anonymous) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_be_edited
    if (!chat_member->can_be_edited) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_be_edited", chat_member->can_be_edited) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_manage_chat
    if (!chat_member->can_manage_chat) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_manage_chat", chat_member->can_manage_chat) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_delete_messages
    if (!chat_member->can_delete_messages) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_delete_messages", chat_member->can_delete_messages) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_manage_video_chats
    if (!chat_member->can_manage_video_chats) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_manage_video_chats", chat_member->can_manage_video_chats) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_restrict_members
    if (!chat_member->can_restrict_members) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_restrict_members", chat_member->can_restrict_members) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_promote_members
    if (!chat_member->can_promote_members) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_promote_members", chat_member->can_promote_members) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_change_info
    if (!chat_member->can_change_info) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_change_info", chat_member->can_change_info) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_invite_users
    if (!chat_member->can_invite_users) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_invite_users", chat_member->can_invite_users) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_post_stories
    if (!chat_member->can_post_stories) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_post_stories", chat_member->can_post_stories) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_edit_stories
    if (!chat_member->can_edit_stories) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_edit_stories", chat_member->can_edit_stories) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_delete_stories
    if (!chat_member->can_delete_stories) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_delete_stories", chat_member->can_delete_stories) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_pin_messages
    if (!chat_member->can_pin_messages) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_pin_messages", chat_member->can_pin_messages) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_manage_topics
    if (!chat_member->can_manage_topics) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_manage_topics", chat_member->can_manage_topics) == NULL) {
    goto fail; //Bool
    }


    // chat_member->until_date
    if (!chat_member->until_date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "until_date", chat_member->until_date) == NULL) {
    goto fail; //Numeric
    }


    // chat_member->is_member
    if (!chat_member->is_member) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_member", chat_member->is_member) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_send_messages
    if (!chat_member->can_send_messages) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_send_messages", chat_member->can_send_messages) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_send_audios
    if (!chat_member->can_send_audios) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_send_audios", chat_member->can_send_audios) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_send_documents
    if (!chat_member->can_send_documents) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_send_documents", chat_member->can_send_documents) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_send_photos
    if (!chat_member->can_send_photos) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_send_photos", chat_member->can_send_photos) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_send_videos
    if (!chat_member->can_send_videos) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_send_videos", chat_member->can_send_videos) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_send_video_notes
    if (!chat_member->can_send_video_notes) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_send_video_notes", chat_member->can_send_video_notes) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_send_voice_notes
    if (!chat_member->can_send_voice_notes) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_send_voice_notes", chat_member->can_send_voice_notes) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_send_polls
    if (!chat_member->can_send_polls) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_send_polls", chat_member->can_send_polls) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_send_other_messages
    if (!chat_member->can_send_other_messages) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_send_other_messages", chat_member->can_send_other_messages) == NULL) {
    goto fail; //Bool
    }


    // chat_member->can_add_web_page_previews
    if (!chat_member->can_add_web_page_previews) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_add_web_page_previews", chat_member->can_add_web_page_previews) == NULL) {
    goto fail; //Bool
    }


    // chat_member->custom_title
    if(chat_member->custom_title) {
    if(cJSON_AddStringToObject(item, "custom_title", chat_member->custom_title) == NULL) {
    goto fail; //String
    }
    }


    // chat_member->can_post_messages
    if(chat_member->can_post_messages) {
    if(cJSON_AddBoolToObject(item, "can_post_messages", chat_member->can_post_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_member->can_edit_messages
    if(chat_member->can_edit_messages) {
    if(cJSON_AddBoolToObject(item, "can_edit_messages", chat_member->can_edit_messages) == NULL) {
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

chat_member_t *chat_member_parseFromJSON(cJSON *chat_memberJSON){

    chat_member_t *chat_member_local_var = NULL;

    // define the local variable for chat_member->user
    user_t *user_local_nonprim = NULL;

    // chat_member->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // chat_member->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (!user) {
        goto end;
    }

    
    user_local_nonprim = user_parseFromJSON(user); //nonprimitive

    // chat_member->is_anonymous
    cJSON *is_anonymous = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "is_anonymous");
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

    // chat_member->can_be_edited
    cJSON *can_be_edited = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_be_edited");
    if (cJSON_IsNull(can_be_edited)) {
        can_be_edited = NULL;
    }
    if (!can_be_edited) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_be_edited))
    {
    goto end; //Bool
    }

    // chat_member->can_manage_chat
    cJSON *can_manage_chat = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_manage_chat");
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

    // chat_member->can_delete_messages
    cJSON *can_delete_messages = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_delete_messages");
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

    // chat_member->can_manage_video_chats
    cJSON *can_manage_video_chats = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_manage_video_chats");
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

    // chat_member->can_restrict_members
    cJSON *can_restrict_members = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_restrict_members");
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

    // chat_member->can_promote_members
    cJSON *can_promote_members = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_promote_members");
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

    // chat_member->can_change_info
    cJSON *can_change_info = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_change_info");
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

    // chat_member->can_invite_users
    cJSON *can_invite_users = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_invite_users");
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

    // chat_member->can_post_stories
    cJSON *can_post_stories = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_post_stories");
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

    // chat_member->can_edit_stories
    cJSON *can_edit_stories = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_edit_stories");
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

    // chat_member->can_delete_stories
    cJSON *can_delete_stories = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_delete_stories");
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

    // chat_member->can_pin_messages
    cJSON *can_pin_messages = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_pin_messages");
    if (cJSON_IsNull(can_pin_messages)) {
        can_pin_messages = NULL;
    }
    if (!can_pin_messages) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_pin_messages))
    {
    goto end; //Bool
    }

    // chat_member->can_manage_topics
    cJSON *can_manage_topics = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_manage_topics");
    if (cJSON_IsNull(can_manage_topics)) {
        can_manage_topics = NULL;
    }
    if (!can_manage_topics) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_manage_topics))
    {
    goto end; //Bool
    }

    // chat_member->until_date
    cJSON *until_date = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "until_date");
    if (cJSON_IsNull(until_date)) {
        until_date = NULL;
    }
    if (!until_date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(until_date))
    {
    goto end; //Numeric
    }

    // chat_member->is_member
    cJSON *is_member = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "is_member");
    if (cJSON_IsNull(is_member)) {
        is_member = NULL;
    }
    if (!is_member) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_member))
    {
    goto end; //Bool
    }

    // chat_member->can_send_messages
    cJSON *can_send_messages = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_send_messages");
    if (cJSON_IsNull(can_send_messages)) {
        can_send_messages = NULL;
    }
    if (!can_send_messages) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_send_messages))
    {
    goto end; //Bool
    }

    // chat_member->can_send_audios
    cJSON *can_send_audios = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_send_audios");
    if (cJSON_IsNull(can_send_audios)) {
        can_send_audios = NULL;
    }
    if (!can_send_audios) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_send_audios))
    {
    goto end; //Bool
    }

    // chat_member->can_send_documents
    cJSON *can_send_documents = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_send_documents");
    if (cJSON_IsNull(can_send_documents)) {
        can_send_documents = NULL;
    }
    if (!can_send_documents) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_send_documents))
    {
    goto end; //Bool
    }

    // chat_member->can_send_photos
    cJSON *can_send_photos = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_send_photos");
    if (cJSON_IsNull(can_send_photos)) {
        can_send_photos = NULL;
    }
    if (!can_send_photos) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_send_photos))
    {
    goto end; //Bool
    }

    // chat_member->can_send_videos
    cJSON *can_send_videos = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_send_videos");
    if (cJSON_IsNull(can_send_videos)) {
        can_send_videos = NULL;
    }
    if (!can_send_videos) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_send_videos))
    {
    goto end; //Bool
    }

    // chat_member->can_send_video_notes
    cJSON *can_send_video_notes = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_send_video_notes");
    if (cJSON_IsNull(can_send_video_notes)) {
        can_send_video_notes = NULL;
    }
    if (!can_send_video_notes) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_send_video_notes))
    {
    goto end; //Bool
    }

    // chat_member->can_send_voice_notes
    cJSON *can_send_voice_notes = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_send_voice_notes");
    if (cJSON_IsNull(can_send_voice_notes)) {
        can_send_voice_notes = NULL;
    }
    if (!can_send_voice_notes) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_send_voice_notes))
    {
    goto end; //Bool
    }

    // chat_member->can_send_polls
    cJSON *can_send_polls = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_send_polls");
    if (cJSON_IsNull(can_send_polls)) {
        can_send_polls = NULL;
    }
    if (!can_send_polls) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_send_polls))
    {
    goto end; //Bool
    }

    // chat_member->can_send_other_messages
    cJSON *can_send_other_messages = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_send_other_messages");
    if (cJSON_IsNull(can_send_other_messages)) {
        can_send_other_messages = NULL;
    }
    if (!can_send_other_messages) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_send_other_messages))
    {
    goto end; //Bool
    }

    // chat_member->can_add_web_page_previews
    cJSON *can_add_web_page_previews = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_add_web_page_previews");
    if (cJSON_IsNull(can_add_web_page_previews)) {
        can_add_web_page_previews = NULL;
    }
    if (!can_add_web_page_previews) {
        goto end;
    }

    
    if(!cJSON_IsBool(can_add_web_page_previews))
    {
    goto end; //Bool
    }

    // chat_member->custom_title
    cJSON *custom_title = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "custom_title");
    if (cJSON_IsNull(custom_title)) {
        custom_title = NULL;
    }
    if (custom_title) { 
    if(!cJSON_IsString(custom_title) && !cJSON_IsNull(custom_title))
    {
    goto end; //String
    }
    }

    // chat_member->can_post_messages
    cJSON *can_post_messages = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_post_messages");
    if (cJSON_IsNull(can_post_messages)) {
        can_post_messages = NULL;
    }
    if (can_post_messages) { 
    if(!cJSON_IsBool(can_post_messages))
    {
    goto end; //Bool
    }
    }

    // chat_member->can_edit_messages
    cJSON *can_edit_messages = cJSON_GetObjectItemCaseSensitive(chat_memberJSON, "can_edit_messages");
    if (cJSON_IsNull(can_edit_messages)) {
        can_edit_messages = NULL;
    }
    if (can_edit_messages) { 
    if(!cJSON_IsBool(can_edit_messages))
    {
    goto end; //Bool
    }
    }


    chat_member_local_var = chat_member_create_internal (
        strdup(status->valuestring),
        user_local_nonprim,
        is_anonymous->valueint,
        can_be_edited->valueint,
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
        can_pin_messages->valueint,
        can_manage_topics->valueint,
        until_date->valuedouble,
        is_member->valueint,
        can_send_messages->valueint,
        can_send_audios->valueint,
        can_send_documents->valueint,
        can_send_photos->valueint,
        can_send_videos->valueint,
        can_send_video_notes->valueint,
        can_send_voice_notes->valueint,
        can_send_polls->valueint,
        can_send_other_messages->valueint,
        can_add_web_page_previews->valueint,
        custom_title && !cJSON_IsNull(custom_title) ? strdup(custom_title->valuestring) : NULL,
        can_post_messages ? can_post_messages->valueint : 0,
        can_edit_messages ? can_edit_messages->valueint : 0
        );

    return chat_member_local_var;
end:
    if (user_local_nonprim) {
        user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
