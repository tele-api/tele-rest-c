#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "passport_file.h"



static passport_file_t *passport_file_create_internal(
    char *file_id,
    char *file_unique_id,
    int file_size,
    int file_date
    ) {
    passport_file_t *passport_file_local_var = malloc(sizeof(passport_file_t));
    if (!passport_file_local_var) {
        return NULL;
    }
    passport_file_local_var->file_id = file_id;
    passport_file_local_var->file_unique_id = file_unique_id;
    passport_file_local_var->file_size = file_size;
    passport_file_local_var->file_date = file_date;

    passport_file_local_var->_library_owned = 1;
    return passport_file_local_var;
}

__attribute__((deprecated)) passport_file_t *passport_file_create(
    char *file_id,
    char *file_unique_id,
    int file_size,
    int file_date
    ) {
    return passport_file_create_internal (
        file_id,
        file_unique_id,
        file_size,
        file_date
        );
}

void passport_file_free(passport_file_t *passport_file) {
    if(NULL == passport_file){
        return ;
    }
    if(passport_file->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "passport_file_free");
        return ;
    }
    listEntry_t *listEntry;
    if (passport_file->file_id) {
        free(passport_file->file_id);
        passport_file->file_id = NULL;
    }
    if (passport_file->file_unique_id) {
        free(passport_file->file_unique_id);
        passport_file->file_unique_id = NULL;
    }
    free(passport_file);
}

cJSON *passport_file_convertToJSON(passport_file_t *passport_file) {
    cJSON *item = cJSON_CreateObject();

    // passport_file->file_id
    if (!passport_file->file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_id", passport_file->file_id) == NULL) {
    goto fail; //String
    }


    // passport_file->file_unique_id
    if (!passport_file->file_unique_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_unique_id", passport_file->file_unique_id) == NULL) {
    goto fail; //String
    }


    // passport_file->file_size
    if (!passport_file->file_size) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "file_size", passport_file->file_size) == NULL) {
    goto fail; //Numeric
    }


    // passport_file->file_date
    if (!passport_file->file_date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "file_date", passport_file->file_date) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

passport_file_t *passport_file_parseFromJSON(cJSON *passport_fileJSON){

    passport_file_t *passport_file_local_var = NULL;

    // passport_file->file_id
    cJSON *file_id = cJSON_GetObjectItemCaseSensitive(passport_fileJSON, "file_id");
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

    // passport_file->file_unique_id
    cJSON *file_unique_id = cJSON_GetObjectItemCaseSensitive(passport_fileJSON, "file_unique_id");
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

    // passport_file->file_size
    cJSON *file_size = cJSON_GetObjectItemCaseSensitive(passport_fileJSON, "file_size");
    if (cJSON_IsNull(file_size)) {
        file_size = NULL;
    }
    if (!file_size) {
        goto end;
    }

    
    if(!cJSON_IsNumber(file_size))
    {
    goto end; //Numeric
    }

    // passport_file->file_date
    cJSON *file_date = cJSON_GetObjectItemCaseSensitive(passport_fileJSON, "file_date");
    if (cJSON_IsNull(file_date)) {
        file_date = NULL;
    }
    if (!file_date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(file_date))
    {
    goto end; //Numeric
    }


    passport_file_local_var = passport_file_create_internal (
        strdup(file_id->valuestring),
        strdup(file_unique_id->valuestring),
        file_size->valuedouble,
        file_date->valuedouble
        );

    return passport_file_local_var;
end:
    return NULL;

}
