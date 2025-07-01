/*
 * inline_query_result_venue.h
 *
 * Represents a venue. By default, the venue will be sent by the user. Alternatively, you can use *input\\_message\\_content* to send a message with the specified content instead of the venue.
 */

#ifndef _inline_query_result_venue_H_
#define _inline_query_result_venue_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_query_result_venue_t inline_query_result_venue_t;

#include "inline_keyboard_markup.h"
#include "input_message_content.h"



typedef struct inline_query_result_venue_t {
    char *type; // string
    char *id; // string
    double latitude; //numeric
    double longitude; //numeric
    char *title; // string
    char *address; // string
    char *foursquare_id; // string
    char *foursquare_type; // string
    char *google_place_id; // string
    char *google_place_type; // string
    struct inline_keyboard_markup_t *reply_markup; //model
    struct input_message_content_t *input_message_content; //model
    char *thumbnail_url; // string
    int thumbnail_width; //numeric
    int thumbnail_height; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} inline_query_result_venue_t;

__attribute__((deprecated)) inline_query_result_venue_t *inline_query_result_venue_create(
    char *type,
    char *id,
    double latitude,
    double longitude,
    char *title,
    char *address,
    char *foursquare_id,
    char *foursquare_type,
    char *google_place_id,
    char *google_place_type,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content,
    char *thumbnail_url,
    int thumbnail_width,
    int thumbnail_height
);

void inline_query_result_venue_free(inline_query_result_venue_t *inline_query_result_venue);

inline_query_result_venue_t *inline_query_result_venue_parseFromJSON(cJSON *inline_query_result_venueJSON);

cJSON *inline_query_result_venue_convertToJSON(inline_query_result_venue_t *inline_query_result_venue);

#endif /* _inline_query_result_venue_H_ */

