/*
 * input_paid_media_photo.h
 *
 * The paid media to send is a photo.
 */

#ifndef _input_paid_media_photo_H_
#define _input_paid_media_photo_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_paid_media_photo_t input_paid_media_photo_t;




typedef struct input_paid_media_photo_t {
    char *type; // string
    char *media; // string

    int _library_owned; // Is the library responsible for freeing this object?
} input_paid_media_photo_t;

__attribute__((deprecated)) input_paid_media_photo_t *input_paid_media_photo_create(
    char *type,
    char *media
);

void input_paid_media_photo_free(input_paid_media_photo_t *input_paid_media_photo);

input_paid_media_photo_t *input_paid_media_photo_parseFromJSON(cJSON *input_paid_media_photoJSON);

cJSON *input_paid_media_photo_convertToJSON(input_paid_media_photo_t *input_paid_media_photo);

#endif /* _input_paid_media_photo_H_ */

