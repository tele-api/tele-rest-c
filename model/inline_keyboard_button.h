/*
 * inline_keyboard_button.h
 *
 * This object represents one button of an inline keyboard. Exactly one of the optional fields must be used to specify type of the button.
 */

#ifndef _inline_keyboard_button_H_
#define _inline_keyboard_button_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_keyboard_button_t inline_keyboard_button_t;

#include "any_type.h"
#include "copy_text_button.h"
#include "login_url.h"
#include "switch_inline_query_chosen_chat.h"
#include "web_app_info.h"



typedef struct inline_keyboard_button_t {
    char *text; // string
    char *url; // string
    char *callback_data; // string
    struct web_app_info_t *web_app; //model
    struct login_url_t *login_url; //model
    char *switch_inline_query; // string
    char *switch_inline_query_current_chat; // string
    struct switch_inline_query_chosen_chat_t *switch_inline_query_chosen_chat; //model
    struct copy_text_button_t *copy_text; //model
    any_type_t *callback_game; // custom
    int pay; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} inline_keyboard_button_t;

__attribute__((deprecated)) inline_keyboard_button_t *inline_keyboard_button_create(
    char *text,
    char *url,
    char *callback_data,
    web_app_info_t *web_app,
    login_url_t *login_url,
    char *switch_inline_query,
    char *switch_inline_query_current_chat,
    switch_inline_query_chosen_chat_t *switch_inline_query_chosen_chat,
    copy_text_button_t *copy_text,
    any_type_t *callback_game,
    int pay
);

void inline_keyboard_button_free(inline_keyboard_button_t *inline_keyboard_button);

inline_keyboard_button_t *inline_keyboard_button_parseFromJSON(cJSON *inline_keyboard_buttonJSON);

cJSON *inline_keyboard_button_convertToJSON(inline_keyboard_button_t *inline_keyboard_button);

#endif /* _inline_keyboard_button_H_ */

