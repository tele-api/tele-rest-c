/*
 * post_verify_user_request.h
 *
 * 
 */

#ifndef _post_verify_user_request_H_
#define _post_verify_user_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_verify_user_request_t post_verify_user_request_t;




typedef struct post_verify_user_request_t {
    int user_id; //numeric
    char *custom_description; // string

    int _library_owned; // Is the library responsible for freeing this object?
} post_verify_user_request_t;

__attribute__((deprecated)) post_verify_user_request_t *post_verify_user_request_create(
    int user_id,
    char *custom_description
);

void post_verify_user_request_free(post_verify_user_request_t *post_verify_user_request);

post_verify_user_request_t *post_verify_user_request_parseFromJSON(cJSON *post_verify_user_requestJSON);

cJSON *post_verify_user_request_convertToJSON(post_verify_user_request_t *post_verify_user_request);

#endif /* _post_verify_user_request_H_ */

