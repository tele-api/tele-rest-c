/*
 * inline_query_result_photo.h
 *
 * Represents a link to a photo. By default, this photo will be sent by the user with optional caption. Alternatively, you can use *input\\_message\\_content* to send a message with the specified content instead of the photo.
 */

#ifndef _inline_query_result_photo_H_
#define _inline_query_result_photo_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_query_result_photo_t inline_query_result_photo_t;

#include "inline_keyboard_markup.h"
#include "input_message_content.h"
#include "message_entity.h"



typedef struct inline_query_result_photo_t {
    char *type; // string
    char *id; // string
    char *photo_url; // string
    char *thumbnail_url; // string
    int photo_width; //numeric
    int photo_height; //numeric
    char *title; // string
    char *description; // string
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    int show_caption_above_media; //boolean
    struct inline_keyboard_markup_t *reply_markup; //model
    struct input_message_content_t *input_message_content; //model

    int _library_owned; // Is the library responsible for freeing this object?
} inline_query_result_photo_t;

__attribute__((deprecated)) inline_query_result_photo_t *inline_query_result_photo_create(
    char *type,
    char *id,
    char *photo_url,
    char *thumbnail_url,
    int photo_width,
    int photo_height,
    char *title,
    char *description,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
);

void inline_query_result_photo_free(inline_query_result_photo_t *inline_query_result_photo);

inline_query_result_photo_t *inline_query_result_photo_parseFromJSON(cJSON *inline_query_result_photoJSON);

cJSON *inline_query_result_photo_convertToJSON(inline_query_result_photo_t *inline_query_result_photo);

#endif /* _inline_query_result_photo_H_ */

