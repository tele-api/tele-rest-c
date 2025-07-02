/*
 * post_stop_poll_200_response.h
 *
 * 
 */

#ifndef _post_stop_poll_200_response_H_
#define _post_stop_poll_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_stop_poll_200_response_t post_stop_poll_200_response_t;

#include "poll.h"



typedef struct post_stop_poll_200_response_t {
    int ok; //boolean
    struct poll_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_stop_poll_200_response_t;

__attribute__((deprecated)) post_stop_poll_200_response_t *post_stop_poll_200_response_create(
    int ok,
    poll_t *result
);

void post_stop_poll_200_response_free(post_stop_poll_200_response_t *post_stop_poll_200_response);

post_stop_poll_200_response_t *post_stop_poll_200_response_parseFromJSON(cJSON *post_stop_poll_200_responseJSON);

cJSON *post_stop_poll_200_response_convertToJSON(post_stop_poll_200_response_t *post_stop_poll_200_response);

#endif /* _post_stop_poll_200_response_H_ */

