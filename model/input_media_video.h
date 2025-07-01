/*
 * input_media_video.h
 *
 * Represents a video to be sent.
 */

#ifndef _input_media_video_H_
#define _input_media_video_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_media_video_t input_media_video_t;

#include "message_entity.h"



typedef struct input_media_video_t {
    char *type; // string
    char *media; // string
    char *thumbnail; // string
    char *cover; // string
    int start_timestamp; //numeric
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    int show_caption_above_media; //boolean
    int width; //numeric
    int height; //numeric
    int duration; //numeric
    int supports_streaming; //boolean
    int has_spoiler; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} input_media_video_t;

__attribute__((deprecated)) input_media_video_t *input_media_video_create(
    char *type,
    char *media,
    char *thumbnail,
    char *cover,
    int start_timestamp,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    int width,
    int height,
    int duration,
    int supports_streaming,
    int has_spoiler
);

void input_media_video_free(input_media_video_t *input_media_video);

input_media_video_t *input_media_video_parseFromJSON(cJSON *input_media_videoJSON);

cJSON *input_media_video_convertToJSON(input_media_video_t *input_media_video);

#endif /* _input_media_video_H_ */

