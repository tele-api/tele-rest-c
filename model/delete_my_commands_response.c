#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delete_my_commands_response.h"



static delete_my_commands_response_t *delete_my_commands_response_create_internal(
    int ok,
    int result
    ) {
    delete_my_commands_response_t *delete_my_commands_response_local_var = malloc(sizeof(delete_my_commands_response_t));
    if (!delete_my_commands_response_local_var) {
        return NULL;
    }
    delete_my_commands_response_local_var->ok = ok;
    delete_my_commands_response_local_var->result = result;

    delete_my_commands_response_local_var->_library_owned = 1;
    return delete_my_commands_response_local_var;
}

__attribute__((deprecated)) delete_my_commands_response_t *delete_my_commands_response_create(
    int ok,
    int result
    ) {
    return delete_my_commands_response_create_internal (
        ok,
        result
        );
}

void delete_my_commands_response_free(delete_my_commands_response_t *delete_my_commands_response) {
    if(NULL == delete_my_commands_response){
        return ;
    }
    if(delete_my_commands_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delete_my_commands_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(delete_my_commands_response);
}

cJSON *delete_my_commands_response_convertToJSON(delete_my_commands_response_t *delete_my_commands_response) {
    cJSON *item = cJSON_CreateObject();

    // delete_my_commands_response->ok
    if (!delete_my_commands_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", delete_my_commands_response->ok) == NULL) {
    goto fail; //Bool
    }


    // delete_my_commands_response->result
    if (!delete_my_commands_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", delete_my_commands_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

delete_my_commands_response_t *delete_my_commands_response_parseFromJSON(cJSON *delete_my_commands_responseJSON){

    delete_my_commands_response_t *delete_my_commands_response_local_var = NULL;

    // delete_my_commands_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(delete_my_commands_responseJSON, "ok");
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

    // delete_my_commands_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(delete_my_commands_responseJSON, "result");
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


    delete_my_commands_response_local_var = delete_my_commands_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return delete_my_commands_response_local_var;
end:
    return NULL;

}
