#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_member_member.h"



static chat_member_member_t *chat_member_member_create_internal(
    char *status,
    user_t *user,
    int until_date
    ) {
    chat_member_member_t *chat_member_member_local_var = malloc(sizeof(chat_member_member_t));
    if (!chat_member_member_local_var) {
        return NULL;
    }
    chat_member_member_local_var->status = status;
    chat_member_member_local_var->user = user;
    chat_member_member_local_var->until_date = until_date;

    chat_member_member_local_var->_library_owned = 1;
    return chat_member_member_local_var;
}

__attribute__((deprecated)) chat_member_member_t *chat_member_member_create(
    char *status,
    user_t *user,
    int until_date
    ) {
    return chat_member_member_create_internal (
        status,
        user,
        until_date
        );
}

void chat_member_member_free(chat_member_member_t *chat_member_member) {
    if(NULL == chat_member_member){
        return ;
    }
    if(chat_member_member->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_member_member_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_member_member->status) {
        free(chat_member_member->status);
        chat_member_member->status = NULL;
    }
    if (chat_member_member->user) {
        user_free(chat_member_member->user);
        chat_member_member->user = NULL;
    }
    free(chat_member_member);
}

cJSON *chat_member_member_convertToJSON(chat_member_member_t *chat_member_member) {
    cJSON *item = cJSON_CreateObject();

    // chat_member_member->status
    if (!chat_member_member->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", chat_member_member->status) == NULL) {
    goto fail; //String
    }


    // chat_member_member->user
    if (!chat_member_member->user) {
        goto fail;
    }
    cJSON *user_local_JSON = user_convertToJSON(chat_member_member->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // chat_member_member->until_date
    if(chat_member_member->until_date) {
    if(cJSON_AddNumberToObject(item, "until_date", chat_member_member->until_date) == NULL) {
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

chat_member_member_t *chat_member_member_parseFromJSON(cJSON *chat_member_memberJSON){

    chat_member_member_t *chat_member_member_local_var = NULL;

    // define the local variable for chat_member_member->user
    user_t *user_local_nonprim = NULL;

    // chat_member_member->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(chat_member_memberJSON, "status");
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

    // chat_member_member->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(chat_member_memberJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (!user) {
        goto end;
    }

    
    user_local_nonprim = user_parseFromJSON(user); //nonprimitive

    // chat_member_member->until_date
    cJSON *until_date = cJSON_GetObjectItemCaseSensitive(chat_member_memberJSON, "until_date");
    if (cJSON_IsNull(until_date)) {
        until_date = NULL;
    }
    if (until_date) { 
    if(!cJSON_IsNumber(until_date))
    {
    goto end; //Numeric
    }
    }


    chat_member_member_local_var = chat_member_member_create_internal (
        strdup(status->valuestring),
        user_local_nonprim,
        until_date ? until_date->valuedouble : 0
        );

    return chat_member_member_local_var;
end:
    if (user_local_nonprim) {
        user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
