/*
 * close_response.h
 *
 * 
 */

#ifndef _close_response_H_
#define _close_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct close_response_t close_response_t;




typedef struct close_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} close_response_t;

__attribute__((deprecated)) close_response_t *close_response_create(
    int ok,
    int result
);

void close_response_free(close_response_t *close_response);

close_response_t *close_response_parseFromJSON(cJSON *close_responseJSON);

cJSON *close_response_convertToJSON(close_response_t *close_response);

#endif /* _close_response_H_ */

