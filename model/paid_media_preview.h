/*
 * paid_media_preview.h
 *
 * The paid media isn&#39;t available before the payment.
 */

#ifndef _paid_media_preview_H_
#define _paid_media_preview_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct paid_media_preview_t paid_media_preview_t;




typedef struct paid_media_preview_t {
    char *type; // string
    int width; //numeric
    int height; //numeric
    int duration; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} paid_media_preview_t;

__attribute__((deprecated)) paid_media_preview_t *paid_media_preview_create(
    char *type,
    int width,
    int height,
    int duration
);

void paid_media_preview_free(paid_media_preview_t *paid_media_preview);

paid_media_preview_t *paid_media_preview_parseFromJSON(cJSON *paid_media_previewJSON);

cJSON *paid_media_preview_convertToJSON(paid_media_preview_t *paid_media_preview);

#endif /* _paid_media_preview_H_ */

