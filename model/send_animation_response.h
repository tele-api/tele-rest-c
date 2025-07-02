/*
 * send_animation_response.h
 *
 * 
 */

#ifndef _send_animation_response_H_
#define _send_animation_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_animation_response_t send_animation_response_t;

#include "message.h"



typedef struct send_animation_response_t {
    int ok; //boolean
    struct message_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} send_animation_response_t;

__attribute__((deprecated)) send_animation_response_t *send_animation_response_create(
    int ok,
    message_t *result
);

void send_animation_response_free(send_animation_response_t *send_animation_response);

send_animation_response_t *send_animation_response_parseFromJSON(cJSON *send_animation_responseJSON);

cJSON *send_animation_response_convertToJSON(send_animation_response_t *send_animation_response);

#endif /* _send_animation_response_H_ */

