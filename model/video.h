/*
 * video.h
 *
 * This object represents a video file.
 */

#ifndef _video_H_
#define _video_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct video_t video_t;

#include "photo_size.h"



typedef struct video_t {
    char *file_id; // string
    char *file_unique_id; // string
    int width; //numeric
    int height; //numeric
    int duration; //numeric
    struct photo_size_t *thumbnail; //model
    list_t *cover; //nonprimitive container
    int start_timestamp; //numeric
    char *file_name; // string
    char *mime_type; // string
    int file_size; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} video_t;

__attribute__((deprecated)) video_t *video_create(
    char *file_id,
    char *file_unique_id,
    int width,
    int height,
    int duration,
    photo_size_t *thumbnail,
    list_t *cover,
    int start_timestamp,
    char *file_name,
    char *mime_type,
    int file_size
);

void video_free(video_t *video);

video_t *video_parseFromJSON(cJSON *videoJSON);

cJSON *video_convertToJSON(video_t *video);

#endif /* _video_H_ */

