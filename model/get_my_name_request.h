/*
 * get_my_name_request.h
 *
 * Request parameters for getMyName
 */

#ifndef _get_my_name_request_H_
#define _get_my_name_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_my_name_request_t get_my_name_request_t;




typedef struct get_my_name_request_t {
    char *language_code; // string

    int _library_owned; // Is the library responsible for freeing this object?
} get_my_name_request_t;

__attribute__((deprecated)) get_my_name_request_t *get_my_name_request_create(
    char *language_code
);

void get_my_name_request_free(get_my_name_request_t *get_my_name_request);

get_my_name_request_t *get_my_name_request_parseFromJSON(cJSON *get_my_name_requestJSON);

cJSON *get_my_name_request_convertToJSON(get_my_name_request_t *get_my_name_request);

#endif /* _get_my_name_request_H_ */

