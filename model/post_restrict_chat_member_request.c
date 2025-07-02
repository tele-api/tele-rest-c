#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_restrict_chat_member_request.h"



static post_restrict_chat_member_request_t *post_restrict_chat_member_request_create_internal(
    post_restrict_chat_member_request_chat_id_t *chat_id,
    int user_id,
    chat_permissions_t *permissions,
    int use_independent_chat_permissions,
    int until_date
    ) {
    post_restrict_chat_member_request_t *post_restrict_chat_member_request_local_var = malloc(sizeof(post_restrict_chat_member_request_t));
    if (!post_restrict_chat_member_request_local_var) {
        return NULL;
    }
    post_restrict_chat_member_request_local_var->chat_id = chat_id;
    post_restrict_chat_member_request_local_var->user_id = user_id;
    post_restrict_chat_member_request_local_var->permissions = permissions;
    post_restrict_chat_member_request_local_var->use_independent_chat_permissions = use_independent_chat_permissions;
    post_restrict_chat_member_request_local_var->until_date = until_date;

    post_restrict_chat_member_request_local_var->_library_owned = 1;
    return post_restrict_chat_member_request_local_var;
}

__attribute__((deprecated)) post_restrict_chat_member_request_t *post_restrict_chat_member_request_create(
    post_restrict_chat_member_request_chat_id_t *chat_id,
    int user_id,
    chat_permissions_t *permissions,
    int use_independent_chat_permissions,
    int until_date
    ) {
    return post_restrict_chat_member_request_create_internal (
        chat_id,
        user_id,
        permissions,
        use_independent_chat_permissions,
        until_date
        );
}

void post_restrict_chat_member_request_free(post_restrict_chat_member_request_t *post_restrict_chat_member_request) {
    if(NULL == post_restrict_chat_member_request){
        return ;
    }
    if(post_restrict_chat_member_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_restrict_chat_member_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_restrict_chat_member_request->chat_id) {
        post_restrict_chat_member_request_chat_id_free(post_restrict_chat_member_request->chat_id);
        post_restrict_chat_member_request->chat_id = NULL;
    }
    if (post_restrict_chat_member_request->permissions) {
        chat_permissions_free(post_restrict_chat_member_request->permissions);
        post_restrict_chat_member_request->permissions = NULL;
    }
    free(post_restrict_chat_member_request);
}

cJSON *post_restrict_chat_member_request_convertToJSON(post_restrict_chat_member_request_t *post_restrict_chat_member_request) {
    cJSON *item = cJSON_CreateObject();

    // post_restrict_chat_member_request->chat_id
    if (!post_restrict_chat_member_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_restrict_chat_member_request_chat_id_convertToJSON(post_restrict_chat_member_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_restrict_chat_member_request->user_id
    if (!post_restrict_chat_member_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", post_restrict_chat_member_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // post_restrict_chat_member_request->permissions
    if (!post_restrict_chat_member_request->permissions) {
        goto fail;
    }
    cJSON *permissions_local_JSON = chat_permissions_convertToJSON(post_restrict_chat_member_request->permissions);
    if(permissions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "permissions", permissions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_restrict_chat_member_request->use_independent_chat_permissions
    if(post_restrict_chat_member_request->use_independent_chat_permissions) {
    if(cJSON_AddBoolToObject(item, "use_independent_chat_permissions", post_restrict_chat_member_request->use_independent_chat_permissions) == NULL) {
    goto fail; //Bool
    }
    }


    // post_restrict_chat_member_request->until_date
    if(post_restrict_chat_member_request->until_date) {
    if(cJSON_AddNumberToObject(item, "until_date", post_restrict_chat_member_request->until_date) == NULL) {
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

post_restrict_chat_member_request_t *post_restrict_chat_member_request_parseFromJSON(cJSON *post_restrict_chat_member_requestJSON){

    post_restrict_chat_member_request_t *post_restrict_chat_member_request_local_var = NULL;

    // define the local variable for post_restrict_chat_member_request->chat_id
    post_restrict_chat_member_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for post_restrict_chat_member_request->permissions
    chat_permissions_t *permissions_local_nonprim = NULL;

    // post_restrict_chat_member_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_restrict_chat_member_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_restrict_chat_member_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_restrict_chat_member_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(post_restrict_chat_member_requestJSON, "user_id");
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

    // post_restrict_chat_member_request->permissions
    cJSON *permissions = cJSON_GetObjectItemCaseSensitive(post_restrict_chat_member_requestJSON, "permissions");
    if (cJSON_IsNull(permissions)) {
        permissions = NULL;
    }
    if (!permissions) {
        goto end;
    }

    
    permissions_local_nonprim = chat_permissions_parseFromJSON(permissions); //nonprimitive

    // post_restrict_chat_member_request->use_independent_chat_permissions
    cJSON *use_independent_chat_permissions = cJSON_GetObjectItemCaseSensitive(post_restrict_chat_member_requestJSON, "use_independent_chat_permissions");
    if (cJSON_IsNull(use_independent_chat_permissions)) {
        use_independent_chat_permissions = NULL;
    }
    if (use_independent_chat_permissions) { 
    if(!cJSON_IsBool(use_independent_chat_permissions))
    {
    goto end; //Bool
    }
    }

    // post_restrict_chat_member_request->until_date
    cJSON *until_date = cJSON_GetObjectItemCaseSensitive(post_restrict_chat_member_requestJSON, "until_date");
    if (cJSON_IsNull(until_date)) {
        until_date = NULL;
    }
    if (until_date) { 
    if(!cJSON_IsNumber(until_date))
    {
    goto end; //Numeric
    }
    }


    post_restrict_chat_member_request_local_var = post_restrict_chat_member_request_create_internal (
        chat_id_local_nonprim,
        user_id->valuedouble,
        permissions_local_nonprim,
        use_independent_chat_permissions ? use_independent_chat_permissions->valueint : 0,
        until_date ? until_date->valuedouble : 0
        );

    return post_restrict_chat_member_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_restrict_chat_member_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (permissions_local_nonprim) {
        chat_permissions_free(permissions_local_nonprim);
        permissions_local_nonprim = NULL;
    }
    return NULL;

}
