#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "passport_element_error_files.h"


char* passport_element_error_files_type_ToString(telegram_bot_api_passport_element_error_files_TYPE_e type) {
    char* typeArray[] =  { "NULL", "utility_bill", "bank_statement", "rental_agreement", "passport_registration", "temporary_registration" };
    return typeArray[type];
}

telegram_bot_api_passport_element_error_files_TYPE_e passport_element_error_files_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "utility_bill", "bank_statement", "rental_agreement", "passport_registration", "temporary_registration" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static passport_element_error_files_t *passport_element_error_files_create_internal(
    char *source,
    telegram_bot_api_passport_element_error_files_TYPE_e type,
    list_t *file_hashes,
    char *message
    ) {
    passport_element_error_files_t *passport_element_error_files_local_var = malloc(sizeof(passport_element_error_files_t));
    if (!passport_element_error_files_local_var) {
        return NULL;
    }
    passport_element_error_files_local_var->source = source;
    passport_element_error_files_local_var->type = type;
    passport_element_error_files_local_var->file_hashes = file_hashes;
    passport_element_error_files_local_var->message = message;

    passport_element_error_files_local_var->_library_owned = 1;
    return passport_element_error_files_local_var;
}

__attribute__((deprecated)) passport_element_error_files_t *passport_element_error_files_create(
    char *source,
    telegram_bot_api_passport_element_error_files_TYPE_e type,
    list_t *file_hashes,
    char *message
    ) {
    return passport_element_error_files_create_internal (
        source,
        type,
        file_hashes,
        message
        );
}

void passport_element_error_files_free(passport_element_error_files_t *passport_element_error_files) {
    if(NULL == passport_element_error_files){
        return ;
    }
    if(passport_element_error_files->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "passport_element_error_files_free");
        return ;
    }
    listEntry_t *listEntry;
    if (passport_element_error_files->source) {
        free(passport_element_error_files->source);
        passport_element_error_files->source = NULL;
    }
    if (passport_element_error_files->file_hashes) {
        list_ForEach(listEntry, passport_element_error_files->file_hashes) {
            free(listEntry->data);
        }
        list_freeList(passport_element_error_files->file_hashes);
        passport_element_error_files->file_hashes = NULL;
    }
    if (passport_element_error_files->message) {
        free(passport_element_error_files->message);
        passport_element_error_files->message = NULL;
    }
    free(passport_element_error_files);
}

cJSON *passport_element_error_files_convertToJSON(passport_element_error_files_t *passport_element_error_files) {
    cJSON *item = cJSON_CreateObject();

    // passport_element_error_files->source
    if (!passport_element_error_files->source) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "source", passport_element_error_files->source) == NULL) {
    goto fail; //String
    }


    // passport_element_error_files->type
    if (telegram_bot_api_passport_element_error_files_TYPE_NULL == passport_element_error_files->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", passport_element_error_files_type_ToString(passport_element_error_files->type)) == NULL)
    {
    goto fail; //Enum
    }


    // passport_element_error_files->file_hashes
    if (!passport_element_error_files->file_hashes) {
        goto fail;
    }
    cJSON *file_hashes = cJSON_AddArrayToObject(item, "file_hashes");
    if(file_hashes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *file_hashesListEntry;
    list_ForEach(file_hashesListEntry, passport_element_error_files->file_hashes) {
    if(cJSON_AddStringToObject(file_hashes, "", file_hashesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // passport_element_error_files->message
    if (!passport_element_error_files->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", passport_element_error_files->message) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

passport_element_error_files_t *passport_element_error_files_parseFromJSON(cJSON *passport_element_error_filesJSON){

    passport_element_error_files_t *passport_element_error_files_local_var = NULL;

    // define the local list for passport_element_error_files->file_hashes
    list_t *file_hashesList = NULL;

    // passport_element_error_files->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(passport_element_error_filesJSON, "source");
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

    // passport_element_error_files->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(passport_element_error_filesJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    telegram_bot_api_passport_element_error_files_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = passport_element_error_files_type_FromString(type->valuestring);

    // passport_element_error_files->file_hashes
    cJSON *file_hashes = cJSON_GetObjectItemCaseSensitive(passport_element_error_filesJSON, "file_hashes");
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

    // passport_element_error_files->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(passport_element_error_filesJSON, "message");
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


    passport_element_error_files_local_var = passport_element_error_files_create_internal (
        strdup(source->valuestring),
        typeVariable,
        file_hashesList,
        strdup(message->valuestring)
        );

    return passport_element_error_files_local_var;
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
