/*
 * _get_chat_menu_button_post_request.h
 *
 * 
 */

#ifndef __get_chat_menu_button_post_request_H_
#define __get_chat_menu_button_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _get_chat_menu_button_post_request_t _get_chat_menu_button_post_request_t;




typedef struct _get_chat_menu_button_post_request_t {
    int chat_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} _get_chat_menu_button_post_request_t;

__attribute__((deprecated)) _get_chat_menu_button_post_request_t *_get_chat_menu_button_post_request_create(
    int chat_id
);

void _get_chat_menu_button_post_request_free(_get_chat_menu_button_post_request_t *_get_chat_menu_button_post_request);

_get_chat_menu_button_post_request_t *_get_chat_menu_button_post_request_parseFromJSON(cJSON *_get_chat_menu_button_post_requestJSON);

cJSON *_get_chat_menu_button_post_request_convertToJSON(_get_chat_menu_button_post_request_t *_get_chat_menu_button_post_request);

#endif /* __get_chat_menu_button_post_request_H_ */

