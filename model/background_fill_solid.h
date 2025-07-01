/*
 * background_fill_solid.h
 *
 * The background is filled using the selected color.
 */

#ifndef _background_fill_solid_H_
#define _background_fill_solid_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct background_fill_solid_t background_fill_solid_t;




typedef struct background_fill_solid_t {
    char *type; // string
    int color; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} background_fill_solid_t;

__attribute__((deprecated)) background_fill_solid_t *background_fill_solid_create(
    char *type,
    int color
);

void background_fill_solid_free(background_fill_solid_t *background_fill_solid);

background_fill_solid_t *background_fill_solid_parseFromJSON(cJSON *background_fill_solidJSON);

cJSON *background_fill_solid_convertToJSON(background_fill_solid_t *background_fill_solid);

#endif /* _background_fill_solid_H_ */

