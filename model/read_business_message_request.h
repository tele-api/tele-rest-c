/*
 * read_business_message_request.h
 *
 * Request parameters for readBusinessMessage
 */

#ifndef _read_business_message_request_H_
#define _read_business_message_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct read_business_message_request_t read_business_message_request_t;




typedef struct read_business_message_request_t {
    char *business_connection_id; // string
    int chat_id; //numeric
    int message_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} read_business_message_request_t;

__attribute__((deprecated)) read_business_message_request_t *read_business_message_request_create(
    char *business_connection_id,
    int chat_id,
    int message_id
);

void read_business_message_request_free(read_business_message_request_t *read_business_message_request);

read_business_message_request_t *read_business_message_request_parseFromJSON(cJSON *read_business_message_requestJSON);

cJSON *read_business_message_request_convertToJSON(read_business_message_request_t *read_business_message_request);

#endif /* _read_business_message_request_H_ */

