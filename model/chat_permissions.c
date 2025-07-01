#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_permissions.h"



static chat_permissions_t *chat_permissions_create_internal(
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
    int can_change_info,
    int can_invite_users,
    int can_pin_messages,
    int can_manage_topics
    ) {
    chat_permissions_t *chat_permissions_local_var = malloc(sizeof(chat_permissions_t));
    if (!chat_permissions_local_var) {
        return NULL;
    }
    chat_permissions_local_var->can_send_messages = can_send_messages;
    chat_permissions_local_var->can_send_audios = can_send_audios;
    chat_permissions_local_var->can_send_documents = can_send_documents;
    chat_permissions_local_var->can_send_photos = can_send_photos;
    chat_permissions_local_var->can_send_videos = can_send_videos;
    chat_permissions_local_var->can_send_video_notes = can_send_video_notes;
    chat_permissions_local_var->can_send_voice_notes = can_send_voice_notes;
    chat_permissions_local_var->can_send_polls = can_send_polls;
    chat_permissions_local_var->can_send_other_messages = can_send_other_messages;
    chat_permissions_local_var->can_add_web_page_previews = can_add_web_page_previews;
    chat_permissions_local_var->can_change_info = can_change_info;
    chat_permissions_local_var->can_invite_users = can_invite_users;
    chat_permissions_local_var->can_pin_messages = can_pin_messages;
    chat_permissions_local_var->can_manage_topics = can_manage_topics;

    chat_permissions_local_var->_library_owned = 1;
    return chat_permissions_local_var;
}

__attribute__((deprecated)) chat_permissions_t *chat_permissions_create(
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
    int can_change_info,
    int can_invite_users,
    int can_pin_messages,
    int can_manage_topics
    ) {
    return chat_permissions_create_internal (
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
        can_change_info,
        can_invite_users,
        can_pin_messages,
        can_manage_topics
        );
}

void chat_permissions_free(chat_permissions_t *chat_permissions) {
    if(NULL == chat_permissions){
        return ;
    }
    if(chat_permissions->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_permissions_free");
        return ;
    }
    listEntry_t *listEntry;
    free(chat_permissions);
}

