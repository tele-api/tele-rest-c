#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_business_account_gift_settings_request.h"



static set_business_account_gift_settings_request_t *set_business_account_gift_settings_request_create_internal(
    char *business_connection_id,
    int show_gift_button,
    accepted_gift_types_t *accepted_gift_types
    ) {
    set_business_account_gift_settings_request_t *set_business_account_gift_settings_request_local_var = malloc(sizeof(set_business_account_gift_settings_request_t));
    if (!set_business_account_gift_settings_request_local_var) {
        return NULL;
    }
    set_business_account_gift_settings_request_local_var->business_connection_id = business_connection_id;
    set_business_account_gift_settings_request_local_var->show_gift_button = show_gift_button;
    set_business_account_gift_settings_request_local_var->accepted_gift_types = accepted_gift_types;

    set_business_account_gift_settings_request_local_var->_library_owned = 1;
    return set_business_account_gift_settings_request_local_var;
}

__attribute__((deprecated)) set_business_account_gift_settings_request_t *set_business_account_gift_settings_request_create(
    char *business_connection_id,
    int show_gift_button,
    accepted_gift_types_t *accepted_gift_types
    ) {
    return set_business_account_gift_settings_request_create_internal (
        business_connection_id,
        show_gift_button,
        accepted_gift_types
        );
}

void set_business_account_gift_settings_request_free(set_business_account_gift_settings_request_t *set_business_account_gift_settings_request) {
    if(NULL == set_business_account_gift_settings_request){
        return ;
    }
    if(set_business_account_gift_settings_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_business_account_gift_settings_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_business_account_gift_settings_request->business_connection_id) {
        free(set_business_account_gift_settings_request->business_connection_id);
        set_business_account_gift_settings_request->business_connection_id = NULL;
    }
    if (set_business_account_gift_settings_request->accepted_gift_types) {
        accepted_gift_types_free(set_business_account_gift_settings_request->accepted_gift_types);
        set_business_account_gift_settings_request->accepted_gift_types = NULL;
    }
    free(set_business_account_gift_settings_request);
}

cJSON *set_business_account_gift_settings_request_convertToJSON(set_business_account_gift_settings_request_t *set_business_account_gift_settings_request) {
    cJSON *item = cJSON_CreateObject();

    // set_business_account_gift_settings_request->business_connection_id
    if (!set_business_account_gift_settings_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", set_business_account_gift_settings_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // set_business_account_gift_settings_request->show_gift_button
    if (!set_business_account_gift_settings_request->show_gift_button) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "show_gift_button", set_business_account_gift_settings_request->show_gift_button) == NULL) {
    goto fail; //Bool
    }


    // set_business_account_gift_settings_request->accepted_gift_types
    if (!set_business_account_gift_settings_request->accepted_gift_types) {
        goto fail;
    }
    cJSON *accepted_gift_types_local_JSON = accepted_gift_types_convertToJSON(set_business_account_gift_settings_request->accepted_gift_types);
    if(accepted_gift_types_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "accepted_gift_types", accepted_gift_types_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

set_business_account_gift_settings_request_t *set_business_account_gift_settings_request_parseFromJSON(cJSON *set_business_account_gift_settings_requestJSON){

    set_business_account_gift_settings_request_t *set_business_account_gift_settings_request_local_var = NULL;

    // define the local variable for set_business_account_gift_settings_request->accepted_gift_types
    accepted_gift_types_t *accepted_gift_types_local_nonprim = NULL;

    // set_business_account_gift_settings_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(set_business_account_gift_settings_requestJSON, "business_connection_id");
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

    // set_business_account_gift_settings_request->show_gift_button
    cJSON *show_gift_button = cJSON_GetObjectItemCaseSensitive(set_business_account_gift_settings_requestJSON, "show_gift_button");
    if (cJSON_IsNull(show_gift_button)) {
        show_gift_button = NULL;
    }
    if (!show_gift_button) {
        goto end;
    }

    
    if(!cJSON_IsBool(show_gift_button))
    {
    goto end; //Bool
    }

    // set_business_account_gift_settings_request->accepted_gift_types
    cJSON *accepted_gift_types = cJSON_GetObjectItemCaseSensitive(set_business_account_gift_settings_requestJSON, "accepted_gift_types");
    if (cJSON_IsNull(accepted_gift_types)) {
        accepted_gift_types = NULL;
    }
    if (!accepted_gift_types) {
        goto end;
    }

    
    accepted_gift_types_local_nonprim = accepted_gift_types_parseFromJSON(accepted_gift_types); //nonprimitive


    set_business_account_gift_settings_request_local_var = set_business_account_gift_settings_request_create_internal (
        strdup(business_connection_id->valuestring),
        show_gift_button->valueint,
        accepted_gift_types_local_nonprim
        );

    return set_business_account_gift_settings_request_local_var;
end:
    if (accepted_gift_types_local_nonprim) {
        accepted_gift_types_free(accepted_gift_types_local_nonprim);
        accepted_gift_types_local_nonprim = NULL;
    }
    return NULL;

}
