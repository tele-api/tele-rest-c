/*
 * get_chat_menu_button_request.h
 *
 * Request parameters for getChatMenuButton
 */

#ifndef _get_chat_menu_button_request_H_
#define _get_chat_menu_button_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_chat_menu_button_request_t get_chat_menu_button_request_t;




typedef struct get_chat_menu_button_request_t {
    int chat_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} get_chat_menu_button_request_t;

__attribute__((deprecated)) get_chat_menu_button_request_t *get_chat_menu_button_request_create(
    int chat_id
);

void get_chat_menu_button_request_free(get_chat_menu_button_request_t *get_chat_menu_button_request);

get_chat_menu_button_request_t *get_chat_menu_button_request_parseFromJSON(cJSON *get_chat_menu_button_requestJSON);

cJSON *get_chat_menu_button_request_convertToJSON(get_chat_menu_button_request_t *get_chat_menu_button_request);

#endif /* _get_chat_menu_button_request_H_ */

