#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_chat_permissions_request.h"



static set_chat_permissions_request_t *set_chat_permissions_request_create_internal(
    bot_command_scope_chat_chat_id_t *chat_id,
    chat_permissions_t *permissions,
    int use_independent_chat_permissions
    ) {
    set_chat_permissions_request_t *set_chat_permissions_request_local_var = malloc(sizeof(set_chat_permissions_request_t));
    if (!set_chat_permissions_request_local_var) {
        return NULL;
    }
    set_chat_permissions_request_local_var->chat_id = chat_id;
    set_chat_permissions_request_local_var->permissions = permissions;
    set_chat_permissions_request_local_var->use_independent_chat_permissions = use_independent_chat_permissions;

    set_chat_permissions_request_local_var->_library_owned = 1;
    return set_chat_permissions_request_local_var;
}

__attribute__((deprecated)) set_chat_permissions_request_t *set_chat_permissions_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    chat_permissions_t *permissions,
    int use_independent_chat_permissions
    ) {
    return set_chat_permissions_request_create_internal (
        chat_id,
        permissions,
        use_independent_chat_permissions
        );
}

void set_chat_permissions_request_free(set_chat_permissions_request_t *set_chat_permissions_request) {
    if(NULL == set_chat_permissions_request){
        return ;
    }
    if(set_chat_permissions_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_chat_permissions_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_chat_permissions_request->chat_id) {
        bot_command_scope_chat_chat_id_free(set_chat_permissions_request->chat_id);
        set_chat_permissions_request->chat_id = NULL;
    }
    if (set_chat_permissions_request->permissions) {
        chat_permissions_free(set_chat_permissions_request->permissions);
        set_chat_permissions_request->permissions = NULL;
    }
    free(set_chat_permissions_request);
}

cJSON *set_chat_permissions_request_convertToJSON(set_chat_permissions_request_t *set_chat_permissions_request) {
    cJSON *item = cJSON_CreateObject();

    // set_chat_permissions_request->chat_id
    if (!set_chat_permissions_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = bot_command_scope_chat_chat_id_convertToJSON(set_chat_permissions_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // set_chat_permissions_request->permissions
    if (!set_chat_permissions_request->permissions) {
        goto fail;
    }
    cJSON *permissions_local_JSON = chat_permissions_convertToJSON(set_chat_permissions_request->permissions);
    if(permissions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "permissions", permissions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // set_chat_permissions_request->use_independent_chat_permissions
    if(set_chat_permissions_request->use_independent_chat_permissions) {
    if(cJSON_AddBoolToObject(item, "use_independent_chat_permissions", set_chat_permissions_request->use_independent_chat_permissions) == NULL) {
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

set_chat_permissions_request_t *set_chat_permissions_request_parseFromJSON(cJSON *set_chat_permissions_requestJSON){

    set_chat_permissions_request_t *set_chat_permissions_request_local_var = NULL;

    // define the local variable for set_chat_permissions_request->chat_id
    bot_command_scope_chat_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for set_chat_permissions_request->permissions
    chat_permissions_t *permissions_local_nonprim = NULL;

    // set_chat_permissions_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(set_chat_permissions_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = bot_command_scope_chat_chat_id_parseFromJSON(chat_id); //nonprimitive

    // set_chat_permissions_request->permissions
    cJSON *permissions = cJSON_GetObjectItemCaseSensitive(set_chat_permissions_requestJSON, "permissions");
    if (cJSON_IsNull(permissions)) {
        permissions = NULL;
    }
    if (!permissions) {
        goto end;
    }

    
    permissions_local_nonprim = chat_permissions_parseFromJSON(permissions); //nonprimitive

    // set_chat_permissions_request->use_independent_chat_permissions
    cJSON *use_independent_chat_permissions = cJSON_GetObjectItemCaseSensitive(set_chat_permissions_requestJSON, "use_independent_chat_permissions");
    if (cJSON_IsNull(use_independent_chat_permissions)) {
        use_independent_chat_permissions = NULL;
    }
    if (use_independent_chat_permissions) { 
    if(!cJSON_IsBool(use_independent_chat_permissions))
    {
    goto end; //Bool
    }
    }


    set_chat_permissions_request_local_var = set_chat_permissions_request_create_internal (
        chat_id_local_nonprim,
        permissions_local_nonprim,
        use_independent_chat_permissions ? use_independent_chat_permissions->valueint : 0
        );

    return set_chat_permissions_request_local_var;
end:
    if (chat_id_local_nonprim) {
        bot_command_scope_chat_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (permissions_local_nonprim) {
        chat_permissions_free(permissions_local_nonprim);
        permissions_local_nonprim = NULL;
    }
    return NULL;

}
