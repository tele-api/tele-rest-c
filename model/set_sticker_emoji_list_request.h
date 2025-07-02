/*
 * set_sticker_emoji_list_request.h
 *
 * Request parameters for setStickerEmojiList
 */

#ifndef _set_sticker_emoji_list_request_H_
#define _set_sticker_emoji_list_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_sticker_emoji_list_request_t set_sticker_emoji_list_request_t;




typedef struct set_sticker_emoji_list_request_t {
    char *sticker; // string
    list_t *emoji_list; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} set_sticker_emoji_list_request_t;

__attribute__((deprecated)) set_sticker_emoji_list_request_t *set_sticker_emoji_list_request_create(
    char *sticker,
    list_t *emoji_list
);

void set_sticker_emoji_list_request_free(set_sticker_emoji_list_request_t *set_sticker_emoji_list_request);

set_sticker_emoji_list_request_t *set_sticker_emoji_list_request_parseFromJSON(cJSON *set_sticker_emoji_list_requestJSON);

cJSON *set_sticker_emoji_list_request_convertToJSON(set_sticker_emoji_list_request_t *set_sticker_emoji_list_request);

#endif /* _set_sticker_emoji_list_request_H_ */

