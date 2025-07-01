#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_full_info.h"


char* chat_full_info_type_ToString(telegram_bot_api_chat_full_info_TYPE_e type) {
    char* typeArray[] =  { "NULL", "private", "group", "supergroup", "channel" };
    return typeArray[type];
}

telegram_bot_api_chat_full_info_TYPE_e chat_full_info_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "private", "group", "supergroup", "channel" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static chat_full_info_t *chat_full_info_create_internal(
    int id,
    telegram_bot_api_chat_full_info_TYPE_e type,
    int accent_color_id,
    int max_reaction_count,
    accepted_gift_types_t *accepted_gift_types,
    char *title,
    char *username,
    char *first_name,
    char *last_name,
    int is_forum,
    chat_photo_t *photo,
    list_t *active_usernames,
    birthdate_t *birthdate,
    business_intro_t *business_intro,
    business_location_t *business_location,
    business_opening_hours_t *business_opening_hours,
    chat_t *personal_chat,
    list_t *available_reactions,
    char *background_custom_emoji_id,
    int profile_accent_color_id,
    char *profile_background_custom_emoji_id,
    char *emoji_status_custom_emoji_id,
    int emoji_status_expiration_date,
    char *bio,
    int has_private_forwards,
    int has_restricted_voice_and_video_messages,
    int join_to_send_messages,
    int join_by_request,
    char *description,
    char *invite_link,
    message_t *pinned_message,
    chat_permissions_t *permissions,
    int can_send_paid_media,
    int slow_mode_delay,
    int unrestrict_boost_count,
    int message_auto_delete_time,
    int has_aggressive_anti_spam_enabled,
    int has_hidden_members,
    int has_protected_content,
    int has_visible_history,
    char *sticker_set_name,
    int can_set_sticker_set,
    char *custom_emoji_sticker_set_name,
    int linked_chat_id,
    chat_location_t *location
    ) {
    chat_full_info_t *chat_full_info_local_var = malloc(sizeof(chat_full_info_t));
    if (!chat_full_info_local_var) {
        return NULL;
    }
    chat_full_info_local_var->id = id;
    chat_full_info_local_var->type = type;
    chat_full_info_local_var->accent_color_id = accent_color_id;
    chat_full_info_local_var->max_reaction_count = max_reaction_count;
    chat_full_info_local_var->accepted_gift_types = accepted_gift_types;
    chat_full_info_local_var->title = title;
    chat_full_info_local_var->username = username;
    chat_full_info_local_var->first_name = first_name;
    chat_full_info_local_var->last_name = last_name;
    chat_full_info_local_var->is_forum = is_forum;
    chat_full_info_local_var->photo = photo;
    chat_full_info_local_var->active_usernames = active_usernames;
    chat_full_info_local_var->birthdate = birthdate;
    chat_full_info_local_var->business_intro = business_intro;
    chat_full_info_local_var->business_location = business_location;
    chat_full_info_local_var->business_opening_hours = business_opening_hours;
    chat_full_info_local_var->personal_chat = personal_chat;
    chat_full_info_local_var->available_reactions = available_reactions;
    chat_full_info_local_var->background_custom_emoji_id = background_custom_emoji_id;
    chat_full_info_local_var->profile_accent_color_id = profile_accent_color_id;
    chat_full_info_local_var->profile_background_custom_emoji_id = profile_background_custom_emoji_id;
    chat_full_info_local_var->emoji_status_custom_emoji_id = emoji_status_custom_emoji_id;
    chat_full_info_local_var->emoji_status_expiration_date = emoji_status_expiration_date;
    chat_full_info_local_var->bio = bio;
    chat_full_info_local_var->has_private_forwards = has_private_forwards;
    chat_full_info_local_var->has_restricted_voice_and_video_messages = has_restricted_voice_and_video_messages;
    chat_full_info_local_var->join_to_send_messages = join_to_send_messages;
    chat_full_info_local_var->join_by_request = join_by_request;
    chat_full_info_local_var->description = description;
    chat_full_info_local_var->invite_link = invite_link;
    chat_full_info_local_var->pinned_message = pinned_message;
    chat_full_info_local_var->permissions = permissions;
    chat_full_info_local_var->can_send_paid_media = can_send_paid_media;
    chat_full_info_local_var->slow_mode_delay = slow_mode_delay;
    chat_full_info_local_var->unrestrict_boost_count = unrestrict_boost_count;
    chat_full_info_local_var->message_auto_delete_time = message_auto_delete_time;
    chat_full_info_local_var->has_aggressive_anti_spam_enabled = has_aggressive_anti_spam_enabled;
    chat_full_info_local_var->has_hidden_members = has_hidden_members;
    chat_full_info_local_var->has_protected_content = has_protected_content;
    chat_full_info_local_var->has_visible_history = has_visible_history;
    chat_full_info_local_var->sticker_set_name = sticker_set_name;
    chat_full_info_local_var->can_set_sticker_set = can_set_sticker_set;
    chat_full_info_local_var->custom_emoji_sticker_set_name = custom_emoji_sticker_set_name;
    chat_full_info_local_var->linked_chat_id = linked_chat_id;
    chat_full_info_local_var->location = location;

    chat_full_info_local_var->_library_owned = 1;
    return chat_full_info_local_var;
}

