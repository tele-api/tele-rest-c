/*
 * background_fill_gradient.h
 *
 * The background is a gradient fill.
 */

#ifndef _background_fill_gradient_H_
#define _background_fill_gradient_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct background_fill_gradient_t background_fill_gradient_t;




typedef struct background_fill_gradient_t {
    char *type; // string
    int top_color; //numeric
    int bottom_color; //numeric
    int rotation_angle; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} background_fill_gradient_t;

__attribute__((deprecated)) background_fill_gradient_t *background_fill_gradient_create(
    char *type,
    int top_color,
    int bottom_color,
    int rotation_angle
);

void background_fill_gradient_free(background_fill_gradient_t *background_fill_gradient);

background_fill_gradient_t *background_fill_gradient_parseFromJSON(cJSON *background_fill_gradientJSON);

cJSON *background_fill_gradient_convertToJSON(background_fill_gradient_t *background_fill_gradient);

#endif /* _background_fill_gradient_H_ */

