/*
 * input_profile_photo.h
 *
 * This object describes a profile photo to set. Currently, it can be one of  * [InputProfilePhotoStatic](https://core.telegram.org/bots/api/#inputprofilephotostatic) * [InputProfilePhotoAnimated](https://core.telegram.org/bots/api/#inputprofilephotoanimated)
 */

#ifndef _input_profile_photo_H_
#define _input_profile_photo_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_profile_photo_t input_profile_photo_t;

#include "input_profile_photo_animated.h"
#include "input_profile_photo_static.h"



typedef struct input_profile_photo_t {
    char *type; // string
    char *photo; // string
    char *animation; // string
    double main_frame_timestamp; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} input_profile_photo_t;

__attribute__((deprecated)) input_profile_photo_t *input_profile_photo_create(
    char *type,
    char *photo,
    char *animation,
    double main_frame_timestamp
);

void input_profile_photo_free(input_profile_photo_t *input_profile_photo);

input_profile_photo_t *input_profile_photo_parseFromJSON(cJSON *input_profile_photoJSON);

cJSON *input_profile_photo_convertToJSON(input_profile_photo_t *input_profile_photo);

#endif /* _input_profile_photo_H_ */

