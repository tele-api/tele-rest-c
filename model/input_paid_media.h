/*
 * input_paid_media.h
 *
 * This object describes the paid media to be sent. Currently, it can be one of  * [InputPaidMediaPhoto](https://core.telegram.org/bots/api/#inputpaidmediaphoto) * [InputPaidMediaVideo](https://core.telegram.org/bots/api/#inputpaidmediavideo)
 */

#ifndef _input_paid_media_H_
#define _input_paid_media_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_paid_media_t input_paid_media_t;

#include "input_paid_media_photo.h"
#include "input_paid_media_video.h"



typedef struct input_paid_media_t {
    char *type; // string
    char *media; // string
    char *thumbnail; // string
    char *cover; // string
    int start_timestamp; //numeric
    int width; //numeric
    int height; //numeric
    int duration; //numeric
    int supports_streaming; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} input_paid_media_t;

__attribute__((deprecated)) input_paid_media_t *input_paid_media_create(
    char *type,
    char *media,
    char *thumbnail,
    char *cover,
    int start_timestamp,
    int width,
    int height,
    int duration,
    int supports_streaming
);

void input_paid_media_free(input_paid_media_t *input_paid_media);

input_paid_media_t *input_paid_media_parseFromJSON(cJSON *input_paid_mediaJSON);

cJSON *input_paid_media_convertToJSON(input_paid_media_t *input_paid_media);

#endif /* _input_paid_media_H_ */

