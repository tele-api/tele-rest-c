#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_edit_message_text_post_200_response_result.h"



static _edit_message_text_post_200_response_result_t *_edit_message_text_post_200_response_result_create_internal(
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
    ) {
    _edit_message_text_post_200_response_result_t *_edit_message_text_post_200_response_result_local_var = malloc(sizeof(_edit_message_text_post_200_response_result_t));
    if (!_edit_message_text_post_200_response_result_local_var) {
        return NULL;
    }
    _edit_message_text_post_200_response_result_local_var->message_id = message_id;
    _edit_message_text_post_200_response_result_local_var->date = date;
    _edit_message_text_post_200_response_result_local_var->chat = chat;
    _edit_message_text_post_200_response_result_local_var->message_thread_id = message_thread_id;
    _edit_message_text_post_200_response_result_local_var->from = from;
    _edit_message_text_post_200_response_result_local_var->sender_chat = sender_chat;
    _edit_message_text_post_200_response_result_local_var->sender_boost_count = sender_boost_count;
    _edit_message_text_post_200_response_result_local_var->sender_business_bot = sender_business_bot;
    _edit_message_text_post_200_response_result_local_var->business_connection_id = business_connection_id;
    _edit_message_text_post_200_response_result_local_var->forward_origin = forward_origin;
    _edit_message_text_post_200_response_result_local_var->is_topic_message = is_topic_message;
    _edit_message_text_post_200_response_result_local_var->is_automatic_forward = is_automatic_forward;
    _edit_message_text_post_200_response_result_local_var->reply_to_message = reply_to_message;
    _edit_message_text_post_200_response_result_local_var->external_reply = external_reply;
    _edit_message_text_post_200_response_result_local_var->quote = quote;
    _edit_message_text_post_200_response_result_local_var->reply_to_story = reply_to_story;
    _edit_message_text_post_200_response_result_local_var->via_bot = via_bot;
    _edit_message_text_post_200_response_result_local_var->edit_date = edit_date;
    _edit_message_text_post_200_response_result_local_var->has_protected_content = has_protected_content;
    _edit_message_text_post_200_response_result_local_var->is_from_offline = is_from_offline;
    _edit_message_text_post_200_response_result_local_var->media_group_id = media_group_id;
    _edit_message_text_post_200_response_result_local_var->author_signature = author_signature;
    _edit_message_text_post_200_response_result_local_var->paid_star_count = paid_star_count;
    _edit_message_text_post_200_response_result_local_var->text = text;
    _edit_message_text_post_200_response_result_local_var->entities = entities;
    _edit_message_text_post_200_response_result_local_var->link_preview_options = link_preview_options;
    _edit_message_text_post_200_response_result_local_var->effect_id = effect_id;
    _edit_message_text_post_200_response_result_local_var->animation = animation;
    _edit_message_text_post_200_response_result_local_var->audio = audio;
    _edit_message_text_post_200_response_result_local_var->document = document;
    _edit_message_text_post_200_response_result_local_var->paid_media = paid_media;
    _edit_message_text_post_200_response_result_local_var->photo = photo;
    _edit_message_text_post_200_response_result_local_var->sticker = sticker;
    _edit_message_text_post_200_response_result_local_var->story = story;
    _edit_message_text_post_200_response_result_local_var->video = video;
    _edit_message_text_post_200_response_result_local_var->video_note = video_note;
    _edit_message_text_post_200_response_result_local_var->voice = voice;
    _edit_message_text_post_200_response_result_local_var->caption = caption;
    _edit_message_text_post_200_response_result_local_var->caption_entities = caption_entities;
    _edit_message_text_post_200_response_result_local_var->show_caption_above_media = show_caption_above_media;
    _edit_message_text_post_200_response_result_local_var->has_media_spoiler = has_media_spoiler;
    _edit_message_text_post_200_response_result_local_var->contact = contact;
    _edit_message_text_post_200_response_result_local_var->dice = dice;
    _edit_message_text_post_200_response_result_local_var->game = game;
    _edit_message_text_post_200_response_result_local_var->poll = poll;
    _edit_message_text_post_200_response_result_local_var->venue = venue;
    _edit_message_text_post_200_response_result_local_var->location = location;
    _edit_message_text_post_200_response_result_local_var->new_chat_members = new_chat_members;
    _edit_message_text_post_200_response_result_local_var->left_chat_member = left_chat_member;
    _edit_message_text_post_200_response_result_local_var->new_chat_title = new_chat_title;
    _edit_message_text_post_200_response_result_local_var->new_chat_photo = new_chat_photo;
    _edit_message_text_post_200_response_result_local_var->delete_chat_photo = delete_chat_photo;
    _edit_message_text_post_200_response_result_local_var->group_chat_created = group_chat_created;
    _edit_message_text_post_200_response_result_local_var->supergroup_chat_created = supergroup_chat_created;
    _edit_message_text_post_200_response_result_local_var->channel_chat_created = channel_chat_created;
    _edit_message_text_post_200_response_result_local_var->message_auto_delete_timer_changed = message_auto_delete_timer_changed;
    _edit_message_text_post_200_response_result_local_var->migrate_to_chat_id = migrate_to_chat_id;
    _edit_message_text_post_200_response_result_local_var->migrate_from_chat_id = migrate_from_chat_id;
    _edit_message_text_post_200_response_result_local_var->pinned_message = pinned_message;
    _edit_message_text_post_200_response_result_local_var->invoice = invoice;
    _edit_message_text_post_200_response_result_local_var->successful_payment = successful_payment;
    _edit_message_text_post_200_response_result_local_var->refunded_payment = refunded_payment;
    _edit_message_text_post_200_response_result_local_var->users_shared = users_shared;
    _edit_message_text_post_200_response_result_local_var->chat_shared = chat_shared;
    _edit_message_text_post_200_response_result_local_var->gift = gift;
    _edit_message_text_post_200_response_result_local_var->unique_gift = unique_gift;
    _edit_message_text_post_200_response_result_local_var->connected_website = connected_website;
    _edit_message_text_post_200_response_result_local_var->write_access_allowed = write_access_allowed;
    _edit_message_text_post_200_response_result_local_var->passport_data = passport_data;
    _edit_message_text_post_200_response_result_local_var->proximity_alert_triggered = proximity_alert_triggered;
    _edit_message_text_post_200_response_result_local_var->boost_added = boost_added;
    _edit_message_text_post_200_response_result_local_var->chat_background_set = chat_background_set;
    _edit_message_text_post_200_response_result_local_var->forum_topic_created = forum_topic_created;
    _edit_message_text_post_200_response_result_local_var->forum_topic_edited = forum_topic_edited;
    _edit_message_text_post_200_response_result_local_var->forum_topic_closed = forum_topic_closed;
    _edit_message_text_post_200_response_result_local_var->forum_topic_reopened = forum_topic_reopened;
    _edit_message_text_post_200_response_result_local_var->general_forum_topic_hidden = general_forum_topic_hidden;
    _edit_message_text_post_200_response_result_local_var->general_forum_topic_unhidden = general_forum_topic_unhidden;
    _edit_message_text_post_200_response_result_local_var->giveaway_created = giveaway_created;
    _edit_message_text_post_200_response_result_local_var->giveaway = giveaway;
    _edit_message_text_post_200_response_result_local_var->giveaway_winners = giveaway_winners;
    _edit_message_text_post_200_response_result_local_var->giveaway_completed = giveaway_completed;
    _edit_message_text_post_200_response_result_local_var->paid_message_price_changed = paid_message_price_changed;
    _edit_message_text_post_200_response_result_local_var->video_chat_scheduled = video_chat_scheduled;
    _edit_message_text_post_200_response_result_local_var->video_chat_started = video_chat_started;
    _edit_message_text_post_200_response_result_local_var->video_chat_ended = video_chat_ended;
    _edit_message_text_post_200_response_result_local_var->video_chat_participants_invited = video_chat_participants_invited;
    _edit_message_text_post_200_response_result_local_var->web_app_data = web_app_data;
    _edit_message_text_post_200_response_result_local_var->reply_markup = reply_markup;

    _edit_message_text_post_200_response_result_local_var->_library_owned = 1;
    return _edit_message_text_post_200_response_result_local_var;
}

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
    ) {
    return _edit_message_text_post_200_response_result_create_internal (
        message_id,
        date,
        chat,
        message_thread_id,
        from,
        sender_chat,
        sender_boost_count,
        sender_business_bot,
        business_connection_id,
        forward_origin,
        is_topic_message,
        is_automatic_forward,
        reply_to_message,
        external_reply,
        quote,
        reply_to_story,
        via_bot,
        edit_date,
        has_protected_content,
        is_from_offline,
        media_group_id,
        author_signature,
        paid_star_count,
        text,
        entities,
        link_preview_options,
        effect_id,
        animation,
        audio,
        document,
        paid_media,
        photo,
        sticker,
        story,
        video,
        video_note,
        voice,
        caption,
        caption_entities,
        show_caption_above_media,
        has_media_spoiler,
        contact,
        dice,
        game,
        poll,
        venue,
        location,
        new_chat_members,
        left_chat_member,
        new_chat_title,
        new_chat_photo,
        delete_chat_photo,
        group_chat_created,
        supergroup_chat_created,
        channel_chat_created,
        message_auto_delete_timer_changed,
        migrate_to_chat_id,
        migrate_from_chat_id,
        pinned_message,
        invoice,
        successful_payment,
        refunded_payment,
        users_shared,
        chat_shared,
        gift,
        unique_gift,
        connected_website,
        write_access_allowed,
        passport_data,
        proximity_alert_triggered,
        boost_added,
        chat_background_set,
        forum_topic_created,
        forum_topic_edited,
        forum_topic_closed,
        forum_topic_reopened,
        general_forum_topic_hidden,
        general_forum_topic_unhidden,
        giveaway_created,
        giveaway,
        giveaway_winners,
        giveaway_completed,
        paid_message_price_changed,
        video_chat_scheduled,
        video_chat_started,
        video_chat_ended,
        video_chat_participants_invited,
        web_app_data,
        reply_markup
        );
}

