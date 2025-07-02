#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_business_account_name_request.h"



static set_business_account_name_request_t *set_business_account_name_request_create_internal(
    char *business_connection_id,
    char *first_name,
    char *last_name
    ) {
    set_business_account_name_request_t *set_business_account_name_request_local_var = malloc(sizeof(set_business_account_name_request_t));
    if (!set_business_account_name_request_local_var) {
        return NULL;
    }
    set_business_account_name_request_local_var->business_connection_id = business_connection_id;
    set_business_account_name_request_local_var->first_name = first_name;
    set_business_account_name_request_local_var->last_name = last_name;

    set_business_account_name_request_local_var->_library_owned = 1;
    return set_business_account_name_request_local_var;
}

__attribute__((deprecated)) set_business_account_name_request_t *set_business_account_name_request_create(
    char *business_connection_id,
    char *first_name,
    char *last_name
    ) {
    return set_business_account_name_request_create_internal (
        business_connection_id,
        first_name,
        last_name
        );
}

void set_business_account_name_request_free(set_business_account_name_request_t *set_business_account_name_request) {
    if(NULL == set_business_account_name_request){
        return ;
    }
    if(set_business_account_name_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_business_account_name_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_business_account_name_request->business_connection_id) {
        free(set_business_account_name_request->business_connection_id);
        set_business_account_name_request->business_connection_id = NULL;
    }
    if (set_business_account_name_request->first_name) {
        free(set_business_account_name_request->first_name);
        set_business_account_name_request->first_name = NULL;
    }
    if (set_business_account_name_request->last_name) {
        free(set_business_account_name_request->last_name);
        set_business_account_name_request->last_name = NULL;
    }
    free(set_business_account_name_request);
}

cJSON *set_business_account_name_request_convertToJSON(set_business_account_name_request_t *set_business_account_name_request) {
    cJSON *item = cJSON_CreateObject();

    // set_business_account_name_request->business_connection_id
    if (!set_business_account_name_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", set_business_account_name_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // set_business_account_name_request->first_name
    if (!set_business_account_name_request->first_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "first_name", set_business_account_name_request->first_name) == NULL) {
    goto fail; //String
    }


    // set_business_account_name_request->last_name
    if(set_business_account_name_request->last_name) {
    if(cJSON_AddStringToObject(item, "last_name", set_business_account_name_request->last_name) == NULL) {
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

set_business_account_name_request_t *set_business_account_name_request_parseFromJSON(cJSON *set_business_account_name_requestJSON){

    set_business_account_name_request_t *set_business_account_name_request_local_var = NULL;

    // set_business_account_name_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(set_business_account_name_requestJSON, "business_connection_id");
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

    // set_business_account_name_request->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(set_business_account_name_requestJSON, "first_name");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (!first_name) {
        goto end;
    }

    
    if(!cJSON_IsString(first_name))
    {
    goto end; //String
    }

    // set_business_account_name_request->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(set_business_account_name_requestJSON, "last_name");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }


    set_business_account_name_request_local_var = set_business_account_name_request_create_internal (
        strdup(business_connection_id->valuestring),
        strdup(first_name->valuestring),
        last_name && !cJSON_IsNull(last_name) ? strdup(last_name->valuestring) : NULL
        );

    return set_business_account_name_request_local_var;
end:
    return NULL;

}
