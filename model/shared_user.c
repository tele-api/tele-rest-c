#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shared_user.h"



static shared_user_t *shared_user_create_internal(
    int user_id,
    char *first_name,
    char *last_name,
    char *username,
    list_t *photo
    ) {
    shared_user_t *shared_user_local_var = malloc(sizeof(shared_user_t));
    if (!shared_user_local_var) {
        return NULL;
    }
    shared_user_local_var->user_id = user_id;
    shared_user_local_var->first_name = first_name;
    shared_user_local_var->last_name = last_name;
    shared_user_local_var->username = username;
    shared_user_local_var->photo = photo;

    shared_user_local_var->_library_owned = 1;
    return shared_user_local_var;
}

__attribute__((deprecated)) shared_user_t *shared_user_create(
    int user_id,
    char *first_name,
    char *last_name,
    char *username,
    list_t *photo
    ) {
    return shared_user_create_internal (
        user_id,
        first_name,
        last_name,
        username,
        photo
        );
}

void shared_user_free(shared_user_t *shared_user) {
    if(NULL == shared_user){
        return ;
    }
    if(shared_user->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "shared_user_free");
        return ;
    }
    listEntry_t *listEntry;
    if (shared_user->first_name) {
        free(shared_user->first_name);
        shared_user->first_name = NULL;
    }
    if (shared_user->last_name) {
        free(shared_user->last_name);
        shared_user->last_name = NULL;
    }
    if (shared_user->username) {
        free(shared_user->username);
        shared_user->username = NULL;
    }
    if (shared_user->photo) {
        list_ForEach(listEntry, shared_user->photo) {
            photo_size_free(listEntry->data);
        }
        list_freeList(shared_user->photo);
        shared_user->photo = NULL;
    }
    free(shared_user);
}

cJSON *shared_user_convertToJSON(shared_user_t *shared_user) {
    cJSON *item = cJSON_CreateObject();

    // shared_user->user_id
    if (!shared_user->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", shared_user->user_id) == NULL) {
    goto fail; //Numeric
    }


    // shared_user->first_name
    if(shared_user->first_name) {
    if(cJSON_AddStringToObject(item, "first_name", shared_user->first_name) == NULL) {
    goto fail; //String
    }
    }


    // shared_user->last_name
    if(shared_user->last_name) {
    if(cJSON_AddStringToObject(item, "last_name", shared_user->last_name) == NULL) {
    goto fail; //String
    }
    }


    // shared_user->username
    if(shared_user->username) {
    if(cJSON_AddStringToObject(item, "username", shared_user->username) == NULL) {
    goto fail; //String
    }
    }


    // shared_user->photo
    if(shared_user->photo) {
    cJSON *photo = cJSON_AddArrayToObject(item, "photo");
    if(photo == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *photoListEntry;
    if (shared_user->photo) {
    list_ForEach(photoListEntry, shared_user->photo) {
    cJSON *itemLocal = photo_size_convertToJSON(photoListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(photo, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

shared_user_t *shared_user_parseFromJSON(cJSON *shared_userJSON){

    shared_user_t *shared_user_local_var = NULL;

    // define the local list for shared_user->photo
    list_t *photoList = NULL;

    // shared_user->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(shared_userJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(user_id))
    {
    goto end; //Numeric
    }

    // shared_user->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(shared_userJSON, "first_name");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (first_name) { 
    if(!cJSON_IsString(first_name) && !cJSON_IsNull(first_name))
    {
    goto end; //String
    }
    }

    // shared_user->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(shared_userJSON, "last_name");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }

    // shared_user->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(shared_userJSON, "username");
    if (cJSON_IsNull(username)) {
        username = NULL;
    }
    if (username) { 
    if(!cJSON_IsString(username) && !cJSON_IsNull(username))
    {
    goto end; //String
    }
    }

    // shared_user->photo
    cJSON *photo = cJSON_GetObjectItemCaseSensitive(shared_userJSON, "photo");
    if (cJSON_IsNull(photo)) {
        photo = NULL;
    }
    if (photo) { 
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
    }


    shared_user_local_var = shared_user_create_internal (
        user_id->valuedouble,
        first_name && !cJSON_IsNull(first_name) ? strdup(first_name->valuestring) : NULL,
        last_name && !cJSON_IsNull(last_name) ? strdup(last_name->valuestring) : NULL,
        username && !cJSON_IsNull(username) ? strdup(username->valuestring) : NULL,
        photo ? photoList : NULL
        );

    return shared_user_local_var;
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
