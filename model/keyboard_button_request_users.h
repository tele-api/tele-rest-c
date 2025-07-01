/*
 * keyboard_button_request_users.h
 *
 * This object defines the criteria used to request suitable users. Information about the selected users will be shared with the bot when the corresponding button is pressed. [More about requesting users »](https://core.telegram.org/bots/features#chat-and-user-selection)
 */

#ifndef _keyboard_button_request_users_H_
#define _keyboard_button_request_users_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct keyboard_button_request_users_t keyboard_button_request_users_t;




typedef struct keyboard_button_request_users_t {
    int request_id; //numeric
    int user_is_bot; //boolean
    int user_is_premium; //boolean
    int max_quantity; //numeric
    int request_name; //boolean
    int request_username; //boolean
    int request_photo; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} keyboard_button_request_users_t;

__attribute__((deprecated)) keyboard_button_request_users_t *keyboard_button_request_users_create(
    int request_id,
    int user_is_bot,
    int user_is_premium,
    int max_quantity,
    int request_name,
    int request_username,
    int request_photo
);

void keyboard_button_request_users_free(keyboard_button_request_users_t *keyboard_button_request_users);

keyboard_button_request_users_t *keyboard_button_request_users_parseFromJSON(cJSON *keyboard_button_request_usersJSON);

cJSON *keyboard_button_request_users_convertToJSON(keyboard_button_request_users_t *keyboard_button_request_users);

#endif /* _keyboard_button_request_users_H_ */

