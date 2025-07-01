/*
 * background_fill.h
 *
 * This object describes the way a background is filled based on the selected colors. Currently, it can be one of  * [BackgroundFillSolid](https://core.telegram.org/bots/api/#backgroundfillsolid) * [BackgroundFillGradient](https://core.telegram.org/bots/api/#backgroundfillgradient) * [BackgroundFillFreeformGradient](https://core.telegram.org/bots/api/#backgroundfillfreeformgradient)
 */

#ifndef _background_fill_H_
#define _background_fill_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct background_fill_t background_fill_t;

#include "background_fill_freeform_gradient.h"
#include "background_fill_gradient.h"
#include "background_fill_solid.h"



typedef struct background_fill_t {
    char *type; // string
    int color; //numeric
    int top_color; //numeric
    int bottom_color; //numeric
    int rotation_angle; //numeric
    list_t *colors; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} background_fill_t;

__attribute__((deprecated)) background_fill_t *background_fill_create(
    char *type,
    int color,
    int top_color,
    int bottom_color,
    int rotation_angle,
    list_t *colors
);

void background_fill_free(background_fill_t *background_fill);

background_fill_t *background_fill_parseFromJSON(cJSON *background_fillJSON);

cJSON *background_fill_convertToJSON(background_fill_t *background_fill);

#endif /* _background_fill_H_ */

