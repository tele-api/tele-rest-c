/*
 * video_note.h
 *
 * This object represents a [video message](https://telegram.org/blog/video-messages-and-telescope) (available in Telegram apps as of [v.4.0](https://telegram.org/blog/video-messages-and-telescope)).
 */

#ifndef _video_note_H_
#define _video_note_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct video_note_t video_note_t;

#include "photo_size.h"



typedef struct video_note_t {
    char *file_id; // string
    char *file_unique_id; // string
    int length; //numeric
    int duration; //numeric
    struct photo_size_t *thumbnail; //model
    int file_size; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} video_note_t;

__attribute__((deprecated)) video_note_t *video_note_create(
    char *file_id,
    char *file_unique_id,
    int length,
    int duration,
    photo_size_t *thumbnail,
    int file_size
);

void video_note_free(video_note_t *video_note);

video_note_t *video_note_parseFromJSON(cJSON *video_noteJSON);

cJSON *video_note_convertToJSON(video_note_t *video_note);

#endif /* _video_note_H_ */

