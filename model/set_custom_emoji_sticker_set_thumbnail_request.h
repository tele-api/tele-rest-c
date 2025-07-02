/*
 * set_custom_emoji_sticker_set_thumbnail_request.h
 *
 * Request parameters for setCustomEmojiStickerSetThumbnail
 */

#ifndef _set_custom_emoji_sticker_set_thumbnail_request_H_
#define _set_custom_emoji_sticker_set_thumbnail_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_custom_emoji_sticker_set_thumbnail_request_t set_custom_emoji_sticker_set_thumbnail_request_t;




typedef struct set_custom_emoji_sticker_set_thumbnail_request_t {
    char *name; // string
    char *custom_emoji_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} set_custom_emoji_sticker_set_thumbnail_request_t;

__attribute__((deprecated)) set_custom_emoji_sticker_set_thumbnail_request_t *set_custom_emoji_sticker_set_thumbnail_request_create(
    char *name,
    char *custom_emoji_id
);

void set_custom_emoji_sticker_set_thumbnail_request_free(set_custom_emoji_sticker_set_thumbnail_request_t *set_custom_emoji_sticker_set_thumbnail_request);

set_custom_emoji_sticker_set_thumbnail_request_t *set_custom_emoji_sticker_set_thumbnail_request_parseFromJSON(cJSON *set_custom_emoji_sticker_set_thumbnail_requestJSON);

cJSON *set_custom_emoji_sticker_set_thumbnail_request_convertToJSON(set_custom_emoji_sticker_set_thumbnail_request_t *set_custom_emoji_sticker_set_thumbnail_request);

#endif /* _set_custom_emoji_sticker_set_thumbnail_request_H_ */

