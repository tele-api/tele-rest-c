/*
 * reaction_type_paid.h
 *
 * The reaction is paid.
 */

#ifndef _reaction_type_paid_H_
#define _reaction_type_paid_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reaction_type_paid_t reaction_type_paid_t;




typedef struct reaction_type_paid_t {
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} reaction_type_paid_t;

__attribute__((deprecated)) reaction_type_paid_t *reaction_type_paid_create(
    char *type
);

void reaction_type_paid_free(reaction_type_paid_t *reaction_type_paid);

reaction_type_paid_t *reaction_type_paid_parseFromJSON(cJSON *reaction_type_paidJSON);

cJSON *reaction_type_paid_convertToJSON(reaction_type_paid_t *reaction_type_paid);

#endif /* _reaction_type_paid_H_ */

