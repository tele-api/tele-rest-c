/*
 * inline_query_result_location.h
 *
 * Represents a location on a map. By default, the location will be sent by the user. Alternatively, you can use *input\\_message\\_content* to send a message with the specified content instead of the location.
 */

#ifndef _inline_query_result_location_H_
#define _inline_query_result_location_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_query_result_location_t inline_query_result_location_t;

#include "inline_keyboard_markup.h"
#include "input_message_content.h"



typedef struct inline_query_result_location_t {
    char *type; // string
    char *id; // string
    double latitude; //numeric
    double longitude; //numeric
    char *title; // string
    double horizontal_accuracy; //numeric
    int live_period; //numeric
    int heading; //numeric
    int proximity_alert_radius; //numeric
    struct inline_keyboard_markup_t *reply_markup; //model
    struct input_message_content_t *input_message_content; //model
    char *thumbnail_url; // string
    int thumbnail_width; //numeric
    int thumbnail_height; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} inline_query_result_location_t;

__attribute__((deprecated)) inline_query_result_location_t *inline_query_result_location_create(
    char *type,
    char *id,
    double latitude,
    double longitude,
    char *title,
    double horizontal_accuracy,
    int live_period,
    int heading,
    int proximity_alert_radius,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content,
    char *thumbnail_url,
    int thumbnail_width,
    int thumbnail_height
);

void inline_query_result_location_free(inline_query_result_location_t *inline_query_result_location);

inline_query_result_location_t *inline_query_result_location_parseFromJSON(cJSON *inline_query_result_locationJSON);

cJSON *inline_query_result_location_convertToJSON(inline_query_result_location_t *inline_query_result_location);

#endif /* _inline_query_result_location_H_ */

