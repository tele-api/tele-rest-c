/*
 * inline_query_result_cached_gif.h
 *
 * Represents a link to an animated GIF file stored on the Telegram servers. By default, this animated GIF file will be sent by the user with an optional caption. Alternatively, you can use *input\\_message\\_content* to send a message with specified content instead of the animation.
 */

#ifndef _inline_query_result_cached_gif_H_
#define _inline_query_result_cached_gif_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_query_result_cached_gif_t inline_query_result_cached_gif_t;

#include "inline_keyboard_markup.h"
#include "input_message_content.h"
#include "message_entity.h"



typedef struct inline_query_result_cached_gif_t {
    char *type; // string
    char *id; // string
    char *gif_file_id; // string
    char *title; // string
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    int show_caption_above_media; //boolean
    struct inline_keyboard_markup_t *reply_markup; //model
    struct input_message_content_t *input_message_content; //model

    int _library_owned; // Is the library responsible for freeing this object?
} inline_query_result_cached_gif_t;

__attribute__((deprecated)) inline_query_result_cached_gif_t *inline_query_result_cached_gif_create(
    char *type,
    char *id,
    char *gif_file_id,
    char *title,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
);

void inline_query_result_cached_gif_free(inline_query_result_cached_gif_t *inline_query_result_cached_gif);

inline_query_result_cached_gif_t *inline_query_result_cached_gif_parseFromJSON(cJSON *inline_query_result_cached_gifJSON);

cJSON *inline_query_result_cached_gif_convertToJSON(inline_query_result_cached_gif_t *inline_query_result_cached_gif);

#endif /* _inline_query_result_cached_gif_H_ */

