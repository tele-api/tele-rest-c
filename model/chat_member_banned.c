#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_member_banned.h"



static chat_member_banned_t *chat_member_banned_create_internal(
    char *status,
    user_t *user,
    int until_date
    ) {
    chat_member_banned_t *chat_member_banned_local_var = malloc(sizeof(chat_member_banned_t));
    if (!chat_member_banned_local_var) {
        return NULL;
    }
    chat_member_banned_local_var->status = status;
    chat_member_banned_local_var->user = user;
    chat_member_banned_local_var->until_date = until_date;

    chat_member_banned_local_var->_library_owned = 1;
    return chat_member_banned_local_var;
}

__attribute__((deprecated)) chat_member_banned_t *chat_member_banned_create(
    char *status,
    user_t *user,
    int until_date
    ) {
    return chat_member_banned_create_internal (
        status,
        user,
        until_date
        );
}

void chat_member_banned_free(chat_member_banned_t *chat_member_banned) {
    if(NULL == chat_member_banned){
        return ;
    }
    if(chat_member_banned->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_member_banned_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_member_banned->status) {
        free(chat_member_banned->status);
        chat_member_banned->status = NULL;
    }
    if (chat_member_banned->user) {
        user_free(chat_member_banned->user);
        chat_member_banned->user = NULL;
    }
    free(chat_member_banned);
}

cJSON *chat_member_banned_convertToJSON(chat_member_banned_t *chat_member_banned) {
    cJSON *item = cJSON_CreateObject();

    // chat_member_banned->status
    if (!chat_member_banned->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", chat_member_banned->status) == NULL) {
    goto fail; //String
    }


    // chat_member_banned->user
    if (!chat_member_banned->user) {
        goto fail;
    }
    cJSON *user_local_JSON = user_convertToJSON(chat_member_banned->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // chat_member_banned->until_date
    if (!chat_member_banned->until_date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "until_date", chat_member_banned->until_date) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

chat_member_banned_t *chat_member_banned_parseFromJSON(cJSON *chat_member_bannedJSON){

    chat_member_banned_t *chat_member_banned_local_var = NULL;

    // define the local variable for chat_member_banned->user
    user_t *user_local_nonprim = NULL;

    // chat_member_banned->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(chat_member_bannedJSON, "status");
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

    // chat_member_banned->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(chat_member_bannedJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (!user) {
        goto end;
    }

    
    user_local_nonprim = user_parseFromJSON(user); //nonprimitive

    // chat_member_banned->until_date
    cJSON *until_date = cJSON_GetObjectItemCaseSensitive(chat_member_bannedJSON, "until_date");
    if (cJSON_IsNull(until_date)) {
        until_date = NULL;
    }
    if (!until_date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(until_date))
    {
    goto end; //Numeric
    }


    chat_member_banned_local_var = chat_member_banned_create_internal (
        strdup(status->valuestring),
        user_local_nonprim,
        until_date->valuedouble
        );

    return chat_member_banned_local_var;
end:
    if (user_local_nonprim) {
        user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
