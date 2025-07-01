/*
 * inline_query_result_game.h
 *
 * Represents a [Game](https://core.telegram.org/bots/api/#games).
 */

#ifndef _inline_query_result_game_H_
#define _inline_query_result_game_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_query_result_game_t inline_query_result_game_t;

#include "inline_keyboard_markup.h"



typedef struct inline_query_result_game_t {
    char *type; // string
    char *id; // string
    char *game_short_name; // string
    struct inline_keyboard_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} inline_query_result_game_t;

__attribute__((deprecated)) inline_query_result_game_t *inline_query_result_game_create(
    char *type,
    char *id,
    char *game_short_name,
    inline_keyboard_markup_t *reply_markup
);

void inline_query_result_game_free(inline_query_result_game_t *inline_query_result_game);

inline_query_result_game_t *inline_query_result_game_parseFromJSON(cJSON *inline_query_result_gameJSON);

cJSON *inline_query_result_game_convertToJSON(inline_query_result_game_t *inline_query_result_game);

#endif /* _inline_query_result_game_H_ */

