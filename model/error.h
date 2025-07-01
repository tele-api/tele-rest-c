/*
 * error.h
 *
 * 
 */

#ifndef _error_H_
#define _error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct error_t error_t;

#include "response_parameters.h"



typedef struct error_t {
    int ok; //boolean
    int error_code; //numeric
    char *description; // string
    struct response_parameters_t *parameters; //model

    int _library_owned; // Is the library responsible for freeing this object?
} error_t;

__attribute__((deprecated)) error_t *error_create(
    int ok,
    int error_code,
    char *description,
    response_parameters_t *parameters
);

void error_free(error_t *error);

error_t *error_parseFromJSON(cJSON *errorJSON);

cJSON *error_convertToJSON(error_t *error);

#endif /* _error_H_ */

