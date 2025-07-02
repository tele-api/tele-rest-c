/*
 * set_chat_menu_button_request.h
 *
 * Request parameters for setChatMenuButton
 */

#ifndef _set_chat_menu_button_request_H_
#define _set_chat_menu_button_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_chat_menu_button_request_t set_chat_menu_button_request_t;

#include "menu_button.h"



typedef struct set_chat_menu_button_request_t {
    int chat_id; //numeric
    struct menu_button_t *menu_button; //model

    int _library_owned; // Is the library responsible for freeing this object?
} set_chat_menu_button_request_t;

__attribute__((deprecated)) set_chat_menu_button_request_t *set_chat_menu_button_request_create(
    int chat_id,
    menu_button_t *menu_button
);

void set_chat_menu_button_request_free(set_chat_menu_button_request_t *set_chat_menu_button_request);

set_chat_menu_button_request_t *set_chat_menu_button_request_parseFromJSON(cJSON *set_chat_menu_button_requestJSON);

cJSON *set_chat_menu_button_request_convertToJSON(set_chat_menu_button_request_t *set_chat_menu_button_request);

#endif /* _set_chat_menu_button_request_H_ */

