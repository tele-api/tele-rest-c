#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_business_account_gift_settings_request.h"



static post_set_business_account_gift_settings_request_t *post_set_business_account_gift_settings_request_create_internal(
    char *business_connection_id,
    int show_gift_button,
    accepted_gift_types_t *accepted_gift_types
    ) {
    post_set_business_account_gift_settings_request_t *post_set_business_account_gift_settings_request_local_var = malloc(sizeof(post_set_business_account_gift_settings_request_t));
    if (!post_set_business_account_gift_settings_request_local_var) {
        return NULL;
    }
    post_set_business_account_gift_settings_request_local_var->business_connection_id = business_connection_id;
    post_set_business_account_gift_settings_request_local_var->show_gift_button = show_gift_button;
    post_set_business_account_gift_settings_request_local_var->accepted_gift_types = accepted_gift_types;

    post_set_business_account_gift_settings_request_local_var->_library_owned = 1;
    return post_set_business_account_gift_settings_request_local_var;
}

__attribute__((deprecated)) post_set_business_account_gift_settings_request_t *post_set_business_account_gift_settings_request_create(
    char *business_connection_id,
    int show_gift_button,
    accepted_gift_types_t *accepted_gift_types
    ) {
    return post_set_business_account_gift_settings_request_create_internal (
        business_connection_id,
        show_gift_button,
        accepted_gift_types
        );
}

void post_set_business_account_gift_settings_request_free(post_set_business_account_gift_settings_request_t *post_set_business_account_gift_settings_request) {
    if(NULL == post_set_business_account_gift_settings_request){
        return ;
    }
    if(post_set_business_account_gift_settings_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_business_account_gift_settings_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_business_account_gift_settings_request->business_connection_id) {
        free(post_set_business_account_gift_settings_request->business_connection_id);
        post_set_business_account_gift_settings_request->business_connection_id = NULL;
    }
    if (post_set_business_account_gift_settings_request->accepted_gift_types) {
        accepted_gift_types_free(post_set_business_account_gift_settings_request->accepted_gift_types);
        post_set_business_account_gift_settings_request->accepted_gift_types = NULL;
    }
    free(post_set_business_account_gift_settings_request);
}

cJSON *post_set_business_account_gift_settings_request_convertToJSON(post_set_business_account_gift_settings_request_t *post_set_business_account_gift_settings_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_business_account_gift_settings_request->business_connection_id
    if (!post_set_business_account_gift_settings_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", post_set_business_account_gift_settings_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // post_set_business_account_gift_settings_request->show_gift_button
    if (!post_set_business_account_gift_settings_request->show_gift_button) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "show_gift_button", post_set_business_account_gift_settings_request->show_gift_button) == NULL) {
    goto fail; //Bool
    }


    // post_set_business_account_gift_settings_request->accepted_gift_types
    if (!post_set_business_account_gift_settings_request->accepted_gift_types) {
        goto fail;
    }
    cJSON *accepted_gift_types_local_JSON = accepted_gift_types_convertToJSON(post_set_business_account_gift_settings_request->accepted_gift_types);
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

post_set_business_account_gift_settings_request_t *post_set_business_account_gift_settings_request_parseFromJSON(cJSON *post_set_business_account_gift_settings_requestJSON){

    post_set_business_account_gift_settings_request_t *post_set_business_account_gift_settings_request_local_var = NULL;

    // define the local variable for post_set_business_account_gift_settings_request->accepted_gift_types
    accepted_gift_types_t *accepted_gift_types_local_nonprim = NULL;

    // post_set_business_account_gift_settings_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_set_business_account_gift_settings_requestJSON, "business_connection_id");
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

    // post_set_business_account_gift_settings_request->show_gift_button
    cJSON *show_gift_button = cJSON_GetObjectItemCaseSensitive(post_set_business_account_gift_settings_requestJSON, "show_gift_button");
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

    // post_set_business_account_gift_settings_request->accepted_gift_types
    cJSON *accepted_gift_types = cJSON_GetObjectItemCaseSensitive(post_set_business_account_gift_settings_requestJSON, "accepted_gift_types");
    if (cJSON_IsNull(accepted_gift_types)) {
        accepted_gift_types = NULL;
    }
    if (!accepted_gift_types) {
        goto end;
    }

    
    accepted_gift_types_local_nonprim = accepted_gift_types_parseFromJSON(accepted_gift_types); //nonprimitive


    post_set_business_account_gift_settings_request_local_var = post_set_business_account_gift_settings_request_create_internal (
        strdup(business_connection_id->valuestring),
        show_gift_button->valueint,
        accepted_gift_types_local_nonprim
        );

    return post_set_business_account_gift_settings_request_local_var;
end:
    if (accepted_gift_types_local_nonprim) {
        accepted_gift_types_free(accepted_gift_types_local_nonprim);
        accepted_gift_types_local_nonprim = NULL;
    }
    return NULL;

}
