#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_profile_photos.h"



static user_profile_photos_t *user_profile_photos_create_internal(
    int total_count,
    list_t *photos
    ) {
    user_profile_photos_t *user_profile_photos_local_var = malloc(sizeof(user_profile_photos_t));
    if (!user_profile_photos_local_var) {
        return NULL;
    }
    user_profile_photos_local_var->total_count = total_count;
    user_profile_photos_local_var->photos = photos;

    user_profile_photos_local_var->_library_owned = 1;
    return user_profile_photos_local_var;
}

__attribute__((deprecated)) user_profile_photos_t *user_profile_photos_create(
    int total_count,
    list_t *photos
    ) {
    return user_profile_photos_create_internal (
        total_count,
        photos
        );
}

void user_profile_photos_free(user_profile_photos_t *user_profile_photos) {
    if(NULL == user_profile_photos){
        return ;
    }
    if(user_profile_photos->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "user_profile_photos_free");
        return ;
    }
    listEntry_t *listEntry;
    if (user_profile_photos->photos) {
        list_ForEach(listEntry, user_profile_photos->photos) {
            free(listEntry->data);
        }
        list_freeList(user_profile_photos->photos);
        user_profile_photos->photos = NULL;
    }
    free(user_profile_photos);
}

cJSON *user_profile_photos_convertToJSON(user_profile_photos_t *user_profile_photos) {
    cJSON *item = cJSON_CreateObject();

    // user_profile_photos->total_count
    if (!user_profile_photos->total_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total_count", user_profile_photos->total_count) == NULL) {
    goto fail; //Numeric
    }


    // user_profile_photos->photos
    if (!user_profile_photos->photos) {
        goto fail;
    }
    cJSON *photos = cJSON_AddArrayToObject(item, "photos");
    if(photos == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *photosListEntry;
    list_ForEach(photosListEntry, user_profile_photos->photos) {
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

user_profile_photos_t *user_profile_photos_parseFromJSON(cJSON *user_profile_photosJSON){

    user_profile_photos_t *user_profile_photos_local_var = NULL;

    // define the local list for user_profile_photos->photos
    list_t *photosList = NULL;

    // user_profile_photos->total_count
    cJSON *total_count = cJSON_GetObjectItemCaseSensitive(user_profile_photosJSON, "total_count");
    if (cJSON_IsNull(total_count)) {
        total_count = NULL;
    }
    if (!total_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total_count))
    {
    goto end; //Numeric
    }

    // user_profile_photos->photos
    cJSON *photos = cJSON_GetObjectItemCaseSensitive(user_profile_photosJSON, "photos");
    if (cJSON_IsNull(photos)) {
        photos = NULL;
    }
    if (!photos) {
        goto end;
    }

    
    cJSON *photos_local = NULL;
    if(!cJSON_IsArray(photos)) {
        goto end;//primitive container
    }
    photosList = list_createList();

    cJSON_ArrayForEach(photos_local, photos)
    {
    }


    user_profile_photos_local_var = user_profile_photos_create_internal (
        total_count->valuedouble,
        photosList
        );

    return user_profile_photos_local_var;
end:
    if (photosList) {
        list_freeList(photosList);
        photosList = NULL;
    }
    return NULL;

}
