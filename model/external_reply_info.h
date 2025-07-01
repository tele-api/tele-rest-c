/*
 * external_reply_info.h
 *
 * This object contains information about a message that is being replied to, which may come from another chat or forum topic.
 */

#ifndef _external_reply_info_H_
#define _external_reply_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct external_reply_info_t external_reply_info_t;

#include "animation.h"
#include "audio.h"
#include "chat.h"
#include "contact.h"
#include "dice.h"
#include "document.h"
#include "game.h"
#include "giveaway.h"
#include "giveaway_winners.h"
#include "invoice.h"
#include "link_preview_options.h"
#include "location.h"
#include "message_origin.h"
#include "paid_media_info.h"
#include "photo_size.h"
#include "poll.h"
#include "sticker.h"
#include "story.h"
#include "venue.h"
#include "video.h"
#include "video_note.h"
#include "voice.h"



typedef struct external_reply_info_t {
    struct message_origin_t *origin; //model
    struct chat_t *chat; //model
    int message_id; //numeric
    struct link_preview_options_t *link_preview_options; //model
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
    int has_media_spoiler; //boolean
    struct contact_t *contact; //model
    struct dice_t *dice; //model
    struct game_t *game; //model
    struct giveaway_t *giveaway; //model
    struct giveaway_winners_t *giveaway_winners; //model
    struct invoice_t *invoice; //model
    struct location_t *location; //model
    struct poll_t *poll; //model
    struct venue_t *venue; //model

    int _library_owned; // Is the library responsible for freeing this object?
} external_reply_info_t;

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
);

void external_reply_info_free(external_reply_info_t *external_reply_info);

external_reply_info_t *external_reply_info_parseFromJSON(cJSON *external_reply_infoJSON);

cJSON *external_reply_info_convertToJSON(external_reply_info_t *external_reply_info);

#endif /* _external_reply_info_H_ */

