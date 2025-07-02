/*
 * verify_user_request.h
 *
 * Request parameters for verifyUser
 */

#ifndef _verify_user_request_H_
#define _verify_user_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct verify_user_request_t verify_user_request_t;




typedef struct verify_user_request_t {
    int user_id; //numeric
    char *custom_description; // string

    int _library_owned; // Is the library responsible for freeing this object?
} verify_user_request_t;

__attribute__((deprecated)) verify_user_request_t *verify_user_request_create(
    int user_id,
    char *custom_description
);

void verify_user_request_free(verify_user_request_t *verify_user_request);

verify_user_request_t *verify_user_request_parseFromJSON(cJSON *verify_user_requestJSON);

cJSON *verify_user_request_convertToJSON(verify_user_request_t *verify_user_request);

#endif /* _verify_user_request_H_ */

