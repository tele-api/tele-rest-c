/*
 * remove_business_account_profile_photo_response.h
 *
 * 
 */

#ifndef _remove_business_account_profile_photo_response_H_
#define _remove_business_account_profile_photo_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct remove_business_account_profile_photo_response_t remove_business_account_profile_photo_response_t;




typedef struct remove_business_account_profile_photo_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} remove_business_account_profile_photo_response_t;

__attribute__((deprecated)) remove_business_account_profile_photo_response_t *remove_business_account_profile_photo_response_create(
    int ok,
    int result
);

void remove_business_account_profile_photo_response_free(remove_business_account_profile_photo_response_t *remove_business_account_profile_photo_response);

remove_business_account_profile_photo_response_t *remove_business_account_profile_photo_response_parseFromJSON(cJSON *remove_business_account_profile_photo_responseJSON);

cJSON *remove_business_account_profile_photo_response_convertToJSON(remove_business_account_profile_photo_response_t *remove_business_account_profile_photo_response);

#endif /* _remove_business_account_profile_photo_response_H_ */

