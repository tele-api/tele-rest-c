#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_member_left.h"



static chat_member_left_t *chat_member_left_create_internal(
    char *status,
    user_t *user
    ) {
    chat_member_left_t *chat_member_left_local_var = malloc(sizeof(chat_member_left_t));
    if (!chat_member_left_local_var) {
        return NULL;
    }
    chat_member_left_local_var->status = status;
    chat_member_left_local_var->user = user;

    chat_member_left_local_var->_library_owned = 1;
    return chat_member_left_local_var;
}

__attribute__((deprecated)) chat_member_left_t *chat_member_left_create(
    char *status,
    user_t *user
    ) {
    return chat_member_left_create_internal (
        status,
        user
        );
}

void chat_member_left_free(chat_member_left_t *chat_member_left) {
    if(NULL == chat_member_left){
        return ;
    }
    if(chat_member_left->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_member_left_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_member_left->status) {
        free(chat_member_left->status);
        chat_member_left->status = NULL;
    }
    if (chat_member_left->user) {
        user_free(chat_member_left->user);
        chat_member_left->user = NULL;
    }
    free(chat_member_left);
}

cJSON *chat_member_left_convertToJSON(chat_member_left_t *chat_member_left) {
    cJSON *item = cJSON_CreateObject();

    // chat_member_left->status
    if (!chat_member_left->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", chat_member_left->status) == NULL) {
    goto fail; //String
    }


    // chat_member_left->user
    if (!chat_member_left->user) {
        goto fail;
    }
    cJSON *user_local_JSON = user_convertToJSON(chat_member_left->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
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

chat_member_left_t *chat_member_left_parseFromJSON(cJSON *chat_member_leftJSON){

    chat_member_left_t *chat_member_left_local_var = NULL;

    // define the local variable for chat_member_left->user
    user_t *user_local_nonprim = NULL;

    // chat_member_left->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(chat_member_leftJSON, "status");
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

    // chat_member_left->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(chat_member_leftJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (!user) {
        goto end;
    }

    
    user_local_nonprim = user_parseFromJSON(user); //nonprimitive


    chat_member_left_local_var = chat_member_left_create_internal (
        strdup(status->valuestring),
        user_local_nonprim
        );

    return chat_member_left_local_var;
end:
    if (user_local_nonprim) {
        user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
