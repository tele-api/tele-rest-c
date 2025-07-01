/*
 * paid_media_video.h
 *
 * The paid media is a video.
 */

#ifndef _paid_media_video_H_
#define _paid_media_video_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct paid_media_video_t paid_media_video_t;

#include "video.h"



typedef struct paid_media_video_t {
    char *type; // string
    struct video_t *video; //model

    int _library_owned; // Is the library responsible for freeing this object?
} paid_media_video_t;

__attribute__((deprecated)) paid_media_video_t *paid_media_video_create(
    char *type,
    video_t *video
);

void paid_media_video_free(paid_media_video_t *paid_media_video);

paid_media_video_t *paid_media_video_parseFromJSON(cJSON *paid_media_videoJSON);

cJSON *paid_media_video_convertToJSON(paid_media_video_t *paid_media_video);

#endif /* _paid_media_video_H_ */

