#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "passport_element_error.h"



static passport_element_error_t *passport_element_error_create_internal(
    char *source,
    char *type,
    char *field_name,
    char *data_hash,
    char *message,
    char *file_hash,
    list_t *file_hashes,
    char *element_hash
    ) {
    passport_element_error_t *passport_element_error_local_var = malloc(sizeof(passport_element_error_t));
    if (!passport_element_error_local_var) {
        return NULL;
    }
    passport_element_error_local_var->source = source;
    passport_element_error_local_var->type = type;
    passport_element_error_local_var->field_name = field_name;
    passport_element_error_local_var->data_hash = data_hash;
    passport_element_error_local_var->message = message;
    passport_element_error_local_var->file_hash = file_hash;
    passport_element_error_local_var->file_hashes = file_hashes;
    passport_element_error_local_var->element_hash = element_hash;

    passport_element_error_local_var->_library_owned = 1;
    return passport_element_error_local_var;
}

__attribute__((deprecated)) passport_element_error_t *passport_element_error_create(
    char *source,
    char *type,
    char *field_name,
    char *data_hash,
    char *message,
    char *file_hash,
    list_t *file_hashes,
    char *element_hash
    ) {
    return passport_element_error_create_internal (
        source,
        type,
        field_name,
        data_hash,
        message,
        file_hash,
        file_hashes,
        element_hash
        );
}

void passport_element_error_free(passport_element_error_t *passport_element_error) {
    if(NULL == passport_element_error){
        return ;
    }
    if(passport_element_error->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "passport_element_error_free");
        return ;
    }
    listEntry_t *listEntry;
    if (passport_element_error->source) {
        free(passport_element_error->source);
        passport_element_error->source = NULL;
    }
    if (passport_element_error->type) {
        free(passport_element_error->type);
        passport_element_error->type = NULL;
    }
    if (passport_element_error->field_name) {
        free(passport_element_error->field_name);
        passport_element_error->field_name = NULL;
    }
    if (passport_element_error->data_hash) {
        free(passport_element_error->data_hash);
        passport_element_error->data_hash = NULL;
    }
    if (passport_element_error->message) {
        free(passport_element_error->message);
        passport_element_error->message = NULL;
    }
    if (passport_element_error->file_hash) {
        free(passport_element_error->file_hash);
        passport_element_error->file_hash = NULL;
    }
    if (passport_element_error->file_hashes) {
        list_ForEach(listEntry, passport_element_error->file_hashes) {
            free(listEntry->data);
        }
        list_freeList(passport_element_error->file_hashes);
        passport_element_error->file_hashes = NULL;
    }
    if (passport_element_error->element_hash) {
        free(passport_element_error->element_hash);
        passport_element_error->element_hash = NULL;
    }
    free(passport_element_error);
}

