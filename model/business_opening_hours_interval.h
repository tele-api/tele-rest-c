/*
 * business_opening_hours_interval.h
 *
 * Describes an interval of time during which a business is open.
 */

#ifndef _business_opening_hours_interval_H_
#define _business_opening_hours_interval_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct business_opening_hours_interval_t business_opening_hours_interval_t;




typedef struct business_opening_hours_interval_t {
    int opening_minute; //numeric
    int closing_minute; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} business_opening_hours_interval_t;

__attribute__((deprecated)) business_opening_hours_interval_t *business_opening_hours_interval_create(
    int opening_minute,
    int closing_minute
);

void business_opening_hours_interval_free(business_opening_hours_interval_t *business_opening_hours_interval);

business_opening_hours_interval_t *business_opening_hours_interval_parseFromJSON(cJSON *business_opening_hours_intervalJSON);

cJSON *business_opening_hours_interval_convertToJSON(business_opening_hours_interval_t *business_opening_hours_interval);

#endif /* _business_opening_hours_interval_H_ */

