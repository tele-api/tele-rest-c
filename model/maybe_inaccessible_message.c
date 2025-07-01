#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "maybe_inaccessible_message.h"



static maybe_inaccessible_message_t *maybe_inaccessible_message_create_internal(
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
    maybe_inaccessible_message_t *maybe_inaccessible_message_local_var = malloc(sizeof(maybe_inaccessible_message_t));
    if (!maybe_inaccessible_message_local_var) {
        return NULL;
    }
    maybe_inaccessible_message_local_var->message_id = message_id;
    maybe_inaccessible_message_local_var->date = date;
    maybe_inaccessible_message_local_var->chat = chat;
    maybe_inaccessible_message_local_var->message_thread_id = message_thread_id;
    maybe_inaccessible_message_local_var->from = from;
    maybe_inaccessible_message_local_var->sender_chat = sender_chat;
    maybe_inaccessible_message_local_var->sender_boost_count = sender_boost_count;
    maybe_inaccessible_message_local_var->sender_business_bot = sender_business_bot;
    maybe_inaccessible_message_local_var->business_connection_id = business_connection_id;
    maybe_inaccessible_message_local_var->forward_origin = forward_origin;
    maybe_inaccessible_message_local_var->is_topic_message = is_topic_message;
    maybe_inaccessible_message_local_var->is_automatic_forward = is_automatic_forward;
    maybe_inaccessible_message_local_var->reply_to_message = reply_to_message;
    maybe_inaccessible_message_local_var->external_reply = external_reply;
    maybe_inaccessible_message_local_var->quote = quote;
    maybe_inaccessible_message_local_var->reply_to_story = reply_to_story;
    maybe_inaccessible_message_local_var->via_bot = via_bot;
    maybe_inaccessible_message_local_var->edit_date = edit_date;
    maybe_inaccessible_message_local_var->has_protected_content = has_protected_content;
    maybe_inaccessible_message_local_var->is_from_offline = is_from_offline;
    maybe_inaccessible_message_local_var->media_group_id = media_group_id;
    maybe_inaccessible_message_local_var->author_signature = author_signature;
    maybe_inaccessible_message_local_var->paid_star_count = paid_star_count;
    maybe_inaccessible_message_local_var->text = text;
    maybe_inaccessible_message_local_var->entities = entities;
    maybe_inaccessible_message_local_var->link_preview_options = link_preview_options;
    maybe_inaccessible_message_local_var->effect_id = effect_id;
    maybe_inaccessible_message_local_var->animation = animation;
    maybe_inaccessible_message_local_var->audio = audio;
    maybe_inaccessible_message_local_var->document = document;
    maybe_inaccessible_message_local_var->paid_media = paid_media;
    maybe_inaccessible_message_local_var->photo = photo;
    maybe_inaccessible_message_local_var->sticker = sticker;
    maybe_inaccessible_message_local_var->story = story;
    maybe_inaccessible_message_local_var->video = video;
    maybe_inaccessible_message_local_var->video_note = video_note;
    maybe_inaccessible_message_local_var->voice = voice;
    maybe_inaccessible_message_local_var->caption = caption;
    maybe_inaccessible_message_local_var->caption_entities = caption_entities;
    maybe_inaccessible_message_local_var->show_caption_above_media = show_caption_above_media;
    maybe_inaccessible_message_local_var->has_media_spoiler = has_media_spoiler;
    maybe_inaccessible_message_local_var->contact = contact;
    maybe_inaccessible_message_local_var->dice = dice;
    maybe_inaccessible_message_local_var->game = game;
    maybe_inaccessible_message_local_var->poll = poll;
    maybe_inaccessible_message_local_var->venue = venue;
    maybe_inaccessible_message_local_var->location = location;
    maybe_inaccessible_message_local_var->new_chat_members = new_chat_members;
    maybe_inaccessible_message_local_var->left_chat_member = left_chat_member;
    maybe_inaccessible_message_local_var->new_chat_title = new_chat_title;
    maybe_inaccessible_message_local_var->new_chat_photo = new_chat_photo;
    maybe_inaccessible_message_local_var->delete_chat_photo = delete_chat_photo;
    maybe_inaccessible_message_local_var->group_chat_created = group_chat_created;
    maybe_inaccessible_message_local_var->supergroup_chat_created = supergroup_chat_created;
    maybe_inaccessible_message_local_var->channel_chat_created = channel_chat_created;
    maybe_inaccessible_message_local_var->message_auto_delete_timer_changed = message_auto_delete_timer_changed;
    maybe_inaccessible_message_local_var->migrate_to_chat_id = migrate_to_chat_id;
    maybe_inaccessible_message_local_var->migrate_from_chat_id = migrate_from_chat_id;
    maybe_inaccessible_message_local_var->pinned_message = pinned_message;
    maybe_inaccessible_message_local_var->invoice = invoice;
    maybe_inaccessible_message_local_var->successful_payment = successful_payment;
    maybe_inaccessible_message_local_var->refunded_payment = refunded_payment;
    maybe_inaccessible_message_local_var->users_shared = users_shared;
    maybe_inaccessible_message_local_var->chat_shared = chat_shared;
    maybe_inaccessible_message_local_var->gift = gift;
    maybe_inaccessible_message_local_var->unique_gift = unique_gift;
    maybe_inaccessible_message_local_var->connected_website = connected_website;
    maybe_inaccessible_message_local_var->write_access_allowed = write_access_allowed;
    maybe_inaccessible_message_local_var->passport_data = passport_data;
    maybe_inaccessible_message_local_var->proximity_alert_triggered = proximity_alert_triggered;
    maybe_inaccessible_message_local_var->boost_added = boost_added;
    maybe_inaccessible_message_local_var->chat_background_set = chat_background_set;
    maybe_inaccessible_message_local_var->forum_topic_created = forum_topic_created;
    maybe_inaccessible_message_local_var->forum_topic_edited = forum_topic_edited;
    maybe_inaccessible_message_local_var->forum_topic_closed = forum_topic_closed;
    maybe_inaccessible_message_local_var->forum_topic_reopened = forum_topic_reopened;
    maybe_inaccessible_message_local_var->general_forum_topic_hidden = general_forum_topic_hidden;
    maybe_inaccessible_message_local_var->general_forum_topic_unhidden = general_forum_topic_unhidden;
    maybe_inaccessible_message_local_var->giveaway_created = giveaway_created;
    maybe_inaccessible_message_local_var->giveaway = giveaway;
    maybe_inaccessible_message_local_var->giveaway_winners = giveaway_winners;
    maybe_inaccessible_message_local_var->giveaway_completed = giveaway_completed;
    maybe_inaccessible_message_local_var->paid_message_price_changed = paid_message_price_changed;
    maybe_inaccessible_message_local_var->video_chat_scheduled = video_chat_scheduled;
    maybe_inaccessible_message_local_var->video_chat_started = video_chat_started;
    maybe_inaccessible_message_local_var->video_chat_ended = video_chat_ended;
    maybe_inaccessible_message_local_var->video_chat_participants_invited = video_chat_participants_invited;
    maybe_inaccessible_message_local_var->web_app_data = web_app_data;
    maybe_inaccessible_message_local_var->reply_markup = reply_markup;

    maybe_inaccessible_message_local_var->_library_owned = 1;
    return maybe_inaccessible_message_local_var;
}