__attribute__((deprecated)) chat_full_info_t *chat_full_info_create(
    int id,
    telegram_bot_api_chat_full_info_TYPE_e type,
    int accent_color_id,
    int max_reaction_count,
    accepted_gift_types_t *accepted_gift_types,
    char *title,
    char *username,
    char *first_name,
    char *last_name,
    int is_forum,
    chat_photo_t *photo,
    list_t *active_usernames,
    birthdate_t *birthdate,
    business_intro_t *business_intro,
    business_location_t *business_location,
    business_opening_hours_t *business_opening_hours,
    chat_t *personal_chat,
    list_t *available_reactions,
    char *background_custom_emoji_id,
    int profile_accent_color_id,
    char *profile_background_custom_emoji_id,
    char *emoji_status_custom_emoji_id,
    int emoji_status_expiration_date,
    char *bio,
    int has_private_forwards,
    int has_restricted_voice_and_video_messages,
    int join_to_send_messages,
    int join_by_request,
    char *description,
    char *invite_link,
    message_t *pinned_message,
    chat_permissions_t *permissions,
    int can_send_paid_media,
    int slow_mode_delay,
    int unrestrict_boost_count,
    int message_auto_delete_time,
    int has_aggressive_anti_spam_enabled,
    int has_hidden_members,
    int has_protected_content,
    int has_visible_history,
    char *sticker_set_name,
    int can_set_sticker_set,
    char *custom_emoji_sticker_set_name,
    int linked_chat_id,
    chat_location_t *location
    ) {
    return chat_full_info_create_internal (
        id,
        type,
        accent_color_id,
        max_reaction_count,
        accepted_gift_types,
        title,
        username,
        first_name,
        last_name,
        is_forum,
        photo,
        active_usernames,
        birthdate,
        business_intro,
        business_location,
        business_opening_hours,
        personal_chat,
        available_reactions,
        background_custom_emoji_id,
        profile_accent_color_id,
        profile_background_custom_emoji_id,
        emoji_status_custom_emoji_id,
        emoji_status_expiration_date,
        bio,
        has_private_forwards,
        has_restricted_voice_and_video_messages,
        join_to_send_messages,
        join_by_request,
        description,
        invite_link,
        pinned_message,
        permissions,
        can_send_paid_media,
        slow_mode_delay,
        unrestrict_boost_count,
        message_auto_delete_time,
        has_aggressive_anti_spam_enabled,
        has_hidden_members,
        has_protected_content,
        has_visible_history,
        sticker_set_name,
        can_set_sticker_set,
        custom_emoji_sticker_set_name,
        linked_chat_id,
        location
        );
}

void chat_full_info_free(chat_full_info_t *chat_full_info) {
    if(NULL == chat_full_info){
        return ;
    }
    if(chat_full_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_full_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_full_info->accepted_gift_types) {
        accepted_gift_types_free(chat_full_info->accepted_gift_types);
        chat_full_info->accepted_gift_types = NULL;
    }
    if (chat_full_info->title) {
        free(chat_full_info->title);
        chat_full_info->title = NULL;
    }
    if (chat_full_info->username) {
        free(chat_full_info->username);
        chat_full_info->username = NULL;
    }
    if (chat_full_info->first_name) {
        free(chat_full_info->first_name);
        chat_full_info->first_name = NULL;
    }
    if (chat_full_info->last_name) {
        free(chat_full_info->last_name);
        chat_full_info->last_name = NULL;
    }
    if (chat_full_info->photo) {
        chat_photo_free(chat_full_info->photo);
        chat_full_info->photo = NULL;
    }
    if (chat_full_info->active_usernames) {
        list_ForEach(listEntry, chat_full_info->active_usernames) {
            free(listEntry->data);
        }
        list_freeList(chat_full_info->active_usernames);
        chat_full_info->active_usernames = NULL;
    }
    if (chat_full_info->birthdate) {
        birthdate_free(chat_full_info->birthdate);
        chat_full_info->birthdate = NULL;
    }
    if (chat_full_info->business_intro) {
        business_intro_free(chat_full_info->business_intro);
        chat_full_info->business_intro = NULL;
    }
    if (chat_full_info->business_location) {
        business_location_free(chat_full_info->business_location);
        chat_full_info->business_location = NULL;
    }
    if (chat_full_info->business_opening_hours) {
        business_opening_hours_free(chat_full_info->business_opening_hours);
        chat_full_info->business_opening_hours = NULL;
    }
    if (chat_full_info->personal_chat) {
        chat_free(chat_full_info->personal_chat);
        chat_full_info->personal_chat = NULL;
    }
    if (chat_full_info->available_reactions) {
        list_ForEach(listEntry, chat_full_info->available_reactions) {
            reaction_type_free(listEntry->data);
        }
        list_freeList(chat_full_info->available_reactions);
        chat_full_info->available_reactions = NULL;
    }
    if (chat_full_info->background_custom_emoji_id) {
        free(chat_full_info->background_custom_emoji_id);
        chat_full_info->background_custom_emoji_id = NULL;
    }
    if (chat_full_info->profile_background_custom_emoji_id) {
        free(chat_full_info->profile_background_custom_emoji_id);
        chat_full_info->profile_background_custom_emoji_id = NULL;
    }
    if (chat_full_info->emoji_status_custom_emoji_id) {
        free(chat_full_info->emoji_status_custom_emoji_id);
        chat_full_info->emoji_status_custom_emoji_id = NULL;
    }
    if (chat_full_info->bio) {
        free(chat_full_info->bio);
        chat_full_info->bio = NULL;
    }
    if (chat_full_info->description) {
        free(chat_full_info->description);
        chat_full_info->description = NULL;
    }
    if (chat_full_info->invite_link) {
        free(chat_full_info->invite_link);
        chat_full_info->invite_link = NULL;
    }
    if (chat_full_info->pinned_message) {
        message_free(chat_full_info->pinned_message);
        chat_full_info->pinned_message = NULL;
    }
    if (chat_full_info->permissions) {
        chat_permissions_free(chat_full_info->permissions);
        chat_full_info->permissions = NULL;
    }
    if (chat_full_info->sticker_set_name) {
        free(chat_full_info->sticker_set_name);
        chat_full_info->sticker_set_name = NULL;
    }
    if (chat_full_info->custom_emoji_sticker_set_name) {
        free(chat_full_info->custom_emoji_sticker_set_name);
        chat_full_info->custom_emoji_sticker_set_name = NULL;
    }
    if (chat_full_info->location) {
        chat_location_free(chat_full_info->location);
        chat_full_info->location = NULL;
    }
    free(chat_full_info);
}

