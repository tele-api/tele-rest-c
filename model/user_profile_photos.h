/*
 * user_profile_photos.h
 *
 * This object represent a user&#39;s profile pictures.
 */

#ifndef _user_profile_photos_H_
#define _user_profile_photos_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_profile_photos_t user_profile_photos_t;

#include "photo_size.h"



typedef struct user_profile_photos_t {
    int total_count; //numeric
    list_t *photos; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} user_profile_photos_t;

__attribute__((deprecated)) user_profile_photos_t *user_profile_photos_create(
    int total_count,
    list_t *photos
);

void user_profile_photos_free(user_profile_photos_t *user_profile_photos);

user_profile_photos_t *user_profile_photos_parseFromJSON(cJSON *user_profile_photosJSON);

cJSON *user_profile_photos_convertToJSON(user_profile_photos_t *user_profile_photos);

#endif /* _user_profile_photos_H_ */

