#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "encrypted_passport_element.h"


char* encrypted_passport_element_type_ToString(telegram_bot_api_encrypted_passport_element_TYPE_e type) {
    char* typeArray[] =  { "NULL", "personal_details", "passport", "driver_license", "identity_card", "internal_passport", "address", "utility_bill", "bank_statement", "rental_agreement", "passport_registration", "temporary_registration", "phone_number", "email" };
    return typeArray[type];
}

telegram_bot_api_encrypted_passport_element_TYPE_e encrypted_passport_element_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "personal_details", "passport", "driver_license", "identity_card", "internal_passport", "address", "utility_bill", "bank_statement", "rental_agreement", "passport_registration", "temporary_registration", "phone_number", "email" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static encrypted_passport_element_t *encrypted_passport_element_create_internal(
    telegram_bot_api_encrypted_passport_element_TYPE_e type,
    char *hash,
    char *data,
    char *phone_number,
    char *email,
    list_t *files,
    passport_file_t *front_side,
    passport_file_t *reverse_side,
    passport_file_t *selfie,
    list_t *translation
    ) {
    encrypted_passport_element_t *encrypted_passport_element_local_var = malloc(sizeof(encrypted_passport_element_t));
    if (!encrypted_passport_element_local_var) {
        return NULL;
    }
    encrypted_passport_element_local_var->type = type;
    encrypted_passport_element_local_var->hash = hash;
    encrypted_passport_element_local_var->data = data;
    encrypted_passport_element_local_var->phone_number = phone_number;
    encrypted_passport_element_local_var->email = email;
    encrypted_passport_element_local_var->files = files;
    encrypted_passport_element_local_var->front_side = front_side;
    encrypted_passport_element_local_var->reverse_side = reverse_side;
    encrypted_passport_element_local_var->selfie = selfie;
    encrypted_passport_element_local_var->translation = translation;

    encrypted_passport_element_local_var->_library_owned = 1;
    return encrypted_passport_element_local_var;
}

__attribute__((deprecated)) encrypted_passport_element_t *encrypted_passport_element_create(
    telegram_bot_api_encrypted_passport_element_TYPE_e type,
    char *hash,
    char *data,
    char *phone_number,
    char *email,
    list_t *files,
    passport_file_t *front_side,
    passport_file_t *reverse_side,
    passport_file_t *selfie,
    list_t *translation
    ) {
    return encrypted_passport_element_create_internal (
        type,
        hash,
        data,
        phone_number,
        email,
        files,
        front_side,
        reverse_side,
        selfie,
        translation
        );
}

void encrypted_passport_element_free(encrypted_passport_element_t *encrypted_passport_element) {
    if(NULL == encrypted_passport_element){
        return ;
    }
    if(encrypted_passport_element->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "encrypted_passport_element_free");
        return ;
    }
    listEntry_t *listEntry;
    if (encrypted_passport_element->hash) {
        free(encrypted_passport_element->hash);
        encrypted_passport_element->hash = NULL;
    }
    if (encrypted_passport_element->data) {
        free(encrypted_passport_element->data);
        encrypted_passport_element->data = NULL;
    }
    if (encrypted_passport_element->phone_number) {
        free(encrypted_passport_element->phone_number);
        encrypted_passport_element->phone_number = NULL;
    }
    if (encrypted_passport_element->email) {
        free(encrypted_passport_element->email);
        encrypted_passport_element->email = NULL;
    }
    if (encrypted_passport_element->files) {
        list_ForEach(listEntry, encrypted_passport_element->files) {
            passport_file_free(listEntry->data);
        }
        list_freeList(encrypted_passport_element->files);
        encrypted_passport_element->files = NULL;
    }
    if (encrypted_passport_element->front_side) {
        passport_file_free(encrypted_passport_element->front_side);
        encrypted_passport_element->front_side = NULL;
    }
    if (encrypted_passport_element->reverse_side) {
        passport_file_free(encrypted_passport_element->reverse_side);
        encrypted_passport_element->reverse_side = NULL;
    }
    if (encrypted_passport_element->selfie) {
        passport_file_free(encrypted_passport_element->selfie);
        encrypted_passport_element->selfie = NULL;
    }
    if (encrypted_passport_element->translation) {
        list_ForEach(listEntry, encrypted_passport_element->translation) {
            passport_file_free(listEntry->data);
        }
        list_freeList(encrypted_passport_element->translation);
        encrypted_passport_element->translation = NULL;
    }
    free(encrypted_passport_element);
}

