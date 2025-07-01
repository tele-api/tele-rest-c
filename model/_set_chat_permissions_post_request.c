#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_chat_permissions_post_request.h"



static _set_chat_permissions_post_request_t *_set_chat_permissions_post_request_create_internal(
    _restrict_chat_member_post_request_chat_id_t *chat_id,
    chat_permissions_t *permissions,
    int use_independent_chat_permissions
    ) {
    _set_chat_permissions_post_request_t *_set_chat_permissions_post_request_local_var = malloc(sizeof(_set_chat_permissions_post_request_t));
    if (!_set_chat_permissions_post_request_local_var) {
        return NULL;
    }
    _set_chat_permissions_post_request_local_var->chat_id = chat_id;
    _set_chat_permissions_post_request_local_var->permissions = permissions;
    _set_chat_permissions_post_request_local_var->use_independent_chat_permissions = use_independent_chat_permissions;

    _set_chat_permissions_post_request_local_var->_library_owned = 1;
    return _set_chat_permissions_post_request_local_var;
}

__attribute__((deprecated)) _set_chat_permissions_post_request_t *_set_chat_permissions_post_request_create(
    _restrict_chat_member_post_request_chat_id_t *chat_id,
    chat_permissions_t *permissions,
    int use_independent_chat_permissions
    ) {
    return _set_chat_permissions_post_request_create_internal (
        chat_id,
        permissions,
        use_independent_chat_permissions
        );
}

void _set_chat_permissions_post_request_free(_set_chat_permissions_post_request_t *_set_chat_permissions_post_request) {
    if(NULL == _set_chat_permissions_post_request){
        return ;
    }
    if(_set_chat_permissions_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_chat_permissions_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_chat_permissions_post_request->chat_id) {
        _restrict_chat_member_post_request_chat_id_free(_set_chat_permissions_post_request->chat_id);
        _set_chat_permissions_post_request->chat_id = NULL;
    }
    if (_set_chat_permissions_post_request->permissions) {
        chat_permissions_free(_set_chat_permissions_post_request->permissions);
        _set_chat_permissions_post_request->permissions = NULL;
    }
    free(_set_chat_permissions_post_request);
}

cJSON *_set_chat_permissions_post_request_convertToJSON(_set_chat_permissions_post_request_t *_set_chat_permissions_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_chat_permissions_post_request->chat_id
    if (!_set_chat_permissions_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _restrict_chat_member_post_request_chat_id_convertToJSON(_set_chat_permissions_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _set_chat_permissions_post_request->permissions
    if (!_set_chat_permissions_post_request->permissions) {
        goto fail;
    }
    cJSON *permissions_local_JSON = chat_permissions_convertToJSON(_set_chat_permissions_post_request->permissions);
    if(permissions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "permissions", permissions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _set_chat_permissions_post_request->use_independent_chat_permissions
    if(_set_chat_permissions_post_request->use_independent_chat_permissions) {
    if(cJSON_AddBoolToObject(item, "use_independent_chat_permissions", _set_chat_permissions_post_request->use_independent_chat_permissions) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_set_chat_permissions_post_request_t *_set_chat_permissions_post_request_parseFromJSON(cJSON *_set_chat_permissions_post_requestJSON){

    _set_chat_permissions_post_request_t *_set_chat_permissions_post_request_local_var = NULL;

    // define the local variable for _set_chat_permissions_post_request->chat_id
    _restrict_chat_member_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for _set_chat_permissions_post_request->permissions
    chat_permissions_t *permissions_local_nonprim = NULL;

    // _set_chat_permissions_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_set_chat_permissions_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _restrict_chat_member_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _set_chat_permissions_post_request->permissions
    cJSON *permissions = cJSON_GetObjectItemCaseSensitive(_set_chat_permissions_post_requestJSON, "permissions");
    if (cJSON_IsNull(permissions)) {
        permissions = NULL;
    }
    if (!permissions) {
        goto end;
    }

    
    permissions_local_nonprim = chat_permissions_parseFromJSON(permissions); //nonprimitive

    // _set_chat_permissions_post_request->use_independent_chat_permissions
    cJSON *use_independent_chat_permissions = cJSON_GetObjectItemCaseSensitive(_set_chat_permissions_post_requestJSON, "use_independent_chat_permissions");
    if (cJSON_IsNull(use_independent_chat_permissions)) {
        use_independent_chat_permissions = NULL;
    }
    if (use_independent_chat_permissions) { 
    if(!cJSON_IsBool(use_independent_chat_permissions))
    {
    goto end; //Bool
    }
    }


    _set_chat_permissions_post_request_local_var = _set_chat_permissions_post_request_create_internal (
        chat_id_local_nonprim,
        permissions_local_nonprim,
        use_independent_chat_permissions ? use_independent_chat_permissions->valueint : 0
        );

    return _set_chat_permissions_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _restrict_chat_member_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (permissions_local_nonprim) {
        chat_permissions_free(permissions_local_nonprim);
        permissions_local_nonprim = NULL;
    }
    return NULL;

}
