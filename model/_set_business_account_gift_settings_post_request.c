#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_business_account_gift_settings_post_request.h"



static _set_business_account_gift_settings_post_request_t *_set_business_account_gift_settings_post_request_create_internal(
    char *business_connection_id,
    int show_gift_button,
    accepted_gift_types_t *accepted_gift_types
    ) {
    _set_business_account_gift_settings_post_request_t *_set_business_account_gift_settings_post_request_local_var = malloc(sizeof(_set_business_account_gift_settings_post_request_t));
    if (!_set_business_account_gift_settings_post_request_local_var) {
        return NULL;
    }
    _set_business_account_gift_settings_post_request_local_var->business_connection_id = business_connection_id;
    _set_business_account_gift_settings_post_request_local_var->show_gift_button = show_gift_button;
    _set_business_account_gift_settings_post_request_local_var->accepted_gift_types = accepted_gift_types;

    _set_business_account_gift_settings_post_request_local_var->_library_owned = 1;
    return _set_business_account_gift_settings_post_request_local_var;
}

__attribute__((deprecated)) _set_business_account_gift_settings_post_request_t *_set_business_account_gift_settings_post_request_create(
    char *business_connection_id,
    int show_gift_button,
    accepted_gift_types_t *accepted_gift_types
    ) {
    return _set_business_account_gift_settings_post_request_create_internal (
        business_connection_id,
        show_gift_button,
        accepted_gift_types
        );
}

void _set_business_account_gift_settings_post_request_free(_set_business_account_gift_settings_post_request_t *_set_business_account_gift_settings_post_request) {
    if(NULL == _set_business_account_gift_settings_post_request){
        return ;
    }
    if(_set_business_account_gift_settings_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_business_account_gift_settings_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_business_account_gift_settings_post_request->business_connection_id) {
        free(_set_business_account_gift_settings_post_request->business_connection_id);
        _set_business_account_gift_settings_post_request->business_connection_id = NULL;
    }
    if (_set_business_account_gift_settings_post_request->accepted_gift_types) {
        accepted_gift_types_free(_set_business_account_gift_settings_post_request->accepted_gift_types);
        _set_business_account_gift_settings_post_request->accepted_gift_types = NULL;
    }
    free(_set_business_account_gift_settings_post_request);
}

cJSON *_set_business_account_gift_settings_post_request_convertToJSON(_set_business_account_gift_settings_post_request_t *_set_business_account_gift_settings_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_business_account_gift_settings_post_request->business_connection_id
    if (!_set_business_account_gift_settings_post_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", _set_business_account_gift_settings_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // _set_business_account_gift_settings_post_request->show_gift_button
    if (!_set_business_account_gift_settings_post_request->show_gift_button) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "show_gift_button", _set_business_account_gift_settings_post_request->show_gift_button) == NULL) {
    goto fail; //Bool
    }


    // _set_business_account_gift_settings_post_request->accepted_gift_types
    if (!_set_business_account_gift_settings_post_request->accepted_gift_types) {
        goto fail;
    }
    cJSON *accepted_gift_types_local_JSON = accepted_gift_types_convertToJSON(_set_business_account_gift_settings_post_request->accepted_gift_types);
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

_set_business_account_gift_settings_post_request_t *_set_business_account_gift_settings_post_request_parseFromJSON(cJSON *_set_business_account_gift_settings_post_requestJSON){

    _set_business_account_gift_settings_post_request_t *_set_business_account_gift_settings_post_request_local_var = NULL;

    // define the local variable for _set_business_account_gift_settings_post_request->accepted_gift_types
    accepted_gift_types_t *accepted_gift_types_local_nonprim = NULL;

    // _set_business_account_gift_settings_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_set_business_account_gift_settings_post_requestJSON, "business_connection_id");
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

    // _set_business_account_gift_settings_post_request->show_gift_button
    cJSON *show_gift_button = cJSON_GetObjectItemCaseSensitive(_set_business_account_gift_settings_post_requestJSON, "show_gift_button");
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

    // _set_business_account_gift_settings_post_request->accepted_gift_types
    cJSON *accepted_gift_types = cJSON_GetObjectItemCaseSensitive(_set_business_account_gift_settings_post_requestJSON, "accepted_gift_types");
    if (cJSON_IsNull(accepted_gift_types)) {
        accepted_gift_types = NULL;
    }
    if (!accepted_gift_types) {
        goto end;
    }

    
    accepted_gift_types_local_nonprim = accepted_gift_types_parseFromJSON(accepted_gift_types); //nonprimitive


    _set_business_account_gift_settings_post_request_local_var = _set_business_account_gift_settings_post_request_create_internal (
        strdup(business_connection_id->valuestring),
        show_gift_button->valueint,
        accepted_gift_types_local_nonprim
        );

    return _set_business_account_gift_settings_post_request_local_var;
end:
    if (accepted_gift_types_local_nonprim) {
        accepted_gift_types_free(accepted_gift_types_local_nonprim);
        accepted_gift_types_local_nonprim = NULL;
    }
    return NULL;

}
