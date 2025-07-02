#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "restrict_chat_member_request.h"



static restrict_chat_member_request_t *restrict_chat_member_request_create_internal(
    bot_command_scope_chat_chat_id_t *chat_id,
    int user_id,
    chat_permissions_t *permissions,
    int use_independent_chat_permissions,
    int until_date
    ) {
    restrict_chat_member_request_t *restrict_chat_member_request_local_var = malloc(sizeof(restrict_chat_member_request_t));
    if (!restrict_chat_member_request_local_var) {
        return NULL;
    }
    restrict_chat_member_request_local_var->chat_id = chat_id;
    restrict_chat_member_request_local_var->user_id = user_id;
    restrict_chat_member_request_local_var->permissions = permissions;
    restrict_chat_member_request_local_var->use_independent_chat_permissions = use_independent_chat_permissions;
    restrict_chat_member_request_local_var->until_date = until_date;

    restrict_chat_member_request_local_var->_library_owned = 1;
    return restrict_chat_member_request_local_var;
}

__attribute__((deprecated)) restrict_chat_member_request_t *restrict_chat_member_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    int user_id,
    chat_permissions_t *permissions,
    int use_independent_chat_permissions,
    int until_date
    ) {
    return restrict_chat_member_request_create_internal (
        chat_id,
        user_id,
        permissions,
        use_independent_chat_permissions,
        until_date
        );
}

void restrict_chat_member_request_free(restrict_chat_member_request_t *restrict_chat_member_request) {
    if(NULL == restrict_chat_member_request){
        return ;
    }
    if(restrict_chat_member_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "restrict_chat_member_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (restrict_chat_member_request->chat_id) {
        bot_command_scope_chat_chat_id_free(restrict_chat_member_request->chat_id);
        restrict_chat_member_request->chat_id = NULL;
    }
    if (restrict_chat_member_request->permissions) {
        chat_permissions_free(restrict_chat_member_request->permissions);
        restrict_chat_member_request->permissions = NULL;
    }
    free(restrict_chat_member_request);
}

cJSON *restrict_chat_member_request_convertToJSON(restrict_chat_member_request_t *restrict_chat_member_request) {
    cJSON *item = cJSON_CreateObject();

    // restrict_chat_member_request->chat_id
    if (!restrict_chat_member_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = bot_command_scope_chat_chat_id_convertToJSON(restrict_chat_member_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // restrict_chat_member_request->user_id
    if (!restrict_chat_member_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", restrict_chat_member_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // restrict_chat_member_request->permissions
    if (!restrict_chat_member_request->permissions) {
        goto fail;
    }
    cJSON *permissions_local_JSON = chat_permissions_convertToJSON(restrict_chat_member_request->permissions);
    if(permissions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "permissions", permissions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // restrict_chat_member_request->use_independent_chat_permissions
    if(restrict_chat_member_request->use_independent_chat_permissions) {
    if(cJSON_AddBoolToObject(item, "use_independent_chat_permissions", restrict_chat_member_request->use_independent_chat_permissions) == NULL) {
    goto fail; //Bool
    }
    }


    // restrict_chat_member_request->until_date
    if(restrict_chat_member_request->until_date) {
    if(cJSON_AddNumberToObject(item, "until_date", restrict_chat_member_request->until_date) == NULL) {
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

restrict_chat_member_request_t *restrict_chat_member_request_parseFromJSON(cJSON *restrict_chat_member_requestJSON){

    restrict_chat_member_request_t *restrict_chat_member_request_local_var = NULL;

    // define the local variable for restrict_chat_member_request->chat_id
    bot_command_scope_chat_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for restrict_chat_member_request->permissions
    chat_permissions_t *permissions_local_nonprim = NULL;

    // restrict_chat_member_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(restrict_chat_member_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = bot_command_scope_chat_chat_id_parseFromJSON(chat_id); //nonprimitive

    // restrict_chat_member_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(restrict_chat_member_requestJSON, "user_id");
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

    // restrict_chat_member_request->permissions
    cJSON *permissions = cJSON_GetObjectItemCaseSensitive(restrict_chat_member_requestJSON, "permissions");
    if (cJSON_IsNull(permissions)) {
        permissions = NULL;
    }
    if (!permissions) {
        goto end;
    }

    
    permissions_local_nonprim = chat_permissions_parseFromJSON(permissions); //nonprimitive

    // restrict_chat_member_request->use_independent_chat_permissions
    cJSON *use_independent_chat_permissions = cJSON_GetObjectItemCaseSensitive(restrict_chat_member_requestJSON, "use_independent_chat_permissions");
    if (cJSON_IsNull(use_independent_chat_permissions)) {
        use_independent_chat_permissions = NULL;
    }
    if (use_independent_chat_permissions) { 
    if(!cJSON_IsBool(use_independent_chat_permissions))
    {
    goto end; //Bool
    }
    }

    // restrict_chat_member_request->until_date
    cJSON *until_date = cJSON_GetObjectItemCaseSensitive(restrict_chat_member_requestJSON, "until_date");
    if (cJSON_IsNull(until_date)) {
        until_date = NULL;
    }
    if (until_date) { 
    if(!cJSON_IsNumber(until_date))
    {
    goto end; //Numeric
    }
    }


    restrict_chat_member_request_local_var = restrict_chat_member_request_create_internal (
        chat_id_local_nonprim,
        user_id->valuedouble,
        permissions_local_nonprim,
        use_independent_chat_permissions ? use_independent_chat_permissions->valueint : 0,
        until_date ? until_date->valuedouble : 0
        );

    return restrict_chat_member_request_local_var;
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
