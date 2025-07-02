/*
 * remove_user_verification_request.h
 *
 * Request parameters for removeUserVerification
 */

#ifndef _remove_user_verification_request_H_
#define _remove_user_verification_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct remove_user_verification_request_t remove_user_verification_request_t;




typedef struct remove_user_verification_request_t {
    int user_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} remove_user_verification_request_t;

__attribute__((deprecated)) remove_user_verification_request_t *remove_user_verification_request_create(
    int user_id
);

void remove_user_verification_request_free(remove_user_verification_request_t *remove_user_verification_request);

remove_user_verification_request_t *remove_user_verification_request_parseFromJSON(cJSON *remove_user_verification_requestJSON);

cJSON *remove_user_verification_request_convertToJSON(remove_user_verification_request_t *remove_user_verification_request);

#endif /* _remove_user_verification_request_H_ */

