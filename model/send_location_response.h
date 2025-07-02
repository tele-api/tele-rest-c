/*
 * send_location_response.h
 *
 * 
 */

#ifndef _send_location_response_H_
#define _send_location_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_location_response_t send_location_response_t;

#include "message.h"



typedef struct send_location_response_t {
    int ok; //boolean
    struct message_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} send_location_response_t;

__attribute__((deprecated)) send_location_response_t *send_location_response_create(
    int ok,
    message_t *result
);

void send_location_response_free(send_location_response_t *send_location_response);

send_location_response_t *send_location_response_parseFromJSON(cJSON *send_location_responseJSON);

cJSON *send_location_response_convertToJSON(send_location_response_t *send_location_response);

#endif /* _send_location_response_H_ */

