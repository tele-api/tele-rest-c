#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bot_command_scope_all_private_chats.h"



static bot_command_scope_all_private_chats_t *bot_command_scope_all_private_chats_create_internal(
    char *type
    ) {
    bot_command_scope_all_private_chats_t *bot_command_scope_all_private_chats_local_var = malloc(sizeof(bot_command_scope_all_private_chats_t));
    if (!bot_command_scope_all_private_chats_local_var) {
        return NULL;
    }
    bot_command_scope_all_private_chats_local_var->type = type;

    bot_command_scope_all_private_chats_local_var->_library_owned = 1;
    return bot_command_scope_all_private_chats_local_var;
}

__attribute__((deprecated)) bot_command_scope_all_private_chats_t *bot_command_scope_all_private_chats_create(
    char *type
    ) {
    return bot_command_scope_all_private_chats_create_internal (
        type
        );
}

void bot_command_scope_all_private_chats_free(bot_command_scope_all_private_chats_t *bot_command_scope_all_private_chats) {
    if(NULL == bot_command_scope_all_private_chats){
        return ;
    }
    if(bot_command_scope_all_private_chats->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "bot_command_scope_all_private_chats_free");
        return ;
    }
    listEntry_t *listEntry;
    if (bot_command_scope_all_private_chats->type) {
        free(bot_command_scope_all_private_chats->type);
        bot_command_scope_all_private_chats->type = NULL;
    }
    free(bot_command_scope_all_private_chats);
}

cJSON *bot_command_scope_all_private_chats_convertToJSON(bot_command_scope_all_private_chats_t *bot_command_scope_all_private_chats) {
    cJSON *item = cJSON_CreateObject();

    // bot_command_scope_all_private_chats->type
    if (!bot_command_scope_all_private_chats->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", bot_command_scope_all_private_chats->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

bot_command_scope_all_private_chats_t *bot_command_scope_all_private_chats_parseFromJSON(cJSON *bot_command_scope_all_private_chatsJSON){

    bot_command_scope_all_private_chats_t *bot_command_scope_all_private_chats_local_var = NULL;

    // bot_command_scope_all_private_chats->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(bot_command_scope_all_private_chatsJSON, "type");
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


    bot_command_scope_all_private_chats_local_var = bot_command_scope_all_private_chats_create_internal (
        strdup(type->valuestring)
        );

    return bot_command_scope_all_private_chats_local_var;
end:
    return NULL;

}
