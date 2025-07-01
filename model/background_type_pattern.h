/*
 * background_type_pattern.h
 *
 * The background is a .PNG or .TGV (gzipped subset of SVG with MIME type “application/x-tgwallpattern”) pattern to be combined with the background fill chosen by the user.
 */

#ifndef _background_type_pattern_H_
#define _background_type_pattern_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct background_type_pattern_t background_type_pattern_t;

#include "background_fill.h"
#include "document.h"



typedef struct background_type_pattern_t {
    char *type; // string
    struct document_t *document; //model
    struct background_fill_t *fill; //model
    int intensity; //numeric
    int is_inverted; //boolean
    int is_moving; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} background_type_pattern_t;

__attribute__((deprecated)) background_type_pattern_t *background_type_pattern_create(
    char *type,
    document_t *document,
    background_fill_t *fill,
    int intensity,
    int is_inverted,
    int is_moving
);

void background_type_pattern_free(background_type_pattern_t *background_type_pattern);

background_type_pattern_t *background_type_pattern_parseFromJSON(cJSON *background_type_patternJSON);

cJSON *background_type_pattern_convertToJSON(background_type_pattern_t *background_type_pattern);

#endif /* _background_type_pattern_H_ */

