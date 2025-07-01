/*
 * keyboard_button.h
 *
 * This object represents one button of the reply keyboard. At most one of the optional fields must be used to specify type of the button. For simple text buttons, *String* can be used instead of this object to specify the button text.
 */

#ifndef _keyboard_button_H_
#define _keyboard_button_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct keyboard_button_t keyboard_button_t;

#include "keyboard_button_poll_type.h"
#include "keyboard_button_request_chat.h"
#include "keyboard_button_request_users.h"
#include "web_app_info.h"



typedef struct keyboard_button_t {
    char *text; // string
    struct keyboard_button_request_users_t *request_users; //model
    struct keyboard_button_request_chat_t *request_chat; //model
    int request_contact; //boolean
    int request_location; //boolean
    struct keyboard_button_poll_type_t *request_poll; //model
    struct web_app_info_t *web_app; //model

    int _library_owned; // Is the library responsible for freeing this object?
} keyboard_button_t;

__attribute__((deprecated)) keyboard_button_t *keyboard_button_create(
    char *text,
    keyboard_button_request_users_t *request_users,
    keyboard_button_request_chat_t *request_chat,
    int request_contact,
    int request_location,
    keyboard_button_poll_type_t *request_poll,
    web_app_info_t *web_app
);

void keyboard_button_free(keyboard_button_t *keyboard_button);

keyboard_button_t *keyboard_button_parseFromJSON(cJSON *keyboard_buttonJSON);

cJSON *keyboard_button_convertToJSON(keyboard_button_t *keyboard_button);

#endif /* _keyboard_button_H_ */

