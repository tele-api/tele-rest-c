/*
 * post_set_passport_data_errors_request.h
 *
 * 
 */

#ifndef _post_set_passport_data_errors_request_H_
#define _post_set_passport_data_errors_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_set_passport_data_errors_request_t post_set_passport_data_errors_request_t;

#include "passport_element_error.h"



typedef struct post_set_passport_data_errors_request_t {
    int user_id; //numeric
    list_t *errors; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} post_set_passport_data_errors_request_t;

__attribute__((deprecated)) post_set_passport_data_errors_request_t *post_set_passport_data_errors_request_create(
    int user_id,
    list_t *errors
);

void post_set_passport_data_errors_request_free(post_set_passport_data_errors_request_t *post_set_passport_data_errors_request);

post_set_passport_data_errors_request_t *post_set_passport_data_errors_request_parseFromJSON(cJSON *post_set_passport_data_errors_requestJSON);

cJSON *post_set_passport_data_errors_request_convertToJSON(post_set_passport_data_errors_request_t *post_set_passport_data_errors_request);

#endif /* _post_set_passport_data_errors_request_H_ */

