#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reply_parameters.h"



static reply_parameters_t *reply_parameters_create_internal(
    int message_id,
    reply_parameters_chat_id_t *chat_id,
    int allow_sending_without_reply,
    char *quote,
    char *quote_parse_mode,
    list_t *quote_entities,
    int quote_position
    ) {
    reply_parameters_t *reply_parameters_local_var = malloc(sizeof(reply_parameters_t));
    if (!reply_parameters_local_var) {
        return NULL;
    }
    reply_parameters_local_var->message_id = message_id;
    reply_parameters_local_var->chat_id = chat_id;
    reply_parameters_local_var->allow_sending_without_reply = allow_sending_without_reply;
    reply_parameters_local_var->quote = quote;
    reply_parameters_local_var->quote_parse_mode = quote_parse_mode;
    reply_parameters_local_var->quote_entities = quote_entities;
    reply_parameters_local_var->quote_position = quote_position;

    reply_parameters_local_var->_library_owned = 1;
    return reply_parameters_local_var;
}

__attribute__((deprecated)) reply_parameters_t *reply_parameters_create(
    int message_id,
    reply_parameters_chat_id_t *chat_id,
    int allow_sending_without_reply,
    char *quote,
    char *quote_parse_mode,
    list_t *quote_entities,
    int quote_position
    ) {
    return reply_parameters_create_internal (
        message_id,
        chat_id,
        allow_sending_without_reply,
        quote,
        quote_parse_mode,
        quote_entities,
        quote_position
        );
}

