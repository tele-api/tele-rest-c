/*
 * get_business_connection_request.h
 *
 * Request parameters for getBusinessConnection
 */

#ifndef _get_business_connection_request_H_
#define _get_business_connection_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_business_connection_request_t get_business_connection_request_t;




typedef struct get_business_connection_request_t {
    char *business_connection_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} get_business_connection_request_t;

__attribute__((deprecated)) get_business_connection_request_t *get_business_connection_request_create(
    char *business_connection_id
);

void get_business_connection_request_free(get_business_connection_request_t *get_business_connection_request);

get_business_connection_request_t *get_business_connection_request_parseFromJSON(cJSON *get_business_connection_requestJSON);

cJSON *get_business_connection_request_convertToJSON(get_business_connection_request_t *get_business_connection_request);

#endif /* _get_business_connection_request_H_ */

