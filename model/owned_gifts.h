/*
 * owned_gifts.h
 *
 * Contains the list of gifts received and owned by a user or a chat.
 */

#ifndef _owned_gifts_H_
#define _owned_gifts_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct owned_gifts_t owned_gifts_t;

#include "owned_gift.h"



typedef struct owned_gifts_t {
    int total_count; //numeric
    list_t *gifts; //nonprimitive container
    char *next_offset; // string

    int _library_owned; // Is the library responsible for freeing this object?
} owned_gifts_t;

__attribute__((deprecated)) owned_gifts_t *owned_gifts_create(
    int total_count,
    list_t *gifts,
    char *next_offset
);

void owned_gifts_free(owned_gifts_t *owned_gifts);

owned_gifts_t *owned_gifts_parseFromJSON(cJSON *owned_giftsJSON);

cJSON *owned_gifts_convertToJSON(owned_gifts_t *owned_gifts);

#endif /* _owned_gifts_H_ */

