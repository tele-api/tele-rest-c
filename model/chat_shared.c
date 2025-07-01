#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_shared.h"



static chat_shared_t *chat_shared_create_internal(
    int request_id,
    int chat_id,
    char *title,
    char *username,
    list_t *photo
    ) {
    chat_shared_t *chat_shared_local_var = malloc(sizeof(chat_shared_t));
    if (!chat_shared_local_var) {
        return NULL;
    }
    chat_shared_local_var->request_id = request_id;
    chat_shared_local_var->chat_id = chat_id;
    chat_shared_local_var->title = title;
    chat_shared_local_var->username = username;
    chat_shared_local_var->photo = photo;

    chat_shared_local_var->_library_owned = 1;
    return chat_shared_local_var;
}

__attribute__((deprecated)) chat_shared_t *chat_shared_create(
    int request_id,
    int chat_id,
    char *title,
    char *username,
    list_t *photo
    ) {
    return chat_shared_create_internal (
        request_id,
        chat_id,
        title,
        username,
        photo
        );
}

void chat_shared_free(chat_shared_t *chat_shared) {
    if(NULL == chat_shared){
        return ;
    }
    if(chat_shared->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_shared_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_shared->title) {
        free(chat_shared->title);
        chat_shared->title = NULL;
    }
    if (chat_shared->username) {
        free(chat_shared->username);
        chat_shared->username = NULL;
    }
    if (chat_shared->photo) {
        list_ForEach(listEntry, chat_shared->photo) {
            photo_size_free(listEntry->data);
        }
        list_freeList(chat_shared->photo);
        chat_shared->photo = NULL;
    }
    free(chat_shared);
}

cJSON *chat_shared_convertToJSON(chat_shared_t *chat_shared) {
    cJSON *item = cJSON_CreateObject();

    // chat_shared->request_id
    if (!chat_shared->request_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "request_id", chat_shared->request_id) == NULL) {
    goto fail; //Numeric
    }


    // chat_shared->chat_id
    if (!chat_shared->chat_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "chat_id", chat_shared->chat_id) == NULL) {
    goto fail; //Numeric
    }


    // chat_shared->title
    if(chat_shared->title) {
    if(cJSON_AddStringToObject(item, "title", chat_shared->title) == NULL) {
    goto fail; //String
    }
    }


    // chat_shared->username
    if(chat_shared->username) {
    if(cJSON_AddStringToObject(item, "username", chat_shared->username) == NULL) {
    goto fail; //String
    }
    }


    // chat_shared->photo
    if(chat_shared->photo) {
    cJSON *photo = cJSON_AddArrayToObject(item, "photo");
    if(photo == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *photoListEntry;
    if (chat_shared->photo) {
    list_ForEach(photoListEntry, chat_shared->photo) {
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

chat_shared_t *chat_shared_parseFromJSON(cJSON *chat_sharedJSON){

    chat_shared_t *chat_shared_local_var = NULL;

    // define the local list for chat_shared->photo
    list_t *photoList = NULL;

    // chat_shared->request_id
    cJSON *request_id = cJSON_GetObjectItemCaseSensitive(chat_sharedJSON, "request_id");
    if (cJSON_IsNull(request_id)) {
        request_id = NULL;
    }
    if (!request_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(request_id))
    {
    goto end; //Numeric
    }

    // chat_shared->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(chat_sharedJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(chat_id))
    {
    goto end; //Numeric
    }

    // chat_shared->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(chat_sharedJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // chat_shared->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(chat_sharedJSON, "username");
    if (cJSON_IsNull(username)) {
        username = NULL;
    }
    if (username) { 
    if(!cJSON_IsString(username) && !cJSON_IsNull(username))
    {
    goto end; //String
    }
    }

    // chat_shared->photo
    cJSON *photo = cJSON_GetObjectItemCaseSensitive(chat_sharedJSON, "photo");
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


    chat_shared_local_var = chat_shared_create_internal (
        request_id->valuedouble,
        chat_id->valuedouble,
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        username && !cJSON_IsNull(username) ? strdup(username->valuestring) : NULL,
        photo ? photoList : NULL
        );

    return chat_shared_local_var;
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
