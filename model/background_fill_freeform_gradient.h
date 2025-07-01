/*
 * background_fill_freeform_gradient.h
 *
 * The background is a freeform gradient that rotates after every message in the chat.
 */

#ifndef _background_fill_freeform_gradient_H_
#define _background_fill_freeform_gradient_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct background_fill_freeform_gradient_t background_fill_freeform_gradient_t;




typedef struct background_fill_freeform_gradient_t {
    char *type; // string
    list_t *colors; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} background_fill_freeform_gradient_t;

__attribute__((deprecated)) background_fill_freeform_gradient_t *background_fill_freeform_gradient_create(
    char *type,
    list_t *colors
);

void background_fill_freeform_gradient_free(background_fill_freeform_gradient_t *background_fill_freeform_gradient);

background_fill_freeform_gradient_t *background_fill_freeform_gradient_parseFromJSON(cJSON *background_fill_freeform_gradientJSON);

cJSON *background_fill_freeform_gradient_convertToJSON(background_fill_freeform_gradient_t *background_fill_freeform_gradient);

#endif /* _background_fill_freeform_gradient_H_ */

