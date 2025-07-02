#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_my_commands_request.h"



static post_set_my_commands_request_t *post_set_my_commands_request_create_internal(
    list_t *commands,
    bot_command_scope_t *scope,
    char *language_code
    ) {
    post_set_my_commands_request_t *post_set_my_commands_request_local_var = malloc(sizeof(post_set_my_commands_request_t));
    if (!post_set_my_commands_request_local_var) {
        return NULL;
    }
    post_set_my_commands_request_local_var->commands = commands;
    post_set_my_commands_request_local_var->scope = scope;
    post_set_my_commands_request_local_var->language_code = language_code;

    post_set_my_commands_request_local_var->_library_owned = 1;
    return post_set_my_commands_request_local_var;
}

__attribute__((deprecated)) post_set_my_commands_request_t *post_set_my_commands_request_create(
    list_t *commands,
    bot_command_scope_t *scope,
    char *language_code
    ) {
    return post_set_my_commands_request_create_internal (
        commands,
        scope,
        language_code
        );
}

void post_set_my_commands_request_free(post_set_my_commands_request_t *post_set_my_commands_request) {
    if(NULL == post_set_my_commands_request){
        return ;
    }
    if(post_set_my_commands_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_my_commands_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_my_commands_request->commands) {
        list_ForEach(listEntry, post_set_my_commands_request->commands) {
            bot_command_free(listEntry->data);
        }
        list_freeList(post_set_my_commands_request->commands);
        post_set_my_commands_request->commands = NULL;
    }
    if (post_set_my_commands_request->scope) {
        bot_command_scope_free(post_set_my_commands_request->scope);
        post_set_my_commands_request->scope = NULL;
    }
    if (post_set_my_commands_request->language_code) {
        free(post_set_my_commands_request->language_code);
        post_set_my_commands_request->language_code = NULL;
    }
    free(post_set_my_commands_request);
}

cJSON *post_set_my_commands_request_convertToJSON(post_set_my_commands_request_t *post_set_my_commands_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_my_commands_request->commands
    if (!post_set_my_commands_request->commands) {
        goto fail;
    }
    cJSON *commands = cJSON_AddArrayToObject(item, "commands");
    if(commands == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *commandsListEntry;
    if (post_set_my_commands_request->commands) {
    list_ForEach(commandsListEntry, post_set_my_commands_request->commands) {
    cJSON *itemLocal = bot_command_convertToJSON(commandsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(commands, itemLocal);
    }
    }


    // post_set_my_commands_request->scope
    if(post_set_my_commands_request->scope) {
    cJSON *scope_local_JSON = bot_command_scope_convertToJSON(post_set_my_commands_request->scope);
    if(scope_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scope", scope_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // post_set_my_commands_request->language_code
    if(post_set_my_commands_request->language_code) {
    if(cJSON_AddStringToObject(item, "language_code", post_set_my_commands_request->language_code) == NULL) {
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

post_set_my_commands_request_t *post_set_my_commands_request_parseFromJSON(cJSON *post_set_my_commands_requestJSON){

    post_set_my_commands_request_t *post_set_my_commands_request_local_var = NULL;

    // define the local list for post_set_my_commands_request->commands
    list_t *commandsList = NULL;

    // define the local variable for post_set_my_commands_request->scope
    bot_command_scope_t *scope_local_nonprim = NULL;

    // post_set_my_commands_request->commands
    cJSON *commands = cJSON_GetObjectItemCaseSensitive(post_set_my_commands_requestJSON, "commands");
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

    // post_set_my_commands_request->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(post_set_my_commands_requestJSON, "scope");
    if (cJSON_IsNull(scope)) {
        scope = NULL;
    }
    if (scope) { 
    scope_local_nonprim = bot_command_scope_parseFromJSON(scope); //nonprimitive
    }

    // post_set_my_commands_request->language_code
    cJSON *language_code = cJSON_GetObjectItemCaseSensitive(post_set_my_commands_requestJSON, "language_code");
    if (cJSON_IsNull(language_code)) {
        language_code = NULL;
    }
    if (language_code) { 
    if(!cJSON_IsString(language_code) && !cJSON_IsNull(language_code))
    {
    goto end; //String
    }
    }


    post_set_my_commands_request_local_var = post_set_my_commands_request_create_internal (
        commandsList,
        scope ? scope_local_nonprim : NULL,
        language_code && !cJSON_IsNull(language_code) ? strdup(language_code->valuestring) : NULL
        );

    return post_set_my_commands_request_local_var;
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
