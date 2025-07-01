/*
 * business_location.h
 *
 * Contains information about the location of a Telegram Business account.
 */

#ifndef _business_location_H_
#define _business_location_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct business_location_t business_location_t;

#include "location.h"



typedef struct business_location_t {
    char *address; // string
    struct location_t *location; //model

    int _library_owned; // Is the library responsible for freeing this object?
} business_location_t;

__attribute__((deprecated)) business_location_t *business_location_create(
    char *address,
    location_t *location
);

void business_location_free(business_location_t *business_location);

business_location_t *business_location_parseFromJSON(cJSON *business_locationJSON);

cJSON *business_location_convertToJSON(business_location_t *business_location);

#endif /* _business_location_H_ */

