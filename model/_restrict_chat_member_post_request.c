#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_restrict_chat_member_post_request.h"



static _restrict_chat_member_post_request_t *_restrict_chat_member_post_request_create_internal(
    _restrict_chat_member_post_request_chat_id_t *chat_id,
    int user_id,
    chat_permissions_t *permissions,
    int use_independent_chat_permissions,
    int until_date
    ) {
    _restrict_chat_member_post_request_t *_restrict_chat_member_post_request_local_var = malloc(sizeof(_restrict_chat_member_post_request_t));
    if (!_restrict_chat_member_post_request_local_var) {
        return NULL;
    }
    _restrict_chat_member_post_request_local_var->chat_id = chat_id;
    _restrict_chat_member_post_request_local_var->user_id = user_id;
    _restrict_chat_member_post_request_local_var->permissions = permissions;
    _restrict_chat_member_post_request_local_var->use_independent_chat_permissions = use_independent_chat_permissions;
    _restrict_chat_member_post_request_local_var->until_date = until_date;

    _restrict_chat_member_post_request_local_var->_library_owned = 1;
    return _restrict_chat_member_post_request_local_var;
}

__attribute__((deprecated)) _restrict_chat_member_post_request_t *_restrict_chat_member_post_request_create(
    _restrict_chat_member_post_request_chat_id_t *chat_id,
    int user_id,
    chat_permissions_t *permissions,
    int use_independent_chat_permissions,
    int until_date
    ) {
    return _restrict_chat_member_post_request_create_internal (
        chat_id,
        user_id,
        permissions,
        use_independent_chat_permissions,
        until_date
        );
}

void _restrict_chat_member_post_request_free(_restrict_chat_member_post_request_t *_restrict_chat_member_post_request) {
    if(NULL == _restrict_chat_member_post_request){
        return ;
    }
    if(_restrict_chat_member_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_restrict_chat_member_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_restrict_chat_member_post_request->chat_id) {
        _restrict_chat_member_post_request_chat_id_free(_restrict_chat_member_post_request->chat_id);
        _restrict_chat_member_post_request->chat_id = NULL;
    }
    if (_restrict_chat_member_post_request->permissions) {
        chat_permissions_free(_restrict_chat_member_post_request->permissions);
        _restrict_chat_member_post_request->permissions = NULL;
    }
    free(_restrict_chat_member_post_request);
}

cJSON *_restrict_chat_member_post_request_convertToJSON(_restrict_chat_member_post_request_t *_restrict_chat_member_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _restrict_chat_member_post_request->chat_id
    if (!_restrict_chat_member_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _restrict_chat_member_post_request_chat_id_convertToJSON(_restrict_chat_member_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _restrict_chat_member_post_request->user_id
    if (!_restrict_chat_member_post_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", _restrict_chat_member_post_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // _restrict_chat_member_post_request->permissions
    if (!_restrict_chat_member_post_request->permissions) {
        goto fail;
    }
    cJSON *permissions_local_JSON = chat_permissions_convertToJSON(_restrict_chat_member_post_request->permissions);
    if(permissions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "permissions", permissions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _restrict_chat_member_post_request->use_independent_chat_permissions
    if(_restrict_chat_member_post_request->use_independent_chat_permissions) {
    if(cJSON_AddBoolToObject(item, "use_independent_chat_permissions", _restrict_chat_member_post_request->use_independent_chat_permissions) == NULL) {
    goto fail; //Bool
    }
    }


    // _restrict_chat_member_post_request->until_date
    if(_restrict_chat_member_post_request->until_date) {
    if(cJSON_AddNumberToObject(item, "until_date", _restrict_chat_member_post_request->until_date) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_restrict_chat_member_post_request_t *_restrict_chat_member_post_request_parseFromJSON(cJSON *_restrict_chat_member_post_requestJSON){

    _restrict_chat_member_post_request_t *_restrict_chat_member_post_request_local_var = NULL;

    // define the local variable for _restrict_chat_member_post_request->chat_id
    _restrict_chat_member_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for _restrict_chat_member_post_request->permissions
    chat_permissions_t *permissions_local_nonprim = NULL;

    // _restrict_chat_member_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_restrict_chat_member_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _restrict_chat_member_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _restrict_chat_member_post_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(_restrict_chat_member_post_requestJSON, "user_id");
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

    // _restrict_chat_member_post_request->permissions
    cJSON *permissions = cJSON_GetObjectItemCaseSensitive(_restrict_chat_member_post_requestJSON, "permissions");
    if (cJSON_IsNull(permissions)) {
        permissions = NULL;
    }
    if (!permissions) {
        goto end;
    }

    
    permissions_local_nonprim = chat_permissions_parseFromJSON(permissions); //nonprimitive

    // _restrict_chat_member_post_request->use_independent_chat_permissions
    cJSON *use_independent_chat_permissions = cJSON_GetObjectItemCaseSensitive(_restrict_chat_member_post_requestJSON, "use_independent_chat_permissions");
    if (cJSON_IsNull(use_independent_chat_permissions)) {
        use_independent_chat_permissions = NULL;
    }
    if (use_independent_chat_permissions) { 
    if(!cJSON_IsBool(use_independent_chat_permissions))
    {
    goto end; //Bool
    }
    }

    // _restrict_chat_member_post_request->until_date
    cJSON *until_date = cJSON_GetObjectItemCaseSensitive(_restrict_chat_member_post_requestJSON, "until_date");
    if (cJSON_IsNull(until_date)) {
        until_date = NULL;
    }
    if (until_date) { 
    if(!cJSON_IsNumber(until_date))
    {
    goto end; //Numeric
    }
    }


    _restrict_chat_member_post_request_local_var = _restrict_chat_member_post_request_create_internal (
        chat_id_local_nonprim,
        user_id->valuedouble,
        permissions_local_nonprim,
        use_independent_chat_permissions ? use_independent_chat_permissions->valueint : 0,
        until_date ? until_date->valuedouble : 0
        );

    return _restrict_chat_member_post_request_local_var;
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
