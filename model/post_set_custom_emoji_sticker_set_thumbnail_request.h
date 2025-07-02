/*
 * post_set_custom_emoji_sticker_set_thumbnail_request.h
 *
 * 
 */

#ifndef _post_set_custom_emoji_sticker_set_thumbnail_request_H_
#define _post_set_custom_emoji_sticker_set_thumbnail_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_set_custom_emoji_sticker_set_thumbnail_request_t post_set_custom_emoji_sticker_set_thumbnail_request_t;




typedef struct post_set_custom_emoji_sticker_set_thumbnail_request_t {
    char *name; // string
    char *custom_emoji_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} post_set_custom_emoji_sticker_set_thumbnail_request_t;

__attribute__((deprecated)) post_set_custom_emoji_sticker_set_thumbnail_request_t *post_set_custom_emoji_sticker_set_thumbnail_request_create(
    char *name,
    char *custom_emoji_id
);

void post_set_custom_emoji_sticker_set_thumbnail_request_free(post_set_custom_emoji_sticker_set_thumbnail_request_t *post_set_custom_emoji_sticker_set_thumbnail_request);

post_set_custom_emoji_sticker_set_thumbnail_request_t *post_set_custom_emoji_sticker_set_thumbnail_request_parseFromJSON(cJSON *post_set_custom_emoji_sticker_set_thumbnail_requestJSON);

cJSON *post_set_custom_emoji_sticker_set_thumbnail_request_convertToJSON(post_set_custom_emoji_sticker_set_thumbnail_request_t *post_set_custom_emoji_sticker_set_thumbnail_request);

#endif /* _post_set_custom_emoji_sticker_set_thumbnail_request_H_ */

