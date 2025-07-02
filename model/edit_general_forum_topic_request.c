#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "edit_general_forum_topic_request.h"



static edit_general_forum_topic_request_t *edit_general_forum_topic_request_create_internal(
    bot_command_scope_chat_chat_id_t *chat_id,
    char *name
    ) {
    edit_general_forum_topic_request_t *edit_general_forum_topic_request_local_var = malloc(sizeof(edit_general_forum_topic_request_t));
    if (!edit_general_forum_topic_request_local_var) {
        return NULL;
    }
    edit_general_forum_topic_request_local_var->chat_id = chat_id;
    edit_general_forum_topic_request_local_var->name = name;

    edit_general_forum_topic_request_local_var->_library_owned = 1;
    return edit_general_forum_topic_request_local_var;
}

__attribute__((deprecated)) edit_general_forum_topic_request_t *edit_general_forum_topic_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    char *name
    ) {
    return edit_general_forum_topic_request_create_internal (
        chat_id,
        name
        );
}

void edit_general_forum_topic_request_free(edit_general_forum_topic_request_t *edit_general_forum_topic_request) {
    if(NULL == edit_general_forum_topic_request){
        return ;
    }
    if(edit_general_forum_topic_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "edit_general_forum_topic_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (edit_general_forum_topic_request->chat_id) {
        bot_command_scope_chat_chat_id_free(edit_general_forum_topic_request->chat_id);
        edit_general_forum_topic_request->chat_id = NULL;
    }
    if (edit_general_forum_topic_request->name) {
        free(edit_general_forum_topic_request->name);
        edit_general_forum_topic_request->name = NULL;
    }
    free(edit_general_forum_topic_request);
}

cJSON *edit_general_forum_topic_request_convertToJSON(edit_general_forum_topic_request_t *edit_general_forum_topic_request) {
    cJSON *item = cJSON_CreateObject();

    // edit_general_forum_topic_request->chat_id
    if (!edit_general_forum_topic_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = bot_command_scope_chat_chat_id_convertToJSON(edit_general_forum_topic_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // edit_general_forum_topic_request->name
    if (!edit_general_forum_topic_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", edit_general_forum_topic_request->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

edit_general_forum_topic_request_t *edit_general_forum_topic_request_parseFromJSON(cJSON *edit_general_forum_topic_requestJSON){

    edit_general_forum_topic_request_t *edit_general_forum_topic_request_local_var = NULL;

    // define the local variable for edit_general_forum_topic_request->chat_id
    bot_command_scope_chat_chat_id_t *chat_id_local_nonprim = NULL;

    // edit_general_forum_topic_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(edit_general_forum_topic_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = bot_command_scope_chat_chat_id_parseFromJSON(chat_id); //nonprimitive

    // edit_general_forum_topic_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(edit_general_forum_topic_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    edit_general_forum_topic_request_local_var = edit_general_forum_topic_request_create_internal (
        chat_id_local_nonprim,
        strdup(name->valuestring)
        );

    return edit_general_forum_topic_request_local_var;
end:
    if (chat_id_local_nonprim) {
        bot_command_scope_chat_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
