/*
 * post_get_custom_emoji_stickers_request.h
 *
 * 
 */

#ifndef _post_get_custom_emoji_stickers_request_H_
#define _post_get_custom_emoji_stickers_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_get_custom_emoji_stickers_request_t post_get_custom_emoji_stickers_request_t;




typedef struct post_get_custom_emoji_stickers_request_t {
    list_t *custom_emoji_ids; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} post_get_custom_emoji_stickers_request_t;

__attribute__((deprecated)) post_get_custom_emoji_stickers_request_t *post_get_custom_emoji_stickers_request_create(
    list_t *custom_emoji_ids
);

void post_get_custom_emoji_stickers_request_free(post_get_custom_emoji_stickers_request_t *post_get_custom_emoji_stickers_request);

post_get_custom_emoji_stickers_request_t *post_get_custom_emoji_stickers_request_parseFromJSON(cJSON *post_get_custom_emoji_stickers_requestJSON);

cJSON *post_get_custom_emoji_stickers_request_convertToJSON(post_get_custom_emoji_stickers_request_t *post_get_custom_emoji_stickers_request);

#endif /* _post_get_custom_emoji_stickers_request_H_ */

