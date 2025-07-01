/*
 * chat_full_info.h
 *
 * This object contains full information about a chat.
 */

#ifndef _chat_full_info_H_
#define _chat_full_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_full_info_t chat_full_info_t;

#include "accepted_gift_types.h"
#include "birthdate.h"
#include "business_intro.h"
#include "business_location.h"
#include "business_opening_hours.h"
#include "chat.h"
#include "chat_location.h"
#include "chat_permissions.h"
#include "chat_photo.h"
#include "message.h"
#include "reaction_type.h"

// Enum TYPE for chat_full_info

typedef enum  { telegram_bot_api_chat_full_info_TYPE_NULL = 0, telegram_bot_api_chat_full_info_TYPE__private, telegram_bot_api_chat_full_info_TYPE_group, telegram_bot_api_chat_full_info_TYPE_supergroup, telegram_bot_api_chat_full_info_TYPE_channel } telegram_bot_api_chat_full_info_TYPE_e;

char* chat_full_info_type_ToString(telegram_bot_api_chat_full_info_TYPE_e type);

telegram_bot_api_chat_full_info_TYPE_e chat_full_info_type_FromString(char* type);



typedef struct chat_full_info_t {
    int id; //numeric
    telegram_bot_api_chat_full_info_TYPE_e type; //enum
    int accent_color_id; //numeric
    int max_reaction_count; //numeric
    struct accepted_gift_types_t *accepted_gift_types; //model
    char *title; // string
    char *username; // string
    char *first_name; // string
    char *last_name; // string
    int is_forum; //boolean
    struct chat_photo_t *photo; //model
    list_t *active_usernames; //primitive container
    struct birthdate_t *birthdate; //model
    struct business_intro_t *business_intro; //model
    struct business_location_t *business_location; //model
    struct business_opening_hours_t *business_opening_hours; //model
    struct chat_t *personal_chat; //model
    list_t *available_reactions; //nonprimitive container
    char *background_custom_emoji_id; // string
    int profile_accent_color_id; //numeric
    char *profile_background_custom_emoji_id; // string
    char *emoji_status_custom_emoji_id; // string
    int emoji_status_expiration_date; //numeric
    char *bio; // string
    int has_private_forwards; //boolean
    int has_restricted_voice_and_video_messages; //boolean
    int join_to_send_messages; //boolean
    int join_by_request; //boolean
    char *description; // string
    char *invite_link; // string
    struct message_t *pinned_message; //model
    struct chat_permissions_t *permissions; //model
    int can_send_paid_media; //boolean
    int slow_mode_delay; //numeric
    int unrestrict_boost_count; //numeric
    int message_auto_delete_time; //numeric
    int has_aggressive_anti_spam_enabled; //boolean
    int has_hidden_members; //boolean
    int has_protected_content; //boolean
    int has_visible_history; //boolean
    char *sticker_set_name; // string
    int can_set_sticker_set; //boolean
    char *custom_emoji_sticker_set_name; // string
    int linked_chat_id; //numeric
    struct chat_location_t *location; //model

    int _library_owned; // Is the library responsible for freeing this object?
} chat_full_info_t;

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
);

void chat_full_info_free(chat_full_info_t *chat_full_info);

chat_full_info_t *chat_full_info_parseFromJSON(cJSON *chat_full_infoJSON);

cJSON *chat_full_info_convertToJSON(chat_full_info_t *chat_full_info);

#endif /* _chat_full_info_H_ */

