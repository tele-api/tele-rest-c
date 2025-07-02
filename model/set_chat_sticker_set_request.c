#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_chat_sticker_set_request.h"



static set_chat_sticker_set_request_t *set_chat_sticker_set_request_create_internal(
    bot_command_scope_chat_chat_id_t *chat_id,
    char *sticker_set_name
    ) {
    set_chat_sticker_set_request_t *set_chat_sticker_set_request_local_var = malloc(sizeof(set_chat_sticker_set_request_t));
    if (!set_chat_sticker_set_request_local_var) {
        return NULL;
    }
    set_chat_sticker_set_request_local_var->chat_id = chat_id;
    set_chat_sticker_set_request_local_var->sticker_set_name = sticker_set_name;

    set_chat_sticker_set_request_local_var->_library_owned = 1;
    return set_chat_sticker_set_request_local_var;
}

__attribute__((deprecated)) set_chat_sticker_set_request_t *set_chat_sticker_set_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    char *sticker_set_name
    ) {
    return set_chat_sticker_set_request_create_internal (
        chat_id,
        sticker_set_name
        );
}

void set_chat_sticker_set_request_free(set_chat_sticker_set_request_t *set_chat_sticker_set_request) {
    if(NULL == set_chat_sticker_set_request){
        return ;
    }
    if(set_chat_sticker_set_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_chat_sticker_set_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_chat_sticker_set_request->chat_id) {
        bot_command_scope_chat_chat_id_free(set_chat_sticker_set_request->chat_id);
        set_chat_sticker_set_request->chat_id = NULL;
    }
    if (set_chat_sticker_set_request->sticker_set_name) {
        free(set_chat_sticker_set_request->sticker_set_name);
        set_chat_sticker_set_request->sticker_set_name = NULL;
    }
    free(set_chat_sticker_set_request);
}

cJSON *set_chat_sticker_set_request_convertToJSON(set_chat_sticker_set_request_t *set_chat_sticker_set_request) {
    cJSON *item = cJSON_CreateObject();

    // set_chat_sticker_set_request->chat_id
    if (!set_chat_sticker_set_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = bot_command_scope_chat_chat_id_convertToJSON(set_chat_sticker_set_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // set_chat_sticker_set_request->sticker_set_name
    if (!set_chat_sticker_set_request->sticker_set_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker_set_name", set_chat_sticker_set_request->sticker_set_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

set_chat_sticker_set_request_t *set_chat_sticker_set_request_parseFromJSON(cJSON *set_chat_sticker_set_requestJSON){

    set_chat_sticker_set_request_t *set_chat_sticker_set_request_local_var = NULL;

    // define the local variable for set_chat_sticker_set_request->chat_id
    bot_command_scope_chat_chat_id_t *chat_id_local_nonprim = NULL;

    // set_chat_sticker_set_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(set_chat_sticker_set_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = bot_command_scope_chat_chat_id_parseFromJSON(chat_id); //nonprimitive

    // set_chat_sticker_set_request->sticker_set_name
    cJSON *sticker_set_name = cJSON_GetObjectItemCaseSensitive(set_chat_sticker_set_requestJSON, "sticker_set_name");
    if (cJSON_IsNull(sticker_set_name)) {
        sticker_set_name = NULL;
    }
    if (!sticker_set_name) {
        goto end;
    }

    
    if(!cJSON_IsString(sticker_set_name))
    {
    goto end; //String
    }


    set_chat_sticker_set_request_local_var = set_chat_sticker_set_request_create_internal (
        chat_id_local_nonprim,
        strdup(sticker_set_name->valuestring)
        );

    return set_chat_sticker_set_request_local_var;
end:
    if (chat_id_local_nonprim) {
        bot_command_scope_chat_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
