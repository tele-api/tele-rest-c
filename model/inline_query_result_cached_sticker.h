/*
 * inline_query_result_cached_sticker.h
 *
 * Represents a link to a sticker stored on the Telegram servers. By default, this sticker will be sent by the user. Alternatively, you can use *input\\_message\\_content* to send a message with the specified content instead of the sticker.
 */

#ifndef _inline_query_result_cached_sticker_H_
#define _inline_query_result_cached_sticker_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_query_result_cached_sticker_t inline_query_result_cached_sticker_t;

#include "inline_keyboard_markup.h"
#include "input_message_content.h"



typedef struct inline_query_result_cached_sticker_t {
    char *type; // string
    char *id; // string
    char *sticker_file_id; // string
    struct inline_keyboard_markup_t *reply_markup; //model
    struct input_message_content_t *input_message_content; //model

    int _library_owned; // Is the library responsible for freeing this object?
} inline_query_result_cached_sticker_t;

__attribute__((deprecated)) inline_query_result_cached_sticker_t *inline_query_result_cached_sticker_create(
    char *type,
    char *id,
    char *sticker_file_id,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
);

void inline_query_result_cached_sticker_free(inline_query_result_cached_sticker_t *inline_query_result_cached_sticker);

inline_query_result_cached_sticker_t *inline_query_result_cached_sticker_parseFromJSON(cJSON *inline_query_result_cached_stickerJSON);

cJSON *inline_query_result_cached_sticker_convertToJSON(inline_query_result_cached_sticker_t *inline_query_result_cached_sticker);

#endif /* _inline_query_result_cached_sticker_H_ */

