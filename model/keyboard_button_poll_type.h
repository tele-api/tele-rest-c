/*
 * keyboard_button_poll_type.h
 *
 * This object represents type of a poll, which is allowed to be created and sent when the corresponding button is pressed.
 */

#ifndef _keyboard_button_poll_type_H_
#define _keyboard_button_poll_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct keyboard_button_poll_type_t keyboard_button_poll_type_t;




typedef struct keyboard_button_poll_type_t {
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} keyboard_button_poll_type_t;

__attribute__((deprecated)) keyboard_button_poll_type_t *keyboard_button_poll_type_create(
    char *type
);

void keyboard_button_poll_type_free(keyboard_button_poll_type_t *keyboard_button_poll_type);

keyboard_button_poll_type_t *keyboard_button_poll_type_parseFromJSON(cJSON *keyboard_button_poll_typeJSON);

cJSON *keyboard_button_poll_type_convertToJSON(keyboard_button_poll_type_t *keyboard_button_poll_type);

#endif /* _keyboard_button_poll_type_H_ */

