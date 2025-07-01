/*
 * unique_gift_backdrop_colors.h
 *
 * This object describes the colors of the backdrop of a unique gift.
 */

#ifndef _unique_gift_backdrop_colors_H_
#define _unique_gift_backdrop_colors_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct unique_gift_backdrop_colors_t unique_gift_backdrop_colors_t;




typedef struct unique_gift_backdrop_colors_t {
    int center_color; //numeric
    int edge_color; //numeric
    int symbol_color; //numeric
    int text_color; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} unique_gift_backdrop_colors_t;

__attribute__((deprecated)) unique_gift_backdrop_colors_t *unique_gift_backdrop_colors_create(
    int center_color,
    int edge_color,
    int symbol_color,
    int text_color
);

void unique_gift_backdrop_colors_free(unique_gift_backdrop_colors_t *unique_gift_backdrop_colors);

unique_gift_backdrop_colors_t *unique_gift_backdrop_colors_parseFromJSON(cJSON *unique_gift_backdrop_colorsJSON);

cJSON *unique_gift_backdrop_colors_convertToJSON(unique_gift_backdrop_colors_t *unique_gift_backdrop_colors);

#endif /* _unique_gift_backdrop_colors_H_ */

