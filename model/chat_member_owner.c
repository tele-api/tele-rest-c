#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_member_owner.h"



static chat_member_owner_t *chat_member_owner_create_internal(
    char *status,
    user_t *user,
    int is_anonymous,
    char *custom_title
    ) {
    chat_member_owner_t *chat_member_owner_local_var = malloc(sizeof(chat_member_owner_t));
    if (!chat_member_owner_local_var) {
        return NULL;
    }
    chat_member_owner_local_var->status = status;
    chat_member_owner_local_var->user = user;
    chat_member_owner_local_var->is_anonymous = is_anonymous;
    chat_member_owner_local_var->custom_title = custom_title;

    chat_member_owner_local_var->_library_owned = 1;
    return chat_member_owner_local_var;
}

__attribute__((deprecated)) chat_member_owner_t *chat_member_owner_create(
    char *status,
    user_t *user,
    int is_anonymous,
    char *custom_title
    ) {
    return chat_member_owner_create_internal (
        status,
        user,
        is_anonymous,
        custom_title
        );
}

void chat_member_owner_free(chat_member_owner_t *chat_member_owner) {
    if(NULL == chat_member_owner){
        return ;
    }
    if(chat_member_owner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_member_owner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_member_owner->status) {
        free(chat_member_owner->status);
        chat_member_owner->status = NULL;
    }
    if (chat_member_owner->user) {
        user_free(chat_member_owner->user);
        chat_member_owner->user = NULL;
    }
    if (chat_member_owner->custom_title) {
        free(chat_member_owner->custom_title);
        chat_member_owner->custom_title = NULL;
    }
    free(chat_member_owner);
}

cJSON *chat_member_owner_convertToJSON(chat_member_owner_t *chat_member_owner) {
    cJSON *item = cJSON_CreateObject();

    // chat_member_owner->status
    if (!chat_member_owner->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", chat_member_owner->status) == NULL) {
    goto fail; //String
    }


    // chat_member_owner->user
    if (!chat_member_owner->user) {
        goto fail;
    }
    cJSON *user_local_JSON = user_convertToJSON(chat_member_owner->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // chat_member_owner->is_anonymous
    if (!chat_member_owner->is_anonymous) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_anonymous", chat_member_owner->is_anonymous) == NULL) {
    goto fail; //Bool
    }


    // chat_member_owner->custom_title
    if(chat_member_owner->custom_title) {
    if(cJSON_AddStringToObject(item, "custom_title", chat_member_owner->custom_title) == NULL) {
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

chat_member_owner_t *chat_member_owner_parseFromJSON(cJSON *chat_member_ownerJSON){

    chat_member_owner_t *chat_member_owner_local_var = NULL;

    // define the local variable for chat_member_owner->user
    user_t *user_local_nonprim = NULL;

    // chat_member_owner->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(chat_member_ownerJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // chat_member_owner->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(chat_member_ownerJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (!user) {
        goto end;
    }

    
    user_local_nonprim = user_parseFromJSON(user); //nonprimitive

    // chat_member_owner->is_anonymous
    cJSON *is_anonymous = cJSON_GetObjectItemCaseSensitive(chat_member_ownerJSON, "is_anonymous");
    if (cJSON_IsNull(is_anonymous)) {
        is_anonymous = NULL;
    }
    if (!is_anonymous) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_anonymous))
    {
    goto end; //Bool
    }

    // chat_member_owner->custom_title
    cJSON *custom_title = cJSON_GetObjectItemCaseSensitive(chat_member_ownerJSON, "custom_title");
    if (cJSON_IsNull(custom_title)) {
        custom_title = NULL;
    }
    if (custom_title) { 
    if(!cJSON_IsString(custom_title) && !cJSON_IsNull(custom_title))
    {
    goto end; //String
    }
    }


    chat_member_owner_local_var = chat_member_owner_create_internal (
        strdup(status->valuestring),
        user_local_nonprim,
        is_anonymous->valueint,
        custom_title && !cJSON_IsNull(custom_title) ? strdup(custom_title->valuestring) : NULL
        );

    return chat_member_owner_local_var;
end:
    if (user_local_nonprim) {
        user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
