#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_passport_data_errors_request.h"



static post_set_passport_data_errors_request_t *post_set_passport_data_errors_request_create_internal(
    int user_id,
    list_t *errors
    ) {
    post_set_passport_data_errors_request_t *post_set_passport_data_errors_request_local_var = malloc(sizeof(post_set_passport_data_errors_request_t));
    if (!post_set_passport_data_errors_request_local_var) {
        return NULL;
    }
    post_set_passport_data_errors_request_local_var->user_id = user_id;
    post_set_passport_data_errors_request_local_var->errors = errors;

    post_set_passport_data_errors_request_local_var->_library_owned = 1;
    return post_set_passport_data_errors_request_local_var;
}

__attribute__((deprecated)) post_set_passport_data_errors_request_t *post_set_passport_data_errors_request_create(
    int user_id,
    list_t *errors
    ) {
    return post_set_passport_data_errors_request_create_internal (
        user_id,
        errors
        );
}

void post_set_passport_data_errors_request_free(post_set_passport_data_errors_request_t *post_set_passport_data_errors_request) {
    if(NULL == post_set_passport_data_errors_request){
        return ;
    }
    if(post_set_passport_data_errors_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_passport_data_errors_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_passport_data_errors_request->errors) {
        list_ForEach(listEntry, post_set_passport_data_errors_request->errors) {
            passport_element_error_free(listEntry->data);
        }
        list_freeList(post_set_passport_data_errors_request->errors);
        post_set_passport_data_errors_request->errors = NULL;
    }
    free(post_set_passport_data_errors_request);
}

cJSON *post_set_passport_data_errors_request_convertToJSON(post_set_passport_data_errors_request_t *post_set_passport_data_errors_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_passport_data_errors_request->user_id
    if (!post_set_passport_data_errors_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", post_set_passport_data_errors_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // post_set_passport_data_errors_request->errors
    if (!post_set_passport_data_errors_request->errors) {
        goto fail;
    }
    cJSON *errors = cJSON_AddArrayToObject(item, "errors");
    if(errors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *errorsListEntry;
    if (post_set_passport_data_errors_request->errors) {
    list_ForEach(errorsListEntry, post_set_passport_data_errors_request->errors) {
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

post_set_passport_data_errors_request_t *post_set_passport_data_errors_request_parseFromJSON(cJSON *post_set_passport_data_errors_requestJSON){

    post_set_passport_data_errors_request_t *post_set_passport_data_errors_request_local_var = NULL;

    // define the local list for post_set_passport_data_errors_request->errors
    list_t *errorsList = NULL;

    // post_set_passport_data_errors_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(post_set_passport_data_errors_requestJSON, "user_id");
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

    // post_set_passport_data_errors_request->errors
    cJSON *errors = cJSON_GetObjectItemCaseSensitive(post_set_passport_data_errors_requestJSON, "errors");
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


    post_set_passport_data_errors_request_local_var = post_set_passport_data_errors_request_create_internal (
        user_id->valuedouble,
        errorsList
        );

    return post_set_passport_data_errors_request_local_var;
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
