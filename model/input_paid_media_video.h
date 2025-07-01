/*
 * input_paid_media_video.h
 *
 * The paid media to send is a video.
 */

#ifndef _input_paid_media_video_H_
#define _input_paid_media_video_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_paid_media_video_t input_paid_media_video_t;




typedef struct input_paid_media_video_t {
    char *type; // string
    char *media; // string
    char *thumbnail; // string
    char *cover; // string
    int start_timestamp; //numeric
    int width; //numeric
    int height; //numeric
    int duration; //numeric
    int supports_streaming; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} input_paid_media_video_t;

__attribute__((deprecated)) input_paid_media_video_t *input_paid_media_video_create(
    char *type,
    char *media,
    char *thumbnail,
    char *cover,
    int start_timestamp,
    int width,
    int height,
    int duration,
    int supports_streaming
);

void input_paid_media_video_free(input_paid_media_video_t *input_paid_media_video);

input_paid_media_video_t *input_paid_media_video_parseFromJSON(cJSON *input_paid_media_videoJSON);

cJSON *input_paid_media_video_convertToJSON(input_paid_media_video_t *input_paid_media_video);

#endif /* _input_paid_media_video_H_ */

