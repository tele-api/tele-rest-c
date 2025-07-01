/*
 * input_venue_message_content.h
 *
 * Represents the [content](https://core.telegram.org/bots/api/#inputmessagecontent) of a venue message to be sent as the result of an inline query.
 */

#ifndef _input_venue_message_content_H_
#define _input_venue_message_content_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_venue_message_content_t input_venue_message_content_t;




typedef struct input_venue_message_content_t {
    double latitude; //numeric
    double longitude; //numeric
    char *title; // string
    char *address; // string
    char *foursquare_id; // string
    char *foursquare_type; // string
    char *google_place_id; // string
    char *google_place_type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} input_venue_message_content_t;

__attribute__((deprecated)) input_venue_message_content_t *input_venue_message_content_create(
    double latitude,
    double longitude,
    char *title,
    char *address,
    char *foursquare_id,
    char *foursquare_type,
    char *google_place_id,
    char *google_place_type
);

void input_venue_message_content_free(input_venue_message_content_t *input_venue_message_content);

input_venue_message_content_t *input_venue_message_content_parseFromJSON(cJSON *input_venue_message_contentJSON);

cJSON *input_venue_message_content_convertToJSON(input_venue_message_content_t *input_venue_message_content);

#endif /* _input_venue_message_content_H_ */

