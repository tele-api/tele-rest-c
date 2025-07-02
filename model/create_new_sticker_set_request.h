/*
 * create_new_sticker_set_request.h
 *
 * Request parameters for createNewStickerSet
 */

#ifndef _create_new_sticker_set_request_H_
#define _create_new_sticker_set_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_new_sticker_set_request_t create_new_sticker_set_request_t;

#include "input_sticker.h"

// Enum STICKERTYPE for create_new_sticker_set_request

typedef enum  { telegram_bot_api_create_new_sticker_set_request_STICKERTYPE_NULL = 0, telegram_bot_api_create_new_sticker_set_request_STICKERTYPE_mask, telegram_bot_api_create_new_sticker_set_request_STICKERTYPE_custom_emoji } telegram_bot_api_create_new_sticker_set_request_STICKERTYPE_e;

char* create_new_sticker_set_request_sticker_type_ToString(telegram_bot_api_create_new_sticker_set_request_STICKERTYPE_e sticker_type);

telegram_bot_api_create_new_sticker_set_request_STICKERTYPE_e create_new_sticker_set_request_sticker_type_FromString(char* sticker_type);



typedef struct create_new_sticker_set_request_t {
    int user_id; //numeric
    char *name; // string
    char *title; // string
    list_t *stickers; //nonprimitive container
    telegram_bot_api_create_new_sticker_set_request_STICKERTYPE_e sticker_type; //enum
    int needs_repainting; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} create_new_sticker_set_request_t;

__attribute__((deprecated)) create_new_sticker_set_request_t *create_new_sticker_set_request_create(
    int user_id,
    char *name,
    char *title,
    list_t *stickers,
    telegram_bot_api_create_new_sticker_set_request_STICKERTYPE_e sticker_type,
    int needs_repainting
);

void create_new_sticker_set_request_free(create_new_sticker_set_request_t *create_new_sticker_set_request);

create_new_sticker_set_request_t *create_new_sticker_set_request_parseFromJSON(cJSON *create_new_sticker_set_requestJSON);

cJSON *create_new_sticker_set_request_convertToJSON(create_new_sticker_set_request_t *create_new_sticker_set_request);

#endif /* _create_new_sticker_set_request_H_ */

