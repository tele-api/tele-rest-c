#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reopen_general_forum_topic_request.h"



static reopen_general_forum_topic_request_t *reopen_general_forum_topic_request_create_internal(
    bot_command_scope_chat_chat_id_t *chat_id
    ) {
    reopen_general_forum_topic_request_t *reopen_general_forum_topic_request_local_var = malloc(sizeof(reopen_general_forum_topic_request_t));
    if (!reopen_general_forum_topic_request_local_var) {
        return NULL;
    }
    reopen_general_forum_topic_request_local_var->chat_id = chat_id;

    reopen_general_forum_topic_request_local_var->_library_owned = 1;
    return reopen_general_forum_topic_request_local_var;
}

__attribute__((deprecated)) reopen_general_forum_topic_request_t *reopen_general_forum_topic_request_create(
    bot_command_scope_chat_chat_id_t *chat_id
    ) {
    return reopen_general_forum_topic_request_create_internal (
        chat_id
        );
}

void reopen_general_forum_topic_request_free(reopen_general_forum_topic_request_t *reopen_general_forum_topic_request) {
    if(NULL == reopen_general_forum_topic_request){
        return ;
    }
    if(reopen_general_forum_topic_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reopen_general_forum_topic_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (reopen_general_forum_topic_request->chat_id) {
        bot_command_scope_chat_chat_id_free(reopen_general_forum_topic_request->chat_id);
        reopen_general_forum_topic_request->chat_id = NULL;
    }
    free(reopen_general_forum_topic_request);
}

cJSON *reopen_general_forum_topic_request_convertToJSON(reopen_general_forum_topic_request_t *reopen_general_forum_topic_request) {
    cJSON *item = cJSON_CreateObject();

    // reopen_general_forum_topic_request->chat_id
    if (!reopen_general_forum_topic_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = bot_command_scope_chat_chat_id_convertToJSON(reopen_general_forum_topic_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reopen_general_forum_topic_request_t *reopen_general_forum_topic_request_parseFromJSON(cJSON *reopen_general_forum_topic_requestJSON){

    reopen_general_forum_topic_request_t *reopen_general_forum_topic_request_local_var = NULL;

    // define the local variable for reopen_general_forum_topic_request->chat_id
    bot_command_scope_chat_chat_id_t *chat_id_local_nonprim = NULL;

    // reopen_general_forum_topic_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(reopen_general_forum_topic_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = bot_command_scope_chat_chat_id_parseFromJSON(chat_id); //nonprimitive


    reopen_general_forum_topic_request_local_var = reopen_general_forum_topic_request_create_internal (
        chat_id_local_nonprim
        );

    return reopen_general_forum_topic_request_local_var;
end:
    if (chat_id_local_nonprim) {
        bot_command_scope_chat_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
