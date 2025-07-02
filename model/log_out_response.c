#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "log_out_response.h"



static log_out_response_t *log_out_response_create_internal(
    int ok,
    int result
    ) {
    log_out_response_t *log_out_response_local_var = malloc(sizeof(log_out_response_t));
    if (!log_out_response_local_var) {
        return NULL;
    }
    log_out_response_local_var->ok = ok;
    log_out_response_local_var->result = result;

    log_out_response_local_var->_library_owned = 1;
    return log_out_response_local_var;
}

__attribute__((deprecated)) log_out_response_t *log_out_response_create(
    int ok,
    int result
    ) {
    return log_out_response_create_internal (
        ok,
        result
        );
}

void log_out_response_free(log_out_response_t *log_out_response) {
    if(NULL == log_out_response){
        return ;
    }
    if(log_out_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "log_out_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(log_out_response);
}

cJSON *log_out_response_convertToJSON(log_out_response_t *log_out_response) {
    cJSON *item = cJSON_CreateObject();

    // log_out_response->ok
    if (!log_out_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", log_out_response->ok) == NULL) {
    goto fail; //Bool
    }


    // log_out_response->result
    if (!log_out_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", log_out_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

log_out_response_t *log_out_response_parseFromJSON(cJSON *log_out_responseJSON){

    log_out_response_t *log_out_response_local_var = NULL;

    // log_out_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(log_out_responseJSON, "ok");
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

    // log_out_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(log_out_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    if(!cJSON_IsBool(result))
    {
    goto end; //Bool
    }


    log_out_response_local_var = log_out_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return log_out_response_local_var;
end:
    return NULL;

}
