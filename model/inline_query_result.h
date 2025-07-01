/*
 * inline_query_result.h
 *
 * This object represents one result of an inline query. Telegram clients currently support results of the following 20 types:  * [InlineQueryResultCachedAudio](https://core.telegram.org/bots/api/#inlinequeryresultcachedaudio) * [InlineQueryResultCachedDocument](https://core.telegram.org/bots/api/#inlinequeryresultcacheddocument) * [InlineQueryResultCachedGif](https://core.telegram.org/bots/api/#inlinequeryresultcachedgif) * [InlineQueryResultCachedMpeg4Gif](https://core.telegram.org/bots/api/#inlinequeryresultcachedmpeg4gif) * [InlineQueryResultCachedPhoto](https://core.telegram.org/bots/api/#inlinequeryresultcachedphoto) * [InlineQueryResultCachedSticker](https://core.telegram.org/bots/api/#inlinequeryresultcachedsticker) * [InlineQueryResultCachedVideo](https://core.telegram.org/bots/api/#inlinequeryresultcachedvideo) * [InlineQueryResultCachedVoice](https://core.telegram.org/bots/api/#inlinequeryresultcachedvoice) * [InlineQueryResultArticle](https://core.telegram.org/bots/api/#inlinequeryresultarticle) * [InlineQueryResultAudio](https://core.telegram.org/bots/api/#inlinequeryresultaudio) * [InlineQueryResultContact](https://core.telegram.org/bots/api/#inlinequeryresultcontact) * [InlineQueryResultGame](https://core.telegram.org/bots/api/#inlinequeryresultgame) * [InlineQueryResultDocument](https://core.telegram.org/bots/api/#inlinequeryresultdocument) * [InlineQueryResultGif](https://core.telegram.org/bots/api/#inlinequeryresultgif) * [InlineQueryResultLocation](https://core.telegram.org/bots/api/#inlinequeryresultlocation) * [InlineQueryResultMpeg4Gif](https://core.telegram.org/bots/api/#inlinequeryresultmpeg4gif) * [InlineQueryResultPhoto](https://core.telegram.org/bots/api/#inlinequeryresultphoto) * [InlineQueryResultVenue](https://core.telegram.org/bots/api/#inlinequeryresultvenue) * [InlineQueryResultVideo](https://core.telegram.org/bots/api/#inlinequeryresultvideo) * [InlineQueryResultVoice](https://core.telegram.org/bots/api/#inlinequeryresultvoice)
 */

#ifndef _inline_query_result_H_
#define _inline_query_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_query_result_t inline_query_result_t;

#include "inline_keyboard_markup.h"
#include "inline_query_result_article.h"
#include "inline_query_result_audio.h"
#include "inline_query_result_cached_audio.h"
#include "inline_query_result_cached_document.h"
#include "inline_query_result_cached_gif.h"
#include "inline_query_result_cached_mpeg4_gif.h"
#include "inline_query_result_cached_photo.h"
#include "inline_query_result_cached_sticker.h"
#include "inline_query_result_cached_video.h"
#include "inline_query_result_cached_voice.h"
#include "inline_query_result_contact.h"
#include "inline_query_result_document.h"
#include "inline_query_result_game.h"
#include "inline_query_result_gif.h"
#include "inline_query_result_location.h"
#include "inline_query_result_mpeg4_gif.h"
#include "inline_query_result_photo.h"
#include "inline_query_result_venue.h"
#include "inline_query_result_video.h"
#include "inline_query_result_voice.h"
#include "input_message_content.h"
#include "message_entity.h"

// Enum MIMETYPE for inline_query_result

typedef enum  { telegram_bot_api_inline_query_result_MIMETYPE_NULL = 0, telegram_bot_api_inline_query_result_MIMETYPE_text/html, telegram_bot_api_inline_query_result_MIMETYPE_video/mp4 } telegram_bot_api_inline_query_result_MIMETYPE_e;

char* inline_query_result_mime_type_ToString(telegram_bot_api_inline_query_result_MIMETYPE_e mime_type);

telegram_bot_api_inline_query_result_MIMETYPE_e inline_query_result_mime_type_FromString(char* mime_type);

