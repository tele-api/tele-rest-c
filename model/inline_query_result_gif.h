/*
 * inline_query_result_gif.h
 *
 * Represents a link to an animated GIF file. By default, this animated GIF file will be sent by the user with optional caption. Alternatively, you can use *input\\_message\\_content* to send a message with the specified content instead of the animation.
 */

#ifndef _inline_query_result_gif_H_
#define _inline_query_result_gif_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_query_result_gif_t inline_query_result_gif_t;

#include "inline_keyboard_markup.h"
#include "input_message_content.h"
#include "message_entity.h"

// Enum THUMBNAILMIMETYPE for inline_query_result_gif

typedef enum  { telegram_bot_api_inline_query_result_gif_THUMBNAILMIMETYPE_NULL = 0, telegram_bot_api_inline_query_result_gif_THUMBNAILMIMETYPE_image/jpeg, telegram_bot_api_inline_query_result_gif_THUMBNAILMIMETYPE_image/gif, telegram_bot_api_inline_query_result_gif_THUMBNAILMIMETYPE_video/mp4 } telegram_bot_api_inline_query_result_gif_THUMBNAILMIMETYPE_e;

char* inline_query_result_gif_thumbnail_mime_type_ToString(telegram_bot_api_inline_query_result_gif_THUMBNAILMIMETYPE_e thumbnail_mime_type);

telegram_bot_api_inline_query_result_gif_THUMBNAILMIMETYPE_e inline_query_result_gif_thumbnail_mime_type_FromString(char* thumbnail_mime_type);



typedef struct inline_query_result_gif_t {
    char *type; // string
    char *id; // string
    char *gif_url; // string
    char *thumbnail_url; // string
    int gif_width; //numeric
    int gif_height; //numeric
    int gif_duration; //numeric
    telegram_bot_api_inline_query_result_gif_THUMBNAILMIMETYPE_e thumbnail_mime_type; //enum
    char *title; // string
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    int show_caption_above_media; //boolean
    struct inline_keyboard_markup_t *reply_markup; //model
    struct input_message_content_t *input_message_content; //model

    int _library_owned; // Is the library responsible for freeing this object?
} inline_query_result_gif_t;

__attribute__((deprecated)) inline_query_result_gif_t *inline_query_result_gif_create(
    char *type,
    char *id,
    char *gif_url,
    char *thumbnail_url,
    int gif_width,
    int gif_height,
    int gif_duration,
    telegram_bot_api_inline_query_result_gif_THUMBNAILMIMETYPE_e thumbnail_mime_type,
    char *title,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
);

void inline_query_result_gif_free(inline_query_result_gif_t *inline_query_result_gif);

inline_query_result_gif_t *inline_query_result_gif_parseFromJSON(cJSON *inline_query_result_gifJSON);

cJSON *inline_query_result_gif_convertToJSON(inline_query_result_gif_t *inline_query_result_gif);

#endif /* _inline_query_result_gif_H_ */

