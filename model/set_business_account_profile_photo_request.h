/*
 * set_business_account_profile_photo_request.h
 *
 * Request parameters for setBusinessAccountProfilePhoto
 */

#ifndef _set_business_account_profile_photo_request_H_
#define _set_business_account_profile_photo_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_business_account_profile_photo_request_t set_business_account_profile_photo_request_t;

#include "input_profile_photo.h"



typedef struct set_business_account_profile_photo_request_t {
    char *business_connection_id; // string
    struct input_profile_photo_t *photo; //model
    int is_public; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} set_business_account_profile_photo_request_t;

__attribute__((deprecated)) set_business_account_profile_photo_request_t *set_business_account_profile_photo_request_create(
    char *business_connection_id,
    input_profile_photo_t *photo,
    int is_public
);

void set_business_account_profile_photo_request_free(set_business_account_profile_photo_request_t *set_business_account_profile_photo_request);

set_business_account_profile_photo_request_t *set_business_account_profile_photo_request_parseFromJSON(cJSON *set_business_account_profile_photo_requestJSON);

cJSON *set_business_account_profile_photo_request_convertToJSON(set_business_account_profile_photo_request_t *set_business_account_profile_photo_request);

#endif /* _set_business_account_profile_photo_request_H_ */

