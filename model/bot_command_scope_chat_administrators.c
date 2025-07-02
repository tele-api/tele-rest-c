#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bot_command_scope_chat_administrators.h"



static bot_command_scope_chat_administrators_t *bot_command_scope_chat_administrators_create_internal(
    char *type,
    bot_command_scope_chat_chat_id_t *chat_id
    ) {
    bot_command_scope_chat_administrators_t *bot_command_scope_chat_administrators_local_var = malloc(sizeof(bot_command_scope_chat_administrators_t));
    if (!bot_command_scope_chat_administrators_local_var) {
        return NULL;
    }
    bot_command_scope_chat_administrators_local_var->type = type;
    bot_command_scope_chat_administrators_local_var->chat_id = chat_id;

    bot_command_scope_chat_administrators_local_var->_library_owned = 1;
    return bot_command_scope_chat_administrators_local_var;
}

__attribute__((deprecated)) bot_command_scope_chat_administrators_t *bot_command_scope_chat_administrators_create(
    char *type,
    bot_command_scope_chat_chat_id_t *chat_id
    ) {
    return bot_command_scope_chat_administrators_create_internal (
        type,
        chat_id
        );
}

void bot_command_scope_chat_administrators_free(bot_command_scope_chat_administrators_t *bot_command_scope_chat_administrators) {
    if(NULL == bot_command_scope_chat_administrators){
        return ;
    }
    if(bot_command_scope_chat_administrators->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "bot_command_scope_chat_administrators_free");
        return ;
    }
    listEntry_t *listEntry;
    if (bot_command_scope_chat_administrators->type) {
        free(bot_command_scope_chat_administrators->type);
        bot_command_scope_chat_administrators->type = NULL;
    }
    if (bot_command_scope_chat_administrators->chat_id) {
        bot_command_scope_chat_chat_id_free(bot_command_scope_chat_administrators->chat_id);
        bot_command_scope_chat_administrators->chat_id = NULL;
    }
    free(bot_command_scope_chat_administrators);
}

cJSON *bot_command_scope_chat_administrators_convertToJSON(bot_command_scope_chat_administrators_t *bot_command_scope_chat_administrators) {
    cJSON *item = cJSON_CreateObject();

    // bot_command_scope_chat_administrators->type
    if (!bot_command_scope_chat_administrators->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", bot_command_scope_chat_administrators->type) == NULL) {
    goto fail; //String
    }


    // bot_command_scope_chat_administrators->chat_id
    if (!bot_command_scope_chat_administrators->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = bot_command_scope_chat_chat_id_convertToJSON(bot_command_scope_chat_administrators->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
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

bot_command_scope_chat_administrators_t *bot_command_scope_chat_administrators_parseFromJSON(cJSON *bot_command_scope_chat_administratorsJSON){

    bot_command_scope_chat_administrators_t *bot_command_scope_chat_administrators_local_var = NULL;

    // define the local variable for bot_command_scope_chat_administrators->chat_id
    bot_command_scope_chat_chat_id_t *chat_id_local_nonprim = NULL;

    // bot_command_scope_chat_administrators->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(bot_command_scope_chat_administratorsJSON, "type");
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

    // bot_command_scope_chat_administrators->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(bot_command_scope_chat_administratorsJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = bot_command_scope_chat_chat_id_parseFromJSON(chat_id); //nonprimitive


    bot_command_scope_chat_administrators_local_var = bot_command_scope_chat_administrators_create_internal (
        strdup(type->valuestring),
        chat_id_local_nonprim
        );

    return bot_command_scope_chat_administrators_local_var;
end:
    if (chat_id_local_nonprim) {
        bot_command_scope_chat_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
