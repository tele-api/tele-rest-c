/*
 * _edit_message_text_post_200_response_result.h
 *
 * 
 */

#ifndef __edit_message_text_post_200_response_result_H_
#define __edit_message_text_post_200_response_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _edit_message_text_post_200_response_result_t _edit_message_text_post_200_response_result_t;

#include "animation.h"
#include "any_type.h"
#include "audio.h"
#include "chat.h"
#include "chat_background.h"
#include "chat_boost_added.h"
#include "chat_shared.h"
#include "contact.h"
#include "dice.h"
#include "document.h"
#include "external_reply_info.h"
#include "forum_topic_created.h"
#include "forum_topic_edited.h"
#include "game.h"
#include "gift_info.h"
#include "giveaway.h"
#include "giveaway_completed.h"
#include "giveaway_created.h"
#include "giveaway_winners.h"
#include "inline_keyboard_markup.h"
#include "invoice.h"
#include "link_preview_options.h"
#include "location.h"
#include "maybe_inaccessible_message.h"
#include "message.h"
#include "message_auto_delete_timer_changed.h"
#include "message_entity.h"
#include "message_origin.h"
#include "paid_media_info.h"
#include "paid_message_price_changed.h"
#include "passport_data.h"
#include "photo_size.h"
#include "poll.h"
#include "proximity_alert_triggered.h"
#include "refunded_payment.h"
#include "sticker.h"
#include "story.h"
#include "successful_payment.h"
#include "text_quote.h"
#include "unique_gift_info.h"
#include "user.h"
#include "users_shared.h"
#include "venue.h"
#include "video.h"
#include "video_chat_ended.h"
#include "video_chat_participants_invited.h"
#include "video_chat_scheduled.h"
#include "video_note.h"
#include "voice.h"
#include "web_app_data.h"
#include "write_access_allowed.h"



