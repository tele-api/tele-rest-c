/*
 * inline_keyboard_markup.h
 *
 * This object represents an [inline keyboard](https://core.telegram.org/bots/features#inline-keyboards) that appears right next to the message it belongs to.
 */

#ifndef _inline_keyboard_markup_H_
#define _inline_keyboard_markup_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_keyboard_markup_t inline_keyboard_markup_t;

#include "inline_keyboard_button.h"



typedef struct inline_keyboard_markup_t {
    list_t *inline_keyboard; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} inline_keyboard_markup_t;

__attribute__((deprecated)) inline_keyboard_markup_t *inline_keyboard_markup_create(
    list_t *inline_keyboard
);

void inline_keyboard_markup_free(inline_keyboard_markup_t *inline_keyboard_markup);

inline_keyboard_markup_t *inline_keyboard_markup_parseFromJSON(cJSON *inline_keyboard_markupJSON);

cJSON *inline_keyboard_markup_convertToJSON(inline_keyboard_markup_t *inline_keyboard_markup);

#endif /* _inline_keyboard_markup_H_ */

