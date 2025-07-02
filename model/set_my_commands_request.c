#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_my_commands_request.h"



static set_my_commands_request_t *set_my_commands_request_create_internal(
    list_t *commands,
    bot_command_scope_t *scope,
    char *language_code
    ) {
    set_my_commands_request_t *set_my_commands_request_local_var = malloc(sizeof(set_my_commands_request_t));
    if (!set_my_commands_request_local_var) {
        return NULL;
    }
    set_my_commands_request_local_var->commands = commands;
    set_my_commands_request_local_var->scope = scope;
    set_my_commands_request_local_var->language_code = language_code;

    set_my_commands_request_local_var->_library_owned = 1;
    return set_my_commands_request_local_var;
}

__attribute__((deprecated)) set_my_commands_request_t *set_my_commands_request_create(
    list_t *commands,
    bot_command_scope_t *scope,
    char *language_code
    ) {
    return set_my_commands_request_create_internal (
        commands,
        scope,
        language_code
        );
}

void set_my_commands_request_free(set_my_commands_request_t *set_my_commands_request) {
    if(NULL == set_my_commands_request){
        return ;
    }
    if(set_my_commands_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_my_commands_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_my_commands_request->commands) {
        list_ForEach(listEntry, set_my_commands_request->commands) {
            bot_command_free(listEntry->data);
        }
        list_freeList(set_my_commands_request->commands);
        set_my_commands_request->commands = NULL;
    }
    if (set_my_commands_request->scope) {
        bot_command_scope_free(set_my_commands_request->scope);
        set_my_commands_request->scope = NULL;
    }
    if (set_my_commands_request->language_code) {
        free(set_my_commands_request->language_code);
        set_my_commands_request->language_code = NULL;
    }
    free(set_my_commands_request);
}

cJSON *set_my_commands_request_convertToJSON(set_my_commands_request_t *set_my_commands_request) {
    cJSON *item = cJSON_CreateObject();

    // set_my_commands_request->commands
    if (!set_my_commands_request->commands) {
        goto fail;
    }
    cJSON *commands = cJSON_AddArrayToObject(item, "commands");
    if(commands == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *commandsListEntry;
    if (set_my_commands_request->commands) {
    list_ForEach(commandsListEntry, set_my_commands_request->commands) {
    cJSON *itemLocal = bot_command_convertToJSON(commandsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(commands, itemLocal);
    }
    }


    // set_my_commands_request->scope
    if(set_my_commands_request->scope) {
    cJSON *scope_local_JSON = bot_command_scope_convertToJSON(set_my_commands_request->scope);
    if(scope_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scope", scope_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // set_my_commands_request->language_code
    if(set_my_commands_request->language_code) {
    if(cJSON_AddStringToObject(item, "language_code", set_my_commands_request->language_code) == NULL) {
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

set_my_commands_request_t *set_my_commands_request_parseFromJSON(cJSON *set_my_commands_requestJSON){

    set_my_commands_request_t *set_my_commands_request_local_var = NULL;

    // define the local list for set_my_commands_request->commands
    list_t *commandsList = NULL;

    // define the local variable for set_my_commands_request->scope
    bot_command_scope_t *scope_local_nonprim = NULL;

    // set_my_commands_request->commands
    cJSON *commands = cJSON_GetObjectItemCaseSensitive(set_my_commands_requestJSON, "commands");
    if (cJSON_IsNull(commands)) {
        commands = NULL;
    }
    if (!commands) {
        goto end;
    }

    
    cJSON *commands_local_nonprimitive = NULL;
    if(!cJSON_IsArray(commands)){
        goto end; //nonprimitive container
    }

    commandsList = list_createList();

    cJSON_ArrayForEach(commands_local_nonprimitive,commands )
    {
        if(!cJSON_IsObject(commands_local_nonprimitive)){
            goto end;
        }
        bot_command_t *commandsItem = bot_command_parseFromJSON(commands_local_nonprimitive);

        list_addElement(commandsList, commandsItem);
    }

    // set_my_commands_request->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(set_my_commands_requestJSON, "scope");
    if (cJSON_IsNull(scope)) {
        scope = NULL;
    }
    if (scope) { 
    scope_local_nonprim = bot_command_scope_parseFromJSON(scope); //nonprimitive
    }

    // set_my_commands_request->language_code
    cJSON *language_code = cJSON_GetObjectItemCaseSensitive(set_my_commands_requestJSON, "language_code");
    if (cJSON_IsNull(language_code)) {
        language_code = NULL;
    }
    if (language_code) { 
    if(!cJSON_IsString(language_code) && !cJSON_IsNull(language_code))
    {
    goto end; //String
    }
    }


    set_my_commands_request_local_var = set_my_commands_request_create_internal (
        commandsList,
        scope ? scope_local_nonprim : NULL,
        language_code && !cJSON_IsNull(language_code) ? strdup(language_code->valuestring) : NULL
        );

    return set_my_commands_request_local_var;
end:
    if (commandsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, commandsList) {
            bot_command_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(commandsList);
        commandsList = NULL;
    }
    if (scope_local_nonprim) {
        bot_command_scope_free(scope_local_nonprim);
        scope_local_nonprim = NULL;
    }
    return NULL;

}
