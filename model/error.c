#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "error.h"



static error_t *error_create_internal(
    int ok,
    int error_code,
    char *description,
    response_parameters_t *parameters
    ) {
    error_t *error_local_var = malloc(sizeof(error_t));
    if (!error_local_var) {
        return NULL;
    }
    error_local_var->ok = ok;
    error_local_var->error_code = error_code;
    error_local_var->description = description;
    error_local_var->parameters = parameters;

    error_local_var->_library_owned = 1;
    return error_local_var;
}

__attribute__((deprecated)) error_t *error_create(
    int ok,
    int error_code,
    char *description,
    response_parameters_t *parameters
    ) {
    return error_create_internal (
        ok,
        error_code,
        description,
        parameters
        );
}

void error_free(error_t *error) {
    if(NULL == error){
        return ;
    }
    if(error->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "error_free");
        return ;
    }
    listEntry_t *listEntry;
    if (error->description) {
        free(error->description);
        error->description = NULL;
    }
    if (error->parameters) {
        response_parameters_free(error->parameters);
        error->parameters = NULL;
    }
    free(error);
}

cJSON *error_convertToJSON(error_t *error) {
    cJSON *item = cJSON_CreateObject();

    // error->ok
    if (!error->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", error->ok) == NULL) {
    goto fail; //Bool
    }


    // error->error_code
    if (!error->error_code) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "error_code", error->error_code) == NULL) {
    goto fail; //Numeric
    }


    // error->description
    if (!error->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", error->description) == NULL) {
    goto fail; //String
    }


    // error->parameters
    if(error->parameters) {
    cJSON *parameters_local_JSON = response_parameters_convertToJSON(error->parameters);
    if(parameters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "parameters", parameters_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

error_t *error_parseFromJSON(cJSON *errorJSON){

    error_t *error_local_var = NULL;

    // define the local variable for error->parameters
    response_parameters_t *parameters_local_nonprim = NULL;

    // error->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(errorJSON, "ok");
    if (cJSON_IsNull(ok)) {
        ok = NULL;
    }
    if (!ok) {
        goto end;
    }

    
    if(!cJSON_IsBool(ok))
    {
    goto end; //Bool
    }

    // error->error_code
    cJSON *error_code = cJSON_GetObjectItemCaseSensitive(errorJSON, "error_code");
    if (cJSON_IsNull(error_code)) {
        error_code = NULL;
    }
    if (!error_code) {
        goto end;
    }

    
    if(!cJSON_IsNumber(error_code))
    {
    goto end; //Numeric
    }

    // error->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(errorJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (!description) {
        goto end;
    }

    
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }

    // error->parameters
    cJSON *parameters = cJSON_GetObjectItemCaseSensitive(errorJSON, "parameters");
    if (cJSON_IsNull(parameters)) {
        parameters = NULL;
    }
    if (parameters) { 
    parameters_local_nonprim = response_parameters_parseFromJSON(parameters); //nonprimitive
    }


    error_local_var = error_create_internal (
        ok->valueint,
        error_code->valuedouble,
        strdup(description->valuestring),
        parameters ? parameters_local_nonprim : NULL
        );

    return error_local_var;
end:
    if (parameters_local_nonprim) {
        response_parameters_free(parameters_local_nonprim);
        parameters_local_nonprim = NULL;
    }
    return NULL;

}
