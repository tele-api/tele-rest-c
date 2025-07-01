#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "message_origin.h"



static message_origin_t *message_origin_create_internal(
    char *type,
    int date,
    user_t *sender_user,
    char *sender_user_name,
    chat_t *sender_chat,
    chat_t *chat,
    int message_id,
    char *author_signature
    ) {
    message_origin_t *message_origin_local_var = malloc(sizeof(message_origin_t));
    if (!message_origin_local_var) {
        return NULL;
    }
    message_origin_local_var->type = type;
    message_origin_local_var->date = date;
    message_origin_local_var->sender_user = sender_user;
    message_origin_local_var->sender_user_name = sender_user_name;
    message_origin_local_var->sender_chat = sender_chat;
    message_origin_local_var->chat = chat;
    message_origin_local_var->message_id = message_id;
    message_origin_local_var->author_signature = author_signature;

    message_origin_local_var->_library_owned = 1;
    return message_origin_local_var;
}

__attribute__((deprecated)) message_origin_t *message_origin_create(
    char *type,
    int date,
    user_t *sender_user,
    char *sender_user_name,
    chat_t *sender_chat,
    chat_t *chat,
    int message_id,
    char *author_signature
    ) {
    return message_origin_create_internal (
        type,
        date,
        sender_user,
        sender_user_name,
        sender_chat,
        chat,
        message_id,
        author_signature
        );
}

void message_origin_free(message_origin_t *message_origin) {
    if(NULL == message_origin){
        return ;
    }
    if(message_origin->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "message_origin_free");
        return ;
    }
    listEntry_t *listEntry;
    if (message_origin->type) {
        free(message_origin->type);
        message_origin->type = NULL;
    }
    if (message_origin->sender_user) {
        user_free(message_origin->sender_user);
        message_origin->sender_user = NULL;
    }
    if (message_origin->sender_user_name) {
        free(message_origin->sender_user_name);
        message_origin->sender_user_name = NULL;
    }
    if (message_origin->sender_chat) {
        chat_free(message_origin->sender_chat);
        message_origin->sender_chat = NULL;
    }
    if (message_origin->chat) {
        chat_free(message_origin->chat);
        message_origin->chat = NULL;
    }
    if (message_origin->author_signature) {
        free(message_origin->author_signature);
        message_origin->author_signature = NULL;
    }
    free(message_origin);
}

cJSON *message_origin_convertToJSON(message_origin_t *message_origin) {
    cJSON *item = cJSON_CreateObject();

    // message_origin->type
    if (!message_origin->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", message_origin->type) == NULL) {
    goto fail; //String
    }


    // message_origin->date
    if (!message_origin->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", message_origin->date) == NULL) {
    goto fail; //Numeric
    }


    // message_origin->sender_user
    if (!message_origin->sender_user) {
        goto fail;
    }
    cJSON *sender_user_local_JSON = user_convertToJSON(message_origin->sender_user);
    if(sender_user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sender_user", sender_user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // message_origin->sender_user_name
    if (!message_origin->sender_user_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sender_user_name", message_origin->sender_user_name) == NULL) {
    goto fail; //String
    }


    // message_origin->sender_chat
    if (!message_origin->sender_chat) {
        goto fail;
    }
    cJSON *sender_chat_local_JSON = chat_convertToJSON(message_origin->sender_chat);
    if(sender_chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sender_chat", sender_chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // message_origin->chat
    if (!message_origin->chat) {
        goto fail;
    }
    cJSON *chat_local_JSON = chat_convertToJSON(message_origin->chat);
    if(chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat", chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // message_origin->message_id
    if (!message_origin->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", message_origin->message_id) == NULL) {
    goto fail; //Numeric
    }


    // message_origin->author_signature
    if(message_origin->author_signature) {
    if(cJSON_AddStringToObject(item, "author_signature", message_origin->author_signature) == NULL) {
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

message_origin_t *message_origin_parseFromJSON(cJSON *message_originJSON){

    message_origin_t *message_origin_local_var = NULL;

    // define the local variable for message_origin->sender_user
    user_t *sender_user_local_nonprim = NULL;

    // define the local variable for message_origin->sender_chat
    chat_t *sender_chat_local_nonprim = NULL;

    // define the local variable for message_origin->chat
    chat_t *chat_local_nonprim = NULL;

    // message_origin->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(message_originJSON, "type");
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

    // message_origin->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(message_originJSON, "date");
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

    // message_origin->sender_user
    cJSON *sender_user = cJSON_GetObjectItemCaseSensitive(message_originJSON, "sender_user");
    if (cJSON_IsNull(sender_user)) {
        sender_user = NULL;
    }
    if (!sender_user) {
        goto end;
    }

    
    sender_user_local_nonprim = user_parseFromJSON(sender_user); //nonprimitive

    // message_origin->sender_user_name
    cJSON *sender_user_name = cJSON_GetObjectItemCaseSensitive(message_originJSON, "sender_user_name");
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

    // message_origin->sender_chat
    cJSON *sender_chat = cJSON_GetObjectItemCaseSensitive(message_originJSON, "sender_chat");
    if (cJSON_IsNull(sender_chat)) {
        sender_chat = NULL;
    }
    if (!sender_chat) {
        goto end;
    }

    
    sender_chat_local_nonprim = chat_parseFromJSON(sender_chat); //nonprimitive

    // message_origin->chat
    cJSON *chat = cJSON_GetObjectItemCaseSensitive(message_originJSON, "chat");
    if (cJSON_IsNull(chat)) {
        chat = NULL;
    }
    if (!chat) {
        goto end;
    }

    
    chat_local_nonprim = chat_parseFromJSON(chat); //nonprimitive

    // message_origin->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(message_originJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (!message_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }

    // message_origin->author_signature
    cJSON *author_signature = cJSON_GetObjectItemCaseSensitive(message_originJSON, "author_signature");
    if (cJSON_IsNull(author_signature)) {
        author_signature = NULL;
    }
    if (author_signature) { 
    if(!cJSON_IsString(author_signature) && !cJSON_IsNull(author_signature))
    {
    goto end; //String
    }
    }


    message_origin_local_var = message_origin_create_internal (
        strdup(type->valuestring),
        date->valuedouble,
        sender_user_local_nonprim,
        strdup(sender_user_name->valuestring),
        sender_chat_local_nonprim,
        chat_local_nonprim,
        message_id->valuedouble,
        author_signature && !cJSON_IsNull(author_signature) ? strdup(author_signature->valuestring) : NULL
        );

    return message_origin_local_var;
end:
    if (sender_user_local_nonprim) {
        user_free(sender_user_local_nonprim);
        sender_user_local_nonprim = NULL;
    }
    if (sender_chat_local_nonprim) {
        chat_free(sender_chat_local_nonprim);
        sender_chat_local_nonprim = NULL;
    }
    if (chat_local_nonprim) {
        chat_free(chat_local_nonprim);
        chat_local_nonprim = NULL;
    }
    return NULL;

}