void reply_parameters_free(reply_parameters_t *reply_parameters) {
    if(NULL == reply_parameters){
        return ;
    }
    if(reply_parameters->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reply_parameters_free");
        return ;
    }
    listEntry_t *listEntry;
    if (reply_parameters->chat_id) {
        reply_parameters_chat_id_free(reply_parameters->chat_id);
        reply_parameters->chat_id = NULL;
    }
    if (reply_parameters->quote) {
        free(reply_parameters->quote);
        reply_parameters->quote = NULL;
    }
    if (reply_parameters->quote_parse_mode) {
        free(reply_parameters->quote_parse_mode);
        reply_parameters->quote_parse_mode = NULL;
    }
    if (reply_parameters->quote_entities) {
        list_ForEach(listEntry, reply_parameters->quote_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(reply_parameters->quote_entities);
        reply_parameters->quote_entities = NULL;
    }
    free(reply_parameters);
}

cJSON *reply_parameters_convertToJSON(reply_parameters_t *reply_parameters) {
    cJSON *item = cJSON_CreateObject();

    // reply_parameters->message_id
    if (!reply_parameters->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", reply_parameters->message_id) == NULL) {
    goto fail; //Numeric
    }


    // reply_parameters->chat_id
    if(reply_parameters->chat_id) {
    cJSON *chat_id_local_JSON = reply_parameters_chat_id_convertToJSON(reply_parameters->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // reply_parameters->allow_sending_without_reply
    if(reply_parameters->allow_sending_without_reply) {
    if(cJSON_AddBoolToObject(item, "allow_sending_without_reply", reply_parameters->allow_sending_without_reply) == NULL) {
    goto fail; //Bool
    }
    }


    // reply_parameters->quote
    if(reply_parameters->quote) {
    if(cJSON_AddStringToObject(item, "quote", reply_parameters->quote) == NULL) {
    goto fail; //String
    }
    }


    // reply_parameters->quote_parse_mode
    if(reply_parameters->quote_parse_mode) {
    if(cJSON_AddStringToObject(item, "quote_parse_mode", reply_parameters->quote_parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // reply_parameters->quote_entities
    if(reply_parameters->quote_entities) {
    cJSON *quote_entities = cJSON_AddArrayToObject(item, "quote_entities");
    if(quote_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *quote_entitiesListEntry;
    if (reply_parameters->quote_entities) {
    list_ForEach(quote_entitiesListEntry, reply_parameters->quote_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(quote_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(quote_entities, itemLocal);
    }
    }
    }


    // reply_parameters->quote_position
    if(reply_parameters->quote_position) {
    if(cJSON_AddNumberToObject(item, "quote_position", reply_parameters->quote_position) == NULL) {
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

reply_parameters_t *reply_parameters_parseFromJSON(cJSON *reply_parametersJSON){

    reply_parameters_t *reply_parameters_local_var = NULL;

    // define the local variable for reply_parameters->chat_id
    reply_parameters_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for reply_parameters->quote_entities
    list_t *quote_entitiesList = NULL;

    // reply_parameters->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(reply_parametersJSON, "message_id");
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

    // reply_parameters->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(reply_parametersJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (chat_id) { 
    chat_id_local_nonprim = reply_parameters_chat_id_parseFromJSON(chat_id); //nonprimitive
    }

    // reply_parameters->allow_sending_without_reply
    cJSON *allow_sending_without_reply = cJSON_GetObjectItemCaseSensitive(reply_parametersJSON, "allow_sending_without_reply");
    if (cJSON_IsNull(allow_sending_without_reply)) {
        allow_sending_without_reply = NULL;
    }
    if (allow_sending_without_reply) { 
    if(!cJSON_IsBool(allow_sending_without_reply))
    {
    goto end; //Bool
    }
    }

    // reply_parameters->quote
    cJSON *quote = cJSON_GetObjectItemCaseSensitive(reply_parametersJSON, "quote");
    if (cJSON_IsNull(quote)) {
        quote = NULL;
    }
    if (quote) { 
    if(!cJSON_IsString(quote) && !cJSON_IsNull(quote))
    {
    goto end; //String
    }
    }

    // reply_parameters->quote_parse_mode
    cJSON *quote_parse_mode = cJSON_GetObjectItemCaseSensitive(reply_parametersJSON, "quote_parse_mode");
    if (cJSON_IsNull(quote_parse_mode)) {
        quote_parse_mode = NULL;
    }
    if (quote_parse_mode) { 
    if(!cJSON_IsString(quote_parse_mode) && !cJSON_IsNull(quote_parse_mode))
    {
    goto end; //String
    }
    }

    // reply_parameters->quote_entities
    cJSON *quote_entities = cJSON_GetObjectItemCaseSensitive(reply_parametersJSON, "quote_entities");
    if (cJSON_IsNull(quote_entities)) {
        quote_entities = NULL;
    }
    if (quote_entities) { 
    cJSON *quote_entities_local_nonprimitive = NULL;
    if(!cJSON_IsArray(quote_entities)){
        goto end; //nonprimitive container
    }

    quote_entitiesList = list_createList();

    cJSON_ArrayForEach(quote_entities_local_nonprimitive,quote_entities )
    {
        if(!cJSON_IsObject(quote_entities_local_nonprimitive)){
            goto end;
        }
        message_entity_t *quote_entitiesItem = message_entity_parseFromJSON(quote_entities_local_nonprimitive);

        list_addElement(quote_entitiesList, quote_entitiesItem);
    }
    }

    // reply_parameters->quote_position
    cJSON *quote_position = cJSON_GetObjectItemCaseSensitive(reply_parametersJSON, "quote_position");
    if (cJSON_IsNull(quote_position)) {
        quote_position = NULL;
    }
    if (quote_position) { 
    if(!cJSON_IsNumber(quote_position))
    {
    goto end; //Numeric
    }
    }


    reply_parameters_local_var = reply_parameters_create_internal (
        message_id->valuedouble,
        chat_id ? chat_id_local_nonprim : NULL,
        allow_sending_without_reply ? allow_sending_without_reply->valueint : 0,
        quote && !cJSON_IsNull(quote) ? strdup(quote->valuestring) : NULL,
        quote_parse_mode && !cJSON_IsNull(quote_parse_mode) ? strdup(quote_parse_mode->valuestring) : NULL,
        quote_entities ? quote_entitiesList : NULL,
        quote_position ? quote_position->valuedouble : 0
        );

    return reply_parameters_local_var;
end:
    if (chat_id_local_nonprim) {
        reply_parameters_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (quote_entitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, quote_entitiesList) {
            message_entity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(quote_entitiesList);
        quote_entitiesList = NULL;
    }
    return NULL;

}
