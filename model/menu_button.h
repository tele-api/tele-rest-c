/*
 * menu_button.h
 *
 * This object describes the bot&#39;s menu button in a private chat. It should be one of  * [MenuButtonCommands](https://core.telegram.org/bots/api/#menubuttoncommands) * [MenuButtonWebApp](https://core.telegram.org/bots/api/#menubuttonwebapp) * [MenuButtonDefault](https://core.telegram.org/bots/api/#menubuttondefault)
 */

#ifndef _menu_button_H_
#define _menu_button_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct menu_button_t menu_button_t;

#include "menu_button_commands.h"
#include "menu_button_default.h"
#include "menu_button_web_app.h"
#include "web_app_info.h"



typedef struct menu_button_t {
    char *type; // string
    char *text; // string
    struct web_app_info_t *web_app; //model

    int _library_owned; // Is the library responsible for freeing this object?
} menu_button_t;

__attribute__((deprecated)) menu_button_t *menu_button_create(
    char *type,
    char *text,
    web_app_info_t *web_app
);

void menu_button_free(menu_button_t *menu_button);

menu_button_t *menu_button_parseFromJSON(cJSON *menu_buttonJSON);

cJSON *menu_button_convertToJSON(menu_button_t *menu_button);

#endif /* _menu_button_H_ */

