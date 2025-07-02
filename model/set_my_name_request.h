/*
 * set_my_name_request.h
 *
 * Request parameters for setMyName
 */

#ifndef _set_my_name_request_H_
#define _set_my_name_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_my_name_request_t set_my_name_request_t;




typedef struct set_my_name_request_t {
    char *name; // string
    char *language_code; // string

    int _library_owned; // Is the library responsible for freeing this object?
} set_my_name_request_t;

__attribute__((deprecated)) set_my_name_request_t *set_my_name_request_create(
    char *name,
    char *language_code
);

void set_my_name_request_free(set_my_name_request_t *set_my_name_request);

set_my_name_request_t *set_my_name_request_parseFromJSON(cJSON *set_my_name_requestJSON);

cJSON *set_my_name_request_convertToJSON(set_my_name_request_t *set_my_name_request);

#endif /* _set_my_name_request_H_ */

