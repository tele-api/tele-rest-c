/*
 * _remove_user_verification_post_request.h
 *
 * 
 */

#ifndef __remove_user_verification_post_request_H_
#define __remove_user_verification_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _remove_user_verification_post_request_t _remove_user_verification_post_request_t;




typedef struct _remove_user_verification_post_request_t {
    int user_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} _remove_user_verification_post_request_t;

__attribute__((deprecated)) _remove_user_verification_post_request_t *_remove_user_verification_post_request_create(
    int user_id
);

void _remove_user_verification_post_request_free(_remove_user_verification_post_request_t *_remove_user_verification_post_request);

_remove_user_verification_post_request_t *_remove_user_verification_post_request_parseFromJSON(cJSON *_remove_user_verification_post_requestJSON);

cJSON *_remove_user_verification_post_request_convertToJSON(_remove_user_verification_post_request_t *_remove_user_verification_post_request);

#endif /* __remove_user_verification_post_request_H_ */

