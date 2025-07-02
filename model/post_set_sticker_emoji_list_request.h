/*
 * post_set_sticker_emoji_list_request.h
 *
 * 
 */

#ifndef _post_set_sticker_emoji_list_request_H_
#define _post_set_sticker_emoji_list_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_set_sticker_emoji_list_request_t post_set_sticker_emoji_list_request_t;




typedef struct post_set_sticker_emoji_list_request_t {
    char *sticker; // string
    list_t *emoji_list; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} post_set_sticker_emoji_list_request_t;

__attribute__((deprecated)) post_set_sticker_emoji_list_request_t *post_set_sticker_emoji_list_request_create(
    char *sticker,
    list_t *emoji_list
);

void post_set_sticker_emoji_list_request_free(post_set_sticker_emoji_list_request_t *post_set_sticker_emoji_list_request);

post_set_sticker_emoji_list_request_t *post_set_sticker_emoji_list_request_parseFromJSON(cJSON *post_set_sticker_emoji_list_requestJSON);

cJSON *post_set_sticker_emoji_list_request_convertToJSON(post_set_sticker_emoji_list_request_t *post_set_sticker_emoji_list_request);

#endif /* _post_set_sticker_emoji_list_request_H_ */

