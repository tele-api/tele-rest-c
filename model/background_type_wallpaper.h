/*
 * background_type_wallpaper.h
 *
 * The background is a wallpaper in the JPEG format.
 */

#ifndef _background_type_wallpaper_H_
#define _background_type_wallpaper_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct background_type_wallpaper_t background_type_wallpaper_t;

#include "document.h"



typedef struct background_type_wallpaper_t {
    char *type; // string
    struct document_t *document; //model
    int dark_theme_dimming; //numeric
    int is_blurred; //boolean
    int is_moving; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} background_type_wallpaper_t;

__attribute__((deprecated)) background_type_wallpaper_t *background_type_wallpaper_create(
    char *type,
    document_t *document,
    int dark_theme_dimming,
    int is_blurred,
    int is_moving
);

void background_type_wallpaper_free(background_type_wallpaper_t *background_type_wallpaper);

background_type_wallpaper_t *background_type_wallpaper_parseFromJSON(cJSON *background_type_wallpaperJSON);

cJSON *background_type_wallpaper_convertToJSON(background_type_wallpaper_t *background_type_wallpaper);

#endif /* _background_type_wallpaper_H_ */

