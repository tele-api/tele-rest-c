/*
 * get_custom_emoji_stickers_request.h
 *
 * Request parameters for getCustomEmojiStickers
 */

#ifndef _get_custom_emoji_stickers_request_H_
#define _get_custom_emoji_stickers_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_custom_emoji_stickers_request_t get_custom_emoji_stickers_request_t;




typedef struct get_custom_emoji_stickers_request_t {
    list_t *custom_emoji_ids; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} get_custom_emoji_stickers_request_t;

__attribute__((deprecated)) get_custom_emoji_stickers_request_t *get_custom_emoji_stickers_request_create(
    list_t *custom_emoji_ids
);

void get_custom_emoji_stickers_request_free(get_custom_emoji_stickers_request_t *get_custom_emoji_stickers_request);

get_custom_emoji_stickers_request_t *get_custom_emoji_stickers_request_parseFromJSON(cJSON *get_custom_emoji_stickers_requestJSON);

cJSON *get_custom_emoji_stickers_request_convertToJSON(get_custom_emoji_stickers_request_t *get_custom_emoji_stickers_request);

#endif /* _get_custom_emoji_stickers_request_H_ */

