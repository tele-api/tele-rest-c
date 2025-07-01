/*
 * background_type_fill.h
 *
 * The background is automatically filled based on the selected colors.
 */

#ifndef _background_type_fill_H_
#define _background_type_fill_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct background_type_fill_t background_type_fill_t;

#include "background_fill.h"



typedef struct background_type_fill_t {
    char *type; // string
    struct background_fill_t *fill; //model
    int dark_theme_dimming; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} background_type_fill_t;

__attribute__((deprecated)) background_type_fill_t *background_type_fill_create(
    char *type,
    background_fill_t *fill,
    int dark_theme_dimming
);

void background_type_fill_free(background_type_fill_t *background_type_fill);

background_type_fill_t *background_type_fill_parseFromJSON(cJSON *background_type_fillJSON);

cJSON *background_type_fill_convertToJSON(background_type_fill_t *background_type_fill);

#endif /* _background_type_fill_H_ */

