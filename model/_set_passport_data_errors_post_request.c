#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_passport_data_errors_post_request.h"



static _set_passport_data_errors_post_request_t *_set_passport_data_errors_post_request_create_internal(
    int user_id,
    list_t *errors
    ) {
    _set_passport_data_errors_post_request_t *_set_passport_data_errors_post_request_local_var = malloc(sizeof(_set_passport_data_errors_post_request_t));
    if (!_set_passport_data_errors_post_request_local_var) {
        return NULL;
    }
    _set_passport_data_errors_post_request_local_var->user_id = user_id;
    _set_passport_data_errors_post_request_local_var->errors = errors;

    _set_passport_data_errors_post_request_local_var->_library_owned = 1;
    return _set_passport_data_errors_post_request_local_var;
}

__attribute__((deprecated)) _set_passport_data_errors_post_request_t *_set_passport_data_errors_post_request_create(
    int user_id,
    list_t *errors
    ) {
    return _set_passport_data_errors_post_request_create_internal (
        user_id,
        errors
        );
}

void _set_passport_data_errors_post_request_free(_set_passport_data_errors_post_request_t *_set_passport_data_errors_post_request) {
    if(NULL == _set_passport_data_errors_post_request){
        return ;
    }
    if(_set_passport_data_errors_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_passport_data_errors_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_passport_data_errors_post_request->errors) {
        list_ForEach(listEntry, _set_passport_data_errors_post_request->errors) {
            passport_element_error_free(listEntry->data);
        }
        list_freeList(_set_passport_data_errors_post_request->errors);
        _set_passport_data_errors_post_request->errors = NULL;
    }
    free(_set_passport_data_errors_post_request);
}

cJSON *_set_passport_data_errors_post_request_convertToJSON(_set_passport_data_errors_post_request_t *_set_passport_data_errors_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_passport_data_errors_post_request->user_id
    if (!_set_passport_data_errors_post_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", _set_passport_data_errors_post_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // _set_passport_data_errors_post_request->errors
    if (!_set_passport_data_errors_post_request->errors) {
        goto fail;
    }
    cJSON *errors = cJSON_AddArrayToObject(item, "errors");
    if(errors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *errorsListEntry;
    if (_set_passport_data_errors_post_request->errors) {
    list_ForEach(errorsListEntry, _set_passport_data_errors_post_request->errors) {
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

_set_passport_data_errors_post_request_t *_set_passport_data_errors_post_request_parseFromJSON(cJSON *_set_passport_data_errors_post_requestJSON){

    _set_passport_data_errors_post_request_t *_set_passport_data_errors_post_request_local_var = NULL;

    // define the local list for _set_passport_data_errors_post_request->errors
    list_t *errorsList = NULL;

    // _set_passport_data_errors_post_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(_set_passport_data_errors_post_requestJSON, "user_id");
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

    // _set_passport_data_errors_post_request->errors
    cJSON *errors = cJSON_GetObjectItemCaseSensitive(_set_passport_data_errors_post_requestJSON, "errors");
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


    _set_passport_data_errors_post_request_local_var = _set_passport_data_errors_post_request_create_internal (
        user_id->valuedouble,
        errorsList
        );

    return _set_passport_data_errors_post_request_local_var;
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
