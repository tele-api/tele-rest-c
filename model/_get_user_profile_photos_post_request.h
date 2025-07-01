/*
 * _get_user_profile_photos_post_request.h
 *
 * 
 */

#ifndef __get_user_profile_photos_post_request_H_
#define __get_user_profile_photos_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _get_user_profile_photos_post_request_t _get_user_profile_photos_post_request_t;




typedef struct _get_user_profile_photos_post_request_t {
    int user_id; //numeric
    int offset; //numeric
    int limit; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} _get_user_profile_photos_post_request_t;

__attribute__((deprecated)) _get_user_profile_photos_post_request_t *_get_user_profile_photos_post_request_create(
    int user_id,
    int offset,
    int limit
);

void _get_user_profile_photos_post_request_free(_get_user_profile_photos_post_request_t *_get_user_profile_photos_post_request);

_get_user_profile_photos_post_request_t *_get_user_profile_photos_post_request_parseFromJSON(cJSON *_get_user_profile_photos_post_requestJSON);

cJSON *_get_user_profile_photos_post_request_convertToJSON(_get_user_profile_photos_post_request_t *_get_user_profile_photos_post_request);

#endif /* __get_user_profile_photos_post_request_H_ */

