#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat.h"


char* chat_type_ToString(telegram_bot_api_chat_TYPE_e type) {
    char* typeArray[] =  { "NULL", "private", "group", "supergroup", "channel" };
    return typeArray[type];
}

telegram_bot_api_chat_TYPE_e chat_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "private", "group", "supergroup", "channel" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static chat_t *chat_create_internal(
    int id,
    telegram_bot_api_chat_TYPE_e type,
    char *title,
    char *username,
    char *first_name,
    char *last_name,
    int is_forum
    ) {
    chat_t *chat_local_var = malloc(sizeof(chat_t));
    if (!chat_local_var) {
        return NULL;
    }
    chat_local_var->id = id;
    chat_local_var->type = type;
    chat_local_var->title = title;
    chat_local_var->username = username;
    chat_local_var->first_name = first_name;
    chat_local_var->last_name = last_name;
    chat_local_var->is_forum = is_forum;

    chat_local_var->_library_owned = 1;
    return chat_local_var;
}

__attribute__((deprecated)) chat_t *chat_create(
    int id,
    telegram_bot_api_chat_TYPE_e type,
    char *title,
    char *username,
    char *first_name,
    char *last_name,
    int is_forum
    ) {
    return chat_create_internal (
        id,
        type,
        title,
        username,
        first_name,
        last_name,
        is_forum
        );
}

void chat_free(chat_t *chat) {
    if(NULL == chat){
        return ;
    }
    if(chat->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat->title) {
        free(chat->title);
        chat->title = NULL;
    }
    if (chat->username) {
        free(chat->username);
        chat->username = NULL;
    }
    if (chat->first_name) {
        free(chat->first_name);
        chat->first_name = NULL;
    }
    if (chat->last_name) {
        free(chat->last_name);
        chat->last_name = NULL;
    }
    free(chat);
}

cJSON *chat_convertToJSON(chat_t *chat) {
    cJSON *item = cJSON_CreateObject();

    // chat->id
    if (!chat->id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "id", chat->id) == NULL) {
    goto fail; //Numeric
    }


    // chat->type
    if (telegram_bot_api_chat_TYPE_NULL == chat->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", chat_type_ToString(chat->type)) == NULL)
    {
    goto fail; //Enum
    }


    // chat->title
    if(chat->title) {
    if(cJSON_AddStringToObject(item, "title", chat->title) == NULL) {
    goto fail; //String
    }
    }


    // chat->username
    if(chat->username) {
    if(cJSON_AddStringToObject(item, "username", chat->username) == NULL) {
    goto fail; //String
    }
    }


    // chat->first_name
    if(chat->first_name) {
    if(cJSON_AddStringToObject(item, "first_name", chat->first_name) == NULL) {
    goto fail; //String
    }
    }


    // chat->last_name
    if(chat->last_name) {
    if(cJSON_AddStringToObject(item, "last_name", chat->last_name) == NULL) {
    goto fail; //String
    }
    }


    // chat->is_forum
    if(chat->is_forum) {
    if(cJSON_AddBoolToObject(item, "is_forum", chat->is_forum) == NULL) {
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

chat_t *chat_parseFromJSON(cJSON *chatJSON){

    chat_t *chat_local_var = NULL;

    // chat->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(chatJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(id))
    {
    goto end; //Numeric
    }

    // chat->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(chatJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    telegram_bot_api_chat_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = chat_type_FromString(type->valuestring);

    // chat->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(chatJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // chat->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(chatJSON, "username");
    if (cJSON_IsNull(username)) {
        username = NULL;
    }
    if (username) { 
    if(!cJSON_IsString(username) && !cJSON_IsNull(username))
    {
    goto end; //String
    }
    }

    // chat->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(chatJSON, "first_name");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (first_name) { 
    if(!cJSON_IsString(first_name) && !cJSON_IsNull(first_name))
    {
    goto end; //String
    }
    }

    // chat->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(chatJSON, "last_name");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }

    // chat->is_forum
    cJSON *is_forum = cJSON_GetObjectItemCaseSensitive(chatJSON, "is_forum");
    if (cJSON_IsNull(is_forum)) {
        is_forum = NULL;
    }
    if (is_forum) { 
    if(!cJSON_IsBool(is_forum))
    {
    goto end; //Bool
    }
    }


    chat_local_var = chat_create_internal (
        id->valuedouble,
        typeVariable,
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        username && !cJSON_IsNull(username) ? strdup(username->valuestring) : NULL,
        first_name && !cJSON_IsNull(first_name) ? strdup(first_name->valuestring) : NULL,
        last_name && !cJSON_IsNull(last_name) ? strdup(last_name->valuestring) : NULL,
        is_forum ? is_forum->valueint : 0
        );

    return chat_local_var;
end:
    return NULL;

}