cJSON *chat_permissions_convertToJSON(chat_permissions_t *chat_permissions) {
    cJSON *item = cJSON_CreateObject();

    // chat_permissions->can_send_messages
    if(chat_permissions->can_send_messages) {
    if(cJSON_AddBoolToObject(item, "can_send_messages", chat_permissions->can_send_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_permissions->can_send_audios
    if(chat_permissions->can_send_audios) {
    if(cJSON_AddBoolToObject(item, "can_send_audios", chat_permissions->can_send_audios) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_permissions->can_send_documents
    if(chat_permissions->can_send_documents) {
    if(cJSON_AddBoolToObject(item, "can_send_documents", chat_permissions->can_send_documents) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_permissions->can_send_photos
    if(chat_permissions->can_send_photos) {
    if(cJSON_AddBoolToObject(item, "can_send_photos", chat_permissions->can_send_photos) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_permissions->can_send_videos
    if(chat_permissions->can_send_videos) {
    if(cJSON_AddBoolToObject(item, "can_send_videos", chat_permissions->can_send_videos) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_permissions->can_send_video_notes
    if(chat_permissions->can_send_video_notes) {
    if(cJSON_AddBoolToObject(item, "can_send_video_notes", chat_permissions->can_send_video_notes) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_permissions->can_send_voice_notes
    if(chat_permissions->can_send_voice_notes) {
    if(cJSON_AddBoolToObject(item, "can_send_voice_notes", chat_permissions->can_send_voice_notes) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_permissions->can_send_polls
    if(chat_permissions->can_send_polls) {
    if(cJSON_AddBoolToObject(item, "can_send_polls", chat_permissions->can_send_polls) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_permissions->can_send_other_messages
    if(chat_permissions->can_send_other_messages) {
    if(cJSON_AddBoolToObject(item, "can_send_other_messages", chat_permissions->can_send_other_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_permissions->can_add_web_page_previews
    if(chat_permissions->can_add_web_page_previews) {
    if(cJSON_AddBoolToObject(item, "can_add_web_page_previews", chat_permissions->can_add_web_page_previews) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_permissions->can_change_info
    if(chat_permissions->can_change_info) {
    if(cJSON_AddBoolToObject(item, "can_change_info", chat_permissions->can_change_info) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_permissions->can_invite_users
    if(chat_permissions->can_invite_users) {
    if(cJSON_AddBoolToObject(item, "can_invite_users", chat_permissions->can_invite_users) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_permissions->can_pin_messages
    if(chat_permissions->can_pin_messages) {
    if(cJSON_AddBoolToObject(item, "can_pin_messages", chat_permissions->can_pin_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_permissions->can_manage_topics
    if(chat_permissions->can_manage_topics) {
    if(cJSON_AddBoolToObject(item, "can_manage_topics", chat_permissions->can_manage_topics) == NULL) {
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

chat_permissions_t *chat_permissions_parseFromJSON(cJSON *chat_permissionsJSON){

    chat_permissions_t *chat_permissions_local_var = NULL;

    // chat_permissions->can_send_messages
    cJSON *can_send_messages = cJSON_GetObjectItemCaseSensitive(chat_permissionsJSON, "can_send_messages");
    if (cJSON_IsNull(can_send_messages)) {
        can_send_messages = NULL;
    }
    if (can_send_messages) { 
    if(!cJSON_IsBool(can_send_messages))
    {
    goto end; //Bool
    }
    }

    // chat_permissions->can_send_audios
    cJSON *can_send_audios = cJSON_GetObjectItemCaseSensitive(chat_permissionsJSON, "can_send_audios");
    if (cJSON_IsNull(can_send_audios)) {
        can_send_audios = NULL;
    }
    if (can_send_audios) { 
    if(!cJSON_IsBool(can_send_audios))
    {
    goto end; //Bool
    }
    }

    // chat_permissions->can_send_documents
    cJSON *can_send_documents = cJSON_GetObjectItemCaseSensitive(chat_permissionsJSON, "can_send_documents");
    if (cJSON_IsNull(can_send_documents)) {
        can_send_documents = NULL;
    }
    if (can_send_documents) { 
    if(!cJSON_IsBool(can_send_documents))
    {
    goto end; //Bool
    }
    }

    // chat_permissions->can_send_photos
    cJSON *can_send_photos = cJSON_GetObjectItemCaseSensitive(chat_permissionsJSON, "can_send_photos");
    if (cJSON_IsNull(can_send_photos)) {
        can_send_photos = NULL;
    }
    if (can_send_photos) { 
    if(!cJSON_IsBool(can_send_photos))
    {
    goto end; //Bool
    }
    }

    // chat_permissions->can_send_videos
    cJSON *can_send_videos = cJSON_GetObjectItemCaseSensitive(chat_permissionsJSON, "can_send_videos");
    if (cJSON_IsNull(can_send_videos)) {
        can_send_videos = NULL;
    }
    if (can_send_videos) { 
    if(!cJSON_IsBool(can_send_videos))
    {
    goto end; //Bool
    }
    }

    // chat_permissions->can_send_video_notes
    cJSON *can_send_video_notes = cJSON_GetObjectItemCaseSensitive(chat_permissionsJSON, "can_send_video_notes");
    if (cJSON_IsNull(can_send_video_notes)) {
        can_send_video_notes = NULL;
    }
    if (can_send_video_notes) { 
    if(!cJSON_IsBool(can_send_video_notes))
    {
    goto end; //Bool
    }
    }

    // chat_permissions->can_send_voice_notes
    cJSON *can_send_voice_notes = cJSON_GetObjectItemCaseSensitive(chat_permissionsJSON, "can_send_voice_notes");
    if (cJSON_IsNull(can_send_voice_notes)) {
        can_send_voice_notes = NULL;
    }
    if (can_send_voice_notes) { 
    if(!cJSON_IsBool(can_send_voice_notes))
    {
    goto end; //Bool
    }
    }

    // chat_permissions->can_send_polls
    cJSON *can_send_polls = cJSON_GetObjectItemCaseSensitive(chat_permissionsJSON, "can_send_polls");
    if (cJSON_IsNull(can_send_polls)) {
        can_send_polls = NULL;
    }
    if (can_send_polls) { 
    if(!cJSON_IsBool(can_send_polls))
    {
    goto end; //Bool
    }
    }

    // chat_permissions->can_send_other_messages
    cJSON *can_send_other_messages = cJSON_GetObjectItemCaseSensitive(chat_permissionsJSON, "can_send_other_messages");
    if (cJSON_IsNull(can_send_other_messages)) {
        can_send_other_messages = NULL;
    }
    if (can_send_other_messages) { 
    if(!cJSON_IsBool(can_send_other_messages))
    {
    goto end; //Bool
    }
    }

    // chat_permissions->can_add_web_page_previews
    cJSON *can_add_web_page_previews = cJSON_GetObjectItemCaseSensitive(chat_permissionsJSON, "can_add_web_page_previews");
    if (cJSON_IsNull(can_add_web_page_previews)) {
        can_add_web_page_previews = NULL;
    }
    if (can_add_web_page_previews) { 
    if(!cJSON_IsBool(can_add_web_page_previews))
    {
    goto end; //Bool
    }
    }

    // chat_permissions->can_change_info
    cJSON *can_change_info = cJSON_GetObjectItemCaseSensitive(chat_permissionsJSON, "can_change_info");
    if (cJSON_IsNull(can_change_info)) {
        can_change_info = NULL;
    }
    if (can_change_info) { 
    if(!cJSON_IsBool(can_change_info))
    {
    goto end; //Bool
    }
    }

    // chat_permissions->can_invite_users
    cJSON *can_invite_users = cJSON_GetObjectItemCaseSensitive(chat_permissionsJSON, "can_invite_users");
    if (cJSON_IsNull(can_invite_users)) {
        can_invite_users = NULL;
    }
    if (can_invite_users) { 
    if(!cJSON_IsBool(can_invite_users))
    {
    goto end; //Bool
    }
    }

    // chat_permissions->can_pin_messages
    cJSON *can_pin_messages = cJSON_GetObjectItemCaseSensitive(chat_permissionsJSON, "can_pin_messages");
    if (cJSON_IsNull(can_pin_messages)) {
        can_pin_messages = NULL;
    }
    if (can_pin_messages) { 
    if(!cJSON_IsBool(can_pin_messages))
    {
    goto end; //Bool
    }
    }

    // chat_permissions->can_manage_topics
    cJSON *can_manage_topics = cJSON_GetObjectItemCaseSensitive(chat_permissionsJSON, "can_manage_topics");
    if (cJSON_IsNull(can_manage_topics)) {
        can_manage_topics = NULL;
    }
    if (can_manage_topics) { 
    if(!cJSON_IsBool(can_manage_topics))
    {
    goto end; //Bool
    }
    }


    chat_permissions_local_var = chat_permissions_create_internal (
        can_send_messages ? can_send_messages->valueint : 0,
        can_send_audios ? can_send_audios->valueint : 0,
        can_send_documents ? can_send_documents->valueint : 0,
        can_send_photos ? can_send_photos->valueint : 0,
        can_send_videos ? can_send_videos->valueint : 0,
        can_send_video_notes ? can_send_video_notes->valueint : 0,
        can_send_voice_notes ? can_send_voice_notes->valueint : 0,
        can_send_polls ? can_send_polls->valueint : 0,
        can_send_other_messages ? can_send_other_messages->valueint : 0,
        can_add_web_page_previews ? can_add_web_page_previews->valueint : 0,
        can_change_info ? can_change_info->valueint : 0,
        can_invite_users ? can_invite_users->valueint : 0,
        can_pin_messages ? can_pin_messages->valueint : 0,
        can_manage_topics ? can_manage_topics->valueint : 0
        );

    return chat_permissions_local_var;
end:
    return NULL;

}
