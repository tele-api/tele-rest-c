/*
 * post_remove_user_verification_request.h
 *
 * 
 */

#ifndef _post_remove_user_verification_request_H_
#define _post_remove_user_verification_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_remove_user_verification_request_t post_remove_user_verification_request_t;




typedef struct post_remove_user_verification_request_t {
    int user_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} post_remove_user_verification_request_t;

__attribute__((deprecated)) post_remove_user_verification_request_t *post_remove_user_verification_request_create(
    int user_id
);

void post_remove_user_verification_request_free(post_remove_user_verification_request_t *post_remove_user_verification_request);

post_remove_user_verification_request_t *post_remove_user_verification_request_parseFromJSON(cJSON *post_remove_user_verification_requestJSON);

cJSON *post_remove_user_verification_request_convertToJSON(post_remove_user_verification_request_t *post_remove_user_verification_request);

#endif /* _post_remove_user_verification_request_H_ */

