/*
 * business_opening_hours.h
 *
 * Describes the opening hours of a business.
 */

#ifndef _business_opening_hours_H_
#define _business_opening_hours_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct business_opening_hours_t business_opening_hours_t;

#include "business_opening_hours_interval.h"



typedef struct business_opening_hours_t {
    char *time_zone_name; // string
    list_t *opening_hours; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} business_opening_hours_t;

__attribute__((deprecated)) business_opening_hours_t *business_opening_hours_create(
    char *time_zone_name,
    list_t *opening_hours
);

void business_opening_hours_free(business_opening_hours_t *business_opening_hours);

business_opening_hours_t *business_opening_hours_parseFromJSON(cJSON *business_opening_hoursJSON);

cJSON *business_opening_hours_convertToJSON(business_opening_hours_t *business_opening_hours);

#endif /* _business_opening_hours_H_ */

