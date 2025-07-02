#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "verify_user_request.h"



static verify_user_request_t *verify_user_request_create_internal(
    int user_id,
    char *custom_description
    ) {
    verify_user_request_t *verify_user_request_local_var = malloc(sizeof(verify_user_request_t));
    if (!verify_user_request_local_var) {
        return NULL;
    }
    verify_user_request_local_var->user_id = user_id;
    verify_user_request_local_var->custom_description = custom_description;

    verify_user_request_local_var->_library_owned = 1;
    return verify_user_request_local_var;
}

__attribute__((deprecated)) verify_user_request_t *verify_user_request_create(
    int user_id,
    char *custom_description
    ) {
    return verify_user_request_create_internal (
        user_id,
        custom_description
        );
}

void verify_user_request_free(verify_user_request_t *verify_user_request) {
    if(NULL == verify_user_request){
        return ;
    }
    if(verify_user_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "verify_user_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (verify_user_request->custom_description) {
        free(verify_user_request->custom_description);
        verify_user_request->custom_description = NULL;
    }
    free(verify_user_request);
}

cJSON *verify_user_request_convertToJSON(verify_user_request_t *verify_user_request) {
    cJSON *item = cJSON_CreateObject();

    // verify_user_request->user_id
    if (!verify_user_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", verify_user_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // verify_user_request->custom_description
    if(verify_user_request->custom_description) {
    if(cJSON_AddStringToObject(item, "custom_description", verify_user_request->custom_description) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

verify_user_request_t *verify_user_request_parseFromJSON(cJSON *verify_user_requestJSON){

    verify_user_request_t *verify_user_request_local_var = NULL;

    // verify_user_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(verify_user_requestJSON, "user_id");
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

    // verify_user_request->custom_description
    cJSON *custom_description = cJSON_GetObjectItemCaseSensitive(verify_user_requestJSON, "custom_description");
    if (cJSON_IsNull(custom_description)) {
        custom_description = NULL;
    }
    if (custom_description) { 
    if(!cJSON_IsString(custom_description) && !cJSON_IsNull(custom_description))
    {
    goto end; //String
    }
    }


    verify_user_request_local_var = verify_user_request_create_internal (
        user_id->valuedouble,
        custom_description && !cJSON_IsNull(custom_description) ? strdup(custom_description->valuestring) : NULL
        );

    return verify_user_request_local_var;
end:
    return NULL;

}
