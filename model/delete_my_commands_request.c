#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delete_my_commands_request.h"



static delete_my_commands_request_t *delete_my_commands_request_create_internal(
    bot_command_scope_t *scope,
    char *language_code
    ) {
    delete_my_commands_request_t *delete_my_commands_request_local_var = malloc(sizeof(delete_my_commands_request_t));
    if (!delete_my_commands_request_local_var) {
        return NULL;
    }
    delete_my_commands_request_local_var->scope = scope;
    delete_my_commands_request_local_var->language_code = language_code;

    delete_my_commands_request_local_var->_library_owned = 1;
    return delete_my_commands_request_local_var;
}

__attribute__((deprecated)) delete_my_commands_request_t *delete_my_commands_request_create(
    bot_command_scope_t *scope,
    char *language_code
    ) {
    return delete_my_commands_request_create_internal (
        scope,
        language_code
        );
}

void delete_my_commands_request_free(delete_my_commands_request_t *delete_my_commands_request) {
    if(NULL == delete_my_commands_request){
        return ;
    }
    if(delete_my_commands_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delete_my_commands_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (delete_my_commands_request->scope) {
        bot_command_scope_free(delete_my_commands_request->scope);
        delete_my_commands_request->scope = NULL;
    }
    if (delete_my_commands_request->language_code) {
        free(delete_my_commands_request->language_code);
        delete_my_commands_request->language_code = NULL;
    }
    free(delete_my_commands_request);
}

cJSON *delete_my_commands_request_convertToJSON(delete_my_commands_request_t *delete_my_commands_request) {
    cJSON *item = cJSON_CreateObject();

    // delete_my_commands_request->scope
    if(delete_my_commands_request->scope) {
    cJSON *scope_local_JSON = bot_command_scope_convertToJSON(delete_my_commands_request->scope);
    if(scope_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scope", scope_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // delete_my_commands_request->language_code
    if(delete_my_commands_request->language_code) {
    if(cJSON_AddStringToObject(item, "language_code", delete_my_commands_request->language_code) == NULL) {
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

delete_my_commands_request_t *delete_my_commands_request_parseFromJSON(cJSON *delete_my_commands_requestJSON){

    delete_my_commands_request_t *delete_my_commands_request_local_var = NULL;

    // define the local variable for delete_my_commands_request->scope
    bot_command_scope_t *scope_local_nonprim = NULL;

    // delete_my_commands_request->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(delete_my_commands_requestJSON, "scope");
    if (cJSON_IsNull(scope)) {
        scope = NULL;
    }
    if (scope) { 
    scope_local_nonprim = bot_command_scope_parseFromJSON(scope); //nonprimitive
    }

    // delete_my_commands_request->language_code
    cJSON *language_code = cJSON_GetObjectItemCaseSensitive(delete_my_commands_requestJSON, "language_code");
    if (cJSON_IsNull(language_code)) {
        language_code = NULL;
    }
    if (language_code) { 
    if(!cJSON_IsString(language_code) && !cJSON_IsNull(language_code))
    {
    goto end; //String
    }
    }


    delete_my_commands_request_local_var = delete_my_commands_request_create_internal (
        scope ? scope_local_nonprim : NULL,
        language_code && !cJSON_IsNull(language_code) ? strdup(language_code->valuestring) : NULL
        );

    return delete_my_commands_request_local_var;
end:
    if (scope_local_nonprim) {
        bot_command_scope_free(scope_local_nonprim);
        scope_local_nonprim = NULL;
    }
    return NULL;

}
