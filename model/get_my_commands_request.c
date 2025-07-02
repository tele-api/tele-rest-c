#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_my_commands_request.h"



static get_my_commands_request_t *get_my_commands_request_create_internal(
    bot_command_scope_t *scope,
    char *language_code
    ) {
    get_my_commands_request_t *get_my_commands_request_local_var = malloc(sizeof(get_my_commands_request_t));
    if (!get_my_commands_request_local_var) {
        return NULL;
    }
    get_my_commands_request_local_var->scope = scope;
    get_my_commands_request_local_var->language_code = language_code;

    get_my_commands_request_local_var->_library_owned = 1;
    return get_my_commands_request_local_var;
}

__attribute__((deprecated)) get_my_commands_request_t *get_my_commands_request_create(
    bot_command_scope_t *scope,
    char *language_code
    ) {
    return get_my_commands_request_create_internal (
        scope,
        language_code
        );
}

void get_my_commands_request_free(get_my_commands_request_t *get_my_commands_request) {
    if(NULL == get_my_commands_request){
        return ;
    }
    if(get_my_commands_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_my_commands_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_my_commands_request->scope) {
        bot_command_scope_free(get_my_commands_request->scope);
        get_my_commands_request->scope = NULL;
    }
    if (get_my_commands_request->language_code) {
        free(get_my_commands_request->language_code);
        get_my_commands_request->language_code = NULL;
    }
    free(get_my_commands_request);
}

cJSON *get_my_commands_request_convertToJSON(get_my_commands_request_t *get_my_commands_request) {
    cJSON *item = cJSON_CreateObject();

    // get_my_commands_request->scope
    if(get_my_commands_request->scope) {
    cJSON *scope_local_JSON = bot_command_scope_convertToJSON(get_my_commands_request->scope);
    if(scope_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scope", scope_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // get_my_commands_request->language_code
    if(get_my_commands_request->language_code) {
    if(cJSON_AddStringToObject(item, "language_code", get_my_commands_request->language_code) == NULL) {
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

get_my_commands_request_t *get_my_commands_request_parseFromJSON(cJSON *get_my_commands_requestJSON){

    get_my_commands_request_t *get_my_commands_request_local_var = NULL;

    // define the local variable for get_my_commands_request->scope
    bot_command_scope_t *scope_local_nonprim = NULL;

    // get_my_commands_request->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(get_my_commands_requestJSON, "scope");
    if (cJSON_IsNull(scope)) {
        scope = NULL;
    }
    if (scope) { 
    scope_local_nonprim = bot_command_scope_parseFromJSON(scope); //nonprimitive
    }

    // get_my_commands_request->language_code
    cJSON *language_code = cJSON_GetObjectItemCaseSensitive(get_my_commands_requestJSON, "language_code");
    if (cJSON_IsNull(language_code)) {
        language_code = NULL;
    }
    if (language_code) { 
    if(!cJSON_IsString(language_code) && !cJSON_IsNull(language_code))
    {
    goto end; //String
    }
    }


    get_my_commands_request_local_var = get_my_commands_request_create_internal (
        scope ? scope_local_nonprim : NULL,
        language_code && !cJSON_IsNull(language_code) ? strdup(language_code->valuestring) : NULL
        );

    return get_my_commands_request_local_var;
end:
    if (scope_local_nonprim) {
        bot_command_scope_free(scope_local_nonprim);
        scope_local_nonprim = NULL;
    }
    return NULL;

}
