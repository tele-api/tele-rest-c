/*
 * audio.h
 *
 * This object represents an audio file to be treated as music by the Telegram clients.
 */

#ifndef _audio_H_
#define _audio_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct audio_t audio_t;

#include "photo_size.h"



typedef struct audio_t {
    char *file_id; // string
    char *file_unique_id; // string
    int duration; //numeric
    char *performer; // string
    char *title; // string
    char *file_name; // string
    char *mime_type; // string
    int file_size; //numeric
    struct photo_size_t *thumbnail; //model

    int _library_owned; // Is the library responsible for freeing this object?
} audio_t;

__attribute__((deprecated)) audio_t *audio_create(
    char *file_id,
    char *file_unique_id,
    int duration,
    char *performer,
    char *title,
    char *file_name,
    char *mime_type,
    int file_size,
    photo_size_t *thumbnail
);

void audio_free(audio_t *audio);

audio_t *audio_parseFromJSON(cJSON *audioJSON);

cJSON *audio_convertToJSON(audio_t *audio);

#endif /* _audio_H_ */