void _edit_message_text_post_200_response_result_free(_edit_message_text_post_200_response_result_t *_edit_message_text_post_200_response_result) {
    if(NULL == _edit_message_text_post_200_response_result){
        return ;
    }
    if(_edit_message_text_post_200_response_result->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_edit_message_text_post_200_response_result_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_edit_message_text_post_200_response_result->chat) {
        chat_free(_edit_message_text_post_200_response_result->chat);
        _edit_message_text_post_200_response_result->chat = NULL;
    }
    if (_edit_message_text_post_200_response_result->from) {
        user_free(_edit_message_text_post_200_response_result->from);
        _edit_message_text_post_200_response_result->from = NULL;
    }
    if (_edit_message_text_post_200_response_result->sender_chat) {
        chat_free(_edit_message_text_post_200_response_result->sender_chat);
        _edit_message_text_post_200_response_result->sender_chat = NULL;
    }
    if (_edit_message_text_post_200_response_result->sender_business_bot) {
        user_free(_edit_message_text_post_200_response_result->sender_business_bot);
        _edit_message_text_post_200_response_result->sender_business_bot = NULL;
    }
    if (_edit_message_text_post_200_response_result->business_connection_id) {
        free(_edit_message_text_post_200_response_result->business_connection_id);
        _edit_message_text_post_200_response_result->business_connection_id = NULL;
    }
    if (_edit_message_text_post_200_response_result->forward_origin) {
        message_origin_free(_edit_message_text_post_200_response_result->forward_origin);
        _edit_message_text_post_200_response_result->forward_origin = NULL;
    }
    if (_edit_message_text_post_200_response_result->reply_to_message) {
        message_free(_edit_message_text_post_200_response_result->reply_to_message);
        _edit_message_text_post_200_response_result->reply_to_message = NULL;
    }
    if (_edit_message_text_post_200_response_result->external_reply) {
        external_reply_info_free(_edit_message_text_post_200_response_result->external_reply);
        _edit_message_text_post_200_response_result->external_reply = NULL;
    }
    if (_edit_message_text_post_200_response_result->quote) {
        text_quote_free(_edit_message_text_post_200_response_result->quote);
        _edit_message_text_post_200_response_result->quote = NULL;
    }
    if (_edit_message_text_post_200_response_result->reply_to_story) {
        story_free(_edit_message_text_post_200_response_result->reply_to_story);
        _edit_message_text_post_200_response_result->reply_to_story = NULL;
    }
    if (_edit_message_text_post_200_response_result->via_bot) {
        user_free(_edit_message_text_post_200_response_result->via_bot);
        _edit_message_text_post_200_response_result->via_bot = NULL;
    }
    if (_edit_message_text_post_200_response_result->media_group_id) {
        free(_edit_message_text_post_200_response_result->media_group_id);
        _edit_message_text_post_200_response_result->media_group_id = NULL;
    }
    if (_edit_message_text_post_200_response_result->author_signature) {
        free(_edit_message_text_post_200_response_result->author_signature);
        _edit_message_text_post_200_response_result->author_signature = NULL;
    }
    if (_edit_message_text_post_200_response_result->text) {
        free(_edit_message_text_post_200_response_result->text);
        _edit_message_text_post_200_response_result->text = NULL;
    }
    if (_edit_message_text_post_200_response_result->entities) {
        list_ForEach(listEntry, _edit_message_text_post_200_response_result->entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(_edit_message_text_post_200_response_result->entities);
        _edit_message_text_post_200_response_result->entities = NULL;
    }
    if (_edit_message_text_post_200_response_result->link_preview_options) {
        link_preview_options_free(_edit_message_text_post_200_response_result->link_preview_options);
        _edit_message_text_post_200_response_result->link_preview_options = NULL;
    }
    if (_edit_message_text_post_200_response_result->effect_id) {
        free(_edit_message_text_post_200_response_result->effect_id);
        _edit_message_text_post_200_response_result->effect_id = NULL;
    }
    if (_edit_message_text_post_200_response_result->animation) {
        animation_free(_edit_message_text_post_200_response_result->animation);
        _edit_message_text_post_200_response_result->animation = NULL;
    }
    if (_edit_message_text_post_200_response_result->audio) {
        audio_free(_edit_message_text_post_200_response_result->audio);
        _edit_message_text_post_200_response_result->audio = NULL;
    }
    if (_edit_message_text_post_200_response_result->document) {
        document_free(_edit_message_text_post_200_response_result->document);
        _edit_message_text_post_200_response_result->document = NULL;
    }
    if (_edit_message_text_post_200_response_result->paid_media) {
        paid_media_info_free(_edit_message_text_post_200_response_result->paid_media);
        _edit_message_text_post_200_response_result->paid_media = NULL;
    }
    if (_edit_message_text_post_200_response_result->photo) {
        list_ForEach(listEntry, _edit_message_text_post_200_response_result->photo) {
            photo_size_free(listEntry->data);
        }
        list_freeList(_edit_message_text_post_200_response_result->photo);
        _edit_message_text_post_200_response_result->photo = NULL;
    }
    if (_edit_message_text_post_200_response_result->sticker) {
        sticker_free(_edit_message_text_post_200_response_result->sticker);
        _edit_message_text_post_200_response_result->sticker = NULL;
    }
    if (_edit_message_text_post_200_response_result->story) {
        story_free(_edit_message_text_post_200_response_result->story);
        _edit_message_text_post_200_response_result->story = NULL;
    }
    if (_edit_message_text_post_200_response_result->video) {
        video_free(_edit_message_text_post_200_response_result->video);
        _edit_message_text_post_200_response_result->video = NULL;
    }
    if (_edit_message_text_post_200_response_result->video_note) {
        video_note_free(_edit_message_text_post_200_response_result->video_note);
        _edit_message_text_post_200_response_result->video_note = NULL;
    }
    if (_edit_message_text_post_200_response_result->voice) {
        voice_free(_edit_message_text_post_200_response_result->voice);
        _edit_message_text_post_200_response_result->voice = NULL;
    }
    if (_edit_message_text_post_200_response_result->caption) {
        free(_edit_message_text_post_200_response_result->caption);
        _edit_message_text_post_200_response_result->caption = NULL;
    }
    if (_edit_message_text_post_200_response_result->caption_entities) {
        list_ForEach(listEntry, _edit_message_text_post_200_response_result->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(_edit_message_text_post_200_response_result->caption_entities);
        _edit_message_text_post_200_response_result->caption_entities = NULL;
    }
    if (_edit_message_text_post_200_response_result->contact) {
        contact_free(_edit_message_text_post_200_response_result->contact);
        _edit_message_text_post_200_response_result->contact = NULL;
    }
    if (_edit_message_text_post_200_response_result->dice) {
        dice_free(_edit_message_text_post_200_response_result->dice);
        _edit_message_text_post_200_response_result->dice = NULL;
    }
    if (_edit_message_text_post_200_response_result->game) {
        game_free(_edit_message_text_post_200_response_result->game);
        _edit_message_text_post_200_response_result->game = NULL;
    }
    if (_edit_message_text_post_200_response_result->poll) {
        poll_free(_edit_message_text_post_200_response_result->poll);
        _edit_message_text_post_200_response_result->poll = NULL;
    }
    if (_edit_message_text_post_200_response_result->venue) {
        venue_free(_edit_message_text_post_200_response_result->venue);
        _edit_message_text_post_200_response_result->venue = NULL;
    }
    if (_edit_message_text_post_200_response_result->location) {
        location_free(_edit_message_text_post_200_response_result->location);
        _edit_message_text_post_200_response_result->location = NULL;
    }
    if (_edit_message_text_post_200_response_result->new_chat_members) {
        list_ForEach(listEntry, _edit_message_text_post_200_response_result->new_chat_members) {
            user_free(listEntry->data);
        }
        list_freeList(_edit_message_text_post_200_response_result->new_chat_members);
        _edit_message_text_post_200_response_result->new_chat_members = NULL;
    }
    if (_edit_message_text_post_200_response_result->left_chat_member) {
        user_free(_edit_message_text_post_200_response_result->left_chat_member);
        _edit_message_text_post_200_response_result->left_chat_member = NULL;
    }
    if (_edit_message_text_post_200_response_result->new_chat_title) {
        free(_edit_message_text_post_200_response_result->new_chat_title);
        _edit_message_text_post_200_response_result->new_chat_title = NULL;
    }
    if (_edit_message_text_post_200_response_result->new_chat_photo) {
        list_ForEach(listEntry, _edit_message_text_post_200_response_result->new_chat_photo) {
            photo_size_free(listEntry->data);
        }
        list_freeList(_edit_message_text_post_200_response_result->new_chat_photo);
        _edit_message_text_post_200_response_result->new_chat_photo = NULL;
    }
    if (_edit_message_text_post_200_response_result->message_auto_delete_timer_changed) {
        message_auto_delete_timer_changed_free(_edit_message_text_post_200_response_result->message_auto_delete_timer_changed);
        _edit_message_text_post_200_response_result->message_auto_delete_timer_changed = NULL;
    }
    if (_edit_message_text_post_200_response_result->pinned_message) {
        maybe_inaccessible_message_free(_edit_message_text_post_200_response_result->pinned_message);
        _edit_message_text_post_200_response_result->pinned_message = NULL;
    }
    if (_edit_message_text_post_200_response_result->invoice) {
        invoice_free(_edit_message_text_post_200_response_result->invoice);
        _edit_message_text_post_200_response_result->invoice = NULL;
    }
    if (_edit_message_text_post_200_response_result->successful_payment) {
        successful_payment_free(_edit_message_text_post_200_response_result->successful_payment);
        _edit_message_text_post_200_response_result->successful_payment = NULL;
    }
    if (_edit_message_text_post_200_response_result->refunded_payment) {
        refunded_payment_free(_edit_message_text_post_200_response_result->refunded_payment);
        _edit_message_text_post_200_response_result->refunded_payment = NULL;
    }
    if (_edit_message_text_post_200_response_result->users_shared) {
        users_shared_free(_edit_message_text_post_200_response_result->users_shared);
        _edit_message_text_post_200_response_result->users_shared = NULL;
    }
    if (_edit_message_text_post_200_response_result->chat_shared) {
        chat_shared_free(_edit_message_text_post_200_response_result->chat_shared);
        _edit_message_text_post_200_response_result->chat_shared = NULL;
    }
    if (_edit_message_text_post_200_response_result->gift) {
        gift_info_free(_edit_message_text_post_200_response_result->gift);
        _edit_message_text_post_200_response_result->gift = NULL;
    }
    if (_edit_message_text_post_200_response_result->unique_gift) {
        unique_gift_info_free(_edit_message_text_post_200_response_result->unique_gift);
        _edit_message_text_post_200_response_result->unique_gift = NULL;
    }
    if (_edit_message_text_post_200_response_result->connected_website) {
        free(_edit_message_text_post_200_response_result->connected_website);
        _edit_message_text_post_200_response_result->connected_website = NULL;
    }
    if (_edit_message_text_post_200_response_result->write_access_allowed) {
        write_access_allowed_free(_edit_message_text_post_200_response_result->write_access_allowed);
        _edit_message_text_post_200_response_result->write_access_allowed = NULL;
    }
    if (_edit_message_text_post_200_response_result->passport_data) {
        passport_data_free(_edit_message_text_post_200_response_result->passport_data);
        _edit_message_text_post_200_response_result->passport_data = NULL;
    }
    if (_edit_message_text_post_200_response_result->proximity_alert_triggered) {
        proximity_alert_triggered_free(_edit_message_text_post_200_response_result->proximity_alert_triggered);
        _edit_message_text_post_200_response_result->proximity_alert_triggered = NULL;
    }
    if (_edit_message_text_post_200_response_result->boost_added) {
        chat_boost_added_free(_edit_message_text_post_200_response_result->boost_added);
        _edit_message_text_post_200_response_result->boost_added = NULL;
    }
    if (_edit_message_text_post_200_response_result->chat_background_set) {
        chat_background_free(_edit_message_text_post_200_response_result->chat_background_set);
        _edit_message_text_post_200_response_result->chat_background_set = NULL;
    }
    if (_edit_message_text_post_200_response_result->forum_topic_created) {
        forum_topic_created_free(_edit_message_text_post_200_response_result->forum_topic_created);
        _edit_message_text_post_200_response_result->forum_topic_created = NULL;
    }
    if (_edit_message_text_post_200_response_result->forum_topic_edited) {
        forum_topic_edited_free(_edit_message_text_post_200_response_result->forum_topic_edited);
        _edit_message_text_post_200_response_result->forum_topic_edited = NULL;
    }
    if (_edit_message_text_post_200_response_result->forum_topic_closed) {
        _free(_edit_message_text_post_200_response_result->forum_topic_closed);
        _edit_message_text_post_200_response_result->forum_topic_closed = NULL;
    }
    if (_edit_message_text_post_200_response_result->forum_topic_reopened) {
        _free(_edit_message_text_post_200_response_result->forum_topic_reopened);
        _edit_message_text_post_200_response_result->forum_topic_reopened = NULL;
    }
    if (_edit_message_text_post_200_response_result->general_forum_topic_hidden) {
        _free(_edit_message_text_post_200_response_result->general_forum_topic_hidden);
        _edit_message_text_post_200_response_result->general_forum_topic_hidden = NULL;
    }
    if (_edit_message_text_post_200_response_result->general_forum_topic_unhidden) {
        _free(_edit_message_text_post_200_response_result->general_forum_topic_unhidden);
        _edit_message_text_post_200_response_result->general_forum_topic_unhidden = NULL;
    }
    if (_edit_message_text_post_200_response_result->giveaway_created) {
        giveaway_created_free(_edit_message_text_post_200_response_result->giveaway_created);
        _edit_message_text_post_200_response_result->giveaway_created = NULL;
    }
    if (_edit_message_text_post_200_response_result->giveaway) {
        giveaway_free(_edit_message_text_post_200_response_result->giveaway);
        _edit_message_text_post_200_response_result->giveaway = NULL;
    }
    if (_edit_message_text_post_200_response_result->giveaway_winners) {
        giveaway_winners_free(_edit_message_text_post_200_response_result->giveaway_winners);
        _edit_message_text_post_200_response_result->giveaway_winners = NULL;
    }
    if (_edit_message_text_post_200_response_result->giveaway_completed) {
        giveaway_completed_free(_edit_message_text_post_200_response_result->giveaway_completed);
        _edit_message_text_post_200_response_result->giveaway_completed = NULL;
    }
    if (_edit_message_text_post_200_response_result->paid_message_price_changed) {
        paid_message_price_changed_free(_edit_message_text_post_200_response_result->paid_message_price_changed);
        _edit_message_text_post_200_response_result->paid_message_price_changed = NULL;
    }
    if (_edit_message_text_post_200_response_result->video_chat_scheduled) {
        video_chat_scheduled_free(_edit_message_text_post_200_response_result->video_chat_scheduled);
        _edit_message_text_post_200_response_result->video_chat_scheduled = NULL;
    }
    if (_edit_message_text_post_200_response_result->video_chat_started) {
        _free(_edit_message_text_post_200_response_result->video_chat_started);
        _edit_message_text_post_200_response_result->video_chat_started = NULL;
    }
    if (_edit_message_text_post_200_response_result->video_chat_ended) {
        video_chat_ended_free(_edit_message_text_post_200_response_result->video_chat_ended);
        _edit_message_text_post_200_response_result->video_chat_ended = NULL;
    }
    if (_edit_message_text_post_200_response_result->video_chat_participants_invited) {
        video_chat_participants_invited_free(_edit_message_text_post_200_response_result->video_chat_participants_invited);
        _edit_message_text_post_200_response_result->video_chat_participants_invited = NULL;
    }
    if (_edit_message_text_post_200_response_result->web_app_data) {
        web_app_data_free(_edit_message_text_post_200_response_result->web_app_data);
        _edit_message_text_post_200_response_result->web_app_data = NULL;
    }
    if (_edit_message_text_post_200_response_result->reply_markup) {
        inline_keyboard_markup_free(_edit_message_text_post_200_response_result->reply_markup);
        _edit_message_text_post_200_response_result->reply_markup = NULL;
    }
    free(_edit_message_text_post_200_response_result);
}

cJSON *_edit_message_text_post_200_response_result_convertToJSON(_edit_message_text_post_200_response_result_t *_edit_message_text_post_200_response_result) {
    cJSON *item = cJSON_CreateObject();

    // _edit_message_text_post_200_response_result->message_id
    if (!_edit_message_text_post_200_response_result->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", _edit_message_text_post_200_response_result->message_id) == NULL) {
    goto fail; //Numeric
    }


    // _edit_message_text_post_200_response_result->date
    if (!_edit_message_text_post_200_response_result->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", _edit_message_text_post_200_response_result->date) == NULL) {
    goto fail; //Numeric
    }


    // _edit_message_text_post_200_response_result->chat
    if (!_edit_message_text_post_200_response_result->chat) {
        goto fail;
    }
    cJSON *chat_local_JSON = chat_convertToJSON(_edit_message_text_post_200_response_result->chat);
    if(chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat", chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _edit_message_text_post_200_response_result->message_thread_id
    if(_edit_message_text_post_200_response_result->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", _edit_message_text_post_200_response_result->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // _edit_message_text_post_200_response_result->from
    if(_edit_message_text_post_200_response_result->from) {
    cJSON *from_local_JSON = user_convertToJSON(_edit_message_text_post_200_response_result->from);
    if(from_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "from", from_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->sender_chat
    if(_edit_message_text_post_200_response_result->sender_chat) {
    cJSON *sender_chat_local_JSON = chat_convertToJSON(_edit_message_text_post_200_response_result->sender_chat);
    if(sender_chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sender_chat", sender_chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->sender_boost_count
    if(_edit_message_text_post_200_response_result->sender_boost_count) {
    if(cJSON_AddNumberToObject(item, "sender_boost_count", _edit_message_text_post_200_response_result->sender_boost_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // _edit_message_text_post_200_response_result->sender_business_bot
    if(_edit_message_text_post_200_response_result->sender_business_bot) {
    cJSON *sender_business_bot_local_JSON = user_convertToJSON(_edit_message_text_post_200_response_result->sender_business_bot);
    if(sender_business_bot_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sender_business_bot", sender_business_bot_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->business_connection_id
    if(_edit_message_text_post_200_response_result->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", _edit_message_text_post_200_response_result->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // _edit_message_text_post_200_response_result->forward_origin
    if(_edit_message_text_post_200_response_result->forward_origin) {
    cJSON *forward_origin_local_JSON = message_origin_convertToJSON(_edit_message_text_post_200_response_result->forward_origin);
    if(forward_origin_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "forward_origin", forward_origin_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->is_topic_message
    if(_edit_message_text_post_200_response_result->is_topic_message) {
    if(cJSON_AddBoolToObject(item, "is_topic_message", _edit_message_text_post_200_response_result->is_topic_message) == NULL) {
    goto fail; //Bool
    }
    }


    // _edit_message_text_post_200_response_result->is_automatic_forward
    if(_edit_message_text_post_200_response_result->is_automatic_forward) {
    if(cJSON_AddBoolToObject(item, "is_automatic_forward", _edit_message_text_post_200_response_result->is_automatic_forward) == NULL) {
    goto fail; //Bool
    }
    }


    // _edit_message_text_post_200_response_result->reply_to_message
    if(_edit_message_text_post_200_response_result->reply_to_message) {
    cJSON *reply_to_message_local_JSON = message_convertToJSON(_edit_message_text_post_200_response_result->reply_to_message);
    if(reply_to_message_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_to_message", reply_to_message_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->external_reply
    if(_edit_message_text_post_200_response_result->external_reply) {
    cJSON *external_reply_local_JSON = external_reply_info_convertToJSON(_edit_message_text_post_200_response_result->external_reply);
    if(external_reply_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "external_reply", external_reply_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->quote
    if(_edit_message_text_post_200_response_result->quote) {
    cJSON *quote_local_JSON = text_quote_convertToJSON(_edit_message_text_post_200_response_result->quote);
    if(quote_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "quote", quote_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->reply_to_story
    if(_edit_message_text_post_200_response_result->reply_to_story) {
    cJSON *reply_to_story_local_JSON = story_convertToJSON(_edit_message_text_post_200_response_result->reply_to_story);
    if(reply_to_story_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_to_story", reply_to_story_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->via_bot
    if(_edit_message_text_post_200_response_result->via_bot) {
    cJSON *via_bot_local_JSON = user_convertToJSON(_edit_message_text_post_200_response_result->via_bot);
    if(via_bot_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "via_bot", via_bot_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->edit_date
    if(_edit_message_text_post_200_response_result->edit_date) {
    if(cJSON_AddNumberToObject(item, "edit_date", _edit_message_text_post_200_response_result->edit_date) == NULL) {
    goto fail; //Numeric
    }
    }


    // _edit_message_text_post_200_response_result->has_protected_content
    if(_edit_message_text_post_200_response_result->has_protected_content) {
    if(cJSON_AddBoolToObject(item, "has_protected_content", _edit_message_text_post_200_response_result->has_protected_content) == NULL) {
    goto fail; //Bool
    }
    }


    // _edit_message_text_post_200_response_result->is_from_offline
    if(_edit_message_text_post_200_response_result->is_from_offline) {
    if(cJSON_AddBoolToObject(item, "is_from_offline", _edit_message_text_post_200_response_result->is_from_offline) == NULL) {
    goto fail; //Bool
    }
    }


    // _edit_message_text_post_200_response_result->media_group_id
    if(_edit_message_text_post_200_response_result->media_group_id) {
    if(cJSON_AddStringToObject(item, "media_group_id", _edit_message_text_post_200_response_result->media_group_id) == NULL) {
    goto fail; //String
    }
    }


    // _edit_message_text_post_200_response_result->author_signature
    if(_edit_message_text_post_200_response_result->author_signature) {
    if(cJSON_AddStringToObject(item, "author_signature", _edit_message_text_post_200_response_result->author_signature) == NULL) {
    goto fail; //String
    }
    }


    // _edit_message_text_post_200_response_result->paid_star_count
    if(_edit_message_text_post_200_response_result->paid_star_count) {
    if(cJSON_AddNumberToObject(item, "paid_star_count", _edit_message_text_post_200_response_result->paid_star_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // _edit_message_text_post_200_response_result->text
    if(_edit_message_text_post_200_response_result->text) {
    if(cJSON_AddStringToObject(item, "text", _edit_message_text_post_200_response_result->text) == NULL) {
    goto fail; //String
    }
    }


    // _edit_message_text_post_200_response_result->entities
    if(_edit_message_text_post_200_response_result->entities) {
    cJSON *entities = cJSON_AddArrayToObject(item, "entities");
    if(entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *entitiesListEntry;
    if (_edit_message_text_post_200_response_result->entities) {
    list_ForEach(entitiesListEntry, _edit_message_text_post_200_response_result->entities) {
    cJSON *itemLocal = message_entity_convertToJSON(entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(entities, itemLocal);
    }
    }
    }


    // _edit_message_text_post_200_response_result->link_preview_options
    if(_edit_message_text_post_200_response_result->link_preview_options) {
    cJSON *link_preview_options_local_JSON = link_preview_options_convertToJSON(_edit_message_text_post_200_response_result->link_preview_options);
    if(link_preview_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "link_preview_options", link_preview_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->effect_id
    if(_edit_message_text_post_200_response_result->effect_id) {
    if(cJSON_AddStringToObject(item, "effect_id", _edit_message_text_post_200_response_result->effect_id) == NULL) {
    goto fail; //String
    }
    }


    // _edit_message_text_post_200_response_result->animation
    if(_edit_message_text_post_200_response_result->animation) {
    cJSON *animation_local_JSON = animation_convertToJSON(_edit_message_text_post_200_response_result->animation);
    if(animation_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "animation", animation_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->audio
    if(_edit_message_text_post_200_response_result->audio) {
    cJSON *audio_local_JSON = audio_convertToJSON(_edit_message_text_post_200_response_result->audio);
    if(audio_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "audio", audio_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->document
    if(_edit_message_text_post_200_response_result->document) {
    cJSON *document_local_JSON = document_convertToJSON(_edit_message_text_post_200_response_result->document);
    if(document_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "document", document_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->paid_media
    if(_edit_message_text_post_200_response_result->paid_media) {
    cJSON *paid_media_local_JSON = paid_media_info_convertToJSON(_edit_message_text_post_200_response_result->paid_media);
    if(paid_media_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "paid_media", paid_media_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->photo
    if(_edit_message_text_post_200_response_result->photo) {
    cJSON *photo = cJSON_AddArrayToObject(item, "photo");
    if(photo == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *photoListEntry;
    if (_edit_message_text_post_200_response_result->photo) {
    list_ForEach(photoListEntry, _edit_message_text_post_200_response_result->photo) {
    cJSON *itemLocal = photo_size_convertToJSON(photoListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(photo, itemLocal);
    }
    }
    }


    // _edit_message_text_post_200_response_result->sticker
    if(_edit_message_text_post_200_response_result->sticker) {
    cJSON *sticker_local_JSON = sticker_convertToJSON(_edit_message_text_post_200_response_result->sticker);
    if(sticker_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sticker", sticker_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->story
    if(_edit_message_text_post_200_response_result->story) {
    cJSON *story_local_JSON = story_convertToJSON(_edit_message_text_post_200_response_result->story);
    if(story_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "story", story_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->video
    if(_edit_message_text_post_200_response_result->video) {
    cJSON *video_local_JSON = video_convertToJSON(_edit_message_text_post_200_response_result->video);
    if(video_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "video", video_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->video_note
    if(_edit_message_text_post_200_response_result->video_note) {
    cJSON *video_note_local_JSON = video_note_convertToJSON(_edit_message_text_post_200_response_result->video_note);
    if(video_note_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "video_note", video_note_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->voice
    if(_edit_message_text_post_200_response_result->voice) {
    cJSON *voice_local_JSON = voice_convertToJSON(_edit_message_text_post_200_response_result->voice);
    if(voice_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "voice", voice_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->caption
    if(_edit_message_text_post_200_response_result->caption) {
    if(cJSON_AddStringToObject(item, "caption", _edit_message_text_post_200_response_result->caption) == NULL) {
    goto fail; //String
    }
    }


    // _edit_message_text_post_200_response_result->caption_entities
    if(_edit_message_text_post_200_response_result->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (_edit_message_text_post_200_response_result->caption_entities) {
    list_ForEach(caption_entitiesListEntry, _edit_message_text_post_200_response_result->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // _edit_message_text_post_200_response_result->show_caption_above_media
    if(_edit_message_text_post_200_response_result->show_caption_above_media) {
    if(cJSON_AddBoolToObject(item, "show_caption_above_media", _edit_message_text_post_200_response_result->show_caption_above_media) == NULL) {
    goto fail; //Bool
    }
    }


    // _edit_message_text_post_200_response_result->has_media_spoiler
    if(_edit_message_text_post_200_response_result->has_media_spoiler) {
    if(cJSON_AddBoolToObject(item, "has_media_spoiler", _edit_message_text_post_200_response_result->has_media_spoiler) == NULL) {
    goto fail; //Bool
    }
    }


    // _edit_message_text_post_200_response_result->contact
    if(_edit_message_text_post_200_response_result->contact) {
    cJSON *contact_local_JSON = contact_convertToJSON(_edit_message_text_post_200_response_result->contact);
    if(contact_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "contact", contact_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->dice
    if(_edit_message_text_post_200_response_result->dice) {
    cJSON *dice_local_JSON = dice_convertToJSON(_edit_message_text_post_200_response_result->dice);
    if(dice_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "dice", dice_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->game
    if(_edit_message_text_post_200_response_result->game) {
    cJSON *game_local_JSON = game_convertToJSON(_edit_message_text_post_200_response_result->game);
    if(game_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "game", game_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->poll
    if(_edit_message_text_post_200_response_result->poll) {
    cJSON *poll_local_JSON = poll_convertToJSON(_edit_message_text_post_200_response_result->poll);
    if(poll_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "poll", poll_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->venue
    if(_edit_message_text_post_200_response_result->venue) {
    cJSON *venue_local_JSON = venue_convertToJSON(_edit_message_text_post_200_response_result->venue);
    if(venue_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "venue", venue_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->location
    if(_edit_message_text_post_200_response_result->location) {
    cJSON *location_local_JSON = location_convertToJSON(_edit_message_text_post_200_response_result->location);
    if(location_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "location", location_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->new_chat_members
    if(_edit_message_text_post_200_response_result->new_chat_members) {
    cJSON *new_chat_members = cJSON_AddArrayToObject(item, "new_chat_members");
    if(new_chat_members == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *new_chat_membersListEntry;
    if (_edit_message_text_post_200_response_result->new_chat_members) {
    list_ForEach(new_chat_membersListEntry, _edit_message_text_post_200_response_result->new_chat_members) {
    cJSON *itemLocal = user_convertToJSON(new_chat_membersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(new_chat_members, itemLocal);
    }
    }
    }


    // _edit_message_text_post_200_response_result->left_chat_member
    if(_edit_message_text_post_200_response_result->left_chat_member) {
    cJSON *left_chat_member_local_JSON = user_convertToJSON(_edit_message_text_post_200_response_result->left_chat_member);
    if(left_chat_member_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "left_chat_member", left_chat_member_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->new_chat_title
    if(_edit_message_text_post_200_response_result->new_chat_title) {
    if(cJSON_AddStringToObject(item, "new_chat_title", _edit_message_text_post_200_response_result->new_chat_title) == NULL) {
    goto fail; //String
    }
    }


    // _edit_message_text_post_200_response_result->new_chat_photo
    if(_edit_message_text_post_200_response_result->new_chat_photo) {
    cJSON *new_chat_photo = cJSON_AddArrayToObject(item, "new_chat_photo");
    if(new_chat_photo == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *new_chat_photoListEntry;
    if (_edit_message_text_post_200_response_result->new_chat_photo) {
    list_ForEach(new_chat_photoListEntry, _edit_message_text_post_200_response_result->new_chat_photo) {
    cJSON *itemLocal = photo_size_convertToJSON(new_chat_photoListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(new_chat_photo, itemLocal);
    }
    }
    }


    // _edit_message_text_post_200_response_result->delete_chat_photo
    if(_edit_message_text_post_200_response_result->delete_chat_photo) {
    if(cJSON_AddBoolToObject(item, "delete_chat_photo", _edit_message_text_post_200_response_result->delete_chat_photo) == NULL) {
    goto fail; //Bool
    }
    }


    // _edit_message_text_post_200_response_result->group_chat_created
    if(_edit_message_text_post_200_response_result->group_chat_created) {
    if(cJSON_AddBoolToObject(item, "group_chat_created", _edit_message_text_post_200_response_result->group_chat_created) == NULL) {
    goto fail; //Bool
    }
    }


    // _edit_message_text_post_200_response_result->supergroup_chat_created
    if(_edit_message_text_post_200_response_result->supergroup_chat_created) {
    if(cJSON_AddBoolToObject(item, "supergroup_chat_created", _edit_message_text_post_200_response_result->supergroup_chat_created) == NULL) {
    goto fail; //Bool
    }
    }


    // _edit_message_text_post_200_response_result->channel_chat_created
    if(_edit_message_text_post_200_response_result->channel_chat_created) {
    if(cJSON_AddBoolToObject(item, "channel_chat_created", _edit_message_text_post_200_response_result->channel_chat_created) == NULL) {
    goto fail; //Bool
    }
    }


    // _edit_message_text_post_200_response_result->message_auto_delete_timer_changed
    if(_edit_message_text_post_200_response_result->message_auto_delete_timer_changed) {
    cJSON *message_auto_delete_timer_changed_local_JSON = message_auto_delete_timer_changed_convertToJSON(_edit_message_text_post_200_response_result->message_auto_delete_timer_changed);
    if(message_auto_delete_timer_changed_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "message_auto_delete_timer_changed", message_auto_delete_timer_changed_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->migrate_to_chat_id
    if(_edit_message_text_post_200_response_result->migrate_to_chat_id) {
    if(cJSON_AddNumberToObject(item, "migrate_to_chat_id", _edit_message_text_post_200_response_result->migrate_to_chat_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // _edit_message_text_post_200_response_result->migrate_from_chat_id
    if(_edit_message_text_post_200_response_result->migrate_from_chat_id) {
    if(cJSON_AddNumberToObject(item, "migrate_from_chat_id", _edit_message_text_post_200_response_result->migrate_from_chat_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // _edit_message_text_post_200_response_result->pinned_message
    if(_edit_message_text_post_200_response_result->pinned_message) {
    cJSON *pinned_message_local_JSON = maybe_inaccessible_message_convertToJSON(_edit_message_text_post_200_response_result->pinned_message);
    if(pinned_message_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "pinned_message", pinned_message_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->invoice
    if(_edit_message_text_post_200_response_result->invoice) {
    cJSON *invoice_local_JSON = invoice_convertToJSON(_edit_message_text_post_200_response_result->invoice);
    if(invoice_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "invoice", invoice_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->successful_payment
    if(_edit_message_text_post_200_response_result->successful_payment) {
    cJSON *successful_payment_local_JSON = successful_payment_convertToJSON(_edit_message_text_post_200_response_result->successful_payment);
    if(successful_payment_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "successful_payment", successful_payment_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->refunded_payment
    if(_edit_message_text_post_200_response_result->refunded_payment) {
    cJSON *refunded_payment_local_JSON = refunded_payment_convertToJSON(_edit_message_text_post_200_response_result->refunded_payment);
    if(refunded_payment_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "refunded_payment", refunded_payment_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->users_shared
    if(_edit_message_text_post_200_response_result->users_shared) {
    cJSON *users_shared_local_JSON = users_shared_convertToJSON(_edit_message_text_post_200_response_result->users_shared);
    if(users_shared_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "users_shared", users_shared_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->chat_shared
    if(_edit_message_text_post_200_response_result->chat_shared) {
    cJSON *chat_shared_local_JSON = chat_shared_convertToJSON(_edit_message_text_post_200_response_result->chat_shared);
    if(chat_shared_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_shared", chat_shared_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->gift
    if(_edit_message_text_post_200_response_result->gift) {
    cJSON *gift_local_JSON = gift_info_convertToJSON(_edit_message_text_post_200_response_result->gift);
    if(gift_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "gift", gift_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->unique_gift
    if(_edit_message_text_post_200_response_result->unique_gift) {
    cJSON *unique_gift_local_JSON = unique_gift_info_convertToJSON(_edit_message_text_post_200_response_result->unique_gift);
    if(unique_gift_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "unique_gift", unique_gift_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->connected_website
    if(_edit_message_text_post_200_response_result->connected_website) {
    if(cJSON_AddStringToObject(item, "connected_website", _edit_message_text_post_200_response_result->connected_website) == NULL) {
    goto fail; //String
    }
    }


    // _edit_message_text_post_200_response_result->write_access_allowed
    if(_edit_message_text_post_200_response_result->write_access_allowed) {
    cJSON *write_access_allowed_local_JSON = write_access_allowed_convertToJSON(_edit_message_text_post_200_response_result->write_access_allowed);
    if(write_access_allowed_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "write_access_allowed", write_access_allowed_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->passport_data
    if(_edit_message_text_post_200_response_result->passport_data) {
    cJSON *passport_data_local_JSON = passport_data_convertToJSON(_edit_message_text_post_200_response_result->passport_data);
    if(passport_data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "passport_data", passport_data_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->proximity_alert_triggered
    if(_edit_message_text_post_200_response_result->proximity_alert_triggered) {
    cJSON *proximity_alert_triggered_local_JSON = proximity_alert_triggered_convertToJSON(_edit_message_text_post_200_response_result->proximity_alert_triggered);
    if(proximity_alert_triggered_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "proximity_alert_triggered", proximity_alert_triggered_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->boost_added
    if(_edit_message_text_post_200_response_result->boost_added) {
    cJSON *boost_added_local_JSON = chat_boost_added_convertToJSON(_edit_message_text_post_200_response_result->boost_added);
    if(boost_added_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "boost_added", boost_added_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->chat_background_set
    if(_edit_message_text_post_200_response_result->chat_background_set) {
    cJSON *chat_background_set_local_JSON = chat_background_convertToJSON(_edit_message_text_post_200_response_result->chat_background_set);
    if(chat_background_set_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_background_set", chat_background_set_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->forum_topic_created
    if(_edit_message_text_post_200_response_result->forum_topic_created) {
    cJSON *forum_topic_created_local_JSON = forum_topic_created_convertToJSON(_edit_message_text_post_200_response_result->forum_topic_created);
    if(forum_topic_created_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "forum_topic_created", forum_topic_created_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->forum_topic_edited
    if(_edit_message_text_post_200_response_result->forum_topic_edited) {
    cJSON *forum_topic_edited_local_JSON = forum_topic_edited_convertToJSON(_edit_message_text_post_200_response_result->forum_topic_edited);
    if(forum_topic_edited_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "forum_topic_edited", forum_topic_edited_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->forum_topic_closed
    if(_edit_message_text_post_200_response_result->forum_topic_closed) {
    cJSON *forum_topic_closed_local_JSON = _convertToJSON(_edit_message_text_post_200_response_result->forum_topic_closed);
    if(forum_topic_closed_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "forum_topic_closed", forum_topic_closed_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->forum_topic_reopened
    if(_edit_message_text_post_200_response_result->forum_topic_reopened) {
    cJSON *forum_topic_reopened_local_JSON = _convertToJSON(_edit_message_text_post_200_response_result->forum_topic_reopened);
    if(forum_topic_reopened_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "forum_topic_reopened", forum_topic_reopened_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->general_forum_topic_hidden
    if(_edit_message_text_post_200_response_result->general_forum_topic_hidden) {
    cJSON *general_forum_topic_hidden_local_JSON = _convertToJSON(_edit_message_text_post_200_response_result->general_forum_topic_hidden);
    if(general_forum_topic_hidden_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "general_forum_topic_hidden", general_forum_topic_hidden_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->general_forum_topic_unhidden
    if(_edit_message_text_post_200_response_result->general_forum_topic_unhidden) {
    cJSON *general_forum_topic_unhidden_local_JSON = _convertToJSON(_edit_message_text_post_200_response_result->general_forum_topic_unhidden);
    if(general_forum_topic_unhidden_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "general_forum_topic_unhidden", general_forum_topic_unhidden_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->giveaway_created
    if(_edit_message_text_post_200_response_result->giveaway_created) {
    cJSON *giveaway_created_local_JSON = giveaway_created_convertToJSON(_edit_message_text_post_200_response_result->giveaway_created);
    if(giveaway_created_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "giveaway_created", giveaway_created_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->giveaway
    if(_edit_message_text_post_200_response_result->giveaway) {
    cJSON *giveaway_local_JSON = giveaway_convertToJSON(_edit_message_text_post_200_response_result->giveaway);
    if(giveaway_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "giveaway", giveaway_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->giveaway_winners
    if(_edit_message_text_post_200_response_result->giveaway_winners) {
    cJSON *giveaway_winners_local_JSON = giveaway_winners_convertToJSON(_edit_message_text_post_200_response_result->giveaway_winners);
    if(giveaway_winners_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "giveaway_winners", giveaway_winners_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->giveaway_completed
    if(_edit_message_text_post_200_response_result->giveaway_completed) {
    cJSON *giveaway_completed_local_JSON = giveaway_completed_convertToJSON(_edit_message_text_post_200_response_result->giveaway_completed);
    if(giveaway_completed_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "giveaway_completed", giveaway_completed_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->paid_message_price_changed
    if(_edit_message_text_post_200_response_result->paid_message_price_changed) {
    cJSON *paid_message_price_changed_local_JSON = paid_message_price_changed_convertToJSON(_edit_message_text_post_200_response_result->paid_message_price_changed);
    if(paid_message_price_changed_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "paid_message_price_changed", paid_message_price_changed_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->video_chat_scheduled
    if(_edit_message_text_post_200_response_result->video_chat_scheduled) {
    cJSON *video_chat_scheduled_local_JSON = video_chat_scheduled_convertToJSON(_edit_message_text_post_200_response_result->video_chat_scheduled);
    if(video_chat_scheduled_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "video_chat_scheduled", video_chat_scheduled_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->video_chat_started
    if(_edit_message_text_post_200_response_result->video_chat_started) {
    cJSON *video_chat_started_local_JSON = _convertToJSON(_edit_message_text_post_200_response_result->video_chat_started);
    if(video_chat_started_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "video_chat_started", video_chat_started_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->video_chat_ended
    if(_edit_message_text_post_200_response_result->video_chat_ended) {
    cJSON *video_chat_ended_local_JSON = video_chat_ended_convertToJSON(_edit_message_text_post_200_response_result->video_chat_ended);
    if(video_chat_ended_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "video_chat_ended", video_chat_ended_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->video_chat_participants_invited
    if(_edit_message_text_post_200_response_result->video_chat_participants_invited) {
    cJSON *video_chat_participants_invited_local_JSON = video_chat_participants_invited_convertToJSON(_edit_message_text_post_200_response_result->video_chat_participants_invited);
    if(video_chat_participants_invited_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "video_chat_participants_invited", video_chat_participants_invited_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->web_app_data
    if(_edit_message_text_post_200_response_result->web_app_data) {
    cJSON *web_app_data_local_JSON = web_app_data_convertToJSON(_edit_message_text_post_200_response_result->web_app_data);
    if(web_app_data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "web_app_data", web_app_data_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_text_post_200_response_result->reply_markup
    if(_edit_message_text_post_200_response_result->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(_edit_message_text_post_200_response_result->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
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

_edit_message_text_post_200_response_result_t *_edit_message_text_post_200_response_result_parseFromJSON(cJSON *_edit_message_text_post_200_response_resultJSON){

    _edit_message_text_post_200_response_result_t *_edit_message_text_post_200_response_result_local_var = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->chat
    chat_t *chat_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->from
    user_t *from_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->sender_chat
    chat_t *sender_chat_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->sender_business_bot
    user_t *sender_business_bot_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->forward_origin
    message_origin_t *forward_origin_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->reply_to_message
    message_t *reply_to_message_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->external_reply
    external_reply_info_t *external_reply_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->quote
    text_quote_t *quote_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->reply_to_story
    story_t *reply_to_story_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->via_bot
    user_t *via_bot_local_nonprim = NULL;

    // define the local list for _edit_message_text_post_200_response_result->entities
    list_t *entitiesList = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->link_preview_options
    link_preview_options_t *link_preview_options_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->animation
    animation_t *animation_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->audio
    audio_t *audio_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->document
    document_t *document_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->paid_media
    paid_media_info_t *paid_media_local_nonprim = NULL;

    // define the local list for _edit_message_text_post_200_response_result->photo
    list_t *photoList = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->sticker
    sticker_t *sticker_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->story
    story_t *story_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->video
    video_t *video_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->video_note
    video_note_t *video_note_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->voice
    voice_t *voice_local_nonprim = NULL;

    // define the local list for _edit_message_text_post_200_response_result->caption_entities
    list_t *caption_entitiesList = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->contact
    contact_t *contact_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->dice
    dice_t *dice_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->game
    game_t *game_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->poll
    poll_t *poll_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->venue
    venue_t *venue_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->location
    location_t *location_local_nonprim = NULL;

    // define the local list for _edit_message_text_post_200_response_result->new_chat_members
    list_t *new_chat_membersList = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->left_chat_member
    user_t *left_chat_member_local_nonprim = NULL;

    // define the local list for _edit_message_text_post_200_response_result->new_chat_photo
    list_t *new_chat_photoList = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->message_auto_delete_timer_changed
    message_auto_delete_timer_changed_t *message_auto_delete_timer_changed_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->pinned_message
    maybe_inaccessible_message_t *pinned_message_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->invoice
    invoice_t *invoice_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->successful_payment
    successful_payment_t *successful_payment_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->refunded_payment
    refunded_payment_t *refunded_payment_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->users_shared
    users_shared_t *users_shared_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->chat_shared
    chat_shared_t *chat_shared_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->gift
    gift_info_t *gift_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->unique_gift
    unique_gift_info_t *unique_gift_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->write_access_allowed
    write_access_allowed_t *write_access_allowed_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->passport_data
    passport_data_t *passport_data_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->proximity_alert_triggered
    proximity_alert_triggered_t *proximity_alert_triggered_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->boost_added
    chat_boost_added_t *boost_added_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->chat_background_set
    chat_background_t *chat_background_set_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->forum_topic_created
    forum_topic_created_t *forum_topic_created_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->forum_topic_edited
    forum_topic_edited_t *forum_topic_edited_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->forum_topic_closed
    _t *forum_topic_closed_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->forum_topic_reopened
    _t *forum_topic_reopened_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->general_forum_topic_hidden
    _t *general_forum_topic_hidden_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->general_forum_topic_unhidden
    _t *general_forum_topic_unhidden_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->giveaway_created
    giveaway_created_t *giveaway_created_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->giveaway
    giveaway_t *giveaway_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->giveaway_winners
    giveaway_winners_t *giveaway_winners_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->giveaway_completed
    giveaway_completed_t *giveaway_completed_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->paid_message_price_changed
    paid_message_price_changed_t *paid_message_price_changed_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->video_chat_scheduled
    video_chat_scheduled_t *video_chat_scheduled_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->video_chat_started
    _t *video_chat_started_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->video_chat_ended
    video_chat_ended_t *video_chat_ended_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->video_chat_participants_invited
    video_chat_participants_invited_t *video_chat_participants_invited_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->web_app_data
    web_app_data_t *web_app_data_local_nonprim = NULL;

    // define the local variable for _edit_message_text_post_200_response_result->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // _edit_message_text_post_200_response_result->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (!message_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }

    // _edit_message_text_post_200_response_result->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "date");
    if (cJSON_IsNull(date)) {
        date = NULL;
    }
    if (!date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(date))
    {
    goto end; //Numeric
    }

    // _edit_message_text_post_200_response_result->chat
    cJSON *chat = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "chat");
    if (cJSON_IsNull(chat)) {
        chat = NULL;
    }
    if (!chat) {
        goto end;
    }

    
    chat_local_nonprim = chat_parseFromJSON(chat); //nonprimitive

    // _edit_message_text_post_200_response_result->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // _edit_message_text_post_200_response_result->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "from");
    if (cJSON_IsNull(from)) {
        from = NULL;
    }
    if (from) { 
    from_local_nonprim = user_parseFromJSON(from); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->sender_chat
    cJSON *sender_chat = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "sender_chat");
    if (cJSON_IsNull(sender_chat)) {
        sender_chat = NULL;
    }
    if (sender_chat) { 
    sender_chat_local_nonprim = chat_parseFromJSON(sender_chat); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->sender_boost_count
    cJSON *sender_boost_count = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "sender_boost_count");
    if (cJSON_IsNull(sender_boost_count)) {
        sender_boost_count = NULL;
    }
    if (sender_boost_count) { 
    if(!cJSON_IsNumber(sender_boost_count))
    {
    goto end; //Numeric
    }
    }

    // _edit_message_text_post_200_response_result->sender_business_bot
    cJSON *sender_business_bot = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "sender_business_bot");
    if (cJSON_IsNull(sender_business_bot)) {
        sender_business_bot = NULL;
    }
    if (sender_business_bot) { 
    sender_business_bot_local_nonprim = user_parseFromJSON(sender_business_bot); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // _edit_message_text_post_200_response_result->forward_origin
    cJSON *forward_origin = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "forward_origin");
    if (cJSON_IsNull(forward_origin)) {
        forward_origin = NULL;
    }
    if (forward_origin) { 
    forward_origin_local_nonprim = message_origin_parseFromJSON(forward_origin); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->is_topic_message
    cJSON *is_topic_message = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "is_topic_message");
    if (cJSON_IsNull(is_topic_message)) {
        is_topic_message = NULL;
    }
    if (is_topic_message) { 
    if(!cJSON_IsBool(is_topic_message))
    {
    goto end; //Bool
    }
    }

    // _edit_message_text_post_200_response_result->is_automatic_forward
    cJSON *is_automatic_forward = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "is_automatic_forward");
    if (cJSON_IsNull(is_automatic_forward)) {
        is_automatic_forward = NULL;
    }
    if (is_automatic_forward) { 
    if(!cJSON_IsBool(is_automatic_forward))
    {
    goto end; //Bool
    }
    }

    // _edit_message_text_post_200_response_result->reply_to_message
    cJSON *reply_to_message = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "reply_to_message");
    if (cJSON_IsNull(reply_to_message)) {
        reply_to_message = NULL;
    }
    if (reply_to_message) { 
    reply_to_message_local_nonprim = message_parseFromJSON(reply_to_message); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->external_reply
    cJSON *external_reply = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "external_reply");
    if (cJSON_IsNull(external_reply)) {
        external_reply = NULL;
    }
    if (external_reply) { 
    external_reply_local_nonprim = external_reply_info_parseFromJSON(external_reply); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->quote
    cJSON *quote = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "quote");
    if (cJSON_IsNull(quote)) {
        quote = NULL;
    }
    if (quote) { 
    quote_local_nonprim = text_quote_parseFromJSON(quote); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->reply_to_story
    cJSON *reply_to_story = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "reply_to_story");
    if (cJSON_IsNull(reply_to_story)) {
        reply_to_story = NULL;
    }
    if (reply_to_story) { 
    reply_to_story_local_nonprim = story_parseFromJSON(reply_to_story); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->via_bot
    cJSON *via_bot = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "via_bot");
    if (cJSON_IsNull(via_bot)) {
        via_bot = NULL;
    }
    if (via_bot) { 
    via_bot_local_nonprim = user_parseFromJSON(via_bot); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->edit_date
    cJSON *edit_date = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "edit_date");
    if (cJSON_IsNull(edit_date)) {
        edit_date = NULL;
    }
    if (edit_date) { 
    if(!cJSON_IsNumber(edit_date))
    {
    goto end; //Numeric
    }
    }

    // _edit_message_text_post_200_response_result->has_protected_content
    cJSON *has_protected_content = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "has_protected_content");
    if (cJSON_IsNull(has_protected_content)) {
        has_protected_content = NULL;
    }
    if (has_protected_content) { 
    if(!cJSON_IsBool(has_protected_content))
    {
    goto end; //Bool
    }
    }

    // _edit_message_text_post_200_response_result->is_from_offline
    cJSON *is_from_offline = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "is_from_offline");
    if (cJSON_IsNull(is_from_offline)) {
        is_from_offline = NULL;
    }
    if (is_from_offline) { 
    if(!cJSON_IsBool(is_from_offline))
    {
    goto end; //Bool
    }
    }

    // _edit_message_text_post_200_response_result->media_group_id
    cJSON *media_group_id = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "media_group_id");
    if (cJSON_IsNull(media_group_id)) {
        media_group_id = NULL;
    }
    if (media_group_id) { 
    if(!cJSON_IsString(media_group_id) && !cJSON_IsNull(media_group_id))
    {
    goto end; //String
    }
    }

    // _edit_message_text_post_200_response_result->author_signature
    cJSON *author_signature = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "author_signature");
    if (cJSON_IsNull(author_signature)) {
        author_signature = NULL;
    }
    if (author_signature) { 
    if(!cJSON_IsString(author_signature) && !cJSON_IsNull(author_signature))
    {
    goto end; //String
    }
    }

    // _edit_message_text_post_200_response_result->paid_star_count
    cJSON *paid_star_count = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "paid_star_count");
    if (cJSON_IsNull(paid_star_count)) {
        paid_star_count = NULL;
    }
    if (paid_star_count) { 
    if(!cJSON_IsNumber(paid_star_count))
    {
    goto end; //Numeric
    }
    }

    // _edit_message_text_post_200_response_result->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (text) { 
    if(!cJSON_IsString(text) && !cJSON_IsNull(text))
    {
    goto end; //String
    }
    }

    // _edit_message_text_post_200_response_result->entities
    cJSON *entities = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "entities");
    if (cJSON_IsNull(entities)) {
        entities = NULL;
    }
    if (entities) { 
    cJSON *entities_local_nonprimitive = NULL;
    if(!cJSON_IsArray(entities)){
        goto end; //nonprimitive container
    }

    entitiesList = list_createList();

    cJSON_ArrayForEach(entities_local_nonprimitive,entities )
    {
        if(!cJSON_IsObject(entities_local_nonprimitive)){
            goto end;
        }
        message_entity_t *entitiesItem = message_entity_parseFromJSON(entities_local_nonprimitive);

        list_addElement(entitiesList, entitiesItem);
    }
    }

    // _edit_message_text_post_200_response_result->link_preview_options
    cJSON *link_preview_options = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "link_preview_options");
    if (cJSON_IsNull(link_preview_options)) {
        link_preview_options = NULL;
    }
    if (link_preview_options) { 
    link_preview_options_local_nonprim = link_preview_options_parseFromJSON(link_preview_options); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->effect_id
    cJSON *effect_id = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "effect_id");
    if (cJSON_IsNull(effect_id)) {
        effect_id = NULL;
    }
    if (effect_id) { 
    if(!cJSON_IsString(effect_id) && !cJSON_IsNull(effect_id))
    {
    goto end; //String
    }
    }

    // _edit_message_text_post_200_response_result->animation
    cJSON *animation = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "animation");
    if (cJSON_IsNull(animation)) {
        animation = NULL;
    }
    if (animation) { 
    animation_local_nonprim = animation_parseFromJSON(animation); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->audio
    cJSON *audio = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "audio");
    if (cJSON_IsNull(audio)) {
        audio = NULL;
    }
    if (audio) { 
    audio_local_nonprim = audio_parseFromJSON(audio); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->document
    cJSON *document = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "document");
    if (cJSON_IsNull(document)) {
        document = NULL;
    }
    if (document) { 
    document_local_nonprim = document_parseFromJSON(document); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->paid_media
    cJSON *paid_media = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "paid_media");
    if (cJSON_IsNull(paid_media)) {
        paid_media = NULL;
    }
    if (paid_media) { 
    paid_media_local_nonprim = paid_media_info_parseFromJSON(paid_media); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->photo
    cJSON *photo = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "photo");
    if (cJSON_IsNull(photo)) {
        photo = NULL;
    }
    if (photo) { 
    cJSON *photo_local_nonprimitive = NULL;
    if(!cJSON_IsArray(photo)){
        goto end; //nonprimitive container
    }

    photoList = list_createList();

    cJSON_ArrayForEach(photo_local_nonprimitive,photo )
    {
        if(!cJSON_IsObject(photo_local_nonprimitive)){
            goto end;
        }
        photo_size_t *photoItem = photo_size_parseFromJSON(photo_local_nonprimitive);

        list_addElement(photoList, photoItem);
    }
    }

    // _edit_message_text_post_200_response_result->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "sticker");
    if (cJSON_IsNull(sticker)) {
        sticker = NULL;
    }
    if (sticker) { 
    sticker_local_nonprim = sticker_parseFromJSON(sticker); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->story
    cJSON *story = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "story");
    if (cJSON_IsNull(story)) {
        story = NULL;
    }
    if (story) { 
    story_local_nonprim = story_parseFromJSON(story); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->video
    cJSON *video = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "video");
    if (cJSON_IsNull(video)) {
        video = NULL;
    }
    if (video) { 
    video_local_nonprim = video_parseFromJSON(video); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->video_note
    cJSON *video_note = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "video_note");
    if (cJSON_IsNull(video_note)) {
        video_note = NULL;
    }
    if (video_note) { 
    video_note_local_nonprim = video_note_parseFromJSON(video_note); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->voice
    cJSON *voice = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "voice");
    if (cJSON_IsNull(voice)) {
        voice = NULL;
    }
    if (voice) { 
    voice_local_nonprim = voice_parseFromJSON(voice); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // _edit_message_text_post_200_response_result->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "caption_entities");
    if (cJSON_IsNull(caption_entities)) {
        caption_entities = NULL;
    }
    if (caption_entities) { 
    cJSON *caption_entities_local_nonprimitive = NULL;
    if(!cJSON_IsArray(caption_entities)){
        goto end; //nonprimitive container
    }

    caption_entitiesList = list_createList();

    cJSON_ArrayForEach(caption_entities_local_nonprimitive,caption_entities )
    {
        if(!cJSON_IsObject(caption_entities_local_nonprimitive)){
            goto end;
        }
        message_entity_t *caption_entitiesItem = message_entity_parseFromJSON(caption_entities_local_nonprimitive);

        list_addElement(caption_entitiesList, caption_entitiesItem);
    }
    }

    // _edit_message_text_post_200_response_result->show_caption_above_media
    cJSON *show_caption_above_media = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "show_caption_above_media");
    if (cJSON_IsNull(show_caption_above_media)) {
        show_caption_above_media = NULL;
    }
    if (show_caption_above_media) { 
    if(!cJSON_IsBool(show_caption_above_media))
    {
    goto end; //Bool
    }
    }

    // _edit_message_text_post_200_response_result->has_media_spoiler
    cJSON *has_media_spoiler = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "has_media_spoiler");
    if (cJSON_IsNull(has_media_spoiler)) {
        has_media_spoiler = NULL;
    }
    if (has_media_spoiler) { 
    if(!cJSON_IsBool(has_media_spoiler))
    {
    goto end; //Bool
    }
    }

    // _edit_message_text_post_200_response_result->contact
    cJSON *contact = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "contact");
    if (cJSON_IsNull(contact)) {
        contact = NULL;
    }
    if (contact) { 
    contact_local_nonprim = contact_parseFromJSON(contact); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->dice
    cJSON *dice = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "dice");
    if (cJSON_IsNull(dice)) {
        dice = NULL;
    }
    if (dice) { 
    dice_local_nonprim = dice_parseFromJSON(dice); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->game
    cJSON *game = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "game");
    if (cJSON_IsNull(game)) {
        game = NULL;
    }
    if (game) { 
    game_local_nonprim = game_parseFromJSON(game); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->poll
    cJSON *poll = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "poll");
    if (cJSON_IsNull(poll)) {
        poll = NULL;
    }
    if (poll) { 
    poll_local_nonprim = poll_parseFromJSON(poll); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->venue
    cJSON *venue = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "venue");
    if (cJSON_IsNull(venue)) {
        venue = NULL;
    }
    if (venue) { 
    venue_local_nonprim = venue_parseFromJSON(venue); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->location
    cJSON *location = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "location");
    if (cJSON_IsNull(location)) {
        location = NULL;
    }
    if (location) { 
    location_local_nonprim = location_parseFromJSON(location); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->new_chat_members
    cJSON *new_chat_members = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "new_chat_members");
    if (cJSON_IsNull(new_chat_members)) {
        new_chat_members = NULL;
    }
    if (new_chat_members) { 
    cJSON *new_chat_members_local_nonprimitive = NULL;
    if(!cJSON_IsArray(new_chat_members)){
        goto end; //nonprimitive container
    }

    new_chat_membersList = list_createList();

    cJSON_ArrayForEach(new_chat_members_local_nonprimitive,new_chat_members )
    {
        if(!cJSON_IsObject(new_chat_members_local_nonprimitive)){
            goto end;
        }
        user_t *new_chat_membersItem = user_parseFromJSON(new_chat_members_local_nonprimitive);

        list_addElement(new_chat_membersList, new_chat_membersItem);
    }
    }

    // _edit_message_text_post_200_response_result->left_chat_member
    cJSON *left_chat_member = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "left_chat_member");
    if (cJSON_IsNull(left_chat_member)) {
        left_chat_member = NULL;
    }
    if (left_chat_member) { 
    left_chat_member_local_nonprim = user_parseFromJSON(left_chat_member); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->new_chat_title
    cJSON *new_chat_title = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "new_chat_title");
    if (cJSON_IsNull(new_chat_title)) {
        new_chat_title = NULL;
    }
    if (new_chat_title) { 
    if(!cJSON_IsString(new_chat_title) && !cJSON_IsNull(new_chat_title))
    {
    goto end; //String
    }
    }

    // _edit_message_text_post_200_response_result->new_chat_photo
    cJSON *new_chat_photo = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "new_chat_photo");
    if (cJSON_IsNull(new_chat_photo)) {
        new_chat_photo = NULL;
    }
    if (new_chat_photo) { 
    cJSON *new_chat_photo_local_nonprimitive = NULL;
    if(!cJSON_IsArray(new_chat_photo)){
        goto end; //nonprimitive container
    }

    new_chat_photoList = list_createList();

    cJSON_ArrayForEach(new_chat_photo_local_nonprimitive,new_chat_photo )
    {
        if(!cJSON_IsObject(new_chat_photo_local_nonprimitive)){
            goto end;
        }
        photo_size_t *new_chat_photoItem = photo_size_parseFromJSON(new_chat_photo_local_nonprimitive);

        list_addElement(new_chat_photoList, new_chat_photoItem);
    }
    }

    // _edit_message_text_post_200_response_result->delete_chat_photo
    cJSON *delete_chat_photo = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "delete_chat_photo");
    if (cJSON_IsNull(delete_chat_photo)) {
        delete_chat_photo = NULL;
    }
    if (delete_chat_photo) { 
    if(!cJSON_IsBool(delete_chat_photo))
    {
    goto end; //Bool
    }
    }

    // _edit_message_text_post_200_response_result->group_chat_created
    cJSON *group_chat_created = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "group_chat_created");
    if (cJSON_IsNull(group_chat_created)) {
        group_chat_created = NULL;
    }
    if (group_chat_created) { 
    if(!cJSON_IsBool(group_chat_created))
    {
    goto end; //Bool
    }
    }

    // _edit_message_text_post_200_response_result->supergroup_chat_created
    cJSON *supergroup_chat_created = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "supergroup_chat_created");
    if (cJSON_IsNull(supergroup_chat_created)) {
        supergroup_chat_created = NULL;
    }
    if (supergroup_chat_created) { 
    if(!cJSON_IsBool(supergroup_chat_created))
    {
    goto end; //Bool
    }
    }

    // _edit_message_text_post_200_response_result->channel_chat_created
    cJSON *channel_chat_created = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "channel_chat_created");
    if (cJSON_IsNull(channel_chat_created)) {
        channel_chat_created = NULL;
    }
    if (channel_chat_created) { 
    if(!cJSON_IsBool(channel_chat_created))
    {
    goto end; //Bool
    }
    }

    // _edit_message_text_post_200_response_result->message_auto_delete_timer_changed
    cJSON *message_auto_delete_timer_changed = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "message_auto_delete_timer_changed");
    if (cJSON_IsNull(message_auto_delete_timer_changed)) {
        message_auto_delete_timer_changed = NULL;
    }
    if (message_auto_delete_timer_changed) { 
    message_auto_delete_timer_changed_local_nonprim = message_auto_delete_timer_changed_parseFromJSON(message_auto_delete_timer_changed); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->migrate_to_chat_id
    cJSON *migrate_to_chat_id = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "migrate_to_chat_id");
    if (cJSON_IsNull(migrate_to_chat_id)) {
        migrate_to_chat_id = NULL;
    }
    if (migrate_to_chat_id) { 
    if(!cJSON_IsNumber(migrate_to_chat_id))
    {
    goto end; //Numeric
    }
    }

    // _edit_message_text_post_200_response_result->migrate_from_chat_id
    cJSON *migrate_from_chat_id = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "migrate_from_chat_id");
    if (cJSON_IsNull(migrate_from_chat_id)) {
        migrate_from_chat_id = NULL;
    }
    if (migrate_from_chat_id) { 
    if(!cJSON_IsNumber(migrate_from_chat_id))
    {
    goto end; //Numeric
    }
    }

    // _edit_message_text_post_200_response_result->pinned_message
    cJSON *pinned_message = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "pinned_message");
    if (cJSON_IsNull(pinned_message)) {
        pinned_message = NULL;
    }
    if (pinned_message) { 
    pinned_message_local_nonprim = maybe_inaccessible_message_parseFromJSON(pinned_message); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->invoice
    cJSON *invoice = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "invoice");
    if (cJSON_IsNull(invoice)) {
        invoice = NULL;
    }
    if (invoice) { 
    invoice_local_nonprim = invoice_parseFromJSON(invoice); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->successful_payment
    cJSON *successful_payment = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "successful_payment");
    if (cJSON_IsNull(successful_payment)) {
        successful_payment = NULL;
    }
    if (successful_payment) { 
    successful_payment_local_nonprim = successful_payment_parseFromJSON(successful_payment); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->refunded_payment
    cJSON *refunded_payment = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "refunded_payment");
    if (cJSON_IsNull(refunded_payment)) {
        refunded_payment = NULL;
    }
    if (refunded_payment) { 
    refunded_payment_local_nonprim = refunded_payment_parseFromJSON(refunded_payment); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->users_shared
    cJSON *users_shared = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "users_shared");
    if (cJSON_IsNull(users_shared)) {
        users_shared = NULL;
    }
    if (users_shared) { 
    users_shared_local_nonprim = users_shared_parseFromJSON(users_shared); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->chat_shared
    cJSON *chat_shared = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "chat_shared");
    if (cJSON_IsNull(chat_shared)) {
        chat_shared = NULL;
    }
    if (chat_shared) { 
    chat_shared_local_nonprim = chat_shared_parseFromJSON(chat_shared); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->gift
    cJSON *gift = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "gift");
    if (cJSON_IsNull(gift)) {
        gift = NULL;
    }
    if (gift) { 
    gift_local_nonprim = gift_info_parseFromJSON(gift); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->unique_gift
    cJSON *unique_gift = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "unique_gift");
    if (cJSON_IsNull(unique_gift)) {
        unique_gift = NULL;
    }
    if (unique_gift) { 
    unique_gift_local_nonprim = unique_gift_info_parseFromJSON(unique_gift); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->connected_website
    cJSON *connected_website = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "connected_website");
    if (cJSON_IsNull(connected_website)) {
        connected_website = NULL;
    }
    if (connected_website) { 
    if(!cJSON_IsString(connected_website) && !cJSON_IsNull(connected_website))
    {
    goto end; //String
    }
    }

    // _edit_message_text_post_200_response_result->write_access_allowed
    cJSON *write_access_allowed = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "write_access_allowed");
    if (cJSON_IsNull(write_access_allowed)) {
        write_access_allowed = NULL;
    }
    if (write_access_allowed) { 
    write_access_allowed_local_nonprim = write_access_allowed_parseFromJSON(write_access_allowed); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->passport_data
    cJSON *passport_data = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "passport_data");
    if (cJSON_IsNull(passport_data)) {
        passport_data = NULL;
    }
    if (passport_data) { 
    passport_data_local_nonprim = passport_data_parseFromJSON(passport_data); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->proximity_alert_triggered
    cJSON *proximity_alert_triggered = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "proximity_alert_triggered");
    if (cJSON_IsNull(proximity_alert_triggered)) {
        proximity_alert_triggered = NULL;
    }
    if (proximity_alert_triggered) { 
    proximity_alert_triggered_local_nonprim = proximity_alert_triggered_parseFromJSON(proximity_alert_triggered); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->boost_added
    cJSON *boost_added = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "boost_added");
    if (cJSON_IsNull(boost_added)) {
        boost_added = NULL;
    }
    if (boost_added) { 
    boost_added_local_nonprim = chat_boost_added_parseFromJSON(boost_added); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->chat_background_set
    cJSON *chat_background_set = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "chat_background_set");
    if (cJSON_IsNull(chat_background_set)) {
        chat_background_set = NULL;
    }
    if (chat_background_set) { 
    chat_background_set_local_nonprim = chat_background_parseFromJSON(chat_background_set); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->forum_topic_created
    cJSON *forum_topic_created = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "forum_topic_created");
    if (cJSON_IsNull(forum_topic_created)) {
        forum_topic_created = NULL;
    }
    if (forum_topic_created) { 
    forum_topic_created_local_nonprim = forum_topic_created_parseFromJSON(forum_topic_created); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->forum_topic_edited
    cJSON *forum_topic_edited = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "forum_topic_edited");
    if (cJSON_IsNull(forum_topic_edited)) {
        forum_topic_edited = NULL;
    }
    if (forum_topic_edited) { 
    forum_topic_edited_local_nonprim = forum_topic_edited_parseFromJSON(forum_topic_edited); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->forum_topic_closed
    cJSON *forum_topic_closed = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "forum_topic_closed");
    if (cJSON_IsNull(forum_topic_closed)) {
        forum_topic_closed = NULL;
    }
    if (forum_topic_closed) { 
    forum_topic_closed_local_nonprim = _parseFromJSON(forum_topic_closed); //custom
    }

    // _edit_message_text_post_200_response_result->forum_topic_reopened
    cJSON *forum_topic_reopened = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "forum_topic_reopened");
    if (cJSON_IsNull(forum_topic_reopened)) {
        forum_topic_reopened = NULL;
    }
    if (forum_topic_reopened) { 
    forum_topic_reopened_local_nonprim = _parseFromJSON(forum_topic_reopened); //custom
    }

    // _edit_message_text_post_200_response_result->general_forum_topic_hidden
    cJSON *general_forum_topic_hidden = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "general_forum_topic_hidden");
    if (cJSON_IsNull(general_forum_topic_hidden)) {
        general_forum_topic_hidden = NULL;
    }
    if (general_forum_topic_hidden) { 
    general_forum_topic_hidden_local_nonprim = _parseFromJSON(general_forum_topic_hidden); //custom
    }

    // _edit_message_text_post_200_response_result->general_forum_topic_unhidden
    cJSON *general_forum_topic_unhidden = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "general_forum_topic_unhidden");
    if (cJSON_IsNull(general_forum_topic_unhidden)) {
        general_forum_topic_unhidden = NULL;
    }
    if (general_forum_topic_unhidden) { 
    general_forum_topic_unhidden_local_nonprim = _parseFromJSON(general_forum_topic_unhidden); //custom
    }

    // _edit_message_text_post_200_response_result->giveaway_created
    cJSON *giveaway_created = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "giveaway_created");
    if (cJSON_IsNull(giveaway_created)) {
        giveaway_created = NULL;
    }
    if (giveaway_created) { 
    giveaway_created_local_nonprim = giveaway_created_parseFromJSON(giveaway_created); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->giveaway
    cJSON *giveaway = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "giveaway");
    if (cJSON_IsNull(giveaway)) {
        giveaway = NULL;
    }
    if (giveaway) { 
    giveaway_local_nonprim = giveaway_parseFromJSON(giveaway); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->giveaway_winners
    cJSON *giveaway_winners = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "giveaway_winners");
    if (cJSON_IsNull(giveaway_winners)) {
        giveaway_winners = NULL;
    }
    if (giveaway_winners) { 
    giveaway_winners_local_nonprim = giveaway_winners_parseFromJSON(giveaway_winners); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->giveaway_completed
    cJSON *giveaway_completed = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "giveaway_completed");
    if (cJSON_IsNull(giveaway_completed)) {
        giveaway_completed = NULL;
    }
    if (giveaway_completed) { 
    giveaway_completed_local_nonprim = giveaway_completed_parseFromJSON(giveaway_completed); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->paid_message_price_changed
    cJSON *paid_message_price_changed = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "paid_message_price_changed");
    if (cJSON_IsNull(paid_message_price_changed)) {
        paid_message_price_changed = NULL;
    }
    if (paid_message_price_changed) { 
    paid_message_price_changed_local_nonprim = paid_message_price_changed_parseFromJSON(paid_message_price_changed); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->video_chat_scheduled
    cJSON *video_chat_scheduled = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "video_chat_scheduled");
    if (cJSON_IsNull(video_chat_scheduled)) {
        video_chat_scheduled = NULL;
    }
    if (video_chat_scheduled) { 
    video_chat_scheduled_local_nonprim = video_chat_scheduled_parseFromJSON(video_chat_scheduled); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->video_chat_started
    cJSON *video_chat_started = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "video_chat_started");
    if (cJSON_IsNull(video_chat_started)) {
        video_chat_started = NULL;
    }
    if (video_chat_started) { 
    video_chat_started_local_nonprim = _parseFromJSON(video_chat_started); //custom
    }

    // _edit_message_text_post_200_response_result->video_chat_ended
    cJSON *video_chat_ended = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "video_chat_ended");
    if (cJSON_IsNull(video_chat_ended)) {
        video_chat_ended = NULL;
    }
    if (video_chat_ended) { 
    video_chat_ended_local_nonprim = video_chat_ended_parseFromJSON(video_chat_ended); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->video_chat_participants_invited
    cJSON *video_chat_participants_invited = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "video_chat_participants_invited");
    if (cJSON_IsNull(video_chat_participants_invited)) {
        video_chat_participants_invited = NULL;
    }
    if (video_chat_participants_invited) { 
    video_chat_participants_invited_local_nonprim = video_chat_participants_invited_parseFromJSON(video_chat_participants_invited); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->web_app_data
    cJSON *web_app_data = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "web_app_data");
    if (cJSON_IsNull(web_app_data)) {
        web_app_data = NULL;
    }
    if (web_app_data) { 
    web_app_data_local_nonprim = web_app_data_parseFromJSON(web_app_data); //nonprimitive
    }

    // _edit_message_text_post_200_response_result->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(_edit_message_text_post_200_response_resultJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    _edit_message_text_post_200_response_result_local_var = _edit_message_text_post_200_response_result_create_internal (
        message_id->valuedouble,
        date->valuedouble,
        chat_local_nonprim,
        message_thread_id ? message_thread_id->valuedouble : 0,
        from ? from_local_nonprim : NULL,
        sender_chat ? sender_chat_local_nonprim : NULL,
        sender_boost_count ? sender_boost_count->valuedouble : 0,
        sender_business_bot ? sender_business_bot_local_nonprim : NULL,
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        forward_origin ? forward_origin_local_nonprim : NULL,
        is_topic_message ? is_topic_message->valueint : 0,
        is_automatic_forward ? is_automatic_forward->valueint : 0,
        reply_to_message ? reply_to_message_local_nonprim : NULL,
        external_reply ? external_reply_local_nonprim : NULL,
        quote ? quote_local_nonprim : NULL,
        reply_to_story ? reply_to_story_local_nonprim : NULL,
        via_bot ? via_bot_local_nonprim : NULL,
        edit_date ? edit_date->valuedouble : 0,
        has_protected_content ? has_protected_content->valueint : 0,
        is_from_offline ? is_from_offline->valueint : 0,
        media_group_id && !cJSON_IsNull(media_group_id) ? strdup(media_group_id->valuestring) : NULL,
        author_signature && !cJSON_IsNull(author_signature) ? strdup(author_signature->valuestring) : NULL,
        paid_star_count ? paid_star_count->valuedouble : 0,
        text && !cJSON_IsNull(text) ? strdup(text->valuestring) : NULL,
        entities ? entitiesList : NULL,
        link_preview_options ? link_preview_options_local_nonprim : NULL,
        effect_id && !cJSON_IsNull(effect_id) ? strdup(effect_id->valuestring) : NULL,
        animation ? animation_local_nonprim : NULL,
        audio ? audio_local_nonprim : NULL,
        document ? document_local_nonprim : NULL,
        paid_media ? paid_media_local_nonprim : NULL,
        photo ? photoList : NULL,
        sticker ? sticker_local_nonprim : NULL,
        story ? story_local_nonprim : NULL,
        video ? video_local_nonprim : NULL,
        video_note ? video_note_local_nonprim : NULL,
        voice ? voice_local_nonprim : NULL,
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        show_caption_above_media ? show_caption_above_media->valueint : 0,
        has_media_spoiler ? has_media_spoiler->valueint : 0,
        contact ? contact_local_nonprim : NULL,
        dice ? dice_local_nonprim : NULL,
        game ? game_local_nonprim : NULL,
        poll ? poll_local_nonprim : NULL,
        venue ? venue_local_nonprim : NULL,
        location ? location_local_nonprim : NULL,
        new_chat_members ? new_chat_membersList : NULL,
        left_chat_member ? left_chat_member_local_nonprim : NULL,
        new_chat_title && !cJSON_IsNull(new_chat_title) ? strdup(new_chat_title->valuestring) : NULL,
        new_chat_photo ? new_chat_photoList : NULL,
        delete_chat_photo ? delete_chat_photo->valueint : 0,
        group_chat_created ? group_chat_created->valueint : 0,
        supergroup_chat_created ? supergroup_chat_created->valueint : 0,
        channel_chat_created ? channel_chat_created->valueint : 0,
        message_auto_delete_timer_changed ? message_auto_delete_timer_changed_local_nonprim : NULL,
        migrate_to_chat_id ? migrate_to_chat_id->valuedouble : 0,
        migrate_from_chat_id ? migrate_from_chat_id->valuedouble : 0,
        pinned_message ? pinned_message_local_nonprim : NULL,
        invoice ? invoice_local_nonprim : NULL,
        successful_payment ? successful_payment_local_nonprim : NULL,
        refunded_payment ? refunded_payment_local_nonprim : NULL,
        users_shared ? users_shared_local_nonprim : NULL,
        chat_shared ? chat_shared_local_nonprim : NULL,
        gift ? gift_local_nonprim : NULL,
        unique_gift ? unique_gift_local_nonprim : NULL,
        connected_website && !cJSON_IsNull(connected_website) ? strdup(connected_website->valuestring) : NULL,
        write_access_allowed ? write_access_allowed_local_nonprim : NULL,
        passport_data ? passport_data_local_nonprim : NULL,
        proximity_alert_triggered ? proximity_alert_triggered_local_nonprim : NULL,
        boost_added ? boost_added_local_nonprim : NULL,
        chat_background_set ? chat_background_set_local_nonprim : NULL,
        forum_topic_created ? forum_topic_created_local_nonprim : NULL,
        forum_topic_edited ? forum_topic_edited_local_nonprim : NULL,
        forum_topic_closed ? forum_topic_closed_local_nonprim : NULL,
        forum_topic_reopened ? forum_topic_reopened_local_nonprim : NULL,
        general_forum_topic_hidden ? general_forum_topic_hidden_local_nonprim : NULL,
        general_forum_topic_unhidden ? general_forum_topic_unhidden_local_nonprim : NULL,
        giveaway_created ? giveaway_created_local_nonprim : NULL,
        giveaway ? giveaway_local_nonprim : NULL,
        giveaway_winners ? giveaway_winners_local_nonprim : NULL,
        giveaway_completed ? giveaway_completed_local_nonprim : NULL,
        paid_message_price_changed ? paid_message_price_changed_local_nonprim : NULL,
        video_chat_scheduled ? video_chat_scheduled_local_nonprim : NULL,
        video_chat_started ? video_chat_started_local_nonprim : NULL,
        video_chat_ended ? video_chat_ended_local_nonprim : NULL,
        video_chat_participants_invited ? video_chat_participants_invited_local_nonprim : NULL,
        web_app_data ? web_app_data_local_nonprim : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return _edit_message_text_post_200_response_result_local_var;
end:
    if (chat_local_nonprim) {
        chat_free(chat_local_nonprim);
        chat_local_nonprim = NULL;
    }
    if (from_local_nonprim) {
        user_free(from_local_nonprim);
        from_local_nonprim = NULL;
    }
    if (sender_chat_local_nonprim) {
        chat_free(sender_chat_local_nonprim);
        sender_chat_local_nonprim = NULL;
    }
    if (sender_business_bot_local_nonprim) {
        user_free(sender_business_bot_local_nonprim);
        sender_business_bot_local_nonprim = NULL;
    }
    if (forward_origin_local_nonprim) {
        message_origin_free(forward_origin_local_nonprim);
        forward_origin_local_nonprim = NULL;
    }
    if (reply_to_message_local_nonprim) {
        message_free(reply_to_message_local_nonprim);
        reply_to_message_local_nonprim = NULL;
    }
    if (external_reply_local_nonprim) {
        external_reply_info_free(external_reply_local_nonprim);
        external_reply_local_nonprim = NULL;
    }
    if (quote_local_nonprim) {
        text_quote_free(quote_local_nonprim);
        quote_local_nonprim = NULL;
    }
    if (reply_to_story_local_nonprim) {
        story_free(reply_to_story_local_nonprim);
        reply_to_story_local_nonprim = NULL;
    }
    if (via_bot_local_nonprim) {
        user_free(via_bot_local_nonprim);
        via_bot_local_nonprim = NULL;
    }
    if (entitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, entitiesList) {
            message_entity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(entitiesList);
        entitiesList = NULL;
    }
    if (link_preview_options_local_nonprim) {
        link_preview_options_free(link_preview_options_local_nonprim);
        link_preview_options_local_nonprim = NULL;
    }
    if (animation_local_nonprim) {
        animation_free(animation_local_nonprim);
        animation_local_nonprim = NULL;
    }
    if (audio_local_nonprim) {
        audio_free(audio_local_nonprim);
        audio_local_nonprim = NULL;
    }
    if (document_local_nonprim) {
        document_free(document_local_nonprim);
        document_local_nonprim = NULL;
    }
    if (paid_media_local_nonprim) {
        paid_media_info_free(paid_media_local_nonprim);
        paid_media_local_nonprim = NULL;
    }
    if (photoList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, photoList) {
            photo_size_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(photoList);
        photoList = NULL;
    }
    if (sticker_local_nonprim) {
        sticker_free(sticker_local_nonprim);
        sticker_local_nonprim = NULL;
    }
    if (story_local_nonprim) {
        story_free(story_local_nonprim);
        story_local_nonprim = NULL;
    }
    if (video_local_nonprim) {
        video_free(video_local_nonprim);
        video_local_nonprim = NULL;
    }
    if (video_note_local_nonprim) {
        video_note_free(video_note_local_nonprim);
        video_note_local_nonprim = NULL;
    }
    if (voice_local_nonprim) {
        voice_free(voice_local_nonprim);
        voice_local_nonprim = NULL;
    }
    if (caption_entitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, caption_entitiesList) {
            message_entity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(caption_entitiesList);
        caption_entitiesList = NULL;
    }
    if (contact_local_nonprim) {
        contact_free(contact_local_nonprim);
        contact_local_nonprim = NULL;
    }
    if (dice_local_nonprim) {
        dice_free(dice_local_nonprim);
        dice_local_nonprim = NULL;
    }
    if (game_local_nonprim) {
        game_free(game_local_nonprim);
        game_local_nonprim = NULL;
    }
    if (poll_local_nonprim) {
        poll_free(poll_local_nonprim);
        poll_local_nonprim = NULL;
    }
    if (venue_local_nonprim) {
        venue_free(venue_local_nonprim);
        venue_local_nonprim = NULL;
    }
    if (location_local_nonprim) {
        location_free(location_local_nonprim);
        location_local_nonprim = NULL;
    }
    if (new_chat_membersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, new_chat_membersList) {
            user_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(new_chat_membersList);
        new_chat_membersList = NULL;
    }
    if (left_chat_member_local_nonprim) {
        user_free(left_chat_member_local_nonprim);
        left_chat_member_local_nonprim = NULL;
    }
    if (new_chat_photoList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, new_chat_photoList) {
            photo_size_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(new_chat_photoList);
        new_chat_photoList = NULL;
    }
    if (message_auto_delete_timer_changed_local_nonprim) {
        message_auto_delete_timer_changed_free(message_auto_delete_timer_changed_local_nonprim);
        message_auto_delete_timer_changed_local_nonprim = NULL;
    }
    if (pinned_message_local_nonprim) {
        maybe_inaccessible_message_free(pinned_message_local_nonprim);
        pinned_message_local_nonprim = NULL;
    }
    if (invoice_local_nonprim) {
        invoice_free(invoice_local_nonprim);
        invoice_local_nonprim = NULL;
    }
    if (successful_payment_local_nonprim) {
        successful_payment_free(successful_payment_local_nonprim);
        successful_payment_local_nonprim = NULL;
    }
    if (refunded_payment_local_nonprim) {
        refunded_payment_free(refunded_payment_local_nonprim);
        refunded_payment_local_nonprim = NULL;
    }
    if (users_shared_local_nonprim) {
        users_shared_free(users_shared_local_nonprim);
        users_shared_local_nonprim = NULL;
    }
    if (chat_shared_local_nonprim) {
        chat_shared_free(chat_shared_local_nonprim);
        chat_shared_local_nonprim = NULL;
    }
    if (gift_local_nonprim) {
        gift_info_free(gift_local_nonprim);
        gift_local_nonprim = NULL;
    }
    if (unique_gift_local_nonprim) {
        unique_gift_info_free(unique_gift_local_nonprim);
        unique_gift_local_nonprim = NULL;
    }
    if (write_access_allowed_local_nonprim) {
        write_access_allowed_free(write_access_allowed_local_nonprim);
        write_access_allowed_local_nonprim = NULL;
    }
    if (passport_data_local_nonprim) {
        passport_data_free(passport_data_local_nonprim);
        passport_data_local_nonprim = NULL;
    }
    if (proximity_alert_triggered_local_nonprim) {
        proximity_alert_triggered_free(proximity_alert_triggered_local_nonprim);
        proximity_alert_triggered_local_nonprim = NULL;
    }
    if (boost_added_local_nonprim) {
        chat_boost_added_free(boost_added_local_nonprim);
        boost_added_local_nonprim = NULL;
    }
    if (chat_background_set_local_nonprim) {
        chat_background_free(chat_background_set_local_nonprim);
        chat_background_set_local_nonprim = NULL;
    }
    if (forum_topic_created_local_nonprim) {
        forum_topic_created_free(forum_topic_created_local_nonprim);
        forum_topic_created_local_nonprim = NULL;
    }
    if (forum_topic_edited_local_nonprim) {
        forum_topic_edited_free(forum_topic_edited_local_nonprim);
        forum_topic_edited_local_nonprim = NULL;
    }
    if (forum_topic_closed_local_nonprim) {
        _free(forum_topic_closed_local_nonprim);
        forum_topic_closed_local_nonprim = NULL;
    }
    if (forum_topic_reopened_local_nonprim) {
        _free(forum_topic_reopened_local_nonprim);
        forum_topic_reopened_local_nonprim = NULL;
    }
    if (general_forum_topic_hidden_local_nonprim) {
        _free(general_forum_topic_hidden_local_nonprim);
        general_forum_topic_hidden_local_nonprim = NULL;
    }
    if (general_forum_topic_unhidden_local_nonprim) {
        _free(general_forum_topic_unhidden_local_nonprim);
        general_forum_topic_unhidden_local_nonprim = NULL;
    }
    if (giveaway_created_local_nonprim) {
        giveaway_created_free(giveaway_created_local_nonprim);
        giveaway_created_local_nonprim = NULL;
    }
    if (giveaway_local_nonprim) {
        giveaway_free(giveaway_local_nonprim);
        giveaway_local_nonprim = NULL;
    }
    if (giveaway_winners_local_nonprim) {
        giveaway_winners_free(giveaway_winners_local_nonprim);
        giveaway_winners_local_nonprim = NULL;
    }
    if (giveaway_completed_local_nonprim) {
        giveaway_completed_free(giveaway_completed_local_nonprim);
        giveaway_completed_local_nonprim = NULL;
    }
    if (paid_message_price_changed_local_nonprim) {
        paid_message_price_changed_free(paid_message_price_changed_local_nonprim);
        paid_message_price_changed_local_nonprim = NULL;
    }
    if (video_chat_scheduled_local_nonprim) {
        video_chat_scheduled_free(video_chat_scheduled_local_nonprim);
        video_chat_scheduled_local_nonprim = NULL;
    }
    if (video_chat_started_local_nonprim) {
        _free(video_chat_started_local_nonprim);
        video_chat_started_local_nonprim = NULL;
    }
    if (video_chat_ended_local_nonprim) {
        video_chat_ended_free(video_chat_ended_local_nonprim);
        video_chat_ended_local_nonprim = NULL;
    }
    if (video_chat_participants_invited_local_nonprim) {
        video_chat_participants_invited_free(video_chat_participants_invited_local_nonprim);
        video_chat_participants_invited_local_nonprim = NULL;
    }
    if (web_app_data_local_nonprim) {
        web_app_data_free(web_app_data_local_nonprim);
        web_app_data_local_nonprim = NULL;
    }
    if (reply_markup_local_nonprim) {
        inline_keyboard_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    return NULL;

}
