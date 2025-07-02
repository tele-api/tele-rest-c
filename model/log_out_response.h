/*
 * log_out_response.h
 *
 * 
 */

#ifndef _log_out_response_H_
#define _log_out_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct log_out_response_t log_out_response_t;




typedef struct log_out_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} log_out_response_t;

__attribute__((deprecated)) log_out_response_t *log_out_response_create(
    int ok,
    int result
);

void log_out_response_free(log_out_response_t *log_out_response);

log_out_response_t *log_out_response_parseFromJSON(cJSON *log_out_responseJSON);

cJSON *log_out_response_convertToJSON(log_out_response_t *log_out_response);

#endif /* _log_out_response_H_ */

