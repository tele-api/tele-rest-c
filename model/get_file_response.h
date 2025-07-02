/*
 * get_file_response.h
 *
 * 
 */

#ifndef _get_file_response_H_
#define _get_file_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_file_response_t get_file_response_t;

#include "file.h"



typedef struct get_file_response_t {
    int ok; //boolean
    struct binary_t*_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} get_file_response_t;

__attribute__((deprecated)) get_file_response_t *get_file_response_create(
    int ok,
    binary_t*_t *result
);

void get_file_response_free(get_file_response_t *get_file_response);

get_file_response_t *get_file_response_parseFromJSON(cJSON *get_file_responseJSON);

cJSON *get_file_response_convertToJSON(get_file_response_t *get_file_response);

#endif /* _get_file_response_H_ */

