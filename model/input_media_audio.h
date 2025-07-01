/*
 * input_media_audio.h
 *
 * Represents an audio file to be treated as music to be sent.
 */

#ifndef _input_media_audio_H_
#define _input_media_audio_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_media_audio_t input_media_audio_t;

#include "message_entity.h"



typedef struct input_media_audio_t {
    char *type; // string
    char *media; // string
    char *thumbnail; // string
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    int duration; //numeric
    char *performer; // string
    char *title; // string

    int _library_owned; // Is the library responsible for freeing this object?
} input_media_audio_t;

__attribute__((deprecated)) input_media_audio_t *input_media_audio_create(
    char *type,
    char *media,
    char *thumbnail,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int duration,
    char *performer,
    char *title
);

void input_media_audio_free(input_media_audio_t *input_media_audio);

input_media_audio_t *input_media_audio_parseFromJSON(cJSON *input_media_audioJSON);

cJSON *input_media_audio_convertToJSON(input_media_audio_t *input_media_audio);

#endif /* _input_media_audio_H_ */

