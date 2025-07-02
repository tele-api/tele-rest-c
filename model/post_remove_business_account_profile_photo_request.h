/*
 * post_remove_business_account_profile_photo_request.h
 *
 * 
 */

#ifndef _post_remove_business_account_profile_photo_request_H_
#define _post_remove_business_account_profile_photo_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_remove_business_account_profile_photo_request_t post_remove_business_account_profile_photo_request_t;




typedef struct post_remove_business_account_profile_photo_request_t {
    char *business_connection_id; // string
    int is_public; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} post_remove_business_account_profile_photo_request_t;

__attribute__((deprecated)) post_remove_business_account_profile_photo_request_t *post_remove_business_account_profile_photo_request_create(
    char *business_connection_id,
    int is_public
);

void post_remove_business_account_profile_photo_request_free(post_remove_business_account_profile_photo_request_t *post_remove_business_account_profile_photo_request);

post_remove_business_account_profile_photo_request_t *post_remove_business_account_profile_photo_request_parseFromJSON(cJSON *post_remove_business_account_profile_photo_requestJSON);

cJSON *post_remove_business_account_profile_photo_request_convertToJSON(post_remove_business_account_profile_photo_request_t *post_remove_business_account_profile_photo_request);

#endif /* _post_remove_business_account_profile_photo_request_H_ */

