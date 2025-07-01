#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "message_entity.h"


char* message_entity_type_ToString(telegram_bot_api_message_entity_TYPE_e type) {
    char* typeArray[] =  { "NULL", "mention", "hashtag", "cashtag", "bot_command", "url", "email", "phone_number", "bold", "italic", "underline", "strikethrough", "spoiler", "blockquote", "expandable_blockquote", "code", "pre", "text_link", "text_mention", "custom_emoji" };
    return typeArray[type];
}

telegram_bot_api_message_entity_TYPE_e message_entity_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "mention", "hashtag", "cashtag", "bot_command", "url", "email", "phone_number", "bold", "italic", "underline", "strikethrough", "spoiler", "blockquote", "expandable_blockquote", "code", "pre", "text_link", "text_mention", "custom_emoji" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static message_entity_t *message_entity_create_internal(
    telegram_bot_api_message_entity_TYPE_e type,
    int offset,
    int length,
    char *url,
    user_t *user,
    char *language,
    char *custom_emoji_id
    ) {
    message_entity_t *message_entity_local_var = malloc(sizeof(message_entity_t));
    if (!message_entity_local_var) {
        return NULL;
    }
    message_entity_local_var->type = type;
    message_entity_local_var->offset = offset;
    message_entity_local_var->length = length;
    message_entity_local_var->url = url;
    message_entity_local_var->user = user;
    message_entity_local_var->language = language;
    message_entity_local_var->custom_emoji_id = custom_emoji_id;

    message_entity_local_var->_library_owned = 1;
    return message_entity_local_var;
}

__attribute__((deprecated)) message_entity_t *message_entity_create(
    telegram_bot_api_message_entity_TYPE_e type,
    int offset,
    int length,
    char *url,
    user_t *user,
    char *language,
    char *custom_emoji_id
    ) {
    return message_entity_create_internal (
        type,
        offset,
        length,
        url,
        user,
        language,
        custom_emoji_id
        );
}

void message_entity_free(message_entity_t *message_entity) {
    if(NULL == message_entity){
        return ;
    }
    if(message_entity->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "message_entity_free");
        return ;
    }
    listEntry_t *listEntry;
    if (message_entity->url) {
        free(message_entity->url);
        message_entity->url = NULL;
    }
    if (message_entity->user) {
        user_free(message_entity->user);
        message_entity->user = NULL;
    }
    if (message_entity->language) {
        free(message_entity->language);
        message_entity->language = NULL;
    }
    if (message_entity->custom_emoji_id) {
        free(message_entity->custom_emoji_id);
        message_entity->custom_emoji_id = NULL;
    }
    free(message_entity);
}

cJSON *message_entity_convertToJSON(message_entity_t *message_entity) {
    cJSON *item = cJSON_CreateObject();

    // message_entity->type
    if (telegram_bot_api_message_entity_TYPE_NULL == message_entity->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", message_entity_type_ToString(message_entity->type)) == NULL)
    {
    goto fail; //Enum
    }


    // message_entity->offset
    if (!message_entity->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", message_entity->offset) == NULL) {
    goto fail; //Numeric
    }


    // message_entity->length
    if (!message_entity->length) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "length", message_entity->length) == NULL) {
    goto fail; //Numeric
    }


    // message_entity->url
    if(message_entity->url) {
    if(cJSON_AddStringToObject(item, "url", message_entity->url) == NULL) {
    goto fail; //String
    }
    }


    // message_entity->user
    if(message_entity->user) {
    cJSON *user_local_JSON = user_convertToJSON(message_entity->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // message_entity->language
    if(message_entity->language) {
    if(cJSON_AddStringToObject(item, "language", message_entity->language) == NULL) {
    goto fail; //String
    }
    }


    // message_entity->custom_emoji_id
    if(message_entity->custom_emoji_id) {
    if(cJSON_AddStringToObject(item, "custom_emoji_id", message_entity->custom_emoji_id) == NULL) {
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

message_entity_t *message_entity_parseFromJSON(cJSON *message_entityJSON){

    message_entity_t *message_entity_local_var = NULL;

    // define the local variable for message_entity->user
    user_t *user_local_nonprim = NULL;

    // message_entity->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(message_entityJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    telegram_bot_api_message_entity_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = message_entity_type_FromString(type->valuestring);

    // message_entity->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(message_entityJSON, "offset");
    if (cJSON_IsNull(offset)) {
        offset = NULL;
    }
    if (!offset) {
        goto end;
    }

    
    if(!cJSON_IsNumber(offset))
    {
    goto end; //Numeric
    }

    // message_entity->length
    cJSON *length = cJSON_GetObjectItemCaseSensitive(message_entityJSON, "length");
    if (cJSON_IsNull(length)) {
        length = NULL;
    }
    if (!length) {
        goto end;
    }

    
    if(!cJSON_IsNumber(length))
    {
    goto end; //Numeric
    }

    // message_entity->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(message_entityJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }

    // message_entity->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(message_entityJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (user) { 
    user_local_nonprim = user_parseFromJSON(user); //nonprimitive
    }

    // message_entity->language
    cJSON *language = cJSON_GetObjectItemCaseSensitive(message_entityJSON, "language");
    if (cJSON_IsNull(language)) {
        language = NULL;
    }
    if (language) { 
    if(!cJSON_IsString(language) && !cJSON_IsNull(language))
    {
    goto end; //String
    }
    }

    // message_entity->custom_emoji_id
    cJSON *custom_emoji_id = cJSON_GetObjectItemCaseSensitive(message_entityJSON, "custom_emoji_id");
    if (cJSON_IsNull(custom_emoji_id)) {
        custom_emoji_id = NULL;
    }
    if (custom_emoji_id) { 
    if(!cJSON_IsString(custom_emoji_id) && !cJSON_IsNull(custom_emoji_id))
    {
    goto end; //String
    }
    }


    message_entity_local_var = message_entity_create_internal (
        typeVariable,
        offset->valuedouble,
        length->valuedouble,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL,
        user ? user_local_nonprim : NULL,
        language && !cJSON_IsNull(language) ? strdup(language->valuestring) : NULL,
        custom_emoji_id && !cJSON_IsNull(custom_emoji_id) ? strdup(custom_emoji_id->valuestring) : NULL
        );

    return message_entity_local_var;
end:
    if (user_local_nonprim) {
        user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
