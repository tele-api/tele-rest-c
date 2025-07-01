#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_my_commands_post_request.h"



static _set_my_commands_post_request_t *_set_my_commands_post_request_create_internal(
    list_t *commands,
    bot_command_scope_t *scope,
    char *language_code
    ) {
    _set_my_commands_post_request_t *_set_my_commands_post_request_local_var = malloc(sizeof(_set_my_commands_post_request_t));
    if (!_set_my_commands_post_request_local_var) {
        return NULL;
    }
    _set_my_commands_post_request_local_var->commands = commands;
    _set_my_commands_post_request_local_var->scope = scope;
    _set_my_commands_post_request_local_var->language_code = language_code;

    _set_my_commands_post_request_local_var->_library_owned = 1;
    return _set_my_commands_post_request_local_var;
}

__attribute__((deprecated)) _set_my_commands_post_request_t *_set_my_commands_post_request_create(
    list_t *commands,
    bot_command_scope_t *scope,
    char *language_code
    ) {
    return _set_my_commands_post_request_create_internal (
        commands,
        scope,
        language_code
        );
}

void _set_my_commands_post_request_free(_set_my_commands_post_request_t *_set_my_commands_post_request) {
    if(NULL == _set_my_commands_post_request){
        return ;
    }
    if(_set_my_commands_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_my_commands_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_my_commands_post_request->commands) {
        list_ForEach(listEntry, _set_my_commands_post_request->commands) {
            bot_command_free(listEntry->data);
        }
        list_freeList(_set_my_commands_post_request->commands);
        _set_my_commands_post_request->commands = NULL;
    }
    if (_set_my_commands_post_request->scope) {
        bot_command_scope_free(_set_my_commands_post_request->scope);
        _set_my_commands_post_request->scope = NULL;
    }
    if (_set_my_commands_post_request->language_code) {
        free(_set_my_commands_post_request->language_code);
        _set_my_commands_post_request->language_code = NULL;
    }
    free(_set_my_commands_post_request);
}

cJSON *_set_my_commands_post_request_convertToJSON(_set_my_commands_post_request_t *_set_my_commands_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_my_commands_post_request->commands
    if (!_set_my_commands_post_request->commands) {
        goto fail;
    }
    cJSON *commands = cJSON_AddArrayToObject(item, "commands");
    if(commands == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *commandsListEntry;
    if (_set_my_commands_post_request->commands) {
    list_ForEach(commandsListEntry, _set_my_commands_post_request->commands) {
    cJSON *itemLocal = bot_command_convertToJSON(commandsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(commands, itemLocal);
    }
    }


    // _set_my_commands_post_request->scope
    if(_set_my_commands_post_request->scope) {
    cJSON *scope_local_JSON = bot_command_scope_convertToJSON(_set_my_commands_post_request->scope);
    if(scope_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scope", scope_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _set_my_commands_post_request->language_code
    if(_set_my_commands_post_request->language_code) {
    if(cJSON_AddStringToObject(item, "language_code", _set_my_commands_post_request->language_code) == NULL) {
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

_set_my_commands_post_request_t *_set_my_commands_post_request_parseFromJSON(cJSON *_set_my_commands_post_requestJSON){

    _set_my_commands_post_request_t *_set_my_commands_post_request_local_var = NULL;

    // define the local list for _set_my_commands_post_request->commands
    list_t *commandsList = NULL;

    // define the local variable for _set_my_commands_post_request->scope
    bot_command_scope_t *scope_local_nonprim = NULL;

    // _set_my_commands_post_request->commands
    cJSON *commands = cJSON_GetObjectItemCaseSensitive(_set_my_commands_post_requestJSON, "commands");
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

    // _set_my_commands_post_request->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(_set_my_commands_post_requestJSON, "scope");
    if (cJSON_IsNull(scope)) {
        scope = NULL;
    }
    if (scope) { 
    scope_local_nonprim = bot_command_scope_parseFromJSON(scope); //nonprimitive
    }

    // _set_my_commands_post_request->language_code
    cJSON *language_code = cJSON_GetObjectItemCaseSensitive(_set_my_commands_post_requestJSON, "language_code");
    if (cJSON_IsNull(language_code)) {
        language_code = NULL;
    }
    if (language_code) { 
    if(!cJSON_IsString(language_code) && !cJSON_IsNull(language_code))
    {
    goto end; //String
    }
    }


    _set_my_commands_post_request_local_var = _set_my_commands_post_request_create_internal (
        commandsList,
        scope ? scope_local_nonprim : NULL,
        language_code && !cJSON_IsNull(language_code) ? strdup(language_code->valuestring) : NULL
        );

    return _set_my_commands_post_request_local_var;
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
