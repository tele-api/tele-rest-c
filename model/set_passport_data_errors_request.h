/*
 * set_passport_data_errors_request.h
 *
 * Request parameters for setPassportDataErrors
 */

#ifndef _set_passport_data_errors_request_H_
#define _set_passport_data_errors_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_passport_data_errors_request_t set_passport_data_errors_request_t;

#include "passport_element_error.h"



typedef struct set_passport_data_errors_request_t {
    int user_id; //numeric
    list_t *errors; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} set_passport_data_errors_request_t;

__attribute__((deprecated)) set_passport_data_errors_request_t *set_passport_data_errors_request_create(
    int user_id,
    list_t *errors
);

void set_passport_data_errors_request_free(set_passport_data_errors_request_t *set_passport_data_errors_request);

set_passport_data_errors_request_t *set_passport_data_errors_request_parseFromJSON(cJSON *set_passport_data_errors_requestJSON);

cJSON *set_passport_data_errors_request_convertToJSON(set_passport_data_errors_request_t *set_passport_data_errors_request);

#endif /* _set_passport_data_errors_request_H_ */

