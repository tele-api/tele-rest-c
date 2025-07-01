/*
 * _verify_user_post_request.h
 *
 * 
 */

#ifndef __verify_user_post_request_H_
#define __verify_user_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _verify_user_post_request_t _verify_user_post_request_t;




typedef struct _verify_user_post_request_t {
    int user_id; //numeric
    char *custom_description; // string

    int _library_owned; // Is the library responsible for freeing this object?
} _verify_user_post_request_t;

__attribute__((deprecated)) _verify_user_post_request_t *_verify_user_post_request_create(
    int user_id,
    char *custom_description
);

void _verify_user_post_request_free(_verify_user_post_request_t *_verify_user_post_request);

_verify_user_post_request_t *_verify_user_post_request_parseFromJSON(cJSON *_verify_user_post_requestJSON);

cJSON *_verify_user_post_request_convertToJSON(_verify_user_post_request_t *_verify_user_post_request);

#endif /* __verify_user_post_request_H_ */

