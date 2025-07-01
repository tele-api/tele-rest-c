/*
 * menu_button_commands.h
 *
 * Represents a menu button, which opens the bot&#39;s list of commands.
 */

#ifndef _menu_button_commands_H_
#define _menu_button_commands_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct menu_button_commands_t menu_button_commands_t;




typedef struct menu_button_commands_t {
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} menu_button_commands_t;

__attribute__((deprecated)) menu_button_commands_t *menu_button_commands_create(
    char *type
);

void menu_button_commands_free(menu_button_commands_t *menu_button_commands);

menu_button_commands_t *menu_button_commands_parseFromJSON(cJSON *menu_button_commandsJSON);

cJSON *menu_button_commands_convertToJSON(menu_button_commands_t *menu_button_commands);

#endif /* _menu_button_commands_H_ */