// Enum THUMBNAILMIMETYPE for inline_query_result

typedef enum  { telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_NULL = 0, telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_image/jpeg, telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_image/gif, telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_video/mp4 } telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_e;

char* inline_query_result_thumbnail_mime_type_ToString(telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_e thumbnail_mime_type);

telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_e inline_query_result_thumbnail_mime_type_FromString(char* thumbnail_mime_type);



typedef struct inline_query_result_t {
    char *type; // string
    char *id; // string
    char *audio_file_id; // string
    struct input_message_content_t *input_message_content; //model
    char *title; // string
    char *document_file_id; // string
    char *gif_file_id; // string
    char *mpeg4_file_id; // string
    char *photo_file_id; // string
    char *sticker_file_id; // string
    char *video_file_id; // string
    char *voice_file_id; // string
    char *thumbnail_url; // string
    char *audio_url; // string
    char *phone_number; // string
    char *first_name; // string
    char *game_short_name; // string
    char *document_url; // string
    telegram_bot_api_inline_query_result_MIMETYPE_e mime_type; //enum
    char *gif_url; // string
    double latitude; //numeric
    double longitude; //numeric
    char *mpeg4_url; // string
    char *photo_url; // string
    char *address; // string
    char *video_url; // string
    char *voice_url; // string
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    struct inline_keyboard_markup_t *reply_markup; //model
    char *description; // string
    int show_caption_above_media; //boolean
    char *url; // string
    int thumbnail_width; //numeric
    int thumbnail_height; //numeric
    char *performer; // string
    int audio_duration; //numeric
    char *last_name; // string
    char *vcard; // string
    int gif_width; //numeric
    int gif_height; //numeric
    int gif_duration; //numeric
    telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_e thumbnail_mime_type; //enum
    double horizontal_accuracy; //numeric
    int live_period; //numeric
    int heading; //numeric
    int proximity_alert_radius; //numeric
    int mpeg4_width; //numeric
    int mpeg4_height; //numeric
    int mpeg4_duration; //numeric
    int photo_width; //numeric
    int photo_height; //numeric
    char *foursquare_id; // string
    char *foursquare_type; // string
    char *google_place_id; // string
    char *google_place_type; // string
    int video_width; //numeric
    int video_height; //numeric
    int video_duration; //numeric
    int voice_duration; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} inline_query_result_t;

__attribute__((deprecated)) inline_query_result_t *inline_query_result_create(
    char *type,
    char *id,
    char *audio_file_id,
    input_message_content_t *input_message_content,
    char *title,
    char *document_file_id,
    char *gif_file_id,
    char *mpeg4_file_id,
    char *photo_file_id,
    char *sticker_file_id,
    char *video_file_id,
    char *voice_file_id,
    char *thumbnail_url,
    char *audio_url,
    char *phone_number,
    char *first_name,
    char *game_short_name,
    char *document_url,
    telegram_bot_api_inline_query_result_MIMETYPE_e mime_type,
    char *gif_url,
    double latitude,
    double longitude,
    char *mpeg4_url,
    char *photo_url,
    char *address,
    char *video_url,
    char *voice_url,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    inline_keyboard_markup_t *reply_markup,
    char *description,
    int show_caption_above_media,
    char *url,
    int thumbnail_width,
    int thumbnail_height,
    char *performer,
    int audio_duration,
    char *last_name,
    char *vcard,
    int gif_width,
    int gif_height,
    int gif_duration,
    telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_e thumbnail_mime_type,
    double horizontal_accuracy,
    int live_period,
    int heading,
    int proximity_alert_radius,
    int mpeg4_width,
    int mpeg4_height,
    int mpeg4_duration,
    int photo_width,
    int photo_height,
    char *foursquare_id,
    char *foursquare_type,
    char *google_place_id,
    char *google_place_type,
    int video_width,
    int video_height,
    int video_duration,
    int voice_duration
);

void inline_query_result_free(inline_query_result_t *inline_query_result);

inline_query_result_t *inline_query_result_parseFromJSON(cJSON *inline_query_resultJSON);

cJSON *inline_query_result_convertToJSON(inline_query_result_t *inline_query_result);

#endif /* _inline_query_result_H_ */

