/*
 * send_poll_response.h
 *
 * 
 */

#ifndef _send_poll_response_H_
#define _send_poll_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_poll_response_t send_poll_response_t;

#include "message.h"



typedef struct send_poll_response_t {
    int ok; //boolean
    struct message_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} send_poll_response_t;

__attribute__((deprecated)) send_poll_response_t *send_poll_response_create(
    int ok,
    message_t *result
);

void send_poll_response_free(send_poll_response_t *send_poll_response);

send_poll_response_t *send_poll_response_parseFromJSON(cJSON *send_poll_responseJSON);

cJSON *send_poll_response_convertToJSON(send_poll_response_t *send_poll_response);

#endif /* _send_poll_response_H_ */

