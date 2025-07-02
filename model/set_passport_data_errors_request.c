#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_passport_data_errors_request.h"



static set_passport_data_errors_request_t *set_passport_data_errors_request_create_internal(
    int user_id,
    list_t *errors
    ) {
    set_passport_data_errors_request_t *set_passport_data_errors_request_local_var = malloc(sizeof(set_passport_data_errors_request_t));
    if (!set_passport_data_errors_request_local_var) {
        return NULL;
    }
    set_passport_data_errors_request_local_var->user_id = user_id;
    set_passport_data_errors_request_local_var->errors = errors;

    set_passport_data_errors_request_local_var->_library_owned = 1;
    return set_passport_data_errors_request_local_var;
}

__attribute__((deprecated)) set_passport_data_errors_request_t *set_passport_data_errors_request_create(
    int user_id,
    list_t *errors
    ) {
    return set_passport_data_errors_request_create_internal (
        user_id,
        errors
        );
}

void set_passport_data_errors_request_free(set_passport_data_errors_request_t *set_passport_data_errors_request) {
    if(NULL == set_passport_data_errors_request){
        return ;
    }
    if(set_passport_data_errors_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_passport_data_errors_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_passport_data_errors_request->errors) {
        list_ForEach(listEntry, set_passport_data_errors_request->errors) {
            passport_element_error_free(listEntry->data);
        }
        list_freeList(set_passport_data_errors_request->errors);
        set_passport_data_errors_request->errors = NULL;
    }
    free(set_passport_data_errors_request);
}

cJSON *set_passport_data_errors_request_convertToJSON(set_passport_data_errors_request_t *set_passport_data_errors_request) {
    cJSON *item = cJSON_CreateObject();

    // set_passport_data_errors_request->user_id
    if (!set_passport_data_errors_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", set_passport_data_errors_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // set_passport_data_errors_request->errors
    if (!set_passport_data_errors_request->errors) {
        goto fail;
    }
    cJSON *errors = cJSON_AddArrayToObject(item, "errors");
    if(errors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *errorsListEntry;
    if (set_passport_data_errors_request->errors) {
    list_ForEach(errorsListEntry, set_passport_data_errors_request->errors) {
    cJSON *itemLocal = passport_element_error_convertToJSON(errorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(errors, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

set_passport_data_errors_request_t *set_passport_data_errors_request_parseFromJSON(cJSON *set_passport_data_errors_requestJSON){

    set_passport_data_errors_request_t *set_passport_data_errors_request_local_var = NULL;

    // define the local list for set_passport_data_errors_request->errors
    list_t *errorsList = NULL;

    // set_passport_data_errors_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(set_passport_data_errors_requestJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(user_id))
    {
    goto end; //Numeric
    }

    // set_passport_data_errors_request->errors
    cJSON *errors = cJSON_GetObjectItemCaseSensitive(set_passport_data_errors_requestJSON, "errors");
    if (cJSON_IsNull(errors)) {
        errors = NULL;
    }
    if (!errors) {
        goto end;
    }

    
    cJSON *errors_local_nonprimitive = NULL;
    if(!cJSON_IsArray(errors)){
        goto end; //nonprimitive container
    }

    errorsList = list_createList();

    cJSON_ArrayForEach(errors_local_nonprimitive,errors )
    {
        if(!cJSON_IsObject(errors_local_nonprimitive)){
            goto end;
        }
        passport_element_error_t *errorsItem = passport_element_error_parseFromJSON(errors_local_nonprimitive);

        list_addElement(errorsList, errorsItem);
    }


    set_passport_data_errors_request_local_var = set_passport_data_errors_request_create_internal (
        user_id->valuedouble,
        errorsList
        );

    return set_passport_data_errors_request_local_var;
end:
    if (errorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, errorsList) {
            passport_element_error_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(errorsList);
        errorsList = NULL;
    }
    return NULL;

}
