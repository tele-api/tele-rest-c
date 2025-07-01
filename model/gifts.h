/*
 * gifts.h
 *
 * This object represent a list of gifts.
 */

#ifndef _gifts_H_
#define _gifts_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gifts_t gifts_t;

#include "gift.h"



typedef struct gifts_t {
    list_t *gifts; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} gifts_t;

__attribute__((deprecated)) gifts_t *gifts_create(
    list_t *gifts
);

void gifts_free(gifts_t *gifts);

gifts_t *gifts_parseFromJSON(cJSON *giftsJSON);

cJSON *gifts_convertToJSON(gifts_t *gifts);

#endif /* _gifts_H_ */

