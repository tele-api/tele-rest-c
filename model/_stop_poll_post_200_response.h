/*
 * _stop_poll_post_200_response.h
 *
 * 
 */

#ifndef __stop_poll_post_200_response_H_
#define __stop_poll_post_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _stop_poll_post_200_response_t _stop_poll_post_200_response_t;

#include "poll.h"



typedef struct _stop_poll_post_200_response_t {
    int ok; //boolean
    struct poll_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _stop_poll_post_200_response_t;

__attribute__((deprecated)) _stop_poll_post_200_response_t *_stop_poll_post_200_response_create(
    int ok,
    poll_t *result
);

void _stop_poll_post_200_response_free(_stop_poll_post_200_response_t *_stop_poll_post_200_response);

_stop_poll_post_200_response_t *_stop_poll_post_200_response_parseFromJSON(cJSON *_stop_poll_post_200_responseJSON);

cJSON *_stop_poll_post_200_response_convertToJSON(_stop_poll_post_200_response_t *_stop_poll_post_200_response);

#endif /* __stop_poll_post_200_response_H_ */

