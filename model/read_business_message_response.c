#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "read_business_message_response.h"



static read_business_message_response_t *read_business_message_response_create_internal(
    int ok,
    int result
    ) {
    read_business_message_response_t *read_business_message_response_local_var = malloc(sizeof(read_business_message_response_t));
    if (!read_business_message_response_local_var) {
        return NULL;
    }
    read_business_message_response_local_var->ok = ok;
    read_business_message_response_local_var->result = result;

    read_business_message_response_local_var->_library_owned = 1;
    return read_business_message_response_local_var;
}

__attribute__((deprecated)) read_business_message_response_t *read_business_message_response_create(
    int ok,
    int result
    ) {
    return read_business_message_response_create_internal (
        ok,
        result
        );
}

void read_business_message_response_free(read_business_message_response_t *read_business_message_response) {
    if(NULL == read_business_message_response){
        return ;
    }
    if(read_business_message_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "read_business_message_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(read_business_message_response);
}

cJSON *read_business_message_response_convertToJSON(read_business_message_response_t *read_business_message_response) {
    cJSON *item = cJSON_CreateObject();

    // read_business_message_response->ok
    if (!read_business_message_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", read_business_message_response->ok) == NULL) {
    goto fail; //Bool
    }


    // read_business_message_response->result
    if (!read_business_message_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", read_business_message_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

read_business_message_response_t *read_business_message_response_parseFromJSON(cJSON *read_business_message_responseJSON){

    read_business_message_response_t *read_business_message_response_local_var = NULL;

    // read_business_message_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(read_business_message_responseJSON, "ok");
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

    // read_business_message_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(read_business_message_responseJSON, "result");
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


    read_business_message_response_local_var = read_business_message_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return read_business_message_response_local_var;
end:
    return NULL;

}
