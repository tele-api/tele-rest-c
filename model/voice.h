/*
 * voice.h
 *
 * This object represents a voice note.
 */

#ifndef _voice_H_
#define _voice_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct voice_t voice_t;




typedef struct voice_t {
    char *file_id; // string
    char *file_unique_id; // string
    int duration; //numeric
    char *mime_type; // string
    int file_size; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} voice_t;

__attribute__((deprecated)) voice_t *voice_create(
    char *file_id,
    char *file_unique_id,
    int duration,
    char *mime_type,
    int file_size
);

void voice_free(voice_t *voice);

voice_t *voice_parseFromJSON(cJSON *voiceJSON);

cJSON *voice_convertToJSON(voice_t *voice);

#endif /* _voice_H_ */

