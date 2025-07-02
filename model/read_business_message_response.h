/*
 * read_business_message_response.h
 *
 * 
 */

#ifndef _read_business_message_response_H_
#define _read_business_message_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct read_business_message_response_t read_business_message_response_t;




typedef struct read_business_message_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} read_business_message_response_t;

__attribute__((deprecated)) read_business_message_response_t *read_business_message_response_create(
    int ok,
    int result
);

void read_business_message_response_free(read_business_message_response_t *read_business_message_response);

read_business_message_response_t *read_business_message_response_parseFromJSON(cJSON *read_business_message_responseJSON);

cJSON *read_business_message_response_convertToJSON(read_business_message_response_t *read_business_message_response);

#endif /* _read_business_message_response_H_ */

