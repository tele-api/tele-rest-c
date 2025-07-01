#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "external_reply_info.h"



static external_reply_info_t *external_reply_info_create_internal(
    message_origin_t *origin,
    chat_t *chat,
    int message_id,
    link_preview_options_t *link_preview_options,
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
    int has_media_spoiler,
    contact_t *contact,
    dice_t *dice,
    game_t *game,
    giveaway_t *giveaway,
    giveaway_winners_t *giveaway_winners,
    invoice_t *invoice,
    location_t *location,
    poll_t *poll,
    venue_t *venue
    ) {
    external_reply_info_t *external_reply_info_local_var = malloc(sizeof(external_reply_info_t));
    if (!external_reply_info_local_var) {
        return NULL;
    }
    external_reply_info_local_var->origin = origin;
    external_reply_info_local_var->chat = chat;
    external_reply_info_local_var->message_id = message_id;
    external_reply_info_local_var->link_preview_options = link_preview_options;
    external_reply_info_local_var->animation = animation;
    external_reply_info_local_var->audio = audio;
    external_reply_info_local_var->document = document;
    external_reply_info_local_var->paid_media = paid_media;
    external_reply_info_local_var->photo = photo;
    external_reply_info_local_var->sticker = sticker;
    external_reply_info_local_var->story = story;
    external_reply_info_local_var->video = video;
    external_reply_info_local_var->video_note = video_note;
    external_reply_info_local_var->voice = voice;
    external_reply_info_local_var->has_media_spoiler = has_media_spoiler;
    external_reply_info_local_var->contact = contact;
    external_reply_info_local_var->dice = dice;
    external_reply_info_local_var->game = game;
    external_reply_info_local_var->giveaway = giveaway;
    external_reply_info_local_var->giveaway_winners = giveaway_winners;
    external_reply_info_local_var->invoice = invoice;
    external_reply_info_local_var->location = location;
    external_reply_info_local_var->poll = poll;
    external_reply_info_local_var->venue = venue;

    external_reply_info_local_var->_library_owned = 1;
    return external_reply_info_local_var;
}

__attribute__((deprecated)) external_reply_info_t *external_reply_info_create(
    message_origin_t *origin,
    chat_t *chat,
    int message_id,
    link_preview_options_t *link_preview_options,
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
    int has_media_spoiler,
    contact_t *contact,
    dice_t *dice,
    game_t *game,
    giveaway_t *giveaway,
    giveaway_winners_t *giveaway_winners,
    invoice_t *invoice,
    location_t *location,
    poll_t *poll,
    venue_t *venue
    ) {
    return external_reply_info_create_internal (
        origin,
        chat,
        message_id,
        link_preview_options,
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
        has_media_spoiler,
        contact,
        dice,
        game,
        giveaway,
        giveaway_winners,
        invoice,
        location,
        poll,
        venue
        );
}

