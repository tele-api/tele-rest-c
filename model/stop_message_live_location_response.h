/*
 * stop_message_live_location_response.h
 *
 * 
 */

#ifndef _stop_message_live_location_response_H_
#define _stop_message_live_location_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct stop_message_live_location_response_t stop_message_live_location_response_t;

#include "edit_message_text_response_result.h"



typedef struct stop_message_live_location_response_t {
    int ok; //boolean
    struct edit_message_text_response_result_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} stop_message_live_location_response_t;

__attribute__((deprecated)) stop_message_live_location_response_t *stop_message_live_location_response_create(
    int ok,
    edit_message_text_response_result_t *result
);

void stop_message_live_location_response_free(stop_message_live_location_response_t *stop_message_live_location_response);

stop_message_live_location_response_t *stop_message_live_location_response_parseFromJSON(cJSON *stop_message_live_location_responseJSON);

cJSON *stop_message_live_location_response_convertToJSON(stop_message_live_location_response_t *stop_message_live_location_response);

#endif /* _stop_message_live_location_response_H_ */

