/*
 * get_updates_response.h
 *
 * 
 */

#ifndef _get_updates_response_H_
#define _get_updates_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_updates_response_t get_updates_response_t;

#include "update.h"



typedef struct get_updates_response_t {
    int ok; //boolean
    list_t *result; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} get_updates_response_t;

__attribute__((deprecated)) get_updates_response_t *get_updates_response_create(
    int ok,
    list_t *result
);

void get_updates_response_free(get_updates_response_t *get_updates_response);

get_updates_response_t *get_updates_response_parseFromJSON(cJSON *get_updates_responseJSON);

cJSON *get_updates_response_convertToJSON(get_updates_response_t *get_updates_response);

#endif /* _get_updates_response_H_ */

