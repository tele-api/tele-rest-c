#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_member_restricted.h"



static chat_member_restricted_t *chat_member_restricted_create_internal(
    char *status,
    user_t *user,
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
    int can_change_info,
    int can_invite_users,
    int can_pin_messages,
    int can_manage_topics,
    int until_date
    ) {
    chat_member_restricted_t *chat_member_restricted_local_var = malloc(sizeof(chat_member_restricted_t));
    if (!chat_member_restricted_local_var) {
        return NULL;
    }
    chat_member_restricted_local_var->status = status;
    chat_member_restricted_local_var->user = user;
    chat_member_restricted_local_var->is_member = is_member;
    chat_member_restricted_local_var->can_send_messages = can_send_messages;
    chat_member_restricted_local_var->can_send_audios = can_send_audios;
    chat_member_restricted_local_var->can_send_documents = can_send_documents;
    chat_member_restricted_local_var->can_send_photos = can_send_photos;
    chat_member_restricted_local_var->can_send_videos = can_send_videos;
    chat_member_restricted_local_var->can_send_video_notes = can_send_video_notes;
    chat_member_restricted_local_var->can_send_voice_notes = can_send_voice_notes;
    chat_member_restricted_local_var->can_send_polls = can_send_polls;
    chat_member_restricted_local_var->can_send_other_messages = can_send_other_messages;
    chat_member_restricted_local_var->can_add_web_page_previews = can_add_web_page_previews;
    chat_member_restricted_local_var->can_change_info = can_change_info;
    chat_member_restricted_local_var->can_invite_users = can_invite_users;
    chat_member_restricted_local_var->can_pin_messages = can_pin_messages;
    chat_member_restricted_local_var->can_manage_topics = can_manage_topics;
    chat_member_restricted_local_var->until_date = until_date;

    chat_member_restricted_local_var->_library_owned = 1;
    return chat_member_restricted_local_var;
}

__attribute__((deprecated)) chat_member_restricted_t *chat_member_restricted_create(
    char *status,
    user_t *user,
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
    int can_change_info,
    int can_invite_users,
    int can_pin_messages,
    int can_manage_topics,
    int until_date
    ) {
    return chat_member_restricted_create_internal (
        status,
        user,
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
        can_change_info,
        can_invite_users,
        can_pin_messages,
        can_manage_topics,
        until_date
        );
}

void chat_member_restricted_free(chat_member_restricted_t *chat_member_restricted) {
    if(NULL == chat_member_restricted){
        return ;
    }
    if(chat_member_restricted->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_member_restricted_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_member_restricted->status) {
        free(chat_member_restricted->status);
        chat_member_restricted->status = NULL;
    }
    if (chat_member_restricted->user) {
        user_free(chat_member_restricted->user);
        chat_member_restricted->user = NULL;
    }
    free(chat_member_restricted);
}

cJSON *chat_member_restricted_convertToJSON(chat_member_restricted_t *chat_member_restricted) {
    cJSON *item = cJSON_CreateObject();

    // chat_member_restricted->status
    if (!chat_member_restricted->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", chat_member_restricted->status) == NULL) {
    goto fail; //String
    }


    // chat_member_restricted->user
    if (!chat_member_restricted->user) {
        goto fail;
    }
    cJSON *user_local_JSON = user_convertToJSON(chat_member_restricted->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // chat_member_restricted->is_member
    if (!chat_member_restricted->is_member) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_member", chat_member_restricted->is_member) == NULL) {
    goto fail; //Bool
    }


    // chat_member_restricted->can_send_messages
    if (!chat_member_restricted->can_send_messages) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_send_messages", chat_member_restricted->can_send_messages) == NULL) {
    goto fail; //Bool
    }


    // chat_member_restricted->can_send_audios
    if (!chat_member_restricted->can_send_audios) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_send_audios", chat_member_restricted->can_send_audios) == NULL) {
    goto fail; //Bool
    }


    // chat_member_restricted->can_send_documents
    if (!chat_member_restricted->can_send_documents) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_send_documents", chat_member_restricted->can_send_documents) == NULL) {
    goto fail; //Bool
    }


    // chat_member_restricted->can_send_photos
    if (!chat_member_restricted->can_send_photos) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_send_photos", chat_member_restricted->can_send_photos) == NULL) {
    goto fail; //Bool
    }


    // chat_member_restricted->can_send_videos
    if (!chat_member_restricted->can_send_videos) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_send_videos", chat_member_restricted->can_send_videos) == NULL) {
    goto fail; //Bool
    }


    // chat_member_restricted->can_send_video_notes
    if (!chat_member_restricted->can_send_video_notes) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_send_video_notes", chat_member_restricted->can_send_video_notes) == NULL) {
    goto fail; //Bool
    }


    // chat_member_restricted->can_send_voice_notes
    if (!chat_member_restricted->can_send_voice_notes) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_send_voice_notes", chat_member_restricted->can_send_voice_notes) == NULL) {
    goto fail; //Bool
    }


    // chat_member_restricted->can_send_polls
    if (!chat_member_restricted->can_send_polls) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_send_polls", chat_member_restricted->can_send_polls) == NULL) {
    goto fail; //Bool
    }


    // chat_member_restricted->can_send_other_messages
    if (!chat_member_restricted->can_send_other_messages) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_send_other_messages", chat_member_restricted->can_send_other_messages) == NULL) {
    goto fail; //Bool
    }


    // chat_member_restricted->can_add_web_page_previews
    if (!chat_member_restricted->can_add_web_page_previews) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_add_web_page_previews", chat_member_restricted->can_add_web_page_previews) == NULL) {
    goto fail; //Bool
    }


    // chat_member_restricted->can_change_info
    if (!chat_member_restricted->can_change_info) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_change_info", chat_member_restricted->can_change_info) == NULL) {
    goto fail; //Bool
    }


    // chat_member_restricted->can_invite_users
    if (!chat_member_restricted->can_invite_users) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_invite_users", chat_member_restricted->can_invite_users) == NULL) {
    goto fail; //Bool
    }


    // chat_member_restricted->can_pin_messages
    if (!chat_member_restricted->can_pin_messages) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_pin_messages", chat_member_restricted->can_pin_messages) == NULL) {
    goto fail; //Bool
    }


    // chat_member_restricted->can_manage_topics
    if (!chat_member_restricted->can_manage_topics) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "can_manage_topics", chat_member_restricted->can_manage_topics) == NULL) {
    goto fail; //Bool
    }


    // chat_member_restricted->until_date
    if (!chat_member_restricted->until_date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "until_date", chat_member_restricted->until_date) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

