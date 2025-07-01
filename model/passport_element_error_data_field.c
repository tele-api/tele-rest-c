#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "passport_element_error_data_field.h"


char* passport_element_error_data_field_type_ToString(telegram_bot_api_passport_element_error_data_field_TYPE_e type) {
    char* typeArray[] =  { "NULL", "personal_details", "passport", "driver_license", "identity_card", "internal_passport", "address" };
    return typeArray[type];
}

telegram_bot_api_passport_element_error_data_field_TYPE_e passport_element_error_data_field_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "personal_details", "passport", "driver_license", "identity_card", "internal_passport", "address" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static passport_element_error_data_field_t *passport_element_error_data_field_create_internal(
    char *source,
    telegram_bot_api_passport_element_error_data_field_TYPE_e type,
    char *field_name,
    char *data_hash,
    char *message
    ) {
    passport_element_error_data_field_t *passport_element_error_data_field_local_var = malloc(sizeof(passport_element_error_data_field_t));
    if (!passport_element_error_data_field_local_var) {
        return NULL;
    }
    passport_element_error_data_field_local_var->source = source;
    passport_element_error_data_field_local_var->type = type;
    passport_element_error_data_field_local_var->field_name = field_name;
    passport_element_error_data_field_local_var->data_hash = data_hash;
    passport_element_error_data_field_local_var->message = message;

    passport_element_error_data_field_local_var->_library_owned = 1;
    return passport_element_error_data_field_local_var;
}

__attribute__((deprecated)) passport_element_error_data_field_t *passport_element_error_data_field_create(
    char *source,
    telegram_bot_api_passport_element_error_data_field_TYPE_e type,
    char *field_name,
    char *data_hash,
    char *message
    ) {
    return passport_element_error_data_field_create_internal (
        source,
        type,
        field_name,
        data_hash,
        message
        );
}

void passport_element_error_data_field_free(passport_element_error_data_field_t *passport_element_error_data_field) {
    if(NULL == passport_element_error_data_field){
        return ;
    }
    if(passport_element_error_data_field->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "passport_element_error_data_field_free");
        return ;
    }
    listEntry_t *listEntry;
    if (passport_element_error_data_field->source) {
        free(passport_element_error_data_field->source);
        passport_element_error_data_field->source = NULL;
    }
    if (passport_element_error_data_field->field_name) {
        free(passport_element_error_data_field->field_name);
        passport_element_error_data_field->field_name = NULL;
    }
    if (passport_element_error_data_field->data_hash) {
        free(passport_element_error_data_field->data_hash);
        passport_element_error_data_field->data_hash = NULL;
    }
    if (passport_element_error_data_field->message) {
        free(passport_element_error_data_field->message);
        passport_element_error_data_field->message = NULL;
    }
    free(passport_element_error_data_field);
}

cJSON *passport_element_error_data_field_convertToJSON(passport_element_error_data_field_t *passport_element_error_data_field) {
    cJSON *item = cJSON_CreateObject();

    // passport_element_error_data_field->source
    if (!passport_element_error_data_field->source) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "source", passport_element_error_data_field->source) == NULL) {
    goto fail; //String
    }


    // passport_element_error_data_field->type
    if (telegram_bot_api_passport_element_error_data_field_TYPE_NULL == passport_element_error_data_field->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", passport_element_error_data_field_type_ToString(passport_element_error_data_field->type)) == NULL)
    {
    goto fail; //Enum
    }


    // passport_element_error_data_field->field_name
    if (!passport_element_error_data_field->field_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "field_name", passport_element_error_data_field->field_name) == NULL) {
    goto fail; //String
    }


    // passport_element_error_data_field->data_hash
    if (!passport_element_error_data_field->data_hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "data_hash", passport_element_error_data_field->data_hash) == NULL) {
    goto fail; //String
    }


    // passport_element_error_data_field->message
    if (!passport_element_error_data_field->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", passport_element_error_data_field->message) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

passport_element_error_data_field_t *passport_element_error_data_field_parseFromJSON(cJSON *passport_element_error_data_fieldJSON){

    passport_element_error_data_field_t *passport_element_error_data_field_local_var = NULL;

    // passport_element_error_data_field->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(passport_element_error_data_fieldJSON, "source");
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

    // passport_element_error_data_field->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(passport_element_error_data_fieldJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    telegram_bot_api_passport_element_error_data_field_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = passport_element_error_data_field_type_FromString(type->valuestring);

    // passport_element_error_data_field->field_name
    cJSON *field_name = cJSON_GetObjectItemCaseSensitive(passport_element_error_data_fieldJSON, "field_name");
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

    // passport_element_error_data_field->data_hash
    cJSON *data_hash = cJSON_GetObjectItemCaseSensitive(passport_element_error_data_fieldJSON, "data_hash");
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

    // passport_element_error_data_field->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(passport_element_error_data_fieldJSON, "message");
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


    passport_element_error_data_field_local_var = passport_element_error_data_field_create_internal (
        strdup(source->valuestring),
        typeVariable,
        strdup(field_name->valuestring),
        strdup(data_hash->valuestring),
        strdup(message->valuestring)
        );

    return passport_element_error_data_field_local_var;
end:
    return NULL;

}
