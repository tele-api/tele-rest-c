/*
 * background_type.h
 *
 * This object describes the type of a background. Currently, it can be one of  * [BackgroundTypeFill](https://core.telegram.org/bots/api/#backgroundtypefill) * [BackgroundTypeWallpaper](https://core.telegram.org/bots/api/#backgroundtypewallpaper) * [BackgroundTypePattern](https://core.telegram.org/bots/api/#backgroundtypepattern) * [BackgroundTypeChatTheme](https://core.telegram.org/bots/api/#backgroundtypechattheme)
 */

#ifndef _background_type_H_
#define _background_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct background_type_t background_type_t;

#include "background_fill.h"
#include "background_type_chat_theme.h"
#include "background_type_fill.h"
#include "background_type_pattern.h"
#include "background_type_wallpaper.h"
#include "document.h"



typedef struct background_type_t {
    char *type; // string
    struct background_fill_t *fill; //model
    int dark_theme_dimming; //numeric
    struct document_t *document; //model
    int intensity; //numeric
    char *theme_name; // string
    int is_blurred; //boolean
    int is_moving; //boolean
    int is_inverted; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} background_type_t;

__attribute__((deprecated)) background_type_t *background_type_create(
    char *type,
    background_fill_t *fill,
    int dark_theme_dimming,
    document_t *document,
    int intensity,
    char *theme_name,
    int is_blurred,
    int is_moving,
    int is_inverted
);

void background_type_free(background_type_t *background_type);

background_type_t *background_type_parseFromJSON(cJSON *background_typeJSON);

cJSON *background_type_convertToJSON(background_type_t *background_type);

#endif /* _background_type_H_ */

