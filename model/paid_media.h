/*
 * paid_media.h
 *
 * This object describes paid media. Currently, it can be one of  * [PaidMediaPreview](https://core.telegram.org/bots/api/#paidmediapreview) * [PaidMediaPhoto](https://core.telegram.org/bots/api/#paidmediaphoto) * [PaidMediaVideo](https://core.telegram.org/bots/api/#paidmediavideo)
 */

#ifndef _paid_media_H_
#define _paid_media_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct paid_media_t paid_media_t;

#include "paid_media_photo.h"
#include "paid_media_preview.h"
#include "paid_media_video.h"
#include "photo_size.h"
#include "video.h"



typedef struct paid_media_t {
    char *type; // string
    list_t *photo; //nonprimitive container
    struct video_t *video; //model
    int width; //numeric
    int height; //numeric
    int duration; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} paid_media_t;

__attribute__((deprecated)) paid_media_t *paid_media_create(
    char *type,
    list_t *photo,
    video_t *video,
    int width,
    int height,
    int duration
);

void paid_media_free(paid_media_t *paid_media);

paid_media_t *paid_media_parseFromJSON(cJSON *paid_mediaJSON);

cJSON *paid_media_convertToJSON(paid_media_t *paid_media);

#endif /* _paid_media_H_ */

