/*
 * forward_message_response.h
 *
 * 
 */

#ifndef _forward_message_response_H_
#define _forward_message_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct forward_message_response_t forward_message_response_t;

#include "message.h"



typedef struct forward_message_response_t {
    int ok; //boolean
    struct message_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} forward_message_response_t;

__attribute__((deprecated)) forward_message_response_t *forward_message_response_create(
    int ok,
    message_t *result
);

void forward_message_response_free(forward_message_response_t *forward_message_response);

forward_message_response_t *forward_message_response_parseFromJSON(cJSON *forward_message_responseJSON);

cJSON *forward_message_response_convertToJSON(forward_message_response_t *forward_message_response);

#endif /* _forward_message_response_H_ */

