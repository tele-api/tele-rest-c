/*
 * set_custom_emoji_sticker_set_thumbnail_response.h
 *
 * 
 */

#ifndef _set_custom_emoji_sticker_set_thumbnail_response_H_
#define _set_custom_emoji_sticker_set_thumbnail_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_custom_emoji_sticker_set_thumbnail_response_t set_custom_emoji_sticker_set_thumbnail_response_t;




typedef struct set_custom_emoji_sticker_set_thumbnail_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} set_custom_emoji_sticker_set_thumbnail_response_t;

__attribute__((deprecated)) set_custom_emoji_sticker_set_thumbnail_response_t *set_custom_emoji_sticker_set_thumbnail_response_create(
    int ok,
    int result
);

void set_custom_emoji_sticker_set_thumbnail_response_free(set_custom_emoji_sticker_set_thumbnail_response_t *set_custom_emoji_sticker_set_thumbnail_response);

set_custom_emoji_sticker_set_thumbnail_response_t *set_custom_emoji_sticker_set_thumbnail_response_parseFromJSON(cJSON *set_custom_emoji_sticker_set_thumbnail_responseJSON);

cJSON *set_custom_emoji_sticker_set_thumbnail_response_convertToJSON(set_custom_emoji_sticker_set_thumbnail_response_t *set_custom_emoji_sticker_set_thumbnail_response);

#endif /* _set_custom_emoji_sticker_set_thumbnail_response_H_ */

