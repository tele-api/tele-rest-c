/*
 * sticker_set.h
 *
 * This object represents a sticker set.
 */

#ifndef _sticker_set_H_
#define _sticker_set_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sticker_set_t sticker_set_t;

#include "photo_size.h"
#include "sticker.h"

// Enum STICKERTYPE for sticker_set

typedef enum  { telegram_bot_api_sticker_set_STICKERTYPE_NULL = 0, telegram_bot_api_sticker_set_STICKERTYPE_regular, telegram_bot_api_sticker_set_STICKERTYPE_mask, telegram_bot_api_sticker_set_STICKERTYPE_custom_emoji } telegram_bot_api_sticker_set_STICKERTYPE_e;

char* sticker_set_sticker_type_ToString(telegram_bot_api_sticker_set_STICKERTYPE_e sticker_type);

telegram_bot_api_sticker_set_STICKERTYPE_e sticker_set_sticker_type_FromString(char* sticker_type);



typedef struct sticker_set_t {
    char *name; // string
    char *title; // string
    telegram_bot_api_sticker_set_STICKERTYPE_e sticker_type; //enum
    list_t *stickers; //nonprimitive container
    struct photo_size_t *thumbnail; //model

    int _library_owned; // Is the library responsible for freeing this object?
} sticker_set_t;

__attribute__((deprecated)) sticker_set_t *sticker_set_create(
    char *name,
    char *title,
    telegram_bot_api_sticker_set_STICKERTYPE_e sticker_type,
    list_t *stickers,
    photo_size_t *thumbnail
);

void sticker_set_free(sticker_set_t *sticker_set);

sticker_set_t *sticker_set_parseFromJSON(cJSON *sticker_setJSON);

cJSON *sticker_set_convertToJSON(sticker_set_t *sticker_set);

#endif /* _sticker_set_H_ */

