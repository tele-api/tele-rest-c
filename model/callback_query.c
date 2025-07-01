#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "callback_query.h"



static callback_query_t *callback_query_create_internal(
    char *id,
    user_t *from,
    char *chat_instance,
    maybe_inaccessible_message_t *message,
    char *inline_message_id,
    char *data,
    char *game_short_name
    ) {
    callback_query_t *callback_query_local_var = malloc(sizeof(callback_query_t));
    if (!callback_query_local_var) {
        return NULL;
    }
    callback_query_local_var->id = id;
    callback_query_local_var->from = from;
    callback_query_local_var->chat_instance = chat_instance;
    callback_query_local_var->message = message;
    callback_query_local_var->inline_message_id = inline_message_id;
    callback_query_local_var->data = data;
    callback_query_local_var->game_short_name = game_short_name;

    callback_query_local_var->_library_owned = 1;
    return callback_query_local_var;
}

__attribute__((deprecated)) callback_query_t *callback_query_create(
    char *id,
    user_t *from,
    char *chat_instance,
    maybe_inaccessible_message_t *message,
    char *inline_message_id,
    char *data,
    char *game_short_name
    ) {
    return callback_query_create_internal (
        id,
        from,
        chat_instance,
        message,
        inline_message_id,
        data,
        game_short_name
        );
}

void callback_query_free(callback_query_t *callback_query) {
    if(NULL == callback_query){
        return ;
    }
    if(callback_query->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "callback_query_free");
        return ;
    }
    listEntry_t *listEntry;
    if (callback_query->id) {
        free(callback_query->id);
        callback_query->id = NULL;
    }
    if (callback_query->from) {
        user_free(callback_query->from);
        callback_query->from = NULL;
    }
    if (callback_query->chat_instance) {
        free(callback_query->chat_instance);
        callback_query->chat_instance = NULL;
    }
    if (callback_query->message) {
        maybe_inaccessible_message_free(callback_query->message);
        callback_query->message = NULL;
    }
    if (callback_query->inline_message_id) {
        free(callback_query->inline_message_id);
        callback_query->inline_message_id = NULL;
    }
    if (callback_query->data) {
        free(callback_query->data);
        callback_query->data = NULL;
    }
    if (callback_query->game_short_name) {
        free(callback_query->game_short_name);
        callback_query->game_short_name = NULL;
    }
    free(callback_query);
}

cJSON *callback_query_convertToJSON(callback_query_t *callback_query) {
    cJSON *item = cJSON_CreateObject();

    // callback_query->id
    if (!callback_query->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", callback_query->id) == NULL) {
    goto fail; //String
    }


    // callback_query->from
    if (!callback_query->from) {
        goto fail;
    }
    cJSON *from_local_JSON = user_convertToJSON(callback_query->from);
    if(from_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "from", from_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // callback_query->chat_instance
    if (!callback_query->chat_instance) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "chat_instance", callback_query->chat_instance) == NULL) {
    goto fail; //String
    }


    // callback_query->message
    if(callback_query->message) {
    cJSON *message_local_JSON = maybe_inaccessible_message_convertToJSON(callback_query->message);
    if(message_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "message", message_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // callback_query->inline_message_id
    if(callback_query->inline_message_id) {
    if(cJSON_AddStringToObject(item, "inline_message_id", callback_query->inline_message_id) == NULL) {
    goto fail; //String
    }
    }


    // callback_query->data
    if(callback_query->data) {
    if(cJSON_AddStringToObject(item, "data", callback_query->data) == NULL) {
    goto fail; //String
    }
    }


    // callback_query->game_short_name
    if(callback_query->game_short_name) {
    if(cJSON_AddStringToObject(item, "game_short_name", callback_query->game_short_name) == NULL) {
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

callback_query_t *callback_query_parseFromJSON(cJSON *callback_queryJSON){

    callback_query_t *callback_query_local_var = NULL;

    // define the local variable for callback_query->from
    user_t *from_local_nonprim = NULL;

    // define the local variable for callback_query->message
    maybe_inaccessible_message_t *message_local_nonprim = NULL;

    // callback_query->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(callback_queryJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // callback_query->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(callback_queryJSON, "from");
    if (cJSON_IsNull(from)) {
        from = NULL;
    }
    if (!from) {
        goto end;
    }

    
    from_local_nonprim = user_parseFromJSON(from); //nonprimitive

    // callback_query->chat_instance
    cJSON *chat_instance = cJSON_GetObjectItemCaseSensitive(callback_queryJSON, "chat_instance");
    if (cJSON_IsNull(chat_instance)) {
        chat_instance = NULL;
    }
    if (!chat_instance) {
        goto end;
    }

    
    if(!cJSON_IsString(chat_instance))
    {
    goto end; //String
    }

    // callback_query->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(callback_queryJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    message_local_nonprim = maybe_inaccessible_message_parseFromJSON(message); //nonprimitive
    }

    // callback_query->inline_message_id
    cJSON *inline_message_id = cJSON_GetObjectItemCaseSensitive(callback_queryJSON, "inline_message_id");
    if (cJSON_IsNull(inline_message_id)) {
        inline_message_id = NULL;
    }
    if (inline_message_id) { 
    if(!cJSON_IsString(inline_message_id) && !cJSON_IsNull(inline_message_id))
    {
    goto end; //String
    }
    }

    // callback_query->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(callback_queryJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    if(!cJSON_IsString(data) && !cJSON_IsNull(data))
    {
    goto end; //String
    }
    }

    // callback_query->game_short_name
    cJSON *game_short_name = cJSON_GetObjectItemCaseSensitive(callback_queryJSON, "game_short_name");
    if (cJSON_IsNull(game_short_name)) {
        game_short_name = NULL;
    }
    if (game_short_name) { 
    if(!cJSON_IsString(game_short_name) && !cJSON_IsNull(game_short_name))
    {
    goto end; //String
    }
    }


    callback_query_local_var = callback_query_create_internal (
        strdup(id->valuestring),
        from_local_nonprim,
        strdup(chat_instance->valuestring),
        message ? message_local_nonprim : NULL,
        inline_message_id && !cJSON_IsNull(inline_message_id) ? strdup(inline_message_id->valuestring) : NULL,
        data && !cJSON_IsNull(data) ? strdup(data->valuestring) : NULL,
        game_short_name && !cJSON_IsNull(game_short_name) ? strdup(game_short_name->valuestring) : NULL
        );

    return callback_query_local_var;
end:
    if (from_local_nonprim) {
        user_free(from_local_nonprim);
        from_local_nonprim = NULL;
    }
    if (message_local_nonprim) {
        maybe_inaccessible_message_free(message_local_nonprim);
        message_local_nonprim = NULL;
    }
    return NULL;

}
