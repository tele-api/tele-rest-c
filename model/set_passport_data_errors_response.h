/*
 * set_passport_data_errors_response.h
 *
 * 
 */

#ifndef _set_passport_data_errors_response_H_
#define _set_passport_data_errors_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_passport_data_errors_response_t set_passport_data_errors_response_t;




typedef struct set_passport_data_errors_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} set_passport_data_errors_response_t;

__attribute__((deprecated)) set_passport_data_errors_response_t *set_passport_data_errors_response_create(
    int ok,
    int result
);

void set_passport_data_errors_response_free(set_passport_data_errors_response_t *set_passport_data_errors_response);

set_passport_data_errors_response_t *set_passport_data_errors_response_parseFromJSON(cJSON *set_passport_data_errors_responseJSON);

cJSON *set_passport_data_errors_response_convertToJSON(set_passport_data_errors_response_t *set_passport_data_errors_response);

#endif /* _set_passport_data_errors_response_H_ */

