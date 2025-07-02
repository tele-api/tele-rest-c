/*
 * get_available_gifts_response.h
 *
 * 
 */

#ifndef _get_available_gifts_response_H_
#define _get_available_gifts_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_available_gifts_response_t get_available_gifts_response_t;

#include "gifts.h"



typedef struct get_available_gifts_response_t {
    int ok; //boolean
    struct gifts_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} get_available_gifts_response_t;

__attribute__((deprecated)) get_available_gifts_response_t *get_available_gifts_response_create(
    int ok,
    gifts_t *result
);

void get_available_gifts_response_free(get_available_gifts_response_t *get_available_gifts_response);

get_available_gifts_response_t *get_available_gifts_response_parseFromJSON(cJSON *get_available_gifts_responseJSON);

cJSON *get_available_gifts_response_convertToJSON(get_available_gifts_response_t *get_available_gifts_response);

#endif /* _get_available_gifts_response_H_ */

