/*
 * _remove_business_account_profile_photo_post_request.h
 *
 * 
 */

#ifndef __remove_business_account_profile_photo_post_request_H_
#define __remove_business_account_profile_photo_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _remove_business_account_profile_photo_post_request_t _remove_business_account_profile_photo_post_request_t;




typedef struct _remove_business_account_profile_photo_post_request_t {
    char *business_connection_id; // string
    int is_public; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} _remove_business_account_profile_photo_post_request_t;

__attribute__((deprecated)) _remove_business_account_profile_photo_post_request_t *_remove_business_account_profile_photo_post_request_create(
    char *business_connection_id,
    int is_public
);

void _remove_business_account_profile_photo_post_request_free(_remove_business_account_profile_photo_post_request_t *_remove_business_account_profile_photo_post_request);

_remove_business_account_profile_photo_post_request_t *_remove_business_account_profile_photo_post_request_parseFromJSON(cJSON *_remove_business_account_profile_photo_post_requestJSON);

cJSON *_remove_business_account_profile_photo_post_request_convertToJSON(_remove_business_account_profile_photo_post_request_t *_remove_business_account_profile_photo_post_request);

#endif /* __remove_business_account_profile_photo_post_request_H_ */

