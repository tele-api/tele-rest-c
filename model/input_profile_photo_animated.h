/*
 * input_profile_photo_animated.h
 *
 * An animated profile photo in the MPEG4 format.
 */

#ifndef _input_profile_photo_animated_H_
#define _input_profile_photo_animated_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_profile_photo_animated_t input_profile_photo_animated_t;




typedef struct input_profile_photo_animated_t {
    char *type; // string
    char *animation; // string
    double main_frame_timestamp; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} input_profile_photo_animated_t;

__attribute__((deprecated)) input_profile_photo_animated_t *input_profile_photo_animated_create(
    char *type,
    char *animation,
    double main_frame_timestamp
);

void input_profile_photo_animated_free(input_profile_photo_animated_t *input_profile_photo_animated);

input_profile_photo_animated_t *input_profile_photo_animated_parseFromJSON(cJSON *input_profile_photo_animatedJSON);

cJSON *input_profile_photo_animated_convertToJSON(input_profile_photo_animated_t *input_profile_photo_animated);

#endif /* _input_profile_photo_animated_H_ */

