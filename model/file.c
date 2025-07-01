#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "file.h"



static file_t *file_create_internal(
    char *file_id,
    char *file_unique_id,
    int file_size,
    char *file_path
    ) {
    file_t *file_local_var = malloc(sizeof(file_t));
    if (!file_local_var) {
        return NULL;
    }
    file_local_var->file_id = file_id;
    file_local_var->file_unique_id = file_unique_id;
    file_local_var->file_size = file_size;
    file_local_var->file_path = file_path;

    file_local_var->_library_owned = 1;
    return file_local_var;
}

__attribute__((deprecated)) file_t *file_create(
    char *file_id,
    char *file_unique_id,
    int file_size,
    char *file_path
    ) {
    return file_create_internal (
        file_id,
        file_unique_id,
        file_size,
        file_path
        );
}

void file_free(file_t *file) {
    if(NULL == file){
        return ;
    }
    if(file->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "file_free");
        return ;
    }
    listEntry_t *listEntry;
    if (file->file_id) {
        free(file->file_id);
        file->file_id = NULL;
    }
    if (file->file_unique_id) {
        free(file->file_unique_id);
        file->file_unique_id = NULL;
    }
    if (file->file_path) {
        free(file->file_path);
        file->file_path = NULL;
    }
    free(file);
}

cJSON *file_convertToJSON(file_t *file) {
    cJSON *item = cJSON_CreateObject();

    // file->file_id
    if (!file->file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_id", file->file_id) == NULL) {
    goto fail; //String
    }


    // file->file_unique_id
    if (!file->file_unique_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_unique_id", file->file_unique_id) == NULL) {
    goto fail; //String
    }


    // file->file_size
    if(file->file_size) {
    if(cJSON_AddNumberToObject(item, "file_size", file->file_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // file->file_path
    if(file->file_path) {
    if(cJSON_AddStringToObject(item, "file_path", file->file_path) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

file_t *file_parseFromJSON(cJSON *fileJSON){

    file_t *file_local_var = NULL;

    // file->file_id
    cJSON *file_id = cJSON_GetObjectItemCaseSensitive(fileJSON, "file_id");
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

    // file->file_unique_id
    cJSON *file_unique_id = cJSON_GetObjectItemCaseSensitive(fileJSON, "file_unique_id");
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

    // file->file_size
    cJSON *file_size = cJSON_GetObjectItemCaseSensitive(fileJSON, "file_size");
    if (cJSON_IsNull(file_size)) {
        file_size = NULL;
    }
    if (file_size) { 
    if(!cJSON_IsNumber(file_size))
    {
    goto end; //Numeric
    }
    }

    // file->file_path
    cJSON *file_path = cJSON_GetObjectItemCaseSensitive(fileJSON, "file_path");
    if (cJSON_IsNull(file_path)) {
        file_path = NULL;
    }
    if (file_path) { 
    if(!cJSON_IsString(file_path) && !cJSON_IsNull(file_path))
    {
    goto end; //String
    }
    }


    file_local_var = file_create_internal (
        strdup(file_id->valuestring),
        strdup(file_unique_id->valuestring),
        file_size ? file_size->valuedouble : 0,
        file_path && !cJSON_IsNull(file_path) ? strdup(file_path->valuestring) : NULL
        );

    return file_local_var;
end:
    return NULL;

}
