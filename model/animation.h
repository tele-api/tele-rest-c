/*
 * animation.h
 *
 * This object represents an animation file (GIF or H.264/MPEG-4 AVC video without sound).
 */

#ifndef _animation_H_
#define _animation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct animation_t animation_t;

#include "photo_size.h"



typedef struct animation_t {
    char *file_id; // string
    char *file_unique_id; // string
    int width; //numeric
    int height; //numeric
    int duration; //numeric
    struct photo_size_t *thumbnail; //model
    char *file_name; // string
    char *mime_type; // string
    int file_size; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} animation_t;

__attribute__((deprecated)) animation_t *animation_create(
    char *file_id,
    char *file_unique_id,
    int width,
    int height,
    int duration,
    photo_size_t *thumbnail,
    char *file_name,
    char *mime_type,
    int file_size
);

void animation_free(animation_t *animation);

animation_t *animation_parseFromJSON(cJSON *animationJSON);

cJSON *animation_convertToJSON(animation_t *animation);

#endif /* _animation_H_ */

