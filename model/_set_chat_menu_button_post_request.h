/*
 * _set_chat_menu_button_post_request.h
 *
 * 
 */

#ifndef __set_chat_menu_button_post_request_H_
#define __set_chat_menu_button_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _set_chat_menu_button_post_request_t _set_chat_menu_button_post_request_t;

#include "menu_button.h"



typedef struct _set_chat_menu_button_post_request_t {
    int chat_id; //numeric
    struct menu_button_t *menu_button; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _set_chat_menu_button_post_request_t;

__attribute__((deprecated)) _set_chat_menu_button_post_request_t *_set_chat_menu_button_post_request_create(
    int chat_id,
    menu_button_t *menu_button
);

void _set_chat_menu_button_post_request_free(_set_chat_menu_button_post_request_t *_set_chat_menu_button_post_request);

_set_chat_menu_button_post_request_t *_set_chat_menu_button_post_request_parseFromJSON(cJSON *_set_chat_menu_button_post_requestJSON);

cJSON *_set_chat_menu_button_post_request_convertToJSON(_set_chat_menu_button_post_request_t *_set_chat_menu_button_post_request);

#endif /* __set_chat_menu_button_post_request_H_ */

