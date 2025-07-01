#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "message_origin_user.h"



static message_origin_user_t *message_origin_user_create_internal(
    char *type,
    int date,
    user_t *sender_user
    ) {
    message_origin_user_t *message_origin_user_local_var = malloc(sizeof(message_origin_user_t));
    if (!message_origin_user_local_var) {
        return NULL;
    }
    message_origin_user_local_var->type = type;
    message_origin_user_local_var->date = date;
    message_origin_user_local_var->sender_user = sender_user;

    message_origin_user_local_var->_library_owned = 1;
    return message_origin_user_local_var;
}

__attribute__((deprecated)) message_origin_user_t *message_origin_user_create(
    char *type,
    int date,
    user_t *sender_user
    ) {
    return message_origin_user_create_internal (
        type,
        date,
        sender_user
        );
}

void message_origin_user_free(message_origin_user_t *message_origin_user) {
    if(NULL == message_origin_user){
        return ;
    }
    if(message_origin_user->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "message_origin_user_free");
        return ;
    }
    listEntry_t *listEntry;
    if (message_origin_user->type) {
        free(message_origin_user->type);
        message_origin_user->type = NULL;
    }
    if (message_origin_user->sender_user) {
        user_free(message_origin_user->sender_user);
        message_origin_user->sender_user = NULL;
    }
    free(message_origin_user);
}

cJSON *message_origin_user_convertToJSON(message_origin_user_t *message_origin_user) {
    cJSON *item = cJSON_CreateObject();

    // message_origin_user->type
    if (!message_origin_user->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", message_origin_user->type) == NULL) {
    goto fail; //String
    }


    // message_origin_user->date
    if (!message_origin_user->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", message_origin_user->date) == NULL) {
    goto fail; //Numeric
    }


    // message_origin_user->sender_user
    if (!message_origin_user->sender_user) {
        goto fail;
    }
    cJSON *sender_user_local_JSON = user_convertToJSON(message_origin_user->sender_user);
    if(sender_user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sender_user", sender_user_local_JSON);
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

message_origin_user_t *message_origin_user_parseFromJSON(cJSON *message_origin_userJSON){

    message_origin_user_t *message_origin_user_local_var = NULL;

    // define the local variable for message_origin_user->sender_user
    user_t *sender_user_local_nonprim = NULL;

    // message_origin_user->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(message_origin_userJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // message_origin_user->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(message_origin_userJSON, "date");
    if (cJSON_IsNull(date)) {
        date = NULL;
    }
    if (!date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(date))
    {
    goto end; //Numeric
    }

    // message_origin_user->sender_user
    cJSON *sender_user = cJSON_GetObjectItemCaseSensitive(message_origin_userJSON, "sender_user");
    if (cJSON_IsNull(sender_user)) {
        sender_user = NULL;
    }
    if (!sender_user) {
        goto end;
    }

    
    sender_user_local_nonprim = user_parseFromJSON(sender_user); //nonprimitive


    message_origin_user_local_var = message_origin_user_create_internal (
        strdup(type->valuestring),
        date->valuedouble,
        sender_user_local_nonprim
        );

    return message_origin_user_local_var;
end:
    if (sender_user_local_nonprim) {
        user_free(sender_user_local_nonprim);
        sender_user_local_nonprim = NULL;
    }
    return NULL;

}
