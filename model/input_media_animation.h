/*
 * input_media_animation.h
 *
 * Represents an animation file (GIF or H.264/MPEG-4 AVC video without sound) to be sent.
 */

#ifndef _input_media_animation_H_
#define _input_media_animation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_media_animation_t input_media_animation_t;

#include "message_entity.h"



typedef struct input_media_animation_t {
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

    int _library_owned; // Is the library responsible for freeing this object?
} input_media_animation_t;

__attribute__((deprecated)) input_media_animation_t *input_media_animation_create(
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
    int has_spoiler
);

void input_media_animation_free(input_media_animation_t *input_media_animation);

input_media_animation_t *input_media_animation_parseFromJSON(cJSON *input_media_animationJSON);

cJSON *input_media_animation_convertToJSON(input_media_animation_t *input_media_animation);

#endif /* _input_media_animation_H_ */

