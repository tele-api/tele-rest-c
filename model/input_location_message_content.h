/*
 * input_location_message_content.h
 *
 * Represents the [content](https://core.telegram.org/bots/api/#inputmessagecontent) of a location message to be sent as the result of an inline query.
 */

#ifndef _input_location_message_content_H_
#define _input_location_message_content_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_location_message_content_t input_location_message_content_t;




typedef struct input_location_message_content_t {
    double latitude; //numeric
    double longitude; //numeric
    double horizontal_accuracy; //numeric
    int live_period; //numeric
    int heading; //numeric
    int proximity_alert_radius; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} input_location_message_content_t;

__attribute__((deprecated)) input_location_message_content_t *input_location_message_content_create(
    double latitude,
    double longitude,
    double horizontal_accuracy,
    int live_period,
    int heading,
    int proximity_alert_radius
);

void input_location_message_content_free(input_location_message_content_t *input_location_message_content);

input_location_message_content_t *input_location_message_content_parseFromJSON(cJSON *input_location_message_contentJSON);

cJSON *input_location_message_content_convertToJSON(input_location_message_content_t *input_location_message_content);

#endif /* _input_location_message_content_H_ */

