/*
 * giveaway_created.h
 *
 * This object represents a service message about the creation of a scheduled giveaway.
 */

#ifndef _giveaway_created_H_
#define _giveaway_created_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct giveaway_created_t giveaway_created_t;




typedef struct giveaway_created_t {
    int prize_star_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} giveaway_created_t;

__attribute__((deprecated)) giveaway_created_t *giveaway_created_create(
    int prize_star_count
);

void giveaway_created_free(giveaway_created_t *giveaway_created);

giveaway_created_t *giveaway_created_parseFromJSON(cJSON *giveaway_createdJSON);

cJSON *giveaway_created_convertToJSON(giveaway_created_t *giveaway_created);

#endif /* _giveaway_created_H_ */

