/*
 * menu_button_web_app.h
 *
 * Represents a menu button, which launches a [Web App](https://core.telegram.org/bots/webapps).
 */

#ifndef _menu_button_web_app_H_
#define _menu_button_web_app_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct menu_button_web_app_t menu_button_web_app_t;

#include "web_app_info.h"



typedef struct menu_button_web_app_t {
    char *type; // string
    char *text; // string
    struct web_app_info_t *web_app; //model

    int _library_owned; // Is the library responsible for freeing this object?
} menu_button_web_app_t;

__attribute__((deprecated)) menu_button_web_app_t *menu_button_web_app_create(
    char *type,
    char *text,
    web_app_info_t *web_app
);

void menu_button_web_app_free(menu_button_web_app_t *menu_button_web_app);

menu_button_web_app_t *menu_button_web_app_parseFromJSON(cJSON *menu_button_web_appJSON);

cJSON *menu_button_web_app_convertToJSON(menu_button_web_app_t *menu_button_web_app);

#endif /* _menu_button_web_app_H_ */

