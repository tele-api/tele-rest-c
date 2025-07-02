#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_chat_permissions_request.h"



static post_set_chat_permissions_request_t *post_set_chat_permissions_request_create_internal(
    post_restrict_chat_member_request_chat_id_t *chat_id,
    chat_permissions_t *permissions,
    int use_independent_chat_permissions
    ) {
    post_set_chat_permissions_request_t *post_set_chat_permissions_request_local_var = malloc(sizeof(post_set_chat_permissions_request_t));
    if (!post_set_chat_permissions_request_local_var) {
        return NULL;
    }
    post_set_chat_permissions_request_local_var->chat_id = chat_id;
    post_set_chat_permissions_request_local_var->permissions = permissions;
    post_set_chat_permissions_request_local_var->use_independent_chat_permissions = use_independent_chat_permissions;

    post_set_chat_permissions_request_local_var->_library_owned = 1;
    return post_set_chat_permissions_request_local_var;
}

__attribute__((deprecated)) post_set_chat_permissions_request_t *post_set_chat_permissions_request_create(
    post_restrict_chat_member_request_chat_id_t *chat_id,
    chat_permissions_t *permissions,
    int use_independent_chat_permissions
    ) {
    return post_set_chat_permissions_request_create_internal (
        chat_id,
        permissions,
        use_independent_chat_permissions
        );
}

void post_set_chat_permissions_request_free(post_set_chat_permissions_request_t *post_set_chat_permissions_request) {
    if(NULL == post_set_chat_permissions_request){
        return ;
    }
    if(post_set_chat_permissions_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_chat_permissions_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_chat_permissions_request->chat_id) {
        post_restrict_chat_member_request_chat_id_free(post_set_chat_permissions_request->chat_id);
        post_set_chat_permissions_request->chat_id = NULL;
    }
    if (post_set_chat_permissions_request->permissions) {
        chat_permissions_free(post_set_chat_permissions_request->permissions);
        post_set_chat_permissions_request->permissions = NULL;
    }
    free(post_set_chat_permissions_request);
}

cJSON *post_set_chat_permissions_request_convertToJSON(post_set_chat_permissions_request_t *post_set_chat_permissions_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_chat_permissions_request->chat_id
    if (!post_set_chat_permissions_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_restrict_chat_member_request_chat_id_convertToJSON(post_set_chat_permissions_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_set_chat_permissions_request->permissions
    if (!post_set_chat_permissions_request->permissions) {
        goto fail;
    }
    cJSON *permissions_local_JSON = chat_permissions_convertToJSON(post_set_chat_permissions_request->permissions);
    if(permissions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "permissions", permissions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_set_chat_permissions_request->use_independent_chat_permissions
    if(post_set_chat_permissions_request->use_independent_chat_permissions) {
    if(cJSON_AddBoolToObject(item, "use_independent_chat_permissions", post_set_chat_permissions_request->use_independent_chat_permissions) == NULL) {
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

post_set_chat_permissions_request_t *post_set_chat_permissions_request_parseFromJSON(cJSON *post_set_chat_permissions_requestJSON){

    post_set_chat_permissions_request_t *post_set_chat_permissions_request_local_var = NULL;

    // define the local variable for post_set_chat_permissions_request->chat_id
    post_restrict_chat_member_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for post_set_chat_permissions_request->permissions
    chat_permissions_t *permissions_local_nonprim = NULL;

    // post_set_chat_permissions_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_set_chat_permissions_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_restrict_chat_member_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_set_chat_permissions_request->permissions
    cJSON *permissions = cJSON_GetObjectItemCaseSensitive(post_set_chat_permissions_requestJSON, "permissions");
    if (cJSON_IsNull(permissions)) {
        permissions = NULL;
    }
    if (!permissions) {
        goto end;
    }

    
    permissions_local_nonprim = chat_permissions_parseFromJSON(permissions); //nonprimitive

    // post_set_chat_permissions_request->use_independent_chat_permissions
    cJSON *use_independent_chat_permissions = cJSON_GetObjectItemCaseSensitive(post_set_chat_permissions_requestJSON, "use_independent_chat_permissions");
    if (cJSON_IsNull(use_independent_chat_permissions)) {
        use_independent_chat_permissions = NULL;
    }
    if (use_independent_chat_permissions) { 
    if(!cJSON_IsBool(use_independent_chat_permissions))
    {
    goto end; //Bool
    }
    }


    post_set_chat_permissions_request_local_var = post_set_chat_permissions_request_create_internal (
        chat_id_local_nonprim,
        permissions_local_nonprim,
        use_independent_chat_permissions ? use_independent_chat_permissions->valueint : 0
        );

    return post_set_chat_permissions_request_local_var;
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
