#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "passport_data.h"



static passport_data_t *passport_data_create_internal(
    list_t *data,
    encrypted_credentials_t *credentials
    ) {
    passport_data_t *passport_data_local_var = malloc(sizeof(passport_data_t));
    if (!passport_data_local_var) {
        return NULL;
    }
    passport_data_local_var->data = data;
    passport_data_local_var->credentials = credentials;

    passport_data_local_var->_library_owned = 1;
    return passport_data_local_var;
}

__attribute__((deprecated)) passport_data_t *passport_data_create(
    list_t *data,
    encrypted_credentials_t *credentials
    ) {
    return passport_data_create_internal (
        data,
        credentials
        );
}

void passport_data_free(passport_data_t *passport_data) {
    if(NULL == passport_data){
        return ;
    }
    if(passport_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "passport_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (passport_data->data) {
        list_ForEach(listEntry, passport_data->data) {
            encrypted_passport_element_free(listEntry->data);
        }
        list_freeList(passport_data->data);
        passport_data->data = NULL;
    }
    if (passport_data->credentials) {
        encrypted_credentials_free(passport_data->credentials);
        passport_data->credentials = NULL;
    }
    free(passport_data);
}

cJSON *passport_data_convertToJSON(passport_data_t *passport_data) {
    cJSON *item = cJSON_CreateObject();

    // passport_data->data
    if (!passport_data->data) {
        goto fail;
    }
    cJSON *data = cJSON_AddArrayToObject(item, "data");
    if(data == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *dataListEntry;
    if (passport_data->data) {
    list_ForEach(dataListEntry, passport_data->data) {
    cJSON *itemLocal = encrypted_passport_element_convertToJSON(dataListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(data, itemLocal);
    }
    }


    // passport_data->credentials
    if (!passport_data->credentials) {
        goto fail;
    }
    cJSON *credentials_local_JSON = encrypted_credentials_convertToJSON(passport_data->credentials);
    if(credentials_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "credentials", credentials_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

passport_data_t *passport_data_parseFromJSON(cJSON *passport_dataJSON){

    passport_data_t *passport_data_local_var = NULL;

    // define the local list for passport_data->data
    list_t *dataList = NULL;

    // define the local variable for passport_data->credentials
    encrypted_credentials_t *credentials_local_nonprim = NULL;

    // passport_data->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(passport_dataJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (!data) {
        goto end;
    }

    
    cJSON *data_local_nonprimitive = NULL;
    if(!cJSON_IsArray(data)){
        goto end; //nonprimitive container
    }

    dataList = list_createList();

    cJSON_ArrayForEach(data_local_nonprimitive,data )
    {
        if(!cJSON_IsObject(data_local_nonprimitive)){
            goto end;
        }
        encrypted_passport_element_t *dataItem = encrypted_passport_element_parseFromJSON(data_local_nonprimitive);

        list_addElement(dataList, dataItem);
    }

    // passport_data->credentials
    cJSON *credentials = cJSON_GetObjectItemCaseSensitive(passport_dataJSON, "credentials");
    if (cJSON_IsNull(credentials)) {
        credentials = NULL;
    }
    if (!credentials) {
        goto end;
    }

    
    credentials_local_nonprim = encrypted_credentials_parseFromJSON(credentials); //nonprimitive


    passport_data_local_var = passport_data_create_internal (
        dataList,
        credentials_local_nonprim
        );

    return passport_data_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            encrypted_passport_element_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    if (credentials_local_nonprim) {
        encrypted_credentials_free(credentials_local_nonprim);
        credentials_local_nonprim = NULL;
    }
    return NULL;

}
