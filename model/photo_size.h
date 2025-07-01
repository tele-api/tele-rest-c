/*
 * photo_size.h
 *
 * This object represents one size of a photo or a [file](https://core.telegram.org/bots/api/#document) / [sticker](https://core.telegram.org/bots/api/#sticker) thumbnail.
 */

#ifndef _photo_size_H_
#define _photo_size_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct photo_size_t photo_size_t;




typedef struct photo_size_t {
    char *file_id; // string
    char *file_unique_id; // string
    int width; //numeric
    int height; //numeric
    int file_size; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} photo_size_t;

__attribute__((deprecated)) photo_size_t *photo_size_create(
    char *file_id,
    char *file_unique_id,
    int width,
    int height,
    int file_size
);

void photo_size_free(photo_size_t *photo_size);

photo_size_t *photo_size_parseFromJSON(cJSON *photo_sizeJSON);

cJSON *photo_size_convertToJSON(photo_size_t *photo_size);

#endif /* _photo_size_H_ */

