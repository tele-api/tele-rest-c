/*
 * post_set_chat_menu_button_request.h
 *
 * 
 */

#ifndef _post_set_chat_menu_button_request_H_
#define _post_set_chat_menu_button_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_set_chat_menu_button_request_t post_set_chat_menu_button_request_t;

#include "menu_button.h"



typedef struct post_set_chat_menu_button_request_t {
    int chat_id; //numeric
    struct menu_button_t *menu_button; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_set_chat_menu_button_request_t;

__attribute__((deprecated)) post_set_chat_menu_button_request_t *post_set_chat_menu_button_request_create(
    int chat_id,
    menu_button_t *menu_button
);

void post_set_chat_menu_button_request_free(post_set_chat_menu_button_request_t *post_set_chat_menu_button_request);

post_set_chat_menu_button_request_t *post_set_chat_menu_button_request_parseFromJSON(cJSON *post_set_chat_menu_button_requestJSON);

cJSON *post_set_chat_menu_button_request_convertToJSON(post_set_chat_menu_button_request_t *post_set_chat_menu_button_request);

#endif /* _post_set_chat_menu_button_request_H_ */

