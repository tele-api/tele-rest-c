/*
 * stop_poll_response.h
 *
 * 
 */

#ifndef _stop_poll_response_H_
#define _stop_poll_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct stop_poll_response_t stop_poll_response_t;

#include "poll.h"



typedef struct stop_poll_response_t {
    int ok; //boolean
    struct poll_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} stop_poll_response_t;

__attribute__((deprecated)) stop_poll_response_t *stop_poll_response_create(
    int ok,
    poll_t *result
);

void stop_poll_response_free(stop_poll_response_t *stop_poll_response);

stop_poll_response_t *stop_poll_response_parseFromJSON(cJSON *stop_poll_responseJSON);

cJSON *stop_poll_response_convertToJSON(stop_poll_response_t *stop_poll_response);

#endif /* _stop_poll_response_H_ */

