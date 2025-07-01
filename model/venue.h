/*
 * venue.h
 *
 * This object represents a venue.
 */

#ifndef _venue_H_
#define _venue_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct venue_t venue_t;

#include "location.h"



typedef struct venue_t {
    struct location_t *location; //model
    char *title; // string
    char *address; // string
    char *foursquare_id; // string
    char *foursquare_type; // string
    char *google_place_id; // string
    char *google_place_type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} venue_t;

__attribute__((deprecated)) venue_t *venue_create(
    location_t *location,
    char *title,
    char *address,
    char *foursquare_id,
    char *foursquare_type,
    char *google_place_id,
    char *google_place_type
);

void venue_free(venue_t *venue);

venue_t *venue_parseFromJSON(cJSON *venueJSON);

cJSON *venue_convertToJSON(venue_t *venue);

#endif /* _venue_H_ */

