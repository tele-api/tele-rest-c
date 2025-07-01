/*
 * unique_gift_backdrop.h
 *
 * This object describes the backdrop of a unique gift.
 */

#ifndef _unique_gift_backdrop_H_
#define _unique_gift_backdrop_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct unique_gift_backdrop_t unique_gift_backdrop_t;

#include "unique_gift_backdrop_colors.h"



typedef struct unique_gift_backdrop_t {
    char *name; // string
    struct unique_gift_backdrop_colors_t *colors; //model
    int rarity_per_mille; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} unique_gift_backdrop_t;

__attribute__((deprecated)) unique_gift_backdrop_t *unique_gift_backdrop_create(
    char *name,
    unique_gift_backdrop_colors_t *colors,
    int rarity_per_mille
);

void unique_gift_backdrop_free(unique_gift_backdrop_t *unique_gift_backdrop);

unique_gift_backdrop_t *unique_gift_backdrop_parseFromJSON(cJSON *unique_gift_backdropJSON);

cJSON *unique_gift_backdrop_convertToJSON(unique_gift_backdrop_t *unique_gift_backdrop);

#endif /* _unique_gift_backdrop_H_ */

