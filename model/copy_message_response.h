/*
 * copy_message_response.h
 *
 * 
 */

#ifndef _copy_message_response_H_
#define _copy_message_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct copy_message_response_t copy_message_response_t;

#include "message_id.h"



typedef struct copy_message_response_t {
    int ok; //boolean
    struct message_id_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} copy_message_response_t;

__attribute__((deprecated)) copy_message_response_t *copy_message_response_create(
    int ok,
    message_id_t *result
);

void copy_message_response_free(copy_message_response_t *copy_message_response);

copy_message_response_t *copy_message_response_parseFromJSON(cJSON *copy_message_responseJSON);

cJSON *copy_message_response_convertToJSON(copy_message_response_t *copy_message_response);

#endif /* _copy_message_response_H_ */