void external_reply_info_free(external_reply_info_t *external_reply_info) {
    if(NULL == external_reply_info){
        return ;
    }
    if(external_reply_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "external_reply_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (external_reply_info->origin) {
        message_origin_free(external_reply_info->origin);
        external_reply_info->origin = NULL;
    }
    if (external_reply_info->chat) {
        chat_free(external_reply_info->chat);
        external_reply_info->chat = NULL;
    }
    if (external_reply_info->link_preview_options) {
        link_preview_options_free(external_reply_info->link_preview_options);
        external_reply_info->link_preview_options = NULL;
    }
    if (external_reply_info->animation) {
        animation_free(external_reply_info->animation);
        external_reply_info->animation = NULL;
    }
    if (external_reply_info->audio) {
        audio_free(external_reply_info->audio);
        external_reply_info->audio = NULL;
    }
    if (external_reply_info->document) {
        document_free(external_reply_info->document);
        external_reply_info->document = NULL;
    }
    if (external_reply_info->paid_media) {
        paid_media_info_free(external_reply_info->paid_media);
        external_reply_info->paid_media = NULL;
    }
    if (external_reply_info->photo) {
        list_ForEach(listEntry, external_reply_info->photo) {
            photo_size_free(listEntry->data);
        }
        list_freeList(external_reply_info->photo);
        external_reply_info->photo = NULL;
    }
    if (external_reply_info->sticker) {
        sticker_free(external_reply_info->sticker);
        external_reply_info->sticker = NULL;
    }
    if (external_reply_info->story) {
        story_free(external_reply_info->story);
        external_reply_info->story = NULL;
    }
    if (external_reply_info->video) {
        video_free(external_reply_info->video);
        external_reply_info->video = NULL;
    }
    if (external_reply_info->video_note) {
        video_note_free(external_reply_info->video_note);
        external_reply_info->video_note = NULL;
    }
    if (external_reply_info->voice) {
        voice_free(external_reply_info->voice);
        external_reply_info->voice = NULL;
    }
    if (external_reply_info->contact) {
        contact_free(external_reply_info->contact);
        external_reply_info->contact = NULL;
    }
    if (external_reply_info->dice) {
        dice_free(external_reply_info->dice);
        external_reply_info->dice = NULL;
    }
    if (external_reply_info->game) {
        game_free(external_reply_info->game);
        external_reply_info->game = NULL;
    }
    if (external_reply_info->giveaway) {
        giveaway_free(external_reply_info->giveaway);
        external_reply_info->giveaway = NULL;
    }
    if (external_reply_info->giveaway_winners) {
        giveaway_winners_free(external_reply_info->giveaway_winners);
        external_reply_info->giveaway_winners = NULL;
    }
    if (external_reply_info->invoice) {
        invoice_free(external_reply_info->invoice);
        external_reply_info->invoice = NULL;
    }
    if (external_reply_info->location) {
        location_free(external_reply_info->location);
        external_reply_info->location = NULL;
    }
    if (external_reply_info->poll) {
        poll_free(external_reply_info->poll);
        external_reply_info->poll = NULL;
    }
    if (external_reply_info->venue) {
        venue_free(external_reply_info->venue);
        external_reply_info->venue = NULL;
    }
    free(external_reply_info);
}

