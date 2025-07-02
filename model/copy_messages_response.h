/*
 * copy_messages_response.h
 *
 * 
 */

#ifndef _copy_messages_response_H_
#define _copy_messages_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct copy_messages_response_t copy_messages_response_t;

#include "message_id.h"



typedef struct copy_messages_response_t {
    int ok; //boolean
    list_t *result; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} copy_messages_response_t;

__attribute__((deprecated)) copy_messages_response_t *copy_messages_response_create(
    int ok,
    list_t *result
);

void copy_messages_response_free(copy_messages_response_t *copy_messages_response);

copy_messages_response_t *copy_messages_response_parseFromJSON(cJSON *copy_messages_responseJSON);

cJSON *copy_messages_response_convertToJSON(copy_messages_response_t *copy_messages_response);

#endif /* _copy_messages_response_H_ */

