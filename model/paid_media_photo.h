/*
 * paid_media_photo.h
 *
 * The paid media is a photo.
 */

#ifndef _paid_media_photo_H_
#define _paid_media_photo_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct paid_media_photo_t paid_media_photo_t;

#include "photo_size.h"



typedef struct paid_media_photo_t {
    char *type; // string
    list_t *photo; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} paid_media_photo_t;

__attribute__((deprecated)) paid_media_photo_t *paid_media_photo_create(
    char *type,
    list_t *photo
);

void paid_media_photo_free(paid_media_photo_t *paid_media_photo);

paid_media_photo_t *paid_media_photo_parseFromJSON(cJSON *paid_media_photoJSON);

cJSON *paid_media_photo_convertToJSON(paid_media_photo_t *paid_media_photo);

#endif /* _paid_media_photo_H_ */