cJSON *external_reply_info_convertToJSON(external_reply_info_t *external_reply_info) {
    cJSON *item = cJSON_CreateObject();

    // external_reply_info->origin
    if (!external_reply_info->origin) {
        goto fail;
    }
    cJSON *origin_local_JSON = message_origin_convertToJSON(external_reply_info->origin);
    if(origin_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "origin", origin_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // external_reply_info->chat
    if(external_reply_info->chat) {
    cJSON *chat_local_JSON = chat_convertToJSON(external_reply_info->chat);
    if(chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat", chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->message_id
    if(external_reply_info->message_id) {
    if(cJSON_AddNumberToObject(item, "message_id", external_reply_info->message_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // external_reply_info->link_preview_options
    if(external_reply_info->link_preview_options) {
    cJSON *link_preview_options_local_JSON = link_preview_options_convertToJSON(external_reply_info->link_preview_options);
    if(link_preview_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "link_preview_options", link_preview_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->animation
    if(external_reply_info->animation) {
    cJSON *animation_local_JSON = animation_convertToJSON(external_reply_info->animation);
    if(animation_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "animation", animation_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->audio
    if(external_reply_info->audio) {
    cJSON *audio_local_JSON = audio_convertToJSON(external_reply_info->audio);
    if(audio_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "audio", audio_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->document
    if(external_reply_info->document) {
    cJSON *document_local_JSON = document_convertToJSON(external_reply_info->document);
    if(document_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "document", document_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->paid_media
    if(external_reply_info->paid_media) {
    cJSON *paid_media_local_JSON = paid_media_info_convertToJSON(external_reply_info->paid_media);
    if(paid_media_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "paid_media", paid_media_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->photo
    if(external_reply_info->photo) {
    cJSON *photo = cJSON_AddArrayToObject(item, "photo");
    if(photo == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *photoListEntry;
    if (external_reply_info->photo) {
    list_ForEach(photoListEntry, external_reply_info->photo) {
    cJSON *itemLocal = photo_size_convertToJSON(photoListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(photo, itemLocal);
    }
    }
    }


    // external_reply_info->sticker
    if(external_reply_info->sticker) {
    cJSON *sticker_local_JSON = sticker_convertToJSON(external_reply_info->sticker);
    if(sticker_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sticker", sticker_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->story
    if(external_reply_info->story) {
    cJSON *story_local_JSON = story_convertToJSON(external_reply_info->story);
    if(story_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "story", story_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->video
    if(external_reply_info->video) {
    cJSON *video_local_JSON = video_convertToJSON(external_reply_info->video);
    if(video_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "video", video_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->video_note
    if(external_reply_info->video_note) {
    cJSON *video_note_local_JSON = video_note_convertToJSON(external_reply_info->video_note);
    if(video_note_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "video_note", video_note_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->voice
    if(external_reply_info->voice) {
    cJSON *voice_local_JSON = voice_convertToJSON(external_reply_info->voice);
    if(voice_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "voice", voice_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->has_media_spoiler
    if(external_reply_info->has_media_spoiler) {
    if(cJSON_AddBoolToObject(item, "has_media_spoiler", external_reply_info->has_media_spoiler) == NULL) {
    goto fail; //Bool
    }
    }


    // external_reply_info->contact
    if(external_reply_info->contact) {
    cJSON *contact_local_JSON = contact_convertToJSON(external_reply_info->contact);
    if(contact_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "contact", contact_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->dice
    if(external_reply_info->dice) {
    cJSON *dice_local_JSON = dice_convertToJSON(external_reply_info->dice);
    if(dice_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "dice", dice_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->game
    if(external_reply_info->game) {
    cJSON *game_local_JSON = game_convertToJSON(external_reply_info->game);
    if(game_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "game", game_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->giveaway
    if(external_reply_info->giveaway) {
    cJSON *giveaway_local_JSON = giveaway_convertToJSON(external_reply_info->giveaway);
    if(giveaway_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "giveaway", giveaway_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->giveaway_winners
    if(external_reply_info->giveaway_winners) {
    cJSON *giveaway_winners_local_JSON = giveaway_winners_convertToJSON(external_reply_info->giveaway_winners);
    if(giveaway_winners_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "giveaway_winners", giveaway_winners_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->invoice
    if(external_reply_info->invoice) {
    cJSON *invoice_local_JSON = invoice_convertToJSON(external_reply_info->invoice);
    if(invoice_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "invoice", invoice_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->location
    if(external_reply_info->location) {
    cJSON *location_local_JSON = location_convertToJSON(external_reply_info->location);
    if(location_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "location", location_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->poll
    if(external_reply_info->poll) {
    cJSON *poll_local_JSON = poll_convertToJSON(external_reply_info->poll);
    if(poll_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "poll", poll_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // external_reply_info->venue
    if(external_reply_info->venue) {
    cJSON *venue_local_JSON = venue_convertToJSON(external_reply_info->venue);
    if(venue_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "venue", venue_local_JSON);
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

external_reply_info_t *external_reply_info_parseFromJSON(cJSON *external_reply_infoJSON){

    external_reply_info_t *external_reply_info_local_var = NULL;

    // define the local variable for external_reply_info->origin
    message_origin_t *origin_local_nonprim = NULL;

    // define the local variable for external_reply_info->chat
    chat_t *chat_local_nonprim = NULL;

    // define the local variable for external_reply_info->link_preview_options
    link_preview_options_t *link_preview_options_local_nonprim = NULL;

    // define the local variable for external_reply_info->animation
    animation_t *animation_local_nonprim = NULL;

    // define the local variable for external_reply_info->audio
    audio_t *audio_local_nonprim = NULL;

    // define the local variable for external_reply_info->document
    document_t *document_local_nonprim = NULL;

    // define the local variable for external_reply_info->paid_media
    paid_media_info_t *paid_media_local_nonprim = NULL;

    // define the local list for external_reply_info->photo
    list_t *photoList = NULL;

    // define the local variable for external_reply_info->sticker
    sticker_t *sticker_local_nonprim = NULL;

    // define the local variable for external_reply_info->story
    story_t *story_local_nonprim = NULL;

    // define the local variable for external_reply_info->video
    video_t *video_local_nonprim = NULL;

    // define the local variable for external_reply_info->video_note
    video_note_t *video_note_local_nonprim = NULL;

    // define the local variable for external_reply_info->voice
    voice_t *voice_local_nonprim = NULL;

    // define the local variable for external_reply_info->contact
    contact_t *contact_local_nonprim = NULL;

    // define the local variable for external_reply_info->dice
    dice_t *dice_local_nonprim = NULL;

    // define the local variable for external_reply_info->game
    game_t *game_local_nonprim = NULL;

    // define the local variable for external_reply_info->giveaway
    giveaway_t *giveaway_local_nonprim = NULL;

    // define the local variable for external_reply_info->giveaway_winners
    giveaway_winners_t *giveaway_winners_local_nonprim = NULL;

    // define the local variable for external_reply_info->invoice
    invoice_t *invoice_local_nonprim = NULL;

    // define the local variable for external_reply_info->location
    location_t *location_local_nonprim = NULL;

    // define the local variable for external_reply_info->poll
    poll_t *poll_local_nonprim = NULL;

    // define the local variable for external_reply_info->venue
    venue_t *venue_local_nonprim = NULL;

    // external_reply_info->origin
    cJSON *origin = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "origin");
    if (cJSON_IsNull(origin)) {
        origin = NULL;
    }
    if (!origin) {
        goto end;
    }

    
    origin_local_nonprim = message_origin_parseFromJSON(origin); //nonprimitive

    // external_reply_info->chat
    cJSON *chat = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "chat");
    if (cJSON_IsNull(chat)) {
        chat = NULL;
    }
    if (chat) { 
    chat_local_nonprim = chat_parseFromJSON(chat); //nonprimitive
    }

    // external_reply_info->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (message_id) { 
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }
    }

    // external_reply_info->link_preview_options
    cJSON *link_preview_options = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "link_preview_options");
    if (cJSON_IsNull(link_preview_options)) {
        link_preview_options = NULL;
    }
    if (link_preview_options) { 
    link_preview_options_local_nonprim = link_preview_options_parseFromJSON(link_preview_options); //nonprimitive
    }

    // external_reply_info->animation
    cJSON *animation = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "animation");
    if (cJSON_IsNull(animation)) {
        animation = NULL;
    }
    if (animation) { 
    animation_local_nonprim = animation_parseFromJSON(animation); //nonprimitive
    }

    // external_reply_info->audio
    cJSON *audio = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "audio");
    if (cJSON_IsNull(audio)) {
        audio = NULL;
    }
    if (audio) { 
    audio_local_nonprim = audio_parseFromJSON(audio); //nonprimitive
    }

    // external_reply_info->document
    cJSON *document = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "document");
    if (cJSON_IsNull(document)) {
        document = NULL;
    }
    if (document) { 
    document_local_nonprim = document_parseFromJSON(document); //nonprimitive
    }

    // external_reply_info->paid_media
    cJSON *paid_media = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "paid_media");
    if (cJSON_IsNull(paid_media)) {
        paid_media = NULL;
    }
    if (paid_media) { 
    paid_media_local_nonprim = paid_media_info_parseFromJSON(paid_media); //nonprimitive
    }

    // external_reply_info->photo
    cJSON *photo = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "photo");
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

    // external_reply_info->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "sticker");
    if (cJSON_IsNull(sticker)) {
        sticker = NULL;
    }
    if (sticker) { 
    sticker_local_nonprim = sticker_parseFromJSON(sticker); //nonprimitive
    }

    // external_reply_info->story
    cJSON *story = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "story");
    if (cJSON_IsNull(story)) {
        story = NULL;
    }
    if (story) { 
    story_local_nonprim = story_parseFromJSON(story); //nonprimitive
    }

    // external_reply_info->video
    cJSON *video = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "video");
    if (cJSON_IsNull(video)) {
        video = NULL;
    }
    if (video) { 
    video_local_nonprim = video_parseFromJSON(video); //nonprimitive
    }

    // external_reply_info->video_note
    cJSON *video_note = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "video_note");
    if (cJSON_IsNull(video_note)) {
        video_note = NULL;
    }
    if (video_note) { 
    video_note_local_nonprim = video_note_parseFromJSON(video_note); //nonprimitive
    }

    // external_reply_info->voice
    cJSON *voice = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "voice");
    if (cJSON_IsNull(voice)) {
        voice = NULL;
    }
    if (voice) { 
    voice_local_nonprim = voice_parseFromJSON(voice); //nonprimitive
    }

    // external_reply_info->has_media_spoiler
    cJSON *has_media_spoiler = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "has_media_spoiler");
    if (cJSON_IsNull(has_media_spoiler)) {
        has_media_spoiler = NULL;
    }
    if (has_media_spoiler) { 
    if(!cJSON_IsBool(has_media_spoiler))
    {
    goto end; //Bool
    }
    }

    // external_reply_info->contact
    cJSON *contact = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "contact");
    if (cJSON_IsNull(contact)) {
        contact = NULL;
    }
    if (contact) { 
    contact_local_nonprim = contact_parseFromJSON(contact); //nonprimitive
    }

    // external_reply_info->dice
    cJSON *dice = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "dice");
    if (cJSON_IsNull(dice)) {
        dice = NULL;
    }
    if (dice) { 
    dice_local_nonprim = dice_parseFromJSON(dice); //nonprimitive
    }

    // external_reply_info->game
    cJSON *game = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "game");
    if (cJSON_IsNull(game)) {
        game = NULL;
    }
    if (game) { 
    game_local_nonprim = game_parseFromJSON(game); //nonprimitive
    }

    // external_reply_info->giveaway
    cJSON *giveaway = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "giveaway");
    if (cJSON_IsNull(giveaway)) {
        giveaway = NULL;
    }
    if (giveaway) { 
    giveaway_local_nonprim = giveaway_parseFromJSON(giveaway); //nonprimitive
    }

    // external_reply_info->giveaway_winners
    cJSON *giveaway_winners = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "giveaway_winners");
    if (cJSON_IsNull(giveaway_winners)) {
        giveaway_winners = NULL;
    }
    if (giveaway_winners) { 
    giveaway_winners_local_nonprim = giveaway_winners_parseFromJSON(giveaway_winners); //nonprimitive
    }

    // external_reply_info->invoice
    cJSON *invoice = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "invoice");
    if (cJSON_IsNull(invoice)) {
        invoice = NULL;
    }
    if (invoice) { 
    invoice_local_nonprim = invoice_parseFromJSON(invoice); //nonprimitive
    }

    // external_reply_info->location
    cJSON *location = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "location");
    if (cJSON_IsNull(location)) {
        location = NULL;
    }
    if (location) { 
    location_local_nonprim = location_parseFromJSON(location); //nonprimitive
    }

    // external_reply_info->poll
    cJSON *poll = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "poll");
    if (cJSON_IsNull(poll)) {
        poll = NULL;
    }
    if (poll) { 
    poll_local_nonprim = poll_parseFromJSON(poll); //nonprimitive
    }

    // external_reply_info->venue
    cJSON *venue = cJSON_GetObjectItemCaseSensitive(external_reply_infoJSON, "venue");
    if (cJSON_IsNull(venue)) {
        venue = NULL;
    }
    if (venue) { 
    venue_local_nonprim = venue_parseFromJSON(venue); //nonprimitive
    }


    external_reply_info_local_var = external_reply_info_create_internal (
        origin_local_nonprim,
        chat ? chat_local_nonprim : NULL,
        message_id ? message_id->valuedouble : 0,
        link_preview_options ? link_preview_options_local_nonprim : NULL,
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
        has_media_spoiler ? has_media_spoiler->valueint : 0,
        contact ? contact_local_nonprim : NULL,
        dice ? dice_local_nonprim : NULL,
        game ? game_local_nonprim : NULL,
        giveaway ? giveaway_local_nonprim : NULL,
        giveaway_winners ? giveaway_winners_local_nonprim : NULL,
        invoice ? invoice_local_nonprim : NULL,
        location ? location_local_nonprim : NULL,
        poll ? poll_local_nonprim : NULL,
        venue ? venue_local_nonprim : NULL
        );

    return external_reply_info_local_var;
end:
    if (origin_local_nonprim) {
        message_origin_free(origin_local_nonprim);
        origin_local_nonprim = NULL;
    }
    if (chat_local_nonprim) {
        chat_free(chat_local_nonprim);
        chat_local_nonprim = NULL;
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
    if (giveaway_local_nonprim) {
        giveaway_free(giveaway_local_nonprim);
        giveaway_local_nonprim = NULL;
    }
    if (giveaway_winners_local_nonprim) {
        giveaway_winners_free(giveaway_winners_local_nonprim);
        giveaway_winners_local_nonprim = NULL;
    }
    if (invoice_local_nonprim) {
        invoice_free(invoice_local_nonprim);
        invoice_local_nonprim = NULL;
    }
    if (location_local_nonprim) {
        location_free(location_local_nonprim);
        location_local_nonprim = NULL;
    }
    if (poll_local_nonprim) {
        poll_free(poll_local_nonprim);
        poll_local_nonprim = NULL;
    }
    if (venue_local_nonprim) {
        venue_free(venue_local_nonprim);
        venue_local_nonprim = NULL;
    }
    return NULL;

}
