#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_chat_administrator_custom_title_request.h"



static set_chat_administrator_custom_title_request_t *set_chat_administrator_custom_title_request_create_internal(
    bot_command_scope_chat_chat_id_t *chat_id,
    int user_id,
    char *custom_title
    ) {
    set_chat_administrator_custom_title_request_t *set_chat_administrator_custom_title_request_local_var = malloc(sizeof(set_chat_administrator_custom_title_request_t));
    if (!set_chat_administrator_custom_title_request_local_var) {
        return NULL;
    }
    set_chat_administrator_custom_title_request_local_var->chat_id = chat_id;
    set_chat_administrator_custom_title_request_local_var->user_id = user_id;
    set_chat_administrator_custom_title_request_local_var->custom_title = custom_title;

    set_chat_administrator_custom_title_request_local_var->_library_owned = 1;
    return set_chat_administrator_custom_title_request_local_var;
}

__attribute__((deprecated)) set_chat_administrator_custom_title_request_t *set_chat_administrator_custom_title_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    int user_id,
    char *custom_title
    ) {
    return set_chat_administrator_custom_title_request_create_internal (
        chat_id,
        user_id,
        custom_title
        );
}

void set_chat_administrator_custom_title_request_free(set_chat_administrator_custom_title_request_t *set_chat_administrator_custom_title_request) {
    if(NULL == set_chat_administrator_custom_title_request){
        return ;
    }
    if(set_chat_administrator_custom_title_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_chat_administrator_custom_title_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_chat_administrator_custom_title_request->chat_id) {
        bot_command_scope_chat_chat_id_free(set_chat_administrator_custom_title_request->chat_id);
        set_chat_administrator_custom_title_request->chat_id = NULL;
    }
    if (set_chat_administrator_custom_title_request->custom_title) {
        free(set_chat_administrator_custom_title_request->custom_title);
        set_chat_administrator_custom_title_request->custom_title = NULL;
    }
    free(set_chat_administrator_custom_title_request);
}

cJSON *set_chat_administrator_custom_title_request_convertToJSON(set_chat_administrator_custom_title_request_t *set_chat_administrator_custom_title_request) {
    cJSON *item = cJSON_CreateObject();

    // set_chat_administrator_custom_title_request->chat_id
    if (!set_chat_administrator_custom_title_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = bot_command_scope_chat_chat_id_convertToJSON(set_chat_administrator_custom_title_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // set_chat_administrator_custom_title_request->user_id
    if (!set_chat_administrator_custom_title_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", set_chat_administrator_custom_title_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // set_chat_administrator_custom_title_request->custom_title
    if (!set_chat_administrator_custom_title_request->custom_title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "custom_title", set_chat_administrator_custom_title_request->custom_title) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

set_chat_administrator_custom_title_request_t *set_chat_administrator_custom_title_request_parseFromJSON(cJSON *set_chat_administrator_custom_title_requestJSON){

    set_chat_administrator_custom_title_request_t *set_chat_administrator_custom_title_request_local_var = NULL;

    // define the local variable for set_chat_administrator_custom_title_request->chat_id
    bot_command_scope_chat_chat_id_t *chat_id_local_nonprim = NULL;

    // set_chat_administrator_custom_title_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(set_chat_administrator_custom_title_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = bot_command_scope_chat_chat_id_parseFromJSON(chat_id); //nonprimitive

    // set_chat_administrator_custom_title_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(set_chat_administrator_custom_title_requestJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(user_id))
    {
    goto end; //Numeric
    }

    // set_chat_administrator_custom_title_request->custom_title
    cJSON *custom_title = cJSON_GetObjectItemCaseSensitive(set_chat_administrator_custom_title_requestJSON, "custom_title");
    if (cJSON_IsNull(custom_title)) {
        custom_title = NULL;
    }
    if (!custom_title) {
        goto end;
    }

    
    if(!cJSON_IsString(custom_title))
    {
    goto end; //String
    }


    set_chat_administrator_custom_title_request_local_var = set_chat_administrator_custom_title_request_create_internal (
        chat_id_local_nonprim,
        user_id->valuedouble,
        strdup(custom_title->valuestring)
        );

    return set_chat_administrator_custom_title_request_local_var;
end:
    if (chat_id_local_nonprim) {
        bot_command_scope_chat_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
