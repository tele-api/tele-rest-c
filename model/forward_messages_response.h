/*
 * forward_messages_response.h
 *
 * 
 */

#ifndef _forward_messages_response_H_
#define _forward_messages_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct forward_messages_response_t forward_messages_response_t;

#include "message_id.h"



typedef struct forward_messages_response_t {
    int ok; //boolean
    list_t *result; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} forward_messages_response_t;

__attribute__((deprecated)) forward_messages_response_t *forward_messages_response_create(
    int ok,
    list_t *result
);

void forward_messages_response_free(forward_messages_response_t *forward_messages_response);

forward_messages_response_t *forward_messages_response_parseFromJSON(cJSON *forward_messages_responseJSON);

cJSON *forward_messages_response_convertToJSON(forward_messages_response_t *forward_messages_response);

#endif /* _forward_messages_response_H_ */

