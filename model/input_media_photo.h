/*
 * input_media_photo.h
 *
 * Represents a photo to be sent.
 */

#ifndef _input_media_photo_H_
#define _input_media_photo_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_media_photo_t input_media_photo_t;

#include "message_entity.h"



typedef struct input_media_photo_t {
    char *type; // string
    char *media; // string
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    int show_caption_above_media; //boolean
    int has_spoiler; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} input_media_photo_t;

__attribute__((deprecated)) input_media_photo_t *input_media_photo_create(
    char *type,
    char *media,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    int has_spoiler
);

void input_media_photo_free(input_media_photo_t *input_media_photo);

input_media_photo_t *input_media_photo_parseFromJSON(cJSON *input_media_photoJSON);

cJSON *input_media_photo_convertToJSON(input_media_photo_t *input_media_photo);

#endif /* _input_media_photo_H_ */

