/*
 * input_media.h
 *
 * This object represents the content of a media message to be sent. It should be one of  * [InputMediaAnimation](https://core.telegram.org/bots/api/#inputmediaanimation) * [InputMediaDocument](https://core.telegram.org/bots/api/#inputmediadocument) * [InputMediaAudio](https://core.telegram.org/bots/api/#inputmediaaudio) * [InputMediaPhoto](https://core.telegram.org/bots/api/#inputmediaphoto) * [InputMediaVideo](https://core.telegram.org/bots/api/#inputmediavideo)
 */

#ifndef _input_media_H_
#define _input_media_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_media_t input_media_t;

#include "input_media_animation.h"
#include "input_media_audio.h"
#include "input_media_document.h"
#include "input_media_photo.h"
#include "input_media_video.h"
#include "message_entity.h"



typedef struct input_media_t {
    char *type; // string
    char *media; // string
    char *thumbnail; // string
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    int show_caption_above_media; //boolean
    int width; //numeric
    int height; //numeric
    int duration; //numeric
    int has_spoiler; //boolean
    int disable_content_type_detection; //boolean
    char *performer; // string
    char *title; // string
    char *cover; // string
    int start_timestamp; //numeric
    int supports_streaming; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} input_media_t;

__attribute__((deprecated)) input_media_t *input_media_create(
    char *type,
    char *media,
    char *thumbnail,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    int width,
    int height,
    int duration,
    int has_spoiler,
    int disable_content_type_detection,
    char *performer,
    char *title,
    char *cover,
    int start_timestamp,
    int supports_streaming
);

void input_media_free(input_media_t *input_media);

input_media_t *input_media_parseFromJSON(cJSON *input_mediaJSON);

cJSON *input_media_convertToJSON(input_media_t *input_media);

#endif /* _input_media_H_ */

