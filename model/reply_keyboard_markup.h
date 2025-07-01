/*
 * reply_keyboard_markup.h
 *
 * This object represents a [custom keyboard](https://core.telegram.org/bots/features#keyboards) with reply options (see [Introduction to bots](https://core.telegram.org/bots/features#keyboards) for details and examples). Not supported in channels and for messages sent on behalf of a Telegram Business account.
 */

#ifndef _reply_keyboard_markup_H_
#define _reply_keyboard_markup_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reply_keyboard_markup_t reply_keyboard_markup_t;

#include "keyboard_button.h"



typedef struct reply_keyboard_markup_t {
    list_t *keyboard; //primitive container
    int is_persistent; //boolean
    int resize_keyboard; //boolean
    int one_time_keyboard; //boolean
    char *input_field_placeholder; // string
    int selective; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} reply_keyboard_markup_t;

__attribute__((deprecated)) reply_keyboard_markup_t *reply_keyboard_markup_create(
    list_t *keyboard,
    int is_persistent,
    int resize_keyboard,
    int one_time_keyboard,
    char *input_field_placeholder,
    int selective
);

void reply_keyboard_markup_free(reply_keyboard_markup_t *reply_keyboard_markup);

reply_keyboard_markup_t *reply_keyboard_markup_parseFromJSON(cJSON *reply_keyboard_markupJSON);

cJSON *reply_keyboard_markup_convertToJSON(reply_keyboard_markup_t *reply_keyboard_markup);

#endif /* _reply_keyboard_markup_H_ */

