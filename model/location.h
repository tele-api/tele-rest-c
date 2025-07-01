/*
 * location.h
 *
 * This object represents a point on the map.
 */

#ifndef _location_H_
#define _location_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct location_t location_t;




typedef struct location_t {
    double latitude; //numeric
    double longitude; //numeric
    double horizontal_accuracy; //numeric
    int live_period; //numeric
    int heading; //numeric
    int proximity_alert_radius; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} location_t;

__attribute__((deprecated)) location_t *location_create(
    double latitude,
    double longitude,
    double horizontal_accuracy,
    int live_period,
    int heading,
    int proximity_alert_radius
);

void location_free(location_t *location);

location_t *location_parseFromJSON(cJSON *locationJSON);

cJSON *location_convertToJSON(location_t *location);

#endif /* _location_H_ */

