#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "message_origin_hidden_user.h"



static message_origin_hidden_user_t *message_origin_hidden_user_create_internal(
    char *type,
    int date,
    char *sender_user_name
    ) {
    message_origin_hidden_user_t *message_origin_hidden_user_local_var = malloc(sizeof(message_origin_hidden_user_t));
    if (!message_origin_hidden_user_local_var) {
        return NULL;
    }
    message_origin_hidden_user_local_var->type = type;
    message_origin_hidden_user_local_var->date = date;
    message_origin_hidden_user_local_var->sender_user_name = sender_user_name;

    message_origin_hidden_user_local_var->_library_owned = 1;
    return message_origin_hidden_user_local_var;
}

__attribute__((deprecated)) message_origin_hidden_user_t *message_origin_hidden_user_create(
    char *type,
    int date,
    char *sender_user_name
    ) {
    return message_origin_hidden_user_create_internal (
        type,
        date,
        sender_user_name
        );
}

void message_origin_hidden_user_free(message_origin_hidden_user_t *message_origin_hidden_user) {
    if(NULL == message_origin_hidden_user){
        return ;
    }
    if(message_origin_hidden_user->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "message_origin_hidden_user_free");
        return ;
    }
    listEntry_t *listEntry;
    if (message_origin_hidden_user->type) {
        free(message_origin_hidden_user->type);
        message_origin_hidden_user->type = NULL;
    }
    if (message_origin_hidden_user->sender_user_name) {
        free(message_origin_hidden_user->sender_user_name);
        message_origin_hidden_user->sender_user_name = NULL;
    }
    free(message_origin_hidden_user);
}

cJSON *message_origin_hidden_user_convertToJSON(message_origin_hidden_user_t *message_origin_hidden_user) {
    cJSON *item = cJSON_CreateObject();

    // message_origin_hidden_user->type
    if (!message_origin_hidden_user->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", message_origin_hidden_user->type) == NULL) {
    goto fail; //String
    }


    // message_origin_hidden_user->date
    if (!message_origin_hidden_user->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", message_origin_hidden_user->date) == NULL) {
    goto fail; //Numeric
    }


    // message_origin_hidden_user->sender_user_name
    if (!message_origin_hidden_user->sender_user_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sender_user_name", message_origin_hidden_user->sender_user_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

message_origin_hidden_user_t *message_origin_hidden_user_parseFromJSON(cJSON *message_origin_hidden_userJSON){

    message_origin_hidden_user_t *message_origin_hidden_user_local_var = NULL;

    // message_origin_hidden_user->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(message_origin_hidden_userJSON, "type");
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

    // message_origin_hidden_user->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(message_origin_hidden_userJSON, "date");
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

    // message_origin_hidden_user->sender_user_name
    cJSON *sender_user_name = cJSON_GetObjectItemCaseSensitive(message_origin_hidden_userJSON, "sender_user_name");
    if (cJSON_IsNull(sender_user_name)) {
        sender_user_name = NULL;
    }
    if (!sender_user_name) {
        goto end;
    }

    
    if(!cJSON_IsString(sender_user_name))
    {
    goto end; //String
    }


    message_origin_hidden_user_local_var = message_origin_hidden_user_create_internal (
        strdup(type->valuestring),
        date->valuedouble,
        strdup(sender_user_name->valuestring)
        );

    return message_origin_hidden_user_local_var;
end:
    return NULL;

}
