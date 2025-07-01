/*
 * menu_button_default.h
 *
 * Describes that no specific value for the menu button was set.
 */

#ifndef _menu_button_default_H_
#define _menu_button_default_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct menu_button_default_t menu_button_default_t;




typedef struct menu_button_default_t {
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} menu_button_default_t;

__attribute__((deprecated)) menu_button_default_t *menu_button_default_create(
    char *type
);

void menu_button_default_free(menu_button_default_t *menu_button_default);

menu_button_default_t *menu_button_default_parseFromJSON(cJSON *menu_button_defaultJSON);

cJSON *menu_button_default_convertToJSON(menu_button_default_t *menu_button_default);

#endif /* _menu_button_default_H_ */

