/*
 * inline_query_result_video.h
 *
 * Represents a link to a page containing an embedded video player or a video file. By default, this video file will be sent by the user with an optional caption. Alternatively, you can use *input\\_message\\_content* to send a message with the specified content instead of the video.  If an InlineQueryResultVideo message contains an embedded video (e.g., YouTube), you **must** replace its content using *input\\_message\\_content*.
 */

#ifndef _inline_query_result_video_H_
#define _inline_query_result_video_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_query_result_video_t inline_query_result_video_t;

#include "inline_keyboard_markup.h"
#include "input_message_content.h"
#include "message_entity.h"

// Enum MIMETYPE for inline_query_result_video

typedef enum  { telegram_bot_api_inline_query_result_video_MIMETYPE_NULL = 0, telegram_bot_api_inline_query_result_video_MIMETYPE_text/html, telegram_bot_api_inline_query_result_video_MIMETYPE_video/mp4 } telegram_bot_api_inline_query_result_video_MIMETYPE_e;

char* inline_query_result_video_mime_type_ToString(telegram_bot_api_inline_query_result_video_MIMETYPE_e mime_type);

telegram_bot_api_inline_query_result_video_MIMETYPE_e inline_query_result_video_mime_type_FromString(char* mime_type);



typedef struct inline_query_result_video_t {
    char *type; // string
    char *id; // string
    char *video_url; // string
    telegram_bot_api_inline_query_result_video_MIMETYPE_e mime_type; //enum
    char *thumbnail_url; // string
    char *title; // string
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    int show_caption_above_media; //boolean
    int video_width; //numeric
    int video_height; //numeric
    int video_duration; //numeric
    char *description; // string
    struct inline_keyboard_markup_t *reply_markup; //model
    struct input_message_content_t *input_message_content; //model

    int _library_owned; // Is the library responsible for freeing this object?
} inline_query_result_video_t;

__attribute__((deprecated)) inline_query_result_video_t *inline_query_result_video_create(
    char *type,
    char *id,
    char *video_url,
    telegram_bot_api_inline_query_result_video_MIMETYPE_e mime_type,
    char *thumbnail_url,
    char *title,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    int video_width,
    int video_height,
    int video_duration,
    char *description,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
);

void inline_query_result_video_free(inline_query_result_video_t *inline_query_result_video);

inline_query_result_video_t *inline_query_result_video_parseFromJSON(cJSON *inline_query_result_videoJSON);

cJSON *inline_query_result_video_convertToJSON(inline_query_result_video_t *inline_query_result_video);

#endif /* _inline_query_result_video_H_ */

