/*
 * _set_custom_emoji_sticker_set_thumbnail_post_request.h
 *
 * 
 */

#ifndef __set_custom_emoji_sticker_set_thumbnail_post_request_H_
#define __set_custom_emoji_sticker_set_thumbnail_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _set_custom_emoji_sticker_set_thumbnail_post_request_t _set_custom_emoji_sticker_set_thumbnail_post_request_t;




typedef struct _set_custom_emoji_sticker_set_thumbnail_post_request_t {
    char *name; // string
    char *custom_emoji_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} _set_custom_emoji_sticker_set_thumbnail_post_request_t;

__attribute__((deprecated)) _set_custom_emoji_sticker_set_thumbnail_post_request_t *_set_custom_emoji_sticker_set_thumbnail_post_request_create(
    char *name,
    char *custom_emoji_id
);

void _set_custom_emoji_sticker_set_thumbnail_post_request_free(_set_custom_emoji_sticker_set_thumbnail_post_request_t *_set_custom_emoji_sticker_set_thumbnail_post_request);

_set_custom_emoji_sticker_set_thumbnail_post_request_t *_set_custom_emoji_sticker_set_thumbnail_post_request_parseFromJSON(cJSON *_set_custom_emoji_sticker_set_thumbnail_post_requestJSON);

cJSON *_set_custom_emoji_sticker_set_thumbnail_post_request_convertToJSON(_set_custom_emoji_sticker_set_thumbnail_post_request_t *_set_custom_emoji_sticker_set_thumbnail_post_request);

#endif /* __set_custom_emoji_sticker_set_thumbnail_post_request_H_ */

