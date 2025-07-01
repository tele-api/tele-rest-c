#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_photo.h"



static chat_photo_t *chat_photo_create_internal(
    char *small_file_id,
    char *small_file_unique_id,
    char *big_file_id,
    char *big_file_unique_id
    ) {
    chat_photo_t *chat_photo_local_var = malloc(sizeof(chat_photo_t));
    if (!chat_photo_local_var) {
        return NULL;
    }
    chat_photo_local_var->small_file_id = small_file_id;
    chat_photo_local_var->small_file_unique_id = small_file_unique_id;
    chat_photo_local_var->big_file_id = big_file_id;
    chat_photo_local_var->big_file_unique_id = big_file_unique_id;

    chat_photo_local_var->_library_owned = 1;
    return chat_photo_local_var;
}

__attribute__((deprecated)) chat_photo_t *chat_photo_create(
    char *small_file_id,
    char *small_file_unique_id,
    char *big_file_id,
    char *big_file_unique_id
    ) {
    return chat_photo_create_internal (
        small_file_id,
        small_file_unique_id,
        big_file_id,
        big_file_unique_id
        );
}

void chat_photo_free(chat_photo_t *chat_photo) {
    if(NULL == chat_photo){
        return ;
    }
    if(chat_photo->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_photo_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_photo->small_file_id) {
        free(chat_photo->small_file_id);
        chat_photo->small_file_id = NULL;
    }
    if (chat_photo->small_file_unique_id) {
        free(chat_photo->small_file_unique_id);
        chat_photo->small_file_unique_id = NULL;
    }
    if (chat_photo->big_file_id) {
        free(chat_photo->big_file_id);
        chat_photo->big_file_id = NULL;
    }
    if (chat_photo->big_file_unique_id) {
        free(chat_photo->big_file_unique_id);
        chat_photo->big_file_unique_id = NULL;
    }
    free(chat_photo);
}

cJSON *chat_photo_convertToJSON(chat_photo_t *chat_photo) {
    cJSON *item = cJSON_CreateObject();

    // chat_photo->small_file_id
    if (!chat_photo->small_file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "small_file_id", chat_photo->small_file_id) == NULL) {
    goto fail; //String
    }


    // chat_photo->small_file_unique_id
    if (!chat_photo->small_file_unique_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "small_file_unique_id", chat_photo->small_file_unique_id) == NULL) {
    goto fail; //String
    }


    // chat_photo->big_file_id
    if (!chat_photo->big_file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "big_file_id", chat_photo->big_file_id) == NULL) {
    goto fail; //String
    }


    // chat_photo->big_file_unique_id
    if (!chat_photo->big_file_unique_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "big_file_unique_id", chat_photo->big_file_unique_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

chat_photo_t *chat_photo_parseFromJSON(cJSON *chat_photoJSON){

    chat_photo_t *chat_photo_local_var = NULL;

    // chat_photo->small_file_id
    cJSON *small_file_id = cJSON_GetObjectItemCaseSensitive(chat_photoJSON, "small_file_id");
    if (cJSON_IsNull(small_file_id)) {
        small_file_id = NULL;
    }
    if (!small_file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(small_file_id))
    {
    goto end; //String
    }

    // chat_photo->small_file_unique_id
    cJSON *small_file_unique_id = cJSON_GetObjectItemCaseSensitive(chat_photoJSON, "small_file_unique_id");
    if (cJSON_IsNull(small_file_unique_id)) {
        small_file_unique_id = NULL;
    }
    if (!small_file_unique_id) {
        goto end;
    }

    
    if(!cJSON_IsString(small_file_unique_id))
    {
    goto end; //String
    }

    // chat_photo->big_file_id
    cJSON *big_file_id = cJSON_GetObjectItemCaseSensitive(chat_photoJSON, "big_file_id");
    if (cJSON_IsNull(big_file_id)) {
        big_file_id = NULL;
    }
    if (!big_file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(big_file_id))
    {
    goto end; //String
    }

    // chat_photo->big_file_unique_id
    cJSON *big_file_unique_id = cJSON_GetObjectItemCaseSensitive(chat_photoJSON, "big_file_unique_id");
    if (cJSON_IsNull(big_file_unique_id)) {
        big_file_unique_id = NULL;
    }
    if (!big_file_unique_id) {
        goto end;
    }

    
    if(!cJSON_IsString(big_file_unique_id))
    {
    goto end; //String
    }


    chat_photo_local_var = chat_photo_create_internal (
        strdup(small_file_id->valuestring),
        strdup(small_file_unique_id->valuestring),
        strdup(big_file_id->valuestring),
        strdup(big_file_unique_id->valuestring)
        );

    return chat_photo_local_var;
end:
    return NULL;

}
