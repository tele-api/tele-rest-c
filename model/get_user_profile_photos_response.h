/*
 * get_user_profile_photos_response.h
 *
 * 
 */

#ifndef _get_user_profile_photos_response_H_
#define _get_user_profile_photos_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_user_profile_photos_response_t get_user_profile_photos_response_t;

#include "user_profile_photos.h"



typedef struct get_user_profile_photos_response_t {
    int ok; //boolean
    struct user_profile_photos_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} get_user_profile_photos_response_t;

__attribute__((deprecated)) get_user_profile_photos_response_t *get_user_profile_photos_response_create(
    int ok,
    user_profile_photos_t *result
);

void get_user_profile_photos_response_free(get_user_profile_photos_response_t *get_user_profile_photos_response);

get_user_profile_photos_response_t *get_user_profile_photos_response_parseFromJSON(cJSON *get_user_profile_photos_responseJSON);

cJSON *get_user_profile_photos_response_convertToJSON(get_user_profile_photos_response_t *get_user_profile_photos_response);

#endif /* _get_user_profile_photos_response_H_ */

