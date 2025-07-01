#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "paid_media_photo.h"



static paid_media_photo_t *paid_media_photo_create_internal(
    char *type,
    list_t *photo
    ) {
    paid_media_photo_t *paid_media_photo_local_var = malloc(sizeof(paid_media_photo_t));
    if (!paid_media_photo_local_var) {
        return NULL;
    }
    paid_media_photo_local_var->type = type;
    paid_media_photo_local_var->photo = photo;

    paid_media_photo_local_var->_library_owned = 1;
    return paid_media_photo_local_var;
}

__attribute__((deprecated)) paid_media_photo_t *paid_media_photo_create(
    char *type,
    list_t *photo
    ) {
    return paid_media_photo_create_internal (
        type,
        photo
        );
}

void paid_media_photo_free(paid_media_photo_t *paid_media_photo) {
    if(NULL == paid_media_photo){
        return ;
    }
    if(paid_media_photo->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "paid_media_photo_free");
        return ;
    }
    listEntry_t *listEntry;
    if (paid_media_photo->type) {
        free(paid_media_photo->type);
        paid_media_photo->type = NULL;
    }
    if (paid_media_photo->photo) {
        list_ForEach(listEntry, paid_media_photo->photo) {
            photo_size_free(listEntry->data);
        }
        list_freeList(paid_media_photo->photo);
        paid_media_photo->photo = NULL;
    }
    free(paid_media_photo);
}

cJSON *paid_media_photo_convertToJSON(paid_media_photo_t *paid_media_photo) {
    cJSON *item = cJSON_CreateObject();

    // paid_media_photo->type
    if (!paid_media_photo->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", paid_media_photo->type) == NULL) {
    goto fail; //String
    }


    // paid_media_photo->photo
    if (!paid_media_photo->photo) {
        goto fail;
    }
    cJSON *photo = cJSON_AddArrayToObject(item, "photo");
    if(photo == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *photoListEntry;
    if (paid_media_photo->photo) {
    list_ForEach(photoListEntry, paid_media_photo->photo) {
    cJSON *itemLocal = photo_size_convertToJSON(photoListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(photo, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

paid_media_photo_t *paid_media_photo_parseFromJSON(cJSON *paid_media_photoJSON){

    paid_media_photo_t *paid_media_photo_local_var = NULL;

    // define the local list for paid_media_photo->photo
    list_t *photoList = NULL;

    // paid_media_photo->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(paid_media_photoJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // paid_media_photo->photo
    cJSON *photo = cJSON_GetObjectItemCaseSensitive(paid_media_photoJSON, "photo");
    if (cJSON_IsNull(photo)) {
        photo = NULL;
    }
    if (!photo) {
        goto end;
    }

    
    cJSON *photo_local_nonprimitive = NULL;
    if(!cJSON_IsArray(photo)){
        goto end; //nonprimitive container
    }

    photoList = list_createList();

    cJSON_ArrayForEach(photo_local_nonprimitive,photo )
    {
        if(!cJSON_IsObject(photo_local_nonprimitive)){
            goto end;
        }
        photo_size_t *photoItem = photo_size_parseFromJSON(photo_local_nonprimitive);

        list_addElement(photoList, photoItem);
    }


    paid_media_photo_local_var = paid_media_photo_create_internal (
        strdup(type->valuestring),
        photoList
        );

    return paid_media_photo_local_var;
end:
    if (photoList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, photoList) {
            photo_size_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(photoList);
        photoList = NULL;
    }
    return NULL;

}