cJSON *encrypted_passport_element_convertToJSON(encrypted_passport_element_t *encrypted_passport_element) {
    cJSON *item = cJSON_CreateObject();

    // encrypted_passport_element->type
    if (telegram_bot_api_encrypted_passport_element_TYPE_NULL == encrypted_passport_element->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", encrypted_passport_element_type_ToString(encrypted_passport_element->type)) == NULL)
    {
    goto fail; //Enum
    }


    // encrypted_passport_element->hash
    if (!encrypted_passport_element->hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hash", encrypted_passport_element->hash) == NULL) {
    goto fail; //String
    }


    // encrypted_passport_element->data
    if(encrypted_passport_element->data) {
    if(cJSON_AddStringToObject(item, "data", encrypted_passport_element->data) == NULL) {
    goto fail; //String
    }
    }


    // encrypted_passport_element->phone_number
    if(encrypted_passport_element->phone_number) {
    if(cJSON_AddStringToObject(item, "phone_number", encrypted_passport_element->phone_number) == NULL) {
    goto fail; //String
    }
    }


    // encrypted_passport_element->email
    if(encrypted_passport_element->email) {
    if(cJSON_AddStringToObject(item, "email", encrypted_passport_element->email) == NULL) {
    goto fail; //String
    }
    }


    // encrypted_passport_element->files
    if(encrypted_passport_element->files) {
    cJSON *files = cJSON_AddArrayToObject(item, "files");
    if(files == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *filesListEntry;
    if (encrypted_passport_element->files) {
    list_ForEach(filesListEntry, encrypted_passport_element->files) {
    cJSON *itemLocal = passport_file_convertToJSON(filesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(files, itemLocal);
    }
    }
    }


    // encrypted_passport_element->front_side
    if(encrypted_passport_element->front_side) {
    cJSON *front_side_local_JSON = passport_file_convertToJSON(encrypted_passport_element->front_side);
    if(front_side_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "front_side", front_side_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // encrypted_passport_element->reverse_side
    if(encrypted_passport_element->reverse_side) {
    cJSON *reverse_side_local_JSON = passport_file_convertToJSON(encrypted_passport_element->reverse_side);
    if(reverse_side_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reverse_side", reverse_side_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // encrypted_passport_element->selfie
    if(encrypted_passport_element->selfie) {
    cJSON *selfie_local_JSON = passport_file_convertToJSON(encrypted_passport_element->selfie);
    if(selfie_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selfie", selfie_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // encrypted_passport_element->translation
    if(encrypted_passport_element->translation) {
    cJSON *translation = cJSON_AddArrayToObject(item, "translation");
    if(translation == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *translationListEntry;
    if (encrypted_passport_element->translation) {
    list_ForEach(translationListEntry, encrypted_passport_element->translation) {
    cJSON *itemLocal = passport_file_convertToJSON(translationListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(translation, itemLocal);
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

encrypted_passport_element_t *encrypted_passport_element_parseFromJSON(cJSON *encrypted_passport_elementJSON){

    encrypted_passport_element_t *encrypted_passport_element_local_var = NULL;

    // define the local list for encrypted_passport_element->files
    list_t *filesList = NULL;

    // define the local variable for encrypted_passport_element->front_side
    passport_file_t *front_side_local_nonprim = NULL;

    // define the local variable for encrypted_passport_element->reverse_side
    passport_file_t *reverse_side_local_nonprim = NULL;

    // define the local variable for encrypted_passport_element->selfie
    passport_file_t *selfie_local_nonprim = NULL;

    // define the local list for encrypted_passport_element->translation
    list_t *translationList = NULL;

    // encrypted_passport_element->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(encrypted_passport_elementJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    telegram_bot_api_encrypted_passport_element_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = encrypted_passport_element_type_FromString(type->valuestring);

    // encrypted_passport_element->hash
    cJSON *hash = cJSON_GetObjectItemCaseSensitive(encrypted_passport_elementJSON, "hash");
    if (cJSON_IsNull(hash)) {
        hash = NULL;
    }
    if (!hash) {
        goto end;
    }

    
    if(!cJSON_IsString(hash))
    {
    goto end; //String
    }

    // encrypted_passport_element->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(encrypted_passport_elementJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    if(!cJSON_IsString(data) && !cJSON_IsNull(data))
    {
    goto end; //String
    }
    }

    // encrypted_passport_element->phone_number
    cJSON *phone_number = cJSON_GetObjectItemCaseSensitive(encrypted_passport_elementJSON, "phone_number");
    if (cJSON_IsNull(phone_number)) {
        phone_number = NULL;
    }
    if (phone_number) { 
    if(!cJSON_IsString(phone_number) && !cJSON_IsNull(phone_number))
    {
    goto end; //String
    }
    }

    // encrypted_passport_element->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(encrypted_passport_elementJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // encrypted_passport_element->files
    cJSON *files = cJSON_GetObjectItemCaseSensitive(encrypted_passport_elementJSON, "files");
    if (cJSON_IsNull(files)) {
        files = NULL;
    }
    if (files) { 
    cJSON *files_local_nonprimitive = NULL;
    if(!cJSON_IsArray(files)){
        goto end; //nonprimitive container
    }

    filesList = list_createList();

    cJSON_ArrayForEach(files_local_nonprimitive,files )
    {
        if(!cJSON_IsObject(files_local_nonprimitive)){
            goto end;
        }
        passport_file_t *filesItem = passport_file_parseFromJSON(files_local_nonprimitive);

        list_addElement(filesList, filesItem);
    }
    }

    // encrypted_passport_element->front_side
    cJSON *front_side = cJSON_GetObjectItemCaseSensitive(encrypted_passport_elementJSON, "front_side");
    if (cJSON_IsNull(front_side)) {
        front_side = NULL;
    }
    if (front_side) { 
    front_side_local_nonprim = passport_file_parseFromJSON(front_side); //nonprimitive
    }

    // encrypted_passport_element->reverse_side
    cJSON *reverse_side = cJSON_GetObjectItemCaseSensitive(encrypted_passport_elementJSON, "reverse_side");
    if (cJSON_IsNull(reverse_side)) {
        reverse_side = NULL;
    }
    if (reverse_side) { 
    reverse_side_local_nonprim = passport_file_parseFromJSON(reverse_side); //nonprimitive
    }

    // encrypted_passport_element->selfie
    cJSON *selfie = cJSON_GetObjectItemCaseSensitive(encrypted_passport_elementJSON, "selfie");
    if (cJSON_IsNull(selfie)) {
        selfie = NULL;
    }
    if (selfie) { 
    selfie_local_nonprim = passport_file_parseFromJSON(selfie); //nonprimitive
    }

    // encrypted_passport_element->translation
    cJSON *translation = cJSON_GetObjectItemCaseSensitive(encrypted_passport_elementJSON, "translation");
    if (cJSON_IsNull(translation)) {
        translation = NULL;
    }
    if (translation) { 
    cJSON *translation_local_nonprimitive = NULL;
    if(!cJSON_IsArray(translation)){
        goto end; //nonprimitive container
    }

    translationList = list_createList();

    cJSON_ArrayForEach(translation_local_nonprimitive,translation )
    {
        if(!cJSON_IsObject(translation_local_nonprimitive)){
            goto end;
        }
        passport_file_t *translationItem = passport_file_parseFromJSON(translation_local_nonprimitive);

        list_addElement(translationList, translationItem);
    }
    }


    encrypted_passport_element_local_var = encrypted_passport_element_create_internal (
        typeVariable,
        strdup(hash->valuestring),
        data && !cJSON_IsNull(data) ? strdup(data->valuestring) : NULL,
        phone_number && !cJSON_IsNull(phone_number) ? strdup(phone_number->valuestring) : NULL,
        email && !cJSON_IsNull(email) ? strdup(email->valuestring) : NULL,
        files ? filesList : NULL,
        front_side ? front_side_local_nonprim : NULL,
        reverse_side ? reverse_side_local_nonprim : NULL,
        selfie ? selfie_local_nonprim : NULL,
        translation ? translationList : NULL
        );

    return encrypted_passport_element_local_var;
end:
    if (filesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, filesList) {
            passport_file_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(filesList);
        filesList = NULL;
    }
    if (front_side_local_nonprim) {
        passport_file_free(front_side_local_nonprim);
        front_side_local_nonprim = NULL;
    }
    if (reverse_side_local_nonprim) {
        passport_file_free(reverse_side_local_nonprim);
        reverse_side_local_nonprim = NULL;
    }
    if (selfie_local_nonprim) {
        passport_file_free(selfie_local_nonprim);
        selfie_local_nonprim = NULL;
    }
    if (translationList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, translationList) {
            passport_file_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(translationList);
        translationList = NULL;
    }
    return NULL;

}
