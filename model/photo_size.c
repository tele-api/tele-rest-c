#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "photo_size.h"



static photo_size_t *photo_size_create_internal(
    char *file_id,
    char *file_unique_id,
    int width,
    int height,
    int file_size
    ) {
    photo_size_t *photo_size_local_var = malloc(sizeof(photo_size_t));
    if (!photo_size_local_var) {
        return NULL;
    }
    photo_size_local_var->file_id = file_id;
    photo_size_local_var->file_unique_id = file_unique_id;
    photo_size_local_var->width = width;
    photo_size_local_var->height = height;
    photo_size_local_var->file_size = file_size;

    photo_size_local_var->_library_owned = 1;
    return photo_size_local_var;
}

__attribute__((deprecated)) photo_size_t *photo_size_create(
    char *file_id,
    char *file_unique_id,
    int width,
    int height,
    int file_size
    ) {
    return photo_size_create_internal (
        file_id,
        file_unique_id,
        width,
        height,
        file_size
        );
}

void photo_size_free(photo_size_t *photo_size) {
    if(NULL == photo_size){
        return ;
    }
    if(photo_size->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "photo_size_free");
        return ;
    }
    listEntry_t *listEntry;
    if (photo_size->file_id) {
        free(photo_size->file_id);
        photo_size->file_id = NULL;
    }
    if (photo_size->file_unique_id) {
        free(photo_size->file_unique_id);
        photo_size->file_unique_id = NULL;
    }
    free(photo_size);
}

cJSON *photo_size_convertToJSON(photo_size_t *photo_size) {
    cJSON *item = cJSON_CreateObject();

    // photo_size->file_id
    if (!photo_size->file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_id", photo_size->file_id) == NULL) {
    goto fail; //String
    }


    // photo_size->file_unique_id
    if (!photo_size->file_unique_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_unique_id", photo_size->file_unique_id) == NULL) {
    goto fail; //String
    }


    // photo_size->width
    if (!photo_size->width) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "width", photo_size->width) == NULL) {
    goto fail; //Numeric
    }


    // photo_size->height
    if (!photo_size->height) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "height", photo_size->height) == NULL) {
    goto fail; //Numeric
    }


    // photo_size->file_size
    if(photo_size->file_size) {
    if(cJSON_AddNumberToObject(item, "file_size", photo_size->file_size) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

photo_size_t *photo_size_parseFromJSON(cJSON *photo_sizeJSON){

    photo_size_t *photo_size_local_var = NULL;

    // photo_size->file_id
    cJSON *file_id = cJSON_GetObjectItemCaseSensitive(photo_sizeJSON, "file_id");
    if (cJSON_IsNull(file_id)) {
        file_id = NULL;
    }
    if (!file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(file_id))
    {
    goto end; //String
    }

    // photo_size->file_unique_id
    cJSON *file_unique_id = cJSON_GetObjectItemCaseSensitive(photo_sizeJSON, "file_unique_id");
    if (cJSON_IsNull(file_unique_id)) {
        file_unique_id = NULL;
    }
    if (!file_unique_id) {
        goto end;
    }

    
    if(!cJSON_IsString(file_unique_id))
    {
    goto end; //String
    }

    // photo_size->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(photo_sizeJSON, "width");
    if (cJSON_IsNull(width)) {
        width = NULL;
    }
    if (!width) {
        goto end;
    }

    
    if(!cJSON_IsNumber(width))
    {
    goto end; //Numeric
    }

    // photo_size->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(photo_sizeJSON, "height");
    if (cJSON_IsNull(height)) {
        height = NULL;
    }
    if (!height) {
        goto end;
    }

    
    if(!cJSON_IsNumber(height))
    {
    goto end; //Numeric
    }

    // photo_size->file_size
    cJSON *file_size = cJSON_GetObjectItemCaseSensitive(photo_sizeJSON, "file_size");
    if (cJSON_IsNull(file_size)) {
        file_size = NULL;
    }
    if (file_size) { 
    if(!cJSON_IsNumber(file_size))
    {
    goto end; //Numeric
    }
    }


    photo_size_local_var = photo_size_create_internal (
        strdup(file_id->valuestring),
        strdup(file_unique_id->valuestring),
        width->valuedouble,
        height->valuedouble,
        file_size ? file_size->valuedouble : 0
        );

    return photo_size_local_var;
end:
    return NULL;

}
