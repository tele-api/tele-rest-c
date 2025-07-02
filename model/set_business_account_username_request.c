#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_business_account_username_request.h"



static set_business_account_username_request_t *set_business_account_username_request_create_internal(
    char *business_connection_id,
    char *username
    ) {
    set_business_account_username_request_t *set_business_account_username_request_local_var = malloc(sizeof(set_business_account_username_request_t));
    if (!set_business_account_username_request_local_var) {
        return NULL;
    }
    set_business_account_username_request_local_var->business_connection_id = business_connection_id;
    set_business_account_username_request_local_var->username = username;

    set_business_account_username_request_local_var->_library_owned = 1;
    return set_business_account_username_request_local_var;
}

__attribute__((deprecated)) set_business_account_username_request_t *set_business_account_username_request_create(
    char *business_connection_id,
    char *username
    ) {
    return set_business_account_username_request_create_internal (
        business_connection_id,
        username
        );
}

void set_business_account_username_request_free(set_business_account_username_request_t *set_business_account_username_request) {
    if(NULL == set_business_account_username_request){
        return ;
    }
    if(set_business_account_username_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_business_account_username_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_business_account_username_request->business_connection_id) {
        free(set_business_account_username_request->business_connection_id);
        set_business_account_username_request->business_connection_id = NULL;
    }
    if (set_business_account_username_request->username) {
        free(set_business_account_username_request->username);
        set_business_account_username_request->username = NULL;
    }
    free(set_business_account_username_request);
}

cJSON *set_business_account_username_request_convertToJSON(set_business_account_username_request_t *set_business_account_username_request) {
    cJSON *item = cJSON_CreateObject();

    // set_business_account_username_request->business_connection_id
    if (!set_business_account_username_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", set_business_account_username_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // set_business_account_username_request->username
    if(set_business_account_username_request->username) {
    if(cJSON_AddStringToObject(item, "username", set_business_account_username_request->username) == NULL) {
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

set_business_account_username_request_t *set_business_account_username_request_parseFromJSON(cJSON *set_business_account_username_requestJSON){

    set_business_account_username_request_t *set_business_account_username_request_local_var = NULL;

    // set_business_account_username_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(set_business_account_username_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (!business_connection_id) {
        goto end;
    }

    
    if(!cJSON_IsString(business_connection_id))
    {
    goto end; //String
    }

    // set_business_account_username_request->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(set_business_account_username_requestJSON, "username");
    if (cJSON_IsNull(username)) {
        username = NULL;
    }
    if (username) { 
    if(!cJSON_IsString(username) && !cJSON_IsNull(username))
    {
    goto end; //String
    }
    }


    set_business_account_username_request_local_var = set_business_account_username_request_create_internal (
        strdup(business_connection_id->valuestring),
        username && !cJSON_IsNull(username) ? strdup(username->valuestring) : NULL
        );

    return set_business_account_username_request_local_var;
end:
    return NULL;

}
