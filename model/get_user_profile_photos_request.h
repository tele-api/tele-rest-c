/*
 * get_user_profile_photos_request.h
 *
 * Request parameters for getUserProfilePhotos
 */

#ifndef _get_user_profile_photos_request_H_
#define _get_user_profile_photos_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_user_profile_photos_request_t get_user_profile_photos_request_t;




typedef struct get_user_profile_photos_request_t {
    int user_id; //numeric
    int offset; //numeric
    int limit; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} get_user_profile_photos_request_t;

__attribute__((deprecated)) get_user_profile_photos_request_t *get_user_profile_photos_request_create(
    int user_id,
    int offset,
    int limit
);

void get_user_profile_photos_request_free(get_user_profile_photos_request_t *get_user_profile_photos_request);

get_user_profile_photos_request_t *get_user_profile_photos_request_parseFromJSON(cJSON *get_user_profile_photos_requestJSON);

cJSON *get_user_profile_photos_request_convertToJSON(get_user_profile_photos_request_t *get_user_profile_photos_request);

#endif /* _get_user_profile_photos_request_H_ */