cJSON *passport_element_error_convertToJSON(passport_element_error_t *passport_element_error) {
    cJSON *item = cJSON_CreateObject();

    // passport_element_error->source
    if (!passport_element_error->source) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "source", passport_element_error->source) == NULL) {
    goto fail; //String
    }


    // passport_element_error->type
    if (!passport_element_error->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", passport_element_error->type) == NULL) {
    goto fail; //String
    }


    // passport_element_error->field_name
    if (!passport_element_error->field_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "field_name", passport_element_error->field_name) == NULL) {
    goto fail; //String
    }


    // passport_element_error->data_hash
    if (!passport_element_error->data_hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "data_hash", passport_element_error->data_hash) == NULL) {
    goto fail; //String
    }


    // passport_element_error->message
    if (!passport_element_error->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", passport_element_error->message) == NULL) {
    goto fail; //String
    }


    // passport_element_error->file_hash
    if (!passport_element_error->file_hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_hash", passport_element_error->file_hash) == NULL) {
    goto fail; //String
    }


    // passport_element_error->file_hashes
    if (!passport_element_error->file_hashes) {
        goto fail;
    }
    cJSON *file_hashes = cJSON_AddArrayToObject(item, "file_hashes");
    if(file_hashes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *file_hashesListEntry;
    list_ForEach(file_hashesListEntry, passport_element_error->file_hashes) {
    if(cJSON_AddStringToObject(file_hashes, "", file_hashesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // passport_element_error->element_hash
    if (!passport_element_error->element_hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "element_hash", passport_element_error->element_hash) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

passport_element_error_t *passport_element_error_parseFromJSON(cJSON *passport_element_errorJSON){

    passport_element_error_t *passport_element_error_local_var = NULL;

    // define the local list for passport_element_error->file_hashes
    list_t *file_hashesList = NULL;

    // passport_element_error->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(passport_element_errorJSON, "source");
    if (cJSON_IsNull(source)) {
        source = NULL;
    }
    if (!source) {
        goto end;
    }

    
    if(!cJSON_IsString(source))
    {
    goto end; //String
    }

    // passport_element_error->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(passport_element_errorJSON, "type");
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

    // passport_element_error->field_name
    cJSON *field_name = cJSON_GetObjectItemCaseSensitive(passport_element_errorJSON, "field_name");
    if (cJSON_IsNull(field_name)) {
        field_name = NULL;
    }
    if (!field_name) {
        goto end;
    }

    
    if(!cJSON_IsString(field_name))
    {
    goto end; //String
    }

    // passport_element_error->data_hash
    cJSON *data_hash = cJSON_GetObjectItemCaseSensitive(passport_element_errorJSON, "data_hash");
    if (cJSON_IsNull(data_hash)) {
        data_hash = NULL;
    }
    if (!data_hash) {
        goto end;
    }

    
    if(!cJSON_IsString(data_hash))
    {
    goto end; //String
    }

    // passport_element_error->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(passport_element_errorJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (!message) {
        goto end;
    }

    
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }

    // passport_element_error->file_hash
    cJSON *file_hash = cJSON_GetObjectItemCaseSensitive(passport_element_errorJSON, "file_hash");
    if (cJSON_IsNull(file_hash)) {
        file_hash = NULL;
    }
    if (!file_hash) {
        goto end;
    }

    
    if(!cJSON_IsString(file_hash))
    {
    goto end; //String
    }

    // passport_element_error->file_hashes
    cJSON *file_hashes = cJSON_GetObjectItemCaseSensitive(passport_element_errorJSON, "file_hashes");
    if (cJSON_IsNull(file_hashes)) {
        file_hashes = NULL;
    }
    if (!file_hashes) {
        goto end;
    }

    
    cJSON *file_hashes_local = NULL;
    if(!cJSON_IsArray(file_hashes)) {
        goto end;//primitive container
    }
    file_hashesList = list_createList();

    cJSON_ArrayForEach(file_hashes_local, file_hashes)
    {
        if(!cJSON_IsString(file_hashes_local))
        {
            goto end;
        }
        list_addElement(file_hashesList , strdup(file_hashes_local->valuestring));
    }

    // passport_element_error->element_hash
    cJSON *element_hash = cJSON_GetObjectItemCaseSensitive(passport_element_errorJSON, "element_hash");
    if (cJSON_IsNull(element_hash)) {
        element_hash = NULL;
    }
    if (!element_hash) {
        goto end;
    }

    
    if(!cJSON_IsString(element_hash))
    {
    goto end; //String
    }


    passport_element_error_local_var = passport_element_error_create_internal (
        strdup(source->valuestring),
        strdup(type->valuestring),
        strdup(field_name->valuestring),
        strdup(data_hash->valuestring),
        strdup(message->valuestring),
        strdup(file_hash->valuestring),
        file_hashesList,
        strdup(element_hash->valuestring)
        );

    return passport_element_error_local_var;
end:
    if (file_hashesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, file_hashesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(file_hashesList);
        file_hashesList = NULL;
    }
    return NULL;

}
