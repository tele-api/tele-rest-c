/*
 * sticker.h
 *
 * This object represents a sticker.
 */

#ifndef _sticker_H_
#define _sticker_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sticker_t sticker_t;

#include "file.h"
#include "mask_position.h"
#include "photo_size.h"

// Enum TYPE for sticker

typedef enum  { telegram_bot_api_sticker_TYPE_NULL = 0, telegram_bot_api_sticker_TYPE_regular, telegram_bot_api_sticker_TYPE_mask, telegram_bot_api_sticker_TYPE_custom_emoji } telegram_bot_api_sticker_TYPE_e;

char* sticker_type_ToString(telegram_bot_api_sticker_TYPE_e type);

telegram_bot_api_sticker_TYPE_e sticker_type_FromString(char* type);



typedef struct sticker_t {
    char *file_id; // string
    char *file_unique_id; // string
    telegram_bot_api_sticker_TYPE_e type; //enum
    int width; //numeric
    int height; //numeric
    int is_animated; //boolean
    int is_video; //boolean
    struct photo_size_t *thumbnail; //model
    char *emoji; // string
    char *set_name; // string
    struct binary_t*_t *premium_animation; //model
    struct mask_position_t *mask_position; //model
    char *custom_emoji_id; // string
    int needs_repainting; //boolean
    int file_size; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} sticker_t;

__attribute__((deprecated)) sticker_t *sticker_create(
    char *file_id,
    char *file_unique_id,
    telegram_bot_api_sticker_TYPE_e type,
    int width,
    int height,
    int is_animated,
    int is_video,
    photo_size_t *thumbnail,
    char *emoji,
    char *set_name,
    binary_t*_t *premium_animation,
    mask_position_t *mask_position,
    char *custom_emoji_id,
    int needs_repainting,
    int file_size
);

void sticker_free(sticker_t *sticker);

sticker_t *sticker_parseFromJSON(cJSON *stickerJSON);

cJSON *sticker_convertToJSON(sticker_t *sticker);

#endif /* _sticker_H_ */

