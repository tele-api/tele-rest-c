/*
 * input_profile_photo_static.h
 *
 * A static profile photo in the .JPG format.
 */

#ifndef _input_profile_photo_static_H_
#define _input_profile_photo_static_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_profile_photo_static_t input_profile_photo_static_t;




typedef struct input_profile_photo_static_t {
    char *type; // string
    char *photo; // string

    int _library_owned; // Is the library responsible for freeing this object?
} input_profile_photo_static_t;

__attribute__((deprecated)) input_profile_photo_static_t *input_profile_photo_static_create(
    char *type,
    char *photo
);

void input_profile_photo_static_free(input_profile_photo_static_t *input_profile_photo_static);

input_profile_photo_static_t *input_profile_photo_static_parseFromJSON(cJSON *input_profile_photo_staticJSON);

cJSON *input_profile_photo_static_convertToJSON(input_profile_photo_static_t *input_profile_photo_static);

#endif /* _input_profile_photo_static_H_ */

