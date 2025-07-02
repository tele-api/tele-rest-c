/*
 * remove_business_account_profile_photo_request.h
 *
 * Request parameters for removeBusinessAccountProfilePhoto
 */

#ifndef _remove_business_account_profile_photo_request_H_
#define _remove_business_account_profile_photo_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct remove_business_account_profile_photo_request_t remove_business_account_profile_photo_request_t;




typedef struct remove_business_account_profile_photo_request_t {
    char *business_connection_id; // string
    int is_public; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} remove_business_account_profile_photo_request_t;

__attribute__((deprecated)) remove_business_account_profile_photo_request_t *remove_business_account_profile_photo_request_create(
    char *business_connection_id,
    int is_public
);

void remove_business_account_profile_photo_request_free(remove_business_account_profile_photo_request_t *remove_business_account_profile_photo_request);

remove_business_account_profile_photo_request_t *remove_business_account_profile_photo_request_parseFromJSON(cJSON *remove_business_account_profile_photo_requestJSON);

cJSON *remove_business_account_profile_photo_request_convertToJSON(remove_business_account_profile_photo_request_t *remove_business_account_profile_photo_request);

#endif /* _remove_business_account_profile_photo_request_H_ */

