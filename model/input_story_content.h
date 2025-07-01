/*
 * input_story_content.h
 *
 * This object describes the content of a story to post. Currently, it can be one of  * [InputStoryContentPhoto](https://core.telegram.org/bots/api/#inputstorycontentphoto) * [InputStoryContentVideo](https://core.telegram.org/bots/api/#inputstorycontentvideo)
 */

#ifndef _input_story_content_H_
#define _input_story_content_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_story_content_t input_story_content_t;

#include "input_story_content_photo.h"
#include "input_story_content_video.h"



typedef struct input_story_content_t {
    char *type; // string
    char *photo; // string
    char *video; // string
    double duration; //numeric
    double cover_frame_timestamp; //numeric
    int is_animation; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} input_story_content_t;

__attribute__((deprecated)) input_story_content_t *input_story_content_create(
    char *type,
    char *photo,
    char *video,
    double duration,
    double cover_frame_timestamp,
    int is_animation
);

void input_story_content_free(input_story_content_t *input_story_content);

input_story_content_t *input_story_content_parseFromJSON(cJSON *input_story_contentJSON);

cJSON *input_story_content_convertToJSON(input_story_content_t *input_story_content);

#endif /* _input_story_content_H_ */

