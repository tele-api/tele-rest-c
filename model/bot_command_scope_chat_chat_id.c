#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bot_command_scope_chat_chat_id.h"



static bot_command_scope_chat_chat_id_t *bot_command_scope_chat_chat_id_create_internal(
    ) {
    bot_command_scope_chat_chat_id_t *bot_command_scope_chat_chat_id_local_var = malloc(sizeof(bot_command_scope_chat_chat_id_t));
    if (!bot_command_scope_chat_chat_id_local_var) {
        return NULL;
    }

    bot_command_scope_chat_chat_id_local_var->_library_owned = 1;
    return bot_command_scope_chat_chat_id_local_var;
}

__attribute__((deprecated)) bot_command_scope_chat_chat_id_t *bot_command_scope_chat_chat_id_create(
    ) {
    return bot_command_scope_chat_chat_id_create_internal (
        );
}

void bot_command_scope_chat_chat_id_free(bot_command_scope_chat_chat_id_t *bot_command_scope_chat_chat_id) {
    if(NULL == bot_command_scope_chat_chat_id){
        return ;
    }
    if(bot_command_scope_chat_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "bot_command_scope_chat_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(bot_command_scope_chat_chat_id);
}

cJSON *bot_command_scope_chat_chat_id_convertToJSON(bot_command_scope_chat_chat_id_t *bot_command_scope_chat_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

bot_command_scope_chat_chat_id_t *bot_command_scope_chat_chat_id_parseFromJSON(cJSON *bot_command_scope_chat_chat_idJSON){

    bot_command_scope_chat_chat_id_t *bot_command_scope_chat_chat_id_local_var = NULL;


    bot_command_scope_chat_chat_id_local_var = bot_command_scope_chat_chat_id_create_internal (
        );

    return bot_command_scope_chat_chat_id_local_var;
end:
    return NULL;

}
