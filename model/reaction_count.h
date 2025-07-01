/*
 * reaction_count.h
 *
 * Represents a reaction added to a message along with the number of times it was added.
 */

#ifndef _reaction_count_H_
#define _reaction_count_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reaction_count_t reaction_count_t;

#include "reaction_type.h"



typedef struct reaction_count_t {
    struct reaction_type_t *type; //model
    int total_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} reaction_count_t;

__attribute__((deprecated)) reaction_count_t *reaction_count_create(
    reaction_type_t *type,
    int total_count
);

void reaction_count_free(reaction_count_t *reaction_count);

reaction_count_t *reaction_count_parseFromJSON(cJSON *reaction_countJSON);

cJSON *reaction_count_convertToJSON(reaction_count_t *reaction_count);

#endif /* _reaction_count_H_ */