cJSON *chat_full_info_convertToJSON(chat_full_info_t *chat_full_info) {
    cJSON *item = cJSON_CreateObject();

    // chat_full_info->id
    if (!chat_full_info->id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "id", chat_full_info->id) == NULL) {
    goto fail; //Numeric
    }


    // chat_full_info->type
    if (telegram_bot_api_chat_full_info_TYPE_NULL == chat_full_info->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", chat_full_info_type_ToString(chat_full_info->type)) == NULL)
    {
    goto fail; //Enum
    }


    // chat_full_info->accent_color_id
    if (!chat_full_info->accent_color_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "accent_color_id", chat_full_info->accent_color_id) == NULL) {
    goto fail; //Numeric
    }


    // chat_full_info->max_reaction_count
    if (!chat_full_info->max_reaction_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "max_reaction_count", chat_full_info->max_reaction_count) == NULL) {
    goto fail; //Numeric
    }


    // chat_full_info->accepted_gift_types
    if (!chat_full_info->accepted_gift_types) {
        goto fail;
    }
    cJSON *accepted_gift_types_local_JSON = accepted_gift_types_convertToJSON(chat_full_info->accepted_gift_types);
    if(accepted_gift_types_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "accepted_gift_types", accepted_gift_types_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // chat_full_info->title
    if(chat_full_info->title) {
    if(cJSON_AddStringToObject(item, "title", chat_full_info->title) == NULL) {
    goto fail; //String
    }
    }


    // chat_full_info->username
    if(chat_full_info->username) {
    if(cJSON_AddStringToObject(item, "username", chat_full_info->username) == NULL) {
    goto fail; //String
    }
    }


    // chat_full_info->first_name
    if(chat_full_info->first_name) {
    if(cJSON_AddStringToObject(item, "first_name", chat_full_info->first_name) == NULL) {
    goto fail; //String
    }
    }


    // chat_full_info->last_name
    if(chat_full_info->last_name) {
    if(cJSON_AddStringToObject(item, "last_name", chat_full_info->last_name) == NULL) {
    goto fail; //String
    }
    }


    // chat_full_info->is_forum
    if(chat_full_info->is_forum) {
    if(cJSON_AddBoolToObject(item, "is_forum", chat_full_info->is_forum) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_full_info->photo
    if(chat_full_info->photo) {
    cJSON *photo_local_JSON = chat_photo_convertToJSON(chat_full_info->photo);
    if(photo_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "photo", photo_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // chat_full_info->active_usernames
    if(chat_full_info->active_usernames) {
    cJSON *active_usernames = cJSON_AddArrayToObject(item, "active_usernames");
    if(active_usernames == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *active_usernamesListEntry;
    list_ForEach(active_usernamesListEntry, chat_full_info->active_usernames) {
    if(cJSON_AddStringToObject(active_usernames, "", active_usernamesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // chat_full_info->birthdate
    if(chat_full_info->birthdate) {
    cJSON *birthdate_local_JSON = birthdate_convertToJSON(chat_full_info->birthdate);
    if(birthdate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "birthdate", birthdate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // chat_full_info->business_intro
    if(chat_full_info->business_intro) {
    cJSON *business_intro_local_JSON = business_intro_convertToJSON(chat_full_info->business_intro);
    if(business_intro_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "business_intro", business_intro_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // chat_full_info->business_location
    if(chat_full_info->business_location) {
    cJSON *business_location_local_JSON = business_location_convertToJSON(chat_full_info->business_location);
    if(business_location_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "business_location", business_location_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // chat_full_info->business_opening_hours
    if(chat_full_info->business_opening_hours) {
    cJSON *business_opening_hours_local_JSON = business_opening_hours_convertToJSON(chat_full_info->business_opening_hours);
    if(business_opening_hours_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "business_opening_hours", business_opening_hours_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // chat_full_info->personal_chat
    if(chat_full_info->personal_chat) {
    cJSON *personal_chat_local_JSON = chat_convertToJSON(chat_full_info->personal_chat);
    if(personal_chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "personal_chat", personal_chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // chat_full_info->available_reactions
    if(chat_full_info->available_reactions) {
    cJSON *available_reactions = cJSON_AddArrayToObject(item, "available_reactions");
    if(available_reactions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *available_reactionsListEntry;
    if (chat_full_info->available_reactions) {
    list_ForEach(available_reactionsListEntry, chat_full_info->available_reactions) {
    cJSON *itemLocal = reaction_type_convertToJSON(available_reactionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(available_reactions, itemLocal);
    }
    }
    }


    // chat_full_info->background_custom_emoji_id
    if(chat_full_info->background_custom_emoji_id) {
    if(cJSON_AddStringToObject(item, "background_custom_emoji_id", chat_full_info->background_custom_emoji_id) == NULL) {
    goto fail; //String
    }
    }


    // chat_full_info->profile_accent_color_id
    if(chat_full_info->profile_accent_color_id) {
    if(cJSON_AddNumberToObject(item, "profile_accent_color_id", chat_full_info->profile_accent_color_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // chat_full_info->profile_background_custom_emoji_id
    if(chat_full_info->profile_background_custom_emoji_id) {
    if(cJSON_AddStringToObject(item, "profile_background_custom_emoji_id", chat_full_info->profile_background_custom_emoji_id) == NULL) {
    goto fail; //String
    }
    }


    // chat_full_info->emoji_status_custom_emoji_id
    if(chat_full_info->emoji_status_custom_emoji_id) {
    if(cJSON_AddStringToObject(item, "emoji_status_custom_emoji_id", chat_full_info->emoji_status_custom_emoji_id) == NULL) {
    goto fail; //String
    }
    }


    // chat_full_info->emoji_status_expiration_date
    if(chat_full_info->emoji_status_expiration_date) {
    if(cJSON_AddNumberToObject(item, "emoji_status_expiration_date", chat_full_info->emoji_status_expiration_date) == NULL) {
    goto fail; //Numeric
    }
    }


    // chat_full_info->bio
    if(chat_full_info->bio) {
    if(cJSON_AddStringToObject(item, "bio", chat_full_info->bio) == NULL) {
    goto fail; //String
    }
    }


    // chat_full_info->has_private_forwards
    if(chat_full_info->has_private_forwards) {
    if(cJSON_AddBoolToObject(item, "has_private_forwards", chat_full_info->has_private_forwards) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_full_info->has_restricted_voice_and_video_messages
    if(chat_full_info->has_restricted_voice_and_video_messages) {
    if(cJSON_AddBoolToObject(item, "has_restricted_voice_and_video_messages", chat_full_info->has_restricted_voice_and_video_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_full_info->join_to_send_messages
    if(chat_full_info->join_to_send_messages) {
    if(cJSON_AddBoolToObject(item, "join_to_send_messages", chat_full_info->join_to_send_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_full_info->join_by_request
    if(chat_full_info->join_by_request) {
    if(cJSON_AddBoolToObject(item, "join_by_request", chat_full_info->join_by_request) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_full_info->description
    if(chat_full_info->description) {
    if(cJSON_AddStringToObject(item, "description", chat_full_info->description) == NULL) {
    goto fail; //String
    }
    }


    // chat_full_info->invite_link
    if(chat_full_info->invite_link) {
    if(cJSON_AddStringToObject(item, "invite_link", chat_full_info->invite_link) == NULL) {
    goto fail; //String
    }
    }


    // chat_full_info->pinned_message
    if(chat_full_info->pinned_message) {
    cJSON *pinned_message_local_JSON = message_convertToJSON(chat_full_info->pinned_message);
    if(pinned_message_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "pinned_message", pinned_message_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // chat_full_info->permissions
    if(chat_full_info->permissions) {
    cJSON *permissions_local_JSON = chat_permissions_convertToJSON(chat_full_info->permissions);
    if(permissions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "permissions", permissions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // chat_full_info->can_send_paid_media
    if(chat_full_info->can_send_paid_media) {
    if(cJSON_AddBoolToObject(item, "can_send_paid_media", chat_full_info->can_send_paid_media) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_full_info->slow_mode_delay
    if(chat_full_info->slow_mode_delay) {
    if(cJSON_AddNumberToObject(item, "slow_mode_delay", chat_full_info->slow_mode_delay) == NULL) {
    goto fail; //Numeric
    }
    }


    // chat_full_info->unrestrict_boost_count
    if(chat_full_info->unrestrict_boost_count) {
    if(cJSON_AddNumberToObject(item, "unrestrict_boost_count", chat_full_info->unrestrict_boost_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // chat_full_info->message_auto_delete_time
    if(chat_full_info->message_auto_delete_time) {
    if(cJSON_AddNumberToObject(item, "message_auto_delete_time", chat_full_info->message_auto_delete_time) == NULL) {
    goto fail; //Numeric
    }
    }


    // chat_full_info->has_aggressive_anti_spam_enabled
    if(chat_full_info->has_aggressive_anti_spam_enabled) {
    if(cJSON_AddBoolToObject(item, "has_aggressive_anti_spam_enabled", chat_full_info->has_aggressive_anti_spam_enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_full_info->has_hidden_members
    if(chat_full_info->has_hidden_members) {
    if(cJSON_AddBoolToObject(item, "has_hidden_members", chat_full_info->has_hidden_members) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_full_info->has_protected_content
    if(chat_full_info->has_protected_content) {
    if(cJSON_AddBoolToObject(item, "has_protected_content", chat_full_info->has_protected_content) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_full_info->has_visible_history
    if(chat_full_info->has_visible_history) {
    if(cJSON_AddBoolToObject(item, "has_visible_history", chat_full_info->has_visible_history) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_full_info->sticker_set_name
    if(chat_full_info->sticker_set_name) {
    if(cJSON_AddStringToObject(item, "sticker_set_name", chat_full_info->sticker_set_name) == NULL) {
    goto fail; //String
    }
    }


    // chat_full_info->can_set_sticker_set
    if(chat_full_info->can_set_sticker_set) {
    if(cJSON_AddBoolToObject(item, "can_set_sticker_set", chat_full_info->can_set_sticker_set) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_full_info->custom_emoji_sticker_set_name
    if(chat_full_info->custom_emoji_sticker_set_name) {
    if(cJSON_AddStringToObject(item, "custom_emoji_sticker_set_name", chat_full_info->custom_emoji_sticker_set_name) == NULL) {
    goto fail; //String
    }
    }


    // chat_full_info->linked_chat_id
    if(chat_full_info->linked_chat_id) {
    if(cJSON_AddNumberToObject(item, "linked_chat_id", chat_full_info->linked_chat_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // chat_full_info->location
    if(chat_full_info->location) {
    cJSON *location_local_JSON = chat_location_convertToJSON(chat_full_info->location);
    if(location_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "location", location_local_JSON);
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

chat_full_info_t *chat_full_info_parseFromJSON(cJSON *chat_full_infoJSON){

    chat_full_info_t *chat_full_info_local_var = NULL;

    // define the local variable for chat_full_info->accepted_gift_types
    accepted_gift_types_t *accepted_gift_types_local_nonprim = NULL;

    // define the local variable for chat_full_info->photo
    chat_photo_t *photo_local_nonprim = NULL;

    // define the local list for chat_full_info->active_usernames
    list_t *active_usernamesList = NULL;

    // define the local variable for chat_full_info->birthdate
    birthdate_t *birthdate_local_nonprim = NULL;

    // define the local variable for chat_full_info->business_intro
    business_intro_t *business_intro_local_nonprim = NULL;

    // define the local variable for chat_full_info->business_location
    business_location_t *business_location_local_nonprim = NULL;

    // define the local variable for chat_full_info->business_opening_hours
    business_opening_hours_t *business_opening_hours_local_nonprim = NULL;

    // define the local variable for chat_full_info->personal_chat
    chat_t *personal_chat_local_nonprim = NULL;

    // define the local list for chat_full_info->available_reactions
    list_t *available_reactionsList = NULL;

    // define the local variable for chat_full_info->pinned_message
    message_t *pinned_message_local_nonprim = NULL;

    // define the local variable for chat_full_info->permissions
    chat_permissions_t *permissions_local_nonprim = NULL;

    // define the local variable for chat_full_info->location
    chat_location_t *location_local_nonprim = NULL;

    // chat_full_info->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "id");
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

    // chat_full_info->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    telegram_bot_api_chat_full_info_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = chat_full_info_type_FromString(type->valuestring);

    // chat_full_info->accent_color_id
    cJSON *accent_color_id = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "accent_color_id");
    if (cJSON_IsNull(accent_color_id)) {
        accent_color_id = NULL;
    }
    if (!accent_color_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(accent_color_id))
    {
    goto end; //Numeric
    }

    // chat_full_info->max_reaction_count
    cJSON *max_reaction_count = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "max_reaction_count");
    if (cJSON_IsNull(max_reaction_count)) {
        max_reaction_count = NULL;
    }
    if (!max_reaction_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(max_reaction_count))
    {
    goto end; //Numeric
    }

    // chat_full_info->accepted_gift_types
    cJSON *accepted_gift_types = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "accepted_gift_types");
    if (cJSON_IsNull(accepted_gift_types)) {
        accepted_gift_types = NULL;
    }
    if (!accepted_gift_types) {
        goto end;
    }

    
    accepted_gift_types_local_nonprim = accepted_gift_types_parseFromJSON(accepted_gift_types); //nonprimitive

    // chat_full_info->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // chat_full_info->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "username");
    if (cJSON_IsNull(username)) {
        username = NULL;
    }
    if (username) { 
    if(!cJSON_IsString(username) && !cJSON_IsNull(username))
    {
    goto end; //String
    }
    }

    // chat_full_info->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "first_name");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (first_name) { 
    if(!cJSON_IsString(first_name) && !cJSON_IsNull(first_name))
    {
    goto end; //String
    }
    }

    // chat_full_info->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "last_name");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }

    // chat_full_info->is_forum
    cJSON *is_forum = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "is_forum");
    if (cJSON_IsNull(is_forum)) {
        is_forum = NULL;
    }
    if (is_forum) { 
    if(!cJSON_IsBool(is_forum))
    {
    goto end; //Bool
    }
    }

    // chat_full_info->photo
    cJSON *photo = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "photo");
    if (cJSON_IsNull(photo)) {
        photo = NULL;
    }
    if (photo) { 
    photo_local_nonprim = chat_photo_parseFromJSON(photo); //nonprimitive
    }

    // chat_full_info->active_usernames
    cJSON *active_usernames = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "active_usernames");
    if (cJSON_IsNull(active_usernames)) {
        active_usernames = NULL;
    }
    if (active_usernames) { 
    cJSON *active_usernames_local = NULL;
    if(!cJSON_IsArray(active_usernames)) {
        goto end;//primitive container
    }
    active_usernamesList = list_createList();

    cJSON_ArrayForEach(active_usernames_local, active_usernames)
    {
        if(!cJSON_IsString(active_usernames_local))
        {
            goto end;
        }
        list_addElement(active_usernamesList , strdup(active_usernames_local->valuestring));
    }
    }

    // chat_full_info->birthdate
    cJSON *birthdate = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "birthdate");
    if (cJSON_IsNull(birthdate)) {
        birthdate = NULL;
    }
    if (birthdate) { 
    birthdate_local_nonprim = birthdate_parseFromJSON(birthdate); //nonprimitive
    }

    // chat_full_info->business_intro
    cJSON *business_intro = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "business_intro");
    if (cJSON_IsNull(business_intro)) {
        business_intro = NULL;
    }
    if (business_intro) { 
    business_intro_local_nonprim = business_intro_parseFromJSON(business_intro); //nonprimitive
    }

    // chat_full_info->business_location
    cJSON *business_location = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "business_location");
    if (cJSON_IsNull(business_location)) {
        business_location = NULL;
    }
    if (business_location) { 
    business_location_local_nonprim = business_location_parseFromJSON(business_location); //nonprimitive
    }

    // chat_full_info->business_opening_hours
    cJSON *business_opening_hours = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "business_opening_hours");
    if (cJSON_IsNull(business_opening_hours)) {
        business_opening_hours = NULL;
    }
    if (business_opening_hours) { 
    business_opening_hours_local_nonprim = business_opening_hours_parseFromJSON(business_opening_hours); //nonprimitive
    }

    // chat_full_info->personal_chat
    cJSON *personal_chat = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "personal_chat");
    if (cJSON_IsNull(personal_chat)) {
        personal_chat = NULL;
    }
    if (personal_chat) { 
    personal_chat_local_nonprim = chat_parseFromJSON(personal_chat); //nonprimitive
    }

    // chat_full_info->available_reactions
    cJSON *available_reactions = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "available_reactions");
    if (cJSON_IsNull(available_reactions)) {
        available_reactions = NULL;
    }
    if (available_reactions) { 
    cJSON *available_reactions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(available_reactions)){
        goto end; //nonprimitive container
    }

    available_reactionsList = list_createList();

    cJSON_ArrayForEach(available_reactions_local_nonprimitive,available_reactions )
    {
        if(!cJSON_IsObject(available_reactions_local_nonprimitive)){
            goto end;
        }
        reaction_type_t *available_reactionsItem = reaction_type_parseFromJSON(available_reactions_local_nonprimitive);

        list_addElement(available_reactionsList, available_reactionsItem);
    }
    }

    // chat_full_info->background_custom_emoji_id
    cJSON *background_custom_emoji_id = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "background_custom_emoji_id");
    if (cJSON_IsNull(background_custom_emoji_id)) {
        background_custom_emoji_id = NULL;
    }
    if (background_custom_emoji_id) { 
    if(!cJSON_IsString(background_custom_emoji_id) && !cJSON_IsNull(background_custom_emoji_id))
    {
    goto end; //String
    }
    }

    // chat_full_info->profile_accent_color_id
    cJSON *profile_accent_color_id = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "profile_accent_color_id");
    if (cJSON_IsNull(profile_accent_color_id)) {
        profile_accent_color_id = NULL;
    }
    if (profile_accent_color_id) { 
    if(!cJSON_IsNumber(profile_accent_color_id))
    {
    goto end; //Numeric
    }
    }

    // chat_full_info->profile_background_custom_emoji_id
    cJSON *profile_background_custom_emoji_id = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "profile_background_custom_emoji_id");
    if (cJSON_IsNull(profile_background_custom_emoji_id)) {
        profile_background_custom_emoji_id = NULL;
    }
    if (profile_background_custom_emoji_id) { 
    if(!cJSON_IsString(profile_background_custom_emoji_id) && !cJSON_IsNull(profile_background_custom_emoji_id))
    {
    goto end; //String
    }
    }

    // chat_full_info->emoji_status_custom_emoji_id
    cJSON *emoji_status_custom_emoji_id = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "emoji_status_custom_emoji_id");
    if (cJSON_IsNull(emoji_status_custom_emoji_id)) {
        emoji_status_custom_emoji_id = NULL;
    }
    if (emoji_status_custom_emoji_id) { 
    if(!cJSON_IsString(emoji_status_custom_emoji_id) && !cJSON_IsNull(emoji_status_custom_emoji_id))
    {
    goto end; //String
    }
    }

    // chat_full_info->emoji_status_expiration_date
    cJSON *emoji_status_expiration_date = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "emoji_status_expiration_date");
    if (cJSON_IsNull(emoji_status_expiration_date)) {
        emoji_status_expiration_date = NULL;
    }
    if (emoji_status_expiration_date) { 
    if(!cJSON_IsNumber(emoji_status_expiration_date))
    {
    goto end; //Numeric
    }
    }

    // chat_full_info->bio
    cJSON *bio = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "bio");
    if (cJSON_IsNull(bio)) {
        bio = NULL;
    }
    if (bio) { 
    if(!cJSON_IsString(bio) && !cJSON_IsNull(bio))
    {
    goto end; //String
    }
    }

    // chat_full_info->has_private_forwards
    cJSON *has_private_forwards = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "has_private_forwards");
    if (cJSON_IsNull(has_private_forwards)) {
        has_private_forwards = NULL;
    }
    if (has_private_forwards) { 
    if(!cJSON_IsBool(has_private_forwards))
    {
    goto end; //Bool
    }
    }

    // chat_full_info->has_restricted_voice_and_video_messages
    cJSON *has_restricted_voice_and_video_messages = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "has_restricted_voice_and_video_messages");
    if (cJSON_IsNull(has_restricted_voice_and_video_messages)) {
        has_restricted_voice_and_video_messages = NULL;
    }
    if (has_restricted_voice_and_video_messages) { 
    if(!cJSON_IsBool(has_restricted_voice_and_video_messages))
    {
    goto end; //Bool
    }
    }

    // chat_full_info->join_to_send_messages
    cJSON *join_to_send_messages = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "join_to_send_messages");
    if (cJSON_IsNull(join_to_send_messages)) {
        join_to_send_messages = NULL;
    }
    if (join_to_send_messages) { 
    if(!cJSON_IsBool(join_to_send_messages))
    {
    goto end; //Bool
    }
    }

    // chat_full_info->join_by_request
    cJSON *join_by_request = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "join_by_request");
    if (cJSON_IsNull(join_by_request)) {
        join_by_request = NULL;
    }
    if (join_by_request) { 
    if(!cJSON_IsBool(join_by_request))
    {
    goto end; //Bool
    }
    }

    // chat_full_info->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // chat_full_info->invite_link
    cJSON *invite_link = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "invite_link");
    if (cJSON_IsNull(invite_link)) {
        invite_link = NULL;
    }
    if (invite_link) { 
    if(!cJSON_IsString(invite_link) && !cJSON_IsNull(invite_link))
    {
    goto end; //String
    }
    }

    // chat_full_info->pinned_message
    cJSON *pinned_message = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "pinned_message");
    if (cJSON_IsNull(pinned_message)) {
        pinned_message = NULL;
    }
    if (pinned_message) { 
    pinned_message_local_nonprim = message_parseFromJSON(pinned_message); //nonprimitive
    }

    // chat_full_info->permissions
    cJSON *permissions = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "permissions");
    if (cJSON_IsNull(permissions)) {
        permissions = NULL;
    }
    if (permissions) { 
    permissions_local_nonprim = chat_permissions_parseFromJSON(permissions); //nonprimitive
    }

    // chat_full_info->can_send_paid_media
    cJSON *can_send_paid_media = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "can_send_paid_media");
    if (cJSON_IsNull(can_send_paid_media)) {
        can_send_paid_media = NULL;
    }
    if (can_send_paid_media) { 
    if(!cJSON_IsBool(can_send_paid_media))
    {
    goto end; //Bool
    }
    }

    // chat_full_info->slow_mode_delay
    cJSON *slow_mode_delay = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "slow_mode_delay");
    if (cJSON_IsNull(slow_mode_delay)) {
        slow_mode_delay = NULL;
    }
    if (slow_mode_delay) { 
    if(!cJSON_IsNumber(slow_mode_delay))
    {
    goto end; //Numeric
    }
    }

    // chat_full_info->unrestrict_boost_count
    cJSON *unrestrict_boost_count = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "unrestrict_boost_count");
    if (cJSON_IsNull(unrestrict_boost_count)) {
        unrestrict_boost_count = NULL;
    }
    if (unrestrict_boost_count) { 
    if(!cJSON_IsNumber(unrestrict_boost_count))
    {
    goto end; //Numeric
    }
    }

    // chat_full_info->message_auto_delete_time
    cJSON *message_auto_delete_time = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "message_auto_delete_time");
    if (cJSON_IsNull(message_auto_delete_time)) {
        message_auto_delete_time = NULL;
    }
    if (message_auto_delete_time) { 
    if(!cJSON_IsNumber(message_auto_delete_time))
    {
    goto end; //Numeric
    }
    }

    // chat_full_info->has_aggressive_anti_spam_enabled
    cJSON *has_aggressive_anti_spam_enabled = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "has_aggressive_anti_spam_enabled");
    if (cJSON_IsNull(has_aggressive_anti_spam_enabled)) {
        has_aggressive_anti_spam_enabled = NULL;
    }
    if (has_aggressive_anti_spam_enabled) { 
    if(!cJSON_IsBool(has_aggressive_anti_spam_enabled))
    {
    goto end; //Bool
    }
    }

    // chat_full_info->has_hidden_members
    cJSON *has_hidden_members = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "has_hidden_members");
    if (cJSON_IsNull(has_hidden_members)) {
        has_hidden_members = NULL;
    }
    if (has_hidden_members) { 
    if(!cJSON_IsBool(has_hidden_members))
    {
    goto end; //Bool
    }
    }

    // chat_full_info->has_protected_content
    cJSON *has_protected_content = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "has_protected_content");
    if (cJSON_IsNull(has_protected_content)) {
        has_protected_content = NULL;
    }
    if (has_protected_content) { 
    if(!cJSON_IsBool(has_protected_content))
    {
    goto end; //Bool
    }
    }

    // chat_full_info->has_visible_history
    cJSON *has_visible_history = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "has_visible_history");
    if (cJSON_IsNull(has_visible_history)) {
        has_visible_history = NULL;
    }
    if (has_visible_history) { 
    if(!cJSON_IsBool(has_visible_history))
    {
    goto end; //Bool
    }
    }

    // chat_full_info->sticker_set_name
    cJSON *sticker_set_name = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "sticker_set_name");
    if (cJSON_IsNull(sticker_set_name)) {
        sticker_set_name = NULL;
    }
    if (sticker_set_name) { 
    if(!cJSON_IsString(sticker_set_name) && !cJSON_IsNull(sticker_set_name))
    {
    goto end; //String
    }
    }

    // chat_full_info->can_set_sticker_set
    cJSON *can_set_sticker_set = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "can_set_sticker_set");
    if (cJSON_IsNull(can_set_sticker_set)) {
        can_set_sticker_set = NULL;
    }
    if (can_set_sticker_set) { 
    if(!cJSON_IsBool(can_set_sticker_set))
    {
    goto end; //Bool
    }
    }

    // chat_full_info->custom_emoji_sticker_set_name
    cJSON *custom_emoji_sticker_set_name = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "custom_emoji_sticker_set_name");
    if (cJSON_IsNull(custom_emoji_sticker_set_name)) {
        custom_emoji_sticker_set_name = NULL;
    }
    if (custom_emoji_sticker_set_name) { 
    if(!cJSON_IsString(custom_emoji_sticker_set_name) && !cJSON_IsNull(custom_emoji_sticker_set_name))
    {
    goto end; //String
    }
    }

    // chat_full_info->linked_chat_id
    cJSON *linked_chat_id = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "linked_chat_id");
    if (cJSON_IsNull(linked_chat_id)) {
        linked_chat_id = NULL;
    }
    if (linked_chat_id) { 
    if(!cJSON_IsNumber(linked_chat_id))
    {
    goto end; //Numeric
    }
    }

    // chat_full_info->location
    cJSON *location = cJSON_GetObjectItemCaseSensitive(chat_full_infoJSON, "location");
    if (cJSON_IsNull(location)) {
        location = NULL;
    }
    if (location) { 
    location_local_nonprim = chat_location_parseFromJSON(location); //nonprimitive
    }


    chat_full_info_local_var = chat_full_info_create_internal (
        id->valuedouble,
        typeVariable,
        accent_color_id->valuedouble,
        max_reaction_count->valuedouble,
        accepted_gift_types_local_nonprim,
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        username && !cJSON_IsNull(username) ? strdup(username->valuestring) : NULL,
        first_name && !cJSON_IsNull(first_name) ? strdup(first_name->valuestring) : NULL,
        last_name && !cJSON_IsNull(last_name) ? strdup(last_name->valuestring) : NULL,
        is_forum ? is_forum->valueint : 0,
        photo ? photo_local_nonprim : NULL,
        active_usernames ? active_usernamesList : NULL,
        birthdate ? birthdate_local_nonprim : NULL,
        business_intro ? business_intro_local_nonprim : NULL,
        business_location ? business_location_local_nonprim : NULL,
        business_opening_hours ? business_opening_hours_local_nonprim : NULL,
        personal_chat ? personal_chat_local_nonprim : NULL,
        available_reactions ? available_reactionsList : NULL,
        background_custom_emoji_id && !cJSON_IsNull(background_custom_emoji_id) ? strdup(background_custom_emoji_id->valuestring) : NULL,
        profile_accent_color_id ? profile_accent_color_id->valuedouble : 0,
        profile_background_custom_emoji_id && !cJSON_IsNull(profile_background_custom_emoji_id) ? strdup(profile_background_custom_emoji_id->valuestring) : NULL,
        emoji_status_custom_emoji_id && !cJSON_IsNull(emoji_status_custom_emoji_id) ? strdup(emoji_status_custom_emoji_id->valuestring) : NULL,
        emoji_status_expiration_date ? emoji_status_expiration_date->valuedouble : 0,
        bio && !cJSON_IsNull(bio) ? strdup(bio->valuestring) : NULL,
        has_private_forwards ? has_private_forwards->valueint : 0,
        has_restricted_voice_and_video_messages ? has_restricted_voice_and_video_messages->valueint : 0,
        join_to_send_messages ? join_to_send_messages->valueint : 0,
        join_by_request ? join_by_request->valueint : 0,
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        invite_link && !cJSON_IsNull(invite_link) ? strdup(invite_link->valuestring) : NULL,
        pinned_message ? pinned_message_local_nonprim : NULL,
        permissions ? permissions_local_nonprim : NULL,
        can_send_paid_media ? can_send_paid_media->valueint : 0,
        slow_mode_delay ? slow_mode_delay->valuedouble : 0,
        unrestrict_boost_count ? unrestrict_boost_count->valuedouble : 0,
        message_auto_delete_time ? message_auto_delete_time->valuedouble : 0,
        has_aggressive_anti_spam_enabled ? has_aggressive_anti_spam_enabled->valueint : 0,
        has_hidden_members ? has_hidden_members->valueint : 0,
        has_protected_content ? has_protected_content->valueint : 0,
        has_visible_history ? has_visible_history->valueint : 0,
        sticker_set_name && !cJSON_IsNull(sticker_set_name) ? strdup(sticker_set_name->valuestring) : NULL,
        can_set_sticker_set ? can_set_sticker_set->valueint : 0,
        custom_emoji_sticker_set_name && !cJSON_IsNull(custom_emoji_sticker_set_name) ? strdup(custom_emoji_sticker_set_name->valuestring) : NULL,
        linked_chat_id ? linked_chat_id->valuedouble : 0,
        location ? location_local_nonprim : NULL
        );

    return chat_full_info_local_var;
end:
    if (accepted_gift_types_local_nonprim) {
        accepted_gift_types_free(accepted_gift_types_local_nonprim);
        accepted_gift_types_local_nonprim = NULL;
    }
    if (photo_local_nonprim) {
        chat_photo_free(photo_local_nonprim);
        photo_local_nonprim = NULL;
    }
    if (active_usernamesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, active_usernamesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(active_usernamesList);
        active_usernamesList = NULL;
    }
    if (birthdate_local_nonprim) {
        birthdate_free(birthdate_local_nonprim);
        birthdate_local_nonprim = NULL;
    }
    if (business_intro_local_nonprim) {
        business_intro_free(business_intro_local_nonprim);
        business_intro_local_nonprim = NULL;
    }
    if (business_location_local_nonprim) {
        business_location_free(business_location_local_nonprim);
        business_location_local_nonprim = NULL;
    }
    if (business_opening_hours_local_nonprim) {
        business_opening_hours_free(business_opening_hours_local_nonprim);
        business_opening_hours_local_nonprim = NULL;
    }
    if (personal_chat_local_nonprim) {
        chat_free(personal_chat_local_nonprim);
        personal_chat_local_nonprim = NULL;
    }
    if (available_reactionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, available_reactionsList) {
            reaction_type_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(available_reactionsList);
        available_reactionsList = NULL;
    }
    if (pinned_message_local_nonprim) {
        message_free(pinned_message_local_nonprim);
        pinned_message_local_nonprim = NULL;
    }
    if (permissions_local_nonprim) {
        chat_permissions_free(permissions_local_nonprim);
        permissions_local_nonprim = NULL;
    }
    if (location_local_nonprim) {
        chat_location_free(location_local_nonprim);
        location_local_nonprim = NULL;
    }
    return NULL;

}
