/*
 * story_area_type_location.h
 *
 * Describes a story area pointing to a location. Currently, a story can have up to 10 location areas.
 */

#ifndef _story_area_type_location_H_
#define _story_area_type_location_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct story_area_type_location_t story_area_type_location_t;

#include "location_address.h"



typedef struct story_area_type_location_t {
    char *type; // string
    double latitude; //numeric
    double longitude; //numeric
    struct location_address_t *address; //model

    int _library_owned; // Is the library responsible for freeing this object?
} story_area_type_location_t;

__attribute__((deprecated)) story_area_type_location_t *story_area_type_location_create(
    char *type,
    double latitude,
    double longitude,
    location_address_t *address
);

void story_area_type_location_free(story_area_type_location_t *story_area_type_location);

story_area_type_location_t *story_area_type_location_parseFromJSON(cJSON *story_area_type_locationJSON);

cJSON *story_area_type_location_convertToJSON(story_area_type_location_t *story_area_type_location);

#endif /* _story_area_type_location_H_ */

