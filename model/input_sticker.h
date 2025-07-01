/*
 * input_sticker.h
 *
 * This object describes a sticker to be added to a sticker set.
 */

#ifndef _input_sticker_H_
#define _input_sticker_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_sticker_t input_sticker_t;

#include "mask_position.h"

// Enum FORMAT for input_sticker

typedef enum  { telegram_bot_api_input_sticker_FORMAT_NULL = 0, telegram_bot_api_input_sticker_FORMAT__static, telegram_bot_api_input_sticker_FORMAT_animated, telegram_bot_api_input_sticker_FORMAT_video } telegram_bot_api_input_sticker_FORMAT_e;

char* input_sticker_format_ToString(telegram_bot_api_input_sticker_FORMAT_e format);

telegram_bot_api_input_sticker_FORMAT_e input_sticker_format_FromString(char* format);



typedef struct input_sticker_t {
    char *sticker; // string
    telegram_bot_api_input_sticker_FORMAT_e format; //enum
    list_t *emoji_list; //primitive container
    struct mask_position_t *mask_position; //model
    list_t *keywords; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} input_sticker_t;

__attribute__((deprecated)) input_sticker_t *input_sticker_create(
    char *sticker,
    telegram_bot_api_input_sticker_FORMAT_e format,
    list_t *emoji_list,
    mask_position_t *mask_position,
    list_t *keywords
);

void input_sticker_free(input_sticker_t *input_sticker);

input_sticker_t *input_sticker_parseFromJSON(cJSON *input_stickerJSON);

cJSON *input_sticker_convertToJSON(input_sticker_t *input_sticker);

#endif /* _input_sticker_H_ */