__attribute__((deprecated)) maybe_inaccessible_message_t *maybe_inaccessible_message_create(
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
    return maybe_inaccessible_message_create_internal (
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

void maybe_inaccessible_message_free(maybe_inaccessible_message_t *maybe_inaccessible_message) {
    if(NULL == maybe_inaccessible_message){
        return ;
    }
    if(maybe_inaccessible_message->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "maybe_inaccessible_message_free");
        return ;
    }
    listEntry_t *listEntry;
    if (maybe_inaccessible_message->chat) {
        chat_free(maybe_inaccessible_message->chat);
        maybe_inaccessible_message->chat = NULL;
    }
    if (maybe_inaccessible_message->from) {
        user_free(maybe_inaccessible_message->from);
        maybe_inaccessible_message->from = NULL;
    }
    if (maybe_inaccessible_message->sender_chat) {
        chat_free(maybe_inaccessible_message->sender_chat);
        maybe_inaccessible_message->sender_chat = NULL;
    }
    if (maybe_inaccessible_message->sender_business_bot) {
        user_free(maybe_inaccessible_message->sender_business_bot);
        maybe_inaccessible_message->sender_business_bot = NULL;
    }
    if (maybe_inaccessible_message->business_connection_id) {
        free(maybe_inaccessible_message->business_connection_id);
        maybe_inaccessible_message->business_connection_id = NULL;
    }
    if (maybe_inaccessible_message->forward_origin) {
        message_origin_free(maybe_inaccessible_message->forward_origin);
        maybe_inaccessible_message->forward_origin = NULL;
    }
    if (maybe_inaccessible_message->reply_to_message) {
        message_free(maybe_inaccessible_message->reply_to_message);
        maybe_inaccessible_message->reply_to_message = NULL;
    }
    if (maybe_inaccessible_message->external_reply) {
        external_reply_info_free(maybe_inaccessible_message->external_reply);
        maybe_inaccessible_message->external_reply = NULL;
    }
    if (maybe_inaccessible_message->quote) {
        text_quote_free(maybe_inaccessible_message->quote);
        maybe_inaccessible_message->quote = NULL;
    }
    if (maybe_inaccessible_message->reply_to_story) {
        story_free(maybe_inaccessible_message->reply_to_story);
        maybe_inaccessible_message->reply_to_story = NULL;
    }
    if (maybe_inaccessible_message->via_bot) {
        user_free(maybe_inaccessible_message->via_bot);
        maybe_inaccessible_message->via_bot = NULL;
    }
    if (maybe_inaccessible_message->media_group_id) {
        free(maybe_inaccessible_message->media_group_id);
        maybe_inaccessible_message->media_group_id = NULL;
    }
    if (maybe_inaccessible_message->author_signature) {
        free(maybe_inaccessible_message->author_signature);
        maybe_inaccessible_message->author_signature = NULL;
    }
    if (maybe_inaccessible_message->text) {
        free(maybe_inaccessible_message->text);
        maybe_inaccessible_message->text = NULL;
    }
    if (maybe_inaccessible_message->entities) {
        list_ForEach(listEntry, maybe_inaccessible_message->entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(maybe_inaccessible_message->entities);
        maybe_inaccessible_message->entities = NULL;
    }
    if (maybe_inaccessible_message->link_preview_options) {
        link_preview_options_free(maybe_inaccessible_message->link_preview_options);
        maybe_inaccessible_message->link_preview_options = NULL;
    }
    if (maybe_inaccessible_message->effect_id) {
        free(maybe_inaccessible_message->effect_id);
        maybe_inaccessible_message->effect_id = NULL;
    }
    if (maybe_inaccessible_message->animation) {
        animation_free(maybe_inaccessible_message->animation);
        maybe_inaccessible_message->animation = NULL;
    }
    if (maybe_inaccessible_message->audio) {
        audio_free(maybe_inaccessible_message->audio);
        maybe_inaccessible_message->audio = NULL;
    }
    if (maybe_inaccessible_message->document) {
        document_free(maybe_inaccessible_message->document);
        maybe_inaccessible_message->document = NULL;
    }
    if (maybe_inaccessible_message->paid_media) {
        paid_media_info_free(maybe_inaccessible_message->paid_media);
        maybe_inaccessible_message->paid_media = NULL;
    }
    if (maybe_inaccessible_message->photo) {
        list_ForEach(listEntry, maybe_inaccessible_message->photo) {
            photo_size_free(listEntry->data);
        }
        list_freeList(maybe_inaccessible_message->photo);
        maybe_inaccessible_message->photo = NULL;
    }
    if (maybe_inaccessible_message->sticker) {
        sticker_free(maybe_inaccessible_message->sticker);
        maybe_inaccessible_message->sticker = NULL;
    }
    if (maybe_inaccessible_message->story) {
        story_free(maybe_inaccessible_message->story);
        maybe_inaccessible_message->story = NULL;
    }
    if (maybe_inaccessible_message->video) {
        video_free(maybe_inaccessible_message->video);
        maybe_inaccessible_message->video = NULL;
    }
    if (maybe_inaccessible_message->video_note) {
        video_note_free(maybe_inaccessible_message->video_note);
        maybe_inaccessible_message->video_note = NULL;
    }
    if (maybe_inaccessible_message->voice) {
        voice_free(maybe_inaccessible_message->voice);
        maybe_inaccessible_message->voice = NULL;
    }
    if (maybe_inaccessible_message->caption) {
        free(maybe_inaccessible_message->caption);
        maybe_inaccessible_message->caption = NULL;
    }
    if (maybe_inaccessible_message->caption_entities) {
        list_ForEach(listEntry, maybe_inaccessible_message->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(maybe_inaccessible_message->caption_entities);
        maybe_inaccessible_message->caption_entities = NULL;
    }
    if (maybe_inaccessible_message->contact) {
        contact_free(maybe_inaccessible_message->contact);
        maybe_inaccessible_message->contact = NULL;
    }
    if (maybe_inaccessible_message->dice) {
        dice_free(maybe_inaccessible_message->dice);
        maybe_inaccessible_message->dice = NULL;
    }
    if (maybe_inaccessible_message->game) {
        game_free(maybe_inaccessible_message->game);
        maybe_inaccessible_message->game = NULL;
    }
    if (maybe_inaccessible_message->poll) {
        poll_free(maybe_inaccessible_message->poll);
        maybe_inaccessible_message->poll = NULL;
    }
    if (maybe_inaccessible_message->venue) {
        venue_free(maybe_inaccessible_message->venue);
        maybe_inaccessible_message->venue = NULL;
    }
    if (maybe_inaccessible_message->location) {
        location_free(maybe_inaccessible_message->location);
        maybe_inaccessible_message->location = NULL;
    }
    if (maybe_inaccessible_message->new_chat_members) {
        list_ForEach(listEntry, maybe_inaccessible_message->new_chat_members) {
            user_free(listEntry->data);
        }
        list_freeList(maybe_inaccessible_message->new_chat_members);
        maybe_inaccessible_message->new_chat_members = NULL;
    }
    if (maybe_inaccessible_message->left_chat_member) {
        user_free(maybe_inaccessible_message->left_chat_member);
        maybe_inaccessible_message->left_chat_member = NULL;
    }
    if (maybe_inaccessible_message->new_chat_title) {
        free(maybe_inaccessible_message->new_chat_title);
        maybe_inaccessible_message->new_chat_title = NULL;
    }
    if (maybe_inaccessible_message->new_chat_photo) {
        list_ForEach(listEntry, maybe_inaccessible_message->new_chat_photo) {
            photo_size_free(listEntry->data);
        }
        list_freeList(maybe_inaccessible_message->new_chat_photo);
        maybe_inaccessible_message->new_chat_photo = NULL;
    }
    if (maybe_inaccessible_message->message_auto_delete_timer_changed) {
        message_auto_delete_timer_changed_free(maybe_inaccessible_message->message_auto_delete_timer_changed);
        maybe_inaccessible_message->message_auto_delete_timer_changed = NULL;
    }
    if (maybe_inaccessible_message->pinned_message) {
        maybe_inaccessible_message_free(maybe_inaccessible_message->pinned_message);
        maybe_inaccessible_message->pinned_message = NULL;
    }
    if (maybe_inaccessible_message->invoice) {
        invoice_free(maybe_inaccessible_message->invoice);
        maybe_inaccessible_message->invoice = NULL;
    }
    if (maybe_inaccessible_message->successful_payment) {
        successful_payment_free(maybe_inaccessible_message->successful_payment);
        maybe_inaccessible_message->successful_payment = NULL;
    }
    if (maybe_inaccessible_message->refunded_payment) {
        refunded_payment_free(maybe_inaccessible_message->refunded_payment);
        maybe_inaccessible_message->refunded_payment = NULL;
    }
    if (maybe_inaccessible_message->users_shared) {
        users_shared_free(maybe_inaccessible_message->users_shared);
        maybe_inaccessible_message->users_shared = NULL;
    }
    if (maybe_inaccessible_message->chat_shared) {
        chat_shared_free(maybe_inaccessible_message->chat_shared);
        maybe_inaccessible_message->chat_shared = NULL;
    }
    if (maybe_inaccessible_message->gift) {
        gift_info_free(maybe_inaccessible_message->gift);
        maybe_inaccessible_message->gift = NULL;
    }
    if (maybe_inaccessible_message->unique_gift) {
        unique_gift_info_free(maybe_inaccessible_message->unique_gift);
        maybe_inaccessible_message->unique_gift = NULL;
    }
    if (maybe_inaccessible_message->connected_website) {
        free(maybe_inaccessible_message->connected_website);
        maybe_inaccessible_message->connected_website = NULL;
    }
    if (maybe_inaccessible_message->write_access_allowed) {
        write_access_allowed_free(maybe_inaccessible_message->write_access_allowed);
        maybe_inaccessible_message->write_access_allowed = NULL;
    }
    if (maybe_inaccessible_message->passport_data) {
        passport_data_free(maybe_inaccessible_message->passport_data);
        maybe_inaccessible_message->passport_data = NULL;
    }
    if (maybe_inaccessible_message->proximity_alert_triggered) {
        proximity_alert_triggered_free(maybe_inaccessible_message->proximity_alert_triggered);
        maybe_inaccessible_message->proximity_alert_triggered = NULL;
    }
    if (maybe_inaccessible_message->boost_added) {
        chat_boost_added_free(maybe_inaccessible_message->boost_added);
        maybe_inaccessible_message->boost_added = NULL;
    }
    if (maybe_inaccessible_message->chat_background_set) {
        chat_background_free(maybe_inaccessible_message->chat_background_set);
        maybe_inaccessible_message->chat_background_set = NULL;
    }
    if (maybe_inaccessible_message->forum_topic_created) {
        forum_topic_created_free(maybe_inaccessible_message->forum_topic_created);
        maybe_inaccessible_message->forum_topic_created = NULL;
    }
    if (maybe_inaccessible_message->forum_topic_edited) {
        forum_topic_edited_free(maybe_inaccessible_message->forum_topic_edited);
        maybe_inaccessible_message->forum_topic_edited = NULL;
    }
    if (maybe_inaccessible_message->forum_topic_closed) {
        _free(maybe_inaccessible_message->forum_topic_closed);
        maybe_inaccessible_message->forum_topic_closed = NULL;
    }
    if (maybe_inaccessible_message->forum_topic_reopened) {
        _free(maybe_inaccessible_message->forum_topic_reopened);
        maybe_inaccessible_message->forum_topic_reopened = NULL;
    }
    if (maybe_inaccessible_message->general_forum_topic_hidden) {
        _free(maybe_inaccessible_message->general_forum_topic_hidden);
        maybe_inaccessible_message->general_forum_topic_hidden = NULL;
    }
    if (maybe_inaccessible_message->general_forum_topic_unhidden) {
        _free(maybe_inaccessible_message->general_forum_topic_unhidden);
        maybe_inaccessible_message->general_forum_topic_unhidden = NULL;
    }
    if (maybe_inaccessible_message->giveaway_created) {
        giveaway_created_free(maybe_inaccessible_message->giveaway_created);
        maybe_inaccessible_message->giveaway_created = NULL;
    }
    if (maybe_inaccessible_message->giveaway) {
        giveaway_free(maybe_inaccessible_message->giveaway);
        maybe_inaccessible_message->giveaway = NULL;
    }
    if (maybe_inaccessible_message->giveaway_winners) {
        giveaway_winners_free(maybe_inaccessible_message->giveaway_winners);
        maybe_inaccessible_message->giveaway_winners = NULL;
    }
    if (maybe_inaccessible_message->giveaway_completed) {
        giveaway_completed_free(maybe_inaccessible_message->giveaway_completed);
        maybe_inaccessible_message->giveaway_completed = NULL;
    }
    if (maybe_inaccessible_message->paid_message_price_changed) {
        paid_message_price_changed_free(maybe_inaccessible_message->paid_message_price_changed);
        maybe_inaccessible_message->paid_message_price_changed = NULL;
    }
    if (maybe_inaccessible_message->video_chat_scheduled) {
        video_chat_scheduled_free(maybe_inaccessible_message->video_chat_scheduled);
        maybe_inaccessible_message->video_chat_scheduled = NULL;
    }
    if (maybe_inaccessible_message->video_chat_started) {
        _free(maybe_inaccessible_message->video_chat_started);
        maybe_inaccessible_message->video_chat_started = NULL;
    }
    if (maybe_inaccessible_message->video_chat_ended) {
        video_chat_ended_free(maybe_inaccessible_message->video_chat_ended);
        maybe_inaccessible_message->video_chat_ended = NULL;
    }
    if (maybe_inaccessible_message->video_chat_participants_invited) {
        video_chat_participants_invited_free(maybe_inaccessible_message->video_chat_participants_invited);
        maybe_inaccessible_message->video_chat_participants_invited = NULL;
    }
    if (maybe_inaccessible_message->web_app_data) {
        web_app_data_free(maybe_inaccessible_message->web_app_data);
        maybe_inaccessible_message->web_app_data = NULL;
    }
    if (maybe_inaccessible_message->reply_markup) {
        inline_keyboard_markup_free(maybe_inaccessible_message->reply_markup);
        maybe_inaccessible_message->reply_markup = NULL;
    }
    free(maybe_inaccessible_message);
}

cJSON *maybe_inaccessible_message_convertToJSON(maybe_inaccessible_message_t *maybe_inaccessible_message) {
    cJSON *item = cJSON_CreateObject();

    // maybe_inaccessible_message->message_id
    if (!maybe_inaccessible_message->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", maybe_inaccessible_message->message_id) == NULL) {
    goto fail; //Numeric
    }


    // maybe_inaccessible_message->date
    if (!maybe_inaccessible_message->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", maybe_inaccessible_message->date) == NULL) {
    goto fail; //Numeric
    }


    // maybe_inaccessible_message->chat
    if (!maybe_inaccessible_message->chat) {
        goto fail;
    }
    cJSON *chat_local_JSON = chat_convertToJSON(maybe_inaccessible_message->chat);
    if(chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat", chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // maybe_inaccessible_message->message_thread_id
    if(maybe_inaccessible_message->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", maybe_inaccessible_message->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // maybe_inaccessible_message->from
    if(maybe_inaccessible_message->from) {
    cJSON *from_local_JSON = user_convertToJSON(maybe_inaccessible_message->from);
    if(from_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "from", from_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->sender_chat
    if(maybe_inaccessible_message->sender_chat) {
    cJSON *sender_chat_local_JSON = chat_convertToJSON(maybe_inaccessible_message->sender_chat);
    if(sender_chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sender_chat", sender_chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->sender_boost_count
    if(maybe_inaccessible_message->sender_boost_count) {
    if(cJSON_AddNumberToObject(item, "sender_boost_count", maybe_inaccessible_message->sender_boost_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // maybe_inaccessible_message->sender_business_bot
    if(maybe_inaccessible_message->sender_business_bot) {
    cJSON *sender_business_bot_local_JSON = user_convertToJSON(maybe_inaccessible_message->sender_business_bot);
    if(sender_business_bot_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sender_business_bot", sender_business_bot_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->business_connection_id
    if(maybe_inaccessible_message->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", maybe_inaccessible_message->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // maybe_inaccessible_message->forward_origin
    if(maybe_inaccessible_message->forward_origin) {
    cJSON *forward_origin_local_JSON = message_origin_convertToJSON(maybe_inaccessible_message->forward_origin);
    if(forward_origin_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "forward_origin", forward_origin_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->is_topic_message
    if(maybe_inaccessible_message->is_topic_message) {
    if(cJSON_AddBoolToObject(item, "is_topic_message", maybe_inaccessible_message->is_topic_message) == NULL) {
    goto fail; //Bool
    }
    }


    // maybe_inaccessible_message->is_automatic_forward
    if(maybe_inaccessible_message->is_automatic_forward) {
    if(cJSON_AddBoolToObject(item, "is_automatic_forward", maybe_inaccessible_message->is_automatic_forward) == NULL) {
    goto fail; //Bool
    }
    }


    // maybe_inaccessible_message->reply_to_message
    if(maybe_inaccessible_message->reply_to_message) {
    cJSON *reply_to_message_local_JSON = message_convertToJSON(maybe_inaccessible_message->reply_to_message);
    if(reply_to_message_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_to_message", reply_to_message_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->external_reply
    if(maybe_inaccessible_message->external_reply) {
    cJSON *external_reply_local_JSON = external_reply_info_convertToJSON(maybe_inaccessible_message->external_reply);
    if(external_reply_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "external_reply", external_reply_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->quote
    if(maybe_inaccessible_message->quote) {
    cJSON *quote_local_JSON = text_quote_convertToJSON(maybe_inaccessible_message->quote);
    if(quote_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "quote", quote_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->reply_to_story
    if(maybe_inaccessible_message->reply_to_story) {
    cJSON *reply_to_story_local_JSON = story_convertToJSON(maybe_inaccessible_message->reply_to_story);
    if(reply_to_story_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_to_story", reply_to_story_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->via_bot
    if(maybe_inaccessible_message->via_bot) {
    cJSON *via_bot_local_JSON = user_convertToJSON(maybe_inaccessible_message->via_bot);
    if(via_bot_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "via_bot", via_bot_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->edit_date
    if(maybe_inaccessible_message->edit_date) {
    if(cJSON_AddNumberToObject(item, "edit_date", maybe_inaccessible_message->edit_date) == NULL) {
    goto fail; //Numeric
    }
    }


    // maybe_inaccessible_message->has_protected_content
    if(maybe_inaccessible_message->has_protected_content) {
    if(cJSON_AddBoolToObject(item, "has_protected_content", maybe_inaccessible_message->has_protected_content) == NULL) {
    goto fail; //Bool
    }
    }


    // maybe_inaccessible_message->is_from_offline
    if(maybe_inaccessible_message->is_from_offline) {
    if(cJSON_AddBoolToObject(item, "is_from_offline", maybe_inaccessible_message->is_from_offline) == NULL) {
    goto fail; //Bool
    }
    }


    // maybe_inaccessible_message->media_group_id
    if(maybe_inaccessible_message->media_group_id) {
    if(cJSON_AddStringToObject(item, "media_group_id", maybe_inaccessible_message->media_group_id) == NULL) {
    goto fail; //String
    }
    }


    // maybe_inaccessible_message->author_signature
    if(maybe_inaccessible_message->author_signature) {
    if(cJSON_AddStringToObject(item, "author_signature", maybe_inaccessible_message->author_signature) == NULL) {
    goto fail; //String
    }
    }


    // maybe_inaccessible_message->paid_star_count
    if(maybe_inaccessible_message->paid_star_count) {
    if(cJSON_AddNumberToObject(item, "paid_star_count", maybe_inaccessible_message->paid_star_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // maybe_inaccessible_message->text
    if(maybe_inaccessible_message->text) {
    if(cJSON_AddStringToObject(item, "text", maybe_inaccessible_message->text) == NULL) {
    goto fail; //String
    }
    }


    // maybe_inaccessible_message->entities
    if(maybe_inaccessible_message->entities) {
    cJSON *entities = cJSON_AddArrayToObject(item, "entities");
    if(entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *entitiesListEntry;
    if (maybe_inaccessible_message->entities) {
    list_ForEach(entitiesListEntry, maybe_inaccessible_message->entities) {
    cJSON *itemLocal = message_entity_convertToJSON(entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(entities, itemLocal);
    }
    }
    }


    // maybe_inaccessible_message->link_preview_options
    if(maybe_inaccessible_message->link_preview_options) {
    cJSON *link_preview_options_local_JSON = link_preview_options_convertToJSON(maybe_inaccessible_message->link_preview_options);
    if(link_preview_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "link_preview_options", link_preview_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->effect_id
    if(maybe_inaccessible_message->effect_id) {
    if(cJSON_AddStringToObject(item, "effect_id", maybe_inaccessible_message->effect_id) == NULL) {
    goto fail; //String
    }
    }


    // maybe_inaccessible_message->animation
    if(maybe_inaccessible_message->animation) {
    cJSON *animation_local_JSON = animation_convertToJSON(maybe_inaccessible_message->animation);
    if(animation_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "animation", animation_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->audio
    if(maybe_inaccessible_message->audio) {
    cJSON *audio_local_JSON = audio_convertToJSON(maybe_inaccessible_message->audio);
    if(audio_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "audio", audio_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->document
    if(maybe_inaccessible_message->document) {
    cJSON *document_local_JSON = document_convertToJSON(maybe_inaccessible_message->document);
    if(document_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "document", document_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->paid_media
    if(maybe_inaccessible_message->paid_media) {
    cJSON *paid_media_local_JSON = paid_media_info_convertToJSON(maybe_inaccessible_message->paid_media);
    if(paid_media_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "paid_media", paid_media_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->photo
    if(maybe_inaccessible_message->photo) {
    cJSON *photo = cJSON_AddArrayToObject(item, "photo");
    if(photo == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *photoListEntry;
    if (maybe_inaccessible_message->photo) {
    list_ForEach(photoListEntry, maybe_inaccessible_message->photo) {
    cJSON *itemLocal = photo_size_convertToJSON(photoListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(photo, itemLocal);
    }
    }
    }


    // maybe_inaccessible_message->sticker
    if(maybe_inaccessible_message->sticker) {
    cJSON *sticker_local_JSON = sticker_convertToJSON(maybe_inaccessible_message->sticker);
    if(sticker_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sticker", sticker_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->story
    if(maybe_inaccessible_message->story) {
    cJSON *story_local_JSON = story_convertToJSON(maybe_inaccessible_message->story);
    if(story_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "story", story_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->video
    if(maybe_inaccessible_message->video) {
    cJSON *video_local_JSON = video_convertToJSON(maybe_inaccessible_message->video);
    if(video_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "video", video_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->video_note
    if(maybe_inaccessible_message->video_note) {
    cJSON *video_note_local_JSON = video_note_convertToJSON(maybe_inaccessible_message->video_note);
    if(video_note_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "video_note", video_note_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->voice
    if(maybe_inaccessible_message->voice) {
    cJSON *voice_local_JSON = voice_convertToJSON(maybe_inaccessible_message->voice);
    if(voice_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "voice", voice_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->caption
    if(maybe_inaccessible_message->caption) {
    if(cJSON_AddStringToObject(item, "caption", maybe_inaccessible_message->caption) == NULL) {
    goto fail; //String
    }
    }


    // maybe_inaccessible_message->caption_entities
    if(maybe_inaccessible_message->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (maybe_inaccessible_message->caption_entities) {
    list_ForEach(caption_entitiesListEntry, maybe_inaccessible_message->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // maybe_inaccessible_message->show_caption_above_media
    if(maybe_inaccessible_message->show_caption_above_media) {
    if(cJSON_AddBoolToObject(item, "show_caption_above_media", maybe_inaccessible_message->show_caption_above_media) == NULL) {
    goto fail; //Bool
    }
    }


    // maybe_inaccessible_message->has_media_spoiler
    if(maybe_inaccessible_message->has_media_spoiler) {
    if(cJSON_AddBoolToObject(item, "has_media_spoiler", maybe_inaccessible_message->has_media_spoiler) == NULL) {
    goto fail; //Bool
    }
    }


    // maybe_inaccessible_message->contact
    if(maybe_inaccessible_message->contact) {
    cJSON *contact_local_JSON = contact_convertToJSON(maybe_inaccessible_message->contact);
    if(contact_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "contact", contact_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->dice
    if(maybe_inaccessible_message->dice) {
    cJSON *dice_local_JSON = dice_convertToJSON(maybe_inaccessible_message->dice);
    if(dice_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "dice", dice_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->game
    if(maybe_inaccessible_message->game) {
    cJSON *game_local_JSON = game_convertToJSON(maybe_inaccessible_message->game);
    if(game_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "game", game_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->poll
    if(maybe_inaccessible_message->poll) {
    cJSON *poll_local_JSON = poll_convertToJSON(maybe_inaccessible_message->poll);
    if(poll_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "poll", poll_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->venue
    if(maybe_inaccessible_message->venue) {
    cJSON *venue_local_JSON = venue_convertToJSON(maybe_inaccessible_message->venue);
    if(venue_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "venue", venue_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->location
    if(maybe_inaccessible_message->location) {
    cJSON *location_local_JSON = location_convertToJSON(maybe_inaccessible_message->location);
    if(location_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "location", location_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->new_chat_members
    if(maybe_inaccessible_message->new_chat_members) {
    cJSON *new_chat_members = cJSON_AddArrayToObject(item, "new_chat_members");
    if(new_chat_members == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *new_chat_membersListEntry;
    if (maybe_inaccessible_message->new_chat_members) {
    list_ForEach(new_chat_membersListEntry, maybe_inaccessible_message->new_chat_members) {
    cJSON *itemLocal = user_convertToJSON(new_chat_membersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(new_chat_members, itemLocal);
    }
    }
    }


    // maybe_inaccessible_message->left_chat_member
    if(maybe_inaccessible_message->left_chat_member) {
    cJSON *left_chat_member_local_JSON = user_convertToJSON(maybe_inaccessible_message->left_chat_member);
    if(left_chat_member_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "left_chat_member", left_chat_member_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->new_chat_title
    if(maybe_inaccessible_message->new_chat_title) {
    if(cJSON_AddStringToObject(item, "new_chat_title", maybe_inaccessible_message->new_chat_title) == NULL) {
    goto fail; //String
    }
    }


    // maybe_inaccessible_message->new_chat_photo
    if(maybe_inaccessible_message->new_chat_photo) {
    cJSON *new_chat_photo = cJSON_AddArrayToObject(item, "new_chat_photo");
    if(new_chat_photo == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *new_chat_photoListEntry;
    if (maybe_inaccessible_message->new_chat_photo) {
    list_ForEach(new_chat_photoListEntry, maybe_inaccessible_message->new_chat_photo) {
    cJSON *itemLocal = photo_size_convertToJSON(new_chat_photoListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(new_chat_photo, itemLocal);
    }
    }
    }


    // maybe_inaccessible_message->delete_chat_photo
    if(maybe_inaccessible_message->delete_chat_photo) {
    if(cJSON_AddBoolToObject(item, "delete_chat_photo", maybe_inaccessible_message->delete_chat_photo) == NULL) {
    goto fail; //Bool
    }
    }


    // maybe_inaccessible_message->group_chat_created
    if(maybe_inaccessible_message->group_chat_created) {
    if(cJSON_AddBoolToObject(item, "group_chat_created", maybe_inaccessible_message->group_chat_created) == NULL) {
    goto fail; //Bool
    }
    }


    // maybe_inaccessible_message->supergroup_chat_created
    if(maybe_inaccessible_message->supergroup_chat_created) {
    if(cJSON_AddBoolToObject(item, "supergroup_chat_created", maybe_inaccessible_message->supergroup_chat_created) == NULL) {
    goto fail; //Bool
    }
    }


    // maybe_inaccessible_message->channel_chat_created
    if(maybe_inaccessible_message->channel_chat_created) {
    if(cJSON_AddBoolToObject(item, "channel_chat_created", maybe_inaccessible_message->channel_chat_created) == NULL) {
    goto fail; //Bool
    }
    }


    // maybe_inaccessible_message->message_auto_delete_timer_changed
    if(maybe_inaccessible_message->message_auto_delete_timer_changed) {
    cJSON *message_auto_delete_timer_changed_local_JSON = message_auto_delete_timer_changed_convertToJSON(maybe_inaccessible_message->message_auto_delete_timer_changed);
    if(message_auto_delete_timer_changed_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "message_auto_delete_timer_changed", message_auto_delete_timer_changed_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->migrate_to_chat_id
    if(maybe_inaccessible_message->migrate_to_chat_id) {
    if(cJSON_AddNumberToObject(item, "migrate_to_chat_id", maybe_inaccessible_message->migrate_to_chat_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // maybe_inaccessible_message->migrate_from_chat_id
    if(maybe_inaccessible_message->migrate_from_chat_id) {
    if(cJSON_AddNumberToObject(item, "migrate_from_chat_id", maybe_inaccessible_message->migrate_from_chat_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // maybe_inaccessible_message->pinned_message
    if(maybe_inaccessible_message->pinned_message) {
    cJSON *pinned_message_local_JSON = maybe_inaccessible_message_convertToJSON(maybe_inaccessible_message->pinned_message);
    if(pinned_message_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "pinned_message", pinned_message_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->invoice
    if(maybe_inaccessible_message->invoice) {
    cJSON *invoice_local_JSON = invoice_convertToJSON(maybe_inaccessible_message->invoice);
    if(invoice_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "invoice", invoice_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->successful_payment
    if(maybe_inaccessible_message->successful_payment) {
    cJSON *successful_payment_local_JSON = successful_payment_convertToJSON(maybe_inaccessible_message->successful_payment);
    if(successful_payment_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "successful_payment", successful_payment_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->refunded_payment
    if(maybe_inaccessible_message->refunded_payment) {
    cJSON *refunded_payment_local_JSON = refunded_payment_convertToJSON(maybe_inaccessible_message->refunded_payment);
    if(refunded_payment_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "refunded_payment", refunded_payment_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->users_shared
    if(maybe_inaccessible_message->users_shared) {
    cJSON *users_shared_local_JSON = users_shared_convertToJSON(maybe_inaccessible_message->users_shared);
    if(users_shared_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "users_shared", users_shared_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->chat_shared
    if(maybe_inaccessible_message->chat_shared) {
    cJSON *chat_shared_local_JSON = chat_shared_convertToJSON(maybe_inaccessible_message->chat_shared);
    if(chat_shared_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_shared", chat_shared_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->gift
    if(maybe_inaccessible_message->gift) {
    cJSON *gift_local_JSON = gift_info_convertToJSON(maybe_inaccessible_message->gift);
    if(gift_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "gift", gift_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->unique_gift
    if(maybe_inaccessible_message->unique_gift) {
    cJSON *unique_gift_local_JSON = unique_gift_info_convertToJSON(maybe_inaccessible_message->unique_gift);
    if(unique_gift_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "unique_gift", unique_gift_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->connected_website
    if(maybe_inaccessible_message->connected_website) {
    if(cJSON_AddStringToObject(item, "connected_website", maybe_inaccessible_message->connected_website) == NULL) {
    goto fail; //String
    }
    }


    // maybe_inaccessible_message->write_access_allowed
    if(maybe_inaccessible_message->write_access_allowed) {
    cJSON *write_access_allowed_local_JSON = write_access_allowed_convertToJSON(maybe_inaccessible_message->write_access_allowed);
    if(write_access_allowed_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "write_access_allowed", write_access_allowed_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->passport_data
    if(maybe_inaccessible_message->passport_data) {
    cJSON *passport_data_local_JSON = passport_data_convertToJSON(maybe_inaccessible_message->passport_data);
    if(passport_data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "passport_data", passport_data_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->proximity_alert_triggered
    if(maybe_inaccessible_message->proximity_alert_triggered) {
    cJSON *proximity_alert_triggered_local_JSON = proximity_alert_triggered_convertToJSON(maybe_inaccessible_message->proximity_alert_triggered);
    if(proximity_alert_triggered_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "proximity_alert_triggered", proximity_alert_triggered_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->boost_added
    if(maybe_inaccessible_message->boost_added) {
    cJSON *boost_added_local_JSON = chat_boost_added_convertToJSON(maybe_inaccessible_message->boost_added);
    if(boost_added_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "boost_added", boost_added_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->chat_background_set
    if(maybe_inaccessible_message->chat_background_set) {
    cJSON *chat_background_set_local_JSON = chat_background_convertToJSON(maybe_inaccessible_message->chat_background_set);
    if(chat_background_set_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_background_set", chat_background_set_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->forum_topic_created
    if(maybe_inaccessible_message->forum_topic_created) {
    cJSON *forum_topic_created_local_JSON = forum_topic_created_convertToJSON(maybe_inaccessible_message->forum_topic_created);
    if(forum_topic_created_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "forum_topic_created", forum_topic_created_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->forum_topic_edited
    if(maybe_inaccessible_message->forum_topic_edited) {
    cJSON *forum_topic_edited_local_JSON = forum_topic_edited_convertToJSON(maybe_inaccessible_message->forum_topic_edited);
    if(forum_topic_edited_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "forum_topic_edited", forum_topic_edited_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->forum_topic_closed
    if(maybe_inaccessible_message->forum_topic_closed) {
    cJSON *forum_topic_closed_local_JSON = _convertToJSON(maybe_inaccessible_message->forum_topic_closed);
    if(forum_topic_closed_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "forum_topic_closed", forum_topic_closed_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // maybe_inaccessible_message->forum_topic_reopened
    if(maybe_inaccessible_message->forum_topic_reopened) {
    cJSON *forum_topic_reopened_local_JSON = _convertToJSON(maybe_inaccessible_message->forum_topic_reopened);
    if(forum_topic_reopened_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "forum_topic_reopened", forum_topic_reopened_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // maybe_inaccessible_message->general_forum_topic_hidden
    if(maybe_inaccessible_message->general_forum_topic_hidden) {
    cJSON *general_forum_topic_hidden_local_JSON = _convertToJSON(maybe_inaccessible_message->general_forum_topic_hidden);
    if(general_forum_topic_hidden_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "general_forum_topic_hidden", general_forum_topic_hidden_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // maybe_inaccessible_message->general_forum_topic_unhidden
    if(maybe_inaccessible_message->general_forum_topic_unhidden) {
    cJSON *general_forum_topic_unhidden_local_JSON = _convertToJSON(maybe_inaccessible_message->general_forum_topic_unhidden);
    if(general_forum_topic_unhidden_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "general_forum_topic_unhidden", general_forum_topic_unhidden_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // maybe_inaccessible_message->giveaway_created
    if(maybe_inaccessible_message->giveaway_created) {
    cJSON *giveaway_created_local_JSON = giveaway_created_convertToJSON(maybe_inaccessible_message->giveaway_created);
    if(giveaway_created_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "giveaway_created", giveaway_created_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->giveaway
    if(maybe_inaccessible_message->giveaway) {
    cJSON *giveaway_local_JSON = giveaway_convertToJSON(maybe_inaccessible_message->giveaway);
    if(giveaway_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "giveaway", giveaway_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->giveaway_winners
    if(maybe_inaccessible_message->giveaway_winners) {
    cJSON *giveaway_winners_local_JSON = giveaway_winners_convertToJSON(maybe_inaccessible_message->giveaway_winners);
    if(giveaway_winners_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "giveaway_winners", giveaway_winners_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->giveaway_completed
    if(maybe_inaccessible_message->giveaway_completed) {
    cJSON *giveaway_completed_local_JSON = giveaway_completed_convertToJSON(maybe_inaccessible_message->giveaway_completed);
    if(giveaway_completed_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "giveaway_completed", giveaway_completed_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->paid_message_price_changed
    if(maybe_inaccessible_message->paid_message_price_changed) {
    cJSON *paid_message_price_changed_local_JSON = paid_message_price_changed_convertToJSON(maybe_inaccessible_message->paid_message_price_changed);
    if(paid_message_price_changed_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "paid_message_price_changed", paid_message_price_changed_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->video_chat_scheduled
    if(maybe_inaccessible_message->video_chat_scheduled) {
    cJSON *video_chat_scheduled_local_JSON = video_chat_scheduled_convertToJSON(maybe_inaccessible_message->video_chat_scheduled);
    if(video_chat_scheduled_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "video_chat_scheduled", video_chat_scheduled_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->video_chat_started
    if(maybe_inaccessible_message->video_chat_started) {
    cJSON *video_chat_started_local_JSON = _convertToJSON(maybe_inaccessible_message->video_chat_started);
    if(video_chat_started_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "video_chat_started", video_chat_started_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // maybe_inaccessible_message->video_chat_ended
    if(maybe_inaccessible_message->video_chat_ended) {
    cJSON *video_chat_ended_local_JSON = video_chat_ended_convertToJSON(maybe_inaccessible_message->video_chat_ended);
    if(video_chat_ended_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "video_chat_ended", video_chat_ended_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->video_chat_participants_invited
    if(maybe_inaccessible_message->video_chat_participants_invited) {
    cJSON *video_chat_participants_invited_local_JSON = video_chat_participants_invited_convertToJSON(maybe_inaccessible_message->video_chat_participants_invited);
    if(video_chat_participants_invited_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "video_chat_participants_invited", video_chat_participants_invited_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->web_app_data
    if(maybe_inaccessible_message->web_app_data) {
    cJSON *web_app_data_local_JSON = web_app_data_convertToJSON(maybe_inaccessible_message->web_app_data);
    if(web_app_data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "web_app_data", web_app_data_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // maybe_inaccessible_message->reply_markup
    if(maybe_inaccessible_message->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(maybe_inaccessible_message->reply_markup);
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

maybe_inaccessible_message_t *maybe_inaccessible_message_parseFromJSON(cJSON *maybe_inaccessible_messageJSON){

    maybe_inaccessible_message_t *maybe_inaccessible_message_local_var = NULL;

    // define the local variable for maybe_inaccessible_message->chat
    chat_t *chat_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->from
    user_t *from_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->sender_chat
    chat_t *sender_chat_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->sender_business_bot
    user_t *sender_business_bot_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->forward_origin
    message_origin_t *forward_origin_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->reply_to_message
    message_t *reply_to_message_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->external_reply
    external_reply_info_t *external_reply_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->quote
    text_quote_t *quote_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->reply_to_story
    story_t *reply_to_story_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->via_bot
    user_t *via_bot_local_nonprim = NULL;

    // define the local list for maybe_inaccessible_message->entities
    list_t *entitiesList = NULL;

    // define the local variable for maybe_inaccessible_message->link_preview_options
    link_preview_options_t *link_preview_options_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->animation
    animation_t *animation_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->audio
    audio_t *audio_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->document
    document_t *document_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->paid_media
    paid_media_info_t *paid_media_local_nonprim = NULL;

    // define the local list for maybe_inaccessible_message->photo
    list_t *photoList = NULL;

    // define the local variable for maybe_inaccessible_message->sticker
    sticker_t *sticker_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->story
    story_t *story_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->video
    video_t *video_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->video_note
    video_note_t *video_note_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->voice
    voice_t *voice_local_nonprim = NULL;

    // define the local list for maybe_inaccessible_message->caption_entities
    list_t *caption_entitiesList = NULL;

    // define the local variable for maybe_inaccessible_message->contact
    contact_t *contact_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->dice
    dice_t *dice_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->game
    game_t *game_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->poll
    poll_t *poll_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->venue
    venue_t *venue_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->location
    location_t *location_local_nonprim = NULL;

    // define the local list for maybe_inaccessible_message->new_chat_members
    list_t *new_chat_membersList = NULL;

    // define the local variable for maybe_inaccessible_message->left_chat_member
    user_t *left_chat_member_local_nonprim = NULL;

    // define the local list for maybe_inaccessible_message->new_chat_photo
    list_t *new_chat_photoList = NULL;

    // define the local variable for maybe_inaccessible_message->message_auto_delete_timer_changed
    message_auto_delete_timer_changed_t *message_auto_delete_timer_changed_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->pinned_message
    maybe_inaccessible_message_t *pinned_message_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->invoice
    invoice_t *invoice_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->successful_payment
    successful_payment_t *successful_payment_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->refunded_payment
    refunded_payment_t *refunded_payment_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->users_shared
    users_shared_t *users_shared_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->chat_shared
    chat_shared_t *chat_shared_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->gift
    gift_info_t *gift_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->unique_gift
    unique_gift_info_t *unique_gift_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->write_access_allowed
    write_access_allowed_t *write_access_allowed_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->passport_data
    passport_data_t *passport_data_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->proximity_alert_triggered
    proximity_alert_triggered_t *proximity_alert_triggered_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->boost_added
    chat_boost_added_t *boost_added_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->chat_background_set
    chat_background_t *chat_background_set_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->forum_topic_created
    forum_topic_created_t *forum_topic_created_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->forum_topic_edited
    forum_topic_edited_t *forum_topic_edited_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->forum_topic_closed
    _t *forum_topic_closed_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->forum_topic_reopened
    _t *forum_topic_reopened_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->general_forum_topic_hidden
    _t *general_forum_topic_hidden_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->general_forum_topic_unhidden
    _t *general_forum_topic_unhidden_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->giveaway_created
    giveaway_created_t *giveaway_created_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->giveaway
    giveaway_t *giveaway_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->giveaway_winners
    giveaway_winners_t *giveaway_winners_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->giveaway_completed
    giveaway_completed_t *giveaway_completed_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->paid_message_price_changed
    paid_message_price_changed_t *paid_message_price_changed_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->video_chat_scheduled
    video_chat_scheduled_t *video_chat_scheduled_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->video_chat_started
    _t *video_chat_started_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->video_chat_ended
    video_chat_ended_t *video_chat_ended_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->video_chat_participants_invited
    video_chat_participants_invited_t *video_chat_participants_invited_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->web_app_data
    web_app_data_t *web_app_data_local_nonprim = NULL;

    // define the local variable for maybe_inaccessible_message->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // maybe_inaccessible_message->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "message_id");
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

    // maybe_inaccessible_message->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "date");
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

    // maybe_inaccessible_message->chat
    cJSON *chat = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "chat");
    if (cJSON_IsNull(chat)) {
        chat = NULL;
    }
    if (!chat) {
        goto end;
    }

    
    chat_local_nonprim = chat_parseFromJSON(chat); //nonprimitive

    // maybe_inaccessible_message->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // maybe_inaccessible_message->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "from");
    if (cJSON_IsNull(from)) {
        from = NULL;
    }
    if (from) { 
    from_local_nonprim = user_parseFromJSON(from); //nonprimitive
    }

    // maybe_inaccessible_message->sender_chat
    cJSON *sender_chat = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "sender_chat");
    if (cJSON_IsNull(sender_chat)) {
        sender_chat = NULL;
    }
    if (sender_chat) { 
    sender_chat_local_nonprim = chat_parseFromJSON(sender_chat); //nonprimitive
    }

    // maybe_inaccessible_message->sender_boost_count
    cJSON *sender_boost_count = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "sender_boost_count");
    if (cJSON_IsNull(sender_boost_count)) {
        sender_boost_count = NULL;
    }
    if (sender_boost_count) { 
    if(!cJSON_IsNumber(sender_boost_count))
    {
    goto end; //Numeric
    }
    }

    // maybe_inaccessible_message->sender_business_bot
    cJSON *sender_business_bot = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "sender_business_bot");
    if (cJSON_IsNull(sender_business_bot)) {
        sender_business_bot = NULL;
    }
    if (sender_business_bot) { 
    sender_business_bot_local_nonprim = user_parseFromJSON(sender_business_bot); //nonprimitive
    }

    // maybe_inaccessible_message->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // maybe_inaccessible_message->forward_origin
    cJSON *forward_origin = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "forward_origin");
    if (cJSON_IsNull(forward_origin)) {
        forward_origin = NULL;
    }
    if (forward_origin) { 
    forward_origin_local_nonprim = message_origin_parseFromJSON(forward_origin); //nonprimitive
    }

    // maybe_inaccessible_message->is_topic_message
    cJSON *is_topic_message = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "is_topic_message");
    if (cJSON_IsNull(is_topic_message)) {
        is_topic_message = NULL;
    }
    if (is_topic_message) { 
    if(!cJSON_IsBool(is_topic_message))
    {
    goto end; //Bool
    }
    }

    // maybe_inaccessible_message->is_automatic_forward
    cJSON *is_automatic_forward = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "is_automatic_forward");
    if (cJSON_IsNull(is_automatic_forward)) {
        is_automatic_forward = NULL;
    }
    if (is_automatic_forward) { 
    if(!cJSON_IsBool(is_automatic_forward))
    {
    goto end; //Bool
    }
    }

    // maybe_inaccessible_message->reply_to_message
    cJSON *reply_to_message = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "reply_to_message");
    if (cJSON_IsNull(reply_to_message)) {
        reply_to_message = NULL;
    }
    if (reply_to_message) { 
    reply_to_message_local_nonprim = message_parseFromJSON(reply_to_message); //nonprimitive
    }

    // maybe_inaccessible_message->external_reply
    cJSON *external_reply = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "external_reply");
    if (cJSON_IsNull(external_reply)) {
        external_reply = NULL;
    }
    if (external_reply) { 
    external_reply_local_nonprim = external_reply_info_parseFromJSON(external_reply); //nonprimitive
    }

    // maybe_inaccessible_message->quote
    cJSON *quote = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "quote");
    if (cJSON_IsNull(quote)) {
        quote = NULL;
    }
    if (quote) { 
    quote_local_nonprim = text_quote_parseFromJSON(quote); //nonprimitive
    }

    // maybe_inaccessible_message->reply_to_story
    cJSON *reply_to_story = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "reply_to_story");
    if (cJSON_IsNull(reply_to_story)) {
        reply_to_story = NULL;
    }
    if (reply_to_story) { 
    reply_to_story_local_nonprim = story_parseFromJSON(reply_to_story); //nonprimitive
    }

    // maybe_inaccessible_message->via_bot
    cJSON *via_bot = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "via_bot");
    if (cJSON_IsNull(via_bot)) {
        via_bot = NULL;
    }
    if (via_bot) { 
    via_bot_local_nonprim = user_parseFromJSON(via_bot); //nonprimitive
    }

    // maybe_inaccessible_message->edit_date
    cJSON *edit_date = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "edit_date");
    if (cJSON_IsNull(edit_date)) {
        edit_date = NULL;
    }
    if (edit_date) { 
    if(!cJSON_IsNumber(edit_date))
    {
    goto end; //Numeric
    }
    }

    // maybe_inaccessible_message->has_protected_content
    cJSON *has_protected_content = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "has_protected_content");
    if (cJSON_IsNull(has_protected_content)) {
        has_protected_content = NULL;
    }
    if (has_protected_content) { 
    if(!cJSON_IsBool(has_protected_content))
    {
    goto end; //Bool
    }
    }

    // maybe_inaccessible_message->is_from_offline
    cJSON *is_from_offline = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "is_from_offline");
    if (cJSON_IsNull(is_from_offline)) {
        is_from_offline = NULL;
    }
    if (is_from_offline) { 
    if(!cJSON_IsBool(is_from_offline))
    {
    goto end; //Bool
    }
    }

    // maybe_inaccessible_message->media_group_id
    cJSON *media_group_id = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "media_group_id");
    if (cJSON_IsNull(media_group_id)) {
        media_group_id = NULL;
    }
    if (media_group_id) { 
    if(!cJSON_IsString(media_group_id) && !cJSON_IsNull(media_group_id))
    {
    goto end; //String
    }
    }

    // maybe_inaccessible_message->author_signature
    cJSON *author_signature = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "author_signature");
    if (cJSON_IsNull(author_signature)) {
        author_signature = NULL;
    }
    if (author_signature) { 
    if(!cJSON_IsString(author_signature) && !cJSON_IsNull(author_signature))
    {
    goto end; //String
    }
    }

    // maybe_inaccessible_message->paid_star_count
    cJSON *paid_star_count = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "paid_star_count");
    if (cJSON_IsNull(paid_star_count)) {
        paid_star_count = NULL;
    }
    if (paid_star_count) { 
    if(!cJSON_IsNumber(paid_star_count))
    {
    goto end; //Numeric
    }
    }

    // maybe_inaccessible_message->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (text) { 
    if(!cJSON_IsString(text) && !cJSON_IsNull(text))
    {
    goto end; //String
    }
    }

    // maybe_inaccessible_message->entities
    cJSON *entities = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "entities");
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

    // maybe_inaccessible_message->link_preview_options
    cJSON *link_preview_options = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "link_preview_options");
    if (cJSON_IsNull(link_preview_options)) {
        link_preview_options = NULL;
    }
    if (link_preview_options) { 
    link_preview_options_local_nonprim = link_preview_options_parseFromJSON(link_preview_options); //nonprimitive
    }

    // maybe_inaccessible_message->effect_id
    cJSON *effect_id = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "effect_id");
    if (cJSON_IsNull(effect_id)) {
        effect_id = NULL;
    }
    if (effect_id) { 
    if(!cJSON_IsString(effect_id) && !cJSON_IsNull(effect_id))
    {
    goto end; //String
    }
    }

    // maybe_inaccessible_message->animation
    cJSON *animation = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "animation");
    if (cJSON_IsNull(animation)) {
        animation = NULL;
    }
    if (animation) { 
    animation_local_nonprim = animation_parseFromJSON(animation); //nonprimitive
    }

    // maybe_inaccessible_message->audio
    cJSON *audio = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "audio");
    if (cJSON_IsNull(audio)) {
        audio = NULL;
    }
    if (audio) { 
    audio_local_nonprim = audio_parseFromJSON(audio); //nonprimitive
    }

    // maybe_inaccessible_message->document
    cJSON *document = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "document");
    if (cJSON_IsNull(document)) {
        document = NULL;
    }
    if (document) { 
    document_local_nonprim = document_parseFromJSON(document); //nonprimitive
    }

    // maybe_inaccessible_message->paid_media
    cJSON *paid_media = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "paid_media");
    if (cJSON_IsNull(paid_media)) {
        paid_media = NULL;
    }
    if (paid_media) { 
    paid_media_local_nonprim = paid_media_info_parseFromJSON(paid_media); //nonprimitive
    }

    // maybe_inaccessible_message->photo
    cJSON *photo = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "photo");
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

    // maybe_inaccessible_message->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "sticker");
    if (cJSON_IsNull(sticker)) {
        sticker = NULL;
    }
    if (sticker) { 
    sticker_local_nonprim = sticker_parseFromJSON(sticker); //nonprimitive
    }

    // maybe_inaccessible_message->story
    cJSON *story = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "story");
    if (cJSON_IsNull(story)) {
        story = NULL;
    }
    if (story) { 
    story_local_nonprim = story_parseFromJSON(story); //nonprimitive
    }

    // maybe_inaccessible_message->video
    cJSON *video = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "video");
    if (cJSON_IsNull(video)) {
        video = NULL;
    }
    if (video) { 
    video_local_nonprim = video_parseFromJSON(video); //nonprimitive
    }

    // maybe_inaccessible_message->video_note
    cJSON *video_note = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "video_note");
    if (cJSON_IsNull(video_note)) {
        video_note = NULL;
    }
    if (video_note) { 
    video_note_local_nonprim = video_note_parseFromJSON(video_note); //nonprimitive
    }

    // maybe_inaccessible_message->voice
    cJSON *voice = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "voice");
    if (cJSON_IsNull(voice)) {
        voice = NULL;
    }
    if (voice) { 
    voice_local_nonprim = voice_parseFromJSON(voice); //nonprimitive
    }

    // maybe_inaccessible_message->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // maybe_inaccessible_message->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "caption_entities");
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

    // maybe_inaccessible_message->show_caption_above_media
    cJSON *show_caption_above_media = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "show_caption_above_media");
    if (cJSON_IsNull(show_caption_above_media)) {
        show_caption_above_media = NULL;
    }
    if (show_caption_above_media) { 
    if(!cJSON_IsBool(show_caption_above_media))
    {
    goto end; //Bool
    }
    }

    // maybe_inaccessible_message->has_media_spoiler
    cJSON *has_media_spoiler = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "has_media_spoiler");
    if (cJSON_IsNull(has_media_spoiler)) {
        has_media_spoiler = NULL;
    }
    if (has_media_spoiler) { 
    if(!cJSON_IsBool(has_media_spoiler))
    {
    goto end; //Bool
    }
    }

    // maybe_inaccessible_message->contact
    cJSON *contact = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "contact");
    if (cJSON_IsNull(contact)) {
        contact = NULL;
    }
    if (contact) { 
    contact_local_nonprim = contact_parseFromJSON(contact); //nonprimitive
    }

    // maybe_inaccessible_message->dice
    cJSON *dice = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "dice");
    if (cJSON_IsNull(dice)) {
        dice = NULL;
    }
    if (dice) { 
    dice_local_nonprim = dice_parseFromJSON(dice); //nonprimitive
    }

    // maybe_inaccessible_message->game
    cJSON *game = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "game");
    if (cJSON_IsNull(game)) {
        game = NULL;
    }
    if (game) { 
    game_local_nonprim = game_parseFromJSON(game); //nonprimitive
    }

    // maybe_inaccessible_message->poll
    cJSON *poll = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "poll");
    if (cJSON_IsNull(poll)) {
        poll = NULL;
    }
    if (poll) { 
    poll_local_nonprim = poll_parseFromJSON(poll); //nonprimitive
    }

    // maybe_inaccessible_message->venue
    cJSON *venue = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "venue");
    if (cJSON_IsNull(venue)) {
        venue = NULL;
    }
    if (venue) { 
    venue_local_nonprim = venue_parseFromJSON(venue); //nonprimitive
    }

    // maybe_inaccessible_message->location
    cJSON *location = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "location");
    if (cJSON_IsNull(location)) {
        location = NULL;
    }
    if (location) { 
    location_local_nonprim = location_parseFromJSON(location); //nonprimitive
    }

    // maybe_inaccessible_message->new_chat_members
    cJSON *new_chat_members = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "new_chat_members");
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

    // maybe_inaccessible_message->left_chat_member
    cJSON *left_chat_member = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "left_chat_member");
    if (cJSON_IsNull(left_chat_member)) {
        left_chat_member = NULL;
    }
    if (left_chat_member) { 
    left_chat_member_local_nonprim = user_parseFromJSON(left_chat_member); //nonprimitive
    }

    // maybe_inaccessible_message->new_chat_title
    cJSON *new_chat_title = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "new_chat_title");
    if (cJSON_IsNull(new_chat_title)) {
        new_chat_title = NULL;
    }
    if (new_chat_title) { 
    if(!cJSON_IsString(new_chat_title) && !cJSON_IsNull(new_chat_title))
    {
    goto end; //String
    }
    }

    // maybe_inaccessible_message->new_chat_photo
    cJSON *new_chat_photo = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "new_chat_photo");
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

    // maybe_inaccessible_message->delete_chat_photo
    cJSON *delete_chat_photo = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "delete_chat_photo");
    if (cJSON_IsNull(delete_chat_photo)) {
        delete_chat_photo = NULL;
    }
    if (delete_chat_photo) { 
    if(!cJSON_IsBool(delete_chat_photo))
    {
    goto end; //Bool
    }
    }

    // maybe_inaccessible_message->group_chat_created
    cJSON *group_chat_created = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "group_chat_created");
    if (cJSON_IsNull(group_chat_created)) {
        group_chat_created = NULL;
    }
    if (group_chat_created) { 
    if(!cJSON_IsBool(group_chat_created))
    {
    goto end; //Bool
    }
    }

    // maybe_inaccessible_message->supergroup_chat_created
    cJSON *supergroup_chat_created = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "supergroup_chat_created");
    if (cJSON_IsNull(supergroup_chat_created)) {
        supergroup_chat_created = NULL;
    }
    if (supergroup_chat_created) { 
    if(!cJSON_IsBool(supergroup_chat_created))
    {
    goto end; //Bool
    }
    }

    // maybe_inaccessible_message->channel_chat_created
    cJSON *channel_chat_created = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "channel_chat_created");
    if (cJSON_IsNull(channel_chat_created)) {
        channel_chat_created = NULL;
    }
    if (channel_chat_created) { 
    if(!cJSON_IsBool(channel_chat_created))
    {
    goto end; //Bool
    }
    }

    // maybe_inaccessible_message->message_auto_delete_timer_changed
    cJSON *message_auto_delete_timer_changed = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "message_auto_delete_timer_changed");
    if (cJSON_IsNull(message_auto_delete_timer_changed)) {
        message_auto_delete_timer_changed = NULL;
    }
    if (message_auto_delete_timer_changed) { 
    message_auto_delete_timer_changed_local_nonprim = message_auto_delete_timer_changed_parseFromJSON(message_auto_delete_timer_changed); //nonprimitive
    }

    // maybe_inaccessible_message->migrate_to_chat_id
    cJSON *migrate_to_chat_id = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "migrate_to_chat_id");
    if (cJSON_IsNull(migrate_to_chat_id)) {
        migrate_to_chat_id = NULL;
    }
    if (migrate_to_chat_id) { 
    if(!cJSON_IsNumber(migrate_to_chat_id))
    {
    goto end; //Numeric
    }
    }

    // maybe_inaccessible_message->migrate_from_chat_id
    cJSON *migrate_from_chat_id = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "migrate_from_chat_id");
    if (cJSON_IsNull(migrate_from_chat_id)) {
        migrate_from_chat_id = NULL;
    }
    if (migrate_from_chat_id) { 
    if(!cJSON_IsNumber(migrate_from_chat_id))
    {
    goto end; //Numeric
    }
    }

    // maybe_inaccessible_message->pinned_message
    cJSON *pinned_message = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "pinned_message");
    if (cJSON_IsNull(pinned_message)) {
        pinned_message = NULL;
    }
    if (pinned_message) { 
    pinned_message_local_nonprim = maybe_inaccessible_message_parseFromJSON(pinned_message); //nonprimitive
    }

    // maybe_inaccessible_message->invoice
    cJSON *invoice = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "invoice");
    if (cJSON_IsNull(invoice)) {
        invoice = NULL;
    }
    if (invoice) { 
    invoice_local_nonprim = invoice_parseFromJSON(invoice); //nonprimitive
    }

    // maybe_inaccessible_message->successful_payment
    cJSON *successful_payment = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "successful_payment");
    if (cJSON_IsNull(successful_payment)) {
        successful_payment = NULL;
    }
    if (successful_payment) { 
    successful_payment_local_nonprim = successful_payment_parseFromJSON(successful_payment); //nonprimitive
    }

    // maybe_inaccessible_message->refunded_payment
    cJSON *refunded_payment = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "refunded_payment");
    if (cJSON_IsNull(refunded_payment)) {
        refunded_payment = NULL;
    }
    if (refunded_payment) { 
    refunded_payment_local_nonprim = refunded_payment_parseFromJSON(refunded_payment); //nonprimitive
    }

    // maybe_inaccessible_message->users_shared
    cJSON *users_shared = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "users_shared");
    if (cJSON_IsNull(users_shared)) {
        users_shared = NULL;
    }
    if (users_shared) { 
    users_shared_local_nonprim = users_shared_parseFromJSON(users_shared); //nonprimitive
    }

    // maybe_inaccessible_message->chat_shared
    cJSON *chat_shared = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "chat_shared");
    if (cJSON_IsNull(chat_shared)) {
        chat_shared = NULL;
    }
    if (chat_shared) { 
    chat_shared_local_nonprim = chat_shared_parseFromJSON(chat_shared); //nonprimitive
    }

    // maybe_inaccessible_message->gift
    cJSON *gift = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "gift");
    if (cJSON_IsNull(gift)) {
        gift = NULL;
    }
    if (gift) { 
    gift_local_nonprim = gift_info_parseFromJSON(gift); //nonprimitive
    }

    // maybe_inaccessible_message->unique_gift
    cJSON *unique_gift = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "unique_gift");
    if (cJSON_IsNull(unique_gift)) {
        unique_gift = NULL;
    }
    if (unique_gift) { 
    unique_gift_local_nonprim = unique_gift_info_parseFromJSON(unique_gift); //nonprimitive
    }

    // maybe_inaccessible_message->connected_website
    cJSON *connected_website = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "connected_website");
    if (cJSON_IsNull(connected_website)) {
        connected_website = NULL;
    }
    if (connected_website) { 
    if(!cJSON_IsString(connected_website) && !cJSON_IsNull(connected_website))
    {
    goto end; //String
    }
    }

    // maybe_inaccessible_message->write_access_allowed
    cJSON *write_access_allowed = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "write_access_allowed");
    if (cJSON_IsNull(write_access_allowed)) {
        write_access_allowed = NULL;
    }
    if (write_access_allowed) { 
    write_access_allowed_local_nonprim = write_access_allowed_parseFromJSON(write_access_allowed); //nonprimitive
    }

    // maybe_inaccessible_message->passport_data
    cJSON *passport_data = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "passport_data");
    if (cJSON_IsNull(passport_data)) {
        passport_data = NULL;
    }
    if (passport_data) { 
    passport_data_local_nonprim = passport_data_parseFromJSON(passport_data); //nonprimitive
    }

    // maybe_inaccessible_message->proximity_alert_triggered
    cJSON *proximity_alert_triggered = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "proximity_alert_triggered");
    if (cJSON_IsNull(proximity_alert_triggered)) {
        proximity_alert_triggered = NULL;
    }
    if (proximity_alert_triggered) { 
    proximity_alert_triggered_local_nonprim = proximity_alert_triggered_parseFromJSON(proximity_alert_triggered); //nonprimitive
    }

    // maybe_inaccessible_message->boost_added
    cJSON *boost_added = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "boost_added");
    if (cJSON_IsNull(boost_added)) {
        boost_added = NULL;
    }
    if (boost_added) { 
    boost_added_local_nonprim = chat_boost_added_parseFromJSON(boost_added); //nonprimitive
    }

    // maybe_inaccessible_message->chat_background_set
    cJSON *chat_background_set = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "chat_background_set");
    if (cJSON_IsNull(chat_background_set)) {
        chat_background_set = NULL;
    }
    if (chat_background_set) { 
    chat_background_set_local_nonprim = chat_background_parseFromJSON(chat_background_set); //nonprimitive
    }

    // maybe_inaccessible_message->forum_topic_created
    cJSON *forum_topic_created = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "forum_topic_created");
    if (cJSON_IsNull(forum_topic_created)) {
        forum_topic_created = NULL;
    }
    if (forum_topic_created) { 
    forum_topic_created_local_nonprim = forum_topic_created_parseFromJSON(forum_topic_created); //nonprimitive
    }

    // maybe_inaccessible_message->forum_topic_edited
    cJSON *forum_topic_edited = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "forum_topic_edited");
    if (cJSON_IsNull(forum_topic_edited)) {
        forum_topic_edited = NULL;
    }
    if (forum_topic_edited) { 
    forum_topic_edited_local_nonprim = forum_topic_edited_parseFromJSON(forum_topic_edited); //nonprimitive
    }

    // maybe_inaccessible_message->forum_topic_closed
    cJSON *forum_topic_closed = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "forum_topic_closed");
    if (cJSON_IsNull(forum_topic_closed)) {
        forum_topic_closed = NULL;
    }
    if (forum_topic_closed) { 
    forum_topic_closed_local_nonprim = _parseFromJSON(forum_topic_closed); //custom
    }

    // maybe_inaccessible_message->forum_topic_reopened
    cJSON *forum_topic_reopened = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "forum_topic_reopened");
    if (cJSON_IsNull(forum_topic_reopened)) {
        forum_topic_reopened = NULL;
    }
    if (forum_topic_reopened) { 
    forum_topic_reopened_local_nonprim = _parseFromJSON(forum_topic_reopened); //custom
    }

    // maybe_inaccessible_message->general_forum_topic_hidden
    cJSON *general_forum_topic_hidden = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "general_forum_topic_hidden");
    if (cJSON_IsNull(general_forum_topic_hidden)) {
        general_forum_topic_hidden = NULL;
    }
    if (general_forum_topic_hidden) { 
    general_forum_topic_hidden_local_nonprim = _parseFromJSON(general_forum_topic_hidden); //custom
    }

    // maybe_inaccessible_message->general_forum_topic_unhidden
    cJSON *general_forum_topic_unhidden = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "general_forum_topic_unhidden");
    if (cJSON_IsNull(general_forum_topic_unhidden)) {
        general_forum_topic_unhidden = NULL;
    }
    if (general_forum_topic_unhidden) { 
    general_forum_topic_unhidden_local_nonprim = _parseFromJSON(general_forum_topic_unhidden); //custom
    }

    // maybe_inaccessible_message->giveaway_created
    cJSON *giveaway_created = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "giveaway_created");
    if (cJSON_IsNull(giveaway_created)) {
        giveaway_created = NULL;
    }
    if (giveaway_created) { 
    giveaway_created_local_nonprim = giveaway_created_parseFromJSON(giveaway_created); //nonprimitive
    }

    // maybe_inaccessible_message->giveaway
    cJSON *giveaway = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "giveaway");
    if (cJSON_IsNull(giveaway)) {
        giveaway = NULL;
    }
    if (giveaway) { 
    giveaway_local_nonprim = giveaway_parseFromJSON(giveaway); //nonprimitive
    }

    // maybe_inaccessible_message->giveaway_winners
    cJSON *giveaway_winners = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "giveaway_winners");
    if (cJSON_IsNull(giveaway_winners)) {
        giveaway_winners = NULL;
    }
    if (giveaway_winners) { 
    giveaway_winners_local_nonprim = giveaway_winners_parseFromJSON(giveaway_winners); //nonprimitive
    }

    // maybe_inaccessible_message->giveaway_completed
    cJSON *giveaway_completed = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "giveaway_completed");
    if (cJSON_IsNull(giveaway_completed)) {
        giveaway_completed = NULL;
    }
    if (giveaway_completed) { 
    giveaway_completed_local_nonprim = giveaway_completed_parseFromJSON(giveaway_completed); //nonprimitive
    }

    // maybe_inaccessible_message->paid_message_price_changed
    cJSON *paid_message_price_changed = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "paid_message_price_changed");
    if (cJSON_IsNull(paid_message_price_changed)) {
        paid_message_price_changed = NULL;
    }
    if (paid_message_price_changed) { 
    paid_message_price_changed_local_nonprim = paid_message_price_changed_parseFromJSON(paid_message_price_changed); //nonprimitive
    }

    // maybe_inaccessible_message->video_chat_scheduled
    cJSON *video_chat_scheduled = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "video_chat_scheduled");
    if (cJSON_IsNull(video_chat_scheduled)) {
        video_chat_scheduled = NULL;
    }
    if (video_chat_scheduled) { 
    video_chat_scheduled_local_nonprim = video_chat_scheduled_parseFromJSON(video_chat_scheduled); //nonprimitive
    }

    // maybe_inaccessible_message->video_chat_started
    cJSON *video_chat_started = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "video_chat_started");
    if (cJSON_IsNull(video_chat_started)) {
        video_chat_started = NULL;
    }
    if (video_chat_started) { 
    video_chat_started_local_nonprim = _parseFromJSON(video_chat_started); //custom
    }

    // maybe_inaccessible_message->video_chat_ended
    cJSON *video_chat_ended = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "video_chat_ended");
    if (cJSON_IsNull(video_chat_ended)) {
        video_chat_ended = NULL;
    }
    if (video_chat_ended) { 
    video_chat_ended_local_nonprim = video_chat_ended_parseFromJSON(video_chat_ended); //nonprimitive
    }

    // maybe_inaccessible_message->video_chat_participants_invited
    cJSON *video_chat_participants_invited = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "video_chat_participants_invited");
    if (cJSON_IsNull(video_chat_participants_invited)) {
        video_chat_participants_invited = NULL;
    }
    if (video_chat_participants_invited) { 
    video_chat_participants_invited_local_nonprim = video_chat_participants_invited_parseFromJSON(video_chat_participants_invited); //nonprimitive
    }

    // maybe_inaccessible_message->web_app_data
    cJSON *web_app_data = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "web_app_data");
    if (cJSON_IsNull(web_app_data)) {
        web_app_data = NULL;
    }
    if (web_app_data) { 
    web_app_data_local_nonprim = web_app_data_parseFromJSON(web_app_data); //nonprimitive
    }

    // maybe_inaccessible_message->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(maybe_inaccessible_messageJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    maybe_inaccessible_message_local_var = maybe_inaccessible_message_create_internal (
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

    return maybe_inaccessible_message_local_var;
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