chat_member_restricted_t *chat_member_restricted_parseFromJSON(cJSON *chat_member_restrictedJSON){

    chat_member_restricted_t *chat_member_restricted_local_var = NULL;

    // define the local variable for chat_member_restricted->user
    user_t *user_local_nonprim = NULL;

    // chat_member_restricted->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(chat_member_restrictedJSON, "status");
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

    // chat_member_restricted->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(chat_member_restrictedJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (!user) {
        goto end;
    }

    
    user_local_nonprim = user_parseFromJSON(user); //nonprimitive

    // chat_member_restricted->is_member
    cJSON *is_member = cJSON_GetObjectItemCaseSensitive(chat_member_restrictedJSON, "is_member");
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

    // chat_member_restricted->can_send_messages
    cJSON *can_send_messages = cJSON_GetObjectItemCaseSensitive(chat_member_restrictedJSON, "can_send_messages");
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

    // chat_member_restricted->can_send_audios
    cJSON *can_send_audios = cJSON_GetObjectItemCaseSensitive(chat_member_restrictedJSON, "can_send_audios");
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

    // chat_member_restricted->can_send_documents
    cJSON *can_send_documents = cJSON_GetObjectItemCaseSensitive(chat_member_restrictedJSON, "can_send_documents");
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

    // chat_member_restricted->can_send_photos
    cJSON *can_send_photos = cJSON_GetObjectItemCaseSensitive(chat_member_restrictedJSON, "can_send_photos");
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

    // chat_member_restricted->can_send_videos
    cJSON *can_send_videos = cJSON_GetObjectItemCaseSensitive(chat_member_restrictedJSON, "can_send_videos");
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

    // chat_member_restricted->can_send_video_notes
    cJSON *can_send_video_notes = cJSON_GetObjectItemCaseSensitive(chat_member_restrictedJSON, "can_send_video_notes");
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

    // chat_member_restricted->can_send_voice_notes
    cJSON *can_send_voice_notes = cJSON_GetObjectItemCaseSensitive(chat_member_restrictedJSON, "can_send_voice_notes");
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

    // chat_member_restricted->can_send_polls
    cJSON *can_send_polls = cJSON_GetObjectItemCaseSensitive(chat_member_restrictedJSON, "can_send_polls");
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

    // chat_member_restricted->can_send_other_messages
    cJSON *can_send_other_messages = cJSON_GetObjectItemCaseSensitive(chat_member_restrictedJSON, "can_send_other_messages");
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

    // chat_member_restricted->can_add_web_page_previews
    cJSON *can_add_web_page_previews = cJSON_GetObjectItemCaseSensitive(chat_member_restrictedJSON, "can_add_web_page_previews");
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

    // chat_member_restricted->can_change_info
    cJSON *can_change_info = cJSON_GetObjectItemCaseSensitive(chat_member_restrictedJSON, "can_change_info");
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

    // chat_member_restricted->can_invite_users
    cJSON *can_invite_users = cJSON_GetObjectItemCaseSensitive(chat_member_restrictedJSON, "can_invite_users");
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

    // chat_member_restricted->can_pin_messages
    cJSON *can_pin_messages = cJSON_GetObjectItemCaseSensitive(chat_member_restrictedJSON, "can_pin_messages");
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

    // chat_member_restricted->can_manage_topics
    cJSON *can_manage_topics = cJSON_GetObjectItemCaseSensitive(chat_member_restrictedJSON, "can_manage_topics");
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

    // chat_member_restricted->until_date
    cJSON *until_date = cJSON_GetObjectItemCaseSensitive(chat_member_restrictedJSON, "until_date");
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


    chat_member_restricted_local_var = chat_member_restricted_create_internal (
        strdup(status->valuestring),
        user_local_nonprim,
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
        can_change_info->valueint,
        can_invite_users->valueint,
        can_pin_messages->valueint,
        can_manage_topics->valueint,
        until_date->valuedouble
        );

    return chat_member_restricted_local_var;
end:
    if (user_local_nonprim) {
        user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
