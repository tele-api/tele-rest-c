/*
 * input_story_content_photo.h
 *
 * Describes a photo to post as a story.
 */

#ifndef _input_story_content_photo_H_
#define _input_story_content_photo_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_story_content_photo_t input_story_content_photo_t;




typedef struct input_story_content_photo_t {
    char *type; // string
    char *photo; // string

    int _library_owned; // Is the library responsible for freeing this object?
} input_story_content_photo_t;

__attribute__((deprecated)) input_story_content_photo_t *input_story_content_photo_create(
    char *type,
    char *photo
);

void input_story_content_photo_free(input_story_content_photo_t *input_story_content_photo);

input_story_content_photo_t *input_story_content_photo_parseFromJSON(cJSON *input_story_content_photoJSON);

cJSON *input_story_content_photo_convertToJSON(input_story_content_photo_t *input_story_content_photo);

#endif /* _input_story_content_photo_H_ */

