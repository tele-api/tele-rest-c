#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "passport_element_error_selfie.h"


char* passport_element_error_selfie_type_ToString(telegram_bot_api_passport_element_error_selfie_TYPE_e type) {
    char* typeArray[] =  { "NULL", "passport", "driver_license", "identity_card", "internal_passport" };
    return typeArray[type];
}

telegram_bot_api_passport_element_error_selfie_TYPE_e passport_element_error_selfie_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "passport", "driver_license", "identity_card", "internal_passport" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static passport_element_error_selfie_t *passport_element_error_selfie_create_internal(
    char *source,
    telegram_bot_api_passport_element_error_selfie_TYPE_e type,
    char *file_hash,
    char *message
    ) {
    passport_element_error_selfie_t *passport_element_error_selfie_local_var = malloc(sizeof(passport_element_error_selfie_t));
    if (!passport_element_error_selfie_local_var) {
        return NULL;
    }
    passport_element_error_selfie_local_var->source = source;
    passport_element_error_selfie_local_var->type = type;
    passport_element_error_selfie_local_var->file_hash = file_hash;
    passport_element_error_selfie_local_var->message = message;

    passport_element_error_selfie_local_var->_library_owned = 1;
    return passport_element_error_selfie_local_var;
}

__attribute__((deprecated)) passport_element_error_selfie_t *passport_element_error_selfie_create(
    char *source,
    telegram_bot_api_passport_element_error_selfie_TYPE_e type,
    char *file_hash,
    char *message
    ) {
    return passport_element_error_selfie_create_internal (
        source,
        type,
        file_hash,
        message
        );
}

void passport_element_error_selfie_free(passport_element_error_selfie_t *passport_element_error_selfie) {
    if(NULL == passport_element_error_selfie){
        return ;
    }
    if(passport_element_error_selfie->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "passport_element_error_selfie_free");
        return ;
    }
    listEntry_t *listEntry;
    if (passport_element_error_selfie->source) {
        free(passport_element_error_selfie->source);
        passport_element_error_selfie->source = NULL;
    }
    if (passport_element_error_selfie->file_hash) {
        free(passport_element_error_selfie->file_hash);
        passport_element_error_selfie->file_hash = NULL;
    }
    if (passport_element_error_selfie->message) {
        free(passport_element_error_selfie->message);
        passport_element_error_selfie->message = NULL;
    }
    free(passport_element_error_selfie);
}

cJSON *passport_element_error_selfie_convertToJSON(passport_element_error_selfie_t *passport_element_error_selfie) {
    cJSON *item = cJSON_CreateObject();

    // passport_element_error_selfie->source
    if (!passport_element_error_selfie->source) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "source", passport_element_error_selfie->source) == NULL) {
    goto fail; //String
    }


    // passport_element_error_selfie->type
    if (telegram_bot_api_passport_element_error_selfie_TYPE_NULL == passport_element_error_selfie->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", passport_element_error_selfie_type_ToString(passport_element_error_selfie->type)) == NULL)
    {
    goto fail; //Enum
    }


    // passport_element_error_selfie->file_hash
    if (!passport_element_error_selfie->file_hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_hash", passport_element_error_selfie->file_hash) == NULL) {
    goto fail; //String
    }


    // passport_element_error_selfie->message
    if (!passport_element_error_selfie->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", passport_element_error_selfie->message) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

passport_element_error_selfie_t *passport_element_error_selfie_parseFromJSON(cJSON *passport_element_error_selfieJSON){

    passport_element_error_selfie_t *passport_element_error_selfie_local_var = NULL;

    // passport_element_error_selfie->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(passport_element_error_selfieJSON, "source");
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

    // passport_element_error_selfie->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(passport_element_error_selfieJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    telegram_bot_api_passport_element_error_selfie_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = passport_element_error_selfie_type_FromString(type->valuestring);

    // passport_element_error_selfie->file_hash
    cJSON *file_hash = cJSON_GetObjectItemCaseSensitive(passport_element_error_selfieJSON, "file_hash");
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

    // passport_element_error_selfie->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(passport_element_error_selfieJSON, "message");
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


    passport_element_error_selfie_local_var = passport_element_error_selfie_create_internal (
        strdup(source->valuestring),
        typeVariable,
        strdup(file_hash->valuestring),
        strdup(message->valuestring)
        );

    return passport_element_error_selfie_local_var;
end:
    return NULL;

}
