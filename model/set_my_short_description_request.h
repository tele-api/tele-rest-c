/*
 * set_my_short_description_request.h
 *
 * Request parameters for setMyShortDescription
 */

#ifndef _set_my_short_description_request_H_
#define _set_my_short_description_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_my_short_description_request_t set_my_short_description_request_t;




typedef struct set_my_short_description_request_t {
    char *short_description; // string
    char *language_code; // string

    int _library_owned; // Is the library responsible for freeing this object?
} set_my_short_description_request_t;

__attribute__((deprecated)) set_my_short_description_request_t *set_my_short_description_request_create(
    char *short_description,
    char *language_code
);

void set_my_short_description_request_free(set_my_short_description_request_t *set_my_short_description_request);

set_my_short_description_request_t *set_my_short_description_request_parseFromJSON(cJSON *set_my_short_description_requestJSON);

cJSON *set_my_short_description_request_convertToJSON(set_my_short_description_request_t *set_my_short_description_request);

#endif /* _set_my_short_description_request_H_ */

