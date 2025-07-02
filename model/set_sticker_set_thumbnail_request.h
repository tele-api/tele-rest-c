/*
 * set_sticker_set_thumbnail_request.h
 *
 * Request parameters for setStickerSetThumbnail
 */

#ifndef _set_sticker_set_thumbnail_request_H_
#define _set_sticker_set_thumbnail_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_sticker_set_thumbnail_request_t set_sticker_set_thumbnail_request_t;


// Enum FORMAT for set_sticker_set_thumbnail_request

typedef enum  { telegram_bot_api_set_sticker_set_thumbnail_request_FORMAT_NULL = 0, telegram_bot_api_set_sticker_set_thumbnail_request_FORMAT__static, telegram_bot_api_set_sticker_set_thumbnail_request_FORMAT_animated, telegram_bot_api_set_sticker_set_thumbnail_request_FORMAT_video } telegram_bot_api_set_sticker_set_thumbnail_request_FORMAT_e;

char* set_sticker_set_thumbnail_request_format_ToString(telegram_bot_api_set_sticker_set_thumbnail_request_FORMAT_e format);

telegram_bot_api_set_sticker_set_thumbnail_request_FORMAT_e set_sticker_set_thumbnail_request_format_FromString(char* format);



typedef struct set_sticker_set_thumbnail_request_t {
    char *name; // string
    int user_id; //numeric
    telegram_bot_api_set_sticker_set_thumbnail_request_FORMAT_e format; //enum
    char *thumbnail; // string

    int _library_owned; // Is the library responsible for freeing this object?
} set_sticker_set_thumbnail_request_t;

__attribute__((deprecated)) set_sticker_set_thumbnail_request_t *set_sticker_set_thumbnail_request_create(
    char *name,
    int user_id,
    telegram_bot_api_set_sticker_set_thumbnail_request_FORMAT_e format,
    char *thumbnail
);

void set_sticker_set_thumbnail_request_free(set_sticker_set_thumbnail_request_t *set_sticker_set_thumbnail_request);

set_sticker_set_thumbnail_request_t *set_sticker_set_thumbnail_request_parseFromJSON(cJSON *set_sticker_set_thumbnail_requestJSON);

cJSON *set_sticker_set_thumbnail_request_convertToJSON(set_sticker_set_thumbnail_request_t *set_sticker_set_thumbnail_request);

#endif /* _set_sticker_set_thumbnail_request_H_ */

