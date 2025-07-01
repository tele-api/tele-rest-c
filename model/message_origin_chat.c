#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "message_origin_chat.h"



static message_origin_chat_t *message_origin_chat_create_internal(
    char *type,
    int date,
    chat_t *sender_chat,
    char *author_signature
    ) {
    message_origin_chat_t *message_origin_chat_local_var = malloc(sizeof(message_origin_chat_t));
    if (!message_origin_chat_local_var) {
        return NULL;
    }
    message_origin_chat_local_var->type = type;
    message_origin_chat_local_var->date = date;
    message_origin_chat_local_var->sender_chat = sender_chat;
    message_origin_chat_local_var->author_signature = author_signature;

    message_origin_chat_local_var->_library_owned = 1;
    return message_origin_chat_local_var;
}

__attribute__((deprecated)) message_origin_chat_t *message_origin_chat_create(
    char *type,
    int date,
    chat_t *sender_chat,
    char *author_signature
    ) {
    return message_origin_chat_create_internal (
        type,
        date,
        sender_chat,
        author_signature
        );
}

void message_origin_chat_free(message_origin_chat_t *message_origin_chat) {
    if(NULL == message_origin_chat){
        return ;
    }
    if(message_origin_chat->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "message_origin_chat_free");
        return ;
    }
    listEntry_t *listEntry;
    if (message_origin_chat->type) {
        free(message_origin_chat->type);
        message_origin_chat->type = NULL;
    }
    if (message_origin_chat->sender_chat) {
        chat_free(message_origin_chat->sender_chat);
        message_origin_chat->sender_chat = NULL;
    }
    if (message_origin_chat->author_signature) {
        free(message_origin_chat->author_signature);
        message_origin_chat->author_signature = NULL;
    }
    free(message_origin_chat);
}

cJSON *message_origin_chat_convertToJSON(message_origin_chat_t *message_origin_chat) {
    cJSON *item = cJSON_CreateObject();

    // message_origin_chat->type
    if (!message_origin_chat->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", message_origin_chat->type) == NULL) {
    goto fail; //String
    }


    // message_origin_chat->date
    if (!message_origin_chat->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", message_origin_chat->date) == NULL) {
    goto fail; //Numeric
    }


    // message_origin_chat->sender_chat
    if (!message_origin_chat->sender_chat) {
        goto fail;
    }
    cJSON *sender_chat_local_JSON = chat_convertToJSON(message_origin_chat->sender_chat);
    if(sender_chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sender_chat", sender_chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // message_origin_chat->author_signature
    if(message_origin_chat->author_signature) {
    if(cJSON_AddStringToObject(item, "author_signature", message_origin_chat->author_signature) == NULL) {
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

message_origin_chat_t *message_origin_chat_parseFromJSON(cJSON *message_origin_chatJSON){

    message_origin_chat_t *message_origin_chat_local_var = NULL;

    // define the local variable for message_origin_chat->sender_chat
    chat_t *sender_chat_local_nonprim = NULL;

    // message_origin_chat->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(message_origin_chatJSON, "type");
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

    // message_origin_chat->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(message_origin_chatJSON, "date");
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

    // message_origin_chat->sender_chat
    cJSON *sender_chat = cJSON_GetObjectItemCaseSensitive(message_origin_chatJSON, "sender_chat");
    if (cJSON_IsNull(sender_chat)) {
        sender_chat = NULL;
    }
    if (!sender_chat) {
        goto end;
    }

    
    sender_chat_local_nonprim = chat_parseFromJSON(sender_chat); //nonprimitive

    // message_origin_chat->author_signature
    cJSON *author_signature = cJSON_GetObjectItemCaseSensitive(message_origin_chatJSON, "author_signature");
    if (cJSON_IsNull(author_signature)) {
        author_signature = NULL;
    }
    if (author_signature) { 
    if(!cJSON_IsString(author_signature) && !cJSON_IsNull(author_signature))
    {
    goto end; //String
    }
    }


    message_origin_chat_local_var = message_origin_chat_create_internal (
        strdup(type->valuestring),
        date->valuedouble,
        sender_chat_local_nonprim,
        author_signature && !cJSON_IsNull(author_signature) ? strdup(author_signature->valuestring) : NULL
        );

    return message_origin_chat_local_var;
end:
    if (sender_chat_local_nonprim) {
        chat_free(sender_chat_local_nonprim);
        sender_chat_local_nonprim = NULL;
    }
    return NULL;

}
