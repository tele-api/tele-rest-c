#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bot_command.h"



static bot_command_t *bot_command_create_internal(
    char *command,
    char *description
    ) {
    bot_command_t *bot_command_local_var = malloc(sizeof(bot_command_t));
    if (!bot_command_local_var) {
        return NULL;
    }
    bot_command_local_var->command = command;
    bot_command_local_var->description = description;

    bot_command_local_var->_library_owned = 1;
    return bot_command_local_var;
}

__attribute__((deprecated)) bot_command_t *bot_command_create(
    char *command,
    char *description
    ) {
    return bot_command_create_internal (
        command,
        description
        );
}

void bot_command_free(bot_command_t *bot_command) {
    if(NULL == bot_command){
        return ;
    }
    if(bot_command->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "bot_command_free");
        return ;
    }
    listEntry_t *listEntry;
    if (bot_command->command) {
        free(bot_command->command);
        bot_command->command = NULL;
    }
    if (bot_command->description) {
        free(bot_command->description);
        bot_command->description = NULL;
    }
    free(bot_command);
}

cJSON *bot_command_convertToJSON(bot_command_t *bot_command) {
    cJSON *item = cJSON_CreateObject();

    // bot_command->command
    if (!bot_command->command) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "command", bot_command->command) == NULL) {
    goto fail; //String
    }


    // bot_command->description
    if (!bot_command->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", bot_command->description) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

bot_command_t *bot_command_parseFromJSON(cJSON *bot_commandJSON){

    bot_command_t *bot_command_local_var = NULL;

    // bot_command->command
    cJSON *command = cJSON_GetObjectItemCaseSensitive(bot_commandJSON, "command");
    if (cJSON_IsNull(command)) {
        command = NULL;
    }
    if (!command) {
        goto end;
    }

    
    if(!cJSON_IsString(command))
    {
    goto end; //String
    }

    // bot_command->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(bot_commandJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (!description) {
        goto end;
    }

    
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }


    bot_command_local_var = bot_command_create_internal (
        strdup(command->valuestring),
        strdup(description->valuestring)
        );

    return bot_command_local_var;
end:
    return NULL;

}
