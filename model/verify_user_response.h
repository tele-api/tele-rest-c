/*
 * verify_user_response.h
 *
 * 
 */

#ifndef _verify_user_response_H_
#define _verify_user_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct verify_user_response_t verify_user_response_t;




typedef struct verify_user_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} verify_user_response_t;

__attribute__((deprecated)) verify_user_response_t *verify_user_response_create(
    int ok,
    int result
);

void verify_user_response_free(verify_user_response_t *verify_user_response);

verify_user_response_t *verify_user_response_parseFromJSON(cJSON *verify_user_responseJSON);

cJSON *verify_user_response_convertToJSON(verify_user_response_t *verify_user_response);

#endif /* _verify_user_response_H_ */

