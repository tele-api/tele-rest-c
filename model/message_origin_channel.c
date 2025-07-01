#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "message_origin_channel.h"



static message_origin_channel_t *message_origin_channel_create_internal(
    char *type,
    int date,
    chat_t *chat,
    int message_id,
    char *author_signature
    ) {
    message_origin_channel_t *message_origin_channel_local_var = malloc(sizeof(message_origin_channel_t));
    if (!message_origin_channel_local_var) {
        return NULL;
    }
    message_origin_channel_local_var->type = type;
    message_origin_channel_local_var->date = date;
    message_origin_channel_local_var->chat = chat;
    message_origin_channel_local_var->message_id = message_id;
    message_origin_channel_local_var->author_signature = author_signature;

    message_origin_channel_local_var->_library_owned = 1;
    return message_origin_channel_local_var;
}

__attribute__((deprecated)) message_origin_channel_t *message_origin_channel_create(
    char *type,
    int date,
    chat_t *chat,
    int message_id,
    char *author_signature
    ) {
    return message_origin_channel_create_internal (
        type,
        date,
        chat,
        message_id,
        author_signature
        );
}

void message_origin_channel_free(message_origin_channel_t *message_origin_channel) {
    if(NULL == message_origin_channel){
        return ;
    }
    if(message_origin_channel->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "message_origin_channel_free");
        return ;
    }
    listEntry_t *listEntry;
    if (message_origin_channel->type) {
        free(message_origin_channel->type);
        message_origin_channel->type = NULL;
    }
    if (message_origin_channel->chat) {
        chat_free(message_origin_channel->chat);
        message_origin_channel->chat = NULL;
    }
    if (message_origin_channel->author_signature) {
        free(message_origin_channel->author_signature);
        message_origin_channel->author_signature = NULL;
    }
    free(message_origin_channel);
}

cJSON *message_origin_channel_convertToJSON(message_origin_channel_t *message_origin_channel) {
    cJSON *item = cJSON_CreateObject();

    // message_origin_channel->type
    if (!message_origin_channel->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", message_origin_channel->type) == NULL) {
    goto fail; //String
    }


    // message_origin_channel->date
    if (!message_origin_channel->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", message_origin_channel->date) == NULL) {
    goto fail; //Numeric
    }


    // message_origin_channel->chat
    if (!message_origin_channel->chat) {
        goto fail;
    }
    cJSON *chat_local_JSON = chat_convertToJSON(message_origin_channel->chat);
    if(chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat", chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // message_origin_channel->message_id
    if (!message_origin_channel->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", message_origin_channel->message_id) == NULL) {
    goto fail; //Numeric
    }


    // message_origin_channel->author_signature
    if(message_origin_channel->author_signature) {
    if(cJSON_AddStringToObject(item, "author_signature", message_origin_channel->author_signature) == NULL) {
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

message_origin_channel_t *message_origin_channel_parseFromJSON(cJSON *message_origin_channelJSON){

    message_origin_channel_t *message_origin_channel_local_var = NULL;

    // define the local variable for message_origin_channel->chat
    chat_t *chat_local_nonprim = NULL;

    // message_origin_channel->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(message_origin_channelJSON, "type");
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

    // message_origin_channel->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(message_origin_channelJSON, "date");
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

    // message_origin_channel->chat
    cJSON *chat = cJSON_GetObjectItemCaseSensitive(message_origin_channelJSON, "chat");
    if (cJSON_IsNull(chat)) {
        chat = NULL;
    }
    if (!chat) {
        goto end;
    }

    
    chat_local_nonprim = chat_parseFromJSON(chat); //nonprimitive

    // message_origin_channel->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(message_origin_channelJSON, "message_id");
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

    // message_origin_channel->author_signature
    cJSON *author_signature = cJSON_GetObjectItemCaseSensitive(message_origin_channelJSON, "author_signature");
    if (cJSON_IsNull(author_signature)) {
        author_signature = NULL;
    }
    if (author_signature) { 
    if(!cJSON_IsString(author_signature) && !cJSON_IsNull(author_signature))
    {
    goto end; //String
    }
    }


    message_origin_channel_local_var = message_origin_channel_create_internal (
        strdup(type->valuestring),
        date->valuedouble,
        chat_local_nonprim,
        message_id->valuedouble,
        author_signature && !cJSON_IsNull(author_signature) ? strdup(author_signature->valuestring) : NULL
        );

    return message_origin_channel_local_var;
end:
    if (chat_local_nonprim) {
        chat_free(chat_local_nonprim);
        chat_local_nonprim = NULL;
    }
    return NULL;

}
