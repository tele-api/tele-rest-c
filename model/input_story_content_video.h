/*
 * input_story_content_video.h
 *
 * Describes a video to post as a story.
 */

#ifndef _input_story_content_video_H_
#define _input_story_content_video_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_story_content_video_t input_story_content_video_t;




typedef struct input_story_content_video_t {
    char *type; // string
    char *video; // string
    double duration; //numeric
    double cover_frame_timestamp; //numeric
    int is_animation; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} input_story_content_video_t;

__attribute__((deprecated)) input_story_content_video_t *input_story_content_video_create(
    char *type,
    char *video,
    double duration,
    double cover_frame_timestamp,
    int is_animation
);

void input_story_content_video_free(input_story_content_video_t *input_story_content_video);

input_story_content_video_t *input_story_content_video_parseFromJSON(cJSON *input_story_content_videoJSON);

cJSON *input_story_content_video_convertToJSON(input_story_content_video_t *input_story_content_video);

#endif /* _input_story_content_video_H_ */

