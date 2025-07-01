/*
 * location_address.h
 *
 * Describes the physical address of a location.
 */

#ifndef _location_address_H_
#define _location_address_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct location_address_t location_address_t;




typedef struct location_address_t {
    char *country_code; // string
    char *state; // string
    char *city; // string
    char *street; // string

    int _library_owned; // Is the library responsible for freeing this object?
} location_address_t;

__attribute__((deprecated)) location_address_t *location_address_create(
    char *country_code,
    char *state,
    char *city,
    char *street
);

void location_address_free(location_address_t *location_address);

location_address_t *location_address_parseFromJSON(cJSON *location_addressJSON);

cJSON *location_address_convertToJSON(location_address_t *location_address);

#endif /* _location_address_H_ */

