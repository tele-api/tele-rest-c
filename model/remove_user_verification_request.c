#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "remove_user_verification_request.h"



static remove_user_verification_request_t *remove_user_verification_request_create_internal(
    int user_id
    ) {
    remove_user_verification_request_t *remove_user_verification_request_local_var = malloc(sizeof(remove_user_verification_request_t));
    if (!remove_user_verification_request_local_var) {
        return NULL;
    }
    remove_user_verification_request_local_var->user_id = user_id;

    remove_user_verification_request_local_var->_library_owned = 1;
    return remove_user_verification_request_local_var;
}

__attribute__((deprecated)) remove_user_verification_request_t *remove_user_verification_request_create(
    int user_id
    ) {
    return remove_user_verification_request_create_internal (
        user_id
        );
}

void remove_user_verification_request_free(remove_user_verification_request_t *remove_user_verification_request) {
    if(NULL == remove_user_verification_request){
        return ;
    }
    if(remove_user_verification_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "remove_user_verification_request_free");
        return ;
    }
    listEntry_t *listEntry;
    free(remove_user_verification_request);
}

cJSON *remove_user_verification_request_convertToJSON(remove_user_verification_request_t *remove_user_verification_request) {
    cJSON *item = cJSON_CreateObject();

    // remove_user_verification_request->user_id
    if (!remove_user_verification_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", remove_user_verification_request->user_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

remove_user_verification_request_t *remove_user_verification_request_parseFromJSON(cJSON *remove_user_verification_requestJSON){

    remove_user_verification_request_t *remove_user_verification_request_local_var = NULL;

    // remove_user_verification_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(remove_user_verification_requestJSON, "user_id");
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


    remove_user_verification_request_local_var = remove_user_verification_request_create_internal (
        user_id->valuedouble
        );

    return remove_user_verification_request_local_var;
end:
    return NULL;

}
