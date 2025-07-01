#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_delete_my_commands_post_request.h"



static _delete_my_commands_post_request_t *_delete_my_commands_post_request_create_internal(
    bot_command_scope_t *scope,
    char *language_code
    ) {
    _delete_my_commands_post_request_t *_delete_my_commands_post_request_local_var = malloc(sizeof(_delete_my_commands_post_request_t));
    if (!_delete_my_commands_post_request_local_var) {
        return NULL;
    }
    _delete_my_commands_post_request_local_var->scope = scope;
    _delete_my_commands_post_request_local_var->language_code = language_code;

    _delete_my_commands_post_request_local_var->_library_owned = 1;
    return _delete_my_commands_post_request_local_var;
}

__attribute__((deprecated)) _delete_my_commands_post_request_t *_delete_my_commands_post_request_create(
    bot_command_scope_t *scope,
    char *language_code
    ) {
    return _delete_my_commands_post_request_create_internal (
        scope,
        language_code
        );
}

void _delete_my_commands_post_request_free(_delete_my_commands_post_request_t *_delete_my_commands_post_request) {
    if(NULL == _delete_my_commands_post_request){
        return ;
    }
    if(_delete_my_commands_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_delete_my_commands_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_delete_my_commands_post_request->scope) {
        bot_command_scope_free(_delete_my_commands_post_request->scope);
        _delete_my_commands_post_request->scope = NULL;
    }
    if (_delete_my_commands_post_request->language_code) {
        free(_delete_my_commands_post_request->language_code);
        _delete_my_commands_post_request->language_code = NULL;
    }
    free(_delete_my_commands_post_request);
}

cJSON *_delete_my_commands_post_request_convertToJSON(_delete_my_commands_post_request_t *_delete_my_commands_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _delete_my_commands_post_request->scope
    if(_delete_my_commands_post_request->scope) {
    cJSON *scope_local_JSON = bot_command_scope_convertToJSON(_delete_my_commands_post_request->scope);
    if(scope_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scope", scope_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _delete_my_commands_post_request->language_code
    if(_delete_my_commands_post_request->language_code) {
    if(cJSON_AddStringToObject(item, "language_code", _delete_my_commands_post_request->language_code) == NULL) {
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

_delete_my_commands_post_request_t *_delete_my_commands_post_request_parseFromJSON(cJSON *_delete_my_commands_post_requestJSON){

    _delete_my_commands_post_request_t *_delete_my_commands_post_request_local_var = NULL;

    // define the local variable for _delete_my_commands_post_request->scope
    bot_command_scope_t *scope_local_nonprim = NULL;

    // _delete_my_commands_post_request->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(_delete_my_commands_post_requestJSON, "scope");
    if (cJSON_IsNull(scope)) {
        scope = NULL;
    }
    if (scope) { 
    scope_local_nonprim = bot_command_scope_parseFromJSON(scope); //nonprimitive
    }

    // _delete_my_commands_post_request->language_code
    cJSON *language_code = cJSON_GetObjectItemCaseSensitive(_delete_my_commands_post_requestJSON, "language_code");
    if (cJSON_IsNull(language_code)) {
        language_code = NULL;
    }
    if (language_code) { 
    if(!cJSON_IsString(language_code) && !cJSON_IsNull(language_code))
    {
    goto end; //String
    }
    }


    _delete_my_commands_post_request_local_var = _delete_my_commands_post_request_create_internal (
        scope ? scope_local_nonprim : NULL,
        language_code && !cJSON_IsNull(language_code) ? strdup(language_code->valuestring) : NULL
        );

    return _delete_my_commands_post_request_local_var;
end:
    if (scope_local_nonprim) {
        bot_command_scope_free(scope_local_nonprim);
        scope_local_nonprim = NULL;
    }
    return NULL;

}
