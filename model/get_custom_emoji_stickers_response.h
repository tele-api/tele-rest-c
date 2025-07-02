/*
 * get_custom_emoji_stickers_response.h
 *
 * 
 */

#ifndef _get_custom_emoji_stickers_response_H_
#define _get_custom_emoji_stickers_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_custom_emoji_stickers_response_t get_custom_emoji_stickers_response_t;

#include "sticker.h"



typedef struct get_custom_emoji_stickers_response_t {
    int ok; //boolean
    list_t *result; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} get_custom_emoji_stickers_response_t;

__attribute__((deprecated)) get_custom_emoji_stickers_response_t *get_custom_emoji_stickers_response_create(
    int ok,
    list_t *result
);

void get_custom_emoji_stickers_response_free(get_custom_emoji_stickers_response_t *get_custom_emoji_stickers_response);

get_custom_emoji_stickers_response_t *get_custom_emoji_stickers_response_parseFromJSON(cJSON *get_custom_emoji_stickers_responseJSON);

cJSON *get_custom_emoji_stickers_response_convertToJSON(get_custom_emoji_stickers_response_t *get_custom_emoji_stickers_response);

#endif /* _get_custom_emoji_stickers_response_H_ */