typedef struct _edit_message_text_post_200_response_result_t {
    int message_id; //numeric
    int date; //numeric
    struct chat_t *chat; //model
    int message_thread_id; //numeric
    struct user_t *from; //model
    struct chat_t *sender_chat; //model
    int sender_boost_count; //numeric
    struct user_t *sender_business_bot; //model
    char *business_connection_id; // string
    struct message_origin_t *forward_origin; //model
    int is_topic_message; //boolean
    int is_automatic_forward; //boolean
    struct message_t *reply_to_message; //model
    struct external_reply_info_t *external_reply; //model
    struct text_quote_t *quote; //model
    struct story_t *reply_to_story; //model
    struct user_t *via_bot; //model
    int edit_date; //numeric
    int has_protected_content; //boolean
    int is_from_offline; //boolean
    char *media_group_id; // string
    char *author_signature; // string
    int paid_star_count; //numeric
    char *text; // string
    list_t *entities; //nonprimitive container
    struct link_preview_options_t *link_preview_options; //model
    char *effect_id; // string
    struct animation_t *animation; //model
    struct audio_t *audio; //model
    struct document_t *document; //model
    struct paid_media_info_t *paid_media; //model
    list_t *photo; //nonprimitive container
    struct sticker_t *sticker; //model
    struct story_t *story; //model
    struct video_t *video; //model
    struct video_note_t *video_note; //model
    struct voice_t *voice; //model
    char *caption; // string
    list_t *caption_entities; //nonprimitive container
    int show_caption_above_media; //boolean
    int has_media_spoiler; //boolean
    struct contact_t *contact; //model
    struct dice_t *dice; //model
    struct game_t *game; //model
    struct poll_t *poll; //model
    struct venue_t *venue; //model
    struct location_t *location; //model
    list_t *new_chat_members; //nonprimitive container
    struct user_t *left_chat_member; //model
    char *new_chat_title; // string
    list_t *new_chat_photo; //nonprimitive container
    int delete_chat_photo; //boolean
    int group_chat_created; //boolean
    int supergroup_chat_created; //boolean
    int channel_chat_created; //boolean
    struct message_auto_delete_timer_changed_t *message_auto_delete_timer_changed; //model
    int migrate_to_chat_id; //numeric
    int migrate_from_chat_id; //numeric
    struct maybe_inaccessible_message_t *pinned_message; //model
    struct invoice_t *invoice; //model
    struct successful_payment_t *successful_payment; //model
    struct refunded_payment_t *refunded_payment; //model
    struct users_shared_t *users_shared; //model
    struct chat_shared_t *chat_shared; //model
    struct gift_info_t *gift; //model
    struct unique_gift_info_t *unique_gift; //model
    char *connected_website; // string
    struct write_access_allowed_t *write_access_allowed; //model
    struct passport_data_t *passport_data; //model
    struct proximity_alert_triggered_t *proximity_alert_triggered; //model
    struct chat_boost_added_t *boost_added; //model
    struct chat_background_t *chat_background_set; //model
    struct forum_topic_created_t *forum_topic_created; //model
    struct forum_topic_edited_t *forum_topic_edited; //model
    any_type_t *forum_topic_closed; // custom
    any_type_t *forum_topic_reopened; // custom
    any_type_t *general_forum_topic_hidden; // custom
    any_type_t *general_forum_topic_unhidden; // custom
    struct giveaway_created_t *giveaway_created; //model
    struct giveaway_t *giveaway; //model
    struct giveaway_winners_t *giveaway_winners; //model
    struct giveaway_completed_t *giveaway_completed; //model
    struct paid_message_price_changed_t *paid_message_price_changed; //model
    struct video_chat_scheduled_t *video_chat_scheduled; //model
    any_type_t *video_chat_started; // custom
    struct video_chat_ended_t *video_chat_ended; //model
    struct video_chat_participants_invited_t *video_chat_participants_invited; //model
    struct web_app_data_t *web_app_data; //model
    struct inline_keyboard_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _edit_message_text_post_200_response_result_t;

__attribute__((deprecated)) _edit_message_text_post_200_response_result_t *_edit_message_text_post_200_response_result_create(
    int message_id,
    int date,
    chat_t *chat,
    int message_thread_id,
    user_t *from,
    chat_t *sender_chat,
    int sender_boost_count,
    user_t *sender_business_bot,
    char *business_connection_id,
    message_origin_t *forward_origin,
    int is_topic_message,
    int is_automatic_forward,
    message_t *reply_to_message,
    external_reply_info_t *external_reply,
    text_quote_t *quote,
    story_t *reply_to_story,
    user_t *via_bot,
    int edit_date,
    int has_protected_content,
    int is_from_offline,
    char *media_group_id,
    char *author_signature,
    int paid_star_count,
    char *text,
    list_t *entities,
    link_preview_options_t *link_preview_options,
    char *effect_id,
    animation_t *animation,
    audio_t *audio,
    document_t *document,
    paid_media_info_t *paid_media,
    list_t *photo,
    sticker_t *sticker,
    story_t *story,
    video_t *video,
    video_note_t *video_note,
    voice_t *voice,
    char *caption,
    list_t *caption_entities,
    int show_caption_above_media,
    int has_media_spoiler,
    contact_t *contact,
    dice_t *dice,
    game_t *game,
    poll_t *poll,
    venue_t *venue,
    location_t *location,
    list_t *new_chat_members,
    user_t *left_chat_member,
    char *new_chat_title,
    list_t *new_chat_photo,
    int delete_chat_photo,
    int group_chat_created,
    int supergroup_chat_created,
    int channel_chat_created,
    message_auto_delete_timer_changed_t *message_auto_delete_timer_changed,
    int migrate_to_chat_id,
    int migrate_from_chat_id,
    maybe_inaccessible_message_t *pinned_message,
    invoice_t *invoice,
    successful_payment_t *successful_payment,
    refunded_payment_t *refunded_payment,
    users_shared_t *users_shared,
    chat_shared_t *chat_shared,
    gift_info_t *gift,
    unique_gift_info_t *unique_gift,
    char *connected_website,
    write_access_allowed_t *write_access_allowed,
    passport_data_t *passport_data,
    proximity_alert_triggered_t *proximity_alert_triggered,
    chat_boost_added_t *boost_added,
    chat_background_t *chat_background_set,
    forum_topic_created_t *forum_topic_created,
    forum_topic_edited_t *forum_topic_edited,
    any_type_t *forum_topic_closed,
    any_type_t *forum_topic_reopened,
    any_type_t *general_forum_topic_hidden,
    any_type_t *general_forum_topic_unhidden,
    giveaway_created_t *giveaway_created,
    giveaway_t *giveaway,
    giveaway_winners_t *giveaway_winners,
    giveaway_completed_t *giveaway_completed,
    paid_message_price_changed_t *paid_message_price_changed,
    video_chat_scheduled_t *video_chat_scheduled,
    any_type_t *video_chat_started,
    video_chat_ended_t *video_chat_ended,
    video_chat_participants_invited_t *video_chat_participants_invited,
    web_app_data_t *web_app_data,
    inline_keyboard_markup_t *reply_markup
);

void _edit_message_text_post_200_response_result_free(_edit_message_text_post_200_response_result_t *_edit_message_text_post_200_response_result);

_edit_message_text_post_200_response_result_t *_edit_message_text_post_200_response_result_parseFromJSON(cJSON *_edit_message_text_post_200_response_resultJSON);

cJSON *_edit_message_text_post_200_response_result_convertToJSON(_edit_message_text_post_200_response_result_t *_edit_message_text_post_200_response_result);

#endif /* __edit_message_text_post_200_response_result_H_ */

