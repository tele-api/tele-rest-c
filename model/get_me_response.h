/*
 * get_me_response.h
 *
 * 
 */

#ifndef _get_me_response_H_
#define _get_me_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_me_response_t get_me_response_t;

#include "user.h"



typedef struct get_me_response_t {
    int ok; //boolean
    struct user_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} get_me_response_t;

__attribute__((deprecated)) get_me_response_t *get_me_response_create(
    int ok,
    user_t *result
);

void get_me_response_free(get_me_response_t *get_me_response);

get_me_response_t *get_me_response_parseFromJSON(cJSON *get_me_responseJSON);

cJSON *get_me_response_convertToJSON(get_me_response_t *get_me_response);

#endif /* _get_me_response_H_ */

